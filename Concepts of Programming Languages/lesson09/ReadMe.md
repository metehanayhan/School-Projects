# 10. Hafta

### **Veri Tipleri ve İlkel Veri Tipleri**

Bu bölüm, veri tiplerinin tanımını, ilkel veri tiplerini ve farklı programlama dillerinde veri tiplerinin kullanımını detaylı bir şekilde açıklar. Şimdi, bu kavramları ele alalım:

---

### **1. Veri Tipleri ve Temel Kavramlar**

### **Veri Tipi (Data Type):**

Bir veri tipi, bir veri koleksiyonunu ve o veriler üzerinde tanımlanmış işlemleri ifade eder.

Veri tipleri şu özelliklerle karakterize edilir:

1. **Bellekte Temsil:** Verinin nasıl saklanacağını belirler.
2. **Değer Yorumlama:** Verinin ne anlama geldiğini tanımlar.
3. **İşlemler:** Verinin üzerinde hangi işlemlerin yapılabileceğini belirler.

### **Descriptor (Tanımlayıcı):**

Bir değişkenin tüm özniteliklerinin bir koleksiyonudur. Örneğin, bir değişkenin adı, türü, boyutu ve değeri bir descriptor ile tutulabilir.

### **Obje (Object):**

Kullanıcı tarafından tanımlanan bir veri tipinin (örneğin, sınıfların) bir örneğini (instance) ifade eder.

---

### **2. İlkel Veri Tipleri**

### **Genel Özellikler:**

- İlkel veri tipleri, başka veri tiplerinden türetilmemiştir.
- Programlama dillerinin tasarımında önceden tanımlanmıştır.
- Genellikle donanım seviyesinde doğrudan desteklenir.

---

### **3. İlkel Veri Tipleri ve Türleri**

### **Tamsayılar (Integer):**

- Donanımın doğrudan yansımasıdır ve genellikle haritalama gerektirmez.
- **C Dili:**
    - 4 farklı tamsayı tipi bulunur (örneğin, `short`, `int`, `long`).
    - İşaretli (`signed`) ve işaretsiz (`unsigned`) olarak toplam 8 tür vardır.
- **Java:**
    - Tamsayı türleri: `byte`, `short`, `int`, `long`.

---

### **Kayan Noktalı Sayılar (Floating Point):**

- Reel sayıları temsil eder ancak değerler yaklaşık olarak saklanır.
- Sayı iki bölümde ifade edilir: **Kesir** ve **Üs**.
- **IEEE Standardı:**
    - Tek duyarlıklı (single precision) ve çift duyarlıklı (double precision) formatlar desteklenir.

---

### **Karmaşık Sayılar (Complex):**

- **Destekleyen Diller:** C99, Fortran, Python.
- Her bir karmaşık sayı, **gerçek** ve **sanal** iki bölümden oluşur.
    - Örnek (Python): `(7 + 3j)` → Gerçek kısım: 7, Sanal kısım: 3.

---

### **Onlu Sayılar (Decimal):**

- Ticari işlemler ve para hesaplamaları için kullanılır.
- **Destekleyen Diller:** COBOL, C#.
- Sabit bir ondalık basamak sayısı içerir.
- **Avantaj:** Hassasiyet sağlar.
- **Dezavantajlar:** Bellek israfı, sınırlı aralık.

---

### **Mantıksal (Boolean):**

- İki değer alabilir: **true** ve **false**.
- En basit veri tipidir.
- Genellikle bitler ile temsil edilir ancak okunabilirlik için baytlar olarak da depolanabilir.

---

### **Karakterler (Character):**

- Veriler, sayısal kodlamalar ile saklanır.
- **Kodlama Türleri:**
    - **ASCII:**
        - 8 kontrol karakteri, 31 noktalama işareti, 26 yazılamayan karakter ve diğer harfler/rakamlar.
    - **Unicode (UCS-2 ve UCS-4):**
        - Java, C#, JavaScript, ve Fortran (2003+ sürümleri) destekler.
        - Doğal dillerin çoğunu içerir.

---

### **Karakter Katarları (String):**

