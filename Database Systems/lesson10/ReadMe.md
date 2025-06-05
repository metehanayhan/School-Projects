# 10

### **SQL Komutları, İşlevleri ve Uygulamaları: Ders**

---

### **1. Yeni Bir Tablo Oluşturma ve Veri Ekleme**

- **Tablo oluşturma:**
    
    ```sql
    create table Tblcinsiyet(
    id int primary key,
    cinsiyet varchar(10) not null)
    ```
    
    - `Tblcinsiyet` tablosunu oluşturuyoruz.
    - `id`: Birincil anahtar olarak tanımlanır.
    - `cinsiyet`: Cinsiyet bilgilerini tutar, boş geçilemez (`not null`).
- **Veri ekleme:**
    
    ```sql
    insert into Tblcinsiyet values (1, 'Kadın'), (2, 'Erkek'), (3, 'Bilinmeyen');
    ```
    
    - `INSERT INTO` ile tabloya üç farklı cinsiyet bilgisi ekleniyor.

---

### **2. Tablolara Kolon Eklemek**

- **Var olan bir tabloya yeni bir kolon ekleme:**
    
    ```sql
    Alter table TblMusteriler add cinsId int foreign key references Tblcinsiyet(id);
    ```
    
    - `TblMusteriler` tablosuna `cinsId` adlı yeni bir sütun eklenir.
    - Bu sütun `Tblcinsiyet` tablosundaki `id` sütununa dış anahtar (foreign key) olarak bağlanır.
    - **Amaç:** Müşteri ile cinsiyet arasındaki ilişkiyi tanımlamak.

---

### **3. Varsayılan Değer Tanımlama**

- **Default Constraint Kullanımı:**
    
    ```sql
    alter table TblMusteriler add constraint DF_TblMusteriler_cinsId default 3 for cinsId;
    ```
    
    - Eğer `TblMusteriler` tablosuna yeni bir kayıt eklenirken `cinsId` belirtilmezse, otomatik olarak 3 (`Bilinmeyen`) atanır.
- **Örnek Veri Ekleme:**
    
    ```sql
    insert into TblMusteriler (isim, soyisim, mail) values ('Veli', 'Atak', 'va@gmail.com');
    ```
    
    - `cinsId` belirtilmediği için varsayılan değer 3 atanır.

---

### **4. Varsayılan Değerin Kaldırılması**

- **Varsayılan değeri kaldırmak:**
    
    ```sql
    alter table TblMusteriler drop constraint DF_TblMusteriler_cinsId;
    ```
    
    - Bu işlemden sonra `cinsId` sütunu için varsayılan değer geçerli olmaz.

---

### **5. Veri Bütünlüğü Sağlama (Constraint Kullanımı)**

- **Check Constraint Kullanımı:**
    
    ```sql
    alter table TblUrunler add constraint CK_TblUrunler_fiyatkontrol check (fiyat > 0 and fiyat < 1000);
    ```
    
    - `TblUrunler` tablosunda fiyatın sıfırdan büyük ve 1000'den küçük olması zorunluluğunu getirir.
    - Bu tür kısıtlamalar, yanlış veri girişini engeller.
- **Hatalı Veri Düzeltme:**
    
    ```sql
    update TblUrunler set fiyat = 25 where fiyat < 0;
    ```
    
    - Kısıtlamaları eklemeden önce yanlış girilmiş verileri düzeltiyoruz.

---

### **6. Görünümler (View)**

- **View Nedir?**
    - **View**, SQL'de sanal tablo anlamına gelir.
    - View, sorgu sonuçlarını bir tablo gibi kullanmanıza olanak tanır.
    - Asıl veriyi değiştirmez, yalnızca bir bakış sağlar.
- **View Oluşturma:**
    
    ```sql
    create view vwKategoriyeGoreUrunSayisi as
    select TblUrunKategori.kategori, count(*) as URUN_SAYISI
    from TblUrunKategori
    inner join TblUrunler on TblUrunKategori.id = TblUrunler.urun_kategori_id
    group by TblUrunKategori.kategori;
    ```
    
    - Bu view, her kategoriye ait ürün sayısını listeler.
    - `INNER JOIN` ile `TblUrunKategori` ve `TblUrunler` tabloları birleştirilir.
