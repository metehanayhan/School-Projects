# 2. Hafta

### **İşletim Sistemi Nedir?**

**İşletim sistemi (Operating System - OS)**, bilgisayar donanımı ile uygulama yazılımları arasında bir köprü görevi gören bir yazılımdır. OS, donanım kaynaklarını yönetir, uygulamaların çalışmasını sağlar ve bilgisayar sisteminin etkin bir şekilde işlemesini sağlar. İşletim sisteminin temel işlevleri şunlardır:

1. **Program Yönetimi:** İşletim sistemi, bilgisayarda çalışan programları (yani süreçleri) oluşturur, yönetir ve sonlandırır. Her program, kendine ait bir CPU, bellek ve diğer kaynaklar kullanıyormuş gibi bir algı oluşturur.
2. **Bellek Yönetimi:** İşletim sistemi, her bir programın ihtiyaç duyduğu bellek alanını yönetir. Her program, kendine özel bir bellek alanı varmış gibi davranır; ancak aslında tüm programlar, işletim sistemi tarafından yönetilen aynı fiziksel bellek alanını kullanır.
3. **Aygıt Yönetimi:** OS, diskler, ağ kartları ve diğer harici aygıtlar gibi kaynakları yönetir. Aygıt sürücüleri (device drivers), işletim sisteminin bu aygıtlarla etkileşim kurmasını sağlar.
4. **Kullanıcı Arayüzü:** İşletim sistemi, kullanıcıların bilgisayar ile etkileşimini sağlayan bir arayüz sunar. Bu, grafik arayüz (GUI) veya komut satırı (CLI) şeklinde olabilir.

---

### **Program Çalıştırma Süreci**

Bir program çalıştığında, işletim sisteminin işleyişi şu adımlarla gerçekleşir:

1. **İşlem Çekme (Fetch):** İşlemci (CPU), bellekteki bir talimatı (instruction) alır.
2. **Çözümleme (Decode):** İşlemci, hangi talimatın geldiğini belirler.
3. **Uygulama (Execute):** Örneğin, iki sayıyı toplama, belleğe erişme, bir koşulu kontrol etme gibi işlemler yapılır.
4. **Sonraki Talimata Geçiş (Move on):** İşlemci, bir sonraki talimata geçer ve bu süreç devam eder.

### **Derleme (Compilation)**

Yüksek seviyeli programlar, işletim sistemi tarafından çalıştırılmadan önce makine diline çevrilir. Örneğin, C dilinde yazılmış bir program, `a.out` gibi bir çalıştırılabilir dosyaya dönüştürülür. Bu dosya, işlemcinin anlayabileceği talimatları ve program verilerini içerir.

---

Bir program çalıştırıldığında arka planda birçok işlem gerçekleşir. Programların çalışmasını anlamak için hem donanım hem de yazılım seviyesinde neler olduğunu bilmek önemlidir. İşte bir programın çalışması sırasında neler olduğunun adım adım detaylı bir açıklaması:

### 1. **Derleyici (Compiler) Programı Yüksek Seviyeli Dilden Makine Diline Çevirir:**

