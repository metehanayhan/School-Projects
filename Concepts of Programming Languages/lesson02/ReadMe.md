# 2. Hafta

### Dil Tasarımını Etkileyen Faktörler

Programlama dili tasarımını etkileyen en önemli iki faktör **bilgisayar mimarisi** ve **programlama metodolojileridir**. Bu faktörler, bir dilin nasıl tasarlandığını, hangi amaçlar için uygun olduğunu ve nasıl çalıştırıldığını belirler.

---

### 1. **Bilgisayar Mimarisi**

Bilgisayar mimarisi, programlama dillerinin nasıl çalıştığı ve nasıl tasarlandığı üzerinde büyük bir etkiye sahiptir. En yaygın kullanılan mimari **von Neumann mimarisi**dir.

### **Von Neumann Mimarisi:**

- **1945-1951** yılları arasında John von Neumann tarafından geliştirilen bu mimari, modern bilgisayarların temelini oluşturur.
- **Veri ve komutlar aynı hafızada** tutulur. Yani, hem program kodu hem de işlem yapılacak veriler aynı bellek alanında yer alır.
- Bu mimaride, hafıza organizasyonu kullanıcının kontrolündedir, bu nedenle kullanıcı veri ve komutlar üzerinde serbesttir.
- **Araçlar** (komutlar) ve **hafızadaki veriye** aynı şekilde erişim sağlanır. Bellek, CPU tarafından erişilir ve komutlar bellekte tutulur.

---

### 2. **Bilgisayar Mimarisi ve Programlama Dillerine Etkisi**

### **Zorunlu (Imperative) Diller:**

- Von Neumann mimarisi nedeniyle **zorunlu programlama dilleri** (örneğin, **C**, **C++**, **Java**, **COBOL**) yaygınlaşmıştır.
- **Zorunlu diller**:
    - **Veri ve programları aynı bellekte** saklar.
    - Bellek, CPU’dan ayrıdır. Komutlar ve veri, bellekte tutulur ve **CPU’ya iletilir**.
    - Bu dil türü, **von Neumann mimarisine uygun** olarak gelişmiştir çünkü veri işleme ve bellekten veri aktarma üzerine kuruludur.
    - **Değişkenler** bellekteki hücreleri modeller.
    - **Atama ifadeleri**, verinin aktarımını (piping) ve işlenmesini modeller.
    - **Tekrarlamalar (iteration)** von Neumann bilgisayarlarında oldukça hızlı gerçekleşir, bu nedenle **döngü tabanlı yapı** kullanımı yaygındır.

### **Fonksiyonel (Functional) Diller:**

- Fonksiyonel dillerde **değişkenler**, **atama işlemleri** ve **yinelemeler** (iteration) yoktur. Bu, von Neumann dışı bilgisayar mimarileriyle daha uyumlu olacak şekilde tasarlanmışlardır.
- **Scheme** gibi fonksiyonel diller, bilgisayar bilimcileri tarafından güçlü ve verimli olarak görülse de, von Neumann mimarisi baskın olduğu sürece zorunlu dillerin yerini almaları beklenmemektedir.
- **John Backus** (Fortran’ın ilk versiyonunu tasarlayan kişi) 1978 yılında fonksiyonel dillerin faydalarını savunmuştur, ancak yine de von Neumann mimarisi ile uyumlu olmayan fonksiyonel dillerin performans açısından daha az verimli olduğu görüşü baskın kalmıştır.

---

### 3. **Programlama Metodolojileri**

Dil tasarımını etkileyen bir diğer önemli faktör de **programlama metodolojileridir**. İki yaygın metodoloji şunlardır:

### **1. Yapısal Programlama (Structured Programming):**

- Programların **daha modüler**, **hata yönetimi kolay** ve **anlaşılır** olmasını sağlar.
- Kontrol yapıları, döngüler ve koşullu ifadeler gibi temel yapı taşlarını kullanarak programların düzenli bir yapıya sahip olmasına yardımcı olur.
- **C**, **Pascal** gibi dillerde yaygındır.

### **2. Nesne Yönelimli Programlama (Object-Oriented Programming - OOP):**

- **Nesneler** ve **sınıflar** üzerine kuruludur. Nesne yönelimli programlama, herhangi bir problemi çözmek için **nesneler** arasında etkileşim sağlar. Nesneler, hem **veri** (özellikler) hem de **davranış** (metotlar) içerir.
- **Kapsülleme**, **kalıtım** ve **polimorfizm** gibi temel OOP kavramları ile karmaşık sistemlerin daha modüler ve bakımı kolay hale getirilmesi sağlanır.
- OOP, **Java**, **C++**, **Python** gibi dillerde yaygındır ve büyük yazılım projelerinde verimli çözümler sağlar.

---

### **Bilgisayar Mimarisi ve Programlama Dilleri Arasındaki İlişki**

Bilgisayar mimarisi, özellikle von Neumann mimarisi, programlama dillerinin temel yapılarını etkilemiştir. Zorunlu diller, mimarinin belleğe ve CPU'ya dayalı veri aktarım modeline uygun şekilde tasarlanmıştır. Ancak, programlama dilleri geliştikçe ve bilgisayar bilimcileri yeni yaklaşımlar geliştirdikçe, bu mimariden bağımsız olarak farklı paradigmalarda diller de ortaya çıkmıştır.

### **Von Neumann Mimarisinin Getirdiği Kısıtlamalar:**

- Zorunlu diller, von Neumann mimarisine sıkı sıkıya bağlı olduğundan, **veri işleme** ve **bellek yönetimi** gibi işlemleri manuel olarak yapmak gerekebilir.
- **Fonksiyonel diller** (örneğin, **Haskell**, **Lisp**) gibi diller, değişkenleri ve belleği daha soyut düzeyde yöneterek programcıya daha fazla esneklik sağlar. Ancak bu diller, von Neumann mimarisi üzerinde çalışan makinelerde her zaman optimum performans sunamayabilir.

### **Fonksiyonel Dillerin Potansiyeli:**

- Fonksiyonel programlama dillerinin avantajlarından biri, **yan etkisiz** (stateless) olmalarıdır. Bu, işlemlerin daha tahmin edilebilir ve hataya dayanıklı olmasını sağlar.
- Ancak, **fonksiyonel dillerin** yaygınlaşması, performans açısından daha verimli **von Neumann dışı bilgisayar mimarilerinin** geliştirilmesi ile mümkün olabilir. Şu an için zorunlu diller, mimarinin verimliliği nedeniyle daha popülerdir.

---

### **Dil Tasarımını Etkileyen Diğer Faktörler**

### **1. Taşınabilirlik (Portability):**

Bir dilin taşınabilirliği, farklı platformlarda çalışabilme yeteneğidir. **Dil tasarımı**, bir programın sadece bir bilgisayar veya işletim sisteminde değil, farklı sistemlerde de çalışabilmesini kolaylaştırmalıdır. Bu, özellikle büyük ve karmaşık yazılımlarda önemlidir.

### **2. Genel Geçerlilik (Generality):**

Bir dil, birçok farklı problemi çözebilmek için yeterince **genel amaçlı** olmalıdır. Örneğin, hem bilimsel hesaplamalar hem de web geliştirme için kullanılabilen diller, daha geniş bir alana hitap eder.

### **3. İyi Tanımlanmışlık (Well-Definedness):**

Bir programlama dilinin **iyi tanımlanmış** olması, dilin sözdiziminin ve semantiğinin (anlamının) açık, net ve tutarlı olmasını sağlar. Programcılar dilin nasıl çalışacağını net bir şekilde anlamalıdır, aksi takdirde dilin kullanımı zor ve hataya açık olur.

---

### **Sonuç:**