- **View Kullanma:**
    
    ```sql
    select * from vwKategoriyeGoreUrunSayisi;
    ```
    
    - `vwKategoriyeGoreUrunSayisi` adlı view'den veriler sorgulanır.
- **View Silme:**
    
    ```sql
    drop view vwKategoriyeGoreUrunSayisi;
    ```
    
    - Oluşturulan view'ı kaldırır.

---

### **7. Özel View Örneği**

- **Filtrelenmiş View:**
    
    ```sql
    create view vwKategoriyeGoreUrunSayisiBiskuvi as
    select TblUrunKategori.kategori, count(*) as URUN_SAYISI
    from TblUrunKategori
    inner join TblUrunler on TblUrunKategori.id = TblUrunler.urun_kategori_id
    where TblUrunKategori.kategori = 'Biskuvi'
    group by TblUrunKategori.kategori;
    ```
    
    - Yalnızca "Bisküvi" kategorisindeki ürün sayısını gösteren bir view.
- **Kullanımı:**
    
    ```sql
    select * from vwKategoriyeGoreUrunSayisiBiskuvi;
    ```
    

---

### **Özet: SQL'de Tablo Tasarımı ve Yönetimi**

1. **Tablo Tasarımı:**
    - **Kolonların türü** ve **birincil anahtar** belirlenir.
    - Gerekirse **dış anahtar** ile diğer tablolarla ilişki kurulur.
2. **Constraint Kullanımı:**
    - **Default Constraint:** Varsayılan değerler tanımlanır.
    - **Check Constraint:** Veri doğruluğu sağlanır.
3. **View Kullanımı:**
    - Görünümler, büyük sorguların daha düzenli şekilde kullanılmasını sağlar.
    - Veriyi değiştirmeden yalnızca görüntüleme yapar.

Bu yapı ve kuralları öğrenmek, daha temiz, organize ve hatasız bir veritabanı tasarımı yapmanızı sağlar.

---

### **SQL'de VIEW (Görünüm) Nedir?**

- **View**, SQL'de birden çok tablodan elde edilen sonuçları bir sanal tabloya kaydetmek için kullanılan bir yapıdır.
- Fiziksel bir tablo değildir, sorgu sonucunu sanal olarak saklar.
- **İhtiyaç Durumu:**
    - Farklı tablolardaki veriler birleştirilmek istendiğinde **JOIN** kullanılır. Bu tür sorgular tekrar tekrar yazmak yerine **VIEW** kullanarak sorgu bir defa tanımlanır ve gerektiğinde çağrılır.
    - Örneğin, birden fazla tabloyu birleştirerek ürün kategorileri ve ürün sayılarını göstermek için bir **VIEW** oluşturulabilir.

---

### **VIEW Kullanmanın Avantajları**

1. **Zaman Kazandırır:**
    - Karmaşık sorgular her seferinde yazılmak yerine bir kez yazılır ve daha sonra kullanılır.
2. **Güvenlik Sağlar:**
    - Verilerin tamamını değil, sadece belirli sütun veya satırları gösterebilirsiniz.
    - Örneğin, bir ürün tablosunda fiyat bilgisini gizleyerek yetkisiz kullanıcıların görmesini engelleyebilirsiniz.
3. **Karmaşıklığı Azaltır:**
    - Veritabanındaki tablolar arasında ilişkilendirmeyi kullanıcıdan gizler, böylece veritabanı daha anlaşılır hale gelir.
4. **Satır ve Sütun Seviyesinde Güvenlik:**
    - **Satır Seviyesi:** Örneğin, sadece "BİSKÜVİ" kategorisindeki ürünlerin gösterilmesi istenebilir.
    - **Sütun Seviyesi:** Örneğin, fiyat bilgilerinin görüntülenmesi istenmezse bu bilgiyi gizleyebilirsiniz.

