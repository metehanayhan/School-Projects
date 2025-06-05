# 13

### **1. Müşteri ve Konuşma Kayıtlarının Gruplama ile Sorgulanması**

### **Sorgu:**

```sql
select musteri.ad, musteri.soyad, KonusmaKaydi.yon, sum(saniye)
from KonusmaKaydi
inner join musteri on KonusmaKaydi.Musterikey = musteri.musterikey
group by musteri.ad, musteri.soyad, KonusmaKaydi.yon;
```

### **Açıklama:**

- **`inner join`**:
    - `KonusmaKaydi` ve `musteri` tabloları `Musterikey` sütunu üzerinden birleştirilir.
- **`group by`**:
    - Müşteri adı, soyadı ve konuşma yönü bazında gruplama yapılır.
- **`sum(saniye)`**:
    - Her müşteri için farklı konuşma türlerindeki toplam konuşma süresi hesaplanır.

---

### **2. CASE İfadesi ile Değer Dönüştürme**

### **Sorgu:**

```sql
Declare @degisken int;
set @degisken = (select top 1 KonusmaKaydi.yon from KonusmaKaydi);
select case @degisken
	when 1 then 'Sehir ici'
	when 2 then 'Sehirler Arasi'
	when 3 then 'Gsm'
end;
```

### **Açıklama:**

- **`@degisken` Tanımlama:**
    - Bir değişken tanımlanır ve `KonusmaKaydi` tablosundan ilk yön (`yon`) değeri atanır.
- **CASE Kullanımı:**
    - `@degisken` değerine göre:
        - `1` için "Sehir ici",
        - `2` için "Sehirler Arasi",
        - `3` için "Gsm" döndürülür.

---

### **3. Konuşma Sürelerini Türlerine Göre Gruplama**

### **Sorgu:**

```sql
select musteri.Ad, Musteri.Soyad,
sum(case KonusmaKaydi.Yon when 1 then KonusmaKaydi.Saniye end) as Sehir_ici,
sum(case KonusmaKaydi.Yon when 2 then KonusmaKaydi.Saniye end) as Sehirler_arasi,
sum(case KonusmaKaydi.Yon when 3 then KonusmaKaydi.Saniye end) as Gsm
from KonusmaKaydi
inner join musteri on musteri.MusteriKey = KonusmaKaydi.MusteriKey
group by musteri.Ad, Musteri.Soyad;
```

### **Açıklama:**

- **CASE İfadesi:**
    - Konuşma yönüne (`KonusmaKaydi.Yon`) göre süreler gruplandırılır:
        - `1`: Şehir içi konuşma süresi.
        - `2`: Şehirler arası konuşma süresi.
        - `3`: GSM konuşma süresi.
- **`sum` ve `group by`:**
    - Her müşteri için bu tür konuşmaların toplam süreleri hesaplanır.

---

### **4. Hatalı Sorgu İncelemesi**

### **Hatalı Sorgu:**

```sql
select musteri.Ad, Musteri.Soyad,
if KonusmaKaydi.Yon = 1 begin sum(KonusmaKaydi.Saniye) end else begin null end,
sum(case KonusmaKaydi.Yon when 2 then KonusmaKaydi.Saniye else null end) as Sehirler_arasi,
sum(case KonusmaKaydi.Yon when 3 then KonusmaKaydi.Saniye else null end) as Gsm
from KonusmaKaydi
inner join musteri on musteri.MusteriKey = KonusmaKaydi.MusteriKey
group by musteri.Ad, Musteri.Soyad;
```

### **Hata Analizi:**

- **`if` Kullanımı:**
    - SQL'de `if` ifadesi doğrudan sorgu içinde kullanılamaz. Bunun yerine **CASE** kullanılmalıdır.
- **Doğru Kullanım Örneği:**
    
    ```sql
    select musteri.Ad, Musteri.Soyad,
    sum(case when KonusmaKaydi.Yon = 1 then KonusmaKaydi.Saniye else null end) as Sehir_ici,
    sum(case when KonusmaKaydi.Yon = 2 then KonusmaKaydi.Saniye else null end) as Sehirler_arasi,
    sum(case when KonusmaKaydi.Yon = 3 then KonusmaKaydi.Saniye else null end) as Gsm
    from KonusmaKaydi
    inner join musteri on musteri.MusteriKey = KonusmaKaydi.MusteriKey
    group by musteri.Ad, Musteri.Soyad;
    ```
    

