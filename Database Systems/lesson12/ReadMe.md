# 12

### **SQL Stored Procedure ve T-SQL Kullanımı: Ders**

---

[Daha Detaylı](12%2014ee67fac61d80dea6f1e8cb18cec2d2/Daha%20Detayl%C4%B1%2016be67fac61d80259a99c9b023dd8cdd.md)

### **1. Stored Procedure Nedir?**

- **Stored Procedure**, SQL'de sık kullanılan sorguları veya işlemleri bir defa yazıp defalarca çağırmanıza olanak sağlayan bir programlama birimidir.
- **Avantajları:**
    1. **Yeniden Kullanılabilirlik:** Kod tekrarını azaltır.
    2. **Performans:** İlk çalıştırmada derlenir, sonraki çağrılarda daha hızlı çalışır.
    3. **Güvenlik:** Kaynak kodu gizlenebilir.
    4. **Bakım Kolaylığı:** Değişiklikler merkezi bir yerde yapılabilir.

---

### **2. Stored Procedure Yazma ve Çalıştırma**

### **Basit Bir Stored Procedure:**

```sql
create procedure up_MusteriGetir as
Begin
	select * from TblMusteriler
end
```

- `TblMusteriler` tablosundaki tüm verileri getirir.
- **Çağırma Yolları:**
    
    ```sql
    exec up_MusteriGetir;
    execute up_MusteriGetir;
    ```
    

### **Stored Procedure Silme:**

```sql
drop procedure up_MusteriGetir;
```

---

### **3. Parametre Alan Stored Procedure**

### **Parametreli Procedure Oluşturma:**

```sql
create procedure up_MusteriGetir_CinsiyetveYasagore
@Cins int,
@Yas int
as
Begin
	select * from TblMusteriler where cinsId = @Cins and yas = @Yas
end
```

- **Parametreler:**
    - `@Cins`: Cinsiyet ID'si.
    - `@Yas`: Müşterinin yaşı.
- **Çalıştırma:**
    
    ```sql
    exec up_MusteriGetir_CinsiyetveYasagore 1, 27;
    ```
    

### **Procedure Üzerinde Değişiklik Yapma (ALTER):**

```sql
alter procedure up_MusteriGetir_CinsiyetveYasagore
@cins int,
@yas int
with encryption -- Kaynak kodu gizler
as
begin
	select * from TblMusteriler where cinsId = @Cins and yas = @Yas
end
```

- **Kaynak kodu gizleme:** `sp_helptext` ile procedure kodları görüntülenemez.

### **Procedure Kodlarını Görme:**

```sql
sp_helptext up_MusteriGetir_CinsiyetveYasagore;
```

---

### **4. Output Parametreli Stored Procedure**

### **Output Kullanımı:**

```sql
create proc up_CinsiyeteGoreCalisanSayisi
@Cins int, -- Input parameter
@CalisanSayisi int output -- Output parameter
as
begin
	select @CalisanSayisi = count(*) from TblMusteriler where cinsId = @Cins
end
```

- **Çalıştırma:**
    
    ```sql
    Declare @ToplamCalisanSayisi int
    execute up_CinsiyeteGoreCalisanSayisi 1, @ToplamCalisanSayisi output;
    select @ToplamCalisanSayisi;
    ```
    
- **Output Parametresi:** İşlem sonucunda dönen değeri dışarı aktarır.

---

### **5. T-SQL Koşulları ve Döngüleri**

### **Koşullu İfadeler (IF-ELSE):**

- **Örnek:**
    
    ```sql
    Declare @sayi int;
    select @sayi = count(*) from TblUrunler;
    if @sayi > 1
        print '1 den fazla kayıt var, kayıt sayısı:' + cast(@sayi as varchar(5));
    else
        print 'Kayıt yok';
    ```
    

### **Döngüler (WHILE):**

- **Örnek:**
    
    ```sql
    Declare @sayi int;
    select @sayi = count(*) from TblUrunler;
    while @sayi >= 1
    begin
        print @sayi;
        set @sayi = @sayi - 1;
    end
    ```
    

### **İç İçe Döngüler:**

- **Örnek:**
    
    ```sql
    Declare @i int = 1;
    Declare @j int = 1;
    while @i <= 10
    begin
        while @j <= 20
        begin
      	  print 'A';
      	  set @j = @j + 1;
        end
        set @j = 1;
        set @i = @i + 1;
    end
    ```
    

---

### **6. CASE İfadesi**

