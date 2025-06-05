# 5. Hafta

özellik gramerleri nedir 

Özellik Gramerleri (Attribute Grammars) programlama dillerinin yapısını ve anlamını tanımlamak için kullanılan güçlü bir araçtır. Bu konu, özellikle programlama dillerinin sözdizimi ve statik anlambilimsel analizinde yaygın olarak kullanılır. Şimdi, bu kavramları adım adım ve örneklerle açıklayalım:

### 1. **Özellik Gramerleri Nedir?**

Özellik gramerleri, **Bağlamsız Gramerler**'in (CFG - Context-Free Grammars) genişletilmiş halidir. Bağlamsız gramerler, bir dilin yapısal kurallarını belirler. Ancak sadece sözdizimini belirlemek dilin anlamı hakkında yeterli bilgi sağlamaz. Özellik gramerleri, bu eksikliği gidermek ve dilin statik anlambilimsel kurallarını tanımlamak için ek bilgiler sağlar.

- **Bağlamsız Gramerler (CFG)**: Bir dilin temel yapısını tanımlayan kurallardır. Örneğin, bir matematiksel ifade (expression) şu şekillerde olabilir:
    - `E -> E + E`
    - `E -> E * E`
    - `E -> (E)`
    - `E -> num`

Bu kurallar, matematiksel ifadelerin nasıl oluşturulabileceğini söyler. Ancak bu, ifade içindeki operatörlerin anlamını (örneğin, `+` ve `*` operatörlerinin ne anlama geldiğini) tanımlamaz. İşte bu noktada **Özellik Gramerleri** devreye girer.

### 2. **Özellik Gramerlerinin Amacı ve Yapısı**

Özellik gramerlerinin amacı, dildeki yapılar hakkında ek bilgi sağlamaktır. Bu bilgiler, özellikler (attributes) olarak adlandırılır ve dilin farklı elemanlarına atanır. Bu özellikler, genellikle iki türe ayrılır:

- **Sentezlenmiş Özellikler (Synthesized Attributes)**: Alt düğümlerden üst düğümlere bilgi taşır. Bir ifadenin sonucunu hesaplama gibi işlevlere sahiptir.
- **Kazanılmış Özellikler (Inherited Attributes)**: Üst düğümlerden alt düğümlere bilgi aktarır. Dilin belirli kurallarını kontrol etmek için kullanılır (örneğin, tip uyumluluğu gibi).

Örneğin, bir dildeki bir ifadenin sonucunu hesaplamak için sentezlenmiş özellikler kullanılabilir. Eğer bir ifade `(3 + 4) * 2` ise, önce `(3 + 4)` işlemi yapılır, sonra sonuç `7` ile `* 2` işlemi yapılır ve sonuç `14` olur. Bu işlemler, özellikler aracılığıyla tanımlanır.

### Örnek: Matematiksel İfade Grameri

- CFG Kuralı: `E -> E1 + E2`
    - Burada `E`, `E1` ve `E2` ifadeleridir.
- Özellikler:
    - `E.val = E1.val + E2.val` (Sentezlenmiş özellik)

Bu kural, iki ifadenin toplanmasını tanımlar. Örneğin, `E1` ve `E2` ifadelerinin değerleri (örneğin `3` ve `4`), üstteki `E` düğümüne sentezlenir ve `7` sonucu elde edilir.

### 3. **Statik Anlambilim (Static Semantics) ve Tip Uyumluluğu**

**Statik anlambilim**, bir dilin kurallarını **derleme zamanında** kontrol etmeyi amaçlar. Tip uyumluluğu gibi kurallar statik anlambilimle ilgilidir. Örneğin, bir dilde bir değişkenin tipi, başka bir tipteki değişkenle uyumlu olmalıdır. Bu, dilin derlenmeden önce doğru olduğunun garantilenmesini sağlar.

Özellik gramerleri, tip uyumluluğunu kontrol etmek için de kullanılır. Örneğin, bir dilde `int` tipi bir değişkenle `float` tipi bir değişkeni toplamak istenirse, bu işlemin kurallara uygun olup olmadığı özelliklerle kontrol edilebilir.

### Örnek: Tip Uyumluluğu

- CFG Kuralı: `E -> E1 + E2`
    - `E1.type == E2.type` olmalıdır.
    - Eğer `E1` ve `E2` tipleri aynı değilse, derleyici hata verir.

Bu şekilde, özellikler aracılığıyla derleme zamanında dilin statik anlambilimi kontrol edilir.

### 4. **Özellik Gramerlerinin Kullanım Alanları**

Özellik gramerleri, birçok farklı alanda kullanılmıştır:

- **Programlama Dillerinin Tanımlanması**: Özellik gramerleri, programlama dillerinin hem sözdizimini hem de statik anlambilim kurallarını tanımlamak için kullanılır. Örneğin, bir derleyici, programın doğru tipte olup olmadığını veya belirli kurallara uyup uymadığını özellik gramerleriyle kontrol eder.
    
    **Örnek**: Watt (1979), programlama dillerinin tam tanımını özellik gramerleriyle sağlayan çalışmalardan biridir.
    
- **Derleyici Üretimi**: Özellik gramerleri, derleyicilerin dilin yapısını ve anlamını formel bir şekilde tanımlamasına yardımcı olur. Farrow (1982), bu yaklaşımı kullanarak bir derleyici üretim sistemine formal dil tanımları eklemiştir.
- **Sözdizim Düzenleme Sistemleri**: Fischer ve arkadaşları (1984), Teitelbaum ve Reps (1981) gibi araştırmacılar, sözdizimi temelli düzenleme sistemleri oluştururken özellik gramerlerini temel almışlardır.
- **Doğal Dil İşleme (NLP)**: Özellik gramerleri, doğal dillerin (İngilizce, Türkçe vb.) işlenmesinde de kullanılmaktadır. Correa (1992), doğal dil işleme sistemlerinde bu gramerleri kullanmıştır. Örneğin, bir cümlenin doğru olup olmadığını kontrol etmek için kullanılabilir.

### 5. **Sonuç**

Özellik gramerleri, bir dilin sadece sözdizimini değil, aynı zamanda anlamını ve statik anlambilim kurallarını da tanımlamak için kullanılan güçlü bir araçtır. Bağlamsız gramerlerden farklı olarak, ek bilgi ve kurallar sağlarlar. Programlama dillerinin tanımlanması, derleyici üretimi ve doğal dil işleme gibi birçok alanda geniş bir kullanım alanına sahiptir.

Bu tanımlamalar, bir dilin doğru şekilde tanımlanmasını ve çalışmasını sağlamak için büyük önem taşır.

---

### Statik Semantik (Anlam) Nedir?

**Statik semantik**, bir programlama dilinin kurallarını **derleme zamanında** kontrol eden anlambilimsel kurallardır. Statik semantik, dilin **sözdizimsel** kurallarından farklıdır. Sözdizim kuralları (BNF gibi), programın yapısal doğruluğunu kontrol ederken, statik semantik dilin **tip uyumluluğu**, **değişkenlerin bildirilmesi** gibi mantıksal kuralları kontrol eder.

Bir programda statik semantik kurallarının doğru uygulanması, programın çalışma zamanında beklenmeyen hatalara yol açmadan çalışmasını sağlar. Bu kurallar, genellikle BNF (Backus-Naur Form) gibi bağlamsız gramerler ile tam olarak ifade edilemez. Bu yüzden statik semantik kurallarını ek özellikler ve kontroller ile tanımlamak gereklidir.