- Bir dizi karakterden oluşur.
- **Tasarım Konuları:**
    1. İlkel bir veri tipi mi, yoksa bir dizinin özel bir türü mü?
    2. Uzunluğu statik mi, yoksa dinamik mi?

---

### **4. Dillerde Karakter Katarı Tipleri**

### **Farklı Dillerde Uygulamalar:**

| **Dil** | **Özellikler** |
| --- | --- |
| **C ve C++** | İlkel veri tipi değildir, `char` dizileri kullanılır. |
| **SNOBOL4** | İlkel veri tipidir ve gelişmiş örüntü eşleştirme işlemleri desteklenir. |
| **Fortran, Python** | İlkel veri tipi olarak atanabilir ve temel işlemler yapılabilir. |
| **Java** | `String` sınıfı ile ilkel bir veri tipi gibi davranır. |
| **Perl, PHP** | Düzenli ifadelerle örüntü eşleştirme sağlar. |
| **ADA** | String tipi, karakterlerden oluşan bir dizidir. |

---

### **Karakter Katarlarının Uzunluk Seçenekleri:**

1. **Statik Uzunluk:**
    - Örneğin, **COBOL**, Java'nın `String` sınıfı.
2. **Sınırlı Dinamik Uzunluk:**
    - Örneğin, **C ve C++**. Sonlandırıcı karakter (`\0`) ile biten diziler.
3. **Dinamik Uzunluk:**
    - Örneğin, **SNOBOL4**, Perl, JavaScript. Uzunluk çalışma sırasında değişebilir.

---

### **Sonuç**

- İlkel veri tipleri, programlama dillerinin temel yapı taşlarını oluşturur ve dil tasarımında kritik bir role sahiptir.
- **Tamsayılar**, **kayan noktalı sayılar**, **mantıksal değerler**, **karakterler**, ve **stringler** gibi ilkel veri tipleri, çoğu modern dilde bulunur.
- Diller arasında veri tiplerinin uygulanma biçimleri farklılık gösterse de hepsi verilerin bellek temsili, yorumlanması ve üzerinde işlem yapılması için gereklidir.

---

### **Dinamik Uzunluklu Karakter Katarları İçin Dinamik Bellek Yönetimi**

Karakter katarlarının uzunluğu değiştikçe bellek tahsis ve serbest bırakma yöntemleri farklı yaklaşımlar kullanır. Üç farklı yöntem açıklanmıştır:

1. **Bağlantılı Liste Yöntemi:**
    - Karakterler, yığın bellekte bir bağlı liste (linked list) şeklinde depolanır.
    - Yeni hücreler gerektiğinde, yığın belleğin herhangi bir yerinden alınır.
    - **Dezavantajlar:**
        - Liste bağları için ekstra bellek kullanımı gerektirir.
        - Karakter katarı işlemleri daha karmaşık ve yavaştır.
2. **Gösterici Dizisi Yöntemi:**
    - Karakterler için yığın bellekte bireysel göstericilere (pointers) sahip bir dizi oluşturulur.
    - **Avantajlar:**
        - Bağlantılı liste yöntemine göre daha hızlı işlem yapar.
    - **Dezavantajlar:**
        - Hâlâ ekstra bellek gerektirir.
3. **Bitişik Depolama Yöntemi:**
    - Karakterler, bitişik bellek hücrelerinde saklanır.
    - Eğer karakter katarı büyürse, yeni bir bitişik bellek alanı tahsis edilir ve eski alan yeni yere taşınır.
    - **Avantajlar:**
        - Daha az bellek tüketir.
        - İşlemler hızlıdır.
    - **Dezavantajlar:**
        - Tahsis ve serbest bırakma işlemleri daha yavaştır.

---

### **Kullanıcı Tanımlı Sıralı Tipler**

Kullanıcı tanımlı veri tipleri, programcıların gerçek dünya nesnelerine uygun özel veri tipleri oluşturmasını sağlar. İki ana türü vardır:

