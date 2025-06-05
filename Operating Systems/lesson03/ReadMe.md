# 3. Hafta

### Birçok CPU İllüzyonunu Nasıl Sağlayabiliriz?

### CPU Sanallaştırması

İşletim sistemleri, birden fazla sanal CPU'nun var olduğu izlenimini oluşturmak için CPU sanallaştırması yaparlar. Bu, bir fiziksel CPU'nun birden fazla işlem tarafından kullanılıyormuş gibi görünmesini sağlar. Sanal CPU'lar, kullanıcıların çoklu görev yapabilmesine ve sistem kaynaklarını daha verimli bir şekilde kullanabilmesine olanak tanır.

### Zaman Paylaşımı

Zaman paylaşımı, işletim sisteminin bir süreci belirli bir süre çalıştırdıktan sonra durdurup başka bir süreci çalıştırdığı bir tekniktir. Bu şekilde, CPU'nun çalışma süresi farklı süreçler arasında paylaştırılır. Zaman paylaşımının en büyük avantajı, kullanıcıların birden fazla uygulamayı aynı anda çalışıyormuş gibi deneyimlemeleridir. Ancak, her bir süreç zaman dilimini paylaşmak zorunda olduğu için, her bir işlem daha yavaş çalışır. Yani, CPU'nun aynı anda birçok süreç tarafından kullanılmaya çalışılması, her sürecin daha az zaman dilimi almasına neden olur.

**Potansiyel Maliyet: Performans**
Zaman paylaşımında her bir sürecin performansı düşebilir, çünkü işlemciyi paylaşan süreçler birbirine zaman ayırır. Bu durum, genel sistem performansını etkileyebilir. Daha fazla süreç çalıştırıldığında, her birinin CPU'dan alabileceği zaman dilimi azalır. Dolayısıyla, daha fazla zaman paylaşımı, her sürecin daha yavaş çalışmasına neden olur.

### Zaman Paylaşımı vs. Mekân Paylaşımı

Zaman paylaşımı, kaynakları paylaştırmanın temel bir yöntemidir. Bu teknik, bir kaynağın (örneğin CPU veya ağ bağlantısı) öncelikle bir varlık tarafından, ardından başka bir varlık tarafından ve bu şekilde devam ederek kullanılmasını sağlar. Zaman paylaşımının bir karşıtı olan mekân paylaşımında, bir kaynak fiziksel olarak kullanmak isteyenler arasında bölünmüştür.

Örneğin, disk alanı doğal olarak mekân paylaşımı yapılan bir kaynaktır. Bir blok bir dosyaya atandıktan sonra, bu blok genellikle başka bir dosyaya atanmaz; yani, kullanıcı orijinal dosyayı silene kadar, aynı disk alanı başka bir dosya için kullanılamaz. Bu durum, dosya sistemlerinin veri bütünlüğünü sağlamak için önemlidir.

### Detaylı Açıklama

- **CPU Sanallaştırması**: Modern işletim sistemleri, bir fiziksel CPU'yu birden fazla sanal makineye ayırarak kaynakları verimli bir şekilde yönetir. Bu, sunucu sanallaştırması ve bulut bilişim uygulamalarında sıkça kullanılır. Örneğin, bir sunucuda birden fazla sanal makine çalıştırmak, donanım maliyetlerini azaltırken esnekliği artırır.
- **Zaman Paylaşımı**: Zaman paylaşımı, çoklu görevlerin yönetiminde kritik bir rol oynar. İşletim sistemleri, her bir işleme CPU süresi tahsis ederken, bu süreyi genellikle önceden belirlenmiş zaman dilimleri (quantum) ile belirler. Bu sayede, sistem kullanıcıları birbirinden bağımsız olarak farklı uygulamalar üzerinde çalışabiliyor gibi hissederler. Ancak, zaman dilimlerinin çok kısa olması durumunda, bu paylaşımlar "bağlantı kaybı" olarak adlandırılan bir duruma yol açabilir; bu da, işlemlerin sürekli durdurulup yeniden başlatılmasından dolayı performans kaybı yaratır.
- **Performans Maliyeti**: Zaman paylaşımı performansı etkilerken, işlemcinin toplam yükü ve mevcut süreç sayısı da önemli bir faktördür. Çok sayıda süreç çalıştırmak, işlem başına daha az CPU süresi tahsis edilmesine neden olur; bu da genel sistemin performansını etkiler.
- **Zaman Paylaşımı ile Mekân Paylaşımı**: Zaman paylaşımı, işlemcilerin zaman dilimlerine dayalı olarak paylaştırılmasını sağlarken, mekân paylaşımı fiziksel kaynakların bölünmesini içerir. Bu, dosya sistemleri gibi belirli alanlarda, verilerin nerede saklanacağını belirlemek için kullanılır. Disk alanı, genellikle mekân paylaşımını temsil eder; dosyalar oluşturulduğunda belirli bir alan tahsis edilir ve bu alan, dosya silinene kadar başka dosyalara atanmaz.

---

### CPU Sanallaştırması

### CPU Sanallaştırmasını Uygulamak

CPU sanallaştırması uygulamak için işletim sisteminin hem düşük seviyeli mekanizmalara hem de yüksek seviyeli zekâya ihtiyaç duyduğu ifade edilmektedir. Bu iki unsur, sanallaştırmanın etkili bir şekilde gerçekleştirilmesi için gereklidir.

**Düşük Seviyeli Mekanizmalar**
Düşük seviyeli mekanizmalar, gerekli bir işlevselliği sağlamak için kullanılan temel yöntemler veya protokollerdir. Bu mekanizmalar, işletim sisteminin işlemcinin kaynaklarını yönetmesini ve çoklu görevleri etkili bir şekilde gerçekleştirmesini sağlar.

Örneğin, daha sonra öğreneceğimiz gibi, bir bağlam geçişini (context switch) uygulamak, işletim sisteminin belirli bir CPU'da bir programı durdurup başka bir programı çalıştırabilme yeteneği kazandırır. Bu bağlam geçişi, işletim sisteminin zaman paylaşım mekanizması olarak tüm modern işletim sistemlerinde kullanılır.

### Yüksek Seviyeli Zekâ tekrar policies

Yüksek seviyeli zekâ, işletim sisteminin bu düşük seviyeli mekanizmaları etkili bir şekilde nasıl kullanacağını belirler. Bu, süreçlerin yönetimi, önceliklendirme ve kaynak tahsisi gibi karmaşık karar verme süreçlerini içerir. İşletim sistemi, hangi süreçlerin ne zaman çalıştırılacağına, hangi kaynakların paylaşılacağına ve süreçlerin nasıl önceliklendirileceğine dair kararlar alarak, kullanıcı deneyimini optimize eder.

### Detaylı Açıklama

- **Düşük Seviyeli Mekanizmalar**: CPU sanallaştırmasının temelini atan düşük seviyeli mekanizmalar, bellek yönetimi, işlemci zamanlaması ve bağlam geçişi gibi işlevleri içerir. Bu mekanizmalar, işletim sisteminin fiziksel donanımı sanal kaynaklar olarak kullanabilmesini sağlar. Örneğin, bağlam geçişi, CPU’nun bir süreçten diğerine geçiş yapmasını sağlayarak kullanıcıların birden fazla uygulamayı aynı anda kullanıyormuş gibi hissetmesini sağlar. Bu süreç, CPU'nun mevcut durumunu (register değerleri, program sayacı vb.) kaydedip yeni bir süreç için bu durumun yüklenmesini gerektirir.
- **Yüksek Seviyeli Zekâ**: Yüksek seviyeli zekâ, işletim sisteminin kaynakları etkin bir şekilde yönetmesini sağlayan algoritmalar ve stratejileri içerir. Bu, zaman paylaşımının nasıl yapılacağı, süreçlerin nasıl önceliklendirileceği ve kaynakların ne zaman serbest bırakılacağı gibi kararların alınmasını içerir. Yüksek seviyeli zekâ, işlem önceliği belirleme, bekleyen süreçlerin yönetimi ve performans optimizasyonu gibi karmaşık görevleri yerine getirir.

### Örnek Senaryo

Düşük seviyeli mekanizmalar, CPU’nun her bir sürece belirli bir zaman dilimi ayırmasını sağlarken, yüksek seviyeli zekâ, bu süreçlerin ne zaman çalıştırılacağını ve nasıl yönetileceğini belirler. Örneğin, bir işletim sistemi bir web tarayıcısının açık olduğu ve arka planda bir indirme işlemi gerçekleştirildiği bir senaryoda, tarayıcı ve indirme işlemi arasında sürekli olarak bağlam geçişi yapabilir. Bu geçişler sırasında, işletim sistemi her bir süreç için en uygun zaman dilimlerini belirleyerek kullanıcı deneyimini en üst düzeye çıkarmaya çalışır.

İşletim sistemlerinde **CPU sanallaştırma** (CPU virtualization), tek bir fiziksel işlemci (CPU) varmış gibi görünmesine rağmen, birden fazla programın aynı anda çalışıyormuş gibi görünmesini sağlayan bir tekniktir. Bu illüzyon, işletim sisteminin hem **düşük seviyeli mekanizmalar** (low-level mechanisms) hem de **yüksek seviyeli zeka** (high-level intelligence) kullanmasıyla gerçekleştirilir.

### Temel Kavramlar:

1. **Mekanizmalar** (Mechanisms): Mekanizmalar, bir işlevi yerine getirmek için kullanılan düşük seviyeli yöntemler veya protokollerdir. İşletim sistemi, bu mekanizmaları kullanarak CPU sanallaştırmasını hayata geçirir. Örneğin:
    - **Bağlam değişimi** (Context switch): İşletim sisteminin bir programın çalışmasını durdurup, başka bir programı çalıştırmasını sağlayan bir mekanizmadır. Bu sayede **zaman paylaşımı** (time-sharing) gerçekleştirilir. Modern işletim sistemlerinde yaygın olarak kullanılan bir tekniktir.
2. **Zeka** (Intelligence): Bu, işletim sisteminin hangi programın ne zaman çalıştırılacağı gibi kararları vermesini sağlar. Yani, CPU'yu kimin ne zaman kullanacağına dair stratejileri oluşturur.

### CPU Sanallaştırma Nasıl Gerçekleşir?

İşletim sistemi, CPU'yu farklı programlar arasında paylaşmak için **zaman dilimleme** (time slicing) adı verilen bir yöntem kullanır. Bu, her programın belirli bir süre CPU'yu kullanmasına ve daha sonra bir diğerine geçmesine olanak tanır. Bu geçişler, **bağlam değişimi** (context switching) ile sağlanır, böylece bir programın durdurulduğu yerden daha sonra devam etmesi mümkün olur.

CPU sanallaştırma, aynı fiziksel işlemci üzerinde birden fazla programın verimli bir şekilde çalışmasını sağlar ve kullanıcıya programların sanki eş zamanlı çalışıyormuş gibi görünmesini sağlar.

---

**CPU sanallaştırma** (CPU virtualization) işletim sistemlerinin (OS) önemli işlevlerinden biridir ve CPU’yu birden fazla program arasında paylaştırarak bu programların aynı anda çalışıyormuş gibi görünmesini sağlar. Bunu yapmak için işletim sisteminin hem düşük seviyeli **mekanizmalara** (mechanisms) hem de yüksek seviyeli **politikalar**a (policies) ihtiyacı vardır. Şimdi bu kavramları daha derinlemesine inceleyelim.

### Mekanizmalar (Mechanisms):

Mekanizmalar, CPU sanallaştırmasını gerçekleştirmek için işletim sisteminin kullandığı düşük seviyeli yöntemlerdir. **Bağlam değişimi** (context switch) bunlardan biridir. Bu mekanizma, işletim sisteminin bir programın çalışmasını durdurup, başka bir programı çalıştırmasını sağlar. Bu sayede CPU, bir programın işlemini kaydeder, durdurur ve sonra başka bir programın işlemine geçer. Her program kısa bir süre çalıştıktan sonra CPU'dan çıkarılır ve sıradaki program çalıştırılır. Böylece, CPU’yu kullanan her program belirli bir **zaman diliminde** (time slice) çalışır.

Örneğin:

- Bir programın o anki durumu (CPU kayıtları, bellek durumu vs.) saklanır.
- Başka bir programın durumu yüklenir ve CPU üzerinde çalıştırılır.
- Bir sonraki bağlam değişimi sırasında, ilk programın saklanan durumu tekrar yüklenerek kaldığı yerden devam etmesi sağlanır.

Bu döngü sayesinde kullanıcılar, sanki birden fazla programın aynı anda çalışıyormuş gibi bir deneyim yaşar.

### Politikalar (Policies):

İşletim sistemi yalnızca mekanizmalar kullanarak CPU sanallaştırmayı gerçekleştiremez; aynı zamanda **politikalar** (policies) adı verilen karar verme süreçlerini de kullanır. Politikalar, CPU'nun hangi program tarafından ne zaman kullanılacağını belirleyen **algoritmalar**dır.