### 1. **BNF ile Tanımlanamayan Yapılar**

**BNF** (Backus-Naur Form) bir dilin sözdizimini tanımlayan formeldir. Ancak, bazı dil kurallarını sadece sözdizim ile tanımlamak mümkün değildir. Statik semantik kurallarını, dilin daha anlamlı hale gelmesi için eklememiz gerekir.

- **Tip Uyumluluğu**: Bir programlama dilinde her ifadenin, her işlemin, her değişkenin belirli bir tipi vardır. Tip uyumluluğu, bir ifadenin tipinin beklenen tip ile eşleşmesini ifade eder.
    - Örneğin, bir Java programında `float` tipindeki bir değerin `int` tipindeki bir değişkene atanması gibi durumlar, sözdizim açısından doğru olabilir. Ancak bu durum, **tip uyumluluğu** açısından hatalıdır ve statik anlambilimle kontrol edilmelidir.

BNF, dilin yapısını ve sözdizimini ifade ederken oldukça başarılı olsa da, **tip uyumluluğu** gibi daha soyut kuralları tanımlamak için yetersiz kalır. Bu gibi durumlar için daha karmaşık yapılar ve kurallar gereklidir.

### 2. **Tip Uyumluluğu Örneği**

Bir dilde, `int` ve `float` gibi veri türleri olabilir. Örneğin, Java'da aşağıdaki gibi bir kod parçası düşünelim:

```java
int x;
float y = 5.5f;
x = y; // Hatalı, çünkü float bir değeri int'e atıyoruz
```

Bu durum, Java gibi tip güvenliğine sahip dillerde derleyici tarafından hata olarak tanımlanır. Bu tip uyumluluk hatası, BNF ile tam olarak tanımlanamaz çünkü BNF sadece dilin yapısını, yani sözdizimini tanımlar. Ancak tip uyumluluğu gibi statik semantik kurallarını eklemek, dilin anlambilimsel doğruluğunu garanti eder.

### 3. **BNF'nin Sınırları**

BNF, dilin yapısını tanımlarken oldukça kullanışlıdır. Ancak, bazı statik semantik kurallarını tanımlamak zor ya da imkansız hale gelir. İşte bununla ilgili bazı önemli noktalar:

- **BNF'nin Yetersizliği**: Tüm **tip uyumluluğu** kurallarını BNF ile tanımlamaya çalışmak, dilbilgisinin aşırı derecede büyümesine neden olur. Örneğin, `int`, `float`, `double` gibi birçok farklı veri türünü ve bunların birbirleriyle olan etkileşimlerini BNF ile tanımlamak oldukça karmaşıktır. Bu, derleyici tarafından kullanılacak olan **sözdizim analizcisini** de aşırı derecede karmaşık ve büyük hale getirir.
- **Ekstra Kurallar**: BNF ile bu tip semantik kuralları tanımlanacaksa, dilbilgisine ekstra kurallar ve **nonterminal semboller** eklenmelidir. Örneğin, her farklı tip kombinasyonu için yeni kurallar ve semboller oluşturulması gerekir. Bu durum, dilin **aşırı karmaşık** bir hale gelmesine neden olur ve dilbilgisinin büyüklüğü, derleyicinin performansını etkiler.

### 4. **BNF ile Tanımlanamayan Bir Kural Örneği**

BNF’nin sınırlarını gösteren klasik bir örnek, bir programda **tüm değişkenlerin başvurulmadan önce bildirilmesi gerektiği** kuralıdır. Bu, modern programlama dillerinin çoğunda bulunan önemli bir statik semantik kuralıdır.

- **Değişkenlerin Bildirilmesi**: Bir programda bir değişkene atama yapılmadan önce o değişkenin tanımlanmış olması gerekir. Örneğin, şu Python kodu düşünelim:

```python
x = 5
print(y)  # Hata! 'y' değişkeni tanımlanmamış
```

Bu kurala göre, `y` değişkeni kullanılmadan önce bildirilmelidir. Bu kural, **BNF ile tanımlanamaz** çünkü bu, programın anlamı ile ilgili bir kuraldır, sadece yapısı ile ilgili değildir.

### 5. **Sonuç: Statik Semantik ve Sözdizim İlişkisi**

Özetle, statik semantik kurallar, bir dilin mantıksal ve anlamsal doğruluğunu sağlamak için gereklidir. **BNF**, dilin yapısını tanımlamakta başarılıdır, ancak tip uyumluluğu, değişkenlerin bildirimi gibi kuralları tanımlamak için yetersizdir. Bu yüzden, dil tasarımında ve derleyici geliştirmede **özellik gramerleri** ve **statik semantik** gibi ek araçlar kullanılarak dilin doğruluğu garanti altına alınır.

Örnek olarak, tip uyumluluğu ve değişkenlerin tanımlanması gibi kurallar, BNF ile ifade edilemediği için statik semantik ile tanımlanır ve derleme zamanında bu kurallar kontrol edilir.

---

### Statik Semantik Nedir?

**Statik Semantik** (Static Semantics), bir programlama dilinin **anlambilimsel kurallarının** derleme zamanında kontrol edilmesini sağlar. Statik semantik, programın çalışmasından önce, yazılan kodun dilin belirli kurallarına uygun olup olmadığını kontrol eder. Bu kurallar genellikle **tip kısıtlamaları**, **değişkenlerin doğru kullanımı**, **bildirilmeden önce değişkenlere erişim** gibi mantıksal ve anlamsal doğrulukları içerir.

Bu kavramın önemli noktalarını adım adım açıklayalım:

### 1. **Statik Semantik Kuralları**

Statik semantik kuralları, programın yapısal doğruluğunun yanı sıra bazı anlam kurallarını da içerir. Sözdizimsel doğruluk, dilin kurallarına uygun bir yapıya sahip olup olmadığını ifade ederken, statik semantik mantıksal doğruluğu garanti eder. Bu kurallar genellikle şunları içerir:

- **Tip Kısıtlamaları**: Bir programdaki değişkenlerin ve ifadelerin belirli bir tipte olması gerektiği kurallarını belirtir. Örneğin, bir tamsayı (`int`) değişkenine bir kayan noktalı sayı (`float`) atanması, tip uyumsuzluğu nedeniyle statik semantik kurallarını ihlal eder.
    
    **Örnek**:
    
    ```java
    int x = 5;
    float y = 4.5f;
    x = y;  // Statik semantik hatası: float int'e atanamaz.
    ```
    
- **Değişkenlerin Bildirimi**: Bir değişkene atama yapılmadan önce o değişkenin tanımlanmış olması gerektiği kuralı. Örneğin, bir değişken kullanılmadan önce tanımlanmadıysa, bu bir statik semantik hatasıdır.
    
    **Örnek**:
    
    ```python
    print(x)  # Statik semantik hatası: 'x' tanımlanmamış.
    ```
    
- **Tip Uygunluğu**: Bir programda, belirli operatörler belirli tipler üzerinde çalışır. Örneğin, iki tamsayı (`int`) değeri üzerinde toplama işlemi yapılabilir, ancak bir `int` ve bir `string` üzerinde toplama yapılmaya çalışıldığında bu, statik semantik hatasıdır.
    
    **Örnek**:
    
    ```java
    int a = 5;
    String b = "hello";
    int c = a + b;  // Statik semantik hatası: int ile string toplanamaz.
    ```
    

