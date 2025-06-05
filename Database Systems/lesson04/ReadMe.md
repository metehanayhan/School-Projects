# 4. Ders

### Veritabanı ve Tablolarla İlgili Temel İşlemler

```sql
use VTDERS21EKIM;
Alter database [VTDERS21EKIM] modify name = [VTKITAPYAYIN];
use VTKITAPYAYIN;
```

Bu sorgular, veritabanının kullanımını ve adını değiştirmeyi sağlar:

1. `use VTDERS21EKIM;` — `VTDERS21EKIM` adlı veritabanını aktif hale getirir, yani bu veritabanı üzerinde işlem yapılmasını sağlar.
2. `Alter database [VTDERS21EKIM] modify name = [VTKITAPYAYIN];` — `VTDERS21EKIM` veritabanının adını `VTKITAPYAYIN` olarak değiştirir.
3. `use VTKITAPYAYIN;` — Artık yeni adı `VTKITAPYAYIN` olan veritabanı üzerinde işlem yapılacaktır.

### Ortalama Maaş Hesaplama

```sql
select avg(maas) as ortalama_maas from PERSONEL where ULKE='Türkiye' and CINSIYET = 'E';
```

Bu sorgu, `PERSONEL` tablosundaki Türkiye’deki erkek çalışanların maaşlarının ortalamasını hesaplar:

- `avg(maas)` — Maaşların ortalamasını alır.
- `where ULKE='Türkiye' and CINSIYET = 'E'` — Ülke "Türkiye" ve cinsiyet "E" olan kayıtları filtreler.
- `as ortalama_maas` — Ortalama maaşı `ortalama_maas` olarak adlandırır.

### Gruplama ve Sıralama ile İlgili İşlemler

```sql
select ulke from PERSONEL group by ulke;
```

Bu sorgu, `PERSONEL` tablosundaki `ulke` sütunundaki benzersiz ülkeleri gruplar. `group by` ifadesi, tabloyu belirtilen sütuna göre gruplar.

```sql
select ulke, avg(yas) from PERSONEL group by ulke;
```

Bu sorgu, `ulke` sütununa göre gruplar ve her ülkenin yaş ortalamasını hesaplar.

```sql
select ulke, avg(maas) as ort_maas from PERSONEL group by ulke order by ort_maas asc;
```

Bu sorgu, ülkeleri `ulke` sütununa göre gruplar ve her grubun maaş ortalamasını hesaplar. `order by ort_maas asc` kısmı, sonuçları maaş ortalamasına göre artan sırada sıralar.

### Gruplandırılmış Veriler Üzerinde Filtreleme (`having`)

```sql
select ulke,avg(yas) as ort_yas from personel group by ulke having avg(yas)>25;
```

Bu sorgu, ülkeleri `ulke` sütununa göre gruplar, yaş ortalaması 25’ten büyük olan grupları listeler. `having` ifadesi, gruplandırılmış sonuçlarda filtreleme yapar.

### Şartlı Filtreleme (`where` ile `having` Farkı)

- **`where` ifadesi** — Tablodaki ham veriler üzerinde filtreleme yapar.
- **`having` ifadesi** — `group by` işlemi sonrası ortaya çıkan gruplar üzerinde filtreleme yapar.

Örnek:

```sql
select kent, count(*) as calisan_sayisi from PERSONEL group by kent having count(*) > 1;
```

Bu sorgu, her kenti gruplandırır ve çalışan sayısı 1'den fazla olan kentleri listeler.

### Birden Fazla Şarta Göre Filtreleme

```sql
SELECT ulke, AVG(maas) as ort_maas
FROM PERSONEL
WHERE CINSIYET = 'E'
AND ulke IN (
    SELECT ulke
    FROM PERSONEL
    GROUP BY ulke
    HAVING AVG(maas) > 3000
)
GROUP BY ulke;
```

Bu sorguda:

- `WHERE CINSIYET = 'E'` — Erkek çalışanları filtreler.
- `AND ulke IN (...)` — Ortalama maaşı 3000’den yüksek olan ülkeleri filtreler.
- `GROUP BY ulke` — Ülkeye göre gruplandırır.

Burada alt sorgu `(SELECT ulke FROM PERSONEL GROUP BY ulke HAVING AVG(maas) > 3000)`, her ülke için maaş ortalaması 3000’den fazla olanları getirir.

Bu yapıyı adım adım inceleyerek daha da detaylandırabiliriz. Hangi konuları daha ayrıntılı ele almak istersiniz?