Bir programlama dilinin tasarımı, bilgisayar mimarisi, programlama metodolojileri, güvenilirlik, taşınabilirlik gibi birçok faktörden etkilenir. **Von Neumann mimarisi**, zorunlu dillerin gelişimini büyük ölçüde etkilemiş ve halen modern bilgisayar sistemlerinde bu mimari yaygın olarak kullanılmaktadır. Ancak, gelecekte **fonksiyonel dillerin** ve **von Neumann dışı** mimarilerin daha popüler hale gelmesi, programlama dünyasında yeni yaklaşımların ortaya çıkmasına yol açabilir.

Programlama dillerinin tasarımı, aynı zamanda belirli bir problemin çözümünde ne kadar etkili ve verimli olduklarıyla da ilişkilidir. **Yapısal programlama**, karmaşık yapıların daha düzenli yönetilmesini sağlarken, **nesne yönelimli programlama**, daha esnek ve modüler çözümler sunar. **Fonksiyonel diller** ise yan etkileri azaltarak daha güvenli programlar yazılmasını sağlar, ancak von Neumann mimarisinde performans sorunlarına yol açabilir.

---

## **Dil Tasarımındaki Getiri-Götürü İlişkileri (Trade-offs in Language Design)**

Programlama dili tasarımında, belirli bir amaca hizmet etmek için çeşitli kriterler göz önüne alınır. Ancak bu kriterler bazen birbirleriyle çelişir, yani bir özelliği iyileştirmek başka bir özelliğin zayıflamasına neden olabilir. Bu dengeyi kurmak, dil tasarımcılarının karşılaştığı en önemli zorluklardan biridir.

### 1. **Programlama Dilleri Değerlendirme Kriterleri Arasındaki Çelişki**

Her programlama dili, farklı önceliklere sahip kriterlerle değerlendirilir. Bu kriterler arasında güvenilirlik, yazılabilirlik, okunabilirlik, verimlilik ve maliyet gibi unsurlar yer alır. Ancak bu kriterlerin bazıları birbiriyle çelişebilir.

Hoare (1973), dil tasarımına dair yazdığı önemli makalesinde, bir dilin tasarımında karşılaşılan çelişen kriterlerin, **mühendislik açısından büyük bir uzlaşma gerektirdiğini** belirtmiştir. Yani dil tasarımı, **tüm ihtiyaçları karşılayan mükemmel bir çözüm** bulmak yerine, **farklı kriterler arasında bir denge kurmayı** amaçlar.

### 2. **Güvenilirliğe Karşı Çalıştırma Maliyeti**

Dillerin güvenilirliği artırmak için yapılan bazı iyileştirmeler, programların **çalıştırma maliyetini** artırabilir. Örneğin:

- **Java** dilinde, bir dizinin (array) elemanlarına erişirken her seferinde **referansların** ve **indislerin** kontrol edilmesi gerekir. Bu, potansiyel hataları önlemek için yapılan bir kontroldür ve programın güvenilirliğini artırır. Ancak, bu ek kontroller **çalıştırma maliyetini** de artırır.
- Bu tür denetim mekanizmaları, çalışma zamanında **performans kaybına** neden olabilir, çünkü her işlem ekstra bir kontrol adımını gerektirir.

### 3. **Okunabilirliğe Karşı Yazılabilirlik**

Bazı dillerde, **yazılabilirliği** artırmak amacıyla sağlanan esneklik, **okunabilirliği** azaltabilir. Örneğin:

- **APL** dili, birçok güçlü operatör sunarak oldukça karmaşık hesaplamaların kısa kodlarla yapılabilmesini sağlar. Bu, dilin yazılabilirliğini artırsa da, **kodun anlaşılmasını zorlaştırır**.
- Daniel McCracken, **APL** dilinde dört satırlık bir kodun anlaşılmasının dört saat sürebileceğini ifade etmiştir. Bu, dilin okunabilirlik açısından zayıf olduğunu gösterir. Yani yazılabilirliğin artışı, okunabilirliğin azalmasına neden olabilir.

### 4. **Yazılabilirliğe Karşı Güvenilirlik**

Bazı dillerde, esnekliğin artırılması güvenilirliği azaltabilir. Örneğin:

- **C++** dilindeki **işaretçiler** (pointers) çok güçlüdür ve yazılım geliştirme sürecinde büyük bir esneklik sağlar. Ancak işaretçilerin hatalı kullanımı ciddi güvenlik açıklarına ve bellek sızıntılarına yol açabilir.
- **Java**, işaretçiler gibi tehlikeli yapıların kullanımını kısıtlayarak güvenilirliği artırır, ancak bu durumda programcının bazı esnekliklerden ödün vermesi gerekir.

### 5. **Kompromisler ve Uzlaşmalar (Compromises and Trade-offs)**

Programlama dillerinin tasarımında, her zaman bir **kompromis** yapmak zorunludur. Bir dil, belirli bir kriterde mükemmelliğe ulaşmaya çalışırken, diğer kriterlerde ödünler vermek zorunda kalabilir. Örneğin:

- Bir dilin **güvenilirliği** artırılmak isteniyorsa, **performans** veya **esneklik** açısından ödün verilebilir.
- Bir dilin **yazılabilirliği** artırılırken, bu dilin **okunabilirliği** zorlaşabilir.

---

### **Sonuç:**

Dil tasarımında getiri-götürü ilişkileri, belirli özelliklerin iyileştirilmesinin, diğer alanlarda performans, okunabilirlik veya güvenilirlik gibi zayıflamalara neden olabileceğini gösterir. Tasarımcılar, bu çelişen kriterler arasında **denge** kurmaya çalışır. Programlama dillerinde yapılan her yenilik ve değişiklik, birden fazla faktörün birlikte göz önünde bulundurulmasını gerektirir ve bu süreç karmaşık bir **uzlaşma** işidir.

---

### Gerçekleştirim Metotları

Programlama dillerinin bilgisayar sistemlerinde uygulanması için çeşitli gerçekleştirim metotları bulunmaktadır. Bu metotlar, dilin özelliklerine, performans gereksinimlerine ve uygulama senaryolarına bağlı olarak farklılık gösterir. Aşağıda bu metotlar detaylandırılmıştır.

### 1. İşlemci ve Dahili Hafıza

- **Devreler topluluğu**: İşlemcilerin işleyişini sağlayan elektriksel devreler ve yapılar.
- **Makine komutları**:
    - **Macro Instructions**: Genellikle birden fazla makine komutunu birleştirerek tek bir komut gibi çalıştırır.
    - **Micro Instructions**: İşlemci içindeki en küçük işlemleri gerçekleştiren komutlardır.
- **Program ve veri**: İşlemcinin çalışması için gerekli olan veri ve komutların hafızada nasıl düzenlendiği.

### 2. Makine Dili

- **Makine dili**, bir bilgisayarın anlayabileceği komutlar kümesidir. Her işlemci mimarisinin kendine özgü bir makine dili vardır.
- **Yüksek seviye bir dili makine dili olarak kullanmak**, karmaşık ve zorlayıcıdır. Yüksek seviyeli diller, insan tarafından daha anlaşılırken, makine dili ile doğrudan çalışmak daha az esneklik sunar ve diğer dillerle entegrasyonu zorlaştırır.

### 3. Pratik Olan Makine Dili Tasarımı

- Pratik makine dili tasarımı, donanımda en çok ihtiyaç duyulan ilkel işlemleri sağlayan çok düşük seviyeli bir dildir.
- Bu tasarım, yüksek seviyeli dillerde yazılmış programlara bir arayüz oluşturmak için sistem yazılımı kullanır.

### Gerçekleştirim Metotları

Bir dilin gerçekleştirilmesi için kullanılan başlıca metotlar şunlardır:

