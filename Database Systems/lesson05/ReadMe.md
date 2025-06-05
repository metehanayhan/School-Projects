# 5. Ders

### Temel Veritabanı Kullanımı ve Sorgular

```sql
use VTKITAPYAYIN;
select * from PERSONEL;
```

1. **`use VTKITAPYAYIN;`** — Bu komut, `VTKITAPYAYIN` adlı veritabanını aktif hale getirir.
2. **`select * from PERSONEL;`** — `PERSONEL` tablosundaki tüm sütun ve satırları seçer.

### Genel Fonksiyonlar ve İstatistiksel Hesaplamalar

```sql
select min(maas) minmaas, max(maas) maxmaas, avg(maas) ortmaas, sum(maas) toplammaas from PERSONEL;
```

- **`min(maas)`** — `maas` sütunundaki en küçük maaşı bulur.
- **`max(maas)`** — `maas` sütunundaki en büyük maaşı bulur.
- **`avg(maas)`** — `maas` sütununun ortalamasını alır.
- **`sum(maas)`** — `maas` sütunundaki tüm maaşların toplamını verir.

### Şarta Bağlı Sayma İşlemi

```sql
select count(*) from PERSONEL where ulke = 'Türkiye';
```

Bu sorgu, `ulke` değeri "Türkiye" olan personel sayısını bulur.

### Ülkeye Göre Gruplama ve Sıralama

```sql
select ulke, count(*) as kisisayisi, avg(maas) as ortmaas from PERSONEL group by ULKE order by kisisayisi desc;
```

- **`group by ULKE`** — `ULKE` sütununa göre personelleri gruplar.
- **`count(*) as kisisayisi`** — Her bir ülke için toplam kişi sayısını hesaplar.
- **`avg(maas) as ortmaas`** — Her bir ülke için maaşların ortalamasını hesaplar.
- **`order by kisisayisi desc`** — Sonuçları kişi sayısına göre azalan sırada sıralar.

### Çoklu Gruplama ve Sıralama

```sql
select count(*) kisisayisi, ulke, kent from PERSONEL group by ulke, kent order by ulke asc, kent desc;
```

Bu sorgu:

- **`group by ulke, kent`** — `ulke` ve `kent` sütunlarına göre gruplar.
- **`count(*) kisisayisi`** — Her ülke ve kent için toplam kişi sayısını verir.
- **`order by ulke asc, kent desc`** — Ülke ismine göre artan, kent adına göre azalan sırada sıralar.

### `HAVING` İfadesi ile Filtreleme

```sql
select kent from PERSONEL where ulke = 'Türkiye' group by kent having count(*) = 1;
```

Bu sorgu:

- **`group by kent`** — `kent` sütununa göre gruplar.
- **`having count(*) = 1`** — Sadece Türkiye’deki ve kişi sayısı 1 olan kentleri seçer. `HAVING`, gruplandırılmış sonuçlarda filtreleme yapar.

### İç İçe Sorgular ile Filtreleme

```sql
select * from PERSONEL where CINSIYET = 'E' and yas > (select avg(yas) from PERSONEL where ULKE = 'Türkiye');
```

Bu sorgu:

- **`where CINSIYET = 'E'`** — Erkek (`E`) cinsiyetine sahip personeli seçer.
- **`yas > (select avg(yas) from PERSONEL where ULKE = 'Türkiye')`** — Türkiye’deki yaş ortalamasından büyük yaşa sahip olanları filtreler.

### ASCII ve Karakter Fonksiyonları

```sql
select ascii('a');
select char(65);
```

- **`ascii('a')`** — `'a'` karakterinin ASCII kodunu verir (örneğin, 97).
- **`char(65)`** — ASCII kodu 65 olan karakteri verir (örneğin, `'A'`).

### `CHARINDEX` ve `SUBSTRING` Fonksiyonları

```sql
select CHARINDEX('a', 'Anadana');
select SUBSTRING('Badanada', 1, 4);
```

- **`CHARINDEX('a', 'Anadana')`** — İlk `'a'` karakterinin indeksini bulur. Burada sonuç 2 olacaktır.
- **`SUBSTRING('Badanada', 1, 4)`** — `'Badanada'` metninin 1. karakterinden başlayarak 4 karakter getirir. Sonuç: `'Bada'`.

### `UPPER`, `LOWER`, `LEFT`, ve `RIGHT` Fonksiyonları

```sql
select upper('AhmetHasimGülpiNARda');
select right(isim,1) from PERSONEL;
```

- **`upper('AhmetHasimGülpiNARda')`** — Tüm karakterleri büyük harfe çevirir.
- **`right(isim,1)`** — `isim` sütunundaki her kaydın son karakterini alır.

### `TRIM`, `LTRIM`, `RTRIM` ile Boşlukları Kaldırma

```sql
select trim('     asdfasdfasdfads          ');
```

- **`trim(...)`** — Baş ve sondaki boşlukları kaldırır.

### `REPLACE`, `STUFF`, `CONCAT` Fonksiyonları

```sql
select replace('AhmetAa', 'A', '@');
```

- **`replace('AhmetAa', 'A', '@')`** — `'A'` karakterini `'@'` ile değiştirir. Sonuç: `'@hmet@a'`.

### Palindromik Kontrol ve Belirli Harfleri İçeren İsimler

```sql
select * from PERSONEL where lower(isim) = lower(reverse(isim));
select isim from PERSONEL where CHARINDEX('a', isim) > 0 and CHARINDEX('m', isim) > 0;
```

- **`lower(isim) = lower(reverse(isim))`** — İsim palindromsa (tersi de aynıysa) bu kayıtları getirir.
- **`CHARINDEX('a', isim) > 0 and CHARINDEX('m', isim) > 0`** — İsminde hem `'a'` hem de `'m'` karakterlerini içeren kayıtları seçer.