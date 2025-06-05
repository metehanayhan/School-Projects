# 9. Ders

### **Veritabanı ve Tabloların Oluşturulması**

1. **Veritabanı Oluşturma:**
    
    ```sql
    create database VT_ALISVERİS2_
    ```
    
    - `VT_ALISVERİS2_` adında bir veritabanı oluşturur.
2. **Veritabanını Kullanma:**
    
    ```sql
    USE VT_ALISVERİS2_
    ```
    
    - SQL işlemlerinin bu veritabanında yapılmasını sağlar.
3. **Tabloların Tanımlanması:**
    - **`TblMusteriler`:**
    Müşteri bilgilerini tutar.
        
        ```sql
        create table TblMusteriler(
        id int primary key identity (1,1),
        isim varchar(30) not null,
        soyisim varchar(30) not null,
        tckn char(11) not null,
        ceptel char(11) not null,
        mail varchar(30) not null);
        ```
        
        - `id`: Otomatik artan birincil anahtar.
        - `isim`, `soyisim`, `tckn`, `ceptel`, `mail`: Müşteri detay bilgileri.
    - **`TblUrunKategori`:**
    Ürün kategorilerini tutar.
        
        ```sql
        create table TblUrunKategori(
        id int primary key identity(1,1),
        kategori varchar(30) not null)
        ```
        
    - **`TblUrunler`:**
    Ürün bilgilerini tutar ve kategorilerle ilişkilidir.
        
        ```sql
        create table TblUrunler(
        id int primary key identity(1,1),
        ad varchar(50) not null,
        fiyat float not null,
        barkod char(15) not null,
        urun_kategori_id int foreign key references TblUrunKategori(id))
        ```
        
    - **`TblMusteriAlisverisTarihi`:**
    Müşterilerin alışveriş tarihlerini kaydeder.
        
        ```sql
        create table TblMusteriAlisverisTarihi(
        id int primary key identity(1,1),
        tarih datetime default current_timestamp)
        ```
        
    - **`TblAlisverisKayit`:**
    Alışveriş kayıtlarını tutar.
        
        ```sql
        create table TblAlisverisKayit(
        alisveris_id int foreign key references TblMusteriAlisverisTarihi(id),
        musteri_id int foreign key references TblMusteriler(id),
        urun_id int foreign key references TblUrunler(id),
        urun_fiyat float not null,
        adet int not null)
        ```
        

### **Verilerin Eklenmesi**

1. **Müşteri Verileri Ekleme:**
    
    ```sql
    insert into TblMusteriler values ('Eslem','Göl','1111','5374512552','esslemty@gmail.com');
    ```
    
    - Müşteri bilgileri tabloya eklenir.
2. **Ürün Kategorileri ve Ürünler Ekleme:**
    
    ```sql
    insert into TblUrunKategori values ('GIDA'), ('ŞARKÜTERİ');
    insert into TblUrunler values ('Çay', 29.75, '100', 1);
    ```
    
    - Ürünler ve kategoriler ilişkilendirilir.
3. **Alışveriş Tarihinin Kaydedilmesi:**
    
    ```sql
    insert into TblMusteriAlisverisTarihi (tarih) values (current_timestamp);
    ```
    
    - Bir alışverişin gerçekleştiği tarih kaydedilir.

### **Alışveriş İşlemleri**

1. **Alışveriş Kaydı Oluşturma:**
    - Örneğin, 1. müşteri bir ürün alıyor:
        
        ```sql
        Declare @fiyat float
        set @fiyat = (select fiyat from TblUrunler where id = 1)
        insert into TblAlisverisKayit (alisveris_id, musteri_id, urun_id, urun_fiyat, adet)
        values (1, 1, 1, @fiyat, 3);
        ```
        
    - Ürün fiyatı `TblUrunler` tablosundan alınır ve `TblAlisverisKayit` tablosuna eklenir.
2. **Müşteri Alışveriş Geçmişini Sorgulama:**
    
    ```sql
    select TblAlisverisKayit.alisveris_id, TblMusteriler.isim, TblMusteriler.soyisim, TblUrunler.ad, TblAlisverisKayit.urun_fiyat, TblMusteriAlisverisTarihi.tarih
    from TblAlisverisKayit
    inner join TblMusteriler on TblAlisverisKayit.musteri_id = TblMusteriler.id
    inner join TblUrunler on TblAlisverisKayit.urun_id = TblUrunler.id
    inner join TblMusteriAlisverisTarihi on TblAlisverisKayit.alisveris_id = TblMusteriAlisverisTarihi.id
    where TblMusteriler.id = 1;
    ```
    

### **Fiyat Güncelleme**

1. Örneğin, "Çay" ürününün fiyatını güncelleme:
    
    ```sql
    update TblUrunler set fiyat = 17.25 where id = 1;
    ```
    

### **Özet**

Bu kodlar, ilişkisel bir veritabanı modeli oluşturarak müşteriler, ürünler ve alışveriş kayıtları arasında ilişkiler kurar. Bu sayede:

- Ürün ve kategori bilgileri yönetilebilir.
- Müşteri alışveriş geçmişi takip edilebilir.
- Ürün fiyatları güncellenebilir.

---