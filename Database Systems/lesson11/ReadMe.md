# 11

## 1) Yeni Bir Veritabanı Oluşturma

```sql
CREATE DATABASE KisitOrnekVeritabani;
```

- **Amaç**: `KisitOrnekVeritabani` adında yeni bir veritabanı oluşturuyoruz.
- **Mantık**: SQL Server’da (veya kullandığınız diğer bir veritabanı yönetim sistemi) yeni bir veritabanı yaratmak için `CREATE DATABASE` komutu kullanılır.
- **Önemli Nokta**: Bir veritabanı oluşturduktan sonra, bu veritabanının içindeki tablolar ve diğer nesnelerle çalışabilmek için öncelikle o veritabanına geçmemiz gerekiyor.

---

## 2) Veritabanını Kullan

```sql
USE KisitOrnekVeritabani;
```

- **Amaç**: Biraz önce oluşturduğumuz veritabanına geçiş yapıyoruz.
- **Mantık**: `USE` komutu, hangi veritabanı üzerinde işlem yapacağınızı seçmenizi sağlar. Bu komutun ardından yazacağınız tüm sorgular, seçtiğiniz veritabanı üzerinde çalışır.

---

## 3) Tabloları Oluşturma

### 3.1) Cinsiyet Tablosu

```sql
CREATE TABLE Cinsiyet (
    id INT PRIMARY KEY,  -- Birincil Anahtar (Primary Key)
    cinsiyet VARCHAR(50) NOT NULL -- Boş değer kabul edilmez (NOT NULL)
);
```

- **Amaç**: `Cinsiyet` isminde bir tablo oluşturduk.
- **Alanlar (Kolonlar)**:
    - `id INT PRIMARY KEY`:
        - Bu kolon, tablo için birincil anahtar (Primary Key) oluyor.
        - Primary Key bir tablo içinde tekil (benzersiz) olmasını ve boş geçilemez olmasını sağlar.
    - `cinsiyet VARCHAR(50) NOT NULL`:
        - Cinsiyet bilgisini tutuyor.
        - `NOT NULL` olduğu için bu alan boş bırakılamaz.

### 3.2) Müşteri Tablosu

```sql
CREATE TABLE Musteri (
    id INT PRIMARY KEY,              -- Birincil Anahtar (Primary Key)
    isim VARCHAR(50) NOT NULL,       -- İsim boş bırakılamaz (NOT NULL)
    email VARCHAR(100) UNIQUE,       -- E-posta adresi benzersiz olmalı (UNIQUE)
    cinsiyet_id INT DEFAULT 1,       -- Varsayılan değer 1 (Default)
    FOREIGN KEY (cinsiyet_id) REFERENCES Cinsiyet(id), -- Yabancı anahtar (Foreign Key)
    CHECK (id > 0)                   -- id sıfırdan büyük olmalı (CHECK Kısıtı)
);
```

- **Amaç**: `Musteri` isminde bir tablo oluşturduk ve bu tabloya çeşitli kısıtlar (constraints) ekledik.
- **Alanlar (Kolonlar)**:
    1. `id INT PRIMARY KEY`:
        - Her müşteri için benzersiz bir numara. Sıfırdan ve tekrardan korunmalı.
    2. `isim VARCHAR(50) NOT NULL`:
        - İsim alanı boş bırakılamaz (`NOT NULL`).
    3. `email VARCHAR(100) UNIQUE`:
        - Her müşteri için benzersiz bir e-posta adresi olmasını istiyoruz (`UNIQUE`).
    4. `cinsiyet_id INT DEFAULT 1`:
        - Eğer cinsiyet_id belirtilmezse otomatik olarak 1 değeri atanacak (`DEFAULT 1`).
    5. `FOREIGN KEY (cinsiyet_id) REFERENCES Cinsiyet(id)`:
        - `Musteri` tablosundaki `cinsiyet_id`, `Cinsiyet` tablosunun `id` kolonu ile ilişkili. Bu bir **yabancı anahtar** (Foreign Key).
        - Bu sayede `cinsiyet_id` alanına sadece `Cinsiyet` tablosunda var olan id değerleri girilebilir.
    6. `CHECK (id > 0)`:
        - `id` alanı 0’dan büyük olacak şekilde kontrol ediliyor. 0 veya negatif bir değer girdiğinizde hata alırsınız.