### 2. **Statik Semantik ve Sözdizim İlişkisi**

Statik semantik kuralları, **anlamsal** gibi görünse de aslında **sözdizim** ile yakından ilgilidir. Bu kurallar, dilin yapısal bir parçası olan **tip kuralları** ve **değişken kullanım kuralları** gibi sabit kurallardır ve çalışma zamanından ziyade **derleme zamanında** kontrol edilebilir. Yani, bir programın derlenmesi sırasında bu kurallara aykırı bir durum varsa, program daha çalıştırılmadan hata verir.

Örneğin, derleyici programı analiz ederken her değişkenin doğru tipte olup olmadığını kontrol eder ve uyumsuzluk bulursa derleme işlemi başarısız olur.

### 3. **BNF ve Statik Semantik**

**BNF** (Backus-Naur Form), bir dilin yapısal kurallarını tanımlamak için kullanılır. Ancak BNF, sadece dilin **sözdizimini** tanımlayabilir; yani dilin ifadelerinin nasıl yazılacağını gösterir. Statik semantik kuralları, BNF ile tam olarak tanımlanamaz. Bu nedenle, statik semantik kurallarını belirtmek için daha güçlü ve esnek mekanizmalara ihtiyaç vardır.

Örneğin, bir dilde tip uyumluluğu gibi kurallar, BNF ile kolayca tanımlanamaz. Bu yüzden, **Özellik Gramerleri** (Attribute Grammars) gibi daha güçlü araçlar, hem sözdizimi hem de statik semantik kuralları tanımlamak için kullanılır.

### 4. **Özellik Gramerleri (Attribute Grammars)**

Özellik gramerleri, bir dilin hem sözdizimini hem de statik anlambilimsel kurallarını formal olarak tanımlamak için kullanılır. BNF'nin eksikliklerini giderir ve dilin tip uyumluluğu gibi mantıksal kurallarını tanımlamak için kullanılır. Özellik gramerleri, programlama dillerinin derlenmesi sırasında statik semantik kurallarının kontrol edilmesine yardımcı olur.

- **Sentezlenmiş Özellikler (Synthesized Attributes)**: Alt düğümlerden üst düğümlere bilgi taşır. Örneğin, bir ifadenin sonucunu hesaplar.
- **Kazanılmış Özellikler (Inherited Attributes)**: Üst düğümlerden alt düğümlere bilgi taşır. Örneğin, bir değişkenin doğru tipte olup olmadığını kontrol eder.

Bu özellikler, bir programın derlenmesi sırasında derleyicinin mantıksal doğruluğu kontrol etmesine olanak tanır.

### Örnek: Tip Uyumluluğu

```
E -> E1 + E2
E.type = E1.type if E1.type == E2.type else error
```

Bu örnekte, `E1` ve `E2` ifadelerinin tipleri eşitse, `E` ifadesinin tipi de aynı olur. Ancak tipler uyumlu değilse, bir statik semantik hatası oluşur.

### 5. **Dinamik Semantik (Dynamic Semantics)**

Dinamik semantik, bir programın **çalışma zamanındaki anlamını** ifade eder. Yani, program çalışırken ifadelerin, komutların ve program birimlerinin nasıl çalıştığını tanımlar. Dinamik semantik, programın çalışma sırasında ne anlama geldiğini tanımlarken, statik semantik programın anlamını **derleme zamanında** kontrol eder.

- **Dinamik Semantik Örneği**: Bir if-else ifadesinin çalışma zamanında hangi koşulun doğru olduğuna bağlı olarak hangi kodun çalıştırılacağını tanımlar.
    
    ```java
    if (x > 0) {
        System.out.println("Pozitif");
    } else {
        System.out.println("Negatif");
    }
    ```
    

Bu durumda, programın hangi çıktı vereceği dinamik semantik ile belirlenir. Çalışma zamanında `x` değişkeninin değeri kontrol edilir ve doğru koşul çalıştırılır.

### 6. **Sonuç**

- **Statik Semantik**, bir dilin tip kuralları ve değişken kullanımı gibi derleme zamanında kontrol edilen kurallarını tanımlar. BNF'nin eksik kaldığı noktalarda, özellik gramerleri gibi daha güçlü araçlar kullanılarak bu kurallar formal hale getirilir.
- **Dinamik Semantik** ise bir programın çalışma zamanındaki davranışını tanımlar ve çalışma sırasında ne anlama geldiğini ortaya koyar.

Bu iki tür semantik, programlama dillerinin hem derleme zamanı hem de çalışma zamanı anlamını kontrol etmeye yardımcı olur ve programın hem anlamsal hem de mantıksal doğruluğunu garanti altına alır.

---

### Özellik Gramerlerinin Tanımı

**Özellik gramerleri** (Attribute Grammars), bir dilin sözdizimini ve statik anlambilimini formal olarak tanımlayan güçlü bir araçtır. Bu gramerler, her dilbilgisel sembol için bir özellikler kümesi (attributes) tanımlar ve bu özellikler sembollerin mantıksal ilişkilerini belirlemek için kullanılır. Özellik gramerleri, bir dilin derlenmesi sırasında, hem sözdizimsel doğruluğu hem de anlamsal kuralların kontrolünü sağlar.

### 1. **Her Gramer Sembolünün Özellikler Kümesi**

Her bir dildeki gramer sembolü, bir **özellikler kümesi** ile ilişkilendirilir. Bu özellikler sembolün anlamını ve diğer sembollerle olan ilişkisini belirler. Bu özellik kümesi, ikiye ayrılır:

- **Synthesized Attributes (Sentezlenmiş Özellikler - S(X))**: Bu özellikler, **ağacın alt düğümlerinden üst düğümlere doğru** hesaplanır. Bir sembolün alt elemanlarından alınan bilgilerle hesaplanır ve üst düğüme aktarılır. Örneğin, bir ifadenin sonucunu hesaplayan bir sentezlenmiş özellik olabilir.
- **Inherited Attributes (Kazanılmış Özellikler - I(X))**: Bu özellikler, **ağacın üst düğümünden alt düğümlere doğru** veya **aynı seviyedeki düğümler arasında** geçiş yapar. Bir düğümün anlamı, ebeveyn düğümünden veya kardeş düğümlerden gelen bilgilere bağlı olabilir. Örneğin, bir değişkenin tipinin ne olacağına karar veren kazanılmış bir özellik olabilir.

### 2. **Dilbilgisi Kuralları ve Semantik Fonksiyonlar**

Bir dilbilgisi kuralı, o kuraldaki semboller arasındaki ilişkileri ve özellikleri tanımlar. Özellik gramerleri bu ilişkileri tanımlamak için **semantik fonksiyonlar** kullanır.

- **Sentezlenmiş Özellikler (S(X))**: Alt düğümlerden gelen bilgilerin bir fonksiyonu olarak hesaplanır. Yani, bir düğümün sentezlenmiş özellik değeri, o düğümün altındaki diğer düğümlerin özelliklerine bağlıdır.
    
    Örnek:
    
    ```
    S(X0) = f(A(X1), A(X2), ..., A(Xn))
    ```
    
    Burada, `X0` düğümünün sentezlenmiş özelliği, alt düğümler olan `X1`, `X2`, ..., `Xn`'in özelliklerine bağlı olarak hesaplanır.
    