---

### **VIEW Kullanımında Dikkat Edilmesi Gerekenler**

1. **Parametre Desteği:**
    - View'ler dışarıdan parametre alamaz.
2. **Aggregate Fonksiyonlar:**
    - Örneğin, `SUM`, `COUNT`, `MAX`, `MIN` gibi fonksiyonlar kullanılırken **AS** ile kolon adı verilmelidir.
    - İsimsiz kolonlar ile view oluşturulamaz.
3. **DML İşlemleri (INSERT, UPDATE, DELETE):**
    - **Tek Tablodan Oluşturulan View:** Bu işlemler yapılabilir ve base tabloyu etkiler.
    - **Çok Tablodan Oluşturulan View:** Bu işlemler desteklenmez.

---

### **VIEW ile Örnekler**

### 1. **Karmaşık Sorgunun VIEW ile Basitleştirilmesi**

- **Tablolar:**
    - `TblUrunKategori`: Ürün kategorileri.
    - `TblUrunler`: Ürünler.

```sql
-- Ürün kategorilerine göre toplam ürün sayısı
SELECT TblUrunKategori.kategori, COUNT(*) AS URUN_SAYISI
FROM TblUrunKategori
INNER JOIN TblUrunler ON TblUrunKategori.id = TblUrunler.urun_kategori_id
GROUP BY TblUrunKategori.kategori;

-- Bu sorguyu bir VIEW haline getirelim:
CREATE VIEW vwKategoriGoreUrunSayisi AS
SELECT TblUrunKategori.kategori, COUNT(*) AS URUN_SAYISI
FROM TblUrunKategori
INNER JOIN TblUrunler ON TblUrunKategori.id = TblUrunler.urun_kategori_id
GROUP BY TblUrunKategori.kategori;
```

### 2. **Satır Seviyesinde Güvenlik**

- **Örneğin:** Sadece "BİSKÜVİ" kategorisindeki ürünleri görmek istediğinizde:

```sql
CREATE VIEW vwBiskuviKategoriUrunBilgisi AS
SELECT TblUrunler.ad, TblUrunler.fiyat, TblUrunler.barkod, TblUrunKategori.kategori
FROM TblUrunler
INNER JOIN TblUrunKategori ON TblUrunKategori.id = TblUrunler.urun_kategori_id
WHERE TblUrunKategori.kategori = 'BİSKÜVİ';
```

### 3. **Sütun Seviyesinde Güvenlik**

- **Örneğin:** Ürünlerin fiyat bilgisini gizlemek:

```sql
CREATE VIEW vwFiyatsizUrunBilgisi AS
SELECT TblUrunKategori.kategori, COUNT(*) AS URUN_SAYISI
FROM TblUrunKategori
INNER JOIN TblUrunler ON TblUrunKategori.id = TblUrunler.urun_kategori_id
GROUP BY TblUrunKategori.kategori;
```

---

### **VIEW Yönetimi**

1. **Bir View'in İçeriğini Görmek:**
    
    ```sql
    SP_HELPTEXT vwFiyatsizUrunBilgisi;
    ```
    
2. **Bir View'i Güncellemek:**
    
    ```sql
    ALTER VIEW vwFiyatsizUrunBilgisi AS
    SELECT TblUrunKategori.kategori, COUNT(*) AS URUN_SAYISI
    FROM TblUrunKategori
    INNER JOIN TblUrunler ON TblUrunKategori.id = TblUrunler.urun_kategori_id
    GROUP BY TblUrunKategori.kategori;
    ```
    
3. **Bir View'i Silmek:**
    
    ```sql
    DROP VIEW vwFiyatsizUrunBilgisi;
    ```
    

---

### **Sınavda Çıkabilecek Sorular**

### Teorik Sorular:

1. **VIEW nedir? Neden kullanılır? Avantajları nelerdir?**
2. VIEW kullanırken dikkat edilmesi gerekenler nelerdir?
3. Satır ve sütun seviyesinde güvenlik arasındaki farkları açıklayın.
4. Aggregate fonksiyonlar kullanıldığında dikkat edilmesi gerekenler nelerdir?

