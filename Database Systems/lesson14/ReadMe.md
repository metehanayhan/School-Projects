# 14

[Daha Detaylı](14%2014ee67fac61d807390c7e64ea9d785cb/Daha%20Detayl%C4%B1%2016ce67fac61d8079b564fe1955db18a7.md)

### **Trigger ve Kullanımı: Ders**

---

### **1. Trigger Nedir?**

- **Trigger (Tetikleyici):**
    - Veritabanında belirli bir olay meydana geldiğinde otomatik olarak tetiklenen bir **Stored Procedure** çeşididir.
    - **Kullanıcı tarafından doğrudan çağrılamaz.** Sadece bağlı olduğu tablo üzerinde tanımlanan olay (INSERT, UPDATE, DELETE) gerçekleştiğinde tetiklenir.

---

### **2. Trigger Türleri**

1. **AFTER Trigger (FOR):**
    - Olay tamamlandıktan sonra tetiklenir.
    - Örneğin, bir kayıt eklendikten sonra tetiklenmesi.
2. **INSTEAD OF Trigger:**
    - Olay gerçekleşmeden önce devreye girer ve ilgili işlemi durdurup kendi işlemini yapar.
    - Örneğin, bir kaydı silme işlemini engellemek ve yerine başka bir işlem yapmak.

---

### **3. Örnekler ile Trigger Kullanımı**

### **3.1 Basit Bir Trigger Tanımlama**

- **Amaç:** Yeni ürün eklenirken eklenen kayıtları ekrana göstermek.

### **Trigger Tanımı:**

```sql
create trigger trg_tblUrunler_forInsert
on TblUrunler -- Trigger, `TblUrunler` tablosuna uygulanır.
for insert -- Sadece `INSERT` işlemleri için çalışır.
as
begin
	select * from inserted -- Yeni eklenen kayıtları `inserted` sanal tablosundan alır ve ekrana yazdırır.
end
```

### **Açıklama:**

- **`inserted` Sanal Tablosu:**
    - Trigger içinde, yeni eklenen kayıtları temsil eder.
    - Sadece **INSERT** işlemlerinde kullanılır.

### **Trigger'ın Tetiklenmesi:**

```sql
insert into TblUrunler values('Makarna', 2.75, 106, 1);
```

- Yeni bir ürün eklediğinizde, trigger çalışır ve eklenen verileri ekrana getirir.

---

### **3.2 Trigger ile Loglama**

- **Amaç:** Yeni eklenen ürünlerin bilgilerini bir log tablosuna kaydetmek.

### **Log Tablosu Oluşturma:**

```sql
create table TblUrunlerAudit(
id int primary key identity(1,1), -- Log kaydı için benzersiz bir ID.
AuditData nvarchar(100) -- Log mesajlarını tutar.
);
```

### **Trigger Tanımı:**

```sql
create trigger trg_TblUrunler_forinsert2
on TblUrunler -- `TblUrunler` tablosunda çalışır.
for insert -- Sadece `INSERT` işlemlerinde çalışır.
as
begin
	Declare @id int
	select @id = ID from inserted -- Yeni eklenen kaydın ID'si alınır.
	insert into TblUrunlerAudit
	values (cast(@id as nvarchar(5)) + ' id değerine sahip yeni ürün ' +
	cast(getdate() as nvarchar(20)) + ' tarihinde eklendi')
	-- Yeni ürün bilgisi log tablosuna eklenir.
end
```

### **Trigger'ın Tetiklenmesi:**

```sql
insert into TblUrunler values('Zurna Döner', 135, 109, 2);
```

- Yeni bir ürün eklendiğinde:
    - `TblUrunlerAudit` tablosuna, ürünün ID'si ve eklenme zamanı kaydedilir.
- **Log Sorgulama:**
    
    ```sql
    select * from TblUrunlerAudit;
    ```
    

---

### **4. Transaction ve Trigger**

### **Transaction Nedir?**

- Bir işlem sırasında bir grup sorgunun birlikte çalışmasını sağlar.
- Eğer işlem sırasında bir hata oluşursa, yapılan tüm değişiklikler geri alınır (**ROLLBACK**).

### **Trigger ve Transaction İlişkisi:**

- Trigger’lar kendi başlarına **COMMIT** veya **ROLLBACK** işlemi gerçekleştiremez.
- Ancak tetiklendikleri işlem içinde **Transaction** varsa, o işlemle birlikte çalışırlar.

---

### **5. Önemli Notlar**