1. **Derleyici**
    - Derleyici, yüksek seviyeli bir dili makine diline çevirir.
    - Çevirme süreci tamamlandıktan sonra programın çalıştırılması çok hızlıdır.
    - Örnek diller: **C, COBOL, C++**
    - Derleyicinin çevirdiği dil, **kaynak dil (source language)** olarak adlandırılır.
2. **Saf Yorumlama**
    - Yorumlayıcı, kaynak kodu satır satır okur ve çalıştırır.
    - Derleme süreci yoktur, bu da esneklik sağlar ancak performansı düşürebilir.
    - Örnek diller: **Python, Ruby**
3. **Hibrit Gerçekleştirim Sistemleri**
    - Hem derleyici hem de yorumlayıcı özelliklerini bir arada kullanır.
    - Önce kaynak kodunu bir ara forma (bytecode) çevirir, ardından bu ara formu yorumlayarak çalıştırır.
    - Örnek diller: **Java (Java Virtual Machine - JVM)**
4. **Önişlemci**
    - Kaynak kodunu derlemeden önce, belirli işlemleri gerçekleştiren bir araçtır.
    - Önişlemci, kodu değiştirme ve geliştirme işlemleri yaparak derleme sürecine yardımcı olur.

### Dil Uygulama Sistemi

- Bir dil uygulama sistemi, bilgisayardaki tek bir yazılım olabilir. Bu yazılım, dilin derleyicisi, yorumlayıcısı veya ikisi de olabilir.
- **İşletim Sistemi**: Bilgisayar kaynaklarını yöneten yazılım. Programların çalışmasını ve iletişimini sağlar.
- **Arayüz**: Kullanıcı ile sistem arasında etkileşim sağlayan katman.
- **Katmanlar**: Farklı yazılım bileşenlerinin bir arada çalışmasını sağlayan yapılar.
- **Sanal Bilgisayarlar**: Fiziksel donanım üzerinde sanal ortamlar oluşturan yazılım bileşenleri.

---

### Derleyici (Compiler)

Derleyici, yüksek seviyeli programlama dillerinde yazılmış kaynak kodunu makine diline veya başka bir hedef diline dönüştüren bir yazılımdır. Derleyicinin temel işlevi, kaynak kodunu analiz edip uygun bir biçimde işlemek ve çalıştırılabilir bir program oluşturmaktır. Aşağıda, derleyici sürecinin temel bileşenleri ve her bir bileşenin işlevleri detaylı bir şekilde açıklanmaktadır.

### 1. Sözcüksel Analiz (Lexical Analysis)

Sözcüksel analiz, kaynak kodunu sözcük birimlerine (lexeme) ayırarak ilk adımı atar. Bu aşamada:

- **Sözcük Birimleri (Lexeme):** Programın yapı taşlarını tanımlar. Bunlar; anahtar kelimeler, değişken adları, sayılar ve operatörler gibi öğelerdir.
- **Özel Kelimeler:** Programlama dilinin belirli anlam taşıyan ve özel işlevleri olan kelimeleridir (örneğin `if`, `else`, `while`).
- **Operatörler:** Matematiksel veya mantıksal işlemleri ifade eden sembollerdir (örneğin `+`, ``, ``, `&&`).
- **Noktalama İşaretleri:** Düzgün sözdizimi için gerekli olan işaretlerdir (örneğin `;`, `{}`, `()`).
- **Açıklama Satırları:** Kaynak kodu içinde yorum yapmak için kullanılan satırlardır. Derleyici bu satırları göz ardı eder.

Sözcüksel analiz sırasında, bu öğelerden oluşan bir sembol tablosu oluşturulur ve bu sayede kaynak kodun daha sonraki aşamalarda kullanılması için gerekli bilgiler toplanır.

### 2. Sözdizim Analizi (Syntax Analysis)

Sözdizim analizi, sözcük birimlerini alarak programın doğru bir yapıya sahip olup olmadığını kontrol eder. Bu aşamada:

- **Sözcük Birimlerini Alır:** Sözcüksel analizden gelen verileri işler.
- **Ayrıştırma Ağaçları (Parse Tree):** Kodun yapısını gösteren ağaç yapıları oluşturur. Bu ağaçlar, programın hangi kurallara uygun olduğunu ve nasıl bir yapıda olduğunu gösterir.
- **Sözdizimsel Yapı:** Kodun kurallarına uygunluğunu kontrol eder. Yanlış sözdizimi hataları burada tespit edilir.

### 3. Ara Kod Üretici (Intermediate Code Generation)

Ara kod üretimi, derleyici sürecinin bir sonraki aşamasıdır. Bu aşamada:

- **Kaynak Kod ile Derleyici Çıktısı Arasındaki Kod:** Yüksek seviyeli dilden daha düşük seviyeli bir koda dönüşüm sağlanır. Bu ara kod, makine diline dönüşmeden önceki bir adımdır.
- **Makine Dili Kodu:** Hedef makinenin anlayabileceği bir biçimdeki ara kodlar üretilir.

### 4. Anlamsal Analiz (Semantic Analysis)

Anlamsal analiz, derleyicinin anlam açısından doğru olup olmadığını kontrol ettiği aşamadır. Bu aşamada:

- **Sözdizim Sırasında Anlaşılması Zor Hataları Denetler:** Kodun mantıksal hatalarını kontrol eder. Örneğin, bir değişkenin tanımlanmadan kullanılmasını veya yanlış türde bir değer atamasını kontrol eder.
- **Tip Hataları:** Veri türlerinin uyumsuzluğunu tespit eder. Örneğin, bir tamsayı değişkenine bir ondalıklı sayı atanması gibi hatalar.

### 5. Optimizasyon (Optimization)

Optimizasyon, ara kodu iyileştirmek amacıyla yapılan işlemler bütünüdür. Bu aşamada:

- **Daha Hızlı ve/veya Daha Küçük:** Kodun performansını artırmak için gereksiz işlemler ortadan kaldırılır.
- **Makine Dilinde Zor:** Düşük seviyeli optimizasyonlar, makine dilinde daha karmaşık ve zor olabilir.

### Sonuç

Derleyici, bir yazılımın doğru, etkili ve verimli bir şekilde çalışmasını sağlamak için çeşitli aşamalardan geçen bir sistemdir. Bu aşamalar, programın sözcüksel ve sözdizimsel olarak doğru olmasının yanı sıra, anlamsal olarak da anlamlı olmasını güvence altına alır. Derleyici, bu süreçleri başarıyla yürüttüğünde, yüksek seviyeli dillerde yazılan programların makine diline dönüşümünü gerçekleştirerek çalıştırılabilir bir yazılım oluşturur.

---

### Basitleştirilmiş Derleme Süreci

Derleyici süreci, yüksek seviyeli programlama dillerinden makine diline geçiş aşamalarını içerir. Bu süreç, genel olarak iki ana bölümden oluşur: ön-uç (front-end) ve arka-uç (back-end).

### 1. Ön-Uç (Front-End)

Ön-uç kısmı, bir programın sözdizimi ve anlamını dilin kurallarına göre inceleyerek çözümleyen ve bir ara kod oluşturan bölümdür. Bu bölümün özellikleri şunlardır:

- **Makine Bağımsız:** Ön-uç, herhangi bir makineye bağımlı değildir. Yani, farklı makinelere yönelik programlar oluşturulurken aynı ön-uç bileşenleri kullanılabilir.
- **Sözcüksel ve Sözdizim Analizi:** Ön-uç, kaynak kodun doğru bir biçimde analiz edilmesini sağlar. Bu süreçte sözcük birimleri tanımlanır ve kodun sözdizimsel yapısı kontrol edilir.
- **Anlamsal Analiz:** Programın anlamını kontrol ederek, doğru veri türleri ve işlemlerin kullanılıp kullanılmadığını denetler.
- **Ara Kod Üretimi:** Doğru ve optimize edilmiş bir ara kod oluşturur. Bu kod, daha sonraki aşamalarda makine diline çevrilecektir.