1. **Sayılama Tipleri (Enumeration):**
    - Belirli bir sayıdaki isimden oluşan veri tipleri.
    - Gerçek dünyadaki kavramlara karşılık gelir (örneğin, günler, renkler).
    - **Örnekler:**
        - **Ada:**
            
            ```
            type gunler is (Pazartesi, Salı, Çarşamba, Perşembe, Cuma, Cumartesi, Pazar);
            ```
            
        - **C#:**
            
            ```csharp
            enum days { mon, tue, wed, thu, fri, sat, sun };
            ```
            
2. **Altalan Tipleri (Subrange):**
    - Bir sıralı tipin belirli bir alt kümesi.
    - Okunabilirliği artırır ve güvenilirliği sağlar.
    - **Örnek:**
        
        ```pascal
        type notlar = 1..100;  // 1 ile 100 arasında değerler
        ```
        

---

### **Türetilmiş Veri Tipleri: Diziler**

### **Dizi Tanımı:**

- Aynı türden verilerin sıralı bir şekilde bellekte tutulmasını sağlar.
- **Avantajlar:**
    - Programlama esnekliği sağlar.
    - Okunabilirliği artırır.

### **Dizi Tasarım Soruları:**

1. Hangi türler indisler için kullanılabilir?
2. İndis aralığı kontrol edilir mi?
3. Dizi nesneleri başlatılabilir mi?
4. Çok boyutlu diziler nasıl desteklenir (örneğin, dikdörtgen veya düzensiz)?

### **Dizi İndeksleme ve Sözdizimi:**

- **Sözdizim Örnekleri:**
    - **Fortran, Ada:** Normal parantez kullanır. `( )`
    - **C, C++, Java:** Köşeli parantez kullanır. `[ ]`
- **İndeks Tipleri:**
    - **FORTRAN, C:** Sadece tamsayı tipleri.
    - **Java:** Sadece tamsayı tipleri.

### **İndis Aralığı Kontrolü:**

- **Kontrol Yok:** C, C++, Perl, Fortran.
- **Kontrol Var:** Java, C#, ML.

---

### **Bellek Yönetimi**

### **Bellek Bölgeleri:**

1. **Statik Bellek Bölgesi:**
    - Global değişkenler, sabitler ve `static` olarak tanımlanan yerel değişkenler burada saklanır.
    - Program başlamadan önce ayrılır ve sonlanana kadar kalır.
2. **Çalışma Anı Yığını (Stack):**
    - Alt programların çağrılma sırasına göre bellek tahsisi yapılır.
3. **Heap Bellek:**
    - Dinamik olarak tahsis edilen bellek için kullanılır.
4. **Derlenmiş Kod Bölgesi:**
    - Çalışan programın kodlarının bulunduğu bölgedir.

---

### **Statik Bellek Bölgesi**

- **Statik Bellekte Yer Alan Değişkenler:**
    - Global değişkenler.
    - Sabitler.
    - `Static` olarak tanımlanan yerel değişkenler.
- **Özellikler:**
    - Program başladığında tahsis edilir.
    - Program sonlanana kadar bellekte kalır.
    - **Dezavantaj:** Global değişkenler, beklenmedik hatalara neden olabilir, bu yüzden dikkatli kullanılmalıdır.

---

### **Özet**

1. **Dinamik Bellek Yönetimi:**
    - Bağlantılı liste, gösterici dizisi ve bitişik depolama yöntemleri arasında bir denge kurulmalıdır.
    - Bitişik depolama yöntemi genellikle en etkili çözümdür.
2. **Kullanıcı Tanımlı Sıralı Tipler:**
    - Gerçek dünya nesnelerini modellemek için sayılama ve altalan tipleri kullanılabilir.
3. **Diziler:**
    - İndisleme, indeks kontrolü ve bellek tahsisi dizi tasarımında dikkate alınması gereken önemli konulardır.
4. **Bellek Yönetimi:**
    - Programlarda bellek bölgelerinin doğru bir şekilde kullanımı, performans ve güvenilirlik açısından önemlidir.

---

### **Bellek Yönetimi ve Veri Tipleri**

---

### **Çalışma Anı Yığını (Stack Memory)**

### **Özellikler:**