- **Kazanılmış Özellikler (I(X))**: Ebeveyn düğümlerden veya kardeş düğümlerden gelen bilgiler ile hesaplanır. Bir düğümün kazanılmış özellik değeri, o düğümün ebeveyn veya kardeş düğümlerine bağlıdır.
    
    Örnek:
    
    ```
    I(Xj) = f(A(X0), A(X1), ..., A(Xn))
    ```
    
    Burada `Xj` düğümünün kazanılmış özelliği, üst düğüm (`X0`) ve kardeş düğümler (`X1`, `Xn`) ile ilişkili olabilir.
    

### 3. **Önbiçimleme Fonksiyonları (Preconditioning Functions)**

Özellik gramerleri ayrıca **önbiçimleme fonksiyonları** (preconditioning functions) kullanarak, dilin kurallarını ve kısıtlamalarını tanımlar. Önbiçimleme fonksiyonları, bir sembolün özellik değerlerinin geçerli olup olmadığını belirleyen **Boole ifadeleri** içerir.

- **Doğru Önbiçimleme**: Bir dilin türetmeleri (doğru cümleleri) sadece önbiçimleme fonksiyonlarının doğru olduğu durumlarda geçerli olur. Bu, programın anlambilimsel olarak da doğru olduğunu ifade eder.
- **Yanlış Önbiçimleme**: Eğer bir önbiçimleme fonksiyonu yanlış ise, bu durum dilin **sözdizimi** veya **statik anlam kurallarının** ihlal edildiğini gösterir. Örneğin, bir değişkenin doğru tipte olmaması ya da yanlış bir operatör kullanılması gibi hatalar bu şekilde yakalanır.

### 4. **Tam Atıflı (Fully Attributed) Ayrıştırma Ağacı**

Bir ayrıştırma ağacındaki tüm özellik değerlerinin hesaplanıp tamamlandığı duruma **tam atıflı (fully attributed)** denir. Bu durumda, programın hem sözdizimi hem de statik semantik kuralları tamamen doğru bir şekilde değerlendirilmiş ve doğrulanmıştır.

Özellik gramerleri, derleyici tarafından programın doğruluğunu test etmek için kullanılır. Eğer tüm özellik değerleri hesaplanabilirse, programın hem sözdizimsel hem de statik anlambilimsel kurallarına uygun olduğu kabul edilir.

### 5. **Örnek: Özellik Gramerleri ile Tip Kontrolü**

Bir dildeki ifadelerin doğru tiplerde olup olmadığını kontrol eden bir özellik grameri düşünelim. Aşağıdaki örnekte, iki ifadenin toplama işlemi sonucunda aynı tipte olup olmadığını kontrol eden bir gramer yer alır:

```
E -> E1 + E2
S(E) = if S(E1) == S(E2) then S(E1) else type_error
```

- `E1` ve `E2` ifadelerinin tipleri kontrol edilir.
- Eğer her iki ifadenin tipi aynıysa, `E` ifadesinin tipi de aynı olur. Ancak, tipler uyuşmazsa `type_error` ile bir hata fırlatılır.

Bu tür bir özellik grameri, derleme zamanında **tip uyumluluğunu** kontrol eder ve programın mantıksal olarak doğru olup olmadığını belirler.

### Sonuç

Özellik gramerleri, dilin hem sözdizimsel hem de statik anlambilimsel kurallarını formal olarak tanımlamak için güçlü bir araçtır. Bu gramerler, derleme sürecinde dil kurallarını kontrol eder ve hataların derleme zamanında yakalanmasına olanak tanır. **Sentezlenmiş** ve **kazanılmış** özellikler ile, programın farklı parçalarının birbirleriyle nasıl ilişkili olduğunu ve bu ilişkilerin nasıl değerlendirileceğini anlamamızı sağlar.

---

### İçsel (Intrinsic) Özellikler

**İçsel özellikler** (Intrinsic Attributes), bir dildeki ayrıştırma ağacının yaprak düğümlerinde bulunan ve **ağaç dışında** belirlenen özelliklerdir. Bu özellikler, genellikle **sentezlenmiş** (synthesized) özelliklerdir, çünkü bu yaprak düğümlerine dış kaynaklardan gelen bilgilerle atanırlar. İçsel özellikler, derleme sırasında dilin doğru şekilde anlaşılması ve işlenmesi için önemli bir rol oynar.

### 1. **İçsel Özelliklerin Tanımı**

İçsel özellikler, bir programın yapısal ve semantik doğruluğunun kontrol edilmesinde kullanılır. Ayrıştırma ağacının yaprak düğümleri, genellikle programın temel yapı taşlarını temsil eder ve bu düğümlere atanan içsel özellikler, dilin anlamını doğru şekilde belirlemeye yardımcı olur.

Örneğin:

- Bir **değişkenin tipi**, dilin sembol tablosundan elde edilir ve bu tip bilgisi, değişkenin kullanıldığı her yerde kontrol edilmek üzere yaprak düğümüne atanır.
- **Sabit değerler** veya **sabit türler** de içsel özellikler olarak ele alınır. Sabit bir sayı ya da metin, derleme sürecinde ayrıştırma ağacının yaprak düğümünde belirli bir anlama sahiptir.

### 2. **Başlangıç Durumu: Özelliklendirilmemiş Ayrıştırma Ağacı**

Başlangıçta, bir **özelliklendirilmemiş ayrıştırma ağacı** (unattributed parse tree) oluşturulur. Bu ağaç, dilin sözdizimini temsil eder, ancak henüz anlam açısından herhangi bir doğrulama yapılmamıştır. Ayrıştırma ağacı oluşturulduğunda:

- **İçsel özellikler**: Yaprak düğümlerde değerleri atanmış olan tek özelliklerdir. Diğer düğümler (dahili düğümler) henüz özelliklere sahip değildir.

Örneğin, bir programda bir sabit değer olan `5` ifadesinin bulunduğu bir yaprak düğüm düşünelim. Bu düğüm, içsel bir özellik olarak bu sabit değerin **tam sayı** olduğunu belirtir. Ancak, daha büyük ifadelerin anlamını belirlemek için diğer düğümlerin özelliklerinin de hesaplanması gerekir.

### 3. **İçsel Özelliklerin Kullanımı ve Hesaplanması**

Ayrıştırma ağacındaki içsel özellikler verildikten sonra, geri kalan düğümlerin özellik değerlerini hesaplamak için **anlamsal fonksiyonlar** kullanılır. Bu süreç, yaprak düğümlerinden başlayarak ağacın üst düğümlerine doğru ilerler ve tüm düğümlerin anlamlarının hesaplanmasını sağlar.

- **Yaprak Düğümler**: İçsel özelliklere sahip olan yaprak düğümler, dilin temel elemanlarını tanımlar. Bu düğümlerden başlayarak üst düğümlerin özellikleri hesaplanır.
- **Anlamsal İşlevler**: Ayrıştırma ağacının her katmanında, düğümlerin özellikleri, alt düğümlerden alınan bilgilere dayalı olarak hesaplanır.