### Kodlama Soruları:

1. Aşağıdaki sorguyu bir VIEW haline getirin:
    
    ```sql
    SELECT kategori, AVG(fiyat) AS ORTALAMA_FIYAT
    FROM TblUrunler
    GROUP BY kategori;
    ```
    
2. Aşağıdaki özelliklere sahip bir VIEW oluşturun:
    - Ürünlerin sadece "BİSKÜVİ" kategorisine ait olanlarını gösterin.
    - Fiyat bilgisini gizleyin.
3. Bir view'i ALTER ve DROP ile güncelleme ve silme işlemlerini yazın.

### Doğru/Yanlış Soruları:

1. **(D/Y)** Birden fazla tablodan oluşturulan bir VIEW üzerinde INSERT işlemi yapılabilir.
2. **(D/Y)** VIEW, dışarıdan parametre alabilir.
3. **(D/Y)** VIEW, veritabanında fiziksel olarak bir tablo oluşturur.

---

### **Teorik Sorular ve Cevaplar**

### **1. View ile fiziksel tablo arasındaki fark nedir?**

**Cevap:**

- **View:** Sanal bir tablodur. Sorgu sonucunu saklar, fiziksel olarak veri içermez.
- **Fiziksel Tablo:** Veritabanında fiziksel olarak saklanan ve gerçek veri içeren yapıdır.

### **2. View oluştururken neden aggregate fonksiyonlara (SUM, COUNT, vb.) AS ile isim vermeliyiz?**

**Cevap:**
Aggregate fonksiyonların sonucu isimsiz olursa, oluşturulan VIEW'de bu kolonlara erişim sağlanamaz. Bu nedenle her fonksiyon sonucuna bir isim vermek zorunludur.

### **3. Çok tablodan oluşturulan bir VIEW üzerinde hangi işlemler yapılmaz?**

**Cevap:**
INSERT, UPDATE ve DELETE işlemleri yapılamaz çünkü bu işlemler birden fazla tabloyu etkiler ve tutarsızlıklara yol açabilir.

### **4. VIEW ile satır seviyesinde güvenlik nasıl sağlanır?**

**Cevap:**
Satır seviyesinde güvenlik, **WHERE** ifadesi kullanılarak istenmeyen satırların filtrelenmesiyle sağlanır. Örneğin, sadece belirli bir kategoriye ait ürünleri göstermek için `WHERE kategori = 'BİSKÜVİ'` gibi bir ifade kullanılabilir.

### **5. VIEW'ler dışarıdan parametre alabilir mi?**

**Cevap:**
Hayır, VIEW'ler dışarıdan parametre alamaz. Ancak sorguyu değiştirmek için **ALTER VIEW** kullanılabilir.

---

### **Kodlama Soruları ve Cevapları**

### **1. Aşağıdaki sorguyu bir VIEW haline getirin:**

```sql
SELECT kategori, AVG(fiyat) AS ORTALAMA_FIYAT
FROM TblUrunler
GROUP BY kategori;
```

**Cevap:**

```sql
CREATE VIEW vwOrtalamaFiyat AS
SELECT kategori, AVG(fiyat) AS ORTALAMA_FIYAT
FROM TblUrunler
GROUP BY kategori;
```

---

### **2. Ürünlerin fiyat bilgisi hariç tüm detaylarını görüntüleyen bir VIEW oluşturun.**

**Cevap:**

```sql
CREATE VIEW vwUrunDetaylariFiyatsiz AS
SELECT ad, barkod, urun_kategori_id
FROM TblUrunler;
```

---

### **3. "Çikolata" kategorisindeki ürünleri gösteren bir VIEW oluşturun.**

**Cevap:**