Birden fazla program aynı anda CPU’ya erişmek istediğinde, hangi programın CPU'yu kullanacağına karar vermek için işletim sistemi bir **zamanlama politikası** (scheduling policy) uygular. Bu politikalar, belirli ölçütlere dayanarak kararlar verir:

- **Geçmiş bilgileri** (historical information): Hangi programın en son ne kadar süre çalıştığına bakarak, CPU'yu bir sonraki programa verip vermeyeceğine karar verir. Örneğin, son bir dakikada hangi programın daha çok CPU zamanı aldığı bilgisi burada kullanılabilir.
- **İş yükü bilgisi** (workload knowledge): Çalışan programların türü de göz önünde bulundurulur. Bazı programlar çok fazla işlemci gücü gerektirirken, bazıları daha az gereksinim duyar.
- **Performans hedefleri** (performance metrics): İşletim sistemi hangi performans ölçütüne göre optimize edileceğine de karar verir. Örneğin:
    - **Etkileşimli performans** (interactive performance) hedefleniyorsa, kullanıcının aktif olarak kullandığı uygulamalar öncelik alır.
    - **Verimlilik** (throughput) optimize edilmek isteniyorsa, sistemin genel iş yükünü hızlı bir şekilde işleyip işleyemediğine bakılır.

### Ek Bilgiler:

- **Öncelikli Zamanlama** (Priority Scheduling): Bazı programların daha acil işleri olabilir, bu yüzden işletim sistemi bu programlara öncelik verir. Örneğin, bir kullanıcı tarayıcıda bir bağlantıya tıkladığında, bu işlem hemen yanıt vermelidir. Böyle bir durumda işletim sistemi, bu talebi yerine getirmek için o an çalışan başka bir programı durdurabilir.
- **Yuvarlak Robin Zamanlaması** (Round Robin Scheduling): Bu, CPU'nun farklı programlara adil bir şekilde paylaştırılmasıdır. Her programa belirli bir süre (zaman dilimi) ayrılır ve bu süre dolunca sıradaki programa geçilir. Bu yöntem, özellikle **çoklu görev** (multitasking) için yaygın bir şekilde kullanılır.

### Özet:

CPU sanallaştırma, modern işletim sistemlerinin **çoklu görev** (multitasking) yeteneğini sağlayan temel bir özelliktir. İşletim sisteminin kullandığı **mekanizmalar** CPU'yu verimli bir şekilde paylaştırırken, **politikalar** bu paylaştırmanın nasıl yapılacağına karar verir. Bu süreç, bilgisayar kullanıcılarının birden fazla işlemi aynı anda sorunsuzca yapmalarını sağlar.

---

**CPU sanallaştırma** (CPU virtualization) sürecinde, işletim sistemlerinde yaygın olarak kullanılan önemli bir tasarım ilkesi **politika** (policy) ve **mekanizmayı** (mechanism) birbirinden ayırmaktır. Bu ayrım, işletim sisteminin karmaşık görevleri daha modüler ve esnek bir şekilde gerçekleştirmesini sağlar. Şimdi, bu kavramları daha ayrıntılı açıklayalım.

### Politika ve Mekanizmanın Ayrılması (Separation of Policy and Mechanism):

Bir işletim sistemi tasarımında, **mekanizmalar** sistemin bir işlemi **nasıl** gerçekleştirdiğini, **politikalar** ise bu işlemin **hangi** koşullarda gerçekleştirileceğini belirler. Bu ayrım, farklı karar verme süreçlerinin ve işlevlerin kolayca değiştirilip uyarlanabilmesine olanak tanır.

- **Mekanizma** (Mechanism): Bir görevin nasıl yapılacağını tanımlayan düşük seviyeli işlevlerdir. Örneğin, **bağlam değişimi** (context switch) mekanizması, bir programın CPU’yu bırakıp diğerinin çalışmasını sağlar. Buradaki önemli soru "işletim sistemi bağlam değişimini **nasıl** gerçekleştirir?"dir. Yani, teknik anlamda işletim sisteminin donanımla nasıl etkileşime girdiği, CPU’nun durumu nasıl kaydedildiği ve yeniden yüklendiği gibi detaylarla ilgilenir.
- **Politika** (Policy): Hangi görevin ne zaman yapılacağını belirleyen yüksek seviyeli kararlardır. Bir politika, işletim sisteminin CPU üzerinde hangi programı çalıştıracağını belirler. Burada sorulan soru "işletim sistemi **hangi** programı çalıştırmalı?"dır. Yani, hangi programın CPU’yu alacağı, hangi programın ne kadar süre çalışacağı ve CPU'yu kullanma önceliğinin kime verileceği gibi kararları politikalar belirler.

### Politika ve Mekanizmanın Ayrılmasının Faydaları:

Bu iki kavramın birbirinden ayrı tutulması, işletim sistemine **modülerlik** (modularity) kazandırır. Bu sayede:

- **Esneklik**: Mekanizmayı değiştirmeden, sadece politika üzerinde değişiklik yaparak sistemin davranışını kolayca değiştirebilirsiniz. Örneğin, bir sistemde zamanlama politikasını değiştirmek, mekanizmanın çalışma şeklini etkilemez. Farklı programların CPU'yu kullanım sıklığını değiştirmek için sadece zamanlama politikasını (scheduling policy) ayarlamak yeterli olur.
- **Yeniden Kullanılabilirlik**: Aynı mekanizmalar, farklı politikalarla birlikte kullanılabilir. Bu da yazılım geliştirmede tekrar kullanılabilir bileşenler oluşturmayı kolaylaştırır.

### Örnek:

- **Mekanizma**: İşletim sisteminde **bağlam değişimi** (context switch) bir mekanizmadır. Bir programın CPU'yu kullanması bittiğinde, işletim sistemi bu programın mevcut durumunu (CPU kayıtları, bellek durumu vs.) kaydeder ve başka bir programın durumunu yükler. Bu süreç, programlar arasında geçiş yapılmasını sağlar.
- **Politika**: CPU'da hangi programın çalışacağına karar veren **zamanlama politikası**dır (scheduling policy). Örneğin, işletim sistemi şu anda kullanıcı arayüzünde aktif olan bir programı mı, yoksa arka planda çalışan bir programı mı çalıştıracağına karar verir. Bu kararı verirken, hangi programın daha yüksek önceliğe sahip olduğuna, hangi programın CPU’yu ne kadar süre kullandığına ve sistemin o anki yük durumuna bakabilir.

### Modülerlik (Modularity) ve Yazılım Tasarımı:

Politika ve mekanizmayı birbirinden ayırmak, yazılım geliştirme süreçlerinde modülerliğin temel bir ilkesi olarak kabul edilir. Bu ilke, farklı yazılım bileşenlerinin bağımsız olarak geliştirilip, kolayca değiştirilebilmesini sağlar. Aynı zamanda, sistemin çeşitli parçalarının birbiriyle minimum bağımlılık ile çalışmasına olanak tanır.

Bu ayrım, yazılımın bakımı ve geliştirilmesi açısından büyük avantajlar sağlar. Örneğin, yeni bir CPU zamanlama politikası eklemek isterseniz, var olan bağlam değiştirme mekanizmasını ellemeye gerek kalmaz. Bu, daha az hata yapma riskini ve geliştirme süresini azaltır.

### Özet:

CPU sanallaştırma sürecinde politika ve mekanizmanın ayrı tutulması, işletim sisteminin CPU'yu verimli kullanmasını sağlar. Mekanizmalar, düşük seviyeli görevlerin nasıl yerine getirileceğini belirlerken, politikalar yüksek seviyeli kararları alır. Bu ayrım, yazılım geliştirme süreçlerinde modülerlik sağlar ve sistemin esnekliğini artırır.

---

Bir **process** (işlem), çalışan bir programdır ve birden fazla bileşenden oluşur. İşletim sistemi, her process için bu bileşenleri yönetir. Şimdi bu bileşenleri ve process'in nasıl çalıştığını daha detaylı inceleyelim.

### Process Bileşenleri:

Bir process'in üç ana bileşeni vardır:

### 1. **Adres Uzayı (Address Space)**:

Process'in çalışırken erişebildiği bellek alanıdır. Bu bellek, farklı bölümlerden oluşur:

- **Program kodu (Instructions)**: Çalışan programın makine dili komutları.
- **Statik değişkenler (Static Variables)**: Programın başlangıcında bellekte yerleşen ve tüm işlem süresince değişmeyen veriler.
- **Heap**: Dinamik olarak tahsis edilen bellek alanıdır. Program çalışırken büyüyebilir veya küçülebilir.
- **Yığın (Stack)**: Fonksiyon çağrıları, yerel değişkenler ve geri dönüş adresleri gibi geçici veriler için kullanılan bellek alanıdır.

Bu adres uzayı, bir process'in bellek üzerindeki yerleşimini ve erişebileceği alanları belirler.

### 2. **İşlemci Durumu (Processor State)**:

Bu, CPU'nun process ile ilgili kayıtlarını içerir. İşlemci durumu, process'in o anki çalışma anındaki CPU kayıtlarıyla ilgili bilgileri tutar. İçerdiği bazı önemli bileşenler:

- **Genel amaçlı kayıtlar (General Purpose Registers)**: CPU'nun işlem yaparken kullandığı geçici veri depolama alanlarıdır.
- **Program sayacı (Program Counter)**: Process'in çalıştırılmakta olan sonraki talimatının adresini gösterir. Yani, hangi kod satırının sırada olduğunu belirtir.
- **Yığın işaretçisi (Stack Pointer)**: Yığının en üstündeki elemanın yerini gösterir ve fonksiyon çağrıları gibi işlemlerde önemlidir.

Bu kayıtlar, bir process'in durdurulup tekrar başlatıldığında kaldığı yerden devam edebilmesini sağlar.

### 3. **İşletim Sistemi Kaynakları (OS Resources)**:

Bir process, sadece belleği ve işlemciyi kullanmaz; aynı zamanda işletim sisteminin sağladığı diğer kaynakları da kullanır:

- **Açık dosyalar (Open Files)**: Process'in o anda eriştiği dosyalar. Örneğin, bir program bir dosyayı okuyor veya yazıyorsa, bu dosya bir işletim sistemi kaynağı olarak process'e atanır.
- **Ağ soketleri (Network Sockets)**: Process'in internete veya başka bir ağa bağlanması gerektiğinde kullanılan kaynaklardır.
- **Diğer kaynaklar**: İşlemci zaman dilimleri, bellek tahsisleri ve diğer donanım kaynakları gibi işletim sistemi tarafından yönetilen diğer kaynaklar.

---

**File Descriptor Nedir?**

- **File descriptor**, işletim sisteminin bir dosya veya kaynakla ilişkili olan bir işaretçisidir.
- Genellikle bir tamsayı olarak temsil edilir ve açılan dosyaların yönetimi için kullanılır.
- Program, dosya tanımlayıcıları aracılığıyla dosyalarla (okuma, yazma, kapatma vb.) etkileşimde bulunur.

### Üç Dosya Descriptor'ün Oluşması

Bir program çalıştırıldığında genellikle şu üç dosya tanımlayıcısı otomatik olarak oluşturulur:

1. **Standard Input (stdin)**:
    - **Tanımlayıcı**: `0`
    - Kullanıcıdan veya bir dosyadan veri almak için kullanılır. Genellikle klavye ile ilişkilendirilir.
2. **Standard Output (stdout)**:
    - **Tanımlayıcı**: `1`
    - Programın çıktısını görüntülemek için kullanılır. Genellikle ekrana yazdırılan verileri ifade eder.
3. **Standard Error (stderr)**:
    - **Tanımlayıcı**: `2`
    - Hata mesajlarını ve diğer hata bildirimlerini yazmak için kullanılır. Genellikle ekrana, standart çıktının yanında yazılır.

### Neden Üç Dosya Descriptor Oluşur?

- **Girdi/Çıktı Yönetimi**: Bu üç tanımlayıcı, kullanıcı ile etkileşim kurmak için temel bir yapı sunar. Kullanıcıdan veri almak, çıktı üretmek ve hata mesajlarını iletmek için standart bir yol sağlar.
- **Taşınabilirlik**: Herhangi bir sistemde bu tanımlayıcılar standarttır, bu nedenle programlar farklı sistemlerde çalışırken aynı şekilde davranır.
- **Programın Modülerliği**: Programlar, bu tanımlayıcılar üzerinden diğer dosyalarla etkileşimde bulunabilir. Örneğin, `stdout` ve `stderr`, başka bir dosyaya yönlendirilebilir, bu da çıktıların kaydedilmesini veya hata mesajlarının farklı bir dosyaya yazılmasını sağlar.

### Örnek Kullanım

