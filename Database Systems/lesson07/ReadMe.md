# 7. Ders

### 1. Veritabanı ve Tabloların Oluşturulması

```sql
create database vt_alisveris;
use vt_alisveris;
```

- Yeni bir veritabanı (`vt_alisveris`) oluşturur ve bu veritabanını kullanıma alır.

### TblMusteriler Tablosu

```sql
create table TblMusteriler(
    id int primary key identity (1,1),
    isim varchar(30) not null,
    soyisim varchar(30) not null,
    tckn char(11) not null,
    ceptel char(11) not null,
    mail varchar(30) not null
);
```

- `TblMusteriler` tablosu müşteri bilgilerini tutar.
- `id` sütunu, otomatik artan (`identity`) ve `primary key` olarak ayarlanmıştır.
- `isim`, `soyisim`, `tckn`, `ceptel`, ve `mail` gibi bilgileri içerir.

### TblUrunKategori Tablosu

```sql
create table TblUrunKategori(
    id int primary key identity(1,1),
    kategori varchar(30) not null
);
```

- `TblUrunKategori` tablosu ürün kategorilerini içerir.
- `id` sütunu otomatik artan (`identity`) ve `primary key` olarak tanımlanmıştır.

### TblUrunler Tablosu

```sql
create table TblUrunler(
    id int primary key identity(1,1),
    ad varchar(50) not null,
    fiyat float not null,
    barkod char(15) not null,
    urun_kategori_id int foreign key references TblUrunKategori(id)
);
```

- `TblUrunler` tablosu ürün bilgilerini içerir.
- `urun_kategori_id`, `TblUrunKategori` tablosundaki `id` sütununa `foreign key` olarak bağlıdır.

### TblAlisverisKayit Tablosu

```sql
create table TblAlisverisKayit(
    alisveris_id int primary key identity(1,1),
    musteri_id int foreign key references TblMusteriler(id),
    urun_id int foreign key references TblUrunler(id),
    adet int not null,
    tarih datetime default current_timestamp
);
```

- `TblAlisverisKayit`, alışveriş işlemlerini kaydetmek için kullanılır.
- `musteri_id` ve `urun_id`, sırasıyla `TblMusteriler` ve `TblUrunler` tablolarındaki `id` sütunlarına `foreign key` olarak bağlıdır.

---

### 2. Veri Ekleme

### TblMusteriler Tablosuna Veri Ekleme

```sql
insert into TblMusteriler values ('Ecem', 'Ayhan', '1111', '9344512552', 'ecmayhn@gmail.com'),
                                 ('Metehan', 'Ayhan', '2222', '9574567552', 'metehanayhan1213@gmail.com'),
                                 ('Ali', 'Kaya', '3333', '9371212552', 'alikaya@gmail.com'),
                                 ('Veli', 'Nur', '1245', '9854875142', 'velinur@gmail.com');
```

- `TblMusteriler` tablosuna dört müşteri ekler.

### TblUrunKategori Tablosuna Veri Ekleme

```sql
insert into TblUrunKategori values ('GIDA'), ('ŞARKÜTERİ'), ('ÇİKOLATA'), ('UNLU MAMÜLLER'), ('TEMİZLİK ÜRÜNLERİ');
```

- `TblUrunKategori` tablosuna beş kategori ekler.

### TblUrunler Tablosuna Veri Ekleme

```sql
insert into TblUrunler values ('Çay', 29.75, '100', 1),
                              ('Makarna', 5.75, '101', 1),
                              ('Tereyağı', 49.75, '102', 2),
                              ('Tadelle', 49.75, '103', 3),
                              ('Halley', 24.50, '104', 4),
                              ('Nero', 2.5, '105', 4),
                              ('Ekmek', 1.4, '106', 5),
                              ('Deterjan', 35.55, '107', 5);
```

- `TblUrunler` tablosuna ürünler ekler.

### TblAlisverisKayit Tablosuna Veri Ekleme