---

## 4) Örnek Veriler Ekleme

### 4.1) Cinsiyet Tablosuna Veri Ekleme

```sql
INSERT INTO Cinsiyet (id, cinsiyet) VALUES (1, 'Erkek'), (2, 'Kadın');
```

- **Amaç**: `Cinsiyet` tablosunda 1 numaralı satıra “Erkek”, 2 numaralı satıra “Kadın” değerlerini ekledik.
- **Mantık**: Tek bir `INSERT` cümlesi ile birden fazla kayıt ekleyebiliyoruz. `(1, 'Erkek')` ve `(2, 'Kadın')` şeklinde iki değer tuple’ı eklenmiş oldu.

### 4.2) Müşteri Tablosuna Veri Ekleme

```sql
INSERT INTO Musteri (id, isim, email, cinsiyet_id) VALUES (1, 'Ali', 'ali@gmail.com', 1);
INSERT INTO Musteri (id, isim, email, cinsiyet_id) VALUES (2, 'Ayşe', 'ayse@gmail.com', 2);
INSERT INTO Musteri (id, isim, email) VALUES (3, 'Veli', 'veli@gmail.com'); -- Varsayılan değer kullanılacak
```

- **Amaç**: Müşteri tablosuna örnek üç kayıt ekliyoruz.
- **Detaylar**:
    - İlk satır: `id = 1`, `isim = 'Ali'`, `email = 'ali@gmail.com'`, `cinsiyet_id = 1`
    - İkinci satır: `id = 2`, `isim = 'Ayşe'`, `email = 'ayse@gmail.com'`, `cinsiyet_id = 2`
    - Üçüncü satır: `id = 3`, `isim = 'Veli'`, `email = 'veli@gmail.com'`. Burada `cinsiyet_id` belirtilmediğinden `DEFAULT 1` devreye giriyor, yani `cinsiyet_id` otomatik olarak `1` oluyor.

---

## 5) Tabloları Sorgulama

```sql
SELECT * FROM Cinsiyet;
SELECT * FROM Musteri;
```

- **Amaç**: Eklediğimiz verilerin tabloda gerçekten durup durmadığını kontrol ediyoruz.
- **Mantık**: `SELECT * FROM tabloAdi` ifadesi, tablonun tüm alanlarını ve tüm satırlarını getirir.

---

## 6) Kısıtları Test Etme

Burada yazılan sorguların bazıları kısıt ihlali yapacak şekilde yazılmıştır. Bu sayede hangi kısıtın ne işe yaradığını test etmiş oluyoruz.

### 6.1) CHECK Kısıtı Testi

```sql
-- Bu işlem hata verecektir çünkü id sıfırdan küçük olamaz
INSERT INTO Musteri (id, isim, email, cinsiyet_id) VALUES (-1, 'Mehmet', 'mehmet@gmail.com', 1);
```

- **Amaç**: `id` sütununda `CHECK (id > 0)` kısıtı vardı. -1 girmeye çalışırsak bu kısıta aykırı olduğu için hata alırız.

### 6.2) UNIQUE Kısıtı Testi

```sql
-- Bu işlem hata verecektir çünkü email UNIQUE olmalı
INSERT INTO Musteri (id, isim, email, cinsiyet_id) VALUES (4, 'Fatma', 'ali@gmail.com', 2);
```

- **Amaç**: `email` alanı UNIQUE kısıtı ile korunuyor. Daha önce `ali@gmail.com` kaydedildiği için tekrar eklemeye çalışınca hata alırız.

### 6.3) DEFAULT Kısıtı Testi

```sql
-- cinsiyet_id belirtilmeden veri ekleme
-- cinsiyet_id otomatik olarak 1 atanacak
INSERT INTO Musteri (id, isim, email) VALUES (5, 'Zeynep', 'zeynep@gmail.com');
```

