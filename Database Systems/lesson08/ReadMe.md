# 8. Ders

### 1. Veritabanı ve Tabloların Oluşturulması

```sql
create database lab;
use lab;
```

- Yeni bir `lab` adlı veritabanı oluşturur ve onu kullanıma alır.

### `musteri` Tablosu

```sql
CREATE table musteri(
    musteri_id int primary key,
    ad varchar(20),
    soyad varchar(20),
    adres varchar(20),
    borc int check(borc > 0)
);
```

- `musteri` tablosu müşterilerin bilgilerini tutar.
- `borc` sütununda, yalnızca pozitif borç değerlerine izin veren bir `CHECK` kısıtlaması vardır.

### `urun` Tablosu

```sql
create table urun(
    urun_id int primary key,
    urun_ad varchar(20),
    stok int default 1
);
```

- `urun` tablosu ürün bilgilerini içerir.
- `stok` sütununun varsayılan değeri `1` olarak ayarlanmıştır.

### `siparis` Tablosu

```sql
create table siparis(
    tablo_id int primary key,
    siparis_id int,
    mus_id int,
    u_id int,
    tarih varchar(20)
);
```

- `siparis` tablosu, sipariş bilgilerini tutar. Bu tabloda, her sipariş için `mus_id` müşteri kimliğini, `u_id` ise ürün kimliğini ifade eder.

### 2. Yabancı Anahtar Kısıtlamalarının Eklenmesi

```sql
alter table siparis add constraint fk_siparis_musteri foreign key (mus_id) references musteri(musteri_id);
alter table siparis add constraint fk_siparis_urun foreign key (u_id) references urun(urun_id);
```

- `mus_id` ve `u_id` sütunlarına `foreign key` kısıtlamaları eklenmiştir. `mus_id`, `musteri` tablosundaki `musteri_id` sütununa; `u_id`, `urun` tablosundaki `urun_id` sütununa bağlıdır.

---

### 3. Veri Ekleme

### `musteri` Tablosuna Veri Ekleme

```sql
insert into musteri(musteri_id, ad, soyad, adres, borc) values
(1, 'Ecem', 'Ayhan', 'Niğde', 1),
(2, 'Metehan', 'Ayhan', 'Niğde', 10),
(3, 'Veli', 'Ajram', 'Konya', 3),
(4, 'Ayşe', 'Ozturk', 'Konya', 1000),
(5, 'Ahmet', 'Yılmaz', 'Konya', 500),
(6, 'Nancy', 'Kaya', 'Konya', 1);
```

- `musteri` tablosuna altı müşteri ekler.

### `urun` Tablosuna Veri Ekleme

```sql
insert into urun (urun_id, urun_ad, stok) values
(1, 'Bilgisayar', 10),
(2, 'Televizyon', 1),
(3, 'Ütü', 7),
(4, 'PS', 10),
(5, 'Çamaşır Makinesi', 1);
```

- `urun` tablosuna beş ürün ekler.

### `siparis` Tablosuna Veri Ekleme

```sql
insert into siparis(tablo_id, siparis_id, mus_id, u_id, tarih) values
(1, 1, 1, 1, '10.10.2024'),
(2, 1, 1, 2, '10.10.2024'),
(3, 1, 1, 4, '10.10.2024'),
(4, 2, 2, 1, '15.10.2024'),
(5, 3, 4, 3, '20.10.2024'),
(6, 4, 4, 5, '10.12.2024'),
(7, 5, 5, 2, '21.10.2021'),
(8, 5, 5, 4, '10.10.2003'),
(9, 6, 2, 2, '01.01.2023');
```

- `siparis` tablosuna dokuz sipariş kaydı ekler.

---

### 4. Sorgular

### `INNER JOIN` ile Müşteri ve Ürün Bilgilerini Getirme

```sql
select s.siparis_id, m.ad, m.soyad, u.urun_ad, s.tarih
from siparis s, musteri m, urun u
where m.musteri_id = s.mus_id and u.urun_id = s.u_id;
```

- Bu sorgu, `siparis`, `musteri`, ve `urun` tablolarını birleştirerek sipariş bilgilerini müşteri adı-soyadı ve ürün adı ile birlikte getirir.

```sql
select s.siparis_id, m.ad, m.soyad, u.urun_ad, s.tarih
from (siparis s inner join musteri m on s.mus_id = m.musteri_id)
inner join urun u on u.urun_id = s.u_id;
```

- Bu sorgu, `INNER JOIN` kullanarak aynı bilgileri getirir. `INNER JOIN` daha verimli bir birleştirme yöntemidir.

### Müşteri Adına Göre Stok Güncelleme

```sql
update urun set stok = stok - 1 where urun_id in
(select u_id from siparis where mus_id in
(select mus_id from musteri where ad = 'Ali'));
```

- `Ali` adlı müşterinin sipariş ettiği ürünlerin stoklarını bir azaltır.

### Müşteri Adı ve Soyadına Göre Stok Güncelleme

```sql
update urun set stok = stok + 1 where urun_id in
(select u_id from siparis where mus_id =
(select musteri_id from musteri where ad = 'Ahmet' and soyad = 'Yılmaz'));
```

- `Ahmet Yılmaz` adlı müşterinin sipariş ettiği ürünlerin stoklarını bir artırır.

### Borç Güncelleme

```sql
update musteri set borc = 0 where ad = 'Veli';
```

- `Veli` adlı müşterinin borcunu `0` yapar.

```sql
update musteri set borc = m.borc + u.urun_id
from musteri m, siparis s, urun u
where m.musteri_id = s.mus_id and s.u_id = u.urun_id;
```

- `siparis` tablosundaki her sipariş için, müşterinin borcunu sipariş ettiği ürünün `urun_id` değeri kadar artırır.

### 3 Tablodan Bilgi Getirme

```sql
select * from musteri m, siparis s, urun u
where m.musteri_id = s.mus_id and s.u_id = u.urun_id;
```

- `musteri`, `siparis`, ve `urun` tablolarını birleştirerek tüm müşteri, sipariş ve ürün bilgilerini getirir.