### **CASE Kullanımı:**

```sql
Declare @ay int;
set @ay = 1;
select case @ay
	when 1 then 'Ocak'
	when 2 then 'Şubat'
	when 3 then 'Mart'
	when 4 then 'Nisan'
	when 12 then 'Aralık'
	else 'Geçersiz Ay'
end;
```

- `CASE`, farklı durumlara göre sonuç döndürür.

---

### **Özet: Stored Procedure ve T-SQL**

1. **Stored Procedure:**
    - SQL işlemlerini düzenlemek ve tekrar kullanmak için yazılır.
    - Parametreli, output parametreli ve kaynak kodu gizli yazılabilir.
2. **Koşullar ve Döngüler:**
    - `IF-ELSE`: Koşula bağlı işlem yapar.
    - `WHILE`: Döngüsel işlemler için kullanılır.
3. **CASE İfadesi:**
    - Durumlara göre işlem yapar ve sonuç döndürür.

Bu yapılar, veritabanı yönetimini daha esnek, güvenli ve etkili hale getirir.

---

### **Stored Procedure Kullanmanın Avantajları**

---

### **1. Execution Plan Kontrolü**

- **Execution Plan (EP):** SQL sorgusunun çalıştırılacağı en verimli yolu seçen bir planlama mekanizmasıdır. Özellikle büyük veri tabanlarında sorguların performansını artırmak için önemlidir.
- **Execution Plan Türleri:**
    1. **Estimated Execution Plan (Ctrl + L):** Sorguyu çalıştırmadan, tahmini bir plan oluşturur.
    2. **Actual Execution Plan (Ctrl + M):** Sorgu çalıştırıldıktan sonra, gerçekten kullanılan planı gösterir.
- **Stored Procedure ile EP’nin Avantajı:**
    - Stored Procedure’ler bir kez derlenir ve aynı EP defalarca kullanılır.
    - Dinamik sorgular (ad-hoc queries) her seferinde yeni bir EP oluşturabilir. Bu, performans kaybına neden olur.
    - Örnek:
        
        ```sql
        -- Dinamik sorguda EP her seferinde yeniden oluşturulur
        SELECT * FROM TblMusteriler WHERE id = 1;
        SELECT * FROM TblMusteriler WHERE id = 2;
        
        -- Stored Procedure ile aynı EP tekrar tekrar kullanılır
        EXEC upMusteriGetir @id = 1;
        EXEC upMusteriGetir @id = 2;
        ```
        

### **2. Kod Bakım Maliyetini Azaltır**

- **Sorun:** Aynı sorgunun farklı yerlerde tekrar edilmesi bakım maliyetini artırır.
    - Örneğin, `SELECT * FROM TblMusteriler` sorgusunu 5 farklı yerde kullanıyorsanız, değişiklik gerektiğinde 5 yerde düzenleme yapmanız gerekir.
- **Çözüm:** Stored Procedure ile sorgular merkezi bir yerde tanımlanır ve gerektiğinde sadece Stored Procedure güncellenir.

---

### **3. SQL Injection’dan Koruma**

- **SQL Injection:** Bir saldırganın, sorgulara kötü niyetli ifadeler ekleyerek veritabanı bilgilerine erişim sağlamasıdır.
    - Örneğin:
        
        ```sql
        -- Güvenlik açığı barındıran sorgular
        SELECT * FROM TblMusteriler WHERE isim = 'ali' OR 1=1;
        SELECT * FROM TblUrunKategori WHERE kategori = 'gida' OR 1=1;
        ```
        
    - Yukarıdaki sorgular, "OR 1=1" ifadesi sayesinde tüm tablonun bilgisini getirir.
- **Stored Procedure ile Güvenlik:**
    - Parametreler kontrol edilir ve kötü niyetli girişler engellenir.
    - Örnek:
        
        ```sql
        CREATE PROCEDURE upKategoriGetir
        @kategori NVARCHAR(50)
        AS
        BEGIN
            SELECT * FROM TblUrunKategori WHERE kategori = @kategori;
        END;
        ```
        

---

### **4. Network Trafiğini Azaltır**

- Dinamik sorgular ile sunucuya fazla sayıda istek gönderilmesi network trafiğini artırır.
- Stored Procedure ile:
    - Sunucu tarafında bir kez çalıştırılır.
    - İstemci-sunucu arasındaki veri akışı azalır.
    - Örnek:Bu yöntem, istemci-sunucu arasındaki sorgu boyutunu minimize eder.
        
        ```sql
        EXEC upMusteriGetir @id = 1;
        ```
        