### 2. Arka-Uç (Back-End)

Arka-uç kısmı, programın ara kod gösteriminde isteğe bağlı eniyileme uygulayarak makine kodunu oluşturan bölümdür. Bu bölümün özellikleri şunlardır:

- **Makine Bağımlı:** Arka-uç, belirli bir makineye özgü kod üretir. Bu nedenle, farklı makinelere yönelik optimize edilmiş kodlar oluşturmak için arka-uç bileşenleri farklılık gösterir.
- **Kod Üretimi:** Ara kodu alarak hedef makinenin anlayabileceği biçimde makine diline çevirir.
- **Optimizasyon:** Kodun daha hızlı veya daha az yer kaplayacak şekilde optimize edilmesi işlemlerini gerçekleştirir.

### Derleyici Bileşenleri

### 1. Kod Üretici

Kod üretici, yüksek seviyeli programlama dilinde yazılmış bir kodu makine diline çeviren bölümdür. Bu süreç, programın hedef makinede çalışabilmesi için gerekli tüm adımları içerir.

### 2. Sembol Tablosu

Sembol tablosu, derleyici süreci için bir veritabanı işlevi görür. Bu tabloda:

- **Kullanıcı Tanımlı İsimler:** Programda tanımlanan değişkenler ve fonksiyonlar gibi öğelerin tür ve özellik bilgileri saklanır.
- **Sözcüksel ve Sözdizim Analizcisi:** Sembol tablosuna gerekli bilgileri ekler.
- **Anlamsal Analizci ve Kod Üretici:** Bu bilgileri kullanarak programın mantığını ve kod üretimini gerçekleştirir.

### Bilgisayar ve Çalışma Süreci

- **Donanım:** Derlenmiş kod, bilgisayarda doğrudan çalıştırılabilir. Bunun için gerekli olan işletim sistemi ile uyumlu olması gerekir.
- **Gerekli Programlar:** Kullanıcı programları, işletim sistemi ile etkileşimde bulunabilmesi için gerekli olan diğer programlarla bağlantı kurmalıdır.
- **Load Module veya Executable Image:** Derlenmiş kodun çalıştırılabilir bir biçimde kaydedilmesi sürecidir.
- **Linking and Loading:** Derleyici tarafından oluşturulan kodun, diğer gerekli kütüphanelerle ve programlarla bir araya getirilmesi işlemi.
- **Sistem Programı - Linker:** Bağımsız bileşenleri birleştiren programdır.

### von Neumann Darboğazı

- **Darboğaz (Bottleneck):** von Neumann mimarisine sahip sistemlerde, işlemci ile bellek arasındaki veri akışı, veri yolları üzerinden sağlandığı için sınırlı bir hızda gerçekleşir. Bu, sistemin performansını etkileyebilir.

### Sonuç

Eğer A adet kaynak dil için B adet farklı hedef makine varsa, toplamda A x B adet optimizasyon ve kod üretecine ihtiyaç vardır. Bu, her bir makine için özel olarak optimize edilmiş kodların üretilmesi gerektiğini gösterir. Ayrıca, "front-end" ve "back-end" çalışmalarının birbirinden bağımsız olması, mevcut kısımların yeni durumlarda da kullanılabilmesine olanak sağlar. Bu yapı, derleyicinin esnekliğini artırır ve geliştirme sürecini daha verimli hale getirir.

---

### von Neumann Darboğazı

**Tanım:**
Von Neumann Darboğazı, bilgisayar sistemlerinde işlemcinin (CPU) bellekle iletişim kurarken karşılaştığı bir performans kısıtlamasıdır. Bu durum, işlemcinin verileri ve komutları bellekten almak için beklemek zorunda kalmasından kaynaklanır. Von Neumann mimarisi, verilerin ve komutların aynı bellek alanında saklanmasını öngördüğünden, işlemci her iki tür bilgiye erişirken aynı veri yolunu (bus) kullanmak zorundadır. Bu, veri ve komut akışında bir darboğaza yol açar.

### Nedenleri

1. **Tek Veri Yolu:**
    - Von Neumann mimarisi, hem veri hem de komutların aynı bellek alanında saklanmasını ve bunlara erişimin tek bir veri yolu üzerinden yapılmasını gerektirir. Bu, işlemci bir komut yürütmekteyken aynı anda veri alıp verememesine yol açar. İşlemci, komutları veya verileri alırken diğerine erişim için beklemek zorunda kalır.
2. **Bellek Erişim Süresi:**
    - Bellek erişim süreleri, işlemcinin işlem yapma hızına kıyasla oldukça yavaştır. Modern işlemciler, gigahertz (GHz) hızında çalışabilirken, bellek erişimi nanometre (ns) seviyesinde işlem yapmaktadır. Bu durum, işlemcinin belleğe erişim beklemelerini gerektirir.
3. **İşlemci ve Bellek Hızı Farklılıkları:**
    - İşlemciler, belleğe göre çok daha hızlı çalıştıkları için, işlemcinin ihtiyaç duyduğu verilerin bellekte bulunması zaman alabilir. Bu hız farkı, işlemcinin bellek ile iletişim kurarken daha fazla bekleme süresi yaşamasına neden olur.

### Sonuçları

1. **Performans Kaybı:**
    - Von Neumann Darboğazı, sistemin genel performansını düşürür. İşlemcinin sürekli olarak bellekle iletişim kurmak zorunda kalması, işleme hızını azaltır.
2. **Enerji Tüketimi:**
    - İşlemci sürekli bellek erişim beklerken, daha fazla enerji tüketir. Bu, özellikle mobil cihazlarda ve güç tasarrufu gerektiren sistemlerde önemli bir sorun olabilir.
3. **Çoklu İşlemci Sistemlerinde Sorun:**
    - Çok çekirdekli veya çok işlemcili sistemlerde, her bir işlemci aynı bellek yolunu paylaşmak zorundadır. Bu durum, işlemler arasında daha fazla bekleme süresine yol açar ve verimliliği azaltır.

### Çözüm Yöntemleri

1. **Cache Bellek Kullanımı:**
    - Cache bellek, işlemcinin hızlı bir şekilde erişebileceği küçük bir bellek alanıdır. İşlemci, sık kullanılan verileri cache bellek içinde tutarak bellek erişim süresini azaltabilir.
2. **Harici Bellek Genişletmeleri:**
    - Bellek genişletmeleri (örneğin, daha hızlı RAM veya bellek türleri) kullanarak bellek erişim sürelerini azaltmak mümkündür.
3. **Paralel Veri Yolları:**
    - Modern sistemler, veri ve komutlar için paralel veri yolları kullanarak von Neumann Darboğazını azaltmaya çalışmaktadır. Bu, işlemcinin aynı anda hem veri hem de komutlara erişmesini sağlar.
4. **Heterojen Sistem Mimarileri:**
    - Farklı türde işlemcilerin (GPU gibi) kullanılmasını içeren sistem mimarileri, belirli görevleri daha etkili bir şekilde yerine getirmek için tasarlanmıştır. Bu da bellek erişim süresini ve dolayısıyla darboğazı azaltabilir.

### Sonuç

Von Neumann Darboğazı, modern bilgisayar mimarilerinde önemli bir performans sınırlayıcısıdır. Bu durumu anlamak, daha etkili sistem tasarımları ve daha yüksek performans için çözümler geliştirmek açısından kritik öneme sahiptir. Sistem tasarımcıları, işlemci ile bellek arasındaki iletişimi optimize ederek bu darboğazı minimize etmeye çalışmaktadır.