---

### **5. Özet ve Kullanım Alanları**

1. **Join Kullanımı:**
    - Tablolar arasında ilişkileri kurarak veri birleştirme yapılır.
    - Örneğin, müşteri bilgileri ve konuşma kayıtlarını birleştirmek.
2. **Gruplama ve Toplama:**
    - `GROUP BY` ve `SUM` kullanarak her müşteri için toplam konuşma sürelerini hesaplama.
3. **CASE İfadesi:**
    - Verilere koşullu işlemler uygulamak için kullanılır.
    - Örneğin, yön değerlerini okunabilir metinlere dönüştürmek.
4. **Değişken Kullanımı:**
    - Geçici sonuçları tutarak sorgularda kullanımı esneklik sağlar.

Bu yapılar, karmaşık veri analizleri yaparken güçlü araçlar sunar ve veritabanı yönetimini kolaylaştırır.

---

---

---

### **MS SQL Server'da Değişken Tanımlama, Değer Atama ve Listeleme**

SQL Server'da **Procedure**, **Trigger**, ve **Function** gibi programlama yapılarıyla çalışırken değişkenler sıkça kullanılır. Değişkenler, geçici veri saklama ve işlem yürütme için önemlidir.

---

### **Değişken Tanımlama Kuralları**

1. **@ ile Başlamalıdır:** Tüm değişken isimleri `@` ifadesi ile başlar.
2. **DECLARE İfadesi Kullanılır:** Değişken tanımlanırken `DECLARE` ifadesi kullanılır.
3. **İsim ve Veri Türü Belirtilir:** Değişkene bir isim verilir ve veri türü tanımlanır (örneğin, `INT`, `VARCHAR`, `DATE`).
4. **İlk Değer Atama (Opsiyonel):** Tanımlama sırasında değişkene ilk değer atanabilir.
    - Örneğin: `DECLARE @a INT = 10;`

---

### **Değişken Tanımlama ve Değer Atama**

### **1. Sabit Değer Atama**

```sql
-- Tanımlama ve sonrasında değer atama
DECLARE @a INT;
SET @a = 10;

DECLARE @isim VARCHAR(20);
SET @isim = 'Selma';

-- Tanımlama sırasında değer atama
DECLARE @b INT = 5;
DECLARE @isim2 CHAR(25) = 'Selvi';

-- Birden fazla değişken tanımlayıp değer atama
DECLARE @ad VARCHAR(20) = 'Mehmet', @soyad VARCHAR(20) = 'KAYA';
```

### **2. Tablodan Değer Atama**

Bir değişkene tabloda yer alan bir değeri atamak için **SET** veya **SELECT** kullanılabilir.

**SET Kullanımı:**

```sql
DECLARE @isim VARCHAR(20);
SET @isim = (SELECT ograd FROM ogrenci WHERE ogrno = 10);
```

**SELECT Kullanımı:**

```sql
DECLARE @isim VARCHAR(20);
SELECT @isim = ograd FROM ogrenci WHERE ogrno = 10;

-- Birden fazla değişkene aynı anda değer atama
DECLARE @ad VARCHAR(20), @soyad VARCHAR(20);
SELECT @ad = ograd, @soyad = ogrsoyad FROM ogrenci WHERE ogrno = 3;
```

**Dikkat:**

- Sorgunun **tek bir kayıt döndürmesi gerekir.** Eğer birden fazla kayıt dönerse, değişkene yalnızca son kaydın değeri atanır.

---

### **Değişkenin Değerini Gösterme**

Değişkenlerin içindeki değeri göstermek için **SELECT** veya **PRINT** kullanılır:

### **1. SELECT Kullanımı**

```sql
SELECT @isim;
SELECT @ad, @soyad;
```

- Çıktı, tablo formatında gösterilir.

### **2. PRINT Kullanımı**

```sql
PRINT @isim;
PRINT @ad + ' ' + @soyad;
```

- Çıktı, yazı formatında gösterilir.
- **Dikkat:** `PRINT` ifadesinde **virgül** kullanılmaz; string birleştirme için `+` kullanılır.

---

### **Pratik Bilgiler**

