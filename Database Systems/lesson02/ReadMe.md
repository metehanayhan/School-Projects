# 2. Ders

### 1. Veritabanı Oluşturma ve Kullanma

- `create database VT_Sirket;` ile `VT_Sirket` adında bir veritabanı oluştururuz.
- `use VT_Sirket;` ile bu veritabanını kullanmaya başlarız.

### 2. Tablo Oluşturma (`tbl_Departman`)

- `create table tbl_Departman (...)` komutu ile `tbl_Departman` adlı bir tablo oluşturuyoruz:
    - `id int primary key` — `id` sütunu benzersiz (unique) ve boş bırakılamaz (not null) olarak tanımlanır.
    - `ad varchar(20) not null` — `ad` sütunu en fazla 20 karakter uzunluğunda bir metin alır ve boş bırakılamaz.
    - `tarih varchar(4)` — `tarih` sütunu yılı saklamak için 4 karakterlik bir `varchar` veri türündedir.

### 3. Veri Ekleme (`INSERT INTO`)

- `insert into tbl_Departman values (...)` ile tabloya veri ekliyoruz:
    - `(1,'satinalma','2020')` ile `id=1`, `ad='satinalma'`, `tarih='2020'` verileri eklenir.
    - `(ad,tarih,id) values ('bilgi-islem','2021',2)` ile sütun adlarını belirterek veri eklenir.
    - `(ad,id) values ('temizlik',3)` ile `tarih` bilgisi verilmeden veri eklenir; bu durumda `tarih` alanı `NULL` olur.

### 4. Tablo Yapısını Değiştirme (`ALTER TABLE`)

- `alter table` komutlarıyla tablo yapısında değişiklikler yapabiliriz:
    - `ALTER TABLE tbl_Departman add baskan varchar(30);` — `baskan` adlı bir sütun ekleriz.
    - `alter table tbl_Departman alter column baskan varchar(30) not null;` — `baskan` sütununun `not null` yapılması başarısız olur çünkü tablodaki mevcut kayıtların `baskan` alanı `NULL` değere sahiptir.
    - `ALTER TABLE tbl_Departman add baskan2 varchar(30) not null;` — Bu sütun `not null` olarak eklenmeye çalışılır, ancak mevcut satırlarda değer olmadığından bu işlem başarısız olur.
    - `alter table tbl_Departman alter column tarih int;` — `tarih` sütununun veri tipi `int` olarak değiştirilir.

### 5. Veri Güncelleme ve Silme

- `update tbl_Departman set baskan='mehmet' where id<3;` — `id` değeri `3`ten küçük olan kayıtların `baskan` alanını `mehmet` olarak günceller.
- `delete from tbl_Departman where baskan='ali';` — `baskan` değeri `ali` olan satırları siler.

### 6. Tablodaki Veriyi Sıfırlama (`TRUNCATE TABLE`)

- `truncate table tbl_Departman;` — Tablodaki tüm veriyi siler ve kimlik sayaçlarını sıfırlar.

### 7. Yeni Veriler Ekleme

- `insert into tbl_Departman values (...)` komutlarıyla yeni kayıtlar eklenir:
    - `(1, 'yunus', 2020, 'emre')` gibi değerler eklenir.

### 8. Tablo Yapısını Değiştirme (Primary Key ile)

- `create table tbl_Calisan (...)` ile `tbl_Calisan` tablosunu oluştururuz.
    - `sicil int primary key` sütunu ile `sicil` alanını benzersiz olarak belirleriz.
    - `alter table tbl_calisan drop constraint pk_Calisan;` ile `primary key` kısıtlamasını kaldırırız.

### 9. Veritabanını Silme

- `drop database VT_Sirket;` ile `VT_Sirket` veritabanını tamamen sileriz.

Bu komutlarla, SQL’de veritabanı ve tablo oluşturmayı, veri eklemeyi, tablo yapısını değiştirmeyi ve kayıtları güncellemeyi daha iyi anlamış olduk.