Örneğin, bir değişkenin tipi sembol tablosundan elde ediliyorsa (içsel özellik), bu bilgi daha sonra o değişkenle ilgili ifadelerde kullanılabilir. Böylece, değişkenin doğru tipte olup olmadığı gibi kontroller yapılabilir.

### 4. **Örnek: Değişken Tiplerinin Belirlenmesi**

Bir programda değişken tiplerini içsel özellikler olarak ele alalım. Semboller (değişkenler) bir sembol tablosunda saklanır ve her bir sembolün tipi bu tabloya bağlıdır. Örneğin, aşağıdaki durumdaki gibi:

```
int x;   // 'x' adlı değişkenin tipi içsel bir özellik olarak 'int'
x = 5;   // 'x' adlı değişkene bir tam sayı atanması, tip uyumluluğu kontrol edilir.
```

- Burada, `x` değişkeni için sembol tablosundan gelen **içsel bir özellik** olan `int` tipi belirlenmiştir.
- Bu bilgi, programın geri kalanında `x` değişkeni ile yapılan işlemlerin geçerliliğini kontrol etmek için kullanılır.

### 5. **İçsel Özelliklerin Anlamı**

İçsel özellikler, ayrıştırma ağacının kökünden yapraklarına kadar olan bir süreçte, dilin statik anlam kurallarının (statik semantik) değerlendirilmesini sağlar. **Derleme zamanında** bu içsel özellikler kullanılarak, programın anlamsal doğruluğu kontrol edilir. Özellikle dildeki **tip kontrolü**, **değişken bildirimleri** ve **sabitler** gibi özellikler bu kategoriye girer.

Özetle, **içsel özellikler**, ayrıştırma ağacının yaprak düğümlerinde bulunan ve dilin derlenmesi sürecinde anlamın doğru bir şekilde belirlenmesini sağlayan özelliklerdir. Yaprak düğümlere ait bu içsel bilgiler, daha büyük yapılar için anlamlı ifadeler oluşturmak amacıyla kullanılır.

---

### Özellik Gramerleri Örnek-1: Ada Dilinde Prosedür İfadesi

Bu örnekte, **Ada programlama dili**ndeki bir prosedür tanımı ele alınmaktadır. Ada dilinde, bir prosedürün sonundaki **`end`** ifadesinden sonra **prosedür isminin** tekrar yazılması gereklidir. Bu kural, derleyici tarafından kontrol edilmeli ve eğer yanlış yazılmışsa hata vermelidir. Bu senaryoyu **özellik gramerleri** kullanarak formal bir şekilde nasıl tanımlayabileceğimize bakalım.

### 1. **Sözdizim Kuralı (Syntax Rule)**

Özellik grameri ile prosedür tanımının nasıl ifade edileceğine dikkat edin. Sözdizim kuralı şu şekildedir:

```
<proc_def> -> procedure <proc_name> [1]
              <proc_body> end <proc_name> [2] ;
```

Bu kuralda, `<proc_def>` sembolü bir prosedür tanımını temsil eder. Tanımın içeriği şu şekildedir:

- **Başlangıçta**: `procedure` anahtar kelimesi ile başlar.
- **Prosedür Adı**: İlk `<proc_name> [1]` ile belirtilir, bu prosedürün adı olacaktır.
- **Prosedür Gövdesi**: `<proc_body>` ile temsil edilir, prosedürün asıl işlevlerini içerir.
- **Sonlandırma**: `end` anahtar kelimesi ile prosedür sonlanır, ardından **prosedür adı** tekrar yazılır (`<proc_name> [2]`).

Bu dil kuralında, önemli olan kısım, prosedürün sonundaki **`end`** ifadesinden sonra doğru prosedür adının kullanılmasıdır. İşte bu noktada, özellik grameri devreye girer.

### 2. **Predicate (Doğrulama Kuralı)**

Sadece sözdizim kuralını tanımlamak yeterli değildir, çünkü burada kontrol etmemiz gereken ek bir kural daha var: Prosedürün sonundaki `end` ifadesinden sonra yazılan adın, prosedürün başında belirtilen ad ile aynı olması gerekir. Bunu kontrol etmek için bir **predicate** (doğrulama kuralı) eklenir:

```
Predicate: <proc_name> [1].string == <proc_name> [2].string
```

Bu predicate ifadesi, prosedürün başında (`<proc_name> [1]`) ve sonunda (`<proc_name> [2]`) kullanılan isimlerin aynı olup olmadığını kontrol eder. Eğer bu iki isim aynı ise, program doğru kabul edilir. Eğer farklı ise, derleyici bir hata verecektir.

### 3. **Özellik Grameri ile İlgili Açıklamalar**

- **<proc_name> [1]** ve **<proc_name> [2]** nonterminal sembollerdir ve prosedür adını temsil ederler.
- Bu sembollere atanan bir **string** (karakter dizisi) özelliği vardır, bu özellik prosedür adını içerir. Yani, `string` özelliği bu nonterminal sembollere atanan **sentezlenmiş** (synthesized) bir özelliktir.
- **Predicate**: Burada iki `string` özelliğini karşılaştırarak, prosedür isminin doğru yazılıp yazılmadığını kontrol ederiz. Eğer iki isim eşit değilse, program sözdizimsel olarak hatalıdır.

### 4. **Özelliklerin Ayrıştırılması**

Bu özellik gramerinde, iki farklı `<proc_name>` nonterminal sembolü bulunmaktadır:

- `<proc_name> [1]`: Prosedürün başındaki ad.
- `<proc_name> [2]`: Prosedürün sonundaki ad.

Her iki sembol de **aynı dilsel anlamı** taşıyor olmasına rağmen, gramerde **farklı nonterminal semboller** olarak kullanılırlar, çünkü farklı konumlarda yer alırlar (başlangıç ve bitiş). Özellik grameri bu iki sembolü ayırarak her birinin doğruluğunu ayrı ayrı kontrol etmemize olanak sağlar.

### 5. **Örnek Prosedür Tanımı**

Bir Ada prosedürünün tanımına bakalım:

```
procedure Calculate is
begin
   -- prosedürün gövdesi
end Calculate;
```

Bu örnekte:

- Prosedür adı **`Calculate`**.
- `procedure` ifadesinden sonra **`Calculate`** yazılmış.
- Prosedür `end` ifadesi ile sonlanıyor ve `end` ifadesinin ardından **`Calculate`** prosedür ismi tekrar yazılmış.

Bu prosedür doğru yazılmıştır, çünkü baştaki ve sondaki prosedür isimleri aynıdır. Eğer sonunda **`end Calculate`** yerine **`end SomethingElse`** yazılmış olsaydı, derleyici bir hata verecekti. İşte bu hata kontrolü, özellik grameri ve predicate yardımıyla yapılır.

### Sonuç

Bu örnekte, **özellik grameri** kullanarak bir programlama dilinin sözdizimsel ve statik anlambilimsel kurallarını nasıl formal olarak tanımlayabileceğimizi gördük. Özellikle, **Ada dili**ndeki prosedür tanımında, prosedür isminin başlangıçta ve sonda aynı olması gerekliliği, bir **predicate** yardımıyla kontrol edilir. **Sentezlenmiş özellikler** ve **predicate** kuralları, programın doğruluğunu derleme zamanında sağlamaya yardımcı olur.

---

### Özellik Gramerleri Örnek-2: Basit Bir Atama İfadesi için Tip Kuralları