1. **Trigger Kullanımında Dikkat Edilmesi Gerekenler:**
    - Fazla kullanımı performansı düşürebilir.
    - Karmaşık işlemler için `Stored Procedure` tercih edilebilir.
2. **Trigger Sanal Tabloları:**
    - **`inserted`**: Yeni eklenen kayıtlar.
    - **`deleted`**: Silinen kayıtlar.
    - **`updated`**: Güncellenen kayıtların hem eski hem de yeni değerlerini içerir.

---

### **Özet**

- **Trigger Tanımı:**
    
    ```sql
    create trigger [TriggerName]
    on [TableName]
    [FOR | AFTER | INSTEAD OF] [INSERT, UPDATE, DELETE]
    as
    begin
        -- İşlemler
    end
    ```
    
- **Trigger Kullanımı:**
    - Veri ekleme, güncelleme veya silme işlemlerini otomatik olarak takip edebilirsiniz.
    - Örneğin:
        - Loglama.
        - Veri doğrulama.
        - İlişkili tablolara otomatik veri ekleme.

Trigger'lar, veritabanı yönetiminde otomasyon sağlamak ve veri tutarlılığını korumak için güçlü bir araçtır. Ancak dikkatli tasarlanmalıdır, aksi takdirde karmaşıklık ve performans sorunlarına yol açabilir.

---

---

---

### **Trigger (Tetikleyici) Yapısı ve Kullanımı**

Trigger (Tetikleyici), bir tabloda **INSERT, UPDATE, DELETE** gibi olaylar meydana geldiğinde veya gelmeden önce otomatik olarak çalışan özel bir **Stored Procedure** türüdür. Trigger, veri bütünlüğünü sağlama, iş kurallarını uygulama ve otomatik işlemleri gerçekleştirme gibi durumlarda kullanılır.

---

### **Trigger’ın Temel Özellikleri**

1. **Otomatik Çalışır:** Trigger'lar manuel olarak çalıştırılamaz. Bir olay gerçekleştiğinde otomatik olarak devreye girer.
2. **Transaction Yönetimi:**
    - Trigger içinde **COMMIT** ve **ROLLBACK** doğrudan çağrılamaz. Ancak bir işlemin sonucu tetikleyici içinde dolaylı olarak kontrol edilebilir.
3. **Veri ve Referans Bütünlüğü:** Veri giriş veya değişikliklerinde kuralların ihlal edilmesini önler.
4. **Tablo ve Görünümlere Tanımlanabilir:** Trigger, bir tablo veya view (sanal tablo) üzerinde tanımlanabilir.
5. **Olay Bazlı Çalışır:** Belirli bir olay (INSERT, UPDATE, DELETE, CREATE vb.) tetiklendiğinde devreye girer.

---

### **Trigger Türleri**

### **1. DML Trigger (Data Manipulation Language Trigger)**

- **INSERT, UPDATE, DELETE** işlemleri sırasında tetiklenir.
- **Alt Türleri:**
    1. **AFTER Trigger:**
        - Olay gerçekleştikten sonra tetiklenir.
        - Örneğin, bir satır eklendikten sonra veriyi kontrol etmek.
    2. **INSTEAD OF Trigger:**
        - Olay gerçekleşmeden tetiklenir ve işlemi durdurur.
        - Örneğin, bir tabloya doğrudan ekleme yerine başka bir işlem gerçekleştirmek.

### **2. DDL Trigger (Data Definition Language Trigger)**

- **CREATE, ALTER, DROP** gibi veritabanı nesnesiyle ilgili işlemler için kullanılır.
- **Kullanım Alanları:**
    - Bir tabloyu silme işlemini engellemek.
    - Bir veritabanı nesnesi üzerinde izleme yapmak.

### **3. Logon Trigger**

- Kullanıcıların veritabanı sunucusuna bağlanma işlemini tetikler.
- **Amaç:**
    - Güvenlik için, yalnızca belirli bilgisayarlardan bağlanmaya izin vermek.
    - Maksimum oturum sayısını sınırlamak.

---

### **Trigger’ın Kullanım Alanları**

1. **Veri Bütünlüğü Sağlama:**
    - Girilen veya değiştirilen verilerin iş kurallarına uygun olup olmadığını kontrol eder.
    - Örneğin, ürün fiyatı negatif olamaz.
2. **Referans Bütünlüğü Sağlama:**
    - Bağımlı verileri günceller veya siler.
    - Örneğin, bir müşteri silindiğinde onun siparişlerini de silmek.