1. **SET ile SELECT Arasındaki Fark:**
    - **SET:** Sadece bir değeri işlem yapar, birden fazla değer döndürürse hata alırsınız.
    - **SELECT:** Birden fazla değer dönerse sadece son değeri alır ve hata vermez.
2. **Performans:**
    - `SELECT`, birden fazla değişkene aynı anda değer atama imkanı sunduğu için daha hızlıdır.
3. **Hata Durumu:**
    - Eğer sorgu bir değer döndürmezse, değişken **NULL** olarak atanır.

---

### **Örnekler**

### **1. Öğrencinin adını ve soyadını bir değişkende tutma:**

```sql
DECLARE @ad VARCHAR(20), @soyad VARCHAR(20);
SELECT @ad = ograd, @soyad = ogrsoyad FROM ogrenci WHERE ogrno = 5;

PRINT @ad + ' ' + @soyad;
```

### **2. Satış toplamını hesaplayan bir değişken:**

```sql
DECLARE @toplamSatis INT;
SET @toplamSatis = (SELECT SUM(tutar) FROM satislar WHERE yil = 2023);

PRINT 'Toplam Satış: ' + CAST(@toplamSatis AS VARCHAR);
```

### **3. Ürün kategorisi bilgilerini tutma:**

```sql
DECLARE @kategoriAdi VARCHAR(30);
SELECT @kategoriAdi = kategori FROM urun_kategorileri WHERE id = 2;

PRINT 'Seçilen Kategori: ' + @kategoriAdi;
```

### **4. Birden fazla kayıt olduğunda son değeri atama:**

```sql
DECLARE @urunAdi VARCHAR(50);
SELECT @urunAdi = urun_ad FROM urunler;

PRINT 'Son ürün: ' + @urunAdi;
-- Birden fazla ürün varsa sadece son kaydın adı atanır.
```

### **5. Değişkenlerin SELECT ile gösterilmesi:**

```sql
DECLARE @ad VARCHAR(20) = 'Ali', @soyad VARCHAR(20) = 'Veli';
SELECT @ad AS Ad, @soyad AS Soyad;
```

---

### **Soru-Cevaplar**

### **Teorik Sorular**

1. **SQL Server'da bir değişken nasıl tanımlanır?**
    
    **Cevap:**
    
    - `DECLARE` ifadesi ile tanımlanır. Değişken isimleri `@` işareti ile başlamalıdır.Örnek: `DECLARE @degiskenAdi INT;`
2. **SET ve SELECT arasındaki fark nedir?**
    
    **Cevap:**
    
    - `SET` sadece bir değeri işleyebilir, birden fazla değer dönerse hata alırsınız.
    - `SELECT`, birden fazla değer dönerse son değeri alır.
3. **Bir değişkenin değerini nasıl gösterebiliriz?**
    
    **Cevap:**
    
    - `SELECT` veya `PRINT` ifadeleri kullanılır.
        - `SELECT` tablo formatında gösterir.
        - `PRINT` metin olarak yazdırır.

---

### **Kodlama Soruları**

1. **Bir değişken tanımlayın ve ona 20 atayın, ardından değerini yazdırın.**
    
    **Cevap:**
    
    ```sql
    DECLARE @sayi INT = 20;
    PRINT @sayi;
    ```
    
2. **Birden fazla değişken tanımlayın ve tabloya bağlı değer atayın.**
    
    **Cevap:**
    
    ```sql
    DECLARE @ad VARCHAR(20), @soyad VARCHAR(20);
    SELECT @ad = ograd, @soyad = ogrsoyad FROM ogrenci WHERE ogrno = 10;
    
    PRINT @ad + ' ' + @soyad;
    ```
    
3. **Bir tablodan toplam satış miktarını bir değişkene atayın ve yazdırın.**
    
    **Cevap:**
    
    ```sql
    DECLARE @toplamSatis INT;
    SET @toplamSatis = (SELECT SUM(tutar) FROM satislar);
    
    PRINT 'Toplam Satış: ' + CAST(@toplamSatis AS VARCHAR);
    ```
    
4. **Bir sorgu sonucunda son dönen kaydın değerini değişkene atayın.**
    
    **Cevap:**
    
    ```sql
    DECLARE @sonUrun VARCHAR(50);
    SELECT @sonUrun = urun_ad FROM urunler;
    
    PRINT 'Son ürün: ' + @sonUrun;
    ```