```sql
CREATE VIEW vwCikolataUrunleri AS
SELECT TblUrunler.ad, TblUrunler.fiyat, TblUrunKategori.kategori
FROM TblUrunler
INNER JOIN TblUrunKategori ON TblUrunKategori.id = TblUrunler.urun_kategori_id
WHERE TblUrunKategori.kategori = 'ÇİKOLATA';
```

---

### **4. Mevcut bir VIEW’in adını değiştirin. (Not: SQL doğrudan isim değiştirme komutu içermez.)**

**Cevap:**
SQL'de VIEW'in adını doğrudan değiştirmek için eski VIEW'i silip yeni bir VIEW oluşturmanız gerekir:

```sql
-- Eski VIEW’i sil
DROP VIEW vwEskiViewAdi;

-- Yeni VIEW’i oluştur
CREATE VIEW vwYeniViewAdi AS
SELECT * FROM TblUrunler;
```

---

### **5. Mevcut bir VIEW’i güncelleyerek yeni bir kolon ekleyin.**

**Cevap:**

```sql
ALTER VIEW vwKategoriGoreUrunSayisi AS
SELECT TblUrunKategori.kategori, COUNT(*) AS URUN_SAYISI, AVG(TblUrunler.fiyat) AS ORTALAMA_FIYAT
FROM TblUrunKategori
INNER JOIN TblUrunler ON TblUrunKategori.id = TblUrunler.urun_kategori_id
GROUP BY TblUrunKategori.kategori;
```

---

### **Doğru/Yanlış Soruları ve Cevapları**

1. **(D/Y)** VIEW'ler veritabanında fiziksel veri saklar.
    
    **Cevap:** Yanlış. VIEW'ler fiziksel veri saklamaz, yalnızca sorgu sonucunu sanal olarak kaydeder.
    
2. **(D/Y)** Çok tablodan oluşturulan bir VIEW üzerinde DELETE işlemi yapılabilir.
    
    **Cevap:** Yanlış. Çok tablodan oluşturulan VIEW'lerde DML işlemleri yapılamaz.
    
3. **(D/Y)** Bir VIEW oluşturulduktan sonra sorgu yapısı değiştirilemez.
    
    **Cevap:** Yanlış. **ALTER VIEW** komutu ile değiştirilebilir.
    
4. **(D/Y)** VIEW, güvenlik amacıyla kullanılabilir.
    
    **Cevap:** Doğru. VIEW ile belirli sütunları veya satırları göstermek mümkündür.
    
5. **(D/Y)** Bir VIEW'in içeriğini görmek için sp_helptext komutu kullanılır.
    
    **Cevap:** Doğru. `sp_helptext VIEW_ADI` komutu, VIEW’in sorgu yapısını gösterir.
    

---

### **Açıklamalı Sorular ve Cevaplar**

### **1. Neden VIEW kullanmalıyız?**

**Cevap:**

- Karmaşık sorguları kolaylaştırmak için.
- Veritabanı kullanıcılarına karmaşıklığı gizlemek için.
- Güvenlik amacıyla belirli verilerin görünürlüğünü sınırlandırmak için.
- Aynı sorgunun tekrar tekrar yazılmasını önlemek için.

---

### **2. Aşağıdaki sorguların VIEW oluşturma işlemlerindeki hataları bulun:**

**Sorgu:**

```sql
CREATE VIEW vwOrnek AS
SELECT TblUrunler.ad, MAX(fiyat)
FROM TblUrunler;
```

**Cevap:**

- `MAX(fiyat)` fonksiyonunun sonucu isimsizdir. Kolona bir isim verilmelidir.
- Düzeltilmiş hali:

```sql
CREATE VIEW vwOrnek AS
SELECT TblUrunler.ad, MAX(fiyat) AS EN_YUKSEK_FIYAT
FROM TblUrunler;
```

---

### **3. Bir ürün fiyatının 100'den düşük olduğu ürünleri görüntüleyen VIEW oluşturun.**

**Cevap:**

```sql
CREATE VIEW vwDusukFiyatliUrunler AS
SELECT ad, fiyat
FROM TblUrunler
WHERE fiyat < 100;
```