---

### Saf Yorumlama

**Yorumlayıcı (Interpreter):**
Saf yorumlama, programların satır satır işlenmesini sağlayan bir yazılım yöntemi olarak tanımlanır. Yorumlayıcı, yüksek seviyeli bir dilde yazılmış olan ifadeleri alır ve bunları anlık olarak yürütür. Bu süreç, programı çalıştırmak için herhangi bir dönüştürme yapmadan doğrudan kaynak kodunu çalıştırmayı içerir.

### 1. **Fetch-Execute Döngüsü**

Yorumlayıcılar, makine komutlarından ziyade yüksek seviyeli dil programı ifadeleriyle ilgilenirler. Bu durum, bir yazılım simülasyonu olan sanal makinelerin kullanımını gerektirir. Fetch-execute döngüsü, yorumlayıcının her bir ifadeyi alıp (fetch) yürütme (execute) işlemi gerçekleştirmesi anlamına gelir. Her döngü, programın her bir ifadesini sırayla işleyerek ilerler.

### 2. **Hata Ayıklama**

Yorumlayıcıların en büyük avantajlarından biri hata ayıklama işleminin daha kolay olmasıdır. Programın her bir ifadesi yürütüldüğünde, hata meydana geldiğinde hangi ifadede olduğunu hemen görebilirsiniz. Örneğin, bir dizi sınır aşım hatası gibi bir hata, hemen ortaya çıkar ve geliştirici hatayı düzeltebilir.

### 3. **Performans**

Yorumlayıcılar, derleyicilere göre 10 veya 100 kat daha yavaş çalışabilirler. Bu yavaşlık, yüksek seviyeli dil ifadelerinin çözümleme süresinden kaynaklanır. Yani, her ifade yürütüldüğünde, yorumlayıcı bu ifadenin kodunu yeniden çözümlemek zorundadır. Bu durum, özellikle sık tekrarlanan ifadelerde performans kaybına yol açar.

### 4. **Statement Decoding**

Saf yorumlamanın en büyük darboğazı, her ifadenin yürütülmeden önce çözülme gerekliliğidir. Yorumlayıcı, ifadeleri çözümlemek için belirli bir zaman harcar ve bu da programın genel performansını etkiler. Bu süreç, yüksek seviyeli ifadelerin çözülmesi ve yorumlanmasıyla ilgili karmaşıklıkları içerir.

### 5. **Bellek Kullanımı**

Yorumlama sırasında sembol tablosuna ihtiyaç vardır. Sembol tablosu, değişkenlerin ve fonksiyonların isimleri ile bunlara karşılık gelen adreslerin tutulduğu bir yapıdır. Yorumlayıcı, sembol tablosunu kullanarak kaynak kodundaki öğeleri işler. Bu durum, minimum boyut yerine kolay erişim ve modifikasyon için tasarlanmış bir form gerektirir.

### Örnek Diller

Saf yorumlama yöntemiyle çalışan bazı programlama dilleri şunlardır:

- **APL:** Matris tabanlı hesaplamalar için kullanılan bir dil.
- **SNOBOL:** Metin işleme için geliştirilmiş bir dil.
- **LISP:** Özellikle yapay zeka uygulamalarında yaygın olarak kullanılan bir dil.
- **JavaScript:** Web geliştirme için en çok kullanılan dillerden biridir.
- **PHP:** Web sunucu tarafı betik dili olarak kullanılmaktadır.

### Sonuç

Saf yorumlama, hızlı geliştirme ve hata ayıklama kolaylığı sunmasına rağmen, performans kayıplarına ve daha fazla bellek kullanımına neden olabilir. Yorumlayıcılar, yüksek seviyeli dil ifadelerini işlemek için etkili bir yöntem sunar, ancak yoğun iş yükü altında yavaşlayabilirler. Bu nedenle, kullanım alanına göre derleyici veya yorumlayıcı seçimi önemlidir.

---

### Derleyici (Compiler) ve Yorumlayıcı (Interpreter)

Derleyiciler ve yorumlayıcılar, yüksek seviyeli programlama dillerini makine diline çevirmek için kullanılan iki farklı yöntemdir. Her iki yöntemin de avantajları ve dezavantajları bulunmaktadır. Aşağıda bu iki yaklaşımın temel özelliklerini karşılaştıran bir inceleme sunulmaktadır.

### Derleyici (Compiler)

- **Tam Programı Tarama:** Derleyici, programın tamamını tarar ve bunu makine koduna çevirir. Bu işlem, tüm kaynak kodunun analiz edilmesini gerektirir.
- **Zaman Tüketimi:** Derleyici, kaynak kodunu analiz etmek için daha fazla zaman harcar; ancak, derlenmiş kodun yürütülme süresi genellikle daha hızlıdır. Bu, derleme işleminden sonra elde edilen makine kodunun doğrudan çalıştırılabilmesi ile ilgilidir.
- **Ara Kod Üretimi:** Derleyici, ara kod (object code) üretir. Bu ara kod daha sonra bağlantı (linking) gerektirir, bu da daha fazla bellek tüketimine neden olabilir.
- **Hata Mesajları:** Derleyici, tüm programı taradıktan sonra hata mesajları üretir. Bu nedenle, hata ayıklama (debugging) işlemi daha zor hale gelir çünkü hata tespiti için tüm kodun kontrol edilmesi gerekir.
- **Kullanım Alanları:** C, C++ gibi diller derleyiciler kullanır. Bu diller, performans gereksinimlerinin yüksek olduğu durumlarda tercih edilir.

### Yorumlayıcı (Interpreter)

- **Satır Satır Çeviri:** Yorumlayıcı, programı bir ifade (statement) veya satır halinde çevirir. Bu, kodun hemen yürütülmesini sağlar.
- **Zaman Tüketimi:** Yorumlayıcı, kaynak kodunu analiz etmek için daha az zaman harcar; ancak, yürütme süresi daha yavaştır. Çünkü her bir ifade çözümlenirken, işlem tekrar başlar.
- **Ara Kod Üretimi Yok:** Yorumlayıcı, ara kod üretmez ve bu nedenle bellek açısından daha verimlidir. Kod doğrudan yürütüldüğü için bellek kullanımı daha azdır.
- **Hata Mesajları:** Yorumlayıcı, programı yürütme sürecinde karşılaştığı hatalarda hemen durur ve hata mesajını verir. Bu durum, hata ayıklama işlemini daha kolay hale getirir.
- **Kullanım Alanları:** Python, Ruby gibi diller yorumlayıcılar kullanır. Bu diller, hızlı prototipleme ve geliştirme sürecinde sıkça tercih edilir.

### Özet

- **Derleyici:** Programın tamamını analiz eder ve makine koduna çevirir, ancak hata tespiti daha zor ve zaman alıcıdır. Performansı yüksektir ve C, C++ gibi dillerde yaygın olarak kullanılır.
- **Yorumlayıcı:** Programı satır satır çevirir ve hata durumunda anında durur, böylece hata ayıklama süreci kolaylaşır. Ancak, yürütme süresi daha yavaştır ve Python, Ruby gibi dillerde yaygın olarak kullanılır.

Her iki yöntemin de avantajları ve dezavantajları vardır. Hangi yöntemin kullanılacağı, projenin gereksinimlerine, performans ihtiyaçlarına ve geliştirme sürecine bağlı olarak değişir.

---

### Hibrit Gerçekleştirim Sistemleri

