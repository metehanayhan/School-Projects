# METEHAN AYHAN

from flask import Flask, render_template, request, redirect, url_for, session
import numpy as np
import pickle as pkl
import tensorflow as tf
from tensorflow.keras.applications.resnet50 import ResNet50, preprocess_input
from tensorflow.keras.preprocessing import image
from tensorflow.keras.layers import GlobalMaxPool2D
from sklearn.neighbors import NearestNeighbors
from numpy.linalg import norm
import os
import random

app = Flask(__name__)
app.secret_key = 'your_secret_key'

# ResNet50 modelini yükle
base_model = ResNet50(weights='imagenet', include_top=False, input_shape=(224, 224, 3))
model = tf.keras.Sequential([
    base_model,
    GlobalMaxPool2D()
])
model.trainable = False

# Dosyaları yükle
image_features = pkl.load(open('Images_features.pkl', 'rb'))
filenames = pkl.load(open('filenames_updated.pkl', 'rb'))

print(f"Toplam dosya yolu: {len(filenames)}")  
print(f"İlk dosya yolu: {filenames[0]}") 

products = []
for idx, file_path in enumerate(filenames):
    # DOSYA YOLU DÜZELTMESİ
    corrected_path = file_path.replace('\\', '/') 
    if not corrected_path.startswith('static/'):
        corrected_path = f"static/{corrected_path.lstrip('/')}"
    
    products.append({
        'id': idx + 1,
        'name': f"Ürün {idx}",
        'description': f"{os.path.basename(file_path)} ürünü",
        'price': (idx % 200) + 300,
        'image': corrected_path 
    })

print(f"Oluşturulan ürün sayısı: {len(products)}")  # 0 ise problem var

# KNN modeli
neighbors = NearestNeighbors(n_neighbors=6, algorithm='brute', metric='euclidean')  # 6 komşu
neighbors.fit(image_features)

# Resim özelliklerini çıkaran fonksiyon
def extract_features_from_images(image_path, model):
    img = image.load_img(image_path, target_size=(224, 224))
    img_array = image.img_to_array(img)
    img_expand_dim = np.expand_dims(img_array, axis=0)
    img_preprocess = preprocess_input(img_expand_dim)
    result = model.predict(img_preprocess).flatten()
    norm_result = result / norm(result)  # Normalizasyon
    return norm_result

@app.route('/')
def index():

    return render_template('index.html', products=products[:48]) # İlk 48 ürün..

@app.route('/add_to_cart/<int:product_id>')
def add_to_cart(product_id):
    product = next((item for item in products if item['id'] == product_id), None)
    if product:
        if 'cart' not in session:
            session['cart'] = []
        session['cart'].append(product)
        session.modified = True
    return redirect(url_for('index'))

@app.route('/cart')
def cart_view():
    if 'cart' not in session:
        session['cart'] = []
    return render_template('cart.html', cart=session['cart'])

@app.route('/remove_from_cart/<int:product_id>')
def remove_from_cart(product_id):
    if 'cart' in session:
        session['cart'] = [item for item in session['cart'] if item['id'] != product_id]
        session.modified = True
    return redirect(url_for('cart_view'))

@app.route('/recommend_similar')
def recommend_similar():
    print("\n=== RECOMMEND_SIMILAR FUNKSIYONU ÇALIŞIYOR ===")
    
    if 'cart' not in session or not session['cart']:
        print("! HATA: Sepet boş veya session'da cart yok !")
        return "Sepet boş. Lütfen önce sepete ürün ekleyin."

    print(f"Sepet içeriği: {session['cart']}")
    
    # Sepetteki ilk ürünün resmini al
    first_product = session['cart'][0]
    print(f"İlk ürün: {first_product}")
    
    image_path = os.path.normpath(first_product['image'])  # Windows path düzenlemesi
    print(f"Düzeltilmiş image_path: {image_path} | Dosya var mı?: {os.path.exists(image_path)}")
    
    try:
        # Resim özelliklerini çıkar
        input_image_features = extract_features_from_images(image_path, model)
        print(f"Özellik vektörü boyutu: {input_image_features.shape}")
    except Exception as e:
        print(f"! ÖZELLİK ÇIKARMA HATASI: {str(e)} !")
        raise

    # En yakın 5 resmi bul
    distances, indices = neighbors.kneighbors([input_image_features])
    indices = indices[0][1:]  # İlk sonucu atla (kendisi)
    print(f"Bulunan indeksler: {indices} | Mesafeler: {distances}")
    
    # Benzer ürünleri filenames'den al
    similar_products = []
    print(f"Toplam ürün sayısı: {len(products)} | Toplam filename: {len(filenames)}")
    
    for i in indices:
        print(f"Index kontrolü: {i} -> Geçerli mi?: {i < len(products)}")
        if i < len(products):
            similar_products.append(products[i])
        else:
            print(f"! GEÇERSİZ İNDEX: {i} (max index: {len(products)-1}) !")

    print(f"Bulunan benzer ürün sayısı: {len(similar_products)}")
    return render_template('recommendations.html', 
                         cart=session['cart'], 
                         similar_products=similar_products)

@app.route('/product/<int:product_id>')
def product_detail(product_id):
    product = next((item for item in products if item['id'] == product_id), None)
    if product:
        return render_template('product_detail.html', product=product)
    return "Ürün bulunamadı."

if __name__ == '__main__':
    app.run(debug=True)