---

### **Stored Procedure ile İlgili Sorular ve Cevapları**

### **Teorik Sorular**

1. **Stored Procedure nedir ve neden kullanılır?**
    
    **Cevap:**
    
    - Stored Procedure, tekrar eden SQL sorgularını bir prosedür olarak saklayan ve parametrik olarak çalışan bir yapıdır.
    - Avantajları:
        - Kod tekrarını önler.
        - EP’yi optimize eder.
        - SQL Injection’a karşı güvenlik sağlar.
        - Network trafiğini azaltır.
2. **Execution Plan (EP) nedir ve Stored Procedure ile ilişkisi nedir?**
    
    **Cevap:**
    
    - EP, bir sorgunun en verimli şekilde nasıl çalıştırılacağını belirler.
    - Stored Procedure kullanıldığında EP bir kez oluşturulur ve aynı parametrelerle tekrar kullanılır, performans artar.
3. **Stored Procedure ile dinamik sorgular arasında fark nedir?**
    
    **Cevap:**
    
    - Dinamik sorgular her seferinde yeni bir EP oluşturur.
    - Stored Procedure, bir kez derlenir ve aynı EP tekrar tekrar kullanılır.
4. **SQL Injection nedir? Stored Procedure bunu nasıl engeller?**
    
    **Cevap:**
    
    - SQL Injection, sorgulara kötü niyetli ifadeler eklenerek veritabanına erişim sağlama saldırısıdır.
    - Stored Procedure, parametrik sorgu yapısıyla kullanıcı girişlerini kontrol eder ve bu tür saldırılara karşı güvenlik sağlar.

---

### **Kodlama Soruları**

1. **`TblMusteriler` tablosundaki bir müşteriyi `id` parametresine göre getiren bir Stored Procedure yazın.Cevap:**
    
    ```sql
    CREATE PROCEDURE upMusteriGetir
    @id INT
    AS
    BEGIN
        SELECT * FROM TblMusteriler WHERE id = @id;
    END;
    ```
    
2. **Kategori adına göre ürünleri getiren bir Stored Procedure yazın.Cevap:**
    
    ```sql
    CREATE PROCEDURE upKategoriyeGoreUrunGetir
    @kategori NVARCHAR(50)
    AS
    BEGIN
        SELECT TblUrunler.ad, TblUrunler.fiyat
        FROM TblUrunler
        INNER JOIN TblUrunKategori ON TblUrunler.urun_kategori_id = TblUrunKategori.id
        WHERE TblUrunKategori.kategori = @kategori;
    END;
    ```
    
3. **Müşterilerin isimlerini ve şehirlerini getiren bir Stored Procedure yazın.Cevap:**
    
    ```sql
    CREATE PROCEDURE upMusteriSehirBilgisi
    AS
    BEGIN
        SELECT isim, sehir FROM TblMusteriler;
    END;
    ```
    
4. **Bir ürünün fiyatını güncelleyen Stored Procedure yazın.Cevap:**
    
    ```sql
    CREATE PROCEDURE upUrunFiyatGuncelle
    @urunId INT,
    @yeniFiyat DECIMAL(10, 2)
    AS
    BEGIN
        UPDATE TblUrunler
        SET fiyat = @yeniFiyat
        WHERE id = @urunId;
    END;
    ```
    
5. **Bir müşteriyi id’sine göre silen bir Stored Procedure yazın.Cevap:**
    
    ```sql
    CREATE PROCEDURE upMusteriSil
    @id INT
    AS
    BEGIN
        DELETE FROM TblMusteriler WHERE id = @id;
    END;
    ```
    

---

### **Doğru/Yanlış Soruları**

1. **(D/Y)** Stored Procedure, parametre alabilir.
    
    **Cevap:** Doğru.
    
2. **(D/Y)** Stored Procedure ile aynı sorgu birden çok yerde kullanılamaz.
    
    **Cevap:** Yanlış.
    
3. **(D/Y)** Stored Procedure, SQL Injection’a karşı güvenlik sağlar.
    
    **Cevap:** Doğru.
    
4. **(D/Y)** Execution Plan, yalnızca dinamik sorgular için çalışır.
    
    **Cevap:** Yanlış.
    
5. **(D/Y)** Stored Procedure, istemci-sunucu arasındaki network trafiğini azaltır.
    
    **Cevap:** Doğru.
    

---