Bu örnekte, bir atama ifadesinin hem sözdizimsel hem de **statik anlambilimsel** (statik semantik) kurallarını nasıl özellik gramerleri ile tanımlayacağımızı inceleyeceğiz. Atama ifadelerinde, değişkenlerin **tip uyumu** ve **ifadenin tipi** derleme zamanında kontrol edilmelidir. Aşağıda özellik grameriyle bu kontrollerin nasıl yapıldığı gösterilecektir.

### 1. **Sözdizim Kuralı (Syntax Rule)**

Atama işlemi için verilen basit sözdizim kuralları şu şekildedir:

```
<assign> -> <var> = <expr>
<expr>   -> <var> + <var>
          |  <var>
<var>    -> A | B | C
```

Bu kurallar şu anlamlara gelir:

- **`<assign>`**: Bir atama ifadesini temsil eder ve sağında bir değişkenin (`<var>`) bir ifadeye (`<expr>`) eşitlenmesini gösterir.
- **`<expr>`**: Bir ifade olabilir. Ya tek bir değişkenden (`<var>`) oluşur ya da iki değişkenin toplanmasıyla (`<var> + <var>`) bir araya gelir.
- **`<var>`**: Üç değişken (`A`, `B`, `C`) olabilir. Yani, yalnızca bu üç değişken kullanılır.

### 2. **Tip Kuralları (Type Rules)**

Bu ifadelerde yer alan değişkenler iki tipten biri olabilir:

- **`int` (tamsayı)**
- **`real` (ondalıklı sayı)**

**Atama ifadesinde** dikkat edilmesi gereken kurallar:

- **Sağ tarafta** (right side), değişkenler ya aynı tipte ya da farklı tiplerde olabilir.
- Eğer sağ taraftaki iki değişkenin tipleri farklı ise, ifadenin tipi her zaman **`real`** olur.
- Eğer sağ taraftaki iki değişkenin tipleri aynı ise, ifadenin tipi bu değişkenlerin tipine eşit olur.
- **Sol tarafta** (left side), atanan değişkenin tipi, sağdaki ifadenin tipiyle **aynı olmalıdır**. Tipler uyuşmazsa, atama geçerli değildir.

### 3. **Özellik Gramerleri ile Tip Kontrolü**

Tip kontrollerini özellik gramerleri ile nasıl yapabileceğimizi görelim. Her değişken için bir **`type`** (tip) özelliği tanımlayacağız. Bu özellik, her değişkenin tipi hakkında bilgi içerir. Ayrıca, ifadelerin tipini hesaplamak için **sentezlenmiş özellikler** kullanacağız.

### 3.1 **Sentezlenmiş Özellikler**

Sentezlenmiş özellikler, ağaçtaki alt düğümlerden yukarıya doğru hesaplanır. Burada `expr` ve `assign` kuralları için gerekli olan sentezlenmiş tip özellikleri şunlardır:

- **`<var>.type`**: Değişkenin tipi. A, B ve C gibi değişkenler için bu tip bilgisi dış kaynaklardan, örneğin sembol tablosundan gelir.
- **`<expr>.type`**: Bir ifadenin tipi. Bu, ifadeyi oluşturan değişkenlerin tiplerine bağlı olarak hesaplanır.

### 3.2 **Kural 1: Değişken Tipleri**

Her değişkenin bir tipi olmalıdır. Sembol tablosundan gelen bilgilere göre, `A`, `B` ve `C` değişkenleri için tipler tanımlanır:

```
<var> -> A  { A.type = int }
<var> -> B  { B.type = real }
<var> -> C  { C.type = int }
```

Bu kuralda, `A` değişkeninin tipi `int`, `B` değişkeninin tipi `real` ve `C` değişkeninin tipi `int` olarak belirlenmiştir.

### 3.3 **Kural 2: İfade Tiplerinin Hesaplanması**

Bir ifade ya tek bir değişkenden ya da iki değişkenin toplanmasıyla oluşabilir. İfadenin tipi, değişkenlerin tiplerine göre hesaplanır:

```
<expr> -> <var> + <var>  {
    if (<var>[1].type == <var>[2].type) {
        <expr>.type = <var>[1].type;
    } else {
        <expr>.type = real;
    }
}
```

Bu kural şu şekilde işler:

- Eğer iki değişkenin tipleri aynı ise (`<var>[1].type == <var>[2].type`), ifadenin tipi bu değişkenlerin tipine eşit olur.
- Eğer tipler farklı ise, ifadenin tipi **`real`** olur. Örneğin, bir `int` ve bir `real` toplandığında sonuç `real` tipinde olacaktır.

Ayrıca tek değişkenli ifadeler için kural:

```
<expr> -> <var> {
    <expr>.type = <var>.type;
}
```

Bu kural, eğer ifade tek bir değişkenden oluşuyorsa, ifadenin tipi doğrudan bu değişkenin tipi olur.

### 3.4 **Kural 3: Atama İfadesi Tip Kontrolü**

Atama ifadesinde, sol taraftaki değişkenin tipi, sağ taraftaki ifadenin tipiyle eşleşmelidir:

```
<assign> -> <var> = <expr> {
    if (<var>.type == <expr>.type) {
        // Atama geçerlidir
    } else {
        // Tip uyuşmazlığı hatası
    }
}
```

Bu kuralda, `<var>` değişkeninin tipi ile `<expr>` ifadesinin tipi karşılaştırılır. Eğer tipler eşleşirse, atama işlemi geçerlidir. Eğer tipler uyuşmazsa, bir hata oluşur.

### 4. **Örnek**

Aşağıda bir örnek ile tip kontrolünün nasıl çalıştığını inceleyelim:

```
A = B + C
```

Bu örnekte:

- **`A`** tipi `int`'dir.
- **`B`** tipi `real`, **`C`** tipi ise `int`'dir.

Tip kontrol süreci:

1. **`B + C`** ifadesi:
    - `B` tipi `real`, `C` tipi `int` olduğu için ifadenin tipi `real` olacaktır.
2. **Atama kontrolü**:
    - Sol taraftaki `A` tipi `int`'dir, ancak sağ taraftaki ifade tipi `real`'dir.
    - Tipler uyuşmadığı için derleyici bir **tip uyuşmazlığı hatası** verecektir.

Başka bir örnek:

```
C = A + C
```

Bu durumda:

- **`A`** ve **`C`** ikisi de `int` tipinde olduğundan, `A + C` ifadesinin tipi `int` olacaktır.
- Sol taraftaki `C` de `int` tipindedir, bu yüzden tipler eşleşir ve atama geçerli kabul edilir.

### Sonuç

Bu örnek, **özellik gramerleri** kullanarak bir dilde **tip kurallarının** nasıl kontrol edilebileceğini göstermektedir. Sentezlenmiş tip özellikleri ve bu özelliklere dayalı predicate kuralları, değişkenlerin ve ifadelerin tiplerinin doğru şekilde kontrol edilmesine olanak tanır. Özellikle **atama ifadelerinde** sol ve sağ tarafların tiplerinin eşleşip eşleşmediği derleme zamanında kontrol edilerek programın anlamsal doğruluğu sağlanır.

---

### Özellik Gramerleri Örnek-2: Tip Denetimi için Özelliklerin Tanımı