Hibrit gerçekleştirim sistemleri, derleyici ve saf yorumlayıcı arasında bir uzlaşma sağlayarak yüksek seviyeli programlama dillerini yönetmek için tasarlanmış bir yapıdır. Bu sistemler, programların hızlı bir şekilde yorumlanmasını sağlamak amacıyla ara kod kullanır. Hibrit sistemlerin temel özellikleri ve avantajları aşağıda açıklanmıştır:

### 1. Ara Kod Kullanımı

Hibrit gerçekleştirim sistemleri, yüksek seviyeli dil programlarını önce bir ara dile (intermediate language) çevirir. Bu ara dil, derleme ve yorumlama süreçlerinin avantajlarını birleştirir.

- **Hız:** Saf yorumlama yöntemlerinden daha hızlıdır çünkü kaynak dil ifadeleri bir kez çözülür (decode edilir).
- **Doğrudan Yorumlama:** Ara kod, makine diline çevrilmek yerine doğrudan yorumlanır, bu da programların hızlı bir şekilde çalıştırılmasını sağlar.

### 2. Örnek Diller

**Perl Dili:**

- Perl, yorumlamadan önceki hataları tespit etmek ve yorumlayıcıyı basitleştirmek için kısmen derlenmiştir. Bu sayede geliştiricilere daha fazla hata kontrolü imkanı sunar.

**Java Dili:**

- Java, tamamen hibrit bir dildir. Java programları, önce byte koduna (ara form) derlenir ve ardından Java Virtual Machine (JVM) aracılığıyla çalıştırılır.
- **Taşınabilirlik:** Java byte kodu, farklı işletim sistemlerinde çalışabilme özelliği ile taşınabilirlik sağlar.
- **Just-in-Time (JIT) Gerçekleştirim Sistemi:** JIT, ara dil yöntemlerini makine koduna derleyerek çalışır.
    - **Performans Artışı:** İlk çalıştırmada ara kod çözülür, sonrasında ise makine kodu versiyonu bellekte tutulur. Bu, sonraki çağrılarda daha hızlı yürütme sağlar.

### 3. .NET Framework

.NET, hem derleyici hem de yorumlayıcı sağlayan bir sistemdir.

- **Geliştirme ve Hata Ayıklama:** Geliştiriciler, programlarını hızlı bir şekilde geliştirmek ve hata ayıklamak için yorumlayıcı kullanabilir.
- **Hızlı Yürütme:** Program hatasız olduğunda, derleyici devreye girerek yürütme hızını artırır.

### Sonuç

Hibrit gerçekleştirim sistemleri, programların derlenmesi ve yorumlanması süreçlerinde sağlanan esneklik ile performansı artırır. Derleyici ve yorumlayıcı yöntemlerinin avantajlarını birleştirerek, hem hızlı geliştirme hem de yüksek performans sunar. Bu tür sistemler, modern yazılım geliştirme süreçlerinde yaygın olarak kullanılmaktadır. Özellikle Java ve .NET gibi platformlar, hibrit yaklaşımların sağladığı taşınabilirlik ve performans avantajlarından yararlanmaktadır.

---

### Önişlemciler (Preprocessors)

Önişlemciler, program derlenmeden önce devreye giren ve kodu işleyen araçlardır. Önişlemci, kaynak kodu derleme aşamasına getirmeden önce bazı temel işlemleri gerçekleştirir ve genellikle başka bir dosyadaki kodu programın içine ekleme, makro tanımları oluşturma gibi işlevleri yerine getirir. Özellikle C/C++ dillerinde yaygın olarak kullanılır.

### 1. **Önişlemcinin Temel İşlevleri**

- **Başka Dosyadaki Kodu Dahil Etme:**
Önişlemci, programlara gömülü komutlarla çalışır ve genellikle başka bir dosyadaki kodun programa eklenmesini sağlar. Örneğin:
    
    ```c
    #include "myLib.h"
    ```
    
    Bu satır, önişlemciye `myLib.h` dosyasının içeriğini mevcut dosyaya kopyalaması talimatını verir. Böylece `myLib.h` dosyasındaki tüm tanımlar ve fonksiyonlar, programın bir parçası haline gelir.
    
- **Sembol Tanımları:**
Önişlemciler, semboller veya ifadeleri temsil eden makroları tanımlamak için kullanılır. Örneğin:
    
    ```c
    #define max(A, B) ((A) > (B) ? (A) : (B))
    ```
    
    Bu satır, iki değeri karşılaştıran ve büyük olanı döndüren bir makro tanımlar. Makronun kullanımı şu şekilde olabilir:
    
    ```c
    x = max(2 * y, z / 1.73);
    ```
    
    Bu ifade, önişlemci tarafından şu şekilde genişletilir:
    
    ```c
    x = ((2 * y) > (z / 1.73) ? (2 * y) : (z / 1.73));
    ```
    
    Böylece kodun daha okunabilir olması sağlanırken, önişlemci bu makroyu derleme öncesinde genişleterek doğrudan kodun içerisine yerleştirir.
    

### 2. **Önişlemcinin Diğer İşlevleri**

- **Makro Tanımları:**
Önişlemci makroları, birden fazla yerde aynı işlemi yapmak yerine bir kere tanımlayıp her yerde kullanmayı sağlar. Bu sayede tekrar eden kodlar azaltılır ve bakımı kolaylaştırılır.
- **Koşullu Derleme:**
Önişlemciler, belirli koşullara göre kodun hangi kısımlarının derleneceğini belirleyebilir. Örneğin:
    
    ```c
    #ifdef DEBUG
    printf("Debug modunda çalışıyor.");
    #endif
    ```
    
    Bu kod, yalnızca `DEBUG` sembolü tanımlı olduğunda derlenir.
    

### 3. **Önişlemcilerin Avantajları**

- **Modülerlik:** Farklı dosyalarda tanımlanmış kodları programa dahil ederek modüler bir yapı sağlar. Bu, özellikle büyük projelerde kodun yönetimini kolaylaştırır.
- **Kod Tekrarını Azaltma:** Makrolar sayesinde, aynı kodu tekrar tekrar yazmak yerine tek bir tanımla her yerde kullanılabilir.

### 4. **Zorluklar ve Dikkat Edilmesi Gerekenler**

Önişlemci kullanımı bazı durumlarda dikkatli olmayı gerektirir. Özellikle makroların genişletilmesi, beklenmeyen sonuçlara yol açabilir. Örneğin, aşağıdaki makronun kullanımı sorunlu olabilir:

```c
#define square(x) x * x
```

Eğer bu makro şu şekilde kullanılırsa:

```c
result = square(1 + 2); // Beklenen: 9
```

Önişlemci bu ifadeyi şu şekilde genişletir:

```c
result = 1 + 2 * 1 + 2; // Gerçekleşen: 5
```

Bu hatayı önlemek için makro tanımında parantezler kullanılmalıdır:

```c
#define square(x) ((x) * (x))
```

Sonuç olarak, önişlemciler programlamada büyük kolaylıklar sağlasa da dikkatli kullanılması gereken güçlü araçlardır. Kod modülerliğini artırırken, makro kullanımı sırasında dikkat edilmezse beklenmeyen davranışlar da ortaya çıkabilir.

---

### Programlama Çevreleri

Programlama çevreleri, yazılım geliştirme süreçlerini kolaylaştırmak için kullanılan araçların ve kaynakların bir araya geldiği sistemlerdir. Bu ortamlar, geliştiricilerin daha verimli çalışmasını sağlayarak, yazılımın tasarımı, geliştirilmesi ve bakımında önemli rol oynar. Programlama çevreleri, kullanıcı dostu arayüzler, hata ayıklama araçları, kütüphaneler ve framework'ler gibi çeşitli bileşenler içerir.

### 1. **UNIX**