- Programcılar genellikle **C**, **Java**, **Python** gibi yüksek seviyeli dillerde program yazarlar. Ancak bu diller doğrudan bilgisayar donanımı tarafından anlaşılamaz. Bilgisayar, yalnızca makine dilini (0 ve 1'lerden oluşan ikili kodlar) anlar.
- Bu yüzden, **derleyici (compiler)** adı verilen bir yazılım, bu yüksek seviyeli programları **makine diline** çevirir.
    - **Örnek:** Eğer bir C dilinde yazılan bir programınız varsa, bu dosya `.c` uzantısıyla kaydedilir. Derleyici, bu dosyayı alır ve **yürütülebilir (executable)** bir dosya üretir. C programlarında bu dosyanın adı genellikle `a.out` olur.
- Bu yürütülebilir dosya artık **CPU** tarafından doğrudan çalıştırılabilir komutlar içerir.

### 2. **Yürütülebilir Dosya (Executable File) CPU Tarafından Anlaşılabilen Talimatlar ve Veriler İçerir:**

- Yürütülebilir dosya, iki ana unsur içerir:
    1. **Talimatlar (Instructions):** Programın ne yapacağını belirten komutlar. CPU'nun hangi işlemleri yapacağını tarif eden bu talimatlar, işlemcinin **talimat kümesi mimarisi (instruction set architecture - ISA)** olarak adlandırılan yapısıyla uyumlu olmalıdır. Bu talimatlar CPU'nun anlayabileceği makine dilinde olur.
    2. **Veriler (Data):** Programın çalışırken kullanacağı veriler. Örneğin, bir değişkenin değeri ya da bir dizinin elemanları bu verilere dahil olabilir.
- **Adresleme:** Yürütülebilir dosya içindeki her bir komut ve veri bellekte belirli bir **adresle** numaralandırılır. Bu adresler, bilgisayar belleğinde programın nerede saklandığını gösterir.

### 3. **CPU Üzerinde Talimatlar Çalıştırılır:**

- Bir program çalıştığında, CPU (Merkezi İşlem Birimi) programın komutlarını sırasıyla işler. CPU'nun bu işlemi gerçekleştirmesi için, donanımsal bir yapıya sahip olması gerekir. Bu yapı, **talimat kümesi mimarisi (ISA)** olarak adlandırılır ve işlemcinin hangi talimatları nasıl işleyeceğini tanımlar.
- Örneğin, x86 veya ARM gibi farklı işlemciler farklı ISA'lara sahiptir ve her biri farklı komut setleri kullanabilir.

### 4. **CPU’nun Kayıtları (Registers):**

- CPU, veri işlemek için hızlı bellek alanları olan **kayıtlar (registers)** kullanır. Bu kayıtlar, programın çalışması sırasında geçici olarak veri tutar ve işlemlerin hızını artırır. CPU'nun kullandığı bazı temel kayıtlar şunlardır:
    1. **Program Sayacı (Program Counter - PC):** Bu kayıt, hangi komutun çalıştırılacağını belirtir. Programın sıradaki komutunun bellek adresini tutar. PC, her komut çalıştırıldığında bir sonraki komutun adresine otomatik olarak ilerler.
    2. **İşlem Operatörleri ve Bellek Adresleri (Operands of Instructions, Memory Addresses):** CPU ayrıca komutların işlem yapacağı verileri tutmak için ek kayıtlar kullanır. Bu kayıtlar, komutların hangi verilerle çalışacağını ve bu verilerin bellek adreslerini tutar.

### Program Çalışma Süreci Özet Adımları:

1. **Derleme Aşaması:**
    - Yüksek seviyeli program (`.c`, `.java` gibi) derleyici tarafından makine diline çevrilir ve yürütülebilir bir dosya (`.exe` ya da `a.out`) oluşturulur.
2. **Belleğe Yükleme:**
    - İşletim sistemi, bu yürütülebilir dosyayı bellek (RAM) içerisine yükler. Yani program, bellek üzerinde belirli adreslere yerleştirilir ve programın komutları ile verileri bellekte yer alır.
3. **Talimatların İşlenmesi:**
    - CPU, program sayacındaki adresi kullanarak programın sırasıyla komutlarını bellekteki adreslerden okur ve işler.
    - Her bir komut işlendiğinde, program sayacı bir sonraki komutun adresine ilerler.
4. **Veri ve Talimatların İşlenmesi:**
    - CPU, bellekteki verilere erişir, bu veriler üzerinde işlemler yapar ve programın talimatlarını yerine getirir. Örneğin, bir sayıyı toplar, bir bellek adresinden veri okur veya yazdırma işlemi yapar.
5. **Programın Tamamlanması:**
    - Tüm komutlar sırasıyla işlendikten sonra, program sona erer. Eğer program bir sonuç üretiyorsa (örneğin ekrana bir çıktı basıyorsa), bu sonuç kullanıcıya iletilir.

### Ekstra Detaylar:

- **Yorumlayıcılar (Interpreters) ve Derleyiciler (Compilers):**
    - Bazı diller (Python, JavaScript) derlenmek yerine **yorumlayıcı (interpreter)** kullanılarak çalıştırılır. Yorumlayıcı, programı satır satır okur ve her satırı anında çalıştırır.
    - Diğer yandan, **derlenen diller** (C, C++) önce tamamen derlenir, sonra çalıştırılır. Bu genellikle daha hızlı çalışmayı sağlar çünkü program önceden makine diline çevrilmiştir.

### Sonuç:

Bir program çalıştırıldığında, yüksek seviyeli dilde yazılan kod önce derlenir ve CPU’nun anlayacağı makine diline çevrilir. Programın komutları, bellekte belirli adreslere yüklenir ve CPU sırasıyla bu komutları işler. Program sayacı, her seferinde hangi komutun çalıştırılacağını belirlerken, CPU’nun içindeki kayıtlar bu süreci hızlandırmak ve optimize etmek için kullanılır.

---

### 1. **Programların Kolayca Çalıştırılmasını Sağlama (Making it easy to run programs):**

- **İşletim sistemi**, kullanıcının veya bir programcının bilgisayar üzerinde programları kolayca çalıştırabilmesi için bir arayüz sağlar.
- İşletim sistemi, bir programı çalıştırmak için gerekli olan **bellek yönetimi**, **dosya sistemine erişim**, **giriş/çıkış işlemleri** gibi süreçleri organize eder.
- **Çalışma süreci:**
    - Kullanıcı bir programı başlattığında, işletim sistemi bu programı belleğe yükler ve CPU'nun çalıştırması için gerekli düzenlemeleri yapar. İşletim sistemi, programın hangi donanım kaynaklarını kullanacağını ve diğer programlarla nasıl etkileşim kuracağını da belirler.
- Örneğin, bir bilgisayarda bir tarayıcı açtığınızda, işletim sistemi bu tarayıcıyı başlatmak, bellekte yer ayırmak ve işlemciyi kullanmasını sağlamak için gerekli adımları atar.

### 2. **Programların Belleği Paylaşmasını Sağlama (Allowing programs to share memory):**

- İşletim sistemi, aynı anda çalışan birden fazla programın belleği güvenli ve verimli bir şekilde paylaşmasını sağlar. Bu, modern çoklu görev (multitasking) yeteneğinin temelidir.
- **Bellek yönetimi** çok kritik bir işlemdir. İşletim sistemi, her program için belirli bir bellek alanı ayırır ve bu bellek alanlarının çakışmasını önler. Aynı zamanda, programlar arasında veri paylaşımı gerektiğinde, güvenli bir şekilde bu verilerin paylaşımını organize eder.
- **Sanal bellek (virtual memory)** mekanizması, işletim sistemlerinin belleği daha verimli kullanmasına yardımcı olur. Fiziksel belleğin yetersiz kaldığı durumlarda, işletim sistemi bellekte yer açmak için geçici olarak diski kullanabilir.
- Örneğin, bilgisayarınızda bir metin editörü, tarayıcı ve müzik çalar aynı anda açıkken, işletim sistemi bu programların her birine bellekte güvenli bir alan tahsis eder.

### 3. **Programların Cihazlarla Etkileşimini Sağlama (Enabling programs to interact with devices):**

- İşletim sistemi, programların donanımla etkileşim kurabilmesini sağlar. Örneğin, bir programın yazıcınızda bir belge yazdırması gerektiğinde, bu işlemi doğrudan donanımla yapmak yerine işletim sistemi aracılığıyla gerçekleştirir.
- **Giriş/Çıkış yönetimi (Input/Output management)**, işletim sisteminin cihazlarla iletişim kurmasını sağlar. Bu, klavye, fare, diskler, ağ cihazları gibi çeşitli donanımlarla programların sorunsuz bir şekilde etkileşim kurmasını mümkün kılar.
- İşletim sistemi, bu cihazlardan gelen verileri alır ve gerekli programlara iletir, aynı zamanda programlardan gelen verileri cihazlara iletir. Bu şekilde programlar, yazıcıya veri gönderme, dosya okuma/yazma gibi işlemleri gerçekleştirebilir.
- Örneğin, bir tarayıcıya bir dosya indirirken işletim sistemi bu indirme işlemini disk sürücüsü ile koordine eder ve indirilen verilerin uygun bir şekilde kaydedilmesini sağlar.

### **İşletim Sisteminin Genel Sorumlulukları:**

- **Doğru ve Verimli Çalışmayı Sağlamak (Ensuring correct and efficient system operation):** İşletim sistemi, bilgisayarın kaynaklarını (CPU, bellek, depolama, ağ vs.) doğru ve verimli bir şekilde yönetir. Sistem kaynaklarının optimal bir şekilde kullanılması, tüm programların sorunsuz çalışmasını sağlar. Aynı zamanda sistemde hatalar oluştuğunda bunları tespit eder ve düzeltmek için önlemler alır.
- **Kaynak yönetimi:** İşlemci zamanı, bellek ve cihazlar gibi sınırlı kaynakları en verimli şekilde paylaştırarak, bilgisayarın aynı anda birden fazla programı (veya işlemi) çalıştırmasını sağlar.

### Sonuç:

İşletim sistemi, bilgisayarın **çekirdek yazılımı** olarak, programların kolayca çalıştırılmasını, bellek paylaşımını ve donanımlarla etkileşimini düzenler. Bu görevlerin tümü, sistemin **doğru** ve **verimli** çalışmasını sağlamak amacıyla yapılır.

---

**Sanalizasyon (Virtualization)**, işletim sisteminin (OS), fiziksel kaynakları alıp bunları daha kullanışlı, güçlü ve genelleştirilmiş bir sanal forma dönüştürdüğü bir kavramdır. Bu süreç, donanım kaynaklarının verimli kullanılması ve birden fazla programın veya kullanıcıların aynı kaynakları paylaşmasını sağlar. Şimdi bu süreci ve kavramı daha ayrıntılı açıklayalım:

### 1. **Fiziksel Kaynağın Sanal Forma Dönüştürülmesi:**

- İşletim sistemi, **fiziksel kaynakları** (işlemci, bellek, disk gibi donanımlar) soyutlayarak, bu kaynakların sanal bir temsilini oluşturur. Sanalizasyon sayesinde, bu fiziksel kaynaklar birden çok kullanıcı veya program tarafından paylaşılabilir ve her birine ayrı bir "sanal kaynak" olarak sunulabilir.

### Fiziksel Kaynaklar:

- **İşlemci (Processor):** Bir işletim sistemi, bir fiziksel işlemciyi birden çok sanal işlemciye ayırabilir. Böylece, birden fazla uygulama aynı anda çalışıyormuş gibi görünür. Örneğin, çoklu görev (multitasking) yaparken birden fazla uygulamanın aynı anda işlem yapması sağlanır.
- **Bellek (Memory):** Sanal bellek, işletim sisteminin fiziksel belleği (RAM) soyutlayarak her program için ayrı bir bellek alanı sağladığı bir tekniktir. Bu, programların fiziksel bellek sınırlarını aşmadan çalışabilmesine olanak tanır.
- **Disk:** Sanal diskler, bir fiziksel disk üzerinde birden çok sanal depolama alanı oluşturarak, farklı kullanıcıların veya uygulamaların bağımsız bir disk alanı varmış gibi çalışmasını sağlar. Örneğin, bir sanal makine (VM) farklı bir fiziksel disk kullanıyormuş gibi çalışabilir, ancak aslında aynı diskten paylaşımlı olarak yararlanır.

### 2. **Sanal Form Daha Güçlü ve Kullanımı Kolaydır:**

- Sanal form, fiziksel kaynağa göre daha esnek ve kullanışlıdır. İşletim sistemi, donanımın karmaşıklığını gizler ve kullanıcıya veya programlara daha basit bir arayüz sunar.
- **Daha güçlü:** Sanal makineler veya sanallaştırılmış kaynaklar, kullanıcıya fiziksel kaynaklardan daha fazla kontrol ve özgürlük sağlar. Örneğin, bir sanal makinede birden fazla işletim sistemi çalıştırılabilir veya farklı yazılım ortamları aynı fiziksel donanım üzerinde birbirinden bağımsız çalıştırılabilir.
- **Daha kolay:** Sanallaştırma sayesinde, kullanıcılar veya uygulamalar, fiziksel donanımın teknik detaylarıyla uğraşmadan kaynakları kullanabilir. Örneğin, programlar sanal belleği kullanarak verilerini yönetir, ancak fiziksel belleğin sınırlamalarıyla doğrudan karşılaşmazlar.

### 3. **İşletim Sistemine "Sanal Makine" (Virtual Machine) Olarak Atıfta Bulunulması:**

- İşletim sistemi bazen bir "sanal makine" olarak adlandırılır çünkü fiziksel kaynakları sanal bir forma dönüştürerek, her bir kullanıcıya veya programa bir sanal ortam sağlar. Bu, her programın fiziksel kaynakları doğrudan kullanıyormuş gibi hissetmesini sağlar, ancak aslında işletim sistemi bu kaynakların kullanımını denetler ve düzenler.
- Sanal makineler, tek bir fiziksel makine üzerinde birden fazla işletim sistemini veya uygulama ortamını bağımsız bir şekilde çalıştırma yeteneğine sahiptir. Örneğin, bir bilgisayar aynı anda hem Windows hem de Linux çalıştırabilir, her birini ayrı bir sanal makine üzerinde kullanabilir.

### Sanallaştırmanın Faydaları:

- **Kaynak Paylaşımı:** Birden fazla uygulama, sanal kaynakları kullanarak aynı donanımı paylaşabilir.
- **Verimlilik:** Fiziksel kaynaklar daha etkin bir şekilde kullanılır. Örneğin, birden fazla sanal makine, fiziksel kaynakları daha verimli paylaşarak sistemin genel performansını artırabilir.
- **Güvenlik:** Sanal makineler birbirinden izole edilmiştir, bu sayede bir sanal makinede meydana gelen bir hata veya güvenlik sorunu diğerlerini etkilemez.
- **Esneklik:** Sanal makineler, farklı donanım platformlarında taşınabilir ve kolayca yedeklenebilir, klonlanabilir veya yeniden yapılandırılabilir.

### Özet:

Sanallaştırma, işletim sisteminin fiziksel kaynakları soyutlayarak sanal kaynaklara dönüştürdüğü bir tekniktir. Bu sayede, kaynaklar daha esnek, güçlü ve kolay kullanılır hale gelir. İşletim sistemi, bu sanallaştırmayı yöneterek programların daha etkin çalışmasını sağlar ve fiziksel donanım kaynaklarının paylaşımını optimize eder.

---

### **İşletim Sistemi Bileşenleri**

İşletim sistemi, birçok önemli bileşen içerir:

### **1. Süreç Abstraksiyonu (Process Abstraction)**

- **Süreç (Process):** Çalışan bir programdır. Her süreç, işletim sistemi tarafından yönetilir ve her biri kendine ait bir CPU, bellek ve diğer kaynaklara sahip olduğu hissine kapılır.
- **Çoklu Süreç Yönetimi:** İşletim sistemi, CPU'yu birden fazla süreç arasında paylaştırır. Bu, birden fazla programın aynı anda çalışıyormuş gibi görünmesini sağlar.

### **2. Bellek Yönetimi (Memory Management)**

- İşletim sistemi, her sürecin kendine ait bir bellek alanına sahip olduğunu varsayar. Ancak aslında tüm süreçler aynı fiziksel bellek alanını paylaşır.
- OS, sanal adresler (virtual addresses) kullanarak her sürecin bellek alanını izler ve fiziksel bellek adreslerine çevirir. Bu, programların birbiriyle çakışmadan çalışabilmesini sağlar.

### **3. Aygıt Yönetimi (Device Management)**

- İşletim sistemi, disk, ağ kartı gibi harici aygıtları yönetmek için aygıt sürücüleri (device drivers) kullanır.
- Bu sürücüler, donanım aygıtlarıyla iletişim kurmak için gerekli olan komutları işletim sistemine iletir.

### **Sistem Çağrıları (System Calls)**

Sistem çağrıları, kullanıcıların işletim sistemine ne yapmasını istediğini bildirdiği bir yöntemdir. Örneğin:

- Program çalıştırma
- Belleğe erişim
- Aygıtlara erişim

Bu sistem çağrıları, işletim sisteminin kaynak yönetimini sağlamak için kullanılır.

---

### **Sanallaştırma (Virtualization)**

Sanallaştırma, fiziksel kaynakların (örneğin, işlemci, bellek, disk) sanal bir forma dönüştürülmesi anlamına gelir. İşletim sistemi, bir fiziksel CPU'yu sanki birden fazla sanal CPU varmış gibi kullanarak, birçok programın aynı anda çalışıyormuş gibi görünmesini sağlar. Örneğin:

- Tek bir işlemci (CPU) fiziksel olarak mevcutken, çok sayıda sanal CPU oluşturulabilir ve birçok program aynı anda çalışıyor gibi görünebilir.

---

### **Belleği Sanallaştırma (Virtualizing Memory)**

Fiziksel bellek, byte dizisi olarak düşünülür. Bir program, verilerini bellekte tutar ve bu verilere erişim sağlar. Bellek erişimi iki şekilde yapılır:

1. **Belleği Okuma (Load):** Bellekten veri almak için bir adres belirtir.
2. **Belleğe Yazma (Store):** Veriyi belirli bir adrese yazmak için adresi belirtir.

Her program, kendi sanal bellek alanına sahip olduğunu düşünür. Yani, iki farklı program aynı bellek adresini kullanıyormuş gibi görünse de, aslında işletim sistemi her birinin bellek alanını yönetir.

---

### **Eşzamanlılık (Concurrency) Problemi**

Eşzamanlılık, birden fazla işlemin aynı anda yürütülmesi anlamına gelir. İşletim sistemi, birçok şeyi aynı anda yönetir ve süreçler arasında geçiş yapar. Ancak eşzamanlılık bazı sorunları da beraberinde getirir:

- Örneğin, iki program aynı anda bir paylaşılan sayacı güncellemeye çalıştığında çakışma yaşanabilir. Bu durumda, her bir güncelleme için üç temel talimat vardır:
    1. Sayacın mevcut değerini bellekteki kaynaktan al.
    2. Bu değeri artır.
    3. Yeni değeri tekrar belleğe yaz.

Bu üç talimat atomik olarak çalışmadığı için (yani, tamamı bir bütün olarak gerçekleşmediği için) çakışma problemi ortaya çıkar.

---

### **Kalıcılık (Persistence)**

Kalıcılık, verilerin geçici olmayan (persistent) bir şekilde saklanması anlamına gelir. Örneğin, bilgisayar kapatıldığında bile verilerin kaybolmaması gerekir. İşletim sistemi, verilerin kalıcı olarak saklanması için aşağıdaki gibi süreçler uygular:

- **Girdi/Çıktı Aygıtları:** Donanım (örneğin, sabit disk, SSD) ile verilerin saklanmasını sağlar.
- **Dosya Sistemi:** Diskteki dosyaları yönetir ve kullanıcıların oluşturduğu dosyaları saklar.

İşletim sistemi, verilerin yazılması için şu adımları takip eder:

1. Diskte verinin nerede saklanacağına karar verir.
2. Altyapıdaki depolama aygıtına talimatlar gönderir.
3. Yazma işlemi sırasında sistem çökmesi durumlarını yönetir.

---

### **Tasarım Hedefleri (Design Goals)**

İşletim sistemleri, kullanıcı deneyimini ve sistem performansını artırmak için birkaç temel tasarım hedefini göz önünde bulundurur:

1. **Soyutlama Sağlamak:** Sistemi kullanıcılar için kolay ve erişilebilir hale getirmek.
2. **Yüksek Performans Sağlamak:** İşletim sistemi yükünü minimize etmek ve sanallaştırmayı sağlarken aşırı yüklenmelerden kaçınmak.
3. **Uygulamalar Arasında Koruma Sağlamak:** Bir uygulamanın hatalı çalışması durumunda diğer uygulamaları etkilememesi için izolasyon sağlamak.

Ayrıca, işletim sistemleri yüksek güvenilirlik, enerji verimliliği, güvenlik ve taşınabilirlik gibi diğer faktörleri de göz önünde bulundurur.

---

### **İşletim Sistemlerinin Tarihi**

İşletim sistemleri, bilgisayarların verimli bir şekilde çalışabilmesi için gerekli olan yazılımlardır. Tarihsel olarak, işletim sistemlerinin gelişimi birkaç önemli aşamadan geçmiştir.

### **1. Başlangıç Dönemi: Sadece Kütüphaneler**

- **Tek Program Çalıştırma:** İlk bilgisayarlar, sadece bir programı aynı anda çalıştırabiliyordu. Bu dönemde bir işletim sistemine ihtiyaç yoktu, çünkü her şey belirli kütüphaneler aracılığıyla yürütülüyordu.
- **Programlama:** Programlama genellikle kablolama (wiring) yoluyla yapılırdı. Örneğin, Harvard Mark I (1944) ve ENIAC (1945) gibi erken bilgisayarlar, yalnızca tek bir işlevi yerine getirmek için tasarlandılar.
- **Yazılım Kütüphaneleri:** Bilgisayarın belleğinde, çeşitli işlevleri yerine getirecek kütüphaneler bulunuyordu.

### **2. Toplu İşlem Dönemi: Batch Systems**

- **Toplu İşlem (Batch Processing):** İlk işletim sistemleri, insan operatörler tarafından kontrol edilen toplu işlem sistemleri olarak ortaya çıktı. Operatör, bir dizi işi hazırlayıp çalıştırırdı.
- **Delikli Kartlar:** Programlar, delikli kartlar üzerinde yazılıp işlenirdi. İşletim sistemi, önceki program tamamlandığında bir sonraki programı belleğe yüklerdi.
- **Disk Spooling:** Diskler üzerinde bir program çalışırken, başka programların yüklenmesi için disk üzerinde veri yazma işlemleri gerçekleştirilirdi. Bu, CPU’nun boşta kalmasını önlerdi.

### **3. Çoklu Programlama Dönemi: Multiprogramming**

- **Çoklu İşlem Yükleme:** Çoklu programlama işletim sistemleri, birden fazla çalışabilir iş yükünü bellekte aynı anda tutarak sistem verimliliğini artırmayı hedefledi. Bir iş girdi/çıktı (I/O) beklerken, CPU başka bir iş üzerinde çalışıyordu.
- **Asenkron I/O:** Bu, cihazların I/O işlemlerinin tamamlanıp tamamlanmadığını bilmemizi sağlayacak bir yol gerektiriyordu. Amaç, sistemin toplam verimliliğini (throughput) artırmaktı.

### **4. Zaman Paylaşımı Dönemi: Timesharing**

- **Etkileşimli Kullanım:** Zaman paylaşım sistemleri, çoklu terminalin bir makineye bağlı olduğu bir yapı sunarak, her kullanıcıya makinenin tamamına sahip olma hissi veriyordu.
- **Zaman Dilimi (Timeslicing):** CPU, kullanıcılar arasında adil bir şekilde bölünerek paylaştırılıyordu. Eğer bir iş gerçekten etkileşimli ise, CPU hızlı bir şekilde kullanıcılar arasında geçiş yapabiliyordu.
- **MIT Multics:** 1960’ların ortalarında, Multics sistemi, zaman paylaşımlı sistemlerin öncüsü oldu. Günümüz modern işletim sistemi kavramlarının çoğu burada gelişti.

### **5. Kişisel Bilgisayar Dönemi: Personal Computing**

- **Kişisel Bilgisayarların Yükselişi:** 1980’lerde kişisel bilgisayarlar (PC'ler) pazarında devrim yarattı. CP/M, ilk kişisel bilgisayar işletim sistemlerinden biriydi.
- **MS-DOS’un Gelişimi:** IBM, PC'leri için bir işletim sistemine ihtiyaç duyuyordu. Bill Gates, 86-DOS’u satın alarak MS-DOS’u geliştirdi. DOS, temelde bir alt yordam (subroutine) kütüphanesi olarak düşünülebilir.

### **6. Paralel Bilgi İşlem ve Kümeleme: Parallel Computing and Clusters**

- **Yüksek Performanslı Uygulamalar:** Bilimsel uygulamalar, aynı anda birden fazla CPU kullanarak büyük veri kümeleri üzerinde işlem yapmak istiyor.
- **Paralel İşleme:** Paralel işlem, programı paralel aktivitelere bölmeyi gerektirir. Bu süreçte, işlemciler arasında hızlı bir iletişim sağlanması gerekir.
- **Farklı Paralel Makineler:**
    - **SMP (Simetrik Çoklayıcılar):** Birden fazla CPU’nun aynı belleğe erişimini sağlar.
    - **MPP (Kütleli Paralel İşlemciler):** Her CPU’nun kendi belleği vardır.
    - **Kümeleme (Clusters):** Birçok sıradan makinayı hızlı bir ağ ile birleştirir.

### **7. Dağıtık İşletim Sistemleri: Distributed OS**

- **Coğrafi Olarak Dağıtılmış Kaynaklar:** Dağıtık işletim sistemleri, LAN üzerindeki iş istasyonları ve İnternet üzerindeki sunucular gibi kaynakları kullanmayı amaçlar.
- **İletişim Desteği:** Uygulamalar arası iletişimi destekler. Tek bir makinadaki işlemler arası iletişim (message passing) ve paylaşılan bellek (shared memory) gibi yöntemler kullanılır.
- **Ağ Protokolleri:** TCP/IP, Java RMI ve .NET SOAP gibi protokoller ile birden fazla makine arasında iletişim sağlanır.

### **8. Gömülü İşletim Sistemleri: Embedded OS**

- **Yaygın Bilgisayarların Yükselişi:** Küçük bilgisayarların her yerde var olmasıyla, gömülü sistemler (örneğin, PDA’lar, cep telefonları) popülerlik kazandı.
- **Sınırlı Kaynaklar:** Gömülü sistemler, sınırlı donanım kaynakları (düşük bellek, yavaş işlemciler) ile çalışır.

### **9. Modern İşletim Sistemleri: DOS, Windows, MAC, UNIX, LINUX**

- **Çeşitli İşletim Sistemleri:** Günümüzde birçok farklı işletim sistemi bulunmaktadır. Her biri farklı ihtiyaçları karşılamak için farklı özellikler sunar.

### **İşletim Sistemlerinin Temel İşlevleri**

- **CPU Yönetimi:** Kodları veri ile yürütmek.
- **Bellek Yönetimi:** Kodları ve verileri okuyup yazmak.
- **Depolama Yönetimi:** Kodları kalıcı olarak saklamak.

### **Sonuç**

İşletim sistemleri, bilgisayarların verimli çalışmasını sağlamak için kritik bir rol oynar. Tarih boyunca geçirdiği evrim, günümüzdeki modern sistemlerin temelini oluşturur. Her aşama, bilgisayarların nasıl daha etkili kullanılabileceğini ve kullanıcı deneyiminin nasıl iyileştirilebileceğini göstermektedir.

---

İşletim sistemi, aynı anda çalıştırılmak isteyen iki program olduğunda hangi programın öncelikli olarak çalıştırılacağını belirleyen bir mekanizmaya sahiptir. Bu tip kararlar, işletim sisteminin **planlama (scheduling)** stratejileri ile ilgilidir.

### **Planlama (Scheduling) ve Politikalar**

İşletim sistemi, aynı anda çalışmak isteyen birden fazla program olduğunda bunlar arasındaki kaynak dağılımını yönetir. Bu, CPU zamanının, belleğin ve diğer donanım kaynaklarının paylaştırılmasını içerir. İşte bu süreçte, işletim sistemi **mekanizmalar** ve **politikalar** kullanır:

1. **Mekanizmalar (Mechanisms):**
    - İşletim sisteminin, donanım kaynaklarını (CPU, bellek, disk gibi) nasıl yönettiğine dair **temel araçlardır**. Örneğin, çoklu programların aynı anda çalışabilmesi için **çoklu görev (multitasking)** ve **işlemler arası geçiş (context switching)** gibi mekanizmalar kullanılır.
2. **Politikalar (Policies):**
    - **Politikalar**, bu mekanizmaların ne zaman ve nasıl kullanılacağına karar veren kurallardır. İşletim sistemi politikaları, kaynakların nasıl tahsis edileceği, hangi programın öncelikli çalışacağı gibi sorulara cevap verir. Örneğin, iki program CPU'yu aynı anda kullanmak istiyorsa, hangi programın önce çalışacağına bir **planlama politikası** karar verir.

### **Planlama (Scheduling) Politikaları:**

İşletim sistemi, kaynakları en verimli şekilde kullanmak için çeşitli planlama politikaları uygular. Bu politikalar, sistemin ihtiyaçlarına, kullanıcı gereksinimlerine ve performans hedeflerine göre değişebilir. İşte bazı yaygın planlama politikaları:

1. **İlk Gelen İlk Çıkar (First Come, First Served - FCFS):**
    - Programlar, işlemciyi kullanmak için sıraya girerler. İlk sıradaki program işlendikten sonra bir sonraki programa geçilir. Bu en basit planlama stratejilerinden biridir, ancak verimlilik açısından her zaman en iyi seçenek değildir.
2. **En Kısa İş İlk (Shortest Job First - SJF):**
    - İşletim sistemi, işlemci süresi en kısa olan programı öncelikli olarak çalıştırır. Bu, genel sistem performansını optimize etmek için kullanılan bir politikadır, ancak her zaman adil olmayabilir, çünkü uzun süreli işler daha uzun süre bekleyebilir.
3. **Öncelikli Planlama (Priority Scheduling):**
    - Her programa bir öncelik değeri atanır ve yüksek öncelikli programlar işlemciyi düşük öncelikli programlardan önce alır. Bu politika, kritik öneme sahip görevlerin zamanında tamamlanmasını sağlar. Ancak düşük öncelikli programlar "aç kalabilir" (starvation), yani çok uzun süre işlemciyi alamayabilir.
4. **Zaman Dilimli Planlama (Round Robin):**
    - Her programa eşit miktarda CPU süresi tahsis edilir. Programlar işlemciyi kısa bir süre kullanır ve süreleri dolduğunda sıradaki programa geçilir. Bu politika, çoklu kullanıcı sistemlerinde veya interaktif sistemlerde adil bir kaynak paylaşımı sağlar.
5. **Çok Seviyeli Kuyruk (Multilevel Queue):**
    - Farklı önceliklere sahip işler için ayrı kuyruklar kullanılır. Örneğin, sistem işlemleri yüksek öncelik kuyruğunda, kullanıcı işlemleri ise daha düşük öncelik kuyruğunda olabilir. İşletim sistemi, her kuyruktaki işlere farklı şekilde davranabilir.
6. **Multilevel Feedback Queue:**
    - Çok seviyeli kuyruğa ek olarak, bu politika, işlerin kuyruklar arasında hareket edebilmesine olanak tanır. Örneğin, bir iş belirli bir süre işlemciyi kullandıktan sonra daha düşük öncelikli bir kuyruktan çalıştırılmaya devam edebilir.

### **Politikaların Kullanıldığı Diğer Yerler:**

Politikalar sadece CPU planlamasında değil, aynı zamanda işletim sisteminin diğer birçok alanında da kullanılır:

- **Bellek Yönetimi:** Hangi programların fiziksel bellekte kalacağına ve hangi programların sanal belleğe taşınacağına karar verilir.
- **Dosya Sistemi Yönetimi:** Dosyalara erişim sırası ve hangi kullanıcının dosyalara öncelikli erişim sağlayacağı politikalarla belirlenir.
- **Giriş/Çıkış (I/O) Planlaması:** Hangi programın önce bir disk okuma/yazma işlemi yapacağına karar verilir.

### **Sonuç:**

İki program aynı anda çalışmak istediğinde, işletim sistemi bir **planlama politikası** kullanarak hangi programın önce çalışacağına karar verir. Bu politikalar, kaynakların adil, verimli ve optimal bir şekilde paylaşılmasını sağlamak için tasarlanmıştır. Politika seçimi, işletim sisteminin performansını ve kullanıcı deneyimini doğrudan etkileyebilir.

---

## Privilege level

İşletim sistemlerinde **Privilege Level (Ayrıcalık Seviyesi)**, bir işlemci ya da bir işletim sisteminin birimlerinin sahip olduğu erişim haklarını ve izin seviyelerini tanımlar. Bu kavram, bilgisayar sistemlerinin güvenliğini sağlamak ve sistem kaynaklarını korumak amacıyla kullanılır. Privilege level, hangi işlemlerin hangi kaynaklara, donanım bileşenlerine ya da yazılım seviyelerine erişebileceğini belirler.

Genellikle **Ring (Halka)** modeli olarak adlandırılan bir yapı kullanılır ve bu modelde ayrıcalık seviyeleri bir dizi "halka" ile ifade edilir:

### Privilege Level Halka Modeli

1. **Ring 0 (Çekirdek Seviyesi / Kernel Mode)**:
    - En yüksek ayrıcalık seviyesidir.
    - İşletim sisteminin çekirdeği ve donanım ile doğrudan iletişime geçmesi gereken bileşenler (örneğin sürücüler) bu seviyede çalışır.
    - Tüm sistem kaynaklarına ve donanıma sınırsız erişimi vardır.
    - Kernel modu, düşük seviyeli sistem kontrolü gerektiren görevler için kullanılır (bellek yönetimi, CPU yönetimi, cihaz sürücüsü işlemleri vb.).
2. **Ring 1 (Çekirdeğe Yakın Sistem İşlemleri)**:
    - Çekirdeğe yakın işletim sistemi servisleri ve işletim sisteminin bazı kritik bileşenleri bu seviyede çalışır.
    - Bu halka, işletim sistemine çekirdek dışındaki bazı işlevler için ayrıcalıklı erişim sunar (modern işletim sistemlerinde sık kullanılmaz).
3. **Ring 2 (Cihaz Sürücüleri ve Servisler)**:
    - İşletim sisteminin cihaz sürücüleri veya servisleri bu seviyede çalışabilir.
    - Donanımla doğrudan etkileşime geçen ama tam çekirdek yetkisine sahip olmayan işlemler bu seviyede yer alabilir (modern sistemlerde pek kullanılmaz).
4. **Ring 3 (Kullanıcı Modu / User Mode)**:
    - En düşük ayrıcalık seviyesidir.
    - Kullanıcı uygulamaları bu seviyede çalışır (tarayıcılar, ofis uygulamaları, oyunlar vb.).
    - Sistem kaynaklarına erişimleri sınırlıdır ve doğrudan donanıma veya çekirdek işlevlerine erişimleri yoktur. İşlemlerini işletim sistemi aracılığıyla gerçekleştirirler.
    - Eğer bir kullanıcı modu uygulaması, çekirdekte yapılması gereken bir işlem (örneğin donanım erişimi) istiyorsa, bu talep çekirdek moduna iletilir ve çekirdek tarafından kontrol edilir.

### Neden Privilege Level (Ayrıcalık Seviyesi) Kullanılır?

- **Güvenlik**: Yüksek ayrıcalık gerektiren işlemler yalnızca güvenilen, sistemin çekirdeği tarafından kontrol edilen kodlar tarafından gerçekleştirilir. Bu, kötü amaçlı yazılımların veya hatalı programların doğrudan sistem kaynaklarına zarar vermesini önler.
- **Stabilite**: Kullanıcı modundaki uygulamaların sistemin kritik bileşenlerine erişimi sınırlı olduğundan, bir uygulamanın çökmesi ya da hatalı çalışması sistemin tamamını etkilemez.
- **Kontrol**: İşletim sistemi, hangi seviyedeki yazılımın hangi kaynaklara erişebileceğini denetler. Bu, işletim sistemi ve donanımın uyumlu bir şekilde çalışmasını sağlar.

### Örnek:

Bir bilgisayar oyunu (kullanıcı modu) sistemin ses donanımına doğrudan erişemez. Eğer oyun ses donanımını kullanmak istiyorsa, bu isteği işletim sistemine iletir. İşletim sistemi ise bu isteği uygun görürse, Ring 0'daki çekirdek modunu kullanarak donanıma erişir ve isteği gerçekleştirir.

Modern işletim sistemlerinde güvenliği artırmak için bu privilege level sistemi sıkı bir şekilde uygulanır. Linux, Windows ve diğer büyük işletim sistemleri bu modeli kullanarak sistemdeki işlemleri güvenli ve kontrollü bir şekilde yürütürler.

---

### 1. **Kernel Mode (Çekirdek Modu)**:

- **Ring 0** olarak bilinir.
- İşletim sisteminin çekirdeği (kernel) burada çalışır.
- İşlemcinin tüm komut setlerine ve sistem kaynaklarına (bellek, donanım, giriş/çıkış aygıtları) tam erişim sağlar.
- Donanımla doğrudan iletişim kurabilen sürücüler ve düşük seviyeli işlemler bu modda çalışır.
- Eğer kernel modunda bir hata meydana gelirse, tüm sistem çöker (blue screen gibi).

### 2. **User Mode (Kullanıcı Modu)**:

- **Ring 3** seviyesidir.
- Kullanıcı uygulamaları (tarayıcılar, oyunlar, ofis uygulamaları vb.) bu modda çalışır.
- Kullanıcı modundaki programlar doğrudan donanıma veya çekirdek işlevlerine erişemezler. İhtiyaç duydukları kaynaklara erişmek için işletim sistemi aracılığıyla sistem çağrıları yaparlar.
- Eğer bir kullanıcı modunda çalışan program çökerse, sadece o program etkilenir, sistemin tamamı etkilenmez.

### Kernel ve User Mode'un Farkı Nedir?

- **Kernel Mode**: Sistemin tam kontrolüne sahiptir ve her türlü donanım kaynağına erişebilir. Çekirdek modunda çalışan kod hatalıysa, sistemin tamamı tehlikeye girebilir.
- **User Mode**: Güvenlik ve stabilite açısından daha kısıtlıdır. Kullanıcı modunda çalışan programlar donanıma ve kritik sistem kaynaklarına doğrudan erişim sağlayamaz. Böylece kullanıcı uygulamaları sistemin geri kalanını bozamaz.

### Neden İkiye Ayrılır?

Bu iki mod arasındaki ayrımın temel nedeni **güvenlik** ve **sistem kararlılığı**dır. Çekirdek modunda çalışan kodlar doğrudan donanıma ve sistemin tüm kritik işlevlerine erişebildiği için çok güçlüdür, ancak bu aynı zamanda hatalara veya kötü amaçlı kullanıma açık olma riskini de getirir. Kullanıcı modunda çalışan programlar ise çok daha kısıtlı bir ortamda çalıştıkları için sistemin genel güvenliğini korur.

Bu nedenle, modern işletim sistemlerinde kullanıcı uygulamaları, çekirdek ile etkileşim kurmak istediklerinde sadece **sistem çağrıları** yaparlar ve çekirdek bu talepleri değerlendirir. Bu da sistemin güvenli ve stabil kalmasını sağlar.