- **En aktif bellek bölgesi**: Program çalışırken en sık kullanılan bellek yapısıdır.
- **Genişleme/Daralma:** Fonksiyon çağrıldığında genişler ve dönüşte daralır.
- **Yerel Değişkenler:** Fonksiyon ve metotların yerel değişkenleri burada tutulur.
- **Bellek Yönetimi:** Fonksiyon veya metot çağrısı sona erdiğinde, bu alana ayrılan bellek otomatik olarak geri verilir.

### **Avantajlar:**

1. **Otomatik Yönetim:** Bellek tahsisi ve serbest bırakma otomatik olarak yapılır.
2. **Verimlilik:** Hızlıdır, çünkü yığındaki bellek blokları ardışık olarak yönetilir.

### **Dezavantaj:**

- **Süre Sınırlaması:** Yığındaki değişkenlere, çağrı sona erdikten sonra erişilemez.

---

### **Heap Bellek Bölgesi**

### **Özellikler:**

- **Dinamik Bellek Yönetimi:** Çalışma sırasında boyutları belirlenir.
- **Kullanıcı Kontrolü:** C ve C++ gibi dillerde, heap bellek tahsisi manuel yapılır.
    - **C**: `malloc` ile bellek tahsisi, `free` ile serbest bırakma.
    - **Java**: `new` ile bellek tahsisi, çöp toplayıcı (garbage collector) ile otomatik serbest bırakma.

### **Avantajlar:**

1. **Esneklik:** Dinamik olarak değişken boyutlu yapılar oluşturulabilir.
2. **Dinamik Veri Yapıları:** Bağlı listeler, ağaçlar gibi veri yapıları için uygundur.

### **Dezavantajlar:**

1. **Bellek Sızıntıları:** Kullanıcı `free` veya `delete` kullanmayı unutursa, bellek sızıntısı oluşabilir.
2. **Hata Riski:** Yanlış bellek erişimi hata yaratabilir.

---

### **İndislerin Bağlanması ve Dizi Kategorileri**

### **Dizi Türleri:**

1. **Statik Diziler:**
    - İndis aralıkları ve bellek tahsisi derleme zamanında belirlenir.
    - **Avantaj:** Yüksek verimlilik (dinamik tahsis yok).
2. **Sabit Yığıt-Dinamik Diziler:**
    - İndis aralıkları statik olarak belirlenir ancak bellek tahsisi çalışma zamanında yapılır.
    - **Avantaj:** Bellek tasarrufu.
3. **Sabit Yığın-Dinamik Diziler:**
    - Bellek yığıt yerine heap’ten tahsis edilir, ancak tahsis edildikten sonra boyutları sabittir.
4. **Heap-Dinamik Diziler:**
    - İndis aralıkları ve bellek tahsisi tamamen dinamik ve program sırasında değişebilir.
    - **Avantaj:** Esneklik.

---

### **Dizi İndeksleme**

### **Adres Polinomu:**

- Tek Boyutlu Diziler:
    
    ```css
    Adres(A[k]) = Adres(A[0]) + k * eleman_boyutu
    ```
    
- Çok Boyutlu Diziler:
    
    ```scss
    Adres(A[i, j]) = Adres(A[0, 0]) + (((i - alt_satır) * sütun_sayısı) + (j - alt_sütun)) * eleman_boyutu
    ```
    

---

### **Slices (Alt Dilimler)**

### **Tanım:**

- Bir dizinin alt yapısını temsil eder. Dilimler, bir referans mekanizmasıdır.
- **Kullanım Örnekleri:**
    - **Python:**
        
        ```python
        vector = [2, 4, 6, 8, 10, 12, 14, 16]
        slice_vector = vector[2:5]  # [6, 8, 10]
        ```
        
    - **Ruby:**
        
        ```ruby
        list = [1, 2, 3, 4, 5]
        slice = list.slice(2, 2)  # [3, 4]
        ```
        

---

### **Kayıt (Record) Veri Tipi**

### **Tanım:**