Bu örnekte, **özellik gramerleri** kullanılarak basit bir atama ifadesinin tip kurallarının nasıl kontrol edildiğini inceleyeceğiz. Özellik gramerlerinde, her nonterminal sembolü bir veya daha fazla **özellik** ile ilişkilendirilir. Burada iki önemli özellik tanımlanır: **`actual_type`** ve **`expected_type`**.

### 1. **`actual_type` (Gerçek Tip)**

- **`actual_type`**, **sentezlenmiş bir özellik** (synthesized attribute) olup, `var` ve `<expr>` nonterminalleriyle ilişkilendirilir.
- Bu özellik, bir değişkenin veya ifadenin **gerçek tipini** (`int` veya `real`) saklar.
    - **Değişkenler** için bu özellik **içseldir (intrinsic)** ve doğrudan sembol tablosundan alınır.
    - **İfadeler** için ise, ifadenin **alt düğümleri** olan değişkenlerin veya ifadelerin tiplerine bağlı olarak hesaplanır.

### Örnek:

- `A` değişkeninin **`actual_type`** özelliği `int` olacaktır.
- `B + C` ifadesinin **`actual_type`** özelliği, `B` ve `C`'nin tiplerine göre hesaplanır. Eğer `B` `real`, `C` ise `int` ise, ifadenin tipi her zaman `real` olur (farklı tiplerde olduğunda sonuç her zaman `real`'dir).

### 2. **`expected_type` (Beklenen Tip)**

- **`expected_type`**, **miras alınmış bir özellik** (inherited attribute) olup, `expr` nonterminaliyle ilişkilendirilir.
- Bu özellik, bir atama ifadesinin sol tarafındaki değişkenin tipine göre sağdaki ifadenin hangi tipte olmasının beklendiğini saklar.
- **`expected_type`**, atama ifadesinin sağ tarafındaki ifadenin sol taraftaki değişkenin tipiyle uyumlu olmasını sağlamak için kullanılır.

### Örnek:

- Eğer atama ifadesi `C = B + A` şeklinde ise, `C`'nin tipi `int` olduğundan sağdaki ifadenin de `int` tipinde olması **beklenir** (`expected_type = int`).
- Ancak, `B + A` ifadesi `real` tipinde olursa, bu durumda bir tip uyuşmazlığı meydana gelir.

### Kurallar

### 1. **Değişkenler için `actual_type` Özelliği**

Değişkenlerin tipleri sembol tablosundan alınır ve her değişkenin **`actual_type`** özelliği tanımlanır.

```
<var> -> A  { <var>.actual_type = int }
<var> -> B  { <var>.actual_type = real }
<var> -> C  { <var>.actual_type = int }
```

Bu kural, `A`, `B`, `C` değişkenlerinin tiplerinin **`actual_type`** özelliği ile nasıl belirlendiğini gösterir.

### 2. **İfadeler için `actual_type` Hesaplaması**

İfadelerde tip, alt düğümlerdeki değişkenlerin tiplerine göre hesaplanır. İki değişkenin toplandığı bir ifade için `actual_type` şu şekilde hesaplanır:

```
<expr> -> <var> + <var> {
    if (<var>[1].actual_type == <var>[2].actual_type) {
        <expr>.actual_type = <var>[1].actual_type;
    } else {
        <expr>.actual_type = real;
    }
}
```

Bu kurala göre:

- Eğer iki değişkenin tipi aynıysa, ifadenin tipi de aynı olur.
- Eğer tipler farklıysa, ifadenin tipi `real` olur.

Tek değişkenli ifadeler için:

```
<expr> -> <var> {
    <expr>.actual_type = <var>.actual_type;
}
```

Bu kural, tek değişkenli ifadelerde ifadenin tipini doğrudan değişkenin tipi olarak belirler.

### 3. **Atama İfadesi için `expected_type` ve `actual_type` Uyum Kontrolü**

Atama ifadesinde, sol taraftaki değişkenin tipi sağ taraftaki ifadenin tipiyle uyumlu olmalıdır. Bu uyumu kontrol etmek için `expected_type` ve `actual_type` özellikleri karşılaştırılır:

```
<assign> -> <var> = <expr> {
    <expr>.expected_type = <var>.actual_type;
    if (<expr>.actual_type == <expr>.expected_type) {
        // Atama geçerli
    } else {
        // Tip uyuşmazlığı hatası
    }
}
```

Bu kurala göre:

- Sol taraftaki değişkenin tipi `expected_type` olarak sağdaki ifadeye aktarılır.
- Sağdaki ifadenin **`actual_type`** özelliği ile **`expected_type`** karşılaştırılır. Eğer tipler uyuşuyorsa atama geçerli olur, aksi takdirde bir tip uyuşmazlığı hatası meydana gelir.

### Örnek Senaryo

Bir atama ifadesi olan `A = B + C` üzerinde bu kuralları uygulayalım:

1. **Değişken Tipleri:**
    - `A.actual_type = int`
    - `B.actual_type = real`
    - `C.actual_type = int`
2. **İfade Tipi:**
    - `B + C` ifadesi, `real` ve `int` tiplerine sahip değişkenlerden oluşur. Farklı tiplerde oldukları için, ifadenin **`actual_type`** değeri `real` olur.
3. **Atama Uyum Kontrolü:**
    - `A` değişkeninin **`actual_type`** değeri `int` olduğundan, `A = B + C` atamasında, sağdaki ifadenin **`expected_type`** değeri `int` olur.
    - Ancak, `B + C` ifadesinin **`actual_type`** değeri `real` olduğu için bir **tip uyuşmazlığı** hatası meydana gelir.

### Sonuç

Bu özellik grameri örneğinde, **sentezlenmiş** ve **miras alınmış** özellikler kullanılarak atama ifadelerinin tip uyumu kontrol edilir. **`actual_type`** özelliği, bir değişkenin veya ifadenin gerçek tipini saklarken, **`expected_type`** özelliği, atamanın sol tarafındaki değişkene bağlı olarak sağ tarafta beklenen tipi saklar. Bu kurallar sayesinde, derleme aşamasında tip hataları tespit edilebilir ve düzeltilebilir.

---

# 13. sayfa ya kadar….

### Özellik Değerlerinin Hesaplanması

Özellik gramerlerinde, ayrıştırma ağacındaki (parse tree) **özellik değerlerinin hesaplanması** sürecine "ağacın süslenmesi" (decorating the parse tree) denir. Özellikler **miras alınmış** (inherited) ve **sentezlenmiş** (synthesized) olabilir. Bu süreç, ağacın yapısına ve özellik türlerine bağlı olarak farklı şekillerde gerçekleşir.

### 1. **Miras Alınmış Özellikler (`Inherited Attributes`)**

Miras alınmış özellikler, bir düğümün özelliklerinin **üst düğümden** veya **yan düğümlerden** miras olarak gelmesini ifade eder. Bu özellikler, ayrıştırma ağacında **yukarıdan aşağıya** (top-down) doğru hesaplanır, yani:

- **Kök düğümden** (root) başlayarak, **yaprak düğümlere** kadar özellikler aktarılır.
- Bir nonterminal sembol, kendi babası veya kardeşlerinden özellik alarak hesaplamalarını yapar.

### Örnek:

Eğer bir atama ifadesinde `C = B + A` varsa, `expected_type` özelliği `C` değişkeninin tipine bağlıdır. Bu durumda `C`'nin tipi önce hesaplanır, ardından `B + A` ifadesine bu bilgi miras alınır.