- **Tanım:** UNIX, taşınabilir bir çoklu programlama işletim sistemidir. Geliştiricilere, yazılım üretimi ve bakımı için çok çeşitli güçlü destek araçları sunar.
- **Özellikler:**
    - Taşınabilirlik ve çoklu kullanıcı desteği.
    - Komut satırı arayüzü ile güçlü bir kontrol sağlar.
    - Geliştiricilerin ihtiyaçlarına yönelik geniş araç seti mevcut.
- **Arayüz Eksikliği:** UNIX'in bazı sürümleri, kullanıcı dostu grafik arayüzler sunmaz; bu nedenle CDE, GNOME ve KDE gibi grafiksel arayüzler geliştirilmiştir.

### 2. **Borland JBuilder**

- **Tanım:** Java geliştirme için entegre bir ortamdır. Derleyici, editör, hata ayıklayıcı ve dosya sistemi gibi bileşenler içerir.
- **Özellikler:**
    - Kullanıcı dostu grafik arayüzü ile karmaşık ve güçlü bir sistem sunar.
    - Java uygulamaları geliştirmek için gerekli olan tüm araçları sağlar.

### 3. **Microsoft Visual Studio .NET**

- **Tanım:** Yazılım geliştirme ortamlarının gelişiminde yeni bir adım olarak öne çıkar. Geniş bir araç koleksiyonu sunar.
- **Özellikler:**
    - Pencereli bir arayüze sahiptir ve kullanıcı dostudur.
    - C#, Visual BASIC .NET, JScript (JavaScript'in Microsoft sürümü), F# (işlevsel dil) ve C++/CLI gibi dilleri destekler.
    - Geliştiricilere kapsamlı hata ayıklama ve geliştirme araçları sağlar.

### 4. **NetBeans**

- **Tanım:** Java uygulama geliştirme ortamı olarak bilinir ve JavaScript, Ruby ve PHP gibi diller için de destek sunar.
- **Özellikler:**
    - Kullanıcı dostu arayüz ile geniş bir özellik seti sunar.
    - Açık kaynaklı bir platformdur ve geliştiricilere esneklik sağlar.

### 5. **Frameworks**

- **Tanım:** Framework'ler, uygulamanın ortak kod parçalarını sağlayarak geliştirme sürecini hızlandırır. Geliştiricilerin belirli görevleri yerine getirmesine yardımcı olan yapı taşlarıdır.
- **Özellikler:**
    - Kullanıcıların tekrar eden görevleri kolayca yapabilmesine olanak tanır.
    - Kod yeniden kullanımını teşvik eder ve yazılım geliştirme sürecini standartlaştırır.

### Sonuç

Programlama çevreleri, yazılım geliştirme sürecinin farklı aşamalarında geliştiricilere çeşitli avantajlar sunar. Hangi ortamın seçileceği, projenin gereksinimlerine, geliştirici becerilerine ve hedef platforma bağlı olarak değişebilir. Her ortamın kendine has özellikleri ve sunduğu araçlar vardır, bu nedenle doğru programlama çevresinin seçimi, projenin başarısı için kritik öneme sahiptir.

---

### Zuse’nin Plankalkül

Zuse’nin Plankalkül, bilgisayar programlama tarihinin önemli bir parçasıdır, ancak birçok açıdan sıradışı bir konumda bulunmaktadır. İlk olarak 1945 yılında geliştirilmiş olan bu dil, uzun bir süre boyunca (1972’ye kadar) yayınlanmamış ve asıl uygulama alanına kavuşamamıştır. Zuse, bu programlama dilini geliştirirken, bazı özelliklerinin diğer programlama dillerinde 15 yıl kadar geç görünmesine neden olmuştur.

### Tarihsel Geçmişi

Konrad Zuse, 1936-1945 yılları arasında elektromekanik rölelerden oluşan karmaşık bilgisayarlar inşa etmiştir. Bu süreçte Z4 adını verdiği bilgisayarı bombalama nedeniyle kaybetmiş ve ekibi dağıldı. Zuse, Z4 için hesaplamaları ifade etmek üzere bir dil geliştirmeye karar vermiştir. Bu dilin ismi "Plankalkül" yani "Program hesaplaması" olarak adlandırılmıştır. 1972 yılında Zuse, Plankalkül'ü tanımlamış ve çeşitli problemleri çözmek için dilde algoritmalar yazmıştır.

### Plankalkül - Genel Bakış

Plankalkül, veri yapılarındaki gelişmiş özellikleri ile dikkat çeken, önemli ölçüde tamamlanmış bir programlama dilidir. Aşağıda Plankalkül'ün bazı temel özellikleri yer almaktadır:

- **Veri Tipleri:** En basit veri tipi tek bit olarak tanımlanmıştır. Tek bitten, tam sayı ve kayan noktalı sayılar türetilmiştir. Ayrıca diziler ve kayıtlar (C dilindeki `struct` yapısı) da içerir.
- **Kontrol Yapıları:** Plankalkül'de açıkça bir `goto` ifadesi bulunmamakla birlikte, Ada dilindeki `for` ifadesine benzer bir tekrarlama durumu (fin komutu) mevcuttur. Seçim ifadeleri içerir, ancak `else` durumu yoktur.
- **Matematiksel İfadeler:** Program değişkenleri arasındaki güncel ilişkileri gösteren matematiksel ifadelerin dahil edilmesi, dilin önemli bir özelliğidir. Bu ifadeler, yürütme sırasında kodun belirli noktalarında neyin doğru olduğunu belirtir.

Plankalkül, 1945'ten önce yazılan programlardan çok daha karmaşık yapıda programlar oluşturma imkanı tanımaktadır. Örnekler arasında:

- Sayı dizilerini sıralamak
- Verilen grafın bağlanabilirliğini test etmek
- Karekök dahil olmak üzere tam sayı ve kayan nokta işlemleri gerçekleştirmek
- 6 farklı öncelik seviyesinde parantez ve işleçleri olan mantık formülleri üzerinde sözdizim analizi yapmak
- Satranç oynamak için 49 sayfalık bir algoritma geliştirmek

### Notasyon Problemleri

Zuse’nin Plankalkül'ün en büyük engeli, dilin notasyonu ve gösterim biçimidir. Her ifade genellikle 2 ya da 3 satırdan oluşur. İlk satır, mevcut dillerdeki ifadelere benzer yapıda iken, isteğe bağlı ikinci satır dizi referanslarının ilk satırında belirtilen aboneleri içermektedir. Son satır ise, ilk satırda bahsedilen değişkenlerin tip isimlerini içerir.

### Sonuç

Zuse’nin Plankalkül'ü, programlama dillerinin gelişiminde önemli bir kilometre taşı olarak kabul edilmektedir. Tarihsel açıdan, bilgisayar biliminin temellerini atan bir çalışma olmasının yanı sıra, daha sonra geliştirilen birçok dilin özelliklerini önceden öngörmesi açısından da dikkat çekmektedir. Ancak uygulama eksikliği ve notasyon sorunları, bu dilin geniş çapta benimsenmesini engellemiştir. Yine de Plankalkül, programlamanın tarihindeki yenilikçi düşünceyi temsil etmektedir.

---

### Pseudocode (Sahte Kod)

Pseudocode, genellikle bir algoritmanın mantığını ifade etmek için kullanılan, doğal dil ve programlama dilleri arasında bir köprü işlevi gören bir yöntemdir. 1940'ların sonunda bilgisayarların durumu, yazılım geliştirme sürecinde bazı zorlukların üstesinden gelmeyi gerektiriyordu. Bu dönemde bilgisayarlar, günümüzdekilerle karşılaştırıldığında daha az kullanışlı, yavaş, güvensiz, pahalıydı ve hafızaları oldukça küçüktü.

### 1940'ların Sonunda Bilgisayarların Durumu