- **Amaç**: `cinsiyet_id` vermeden bir kayıt ekliyoruz, otomatik olarak `DEFAULT 1` kısıtından dolayı 1 değeri atanmış oluyor.

### 6.4) FOREIGN KEY Kısıtı Testi

```sql
-- Bu işlem hata verecektir çünkü 3, Cinsiyet tablosunda yok
INSERT INTO Musteri (id, isim, email, cinsiyet_id) VALUES (6, 'Ahmet', 'ahmet@gmail.com', 3);
```

- **Amaç**: `cinsiyet_id` değeri, `Cinsiyet` tablosundaki `id` değeri ile eşleşmediği için (çünkü `Cinsiyet` tablosunda 3 yok), `FOREIGN KEY` kısıtından dolayı hata alırız.

---

## 7) Kısıtların Kaldırılması (Dinamik Olarak)

Tablolar oluşturulduktan sonra, bazen kısıtları kaldırmak gerekebilir. Bu kaldırma işlemini tek tek hangi kısıtın adını bildiğinizde yapabilirsiniz. Ancak burada “dinamik” bir yol izlenerek, sistem tablolarından (catalog view’lardan) hangi kısıtların olduğunu sorguluyor ve sonra `DROP` ediyoruz.

### 7.1) CHECK Kısıtını Bul ve Kaldır

```sql
DECLARE @checkConstraintName NVARCHAR(255);

SELECT @checkConstraintName = name
FROM sys.check_constraints
WHERE parent_object_id = OBJECT_ID('Musteri');

IF @checkConstraintName IS NOT NULL
BEGIN
    EXEC('ALTER TABLE Musteri DROP CONSTRAINT ' + @checkConstraintName);
END
```

- **Mantık**:
    1. `sys.check_constraints`: SQL Server’ın içerisinde hangi tabloda hangi check kısıtının olduğunu tutan sistem tablosu.
    2. `OBJECT_ID('Musteri')`: `Musteri` tablosunun içsel ID’sini alıyoruz.
    3. Bu tabloya ait check kısıtının adını (`name`) alıp, `@checkConstraintName` değişkenine atıyoruz.
    4. `IF @checkConstraintName IS NOT NULL` -> Eğer kısıt varsa `ALTER TABLE Musteri DROP CONSTRAINT <kısıt_adı>` diyerek kısıtı kaldırıyoruz.

### 7.2) UNIQUE Kısıtını Bul ve Kaldır

```sql
DECLARE @uniqueConstraintName NVARCHAR(255);

SELECT @uniqueConstraintName = name
FROM sys.indexes
WHERE object_id = OBJECT_ID('Musteri') AND is_unique = 1;

IF @uniqueConstraintName IS NOT NULL
BEGIN
    EXEC('DROP INDEX ' + @uniqueConstraintName + ' ON Musteri');
END
```

- **Mantık**:
    1. `sys.indexes`: SQL Server’ın indeks bilgilerini saklayan sistem tablosu.
    2. `is_unique = 1` -> Bu indeks UNIQUE olarak tanımlanmışsa, UNIQUE kısıt olduğunu anlıyoruz.
    3. `DROP INDEX` komutu ile o indeks (dolayısıyla UNIQUE kısıt) kaldırılmış olur.

### 7.3) FOREIGN KEY Kısıtını Bul ve Kaldır

```sql
DECLARE @foreignKeyName NVARCHAR(255);

SELECT @foreignKeyName = fk.name
FROM sys.foreign_keys AS fk
WHERE fk.parent_object_id = OBJECT_ID('Musteri');

IF @foreignKeyName IS NOT NULL
BEGIN
    EXEC('ALTER TABLE Musteri DROP CONSTRAINT ' + @foreignKeyName);
END
```

- **Mantık**:
    1. `sys.foreign_keys` tablosunda, `Musteri` tablosuna ait tüm yabancı anahtar kısıtları listelenir.
    2. `fk.name` -> o kısıtın adını tutar.
    3. Bulduğumuz isim üzerinden `ALTER TABLE ... DROP CONSTRAINT ...` diyerek kaldırırız.

