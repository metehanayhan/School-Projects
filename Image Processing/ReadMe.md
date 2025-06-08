# Gerçek Zamanlı Duygu Takibi Sistemi

Bu proje, gerçek zamanlı yüz analizi yaparak kullanıcının anlık ruh halini tespit eden ve buna uygun bir emoji ile arayüzde görsel geri bildirim sağlayan bir yapay zeka uygulamasıdır. Sistem aynı zamanda tespit edilen duyguları zaman damgası ile birlikte kayıt altına alır ve daha sonra bu verileri grafiksel olarak analiz edebilme imkanı sunar. Kullanıcılar "Başlat" butonuna bastıklarında sistem aktif hale gelir, yüz ifadeleri analiz edilerek duygu etiketi ve karşılığı olan emoji ekranda gösterilir.

## **Temel Özellikler:**

- Kullanıcının kamerasından gelen görüntü üzerinde gerçek zamanlı yüz tanıma ve duygu analizi yapılır.
- Kullanılan derin öğrenme tabanlı kütüphane: **DeepFace**
- Tanımlanan 7 duygu: *happy, sad, angry, surprise, neutral, fear, disgust*
- Her tespit edilen duygu, zaman bilgisiyle birlikte `.csv` dosyasına kaydedilir.
- Kayıt altına alınan bu veriler ayrı bir analiz modülü (`rapor.py`) ile görselleştirilebilir.
- Kullanıcı arayüzü, Python’un **Tkinter** kütüphanesi ile geliştirilmiştir.
- Duygulara karşılık gelen özel hazırlanmış emoji görselleri ekranda gösterilir.

## **Kullanılan Teknolojiler:**

- Python 3
- OpenCV – Görüntü işleme
- DeepFace – Derin öğrenme ile duygu analizi
- Tkinter – Grafik arayüz
- Pillow – Görüntü format dönüşümü
- Pandas & Matplotlib – Veri analizi ve grafik çizimi

## **Dosya Açıklamaları:**

- `main.py` → Uygulamanın tüm bileşenlerini içeren ana dosya. Arayüz, kamera, analiz ve emoji sistemi bu dosyada birleştirilmiştir.
- `rapor.py` → Gün içinde toplanan duygu kayıtlarını saat saat gösteren bir grafik oluşturur.
- `duygu_kaydi.csv` → Sistem çalıştıkça oluşan zaman-duygu kayıt dosyasıdır.
- `emojipng/` klasörü → Her duygu için görsel emoji dosyalarının bulunduğu klasördür.

## **Uygulamanın Çalışması:**

1. Uygulama çalıştırıldığında kamera açılır ve yüz tanıma işlemi başlatılır.
2. Her saniyede bir yüz ifadesi analiz edilir ve duygu etiketi tespit edilir.
3. Tespit edilen duygu, ekranda metin olarak ve emoji ile gösterilir.
4. Aynı zamanda `duygu_kaydi.csv` dosyasına zaman bilgisiyle birlikte kaydedilir.
5. `rapor.py` dosyası çalıştırılarak bu kayıtlar grafiksel olarak incelenebilir.

### **Not:**

Bu proje yalnızca eğitim ve deneysel amaçlarla geliştirilmiştir. Gerçek klinik değerlendirme aracı değildir. Kütüphaneler dışa bağımlıdır, bu yüzden çalıştırılmadan önce gerekli paketlerin kurulması gerekir.