```sql
insert into TblAlisverisKayit (musteri_id, urun_id, adet) values (1, 2, 5),
                                                                  (2, 5, 3),
                                                                  (3, 7, 2),
                                                                  (1, 6, 4);

insert into TblAlisverisKayit (musteri_id, urun_id, adet) values (2, 4, 5);
```

- `TblAlisverisKayit` tablosuna alışveriş kayıtları ekler.

---

### 3. Veritabanı Sorguları

### `INNER JOIN` İle Müşteri ve Ürün Bilgilerini Getirme

```sql
select TblMusteriler.isim, TblMusteriler.soyisim, TblUrunler.ad, TblUrunler.fiyat, TblAlisverisKayit.tarih
from TblAlisverisKayit
inner join TblMusteriler on TblAlisverisKayit.musteri_id = TblMusteriler.id
inner join TblUrunler on TblAlisverisKayit.urun_id = TblUrunler.id;
```

- Bu sorgu, `TblAlisverisKayit`, `TblMusteriler` ve `TblUrunler` tablolarını `INNER JOIN` ile birleştirir ve alışveriş tarihi, müşteri adı-soyadı, ürün adı ve fiyatını getirir.

### `WHERE` Kullanarak Kartezyen Çarpımı Filtreleme

```sql
select TblMusteriler.isim, TblMusteriler.soyisim, TblUrunler.ad, TblUrunler.fiyat, TblAlisverisKayit.tarih
from TblAlisverisKayit, TblUrunler, TblMusteriler
where (TblAlisverisKayit.urun_id = TblUrunler.id) and TblAlisverisKayit.musteri_id = TblMusteriler.id;
```

- Bu sorgu, kartezyen çarpım kullanır ve `WHERE` koşulu ile `musteri_id` ve `urun_id` eşleştirmeleri yapılır. Bu yöntem, büyük tablolar üzerinde performans sorunlarına yol açabilir.

### `INNER JOIN` İle Ürün ve Kategorileri Getirme

```sql
SELECT TblUrunler.ad, TblUrunler.barkod, TblUrunler.fiyat, TblUrunKategori.kategori
FROM TblUrunler INNER JOIN TblUrunKategori ON TblUrunler.urun_kategori_id = TblUrunKategori.id;
```

- Bu sorgu, `TblUrunler` ve `TblUrunKategori` tablolarını `INNER JOIN` ile birleştirir ve ürün adı, barkod, fiyat ve kategori bilgilerini getirir.

### 4’lü `INNER JOIN` İle Detaylı Alışveriş Kaydı

```sql
select TblMusteriler.isim, TblMusteriler.soyisim, TblUrunler.ad, TblUrunler.fiyat, TblAlisverisKayit.tarih, TblUrunKategori.kategori
from TblAlisverisKayit
inner join TblMusteriler on TblAlisverisKayit.musteri_id = TblMusteriler.id
inner join TblUrunler on TblAlisverisKayit.urun_id = TblUrunler.id
inner join TblUrunKategori on TblUrunler.urun_kategori_id = TblUrunKategori.id;
```

- `TblAlisverisKayit`, `TblMusteriler`, `TblUrunler` ve `TblUrunKategori` tablolarını birleştirir. Bu sorgu her bir alışveriş kaydına dair müşteri adı, soyadı, ürün adı, fiyatı, alışveriş tarihi ve kategori bilgilerini gösterir.

### 4’lü `WHERE` İle Detaylı Alışveriş Kaydı (Kartezyen Çarpım)

```sql
select TblMusteriler.isim, TblMusteriler.soyisim, TblUrunler.ad, TblUrunler.fiyat, TblAlisverisKayit.tarih, TblUrunKategori.kategori
from TblMusteriler, TblUrunler, TblAlisverisKayit, TblUrunKategori
where (TblAlisverisKayit.musteri_id = TblMusteriler.id)
      and (TblAlisverisKayit.urun_id = TblUrunler.id)
      and (TblUrunler.urun_kategori_id = TblUrunKategori.id);
```

- Bu sorgu da dört tabloyu birleştirir, ancak `WHERE` koşulları ile yapılır. Sonuç yine aynı olur, ancak `INNER JOIN` kullanımı daha performanslıdır.