### 7.4) DEFAULT Kısıtını Bul ve Kaldır

```sql
DECLARE @defaultConstraintName NVARCHAR(255);

SELECT @defaultConstraintName = name
FROM sys.default_constraints
WHERE parent_object_id = OBJECT_ID('Musteri') AND parent_column_id = (
    SELECT column_id
    FROM sys.columns
    WHERE object_id = OBJECT_ID('Musteri') AND name = 'cinsiyet_id'
);

IF @defaultConstraintName IS NOT NULL
BEGIN
    EXEC('ALTER TABLE Musteri DROP CONSTRAINT ' + @defaultConstraintName);
END
```

- **Mantık**:
    1. `sys.default_constraints`: Hangi tabloda, hangi sütun için tanımlı varsayılan değerin (DEFAULT) kısıt adı nedir, buradan öğrenebiliriz.
    2. `parent_column_id = (SELECT column_id FROM sys.columns ...)` ile `cinsiyet_id` kolonunun ID’sini alıyoruz.
    3. Bu şekilde dinamik olarak varsayılan değer kısıtının adı bulunuyor ve `ALTER TABLE ... DROP CONSTRAINT ...` komutuyla kaldırılıyor.

---

## 8) Tabloları Kontrol Etme

```sql
SELECT * FROM Cinsiyet;
SELECT * FROM Musteri;
```

- **Amaç**: Son bir kez tabloların son durumuna bakalım. Artık kısıtlar kaldırılmış olsa da tabloda duran verileri görebiliriz. Kısıtlar “var olan verileri” silmez, sadece yeni eklemeler veya güncellemeler için sınırlamaları kaldırmış olur.

---

# Özet

1. **Veritabanı Oluşturma ve Kullanma**:
    - `CREATE DATABASE` ile veritabanı oluşturduk, `USE` ile seçtik.
2. **Tablo Oluşturma**:
    - `Cinsiyet` tablosunda `id` (Primary Key) ve `cinsiyet` alanı var.
    - `Musteri` tablosunda `Primary Key (id)`, `NOT NULL (isim)`, `UNIQUE (email)`, `DEFAULT (cinsiyet_id = 1)`, `FOREIGN KEY (cinsiyet_id -> Cinsiyet.id)` ve `CHECK (id > 0)` kısıtlarını kullandık.
3. **Veri Ekleme**:
    - `INSERT INTO ... VALUES(...)` komutu ile hem tek tek hem de birden fazla satır şeklinde veri ekledik.
4. **Kısıtların Testi**:
    - `CHECK`, `UNIQUE`, `DEFAULT`, `FOREIGN KEY` kısıtlarını ihlal edecek örnekler gösterdik. Bu sorgular çalıştırıldığında hata verir.
5. **Kısıtların Kaldırılması**:
    - SQL Server’ın sistem tablolarını (`sys.*`) kullanarak dinamik bir şekilde kısıt isimlerini bulduk ve `ALTER TABLE ... DROP CONSTRAINT` veya `DROP INDEX` komutları ile kaldırdık.
6. **Son Kontrol**:
    - `SELECT *` komutu ile tablolardaki verileri görüntüledik.

Bu aşamaları anladıktan sonra sınavda size bu konularla ilgili bir soru geldiğinde:

- Hangi kısıtın ne işe yaradığını,
- Nasıl eklendiğini (`CREATE TABLE` içinde veya sonradan `ALTER TABLE` ile),
- Nasıl kaldırıldığını (özellikle dinamik yolları),
- Neden “PRIMARY KEY”, “FOREIGN KEY”, “UNIQUE”, “NOT NULL”, “CHECK” gibi kısıtları kullanmak gerektiğini

açıklayabilirsiniz. Ayrıca “DEFAULT” kısıtı sayesinde bir kolona değer atanmadığında otomatik olarak devreye giren değerleri yönetebilirsiniz.