3. **Ek Bilgi Türetme:**
    - Veri değişiklikleri sırasında yeni bilgileri hesaplar ve saklar.
    - Örneğin, sipariş miktarındaki değişikliklere göre toplam fiyatı otomatik olarak hesaplar.

---

### **Trigger Örnekleri**

### **1. AFTER INSERT Trigger**

- Yeni bir sipariş eklendiğinde toplam sipariş miktarını güncelleyen bir tetikleyici:

```sql
CREATE TRIGGER trgAfterInsert
ON TblSiparis
AFTER INSERT
AS
BEGIN
    UPDATE TblToplamSiparis
    SET toplam_miktar = toplam_miktar + (SELECT SUM(miktar) FROM INSERTED);
END;
```

### **2. INSTEAD OF INSERT Trigger**

- "TblMusteri" tablosuna doğrudan veri eklenmesini engeller ve başka bir tabloya kaydeder:

```sql
CREATE TRIGGER trgInsteadOfInsert
ON TblMusteri
INSTEAD OF INSERT
AS
BEGIN
    INSERT INTO TblLog (kullanici, islem, tarih)
    SELECT isim, 'INSERT ENGELLENDI', GETDATE()
    FROM INSERTED;
END;
```

### **3. DELETE İşlemi için AFTER Trigger**

- Bir müşteri silindiğinde onun siparişlerini de silen bir tetikleyici:

```sql
CREATE TRIGGER trgAfterDelete
ON TblMusteri
AFTER DELETE
AS
BEGIN
    DELETE FROM TblSiparis
    WHERE musteri_id IN (SELECT id FROM DELETED);
END;
```

### **4. DDL Trigger ile DROP İşlemini Engelleme**

- "TblMusteri" tablosunun silinmesini engelleyen bir tetikleyici:

```sql
CREATE TRIGGER trgPreventDrop
ON DATABASE
FOR DROP_TABLE
AS
BEGIN
    IF EXISTS (SELECT * FROM sys.tables WHERE name = 'TblMusteri')
    BEGIN
        PRINT 'TblMusteri tablosu silinemez.';
        ROLLBACK;
    END;
END;
```

### **5. Logon Trigger ile Güvenlik Kontrolü**

- Sadece belirli bir IP adresinden bağlanmaya izin veren tetikleyici:

```sql
CREATE TRIGGER trgLogonCheck
ON ALL SERVER
FOR LOGON
AS
BEGIN
    IF ORIGINAL_LOGIN() NOT IN ('192.168.1.100')
    BEGIN
        PRINT 'Yetkisiz bağlantı engellendi.';
        ROLLBACK;
    END;
END;
```

---

### **Soru-Cevaplar**

### **Teorik Sorular**

1. **Trigger nedir ve neden kullanılır?Cevap:**
    - Trigger, belirli olaylar sırasında otomatik olarak çalışan bir Stored Procedure türüdür.
    - Veri bütünlüğünü sağlamak, referans ilişkilerini korumak ve ek işlemleri otomatikleştirmek için kullanılır.
2. **AFTER Trigger ve INSTEAD OF Trigger arasındaki fark nedir?Cevap:**
    - **AFTER Trigger:** Olay gerçekleştikten sonra çalışır.
    - **INSTEAD OF Trigger:** Olayı durdurur ve yerine başka işlemler yapar.
3. **Logon Trigger ne için kullanılır?Cevap:**
    - Kullanıcıların SQL Server’a bağlanma işlemlerini kontrol eder.
    - Örneğin, belirli bir bilgisayardan bağlanmaya izin vermek.

---

### **Kodlama Soruları**

1. **Bir müşteri silindiğinde onun siparişlerini de silen bir trigger yazın.Cevap:**
    
    ```sql
    CREATE TRIGGER trgAfterDelete
    ON TblMusteri
    AFTER DELETE
    AS
    BEGIN
        DELETE FROM TblSiparis
        WHERE musteri_id IN (SELECT id FROM DELETED);
    END;
    ```
    
2. **Sipariş miktarı güncellendiğinde toplam fiyatı hesaplayan bir trigger yazın.Cevap:**
    
    ```sql
    CREATE TRIGGER trgAfterUpdate
    ON TblSiparis
    AFTER UPDATE
    AS
    BEGIN
        UPDATE TblSiparis
        SET toplam_fiyat = miktar * birim_fiyat
        WHERE id IN (SELECT id FROM INSERTED);
    END;
    ```
    

---