### 2. **Sentezlenmiş Özellikler (`Synthesized Attributes`)**

Sentezlenmiş özellikler, bir düğümün özelliklerinin **alt düğümlerden** gelmesini ifade eder. Bu özellikler, ayrıştırma ağacında **aşağıdan yukarıya** (bottom-up) doğru hesaplanır, yani:

- **Yaprak düğümlerden** başlayarak, **kök düğüme** kadar özellikler hesaplanır.
- Alt düğümlerin değerleri kullanılarak üst düğümlerin özellikleri hesaplanır.

### Örnek:

Bir `B + A` ifadesinde, `B` ve `A` değişkenlerinin tipleri önce hesaplanır ve bu tipler kullanılarak ifadenin `actual_type` değeri hesaplanır. Eğer `B` `real`, `A` ise `int` tipindeyse, ifadenin `actual_type` değeri `real` olacaktır.

### 3. **Her İki Özelliğin Kullanımı**

Özellik gramerlerinde hem **miras alınmış** hem de **sentezlenmiş** özellikler kullanılabilir. Bu durumda, özelliklerin hesaplanması **tek bir yönde** yapılamaz, çünkü:

- Miras alınmış özellikler yukarıdan aşağıya hesaplanırken,
- Sentezlenmiş özellikler aşağıdan yukarıya hesaplanır.

Dolayısıyla, bu tür gramerlerde özelliklerin hesaplanması **iki yönlü** bir süreç gerektirir. Özellik değerleri, ağacın yukarı ve aşağı yönlerinde birbirini etkileyebilir ve bu yüzden her iki yönlü hesaplama yapılmalıdır.

### Özelliklerin Hesaplanmasına İlişkin Senaryo

Örneğin, bir atama ifadesi olan `A = B + C` ifadesini ele alalım:

1. **Aşama: Miras Alınmış Özelliklerin Hesaplanması**
    - İlk olarak, sol taraftaki `A` değişkeninin **`expected_type`** özelliği hesaplanır ve bu bilgi sağdaki `B + C` ifadesine aktarılır.
    - Bu, yukarıdan aşağıya doğru bir süreçtir: `expected_type` kökten yaprak düğümlere doğru miras alınır.
2. **Aşama: Sentezlenmiş Özelliklerin Hesaplanması**
    - `B` ve `C` değişkenlerinin **`actual_type`** değerleri hesaplanır (örneğin, `B` `real`, `C` `int`).
    - Bu tipler kullanılarak `B + C` ifadesinin **`actual_type`** değeri `real` olarak hesaplanır.
    - Bu süreç aşağıdan yukarıya doğru ilerler: yaprak düğümlerden kök düğüme doğru.
3. **Aşama: Uyum Kontrolü**
    - Son aşamada, sağdaki ifadenin **`actual_type`** değeri ile sol taraftaki değişkenin **`expected_type`** değeri karşılaştırılır.
    - Eğer bu tipler uyumluysa, atama geçerli olur. Aksi takdirde, bir tip uyuşmazlığı hatası meydana gelir.

### Sonuç

Özellik gramerlerinde, **miras alınmış** ve **sentezlenmiş** özellikler birlikte kullanıldığında, özelliklerin hesaplanması hem yukarıdan aşağıya hem de aşağıdan yukarıya doğru gerçekleşir. Bu iki yönlü hesaplama, dilin sözdizimi ve statik anlam kurallarının doğru bir şekilde değerlendirilmesini sağlar.

---

### Statik Anlam Kurallarının Değerlendirilmesi

i are engineer örneği

### 1. **Statik Anlam Kurallarının Önemi**

Statik anlam kuralları, bir programın derleme aşamasında kontrol edilmesi gereken kuralları tanımlar. Derleyici bu kuralları kullanarak, programın yazım hataları veya dil kurallarına aykırı işlemler içerip içermediğini belirler. Örneğin, bir değişkenin tipiyle uyumsuz bir değerin atanması gibi durumlar, bu statik anlam kuralları yardımıyla tespit edilebilir. Bu süreç derleyicinin **sözdizimsel** ve **anlamsal** doğrulama işlevlerinin temelini oluşturur.

### 2. **Özellik Gramerlerinin Kullanımı**

Özellik gramerleri, statik anlam kurallarının formel olarak tanımlanması ve uygulanması için geliştirilmiş güçlü bir araçtır. **Sentezlenmiş** ve **miras alınmış** özelliklerin kullanımıyla, dilin sözdizimsel yapısına uygun kuralların kontrolü sağlanır. Ancak, bir derleyici yazarı özellik gramerlerini bilmese bile, statik anlam kurallarını manuel olarak kendi sisteminde tanımlamak zorunda kalır. Bu, özellik gramerlerinin ne kadar gerekli ve temel olduğunun bir göstergesidir.

### 3. **Modern Programlama Dilleri için Zorluklar**

Modern programlama dillerinin sözdizim ve anlamsal kurallarını tanımlamak oldukça zordur. Bu zorlukların başlıca nedenleri şunlardır:

- **Özellik Gramerlerinin Büyüklüğü ve Karmaşıklığı**: Bir dilin tüm sözdizimsel ve anlamsal kurallarını özellik gramerleri ile tanımlamak büyük bir çaba gerektirir. Özellikle büyük ve karmaşık diller için, bu gramerlerin büyüklüğü artar ve anlaşılması zorlaşır.
- **Kural Sayısının Fazlalığı**: Tam bir programlama dili (PD) için gerekli olan **özellik** ve **anlam kurallarının** çok sayıda olması, bu kuralların hem yazılmasını hem de okunmasını zorlaştırır. Ayrıca, her kuralın doğru ve tutarlı bir şekilde uygulanması da ayrı bir zorluk teşkil eder.
- **Değerlendirme Maliyeti**: Ayrıştırma ağaçlarındaki özelliklerin hesaplanması, özellikle büyük dillerde önemli bir maliyet doğurur. Bu maliyet, dilin karmaşıklığı ve ayrıştırma ağacının büyüklüğüne göre artabilir. Özellik değerlerinin hesaplanması, derleyici tasarımında dikkat edilmesi gereken önemli bir performans sorunudur.

### 4. **Formalizm ve Pratiklik Dengesi**

Özellik gramerleri oldukça formel bir yapıya sahip olmasına rağmen, çoğu derleyici yazarı bu kadar detaylı bir formelliğe ihtiyaç duymaz. Çünkü derleyici yazarları için **önemli olan** derleyiciyi üretme sürecidir, formalizme olan bağlılık değil. Bu yüzden, özellik gramerleri genellikle daha az formel bir şekilde kullanılabilir ve yine de etkili sonuçlar elde edilebilir.

### 5. **Sonuç**

Özellik gramerleri, statik anlam kurallarının formel olarak tanımlanması ve uygulanması için güçlü bir araçtır. Ancak, büyük ve karmaşık diller için özellik gramerlerinin büyüklüğü ve değerlendirme maliyeti zorluklar yaratabilir. Buna rağmen, formalizme ihtiyaç duymadan, derleyici yazarları için özellik gramerleri oldukça kullanışlı ve etkili bir yöntemdir. **Pratik kullanımda**, formalizmin daha basitleştirilmiş ve esnek haliyle derleyicilerde yaygın olarak uygulanabilir.

---