C veya C++ gibi dillerde bu dosya tanımlayıcıları üzerinde işlem yaparken aşağıdaki gibi işlemler gerçekleştirilir:

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    // Stdin'e veri okuma
    char buffer[100];
    read(0, buffer, sizeof(buffer));  // 0, stdin'in tanımlayıcısı

    // Stdout'a veri yazma
    write(1, buffer, sizeof(buffer));  // 1, stdout'un tanımlayıcısı

    // Stderr'a hata mesajı yazma
    write(2, "Error occurred\n", 15);    // 2, stderr'in tanımlayıcısı

    return 0;
}
```

### Sonuç

Üç dosya tanımlayıcısının oluşturulması, işletim sisteminin temel girdi/çıktı yönetimi için kritik öneme sahiptir. Bu yapı, programların kullanıcı etkileşimi ve hata yönetimi açısından daha etkin bir şekilde çalışmasını sağlar. Bu nedenle, programlar genellikle bu tanımlayıcıları kullanarak dosyalarla etkileşimde bulunur.

---

### Process Nasıl Çalışır?

Bir program başlatıldığında, işletim sistemi ona bir **process** oluşturur. Bu process, yukarıda bahsedilen bellek alanına ve işletim sistemi kaynaklarına erişim elde eder. İşlem sırasında, **CPU** talimatları yürütür, yığından veriler alır ve programın ilerlemesini **program sayacı** ile takip eder. Eğer process durdurulursa (örneğin, CPU başka bir process'e geçiş yaparsa), işlemci durumu kaydedilir ve tekrar başlatıldığında kaldığı yerden devam etmesi sağlanır.

Process’in bu yapısı sayesinde işletim sistemi, aynı anda birden fazla programı çalıştırabilir (çoklu görev - multitasking), kaynakları adil bir şekilde dağıtabilir ve her bir process'in izole bir şekilde çalışmasını sağlayabilir.

---

Bir **process adres uzayı** (process address space), bir işlem (process) için ayrılmış olan sanal bellek alanıdır. Bu alan, işlemin çalıştırılabilmesi için gerekli olan tüm verileri içerir. İşletim sistemi, her process'e bağımsız bir adres uzayı sağlar, böylece her bir programın çalışması sırasında diğer programlarla karışmadan belleği kullanabilmesi mümkün olur.

Adres space nedir bölümleri nedir ne işe yarar sınav..

---

**Adres Alanı (Address Space)**, bir işlem veya programın kullanabileceği bellek adreslerinin toplamıdır. İşletim sistemleri, her işlem için kendi adres alanını tanımlar, böylece her işlemin belleği izole edilerek güvenli ve düzenli bir şekilde yönetilebilir. Adres alanı, fiziksel bellekle ilişkilidir ve mantıksal (veya sanal) adreslerin fiziksel adreslere nasıl dönüştürüleceğini yönetir.

### Adres Alanının Bölümleri

1. **Kullanıcı Alanı (User Space)**:
    - Kullanıcı uygulamalarının çalıştığı bellek bölgesidir.
    - Kullanıcı uygulamaları burada çalışır ve yalnızca bu alan içinde bellek tahsis edebilir.
    - Kullanıcı alanı, genellikle sistem kaynaklarına erişim kısıtlamaları olan bir alandır, bu da kullanıcı uygulamalarının doğrudan donanım veya işletim sistemi kaynaklarına erişimini engeller.
    - Örnek: Bir web tarayıcısı, kelime işlemci veya oyun gibi kullanıcı uygulamaları burada çalışır.
2. **Çekirdek Alanı (Kernel Space)**:
    - İşletim sistemi çekirdeğinin çalıştığı bellek bölgesidir.
    - Donanım kaynaklarına erişim ve yönetim için gerekli olan çekirdek kodu burada yer alır.
    - Çekirdek alanı, kullanıcı alanından daha fazla ayrıcalığa ve yetkiye sahiptir; bu nedenle, kullanıcı uygulamaları doğrudan bu alana erişemez.
    - Örnek: İşletim sistemi çekirdeği, sürücüler ve sistem çağrıları gibi bileşenler burada çalışır.

### Adres Alanının İşlevi

- **Bellek Yönetimi**: Adres alanı, bellek yönetimini kolaylaştırır. İşletim sistemi, her bir işlemin kendi adres alanına sahip olmasını sağlayarak bellek çakışmalarını önler.
- **İzolasyon**: Kullanıcı uygulamaları birbirlerinden izole edilir. Bir uygulama diğerinin bellek alanına erişemez, bu da güvenliği artırır.
- **Sanal Bellek**: Adres alanı, sanal bellek yönetimi ile birlikte çalışır. Sanal bellek, fiziksel bellek sınırlamalarını aşarak daha büyük bir bellek alanı gibi görünmesini sağlar. İşletim sistemi, sanal adresleri fiziksel adreslere dönüştürerek bellek erişimini yönetir.
- **Verimlilik**: Adres alanı yönetimi, bellek kullanımını optimize eder. İşletim sistemi, kullanılmayan bellek alanlarını yeniden tahsis ederek kaynakları daha verimli kullanır.

### Sonuç

Adres alanı, işletim sisteminin bellek yönetimini, kullanıcı ve çekirdek alanları arasında bir ayrım yaparak, güvenliği ve verimliliği artırmak için kritik bir bileşendir. Kullanıcı uygulamaları ve işletim sistemi bileşenleri arasındaki bu ayrım, sistemin kararlılığını ve güvenliğini sağlamak açısından son derece önemlidir.

---

### Process Adres Uzayı İçeriği:

### 1. **Kod Segmenti (Code Segment / Text Segment)**:

Bu bölüm, çalıştırılan programın makine dili talimatlarını içerir. Programın çalıştırılabilir kısmı yani kodu buradadır. Bu alan sadece okunabilir, program çalışırken buradaki veriler değiştirilmez.

### 2. **Başlatılmış Değişkenler (Initialized Variables / Data Segment)**:

Bu bölüm, programın başlangıcında belirli değerlerle başlatılmış olan statik değişkenleri içerir. Bu değişkenler, programın çalışması süresince bellekte sabit bir yerde kalır.

### 3. **Yığın (Stack)**:

Yığın, her fonksiyon çağrısında yerel değişkenleri, geri dönüş adreslerini ve fonksiyonların kaydedilmiş CPU kayıtlarını (registers) saklar. Programın işlev çağrıları ve geri dönüşleri burada işlenir. Yığın, belleğin üst kısmında yer alır ve her fonksiyon çağrısıyla büyür, fonksiyon geri döndüğünde ise küçülür. **Yığın işaretçisi** (stack pointer), bu alanın en üstündeki elemanın yerini gösterir ve her işlemde güncellenir.

### 4. **Yığın Dışı Bellek (Heap)**:

Yığın dışı bellek, programın çalışma zamanında dinamik olarak bellek tahsis edebileceği bir alandır. Örneğin, bir program çalışırken yeni bir bellek bloğu (örneğin bir dizi) tahsis ederse, bu bellek alanı yığında değil, heap'te oluşturulur. Heap, programın ihtiyaç duyduğu bellek alanını dinamik olarak büyütüp küçültebilir.

### 5. **Sıfırdan Başlayan Bellek Adresi (0x00000000)** ve **Son Bellek Adresi (0xFFFFFFFF)**:

Process’in sanal bellek adres aralığı, 0x00000000 adresinden başlayarak 0xFFFFFFFF adresine kadar devam eder. Bu adresler 32-bit sistemler için geçerli olup, daha büyük adres aralıkları 64-bit sistemlerde mümkündür.

### 6. **Program Sayacı (Program Counter)**:

**Program sayacı**, şu anda çalıştırılmakta olan talimatın adresini tutar. Bu, işlemin çalışmasının nereye kadar geldiğini ve bir sonraki hangi komutun çalıştırılacağını belirler.

### 7. **Yığın İşaretçisi (Stack Pointer)**:

**Yığın işaretçisi**, yığının en üstündeki elemanın adresini tutar. Bu, yığındaki hangi değerin en son eklendiğini ve işleme alındığını gösterir.

### Adres Uzayının Yapısı:

Bellek adres uzayı, aşağıdan yukarıya doğru farklı segmentlerden oluşur:

1. **Kod Segmenti**: Programın çalıştırılabilir talimatları burada bulunur.
2. **Veri Segmenti**: Başlatılmış global ve statik değişkenler burada yer alır.
3. **Yığın Dışı Bellek (Heap)**: Dinamik olarak tahsis edilen bellek buradadır. Program çalıştıkça büyüyebilir.
4. **Yığın (Stack)**: Fonksiyon çağrıları ve yerel değişkenler buraya eklenir ve çıkarılır. Yığın, yukarıdan aşağıya doğru büyür.

Bu yapı, programların bellek yönetimini daha etkin ve güvenli bir şekilde yapmalarını sağlar. Her process'in kendi sanal bellek uzayı olduğu için, işletim sistemi bu belleği izole bir şekilde yönetir ve diğer işlemlerden korur.

---

Bir **process adres uzayı** (process address space), her işlem için işletim sistemi tarafından sağlanan **sanal bellek** (virtual memory) alanıdır. Bu alan, işlemin belleği nasıl gördüğünü ve kullandığını tanımlar, ancak bu bellek, fiziksel bellekte gerçekte böyle düzenlenmemiş olabilir. İşletim sistemi, sanal bellek sistemi kullanarak her bir process'e kendine aitmiş gibi görünen bir adres uzayı sağlar. Ancak fiziksel bellek (RAM) aslında farklı bir şekilde düzenlenmiş olabilir.

### Sanal Bellek Sistemi (Virtual Memory System):

- **Sanal bellek** (virtual memory), işletim sisteminin fiziksel belleği daha verimli ve güvenli bir şekilde kullanabilmesini sağlayan bir mekanizmadır. Her process, tüm bellek kendine aitmiş gibi sanal bir adres uzayına sahiptir. Bu adres uzayı, **fiziksel bellekten** (physical memory) bağımsız olarak düzenlenir.
- İşletim sistemi, **adres çevirme** (address translation) yöntemini kullanarak, her bir process'in sanal adreslerini fiziksel bellek adreslerine dönüştürür. Bu işlem, **sayfa tablosu** (page table) adı verilen veri yapıları ile gerçekleştirilir.

### Fiziksel Bellek ile Sanal Bellek Arasındaki Fark:

- **Sanal bellek**, bir process’in kendine özel gibi gördüğü bellek alanıdır. Program, adres uzayı üzerinde 0x00000000 ile başlayıp devam eden adreslerdeki verilere eriştiğini düşünür. Ancak, bu adresler fiziksel bellek üzerindeki gerçek adreslerle doğrudan örtüşmez.
- **Fiziksel bellek** ise bilgisayarın RAM’inde bulunan gerçek bellek bloklarıdır. Sanal bellek, fiziksel belleğe ihtiyaç duyuldukça işletim sistemi tarafından yerleştirilir ve kullanılır. Aynı fiziksel bellek bloğu, birden fazla process tarafından paylaşılabilir veya bazı parçalar disk belleğine (swap space) taşınabilir.

### Sanal Belleğin Sağladığı Avantajlar:

1. **İzolasyon**: Her process, diğerlerinden izole edilmiştir. Bu, bir process'in diğerinin belleğine erişmesini engeller ve sistem güvenliğini artırır.
2. **Esneklik**: Process, sadece ihtiyaç duyduğu kadar fiziksel belleği kullanır. Kullanılmayan bellek alanları disk belleğine taşınabilir ve bu da fiziksel bellek kullanımını optimize eder.
3. **Büyük Bellek Alanı**: Sanal bellek, fiziksel belleğin kapasitesinden daha büyük bir adres uzayı sağlayabilir. Örneğin, 32-bit bir sistemde sanal adres uzayı 4 GB olabilirken, fiziksel RAM çok daha küçük olabilir.

### Sanal Belleğin İşleyişi:

Her process'in çalışırken eriştiği sanal bellek, işletim sisteminin **bellek yönetim birimi** (MMU - Memory Management Unit) tarafından fiziksel bellek adreslerine çevrilir. Bellek yönetim birimi, sanal bellek ve fiziksel bellek arasındaki adres dönüşümünü sağlar. Bu sayede:

- Process, kendi adres uzayını kullanırken, işletim sistemi arka planda fiziksel belleğin verimli bir şekilde nasıl kullanılacağını yönetir.
- Belleğin tamamı fiziksel RAM'de tutulmaz, gerekli olduğunda bellek sayfaları fiziksel belleğe yüklenir ve kullanılmayan sayfalar diske taşınabilir (paging).

### Özet:

Bir process, kendi sanal bellek alanında çalışıyormuş gibi görünür, ancak bu bellek fiziksel bellekte tam olarak o şekilde düzenlenmiş değildir. İşletim sistemi, sanal bellek mekanizması ile her process’e fiziksel belleğin üzerinde bağımsız bir sanal bellek alanı sağlar ve bu sayede bellek yönetimini optimize eder, izolasyon sağlar ve belleği daha verimli kullanır.

---

Bir **process API** (Process Application Programming Interface), modern işletim sistemlerinde process'lerin yönetimi ve kontrolü için kullanılan işlevler kümesidir. Bu API'ler, işletim sistemi ile process'ler arasında bir köprü görevi görerek, geliştiricilere programlarını ve sistem süreçlerini yönetme olanağı sağlar. Aşağıda, bu API'lerin yaygın işlevlerini ve nasıl kullanıldıklarını inceleyelim:

### 1. **Create (Oluşturma)**:

Bir program çalıştırılmak istendiğinde yeni bir process oluşturulması gerekir. Bu işlem, işletim sistemine bir çağrı yaparak gerçekleştirilir.

- Bu API, yeni bir process başlatır ve belirli bir programın kodunu çalıştırmasını sağlar.
- Örnek: UNIX/Linux'ta **`fork()`** ve **`exec()`** sistem çağrıları bu amaçla kullanılır. `fork()`, mevcut bir process'in kopyasını oluşturur (child process), `exec()` ise bu yeni process içinde belirli bir programı çalıştırır.
    
    **Kullanım Senaryosu**: Bir web sunucusu, her gelen isteği işlemek için yeni bir process oluşturabilir ve bu process, istemcinin isteğini karşılar.
    

### 2. **Destroy (Yok Etme)**:

Bir process istenmeyen şekilde çalışıyorsa ya da sonlandırılması gerekiyorsa, işletim sistemi bu process'i durdurur ve bellek gibi kaynakları geri alır.

- **`kill()`** gibi sistem çağrıları, bir process’i zorla sonlandırmak için kullanılır. Process’in normal çalışması sırasında beklenmeyen sorunlar çıktığında veya kontrolsüzce CPU’yu tükettiğinde işletim sistemi onu durdurabilir.
    
    **Kullanım Senaryosu**: Bir işlem sonsuz döngüde sıkışmışsa ve sistem kaynaklarını tüketiyorsa, bu API ile process sonlandırılabilir.
    

### 3. **Wait (Bekleme)**:

Bir program, başka bir process'in tamamlanmasını beklemek zorunda kalabilir. Bu durumda, **wait** API'si devreye girer.

- Örneğin, bir **parent process** (ebeveyn işlem), bir **child process** (çocuk işlem) oluşturduktan sonra bu işlemin bitmesini beklemek isteyebilir. UNIX/Linux'ta **`wait()`** fonksiyonu kullanılır.
    
    **Kullanım Senaryosu**: Bir yükleyici (installer), bir alt programın yüklenmesini bekler, yükleme tamamlandığında diğer işlemleri yürütmeye devam eder.
    

### 4. **Miscellaneous Control (Çeşitli Kontroller)**:

Bu API'ler, process'ler üzerinde daha gelişmiş kontroller sunar, örneğin bir process'i geçici olarak durdurmak (suspend) ve sonra yeniden başlatmak (resume) gibi.

- **`kill -STOP`** ve **`kill -CONT`** gibi komutlarla, bir process duraklatılabilir ve daha sonra kaldığı yerden devam ettirilebilir.
    
    **Kullanım Senaryosu**: Bir medya oynatıcısını duraklatıp sonra devam ettirme işlemi, arka planda bir process’in geçici olarak durdurulup daha sonra yeniden başlatılması bu API ile mümkündür.
    

### 5. **Status (Durum Bilgisi)**:

Bu API, belirli bir process hakkında bilgi almak için kullanılır. Bir process'in durumu, çalışıp çalışmadığı, ne kadar bellek kullandığı veya CPU kullanım oranı gibi veriler bu API aracılığıyla alınabilir.

- **`ps`** komutu ya da **`top`** gibi araçlar, sistemdeki mevcut process'ler hakkında bilgi verir.
    
    **Kullanım Senaryosu**: Bir sistem yöneticisi, bir programın ne kadar bellek ve CPU kullandığını görmek için bu API'yi kullanabilir.
    

### Özet:

Process API'leri, işletim sistemlerinde programların başlatılması, durdurulması, kontrol edilmesi ve durumlarının izlenmesi için temel araçlardır. Geliştiriciler, bu API'leri kullanarak programlarının sistemle etkileşimini yönetebilir ve kaynakları verimli şekilde kullanabilirler.

---

Bir **process'in oluşturulması** işletim sistemi tarafından bir dizi adımla gerçekleştirilir. Bu adımlar, bir programın diskteki çalıştırılabilir halinden, bellekte çalışan bir process'e dönüştürülmesini içerir. Aşağıda, bu sürecin adım adım nasıl gerçekleştiğini açıklayalım:

### 1. **Program Kodunun Belleğe Yüklenmesi (Load a Program Code)**:

- Programlar ilk olarak diskte çalıştırılabilir (executable) formatta bulunur. Process oluşturulurken, bu programın kodu ve verileri belleğe yüklenir.
- İşletim sistemi, **lazy loading** kullanarak bu işlemi gerçekleştirebilir. Yani, tüm programı bir kerede belleğe yüklemek yerine, programın çalışması sırasında ihtiyaç duyuldukça belleğe yükler. Bu işlem için **paging** (sayfalama) ve **swapping** (değiştirme) teknikleri kullanılır.**Sonuç**: Programın bellekte yer alan adres uzayı oluşturulur ve kullanıma hazır hale gelir.
    - **Paging**: Bellekte sayfalara bölünen program parçaları sadece ihtiyaç duyuldukça yüklenir.
    - **Swapping**: Bellekte yeterli yer yoksa, kullanılmayan sayfalar disk belleğine taşınır.

### 2. **Programın Yığınının Ayrılması (Run-Time Stack Allocation)**:

- Programın çalışma zamanı yığını (stack), yerel değişkenler, fonksiyon parametreleri ve fonksiyonların geri dönüş adresleri gibi bilgilerin tutulduğu bellek bölgesidir.
- İşletim sistemi, programın yığınını oluşturur ve başlatır. Bu yığının başlangıç noktası, **`argc`** ve **`argv`** dizisi gibi parametrelerle başlatılır. Bu parametreler, programın komut satırından aldığı argümanları içerir:
    - **`argc`**: Komut satırından gelen argümanların sayısı.
    - **`argv`**: Argümanların bir dizi olarak saklandığı alan.
    
    **Sonuç**: Programın yığını oluşturulur ve başlangıç değerleriyle doldurulur.
    

### 3. **Programın Heap Alanının Oluşturulması (Heap Allocation)**:

- **Heap**, programın çalışma zamanında dinamik olarak bellek tahsisi yaptığı bellek alanıdır. Örneğin, veri yapıları (bağlı listeler, hash tabloları, ağaçlar vb.) gibi dinamik olarak büyüyen/veri eklenen yapılar bu alanda yer alır.
- Program, heap üzerinden bellek tahsisini **`malloc()`** ile yapar ve kullanılmayan bellek alanlarını **`free()`** ile serbest bırakır.
    
    **Sonuç**: Program, heap üzerinden dinamik bellek kullanımı için hazır hale getirilir.
    

### 4. **Diğer Başlangıç İşlemleri (Other Initialization Tasks)**:

İşletim sistemi, process'in çalışabilmesi için ek ayarlamalar yapar:

- **Giriş/Çıkış (I/O) Kurulumu**: Her process için varsayılan olarak üç açık dosya tanımlayıcısı (file descriptor) oluşturulur:
- **Sonuç**: Process, giriş/çıkış işlemleri için gerekli dosya tanımlayıcılarıyla başlatılır.
    - **Standart giriş (stdin)**: Kullanıcının giriş yaptığı yer.
    - **Standart çıkış (stdout)**: Programın çıktı verdiği yer (örneğin terminal).
    - **Standart hata (stderr)**: Hataların gönderildiği yer.

### 5. **Programın Çalıştırılmaya Başlanması (Starting the Program)**:

- Tüm hazırlıklar tamamlandığında, işletim sistemi programı başlatır. Bu, programın başlangıç noktası olan **`main()`** fonksiyonuna CPU kontrolünün verilmesiyle gerçekleşir.
- İşletim sistemi, CPU'yu yeni oluşturulan process'e devreder ve program **`main()`** fonksiyonundan itibaren çalışmaya başlar.
    
    **Sonuç**: Program, process olarak başlatılır ve CPU’da çalıştırılmaya başlar.
    

### Özet:

Process oluşturulması adım adım bir süreçtir:

1. Programın kodu ve verileri belleğe yüklenir.
2. Programın yığını (stack) başlatılır.
3. Programın heap alanı oluşturulur.
4. Gerekli giriş/çıkış ayarları yapılır.
5. Program **`main()`** fonksiyonundan başlayarak çalışmaya başlar. İşletim sistemi, bu adımları gerçekleştirerek her process'in bağımsız ve güvenli bir şekilde çalışmasını sağlar.

---

**Programdan Process'e Yükleme (Loading: From Program to Process)**, bir programın diskteki çalıştırılabilir halinden (binary/executable format) işletim sisteminde çalışan bir **process** (işlem) haline dönüşme sürecini ifade eder. Bu işlem, programın belleğe yüklenmesini ve işletim sistemi tarafından çalıştırılmak üzere hazır hale getirilmesini kapsar. Bu sürecin detaylarına bakalım:

### Program ve Process Arasındaki Fark:

- **Program**: Diske kaydedilmiş, çalıştırılabilir (executable) formatta olan, çalışmayan bir kod kümesidir. Program, yalnızca bir dosyadır ve bellekte aktif değildir. Örneğin, bir `.exe` dosyası veya bir Python script’i bu tür bir program olarak kabul edilebilir.
- **Process**: Programın, işletim sistemi tarafından belleğe yüklenip çalıştırılan dinamik halidir. Bir process, programın bir kopyasının bellekteki temsilidir ve kendi **adres uzayı** (address space), **bellek durumu** ve **CPU durumu** vardır. İşletim sistemi tarafından izole edilmiş ve yönetilen bir yapıdadır.

### Yükleme (Loading) Süreci:

1. **Programın Belleğe Yüklenmesi**:
    - İşletim sistemi, diskteki çalıştırılabilir (executable) dosyayı alır ve programın içeriğini işlem için ayrılmış olan **adres uzayına** (address space) yükler.
    - Bu işlem sırasında, program kodu, statik veriler ve diğer bileşenler adres uzayında belirli yerlere yerleştirilir:
        - **Kod Bölgesi (Code Segment)**: Programın çalıştırılacak makine talimatları (instructions) burada yer alır.
        - **Statik Veri Bölgesi (Static Data Segment)**: Değişmeyen sabitler, statik değişkenler gibi veriler bu segmentte saklanır.
        - **Yığın (Stack)** ve **Yığın Bellek (Heap)**: Program çalışmaya başladığında dinamik olarak doldurulacak diğer bellek segmentleridir.
2. **Adres Uzayı (Address Space) Yapısı**:
Program belleğe yüklendikten sonra, bir **process adres uzayı** (process address space) oluşturulur. Bu adres uzayı şu segmentlerden oluşur:
    - **Kod Segmenti (Code Segment)**: Programın makine kodlarını içerir. Bu segment yalnızca **okunabilir** ve **yazılamaz**. Böylece, işlem sırasında bu segmentin değiştirilmesi engellenir.
    - **Statik Veri Segmenti (Static Data Segment)**: Programın başlatma sırasında oluşturulan ve tüm çalışma süresi boyunca sabit kalan değişkenleri içerir. Örneğin, global değişkenler ve sabit diziler bu alanda tutulur.
    - **Heap (Yığın Bellek)**: Programın çalışma süresi boyunca dinamik olarak büyüyen/veri eklenen bellektir. Dinamik bellek tahsisi (`malloc()` gibi fonksiyonlar) bu alanda yapılır ve veri yapıları (bağlı listeler, ağaçlar, vb.) bu alanda saklanır.
    - **Stack (Yığın)**: Yerel değişkenler, fonksiyon parametreleri ve fonksiyonların geri dönüş adresleri bu bellek segmentinde tutulur. Fonksiyon çağrıları ile büyür ve geri dönüşlerle küçülür.
3. **Belleğe Yükleme (Loading) Yöntemleri**:
İşletim sistemi, belleğe yükleme işlemini verimli bir şekilde gerçekleştirebilmek için çeşitli yöntemler kullanır:
    - **Lazı Yükleme (Lazy Loading)**: Tüm programın belleğe yüklenmesi yerine, sadece ihtiyaç duyuldukça parçalar halinde belleğe yükleme işlemi yapılır. Bu yöntem belleğin verimli kullanımını sağlar. Örneğin, bir fonksiyon çalıştırılmadan önce belleğe yüklenmeyebilir ve ancak çağrıldığında belleğe alınır.
    - **Bellek Haritalama (Memory Mapping)**: Diske kaydedilmiş dosyalar, işletim sistemi tarafından doğrudan belleğe haritalanır ve ihtiyaç duyulduğunda belleğe getirilir. Bu, programların ve verilerin bellekte daha hızlı kullanılmasını sağlar.

### Yükleme Adımları:

1. **Program Kodunun ve Statik Verilerin Belleğe Alınması**: Programın kodu ve statik verileri, adres uzayında kod ve veri segmentlerine yerleştirilir.
2. **Yığının (Stack) Başlatılması**: Program başlarken, yığın bölgesi (stack) oluşturulur ve fonksiyon parametreleri ile `argc`, `argv` gibi başlangıç argümanları bu alana yüklenir.
3. **Heap Alanının Ayrılması**: Dinamik bellek için ayrılan heap alanı başlatılır, ancak ilk başta bu alan genellikle boştur ve programın çalışma süresinde dinamik olarak büyütülür.
4. **İşlem Başlangıç Noktasına Geçiş (Jump to Start Point)**: İşletim sistemi, yeni oluşturulan process'in kod segmentinde yer alan **başlangıç noktasına (start point)** geçiş yapar ve programın çalışmasını başlatır. Bu genellikle `main()` fonksiyonunun adresidir.

### Örnek:

Bir program diskte şu şekilde yer alabilir:

```sql
program.exe
+---------------------------+
| Kod Segmenti              |
| (machine instructions)    |
+---------------------------+
| Statik Veri Segmenti      |
| (global variables, const) |
+---------------------------+
```

İşletim sistemi bu programı yüklediğinde, bellek adres uzayında aşağıdaki şekilde yer alır:

```diff
Bellek Adres Uzayı:
0x00000000 (Başlangıç)
+---------------------------+
| Kod Segmenti              |
+---------------------------+
| Statik Veri Segmenti      |
+---------------------------+
| Heap                      |
| (Dinamik bellek tahsisi)  |
+---------------------------+
| Stack                     |
| (Yerel değişkenler,       |
|  fonksiyon çağrıları)     |
+---------------------------+
0xFFFFFFFF (Son)
```

### Özet:

- Bir program diskte pasif bir veri yapısı iken, belleğe yüklendiğinde ve çalışmaya başladığında bir **process** halini alır.
- İşletim sistemi, programı belleğe yükleyip gerekli segmentleri oluşturduktan sonra, process'in çalışmasını başlatır ve CPU denetimini bu yeni process'e devreder.
- Bu sürecin verimli ve güvenli bir şekilde yönetilmesi, bellek izolasyonu ve kaynak yönetimi açısından çok önemlidir.

---

### Program ve Process Arasındaki Fark

**Program**, diskte saklanan bir uygulamadır. Program, kod ve veri içerir ve çalıştırılmadığı sürece pasif bir durumdadır. Programlar, çalıştırıldıklarında bir **process** (işlem) haline gelirler.

- **Program**: Disk üzerinde bulunan, çalıştırılabilir bir uygulamadır. Kod ve veri içerir. Örneğin, bir `.exe` dosyası veya bir Python betiği (script) bu tanıma uyar.
- **Process**: Bir programın çalıştırılmakta olan örneğidir. Process, işletim sistemi tarafından yönetilir ve bellekte bir adres uzayına sahiptir. Her process, tek bir yürütme ipliği (thread) ile başlar.

### Process'in Temel Özellikleri

1. **Tek Yürütme İpliği (Single Thread of Execution)**:
    - Her process, başlangıçta yalnızca bir yürütme ipliği ile başlar. Bu, programın kodunun belli bir sırayla yürütülmesini sağlar.
2. **Adres Uzayı (Address Space)**:
    - Her process, kendi adres uzayına sahiptir. Bu, process'in erişebileceği bellek alanını belirler. Adres uzayı, programın kodunu, statik verilerini, heap ve stack alanlarını içerir.
3. **Birden Fazla İpliğin Başlatılması (Launching Multiple Threads)**:
    - Bir process, aynı adres uzayında birden fazla yürütme ipliği başlatabilir. Bu, çoklu görevlerin (multitasking) gerçekleştirilmesine olanak tanır. Örneğin, bir programda bir iplik kullanıcı arayüzünü yönetirken, diğer bir iplik veri işlemleri yapabilir.
4. **İplere Ait Bellek Yönetimi**:
    - Her iplik, kendi yığını (stack) ile çalışır. Yığın, yerel değişkenler, fonksiyon parametreleri ve geri dönüş adresleri gibi bilgileri saklar.
    - Bununla birlikte, tüm iplikler global verileri, kodu ve heap'i paylaşır. Bu paylaşım, iplikler arasında veri alışverişini kolaylaştırır ama aynı zamanda dikkatli bir yönetim gerektirir, çünkü bir ipliğin global verilere yaptığı değişiklik diğer iplikleri etkileyebilir.

### Örnek

Bir metin düzenleyici programını düşünelim:

- **Program**: Disk üzerinde bulunan ve metin düzenleme işlevlerini içeren bir uygulama.
- **Process**: Metin düzenleyici çalıştırıldığında, diskten belleğe yüklenen ve kullanıcı etkileşimini yöneten bir işlem. Bu process, kullanıcı arayüzü için bir iplik ve dosya okuma/yazma işlemleri için başka bir iplik başlatabilir.

### Özet

- **Program**: Diskteki, pasif bir uygulama.
- **Process**: Çalıştırılan bir programın aktif örneği. Tek bir iplikle başlar ama birden fazla iplik başlatabilir.
- **Adres Uzayı**: Her process'in kendi bellek alanı. İplikler arasında global veri ve kod paylaşılırken, her iplik kendi yığınını kullanır.

Bu yapı, işletim sisteminin çoklu görevleri etkin bir şekilde yönetmesine ve kullanıcıların aynı anda birden fazla uygulama çalıştırabilmesine olanak tanır.

---

### CPU Sanallaştırması (Virtualizing the CPU)

**CPU sanallaştırması**, her bir process'e (işlem) kendine ait bir CPU'ya sahip olduğu illüzyonunu vermek amacıyla tasarlanmıştır. Ancak gerçeklikte, CPU tüm process'ler arasında paylaşılan bir kaynaktır. Bu durumu yönetmek için çeşitli yöntemler ve stratejiler uygulanır.

### Amaç

- **Amaç**: Her bir process'e, CPU’ya özel olarak erişim sağladığı hissini vermektir. Bu, kullanıcıların uygulamalarını daha hızlı ve etkili bir şekilde çalıştırmalarını sağlar.

### Gerçeklik

- **Gerçeklik**: CPU, işletim sistemi tarafından tüm process'ler arasında paylaşılan bir kaynak olarak kullanılır. Yani, aynı anda yalnızca bir process CPU üzerinde çalışabilir.

### İki Yaklaşım

1. **Zaman Paylaşımı (Time Sharing)**:
    - **Tanım**: Zaman paylaşımlı sistemlerde, CPU zaman dilimleri (time slices) kullanılarak birden fazla process'e sırayla hizmet edilir. Her process, belirli bir süre için CPU'yu kullanır, ardından kontrol bir sonraki process'e geçer.
    - **Örnek**: Bir oyun oynarken, oyun motoru bir karaktere odaklanıp birkaç milisaniye boyunca o karakterin hareketlerini hesaplar, ardından diğer karaktere geçer. Bu, kullanıcının oyun sırasında tüm karakterlerle etkileşimde bulunduğu hissini yaratır.
2. **Alan Paylaşımı (Space Sharing)**:
    - **Tanım**: Alan paylaşımında, CPU zaman dilimleri yerine her bir process'e sürekli olarak CPU'dan küçük parçalar (chunks) tahsis edilir. Bu, her process'in sürekli olarak CPU'ya erişimi olduğu hissini verir.
    - **Örnek**: Bir web sunucusu, gelen talepleri işlemek için her bir talebe sürekli küçük zaman dilimleri ayırabilir.

### Farklı Stratejiler

Farklı kaynaklar için farklı yönetim stratejileri uygulanır:

1. **CPU Yönetimi**:
    - **Zaman Paylaşımı**: CPU, birden fazla task (görev) arasında sıklıkla dönüşümlü olarak paylaşılır. Bu, yüksek etkileşimli ve tepki gerektiren uygulamalar için idealdir.
2. **Bellek Yönetimi**:
    - **Alan Paylaşımı**: Bellek, tüm process'ler arasında daha statik bir şekilde paylaşılır. Bu, her process'in kendi adres uzayına sahip olmasını sağlar. Daha sonra bellek yönetimi konusunu daha detaylı inceleyeceğiz.
3. **Disk Yönetimi**:
    - **Alan Paylaşımı**: Disk alanı, dosyalar arasında dinamik bir şekilde paylaşılır. Her bir process, ihtiyacı olan dosya parçalarına erişim sağlar, bu da verimliliği artırır.

### Özet

- CPU sanallaştırması, her bir process'e özel CPU erişimi sağlama amacı güderken, gerçeklikte CPU tüm process'ler tarafından paylaşılan bir kaynaktır.
- Zaman paylaşımı, process'ler arasında CPU kullanımını döngüsel olarak dağıtırken, alan paylaşımı her bir process'e sürekli bir erişim sağlar.
- Farklı kaynaklar (CPU, bellek, disk) için farklı yönetim stratejileri uygulanır, böylece sistem performansı ve verimliliği artırılır. Bu yapı, modern işletim sistemlerinin çoklu görevleri etkin bir şekilde yönetmesini sağlar.

---

### İşletim Sistemi ve Process Abstraksiyonu

**İşletim sistemi (OS)**, kullanıcıların programlarını çalıştırmasını sağlayan bir süreç yönetimi sağlar. Kullanıcı bir programı çalıştırdığında, işletim sistemi bu programı bir process (işlem) olarak oluşturur. Bu süreç, sistem kaynaklarının yönetiminde büyük bir rol oynar.

### OS'nin Process Yönetimindeki Rolü

1. **Process Oluşturma**:
    - Kullanıcı bir program çalıştırdığında, işletim sistemi bu programı bir **process** olarak oluşturur. Bu, programın bellekte çalışabilir bir formudur.
2. **Zaman Paylaşımı**:
    - İşletim sistemi, CPU'yu birden fazla process arasında paylaştırarak zaman paylaşımı yapar. Bu, kullanıcıların birden fazla uygulama ile etkileşimde bulunabilmesini sağlar.
3. **Scheduler (Zamanlayıcı)**:
    - İşletim sistemindeki **scheduler**, çalıştırılabilir olan process'lerden birini seçer ve çalıştırır. Bu seçim, sistem performansını etkileyen kritik bir karar mekanizmasıdır.
    - Scheduler, mevcut tüm process'lerin bir listesini tutar ve hangi process'in ne zaman çalışacağını belirler.
4. **Meta Veri Yönetimi**:
    - Scheduler, process'ler için politika ile ilgili meta verileri de saklar. Bu bilgiler, hangi process'in çalıştırılacağına dair karar almak için kullanılır.

### Politika ve Mekanizma Arasındaki Fark

- **Politika (Policy)**: Hangi process'in çalıştırılacağına karar verir. Örneğin, belirli bir önceliğe veya kaynak kullanımına göre hangi işlemin daha önce çalıştırılacağı.
- **Mekanizma (Mechanism)**: Bir process'ten diğerine nasıl geçileceğini belirler. Bu, işletim sisteminin **context switch (bağlam geçişi)** işlemi ile ilgilidir. Bağlam geçişi, CPU'nun bir process'ten diğerine geçiş yapmasını sağlar ve bu süreçte gerekli verilerin (register'lar, program sayacı vb.) kaydedilmesi ve geri yüklenmesi gerekir.

### Modülerlik

Politika ve mekanizma arasındaki bu ayrım, modülerliği (modularity) mümkün kılar. Yani:

- **Scheduler** (zamanlayıcı), hangi process'in çalıştırılacağını belirleyen politika ile ilgili kararlar alırken, **context switch** (bağlam geçişi) işlevselliği, bu kararlara dayanarak uygulanır.
- Böylece, bir sistemdeki zamanlama politikası değiştirilse bile, bağlam geçişi mekanizması aynı kalır. Bu, sistem tasarımında esneklik ve sürdürülebilirlik sağlar.

### Özet

- İşletim sistemi, kullanıcı programlarını process olarak yönetir ve CPU'yu bu process'ler arasında zaman paylaşımı ile dağıtır.
- Scheduler, çalıştırılabilir process'leri seçer ve politika ile ilgili meta verileri tutar.
- Politika, hangi process'in çalıştırılacağına karar verirken, mekanizma bu geçişin nasıl yapılacağını belirler. Bu ayrım, sistem tasarımında modülerliği sağlar ve esnekliğin artırılmasına yardımcı olur.

---

### Process Oluşturma

Bir işlem (process) oluşturulması, işletim sisteminin (OS) önemli bir görevidir. Bu süreç, bir programın çalıştırılabilir bir forma dönüştürülmesini sağlar ve aşağıdaki adımları içerir:

### 1. İç Veri Yapılarının Tahsisi

- İşletim sistemi, yeni bir process oluşturulurken, **iç veri yapıları** (internal data structures) için bellek ayırır. Bu yapılar, process'in yönetimi için gerekli olan bilgileri (örneğin, process durumu, öncelik, vb.) içerir.

### 2. Adres Uzayının Tahsisi

- OS, process'in çalışması için gerekli olan **adres uzayı** (address space) tahsis eder. Adres uzayı, process'in erişebileceği bellek alanını temsil eder ve programın kodunu, veri segmentlerini, yığın (stack) ve heap alanlarını içerir.

### 3. Diskten Kod ve Verilerin Yüklenmesi

- Programın kodu ve veri segmentleri, diskteki uygulama dosyasından **belleğe yüklenir**. Bu işlem, genellikle tembel yükleme (lazy loading) yöntemi kullanılarak gerçekleştirilir; yani, yalnızca gerektiğinde kod ve veri parçaları yüklenir.

### 4. Çalışma Zamanı Yığını ve Heap’in Oluşturulması

- OS, process için bir **çalışma zamanı yığını** (runtime stack) ve **heap** alanı oluşturur:
    - **Yığın (Stack)**: Yerel değişkenler, fonksiyon parametreleri ve geri dönüş adreslerini saklar. Her fonksiyon çağrısı için yeni bir yığın çerçevesi (stack frame) oluşturulur.
    - **Heap**: Dinamik olarak tahsis edilen veriler için kullanılır. Program, bu alanı `malloc()` gibi fonksiyonlarla talep eder ve `free()` ile serbest bırakır.

### 5. Temel Dosyaların (STDIN, STDOUT, STDERR) Oluşturulması

- Her process için varsayılan olarak üç temel dosya tanımlayıcısı (file descriptor) açılır:
    - **STDIN**: Standart girdi (kullanıcıdan veri almak için)
    - **STDOUT**: Standart çıktı (kullanıcıya veri yazmak için)
    - **STDERR**: Hata çıktısı (hataları kullanıcıya bildirmek için)

### 6. CPU Kayıtlarının (Registers) Başlatılması

- OS, CPU'nun kayıtlarını (registers) **başlatır** ve bu kayıtlar, process'in yürütülmesi sırasında kullanılacak olan durum bilgilerini (state information) saklar. Bu adım, işlem başlatıldığında kontrolün doğru bir şekilde process'e aktarılmasını sağlar.

### Özet

- Process oluşturma süreci, işletim sisteminin bellek yönetimi ve kaynak tahsisi konularındaki işlevselliğini gösterir.
- OS, iç veri yapıları ve adres uzayı tahsisi ile başlar, ardından kod ve verileri disket yükleyerek process'in çalışma ortamını hazırlar.
- Yığın ve heap alanlarının oluşturulması, standart dosya tanımlayıcılarının ayarlanması ve CPU kayıtlarının başlatılması ile işlem tamamlanır.
- Bu süreç, modern işletim sistemlerinin çoklu görev (multitasking) ve kaynak yönetimi yeteneklerinin temelini oluşturur.

---

### Process Durumları (Process States)

Bir işlem (process), çalışma süreci boyunca farklı durumlar (states) alabilir. İşletim sistemi, bu durumları yöneterek kaynakları etkili bir şekilde kullanır. Genel olarak, bir process üç ana durumda bulunabilir:

### 1. Running (Çalışıyor)

- **Tanım**: Process, bir işlemci (CPU) üzerinde aktif olarak çalışıyordur. Bu durumda, process talimatlarını yürütür ve CPU'yu kullanır.
- **Açıklama**: Çalışan bir process, bilgisayarın mevcut görevini yerine getiren programdır. İşletim sistemi, bu durumu yönetmek için zaman dilimlerini kullanarak CPU'yu paylaşır.

### 2. Ready (Hazır)

- **Tanım**: Process çalışmaya hazırdır, ancak işletim sistemi tarafından o anda çalıştırılmamıştır. Yani, kaynaklar yeterli olmasına rağmen, başka bir process CPU'yu kullanmaktadır.
- **Açıklama**: Hazır durumdaki bir process, CPU'yu kullanabilmek için işletim sisteminin onu seçmesini bekler. Bu durum, çoğunlukla zamanlayıcının kararına bağlıdır ve process, CPU’ya geçmek için sırada bekler.

### 3. Blocked (Engellenmiş)

- **Tanım**: Process, bir I/O (girdi/çıktı) işlemi gerçekleştirdiğinde engellenir. Bu durumda, işlemciyi serbest bırakır ve başka bir process CPU'yu kullanabilir.
- **Açıklama**: Engellenmiş bir process, genellikle disk veya ağ gibi harici kaynaklarla iletişim kurarken ortaya çıkar. Örneğin, bir dosya okuma veya yazma işlemi gerçekleştirilirken, process bu işlemin tamamlanmasını bekler. Bu süre zarfında, işletim sistemi diğer process'lerin çalışmasına olanak tanır.

### Özet

- Bir process, üç ana durumdan birinde bulunabilir: Running, Ready ve Blocked.
- **Running** durumu, process'in CPU üzerinde aktif olarak çalıştığını gösterirken, **Ready** durumu, process'in çalışmaya hazır olduğunu fakat o anda CPU'yu kullanmadığını belirtir.
- **Blocked** durumu, process'in I/O işlemi beklediği için işlemciden ayrıldığını ifade eder. Bu durum, işletim sisteminin kaynakları verimli bir şekilde yönetmesini sağlar ve çoklu görev (multitasking) yeteneklerini optimize eder.

---

### Process Durum Geçişleri (Process State Transition)

Bir process, çalışma süresi boyunca farklı durumlar arasında geçiş yapabilir. İşletim sistemi, bu geçişleri yöneterek CPU ve diğer kaynakları en verimli şekilde kullanır. Aşağıda, **Running**, **Ready**, ve **Blocked** durumları arasındaki geçişlerin nasıl gerçekleştiğini açıklayalım:

### 1. Running (Çalışıyor) → Ready (Hazır)

- **Geçiş Durumu**: **Deschedule (Zamandan Çıkarma)**
- **Açıklama**: İşletim sistemi, çalışmakta olan bir process'i belirli bir süre sonunda veya başka bir process'in çalışması gerektiğinde zamanlayıcı tarafından devre dışı bırakır. Bu durumda, mevcut process'in çalışması durur ve hazır durumuna (Ready) geçer.
- **Nedenler**: Zaman dilimi sona erdiğinde veya daha yüksek önceliğe sahip bir process çalıştırılmaya başladığında bu geçiş gerçekleşir.

### 2. Ready (Hazır) → Running (Çalışıyor)

- **Geçiş Durumu**: **Scheduled (Zamanlanmış)**
- **Açıklama**: Hazır durumdaki bir process, işletim sistemi tarafından seçilerek CPU'yu kullanmaya başlar. Bu geçiş, zamanlayıcı (scheduler) tarafından yapılan bir seçimle gerçekleşir.
- **Nedenler**: İşletim sistemi, hazırda bekleyen process'lerden birini çalıştırmak üzere zamanlama yapar.

### 3. Running (Çalışıyor) → Blocked (Engellenmiş)

- **Geçiş Durumu**: **I/O: Initiate (Girdi/Çıktı: Başlat)**
- **Açıklama**: Bir process, bir I/O işlemi başlattığında (örneğin, dosya okuma veya yazma isteği), bu işlem tamamlanana kadar engellenir. Bu süreçte, process CPU'dan ayrılır ve **Blocked** durumuna geçer.
- **Nedenler**: Disk veya ağ gibi harici bir kaynağa erişim isteği olduğunda bu geçiş gerçekleşir.

### 4. Blocked (Engellenmiş) → Ready (Hazır)

- **Geçiş Durumu**: **I/O: Done (Girdi/Çıktı: Tamamlandı)**
- **Açıklama**: Engellenmiş durumda olan bir process, başlattığı I/O işlemi tamamlandığında, tekrar hazır durumuna geçer. Bu durumda, işletim sistemi process'i çalıştırmak için yeniden seçebilir.
- **Nedenler**: I/O işlemi tamamlandığında, process tekrar çalışmaya hazır hale gelir.

### Özet

- **Process Durumları**:
    - **Running**: CPU üzerinde aktif olarak çalışan process.
    - **Ready**: Çalışmaya hazır ancak henüz CPU'yu kullanmayan process.
    - **Blocked**: I/O işlemi bekleyen ve bu nedenle CPU'yu kullanamayan process.
- **Geçişler**:
    - **Deschedule**: Running durumundaki bir process, zamanlama nedeniyle Ready durumuna geçer.
    - **Scheduled**: Ready durumundaki bir process, işletim sistemi tarafından seçilerek Running durumuna geçer.
    - **I/O: Initiate**: Running durumundaki bir process, I/O isteği başlattığında Blocked durumuna geçer.
    - **I/O: Done**: Blocked durumundaki bir process, I/O işlemi tamamlandığında Ready durumuna geçer.

Bu geçişler, işletim sisteminin çoklu görev yönetimini etkili bir şekilde gerçekleştirmesine ve kaynakları verimli bir şekilde kullanmasına olanak tanır.

---

### Process'in İcra Durumu (Execution State)

Her process'in bir **icra durumu** (execution state) veya **bağlam** (context) vardır. Bu durum, process'in o an ne yaptığını gösterir ve işletim sistemi tarafından yönetilen durumların temelini oluşturur. Aşağıda, bir process'in farklı durumları ve bu durumların anlamları açıklanmıştır:

### 1. Running (Çalışıyor)

- **Tanım**: Process, CPU'yu aktif olarak kullanıyordur.
- **Açıklama**: Bu durumda, process'in talimatları işletimci tarafından yürütülmektedir. İşletim sistemi, bir veya daha fazla process'in CPU'yu kullanabilmesi için zamanlama (scheduling) yapar.

### 2. Ready (Hazır)

- **Tanım**: Process, bir CPU'ya atanmayı bekliyordur.
- **Açıklama**: Bu durumda, process çalışmaya hazırdır, ancak başka bir process CPU'yu kullanmaktadır. Hazır durumdaki process, işletim sistemi tarafından seçilmeyi bekler ve CPU'ya geçmek için sırada bekler.

### 3. Waiting (Bekliyor) veya Sleeping (Uyku Durumu)

- **Tanım**: Process, bir olayın gerçekleşmesini bekliyordur.
- **Açıklama**: Bekleme durumundaki bir process, genellikle bir girdi/çıktı (I/O) işleminin tamamlanması veya bir zamanlayıcının sona ermesi gibi bir olayın gerçekleşmesini bekler. Bu durumda, process CPU'dan ayrılır ve diğer process'lerin çalışmasına olanak tanır.

### Bekleme Durumu ile Hazır Durumu Arasındaki Fark

- **Hazır Durum (Ready)**: Process, bir CPU'yu kullanmak için sırada beklemektedir. İşletim sistemi, bu process'i seçebilir ve çalıştırmaya başlayabilir.
- **Bekleme Durumu (Waiting)**: Process, bir olayın gerçekleşmesini bekliyor ve bu nedenle CPU'yu kullanamamaktadır. Hazır durumda değilken, başka bir process CPU'yu kullanabilir.

### En Çok Hangi Durumda Kalır?

- Bir process, genellikle **Waiting (Bekleme)** durumunda daha fazla zaman harcar. Çünkü I/O işlemleri, ağ erişimleri veya zamanlayıcıların beklenmesi gibi nedenlerle çoğu process, çalışırken bekleme durumuna geçer.
- Çoğu modern işletim sistemi, çoklu görev yönetimini optimize etmek için bu durumları dikkate alır ve CPU'yu verimli bir şekilde kullanarak process'lerin mümkün olduğunca hızlı bir şekilde çalışmasını sağlar.

### Özet

- **İcra Durumu (Execution State)**, bir process'in o an ne yaptığını gösterir ve üç ana durumda olabilir: Running, Ready, ve Waiting.
- **Running** durumu, CPU'yu kullanan process'i ifade ederken, **Ready** durumu, CPU için bekleyen process'i gösterir. **Waiting** durumu ise, bir olayın tamamlanmasını bekleyen process'i temsil eder.
- Process'ler, genellikle bekleme durumunda daha fazla zaman harcarlar, bu da sistem kaynaklarının verimli bir şekilde yönetilmesine olanak tanır.

---

### Process Durum (Context) Geçişleri

Bir process, çalışma süresi boyunca farklı durumlar arasında geçiş yapabilir. Bu geçişler, işletim sistemi tarafından yönetilen çeşitli olaylara ve durumlara bağlıdır. Aşağıda, **New**, **Ready**, **Running**, **Waiting**, ve **Terminated** durumları arasındaki geçişlerin nedenlerini açıklayalım.

### Process Durumları ve Geçişler

1. **New (Yeni)**
    - **Tanım**: Yeni bir process oluşturuluyor.
    - **Geçişler**:
        - **create**: Bir process oluşturulduğunda, bu durumdan **Ready** durumuna geçer. İşletim sistemi, yeni process için gerekli kaynakları ayırır ve onu çalıştırılmak üzere hazır hale getirir.
2. **Ready (Hazır)**
    - **Tanım**: Process, CPU'yu kullanmak için sırada bekliyor.
    - **Geçişler**:
        - **schedule**: İşletim sistemi, hazır durumundaki bir process'i seçerek **Running** durumuna geçirir. Zamanlayıcı (scheduler), bu seçim için çeşitli kriterlere dayanabilir.
        - **unschedule**: Eğer mevcut **Running** process bir süre sonunda devre dışı bırakılırsa veya daha yüksek öncelikli bir process çalıştırılacaksa, **Ready** durumundaki process tekrar aktif hale geçebilir.
3. **Running (Çalışıyor)**
    - **Tanım**: Process, CPU üzerinde aktif olarak çalışıyor.
    - **Geçişler**:
        - **unschedule**: Bir process, belirli bir süre sonunda veya bir I/O işlemi başlatıldığında **Waiting** durumuna geçer.
        - **kill or exit**: Eğer process, kendi isteğiyle sonlanırsa (örneğin, işlemi bitirme), **Terminated** durumuna geçer. Ayrıca, başka bir process bu process'i sonlandırırsa da **Terminated** durumuna geçer.
4. **Waiting (Bekliyor)**
    - **Tanım**: Process, bir olayın gerçekleşmesini bekliyor (örneğin, I/O işleminin tamamlanması).
    - **Geçişler**:
        - **I/O, page fault, etc.**: Bu olaylar sırasında, process **Running** durumundan **Waiting** durumuna geçer.
        - **I/O done**: Bekleyen I/O işlemi tamamlandığında, process tekrar **Ready** durumuna geçer.
5. **Terminated (Tamamlandı)**
    - **Tanım**: Process sonlanmış ve artık sistemde bulunmamaktadır.
    - **Geçişler**:
        - **kill or exit**: Process, kendi isteğiyle veya başka bir process tarafından sonlandırıldığında bu duruma geçer.

### Özet

- **Process Durumları**:
    - **New**: Yeni oluşturulmuş bir process.
    - **Ready**: CPU'yu kullanmak için bekleyen process.
    - **Running**: CPU üzerinde aktif olarak çalışan process.
    - **Waiting**: Olayların tamamlanmasını bekleyen process.
    - **Terminated**: Sonlandırılmış process.
- **Geçişler**:
    - **create**: New durumundan Ready durumuna geçiş.
    - **schedule**: Ready durumundan Running durumuna geçiş.
    - **unschedule**: Running durumundan Waiting veya Ready durumuna geçiş.
    - **I/O done**: Waiting durumundan Ready durumuna geçiş.
    - **kill or exit**: Running durumundan Terminated durumuna geçiş.

Bu geçişler, işletim sisteminin kaynakları verimli bir şekilde yönetmesine ve çoklu görev (multitasking) yeteneklerini optimize etmesine olanak tanır.

---

### Process State Transition: Örnek

İşletim sistemlerinde, process'ler farklı durumlar arasında geçiş yaparken, her bir process'in durumunu ve özelliklerini yönetmek için bazı veri yapıları kullanılır. **Process Control Block (PCB)**, bu veri yapılarından biridir ve her process hakkında önemli bilgileri saklar.

### Örnek: İki Process'in Durum Geçişleri

Aşağıda, iki process'in (Process A ve Process B) farklı durumlar arasında nasıl geçiş yapabileceğine dair bir örnek verilmiştir:

1. **Process A:**
    - Başlangıçta **New** durumunda oluşturulur.
    - **create** olayından sonra **Ready** durumuna geçer.
    - İşletim sistemi tarafından seçilerek **Running** durumuna geçer (schedule).
    - Bir I/O isteği başlatır ve **Waiting** durumuna geçer.
    - I/O işlemi tamamlandığında, **Ready** durumuna döner.
    - Zamanlayıcı tarafından tekrar seçildiğinde, tekrar **Running** durumuna geçer.
    - İşlem tamamlandığında, **Terminated** durumuna geçer.
2. **Process B:**
    - Başlangıçta **New** durumunda oluşturulur.
    - **create** olayından sonra **Ready** durumuna geçer.
    - İşletim sistemi tarafından seçilerek **Running** durumuna geçer (schedule).
    - Bir I/O isteği başlatmaz, bu nedenle zaman dilimi sona erdiğinde **Ready** durumuna döner (unschedule).
    - Hazırda beklerken I/O isteği yapar ve **Waiting** durumuna geçer.
    - I/O işlemi tamamlandığında, **Ready** durumuna döner.
    - Zamanlayıcı tarafından tekrar seçildiğinde, tekrar **Running** durumuna geçer.
    - İşlem tamamlandığında, **Terminated** durumuna geçer.

---

### Veri Yapıları

1. **Process Control Block (PCB)**:
    - Her process hakkında bilgi saklar.
    - **Register Context**: Process'in durumunu tanımlayan bir dizi kayıt (register) içerir. Bu, CPU üzerindeki her process için gerekli durumu korur.
    - **Process List**: İşletim sisteminin mevcut tüm process'leri izlemek için kullandığı bir listedir. Bu liste, process'lerin durumlarını (Ready, Running, Blocked) takip eder.
    - **Ready Processes**: Hazır durumda bekleyen process'lerin listesidir. İşletim sistemi, bu listedeki process'lerden birini çalıştırmak için seçer.
    - **Blocked Processes**: I/O veya diğer bekleme durumlarında olan process'lerin listesidir.
    - **Current Running Process**: Şu anda CPU'yu kullanan process'tir. İşletim sistemi, bu process'in durumunu sürekli olarak günceller.

### Özet

- **Process Durumları**:
    - **New**, **Ready**, **Running**, **Waiting**, ve **Terminated** durumları, her process'in farklı aşamalarını temsil eder.
- **Veri Yapıları**:
    - **PCB**: Her process hakkında bilgi saklar.
    - **Register Context**: Process'in durumunu tanımlayan kayıtları içerir.
    - **Process List**: Tüm process'lerin durumlarını izler.
    - **Ready/Blocked Processes**: Hazır ve bekleme durumundaki process'leri yönetir.
    - **Current Running Process**: Şu anda çalışan process'i takip eder.

Bu veri yapıları ve durum geçişleri, işletim sisteminin çoklu görev yönetimi için kritik öneme sahiptir ve sistemin verimliliğini artırır.

---

Pintos, bir eğitim amaçlı işletim sistemidir ve bu yapı, işletim sisteminin çoklu görev (multitasking) yeteneklerini yönetmek için kullanılır. Kodun her bir bölümünü detaylı olarak açıklayalım:

### `struct thread`

Bu yapı, bir iş parçacığını (thread) temsil eder ve iş parçacığının durumunu ve özelliklerini saklar.

```c
struct thread {
```

- **struct thread**: Bu bir yapı tanımıdır ve `thread` isimli bir yapı oluşturulmaktadır. İş parçacığına ait çeşitli bilgileri saklamak için kullanılacaktır.

### Üyeler (Members)

1. **`tid_t tid;`**
    - **Açıklama**: Thread kimliği (identifier). Her iş parçacığının benzersiz bir kimliği vardır. `tid_t`, bu kimliği temsil eden bir veri tipidir.
2. **`enum thread_status status;`**
    - **Açıklama**: Thread'in mevcut durumunu temsil eder. `thread_status` isimli bir enum (sıralı tür) kullanılarak thread'in durumları (örneğin, çalışıyor, bekliyor, sonlandı vb.) tanımlanır.
3. **`char name[16];`**
    - **Açıklama**: Thread'in adını saklar. Bu, özellikle hata ayıklama (debugging) süreçlerinde faydalıdır. Dizi boyutu 16 karakterle sınırlıdır.
4. **`uint8_t *stack;`**
    - **Açıklama**: Thread'in yığın (stack) işaretçisini tutar. Yığın, bir iş parçacığının fonksiyon çağrıları ve yerel değişkenleri için kullanılır.
5. **`int priority;`**
    - **Açıklama**: Thread'in önceliğini temsil eder. İş parçacıklarının önceliklerine göre işletim sistemi tarafından yönetim ve zamanlama yapılır.
6. **`struct list_elem allelem;`**
    - **Açıklama**: Tüm iş parçacıkları listesinin bir elemanını temsil eder. Bu, tüm iş parçacıklarını içeren bir liste yapısının parçasıdır.
7. **`struct list_elem elem;`**
    - **Açıklama**: Bu, genel bir liste elemanı olarak kullanılır. Thread'in belirli bir durumda (örneğin, bekleme veya hazır) tutulmasını sağlar.
8. **`#ifdef USERPROG`**
    - **Açıklama**: Eğer `USERPROG` makrosu tanımlıysa, bu bölüm derlenir. Bu, kullanıcı programlarını destekleyen bir yapı olduğunun göstergesidir.
9. **`uint32_t *pagedir;`**
    - **Açıklama**: Sayfa dizinini (page directory) temsil eder. Bu, bellek sanallaştırma ve kullanıcı programları için gerekli olan bir yapıdır.
10. **`#endif`**
    - **Açıklama**: `#ifdef USERPROG` için bir bitiş işareti. Kullanıcı programları desteklenmediğinde bu bölüm derlenmez.
11. **`unsigned magic;`**
    - **Açıklama**: Yığın taşmasını tespit etmek için kullanılan bir değer. Bu, iş parçacığının yığını üzerinde beklenmeyen bir yazma işlemi olup olmadığını kontrol etmek için kullanılır. `magic` değeri, iş parçacığı yapısının doğruluğunu sağlamak için bir tür güvenlik mekanizmasıdır.

### Özet

Bu `struct thread` yapısı, Pintos işletim sisteminde iş parçacıklarının temel özelliklerini tanımlamak için kullanılır. Her iş parçacığının bir kimliği, durumu, adı, yığın işaretçisi, öncelik seviyesi ve bazı ek bilgileri saklamak için gerekli alanlar vardır. `magic` alanı, güvenlik amacıyla eklenmiş ve yığın taşmalarını tespit etmek için bir kontrol mekanizması sağlamaktadır. İşletim sistemi, bu yapı aracılığıyla iş parçacıklarını yönetir ve farklı durumlar arasında geçiş yapmasını sağlar.

---

xv6, eğitim amaçlı bir UNIX benzeri işletim sistemidir ve bu yapı, işletim sisteminin süreçleri (process) takip etmesini sağlar.

### `struct proc`

Bu yapı, her bir işlem için işletim sisteminin takip ettiği bilgileri içerir. İşlemlerin durumunu ve özelliklerini yönetmek için kullanılır.

```c
struct proc {
```

- **struct proc**: İşlem yapısını tanımlayan bir yapı. Her işlem için gerekli olan bilgileri saklar.

### Üyeler (Members)

1. **`char *mem;`**
    - **Açıklama**: İşlemin bellek başlangıcını gösteren bir işaretçi. Bu, işlemin kullandığı belleğin başlangıç adresini belirtir.
2. **`uint sz;`**
    - **Açıklama**: İşlemin bellekte kapladığı alanın boyutunu belirtir. Bu, işlemin bellek alanının ne kadarını kullandığını gösterir.
3. **`char *kstack;`**
    - **Açıklama**: İşlemin çekirdek yığınının (kernel stack) alt kısmını gösteren bir işaretçi. İşlem çalışırken kullanılacak olan yığın belleğini temsil eder.
4. **`enum proc_state state;`**
    - **Açıklama**: İşlemin mevcut durumunu belirtir. Bu enum, işlemin durumunu (örneğin, çalışıyor, bekliyor, sonlandı vb.) takip etmek için kullanılır.
5. **`int pid;`**
    - **Açıklama**: İşlem kimliği (Process ID). Her işlem için benzersiz bir kimlik numarasıdır. İşletim sistemi, işlemleri bu kimlikler aracılığıyla takip eder.
6. **`struct proc *parent;`**
    - **Açıklama**: İşlemin ebeveyn (parent) işlemini gösteren bir işaretçi. Bu, işlemin hangi işlemden türediğini belirtir.
7. **`void *chan;`**
    - **Açıklama**: Eğer sıfırdan farklı bir değere sahipse, bu işlem bir kanalda (channel) uyuyordur. Bu alan, bir işlem beklerken hangi kaynağa bağlı olduğunu belirtmek için kullanılır.
8. **`int killed;`**
    - **Açıklama**: Eğer sıfırdan farklı bir değere sahipse, işlem öldürülmüştür. Bu, işlemin öldürüldüğünü belirtmek için kullanılır.
9. **`struct file *ofile[NOFILE];`**
    - **Açıklama**: Açık dosyaları tutan bir dizi. `NOFILE`, açık dosya sayısını belirten bir sabittir. Her işlem, kendisine ait açık dosyaları bu dizide saklar.
10. **`struct inode *cwd;`**
    - **Açıklama**: İşlemin mevcut çalışma dizinini (current working directory) tutar. Bu, işlemin dosya sistemindeki mevcut konumunu belirtir.
11. **`struct context context;`**
    - **Açıklama**: İşlemi çalıştırmak için geçiş yapılacak olan durum (context) bilgisini tutar. İşlemin çalıştığı yeri ve durumunu tanımlar.
12. **`struct trapframe *tf;`**
    - **Açıklama**: Mevcut kesme (interrupt) için kullanılan tuzak çerçevesini (trap frame) tutar. İşlemin kesme durumunda geri dönmesi için gerekli olan bilgileri içerir.

### Özet

**`struct proc`** yapısı, xv6 işletim sisteminin her bir işlemi için gerekli bilgileri içerir. Bu bilgiler arasında işlem bellek başlangıcı, bellek boyutu, işlem durumu, işlem kimliği, ebeveyn işlemi, açık dosyalar, mevcut çalışma dizini ve işlem geçişi için gerekli durum bilgileri bulunur. Bu yapı, işletim sisteminin çoklu görev (multitasking) yönetimi için kritik öneme sahiptir. İşletim sistemi, bu bilgileri kullanarak işlemler arasında geçiş yapar ve her bir işlemi yönetir.

---

### **Tangent: Idling (Boşta Kalma)**

### **Tüm İşlemler Engellendiğinde Hangi İşlem Planlanmalı?**

Eğer tüm işlemler engellendiyse (blocked), planlanan işlem **boşta (idle)** işlemidir. Modern çekirdekler, diğer hiçbir işlem çalışmaya hazır olmadığında çalıştırılan düşük öncelikli bir boşta işlem kullanır.

**Boşta İşlem Nedir?**

- **Tanım**: Boşta işlem, sistemde başka hiçbir işlem çalışamaz durumda olduğunda devreye giren bir işlemdir. Bu işlem, sistemin temel çalışma sürekliliğini sağlamak için önemlidir.

### **Boşta İşlemin Özellikleri**

- **Düşük Öncelik**: Boşta işlem, diğer işlemlere göre düşük öncelikli bir işlemdir. Bu, diğer işlemler çalışmaya hazır olduğunda boşta işlemin devre dışı bırakılacağı anlamına gelir.
- **Engellenmez**: Boşta işlem, hiçbir zaman engellenmez. Yani, başka bir işlem çalışmadığında bile kendisi engellenmez.
- **Giriş/Çıkış Yapmaz**: Boşta işlem, giriş/çıkış (I/O) işlemleri gerçekleştirmez. Bu, işlemcinin boşta işlem sırasında diğer işlemleri beklemek için kullanılmadığı anlamına gelir.

### **Boşta İşlemin Avantajları**

1. **Sürekli Çalışma**: Boşta işlem, her zaman en az bir işlemin çalışmasını garanti eder. Bu, işlemci kullanımını optimize eder ve sistemin boşa gitmesini önler.
2. **Planlama Kolaylığı**: Boşta işlem olmadan, planlayıcı (scheduler), hiçbir işlem çalışmaya hazır değilse durumu kontrol etmek zorunda kalırdı. Bu, karmaşık ve zaman alıcı bir işlem olabilir.
3. **Basit Çözüm**: Boşta işlem, karmaşık bir problemi basit bir şekilde çözer. Sistemin düzgün çalışmasını sağlarken, diğer işlemler için de bir alan açar.

### **Özet**

Boşta işlem, tüm diğer işlemler engellendiğinde planlanan bir işlemdir. Bu işlem, düşük öncelikli bir yapıdadır ve sistemin her zaman en az bir işlem çalıştırmasını garanti eder. Boşta işlem sayesinde, planlayıcılar işlem durumlarını kontrol etmek zorunda kalmadan sistemin devamlılığını sağlayabilirler. Bu, işletim sisteminin etkinliğini artırır ve kaynakların daha verimli kullanılmasını sağlar.

---

### **İşletim Sistemi Veri Yapıları**

İşletim sistemi, aktif işlemlerin (process) bilgilerini saklamak için veri yapıları (genellikle diziler veya listeler) kullanır. Her bir işlemin bilgileri, **İşlem Kontrol Bloğu (Process Control Block - PCB)** adı verilen bir yapı içinde saklanır. Linux işletim sisteminde bu yapı **task_struct** olarak adlandırılır.

### **İşlem Kontrol Bloğu (PCB)**

PCB, her bir işlemin durumu ve özellikleri hakkında önemli bilgileri içerir. Aşağıda PCB içinde bulunan temel alanlar açıklanmaktadır:

1. **Process Identifier (PID)**
    - **Tanım**: İşlem Kimliği (Process ID). Her bir işlemin benzersiz tanımlayıcısıdır. PID, işlemleri takip etmek ve yönetmek için kullanılır.
2. **Process State**
    - **Tanım**: İşlemin mevcut durumu. Örneğin, bir işlem "ready" (hazır), "running" (çalışıyor) veya "blocked" (engellenmiş) olabilir. İşlem durumu, işletim sisteminin hangi işlemlerin çalıştırılabileceğini belirlemesine yardımcı olur.
3. **Pointer to Parent Process**
    - **Tanım**: İşlemin ebeveyn (parent) işlemini gösteren bir işaretçi. Bu, işlem hiyerarşisini (parent-child relationship) takip etmek için kullanılır. Linux'ta bu bilgiyi görmek için `cat /proc/self/status` komutu kullanılabilir.
4. **CPU Context**
    - **Tanım**: Eğer işlem çalışmıyorsa, bu alan CPU bağlamını (context) tutar. CPU bağlamı, işlemin çalıştığı sırada CPU'nun durumunu ve kayıtlarını içerir. Bu bilgi, işlemin tekrar çalışmaya başladığında hangi durumdan devam edeceğini belirlemek için gereklidir.
5. **Pointer to Address Space**
    - **Tanım**: İşlemin bellek alanını gösteren bir işaretçi. Bu alan, işlemin kullandığı bellek bloklarının adreslerini içerir. Bu bilgiyi `cat /proc/self/maps` komutuyla görüntülemek mümkündür.
6. **Pointer to List of Open Files**
    - **Tanım**: Açık dosyaları tutan bir işaretçi. Bu, işlemin hangi dosyaları açtığını gösterir ve dosya tanımlayıcıları (file descriptors) içerir. Bu dosyalara erişim ve yönetim için gerekli bilgilerdir. Dosya bilgilerini görmek için `cat /proc/self/fdinfo/*` komutu kullanılabilir.

### **Özet**

İşletim sistemi, aktif işlemleri yönetmek için çeşitli veri yapıları kullanır ve her bir işlemin bilgilerini saklamak için İşlem Kontrol Bloğu (PCB) yapısını kullanır. PCB, PID, işlem durumu, ebeveyn işlemi, CPU bağlamı, bellek alanı ve açık dosyalar gibi önemli bilgileri içerir. Bu yapı, işletim sisteminin çoklu görev yönetimini ve kaynak kullanımını etkin bir şekilde sağlamasına yardımcı olur.

---

### **Ayrım: Program, İşlem ve İplik (Thread)**

### **Program**

- **Tanım**: Disk üzerinde bulunan çalıştırılabilir bir dosyadır. Bir işlemi başlatmak için gerekli tüm bilgileri içerir. Program, kodun yanı sıra değişkenler, yapılandırmalar ve başlangıç bilgilerini de içerir.
- **Örnek**: Bir oyun veya bir kelime işlemci programı.

### **İşlem (Process)**

- **Tanım**: Bir programın çalışan örneğidir. İşlem, programın kodunu ve verilerini (data section) içeren bir bellek alanına sahiptir. İşlem, bir işlemci üzerinde çalışmakta olan bir yapıdır ve yürütme sırasında durumu takip eden bir yığın (stack) ile başlatılır.
- **Özellikler**:
    - Her bir işlem, kendine özgü bir bellek alanına ve kaynaklara sahiptir.
    - İşlemler, işlem kontrol blokları (PCB) ile yönetilir.

### **İplik (Thread)**

- **Tanım**: Bir işlem içinde çalışan daha küçük bir yürütme birimidir. Bir işlem, aynı bellek alanını paylaşan birden fazla iplik içerebilir. Bu, aynı veri üzerinde birden fazla işlem yapabilmeyi sağlar.
- **Özellikler**:
    - İplikler, işlem içindeki kaynakları ve belleği paylaşır.
    - İplikler arasında daha hızlı iletişim sağlanır çünkü aynı bellek alanını kullanırlar.

---

### **İşletim Sistemi Servislerinin İstenmesi**

### **Sistem Çağrıları (System Calls)**

- **Tanım**: İşlemler, işletim sisteminden hizmet talep etmek için sistem çağrı API'si (Application Programming Interface) kullanır.
- **İşleyiş**:
    - Sistem çağrıları, yürütmeyi işletim sistemine aktarır. İşletim sistemi genellikle daha yüksek ayrıcalıklara sahip olarak çalıştığı için, ayrıcalıklı işlemleri gerçekleştirebilir.
    - Hassas işlemler (örneğin, donanım erişimi veya ham bellek erişimi) belirli ayrıcalıklara ihtiyaç duyar.

### **Engelleme (Blocking)**

- **Durum**: Bazı sistem çağrıları (örneğin, `read`, `write`), işlemin engellenmesine (blocking) yol açabilir. Bu durumda, işletim sistemi diğer işlemleri planlayabilir. Yani, bir işlem I/O işlemi gerçekleştirirken beklerken, işletim sistemi başka bir işlemi çalıştırabilir.

### **Kütüphaneler (Libraries)**

- **Kütüphane Örneği**: `libc` gibi kütüphaneler, sistem çağrılarının karmaşasını soyutlar ve işletim sistemi işlevselliğini normal fonksiyon çağrıları olarak dışa aktarır. Yani, kullanıcı uygulamaları bu kütüphaneleri kullanarak daha basit ve anlaşılır bir şekilde işletim sistemi ile etkileşimde bulunabilir.

### **Özet**

Program, işlemin temelini oluşturan çalıştırılabilir bir yapıdır. İşlem, bir programın yürütülmekte olan örneğidir ve iplikler, aynı işlem içinde çoklu yürütme birimleri olarak görev yapar. İşlemler, işletim sistemi servislerini istemek için sistem çağrılarını kullanır ve bu süreçte işletim sistemi, daha yüksek ayrıcalıklara sahip olarak çalışır. Kütüphaneler, bu süreçleri daha erişilebilir hale getirir ve kullanıcıların işletim sistemi işlevlerine daha kolay ulaşmasını sağlar.

---

## Son Özet

### **1. Temel Kavramlar**

- **Program**: Disk üzerinde bulunan çalıştırılabilir bir dosya. İşlemi başlatmak için gerekli tüm bilgileri içerir.
- **İşlem (Process)**: Bir programın çalışan örneği. İşlem, kendine ait bir bellek alanı ve veri yapısına sahiptir. İşlemler, işlem kontrol blokları (PCB) ile yönetilir.
- **İplik (Thread)**: Bir işlem içinde çalışan daha küçük bir yürütme birimidir. İplikler, aynı bellek alanını paylaşarak veri üzerinde aynı anda işlem yapma yeteneği sağlar.

### **2. İşlem Kontrol Bloğu (PCB)**

PCB, her bir işlemin bilgilerini saklar ve aşağıdaki alanları içerir:

- **Process Identifier (PID)**: İşlem kimliği.
- **Process State**: İşlemin mevcut durumu (örneğin, hazır, çalışıyor, engellenmiş).
- **Pointer to Parent Process**: Ebeveyn işlemi gösteren işaretçi.
- **CPU Context**: İşlemin çalışmadığı durumdaki CPU durumu.
- **Pointer to Address Space**: İşlemin bellek alanını gösteren işaretçi.
- **Pointer to List of Open Files**: Açık dosyaların bilgilerini tutar.

### **3. İşlem Durumları ve Geçişleri**

Bir işlem, aşağıdaki üç temel durumdan birinde bulunabilir:

- **Running**: İşlem CPU'yu kullanıyor.
- **Ready**: İşlem çalışmaya hazır, ancak şu anda çalışmıyor.
- **Blocked**: İşlem bir I/O talebi yapmış ve bekliyor.

Geçişler:

- **Scheduled**: İşlem çalışmaya başlamıştır.
- **Descheduled**: İşlem durdurulmuştur.

### **4. Sistem Çağrıları (System Calls)**

- İşlemler, işletim sisteminden hizmet talep etmek için sistem çağrı API'sini kullanır.
- Sistem çağrıları, işletim sistemine daha yüksek ayrıcalıklarla geçiş yapar ve hassas işlemleri (donanım erişimi, bellek erişimi vb.) gerçekleştirmek için gereklidir.
- Bazı sistem çağrıları, işlemin engellenmesine neden olabilir ve bu durum diğer işlemlerin çalışmasına olanak tanır.

### **5. Kütüphaneler**

- Kütüphaneler (örneğin `libc`), sistem çağrılarının karmaşasını soyutlar ve işletim sistemi işlevlerini daha erişilebilir hale getirir. Kullanıcı uygulamaları, bu kütüphaneleri kullanarak sistem işlevlerine daha kolay erişebilir.

### **6. İdling (Boşta Kalma)**

- Tüm işlemler engellenmişse, işletim sistemi bir **idle process** (boşta işlem) kullanarak sürekli bir işlem çalıştırır. Bu, işletim sisteminin her zaman çalışacak en az bir işlem bulundurmasını garanti eder.

---