# 6. Ders

### YAZARLAR Tablosu ve PRIMARY KEY Oluşturma

```sql
select * from YAZARLAR;
alter table yazarlar alter column yazar_no int not null;
alter table yazarlar add constraint pk_yazar primary key (yazar_no);
```

1. **`select * from YAZARLAR;`** — `YAZARLAR` tablosundaki tüm verileri seçer.
2. **`alter table yazarlar alter column yazar_no int not null;`** — `yazar_no` sütununu `NOT NULL` yapar.
3. **`alter table yazarlar add constraint pk_yazar primary key (yazar_no);`** — `yazar_no` sütununa `PRIMARY KEY` kısıtı ekleyerek her yazarın tekil olmasını sağlar.

### Tbl_Kitap Tablosunun Oluşturulması

```sql
create table Tbl_Kitap(
    kitap_no int primary key,
    kitap_ad varchar(20),
    yayinevi varchar(20),
    yazar_id int foreign key references YAZARLAR (YAZAR_NO) DEFAULT 0
);
```

Bu kod, yeni bir tablo oluşturur:

- **`kitap_no`** — `PRIMARY KEY` olarak belirlenmiş, kitap numarası.
- **`kitap_ad`** — Kitabın adı.
- **`yayinevi`** — Kitabın yayınevi adı.
- **`yazar_id`** — `YAZARLAR` tablosundaki `YAZAR_NO` sütununa referans veren bir `FOREIGN KEY`.

### Sonradan `FOREIGN KEY` Ekleme

```sql
alter table TblğKitaplar add constraint fk_yazar_kitap (yazar_id) references Tbl_Yazar(yazar_no);
```

Bu sorgu, `TblğKitaplar` tablosundaki `yazar_id` sütununa sonradan bir `FOREIGN KEY` kısıtı ekler ve `Tbl_Yazar` tablosundaki `yazar_no` sütununu referans alır.

### `INSERT` İfadeleri ve `FOREIGN KEY` Kısıtı

```sql
insert into Tbl_Kitap values(1, 'Savas ve baris', 'Marti', 1);
insert into Tbl_Kitap values(2, 'Suc ve ceza', 'İşbankası', 2);
insert into Tbl_Kitap values(3, 'Hayır diy. Türkiye', 'Marti', 4);
```

Bu sorgular `Tbl_Kitap` tablosuna yeni kitap kayıtları ekler. `yazar_id` değerleri, `YAZARLAR` tablosundaki `YAZAR_NO` değerleri ile eşleşmelidir, aksi takdirde `FOREIGN KEY` kısıtı nedeniyle hata alırız. Örneğin:

```sql
insert into Tbl_Kitap values(4, 'Hayır diy. Türkiye', 'Marti', 5);
```

Bu ekleme işlemi, `yazar_no` değeri `5` olan bir yazar `YAZARLAR` tablosunda yoksa başarısız olur.

### Alt Sorgu ile Veri Seçme

```sql
select * from Tbl_Kitap where yazar_id = (select yazar_no from YAZARLAR where ISIM = 'Alev');
```

Bu sorgu:

- İç sorguda, `YAZARLAR` tablosunda adı `'Alev'` olan yazarın `yazar_no` değeri alınır.
- Dış sorgu, `Tbl_Kitap` tablosunda `yazar_id` bu değere eşit olan kitapları getirir.

### INNER JOIN ile Tablo Birleştirme

```sql
select * from YAZARLAR y inner join Tbl_Kitap k on y.YAZAR_NO = k.yazar_id;
```

Bu sorgu:

- `YAZARLAR` ve `Tbl_Kitap` tablolarını `yazar_no` ve `yazar_id` sütunlarına göre birleştirir.
- Sadece her iki tabloda eşleşen kayıtları getirir.

Alternatif olarak, belirli sütunları seçebiliriz:

```sql
select k.kitap_no, k.kitap_ad, y.ISIM, y.SOYISIM from YAZARLAR y inner join Tbl_Kitap k on y.YAZAR_NO = k.yazar_id;
```

Bu sorgu sadece kitap numarası, adı, yazarın adı ve soyadı sütunlarını seçer.

### RIGHT JOIN ile Eksik Verileri Görüntüleme

```sql
select k.kitap_no, k.kitap_ad, y.ISIM, y.SOYISIM from Tbl_Kitap k right outer join YAZARLAR y on y.YAZAR_NO = k.yazar_id;
```

Bu sorgu, sağdaki tüm `YAZARLAR` tablosundaki verileri getirir ve `Tbl_Kitap` tablosunda eşleşmeyen kitapları `NULL` olarak gösterir. Örneğin, yazarı olmayan kitapları veya kitabı olmayan yazarları görmek istediğimizde **LEFT/RIGHT JOIN** kullanabiliriz.

### Silme İşlemi ve Bağlı Kısıt

```sql
delete from YAZARLAR where isim = 'lev';
```

Bu sorgu, `YAZARLAR` tablosundan ismi `'lev'` olan yazarı silmeye çalışır. Ancak, `Tbl_Kitap` tablosunda bu yazara ait kitaplar varsa, `FOREIGN KEY` kısıtı nedeniyle silme işlemi başarısız olur. Kitap kaydı olmayan yazarları silebiliriz.