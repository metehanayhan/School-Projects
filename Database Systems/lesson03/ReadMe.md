# 3. Ders

Bu SQL sorgularıyla veritabanı üzerinde veri seçme, filtreleme, sıralama, kümeleme ve veri işlemleri gibi çeşitli işlemleri nasıl yapabileceğinizi öğrenebilirsiniz. Şimdi her bir SQL komut grubunu açıklayalım:

### 1. Veri Seçme ve Filtreleme

- `select * from KISILER;` ile `KISILER` tablosundaki tüm verileri seçersiniz.
- `select ad,soyad,sehir, id, adres from KISILER;` ile belirli sütunları seçebilirsiniz.
- `select distinct sehir from KISILER;` — `sehir` alanında tekrar edenleri kaldırarak benzersiz değerleri getirir.
- `select * from KISILER where sehir = 'Istanbul';` — `sehir` değeri "Istanbul" olan kayıtları filtreler.

### 2. `WHERE` Şart İfadesi ile Filtreleme

- `select * from kisiler where sehir='Ankara'` — `sehir` değeri "Ankara" olan kayıtları getirir.
- `select * from yazarlar where DOGUM_YILI > 1821` — 1821 yılından sonra doğan yazarları seçer.
- `select * from UYELER where ISIM = 'Deniz' and CINSIYET = 'K'` — İsmi "Deniz" ve cinsiyeti "K" olan kayıtları getirir.
- `select * from PERSONEL where (YAS > 30 and CINSIYET = 'E') or (YAS < 25 and CINSIYET = 'K')` — Yaşı 30’dan büyük erkekler veya yaşı 25’ten küçük kadınlar.

### 3. Sıralama (`ORDER BY`)

- `select * from UYELER order by isim asc;` — `isim` sütununa göre alfabetik sıralama yapar (varsayılan `asc`).
- `select * from PERSONEL order by maas desc;` — `maas` sütununa göre maaşı yüksekten düşüğe sıralar.

### 4. `TOP` İşlevi

- `select top 5 per_no, isim from PERSONEL;` — `PERSONEL` tablosunda ilk 5 kaydın `per_no` ve `isim` sütunlarını getirir.

### 5. `LIKE` İşleci ile Metin Arama

- `select * from PERSONEL where isim like 'A%'` — İsmi "A" harfiyle başlayanları getirir.
- `select * from UYELER where isim like '_e%'` — 2. harfi "e" olan kayıtları getirir.
- `select * from UYELER where isim like '__r%'` — 3. harfi "r" olanları getirir.

### 6. `IN` ve `BETWEEN` İşleçleri

- `select * from PERSONEL where yas IN (22,23,25,26);` — `yas` değeri belirtilen değerlerden biri olan kayıtları getirir.
- `select * from PERSONEL where yas between 20 and 26;` — `yas` değeri 20 ile 26 arasında olan kayıtları getirir.

### 7. `AS` Sözcüğü Kullanımı

- `select isim as PERSONEL_ADI from PERSONEL;` — `isim` sütununa `PERSONEL_ADI` adı vererek getirir.

### 8. Kümeleme Fonksiyonları

- `select avg(maas) as maas_ort from PERSONEL;` — `PERSONEL` tablosundaki maaşların ortalamasını alır.
- `select sum(maas) as maas_toplam from PERSONEL where ulke='Türkiye';` — Türkiye’deki çalışanların toplam maaşını hesaplar.

### 9. Yuvarlama İşleçleri (`ROUND`, `CEILING`, `FLOOR`)

- `ROUND(5.576, 1)` — Virgülden sonra bir basamak ile 5.6 olarak yuvarlar.
- `CEILING(5.376)` — Her zaman yukarıya (6'ya) yuvarlar.
- `FLOOR(5.576)` — Her zaman aşağıya (5'e) yuvarlar.

### 10. `COUNT` İşlevi

- `select count(*) from YAZARLAR;` — `YAZARLAR` tablosundaki toplam kayıt sayısını verir.
- `select count(distinct sehir) from KISILER;` — `KISILER` tablosunda benzersiz `sehir` sayısını getirir.

### 11. `MAX` ve `MIN` İşlevleri

- `select max(yas) ENYASLI, min(yas) ENGENC from PERSONEL;` — `PERSONEL` tablosundaki en yüksek ve en düşük yaşları getirir.
- `select yas,isim from PERSONEL where yas = (select max(yas) from PERSONEL);` — `PERSONEL` tablosunda yaşı en büyük olan kişinin yaşını ve ismini getirir.

Bu temel sorgularla SQL'de veri seçme, filtreleme, sıralama, grup işlemleri, veri sayma ve çeşitli fonksiyonlar kullanarak daha etkili veri analizi yapabilirsiniz.