Bu dönemde, yüksek seviye diller ve assembly dilleri mevcut değildi. Bunun yerine, programcılar makine dili (hata yapmaya açık ve karmaşık) kullanmak zorundaydılar. Bu bağlamda, sayısal kodlar (örneğin, `ADD` için Kod 14) kullanılıyordu. Diğer bir büyük sorun, mutlak adresleme (absolute addressing) ile ilgiliydi; bu durum, veri ekleme ve silme işlemlerinde zorluk yaratıyordu. Bu sorunlar, assembly dilleri için bir motivasyon kaynağı oluşturdu.

### Pseudocode - Short Code

**John Mauchly** tarafından 1949 yılında **BINAC** bilgisayarı için geliştirilmiştir. Daha sonra **UNIVAC-I** bilgisayarına aktarılmıştır. Ancak, Short Code'un tam açıklaması hiçbir zaman yayınlanmamıştır. Yalnızca UNIVAC I versiyonu için bir programlama kılavuzu (Remington-Rand, 1952) kalmıştır. UNIVAC, 72 bit hafızaya sahip bir kelime (word) ve 6 tane 12 bit gruba sahiptir.

- **Byte Pair:** Kodlar, değişkenler ve denklemler içerir.
- **Çarpım Kodu:** Çarpma işlemi, iki işlenenin yan yana yerleştirilmesiyle belirtilmiştir; dolayısıyla çarpım kodu yoktur.
- **Yürütme:** Short Code, makine koduna çevrilmeden kullanıldı ve bir saf yorumlayıcıyla çalıştırıldı. Bu, otomatik programlamayı sağladı. Ancak, yürütme süresi artmasına rağmen programlama süreci basitleşti, fakat 50 kat daha yavaş bir işlem süresi ortaya çıktı.

### Pseudocode - Speedcoding

**John Backus** tarafından 1954 yılında **IBM 701** için geliştirilmiştir. Speedcoding, kayan noktalı sayı işlemlerini içeren bir yorumlama sistemi olarak işlev görmüştür.

- **Üç Adresli Sanal Makine:** 701'i etkili bir şekilde sanal bir üç adresli kayan noktalı hesap makinesine dönüştürdü.
- **Pseudoinstructions:** Aritmetik işlemleri basit hale getirdi.
- **Bellek Sınırlamaları:** Yorumlayıcı yüklendikten sonra kalan kullanılabilir belleğin yalnızca 700 kelime olduğu belirtilmiştir. Ayrıca, ekleme talimatının yürütülmesi için 4.2 milisaniye sürmektedir.
- **Kayıtların Otomatik Artışı:** Matris çarpımı, 12 Speedcoding komutuyla gerçekleştirilebilmektedir. Backus, makine kodunda programlamak için iki hafta sürebilecek bir problemi Speedcoding kullanarak birkaç saat içinde çözebileceğini iddia etmiştir.

### Pseudocode - UNIVAC Derleme Sistemi

**Grace Hopper** ve ekibi tarafından 1951-1953 yılları arasında geliştirilmiştir. A-0, A-1 ve A-2 adında bir dizi "derleme" sistemi oluşturulmuş, sözdekod makine kodu alt programlarına genişletilmiştir. Bu derleyiciler için sözdekod kaynağı oldukça ilkel kalmıştır.

- **Gelişmeler:** Derleyiciler, kaynak programları çok daha kısa hale getirerek makine kodları üzerinde önemli bir gelişme sağlamıştır.

### İlgili Çalışmalar

Cambridge Üniversitesi'nden **David J. Wheeler** (1950), mutlak adresleme sorununu kısmen çözmek için yeniden tahsis edilebilir adres bloklarını kullanma yöntemini geliştirmiştir. **Maurice V. Wilkes** ise seçilen alt yordamları birleştirip depolama ayırmak için bir assembly programı tasarlama fikrini geliştirmiştir. 1950'lerin başlarında assembly dilleri gelişmeye başlamış, ancak yüksek seviyeli dillerin tasarımda etkileri oldukça az olmuştur.

### Sonuç

Pseudocode, 1940'ların sonlarından itibaren bilgisayar programlamasında önemli bir araç haline gelmiştir. Bu dönemlerde yaşanan zorluklar, daha karmaşık dillerin ve daha etkili programlama yöntemlerinin geliştirilmesine zemin hazırlamıştır. Pseudocode, programlama mantığını ifade etmenin yanı sıra, yazılım geliştirme sürecinde yenilikçi çözümlerin ortaya çıkmasına yardımcı olmuştur.

---

### Alan Cooper - Röportaj Özeti

**Alan Cooper** (3 Haziran 1952 doğumlu) Amerikalı bir yazılım tasarımcısı ve programcıdır. "Visual Basic"in babası olarak tanınan Cooper, kullanıcı arayüzü tasarımı konusundaki en büyük endişelerden birini taşıyan bir dil tasarlamada önemli bir rol oynamıştır. Ona göre, her şey teknolojiyi insana yakınlaştırma vizyonuna dayanıyor.

### Başlangıç ve Eğitim

- **Eğitim:** Lise terk, California topluluk kolejinde programlama üzerine bir ön lisans derecesi.
- **İlk İş:** San Francisco'daki American President Lines'da programcı olarak çalışmaya başladı.
- **Kariyer:** Kısa süreli bazı iş deneyimleri dışında, genellikle serbest çalıştı.

### Mevcut Pozisyon

- **Şirket:** Cooper adlı şirketin kurucu ve başkanı. Bu şirket, teknolojiyi insana yakınlaştırmayı hedefliyor.

### Windows ve Tasarım Süreci

- 1980'lerde Windows'u kullanmaya başladı ve grafiksel kullanıcı arayüzü desteği ile dinamik olarak bağlantılı kütüphaneler gibi özelliklerinden etkilendi.
- **MSDOS.exe:** Windows'un ilk birkaç sürümü için kullanılan bu programın kötü olduğunu düşündü ve daha iyi bir kabuk programı yazmaya karar verdi; bu programın adı **Tripod** oldu.
- **Tripod:** Kullanıcıların Windows masaüstü yerine kendi bilgisayar arayüzlerini oluşturmalarına olanak tanıyan bir uygulamaydı.

### Microsoft ile İşbirliği

- **Tripod ve Ruby:** Tripod ve Ruby aynı şeydi. Bill Gates ile bir anlaşma imzaladıktan sonra, prototipin adını Ruby olarak değiştirdi.
- Ruby prototipini, yüksek kaliteli kod oluşturmak için bir model olarak kullandı. Microsoft, Ruby'nin sürümünü alarak QuickBasic ekleyerek **Visual Basic**'i oluşturdu.

### Tasarım Felsefesi

- **En Sevdiği İş:** Etkileşim tasarım danışmanı olarak çalışmak.
- **Dil Tasarımı:** Yazılım dünyasında kullanıcıyı tanımanın önemine vurgu yaptı.
- **İlgi Alanları:** Programcılar yerine kullanıcıları destekleyen programlama araçları oluşturma konusuna ilgi duyuyor.

### Kritik Tasarım İlkeleri

- **Söz:** "Köprüler mühendisler tarafından değil, demir işçileri tarafından inşa edilir." Bu da yazılım programlarının mühendisler tarafından değil, programcılar tarafından inşa edildiğini vurguluyor.

### Sonuç

Alan Cooper, kullanıcı arayüzü tasarımı ve dil tasarımı alanlarında önemli katkılarda bulunmuş bir liderdir. Yazılımın insan odaklı tasarımını benimsemek gerektiğine inanıyor ve bu bağlamda, kullanıcıların ihtiyaçlarını anlamanın ve onlara uygun araçlar geliştirmenin önemini vurguluyor.

---