- Heterojen veri elemanlarının bir araya getirilmesiyle oluşturulan veri yapısıdır.
- **Dizi ile Fark:** Dizi homojen elemanlardan oluşurken, kayıt heterojen elemanlar içerebilir.
- **Örnek (Pascal):**
    
    ```pascal
    Personel = record
      Ad: String[15];
      Soyad: String[15];
      Maas: LongInt;
    end;
    ```
    

### **Avantaj:**

- Okunabilirlik ve düzen sağlar. Kayıt alanlarına isimle erişim yapılır.

---

### **Tuple (Demet) Tipleri**

### **Tanım:**

- Kayıtlara benzer ancak alanlar adlandırılmamıştır.
- Kullanım alanı: Fonksiyonların birden fazla değer döndürmesi.
- **Örnek (Python):**
    
    ```python
    my_tuple = (3, 5.8, 'apple')
    print(my_tuple[0])  # 3
    ```
    

### **Avantaj:**

- Basit ve esnek bir yapı sağlar.

---

### **Ortaklık (Union) Veri Tipi**

### **Tanım:**

- Aynı bellek bölgesinin birden fazla değişken tarafından kullanılmasını sağlar.
- **Örnek (C):**
    
    ```c
    union Example {
        int i;
        float f;
    };
    ```
    

### **Avantajlar:**

1. Bellek verimliliği sağlar.
2. Birden fazla değişken için aynı bellek bölgesi kullanılır.

### **Dezavantaj:**

- Tip kontrolü yapılmazsa güvenilirlik sorunlarına yol açar.

---

### **Gösterici (Pointer) Veri Tipi**

### **Tanım:**

- Değişkenlerin adreslerini tutan veri tipidir.
- **Örnek (C):**
    
    ```c
    int x = 10;
    int *ptr = &x;
    ```
    

### **Avantajlar:**

1. Dinamik veri yapılarının kullanımı kolaylaşır.
2. Bellek yönetimi ve çoklu değer döndürme işlemlerinde esneklik sağlar.

---

### **Sonuç**

- **Bellek Yönetimi:** Yığın ve heap bölgeleri, farklı kullanım durumlarına göre avantajlar ve zorluklar sunar.
- **Diziler:** Sabit veya dinamik diziler, programlama dili tasarımına göre farklı yaklaşımlar gerektirir.
- **Veri Yapıları:** Kayıtlar, demetler ve union veri tipleri gibi yapılar, heterojen veri saklama ve işleme ihtiyaçlarına uygun çözümler sağlar.
- **Göstericiler:** Bellek üzerinde doğrudan kontrol sağlar ancak dikkatli kullanılmalıdır.

---

### **Pointer Veri Tipi**

### **Tanım:**

- **Pointer** (işaretçi), bellek adreslerini saklayan bir veri tipidir.
- Pointer değişkenlerinin değer aralığı, bellek adreslerinden ve özel bir `nil` değerinden oluşur.
- Dinamik bellek yönetimi ve dolaylı adresleme sağlamak için kullanılır.

### **Kullanım Alanları:**

1. Dinamik bellek tahsisi.
2. Yığın bellek dışında oluşturulan dinamik veriye erişim.

### **Avantajlar:**

- Bellek üzerinde dolaylı kontrol sağlar.
- Dinamik veri yapıları oluşturmayı mümkün kılar (örneğin, bağlı listeler, ağaçlar).

### **Örnek (C++):**

```cpp
int x = 10;
int *ptr = &x; // x'in adresini ptr'ye ata
std::cout << *ptr; // x'in değerini yazdır (10)
```

---

### **Pointer ile İlgili Sorunlar**

### **1. Sallanan Pointerlar (Dangling Pointers):**

- Bir pointer, bellekte serbest bırakılmış bir alana işaret etmeye devam ettiğinde oluşur.
- **Örnek:**
    
    ```cpp
    int *ptr = new int(10);
    delete ptr;  // Bellek serbest bırakılır
    // ptr hala aynı adrese işaret eder ve bu adres artık geçersizdir
    ```
    

### **2. Kaybolan Dinamik Bellek (Lost Heap-Dynamic Variables):**

