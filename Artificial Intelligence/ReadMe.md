# Yapay Zekaya Giriş Dönem Projesi

Bu proje, görsel içeriklerden ürün benzerliği tespit etmek amacıyla geliştirilmiş bir yapay zeka uygulamasıdır. Derin öğrenme tabanlı **ResNet50** modeli kullanılarak her bir ürün görselinden yüksek boyutlu öznitelik (feature) vektörleri çıkarılmıştır. Bu öznitelikler, ürünlerin görsel benzerliklerini sayısal olarak ifade eden temsillerdir. Ardından, bu vektörler üzerinde **k-En Yakın Komşu (K-Nearest Neighbors, KNN)** algoritması kullanılarak benzer ürünler tespit edilmiştir. Kullanıcı bir ürünü sepete eklediğinde sistem, bu ürünün görsel özelliklerine en çok benzeyen ürünleri otomatik olarak önerir. Tüm süreç, Flask tabanlı bir web arayüzü ile kullanıcıya sunulmuş ve görseller üzerinden içerik tabanlı öneri sistemi başarıyla uygulanmıştır.

## **Kullanılan Teknolojiler:**

- Python 3
- Flask (web çatısı)
- TensorFlow / Keras – ResNet50 modeli
- scikit-learn – Nearest Neighbors algoritması
- HTML, Bootstrap – Web arayüzü
- Pickle (.pkl) – Veri saklama

## **Sistem Mimarisi:**

- Görsellerden öznitelik çıkarımı için ResNet50 modeli kullanılmıştır.
- Öznitelik vektörleri `Images_features.pkl` dosyasında saklanmıştır.
- Görsel yolları `filenames_updated.pkl` dosyasında yer almaktadır.
- Flask sunucusu, kullanıcı etkileşimlerini ve öneri sistemini kontrol eder.
- Web arayüzü Bootstrap ile tasarlanmış, dinamik yapı Jinja template engine ile oluşturulmuştur.

## **Klasör/Dosya Yapısı:**

- `app.py` – Uygulamanın ana çalıştırma dosyası
- `model.ipynb` – Resim özniteliklerinin çıkarıldığı çalışma dosyası
- `Images_features.pkl` – Görsellerin öznitelik vektörleri
- `filenames_updated.pkl` – Görsellerin dosya yolları
- `static/` – Görsel içerikler ve stil dosyaları
- `templates/` – HTML tabanlı sayfalar (index, detay, sepet, öneriler vs.)

## **Temel Özellikler:**

- 44.000'den fazla ürün görseli ile çalışır.
- Görsel tabanlı benzerlik tespiti yapar.
- Dinamik sepet sistemi sayesinde kullanıcı etkileşimi desteklenir.
- Benzer ürün önerisi gerçek zamanlı yapılır.
- Modern, responsive web arayüzüne sahiptir.

### **Nasıl Çalıştırılır:**

1. Gerekli kütüphaneleri yükleyin:
    
    `pip install flask tensorflow scikit-learn numpy`
    
2. `app.py` dosyasını çalıştırın.
3. Tarayıcıda app.py çıktısında çıkan adrese gidin.

### **Not:**

Bu proje yalnızca eğitim ve gösterim amacıyla geliştirilmiştir. Ticari bir kullanım amacı taşımaz. Gerçek fiyat, stok veya ürün bilgisi içermez.