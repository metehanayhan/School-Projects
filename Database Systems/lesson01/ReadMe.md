# 1. Ders

### 1. Veritabanı Oluşturma ve Kullanma

- `create database VT_OKUL;` komutuyla `VT_OKUL` adlı bir veritabanı oluştururuz.
- `use VT_OKUL;` komutuyla oluşturduğumuz veritabanını kullanmaya başlarız. Yani, bu veritabanında işlemler yapabiliriz.

### 2. Tablo Oluşturma

- `create table tbl_Ogrenci (...)` komutuyla `tbl_Ogrenci` adlı bir tablo oluştururuz. Bu tablo öğrencilerle ilgili bilgileri saklayacak:
    - `id int not null primary key` — Bu alanın türü `int` (tam sayı) ve `null` değer alması yasak. Ayrıca bu alan `primary key` yani benzersiz bir değer olacak.
    - `isim varchar(30) not null` — `isim` alanı 30 karakter uzunluğunda bir `varchar` (değişken karakter dizisi) ve `null` değer alması yasak.
    - `soyisim varchar(30)` — `soyisim` alanı ise 30 karakterlik bir `varchar`.

### 3. Sütun Ekleme ve Güncelleme

- `alter table tbl_Ogrenci add dogumtarihi varchar(30);` komutuyla `dogumtarihi` adlı yeni bir sütun ekleriz.
- `alter table tbl_Ogrenci alter column dogumtarihi date;` komutuyla `dogumtarihi` sütununun veri tipini `date` olarak değiştiririz.
- `alter table tbl_Ogrenci alter column isim nvarchar(20);` komutuyla `isim` sütununun veri tipini `nvarchar(20)` olarak değiştiririz.

### 4. Veri Ekleme

- `insert into tbl_Ogrenci values (...)` komutlarıyla tabloya veri ekleriz.
- Birinci kayıt: `(1, 'Ali', 'Kaya', '1986')`
- İkinci kayıt: `(2, 'Ayşe', 'Dağ', '')`
- Üçüncü kayıt: `(3, 'ozgur', 'kara')` — `dogumtarihi` belirtilmediği için `NULL` olarak kaydedilecek.
- Çoklu ekleme: `(4, 'Veli', 'Alan', '1995'), (5, 'Fatma', 'Yılmaz', '2003')`

### 5. Yeni Tablo Oluşturma

- `create table tbl_Ogretmen (id int not null);` komutuyla `tbl_Ogretmen` adında yeni bir tablo oluştururuz.

### 6. Sütun Veri Tipini Değiştirme

- `alter table tbl_Ogretmen alter column id varchar(2);` komutuyla `id` sütununun veri tipini `varchar(2)` olarak değiştiririz.
- `insert into tbl_Ogretmen values ('4');` komutuyla karakter içeren bir veri eklenebilir.
- `alter table tbl_Ogretmen alter column id int;` komutuyla tekrar `int` veri tipine döndürürüz.

### 7. Kimlik Sütunu ile Tablo Oluşturma

- `create table tbl_Dersler (id int identity(1,1) primary key, ders_adi varchar(20));` komutuyla `tbl_Dersler` adında kimlik sütunu olan bir tablo oluştururuz. `identity(1,1)` — `id` alanı 1’den başlayarak 1’er artar.

### 8. Güncelleme

- `update tbl_Dersler set ders_adi = 'Türkce';` — Tüm satırlardaki `ders_adi` değerini `Türkce` olarak günceller.
- `update tbl_Dersler set ders_adi = 'Beden' where id = 3;` — `id` değeri `3` olan satırda `ders_adi` `Beden` olarak değiştirilir.

### 9. Kayıt Silme

- `delete top(2) from tbl_Dersler;` — İlk iki satırı siler.
- `delete from tbl_Dersler where id = 4;` — `id` değeri `4` olan kaydı siler.
- `truncate table tbl_Dersler;` — Tablodaki tüm veriyi ve kimlik sayacını sıfırlar.

### 10. Tabloları ve Veritabanını Silme

- `drop table tbl_Dersler;` komutuyla `tbl_Dersler` tablosunu tamamen sileriz.
- `drop database VT_OKUL;` komutuyla `VT_OKUL` veritabanını tamamen sileriz.

Bu adımlarla SQL'in temel komutları olan veritabanı ve tablo oluşturma, veri ekleme, güncelleme, silme ve veri tiplerini değiştirme işlemlerini öğrendik.

---