- Bir pointer, başka bir heap-dinamik değişkene yeniden atanırsa, eski adres erişilemez hale gelir.
- Bu duruma **bellek sızıntısı (memory leakage)** denir.
- **Örnek:**
    
    ```cpp
    int *ptr = new int(10);
    ptr = new int(20); // İlk adres artık ulaşılmaz durumda (sızıntı)
    ```
    

### **Çözüm Yöntemleri:**

- **Manuel Bellek Yönetimi:**
    - Bellek `free` veya `delete` ile serbest bırakılmalıdır.
- **Garbage Collection:**
    - Java gibi dillerde, kullanılmayan bellek alanları otomatik olarak serbest bırakılır.

---

### **Pointerların Değerlendirilmesi**

### **Avantajlar:**

- Dinamik veri yapılarının uygulanmasını sağlar.
- Hafıza yönetimi üzerinde esneklik sunar.

### **Dezavantajlar:**

- **Güvenlik:** Sallanan pointerlar ve bellek sızıntıları ciddi sorunlara yol açabilir.
- **Okunabilirlik:** Kodun takibi zorlaşabilir.

---

### **Tip Kontrolü (Type Checking)**

### **Tanım:**

- Operatörlerin operandlarının uyumlu tiplerde olup olmadığını kontrol etme işlemidir.
- **Uygun Tip:** Operatörle yasal olarak kullanılan veya dil kuralları gereği otomatik olarak dönüştürülebilen tiplerdir.
- **Koersiyon:** Uyumlu olmayan tiplerin otomatik olarak uyumlu bir tipe dönüştürülmesi işlemidir.

### **Örnek (Koersiyon):**

```cpp
int x = 10;
float y = 5.5;
float z = x + y; // x otomatik olarak float'a dönüştürülür
```

### **Tip Hataları:**

- Operatörün uygun olmayan bir operand ile kullanılması durumu.
- **Güçlü Tip Kontrolü (Strong Typing):**
    - Tüm tip hatalarını derleme veya çalışma zamanında yakalayabilen diller (örneğin, Java, C#).

### **Kuvvetli Tipleme Örnekleri:**

- **C ve C++:**
    - Kuvvetli tipli değildir (union kullanımı ve parametre tipi kontrolünden kaçınma durumu vardır).
- **Java ve C#:**
    - Çoğunlukla kuvvetli tipli.
- **ML ve F#:**
    - Tamamen kuvvetli tiplidir.

---

### **Tip Dönüşümleri**

### **Dönüşüm Türleri:**

1. **Daralan Dönüşüm (Narrowing Conversion):**
    - Veri kaybı riski taşır.
    - Örnek: `float` → `int`.
        
        ```cpp
        float x = 10.7;
        int y = (int)x; // y = 10
        ```
        
2. **Genişleyen Dönüşüm (Widening Conversion):**
    - Veri kaybı riski yoktur.
    - Örnek: `int` → `float`.
        
        ```cpp
        int x = 10;
        float y = x; // y = 10.0
        ```
        

### **Örtülü (Implicit) Dönüşüm:**

- Derleyici tarafından otomatik yapılan dönüşümlerdir.
- **Örnek:**
    
    ```cpp
    int a = 5;
    float b = a; // int, float'a dönüştürülür
    ```
    

### **Açık (Explicit) Dönüşüm:**

- Programcı tarafından belirtilir.
- **Örnek:**
    
    ```cpp
    int a = 5;
    float b = (float)a;
    ```
    

---

### **Sonuç**

1. **Pointer Kullanımı:**
    - Bellek yönetimi ve dinamik veri yapılarında vazgeçilmezdir.
    - Ancak, sallanan pointer ve bellek sızıntısı gibi risklere karşı dikkatli olunmalıdır.
2. **Tip Kontrolü:**
    - Kuvvetli tip kontrolü, tip hatalarının erken tespit edilmesini sağlar.
    - Derleyici destekliyorsa, uygun dönüşümler otomatik yapılabilir.
3. **Tip Dönüşümleri:**
    - Genişleyen dönüşümler genellikle güvenli, daralan dönüşümler ise dikkat gerektirir.

---