# 6. Hafta

**Zamanlama (Scheduling): Giriş**

Zamanlama, işletim sistemlerinin en önemli işlevlerinden biridir. Çünkü bir bilgisayarda aynı anda birçok iş yapılabilir. Ancak, bilgisayarın tek bir işlemciyi bir anda sadece bir işlem için kullanabileceğini unutmayalım. İşletim sistemleri bu noktada devreye girerek, işlemcinin her işlemi nasıl ve ne zaman çalıştıracağını düzenler. İşte burada zamanlama devreye girer.

Bu derste bazı varsayımlar yapıyoruz ki zamanlama algoritmalarını daha basit bir şekilde anlayabilelim. Şimdi bu varsayımlara bakalım:

1. **Her işin aynı sürede çalıştığını kabul ediyoruz.**
    
    Bu varsayım, gerçek dünyada çok sık rastlanmasa da işleri basitleştirmek için yararlıdır. Yani, her işlemin aynı sürede bitmesini öngörmek, farklı sürelerde çalışan işler yerine daha basit hesaplamalar yapmamıza olanak sağlar. Gerçek dünyada her işin süresi değişir, çünkü bazı işlemler daha fazla işlemci zamanı gerektirir, bazıları ise daha az.
    
2. **Tüm işlerin aynı anda sisteme geldiğini varsayıyoruz.**
    
    Gerçek dünyada işler (yani programlar veya işlemler) genellikle farklı zamanlarda gelir, yani kullanıcılar veya diğer sistem bileşenleri farklı zamanlarda işlem başlatır. Ama bu varsayımda, işlerin aynı anda geldiğini kabul ediyoruz. Bu durum, algoritmaların performansını anlamada bize kolaylık sağlar. Normalde zaman farkı olduğunda, zamanlayıcı hangi işin önce çalışacağını hesaplamak zorunda kalır.
    
3. **İşlerin sadece CPU kullandığını kabul ediyoruz.**
    
    Normalde işler CPU dışında giriş/çıkış (I/O) işlemleri de yapar. Örneğin, bir programın veri tabanına veri okuma/yazma işlemi yapması gibi. Ancak, bu varsayımda her işin sadece CPU kullandığını düşünüyoruz. Gerçekte ise I/O işlemleri zamanlama algoritmalarını karmaşık hale getirir çünkü I/O sırasında iş CPU'yu kullanmaz, ancak zamanlayıcı bu süreyi de yönetmek zorundadır.
    
4. **Her işin ne kadar sürede tamamlanacağını bildiğimizi varsayıyoruz.**
    
    Bu, aslında genellikle pek de mümkün olmayan bir varsayımdır çünkü işlemlerin çalışma süresi her zaman önceden tahmin edilemez. Ama bu varsayım, hangi işin ne zaman bitirileceğini hesaplamayı kolaylaştırır. Gerçek dünyada belirsizlik daha fazladır, çünkü bir işlemin tamamlanması sırasında çeşitli beklenmedik olaylar olabilir.
    

---

**İşlem Zamanlaması (Process Scheduling)**

İşletim sistemlerinde işlem zamanlayıcı (process scheduler), her bir işleme işlemciyi ne zaman kullanacağını belirler. Bu işlem sırasında zamanlayıcı, işlemler arasında geçişler yapar. İşletim sistemi, her işlemin kendi işlemcisini kullanıyormuş gibi görünmesini sağlar ki bu aslında CPU'nun çok hızlı bir şekilde işlemler arasında geçiş yapmasıyla gerçekleşir. Bu geçişler "context switch" (bağlam değişimi) olarak bilinir. Bir işlemin CPU'dan çıkıp başka bir işlemin devreye girmesi, çok hızlı yapılır, bu yüzden kullanıcıya tüm işlemler aynı anda çalışıyormuş gibi gelir.

Buradaki en önemli hedeflerden biri CPU'yu sürekli meşgul tutmak, yani işlemcinin boşa vakit harcamamasını sağlamaktır. Aynı zamanda zamanlayıcı, işlemler arasında adaletli bir dağılım yapar. Yani, bir işlemin CPU'yu gereğinden fazla kullanıp diğer işlemleri bekletmesine izin vermez.

Zamanlayıcı sadece işlemleri değil, aynı zamanda **thread'leri** (iş parçacıklarını) de zamanlayabilir. Thread'ler, bir işlem içinde daha küçük, bağımsız çalışabilen yapılardır. İşletim sistemleri thread'leri de aynı işlemler gibi sıraya koyar ve CPU'da çalıştırır. Bu, büyük bir işlemin daha küçük parçalara ayrılarak daha verimli çalıştırılmasına olanak sağlar.

Bu temel prensipler çerçevesinde, farklı zamanlama algoritmaları geliştirilir. Bu algoritmaların bazıları, işlemlerin ne kadar süreceğini bilmeden, bazıları ise bu bilgiyi kullanarak çalışır. Amacımız, CPU'nun her zaman meşgul olmasını ve işlemlerin adil bir şekilde sırayla çalıştırılmasını sağlamaktır.

---

### **Context Switch (Bağlam Değişimi)**

**Context Switch** yani bağlam değişimi, işletim sistemlerinde kritik bir mekanizmadır. Bu mekanizma sayesinde, CPU bir işlemden diğerine geçiş yapar. Bir işlem (process) çalışırken, bir başka işlemi çalıştırabilmek için CPU'nun önce mevcut işlemin bağlamını (durumunu) kaydetmesi, ardından yeni işlemin bağlamını yüklemesi gerekir. Bu sırada CPU, işlemci üzerinde yapılan tüm kayıtları (register'lar) ve bellek bilgilerini saklar, böylece işlem kaldığı yerden devam edebilir.

- **Neden önemlidir?**
    
    Çünkü yeni bir işlem veya iş parçacığının (thread) çalışmasına izin verir. Bağlam değişimi olmadan, bir işlem sürekli CPU'yu meşgul eder ve diğer işlemler çalıştırılamaz hale gelir. Bu yüzden bağlam değişimi, çoklu görev (multitasking) işlevi açısından hayati öneme sahiptir.
    
- **Bağlam değişimi neden ek yük getirir?**
    
    Çünkü bağlam değiştirilirken işlemci o sırada hiçbir iş yapmaz, yani gerçek anlamda işlem gerçekleştirilmez. İşlemci, sadece mevcut bağlamı kaydedip yeni bağlamı yüklemeyle meşguldür. Bu, CPU'nun aslında işlem yapmadığı bir süreçtir ve "overhead" yani ek yük olarak adlandırılır.
    
- **Bağlam değişimi, çekirdek modunda (kernel code) gerçekleşir.**
    
    İşlem bağlamının değişimi, işletim sisteminin çekirdek (kernel) seviyesinde gerçekleşir. Çekirdek kodu, sistemin en yetkili ve temel düzeydeki kodlarıdır, çünkü CPU'nun yönetimini burada işletim sistemi yapar.
    
    Buna karşılık, **işlem kodu** (user code), kullanıcının çalıştırdığı programlara aittir. İşlemler kendi kullanıcı alanında çalışır, ancak çekirdek işlemleri gerçekleştirdiğinde işletim sistemine geçiş yapar. İşlemler genellikle CPU'yu kendileri kontrol etmezler, bu görev işletim sistemi tarafından yapılır.
    

Bağlam değişimi zaman çizelgesi üzerinden şöyle özetlenebilir:

- CPU, bir işlemi çalıştırırken kullanıcı kodu (user code) çalışır.
- İşlem bir I/O beklediğinde veya zamanlayıcı başka bir işlemi çalıştırmaya karar verdiğinde bağlam değişimi olur.
- Çekirdek (kernel) devreye girer ve bağlam değişimi yapılır.
- Diğer işlem (örneğin, "Process B") devreye girer ve CPU'da çalıştırılır.

### **Process Scheduling (İşlem Zamanlaması)**

İşlem zamanlayıcı (process scheduler), CPU'nun hangi işlemi ne zaman çalıştıracağını belirler. Bu işlem sırasında işletim sistemi, her işleme kendi işlemcisine sahipmiş gibi bir ilüzyon yaratır. Bu, **eşzamanlılık** (concurrency) ya da **sahte paralellik** (pseudo parallelism) olarak bilinir. Aslında, tek bir işlemci (CPU) tek bir zaman diliminde sadece bir işlemi çalıştırabilir. Ancak, zamanlayıcı işlemler arasında o kadar hızlı geçiş yapar ki, kullanıcı tüm işlemlerin aynı anda çalıştığını zanneder.

- **Tek bir CPU ile çoklu görev (multitasking) nasıl yapılır?**
    
    Örneğin, aynı anda müzik dinleyebilir, bir program üzerinde çalışabilir ve dosya indirebilirsiniz. Zamanlayıcı, bu görevler arasında hızlıca geçiş yapar ve her birine küçük zaman dilimleri ayırır. Bu, kullanıcıya işlemler sanki aynı anda çalışıyormuş gibi gelir.
    
- **İşlem zamanlayıcı ne yapar?**
    
    Zamanlayıcı, sistemdeki mevcut işlemler arasında bir seçim yapar ve bir sonraki çalıştırılacak işlemi CPU'ya verir. İşlemlerin verimli ve adil bir şekilde çalıştırılmasını sağlamak için sistemde çeşitli kuyruklar kullanılır:
    
    1. **Job queue (İş kuyruğu)**: Sistemdeki tüm işlemlerin bulunduğu kuyruktur. Henüz çalıştırılmamış veya çalışmayı bekleyen tüm işlemler burada tutulur.
    2. **Ready queue (Hazır kuyruk)**: Çalışmaya hazır olan işlemler bu kuyruktadır. Bu işlemler CPU tarafından seçilmeyi bekler.
    3. **Device queues (Aygıt kuyrukları)**: Giriş/Çıkış (I/O) cihazlarını bekleyen işlemler bu kuyruklarda yer alır. Örneğin, kullanıcı bir girdi bekliyorsa (scanf işlemi gibi), işlem I/O cihazını bekleyen işlemler arasına eklenir.
    
    İşlemler, bu kuyruklar arasında sürekli olarak geçiş yapar. Örneğin, bir işlem CPU'da çalışırken bir I/O işlemi yapması gerekirse, CPU'dan ayrılır ve aygıt kuyruğuna geçer. I/O işlemi tamamlandığında ise tekrar hazır kuyruğuna döner ve CPU'yu kullanmak için bekler.
    

---

**Zamanlayıcılar (Schedulers)**, işletim sistemlerinde hangi işlemlerin ne zaman çalıştırılacağını belirleyen mekanizmalardır. İşletim sistemleri bu mekanizmalar sayesinde CPU'nun hangi işlemi ne zaman çalıştıracağını kontrol eder. Zamanlayıcılar genellikle üç ana kategoriye ayrılır:

### 1. **Long-term Scheduler (Uzun Dönemli Zamanlayıcı) ya da İş Zamanlayıcı**

- **Görevi nedir?**Uzun dönemli zamanlayıcı, iş kuyruğundan (job queue) hangi işlemlerin hazır kuyruk (ready queue) içine alınacağını belirler. İşletim sistemine çok sayıda işlem geldiğinde, bu zamanlayıcı hangi işlemlerin CPU'yu kullanmak üzere hazır duruma getirileceğine karar verir.
- **Çoklu görevliliği (multitasking) nasıl kontrol eder?**Bu zamanlayıcı, aynı anda çalışacak işlem sayısını yani çoklu görevliliğin derecesini kontrol eder. Eğer çok fazla işlem hazır durumda olursa, CPU bu işlemleri sırayla çalıştırmakta zorlanabilir. Bu yüzden uzun dönemli zamanlayıcı, hangi işlemlerin sisteme alınacağına dikkat eder.
- **Yavaş çalışır:**Genellikle bu zamanlayıcı yavaş çalışır; yani bir işlemi hafızaya yüklemek birkaç saniye veya dakika sürebilir. Çünkü genelde bir işlem tamamlandığında yeni bir işlem hafızaya yüklenir.

### 2. **Short-term Scheduler (Kısa Dönemli Zamanlayıcı) ya da CPU Zamanlayıcı**

- **Görevi nedir?**Kısa dönemli zamanlayıcı, CPU'nun hangi işlemi çalıştıracağını belirler. Hazır kuyruktaki işlemler arasından bir seçim yapar ve CPU'yu ona tahsis eder.
- **Hızlı olmalıdır:**Bu zamanlayıcının milisaniyeler içinde karar vermesi gerekir. Çünkü bir işlem CPU'yu uzun süre meşgul ederse, diğer işlemler çalışamaz ve sistem performansı düşer. CPU'nun sürekli verimli kullanılması için bu zamanlayıcı çok hızlı çalışmalıdır.
- **Bazı sistemlerde tek zamanlayıcı:**Bazı sistemlerde sadece kısa dönemli zamanlayıcı bulunabilir. Bu durumda sistemde uzun dönemli bir zamanlayıcı olmadığı için, tüm işlemleri CPU'ya bu zamanlayıcı atar.

---

### **İşlem Türleri**

İşlemler, CPU'yu nasıl kullandıklarına göre iki ana kategoriye ayrılır:

- **I/O-bound process (G/Ç bağımlı işlem):**
    
    Bu tür işlemler daha çok giriş/çıkış (I/O) işlemleri yapar ve CPU'yu daha az kullanır. Örneğin, bir veri okuma işlemi çok fazla I/O beklemesi gerektirebilir ve işlem uzun süre boyunca CPU'da aktif olmayabilir.
    
    - **Kısa CPU patlamaları (CPU bursts):**I/O-bağımlı işlemler genellikle kısa süreli CPU kullanımına sahiptir. Yani, CPU'yu kısa bir süre kullanıp tekrar bir I/O işlemi beklemeye geçerler.
    - **Örnek:**Bir dosyadan veri okuyan bir program ya da bir kullanıcıdan giriş bekleyen bir program I/O-bağımlı olabilir.
- **CPU-bound process (CPU bağımlı işlem):**
    
    Bu tür işlemler ise CPU'yu yoğun bir şekilde kullanır, yani sürekli hesaplamalar yapar ve bellek değişkenleri üzerinde işlem gerçekleştirir. Bu işlemler nadiren I/O işlemi yapar.
    
    - **Uzun CPU patlamaları:**CPU-bağımlı işlemler genellikle CPU'yu uzun süre kullanır. Yani, kesintisiz bir şekilde işlem yapmaya devam ederler ve I/O işlemlerine pek fazla ihtiyaç duymazlar.
    - **Örnek:**Bir veri seti üzerinde karmaşık matematiksel işlemler yapan bir program CPU-bağımlı olabilir. Örneğin, yoğun hesaplamalar gerektiren bir bilimsel simülasyon programı.

---

### **CPU Patlamaları (CPU Bursts)**

- **CPU burst:** Bir işlemin sürekli olarak CPU'da çalışmak istediği bir zaman dilimidir. I/O işlemleri arasında CPU'nun tamamen meşgul olduğu bu dönemlerde işlem CPU'da aktif kalır.
- **I/O-bound işlemler:** Kısa CPU patlamalarına sahiptir. Yani, bu işlemler genellikle CPU'yu kısa bir süre kullanır ve sonra I/O işlemleri için beklemeye geçer.
- **CPU-bound işlemler:** Daha az sayıda, ama çok uzun CPU patlamalarına sahiptir. Bu işlemler CPU'da daha uzun süre kesintisiz çalışır.

---

### **RAM I/O Bağımlılığı**

- **RAM I/O Bağımlı Örneği:**Eğer bir program büyük miktarda giriş alıyorsa (örneğin, büyük bir veri kümesi) ve bu veriler üzerinde sadece basit işlemler yapıyorsa, bu işlem **bellek-bağımlı** (memory-bound) olabilir. Bellek-bağımlı işlemler, giriş verileri büyük olduğunda ve CPU tarafından yapılan işlemler az olduğunda ortaya çıkar.
    - **Bu bir I/O darboğazıdır:**Eğer veriler bellek üzerinden geçiyorsa, verilerin CPU'ya hızlı bir şekilde ulaşmasını engelleyen dar bir nokta olabilir. Bu tür darboğazlarda çoklu işlemciler kullanmak (paralel işlem) pek bir fayda sağlamaz. Çünkü veriler bellekten tek bir bağlantı üzerinden geçtiği için bellek bant genişliği sınırlayıcı faktör olur.
    - **Paralelleştirme fayda sağlamaz:**Eğer verilerin işlenmesi küçük ve basitse, işlemciler arasında bölünerek paralel çalıştırmak hızlanmayı önemli ölçüde artırmaz. Bunun nedeni, belleğin tek bir veri yolu üzerinden işlemcilere bağlanmasıdır.

---

### **CPU Bağımlı Örnek**

- **CPU-bağımlı işlem:**Eğer bir programın girdi verisi küçükse, ancak bu veriler üzerinde çok fazla işlem yapıyorsa, o zaman bu işlem CPU-bağımlıdır. Bu tür durumlarda çoklu işlemciler kullanmak fayda sağlar çünkü CPU'da yapılan yoğun hesaplamalar paralel çalıştırıldığında, işlem süresi işlemci sayısına bölünür ve hızlanma sağlanır.
    - **Örnek:**Aynı verilerle çok sayıda matematiksel işlem yapan bir programda, her işlemciye farklı başlangıç koşulları vererek bu işlemi paralel hale getirmek süreyi önemli ölçüde kısaltabilir. Bu durumda, her işlemci bir koşulu çalıştırır ve işlem süresi işlemci sayısına bölünür.

---

### **Zamanlayıcılar (Schedulers)**

Zamanlayıcılar, hazır kuyruktaki işlemler arasından CPU'yu kullanacak olanı seçer ve ona CPU'yu tahsis eder. CPU'nun hangi işlemi ne zaman çalıştıracağı zamanlayıcı tarafından belirlenir. İşletim sistemlerinde zamanlama kararları şu durumlarda alınır:

1. **İşlem çalışandan bekleme durumuna geçtiğinde**
    - Bu genellikle bir semafor ya da G/Ç (giriş/çıkış) işlemi gibi bekleme gerektiren olaylar yüzünden olur. Örneğin, bir işlem veri bekliyorsa, CPU'dan ayrılır ve bekleme durumuna geçer.
2. **İşlem çalışandan hazır duruma geçtiğinde**
    - İşlem, belirlenen zaman diliminde (time slice) işlemini tamamlayamazsa CPU'yu bırakır ve hazır duruma geçer. Bu durumda, CPU başka bir işleme tahsis edilir.
3. **İşlem beklemeden hazır duruma geçtiğinde**
    - Beklemekte olan bir işlem, beklediği olay (örneğin, fare tıklaması) gerçekleşince tekrar hazır duruma geçer. Bu işlem tekrar CPU'da çalışmak üzere sıraya alınır.
4. **İşlem sonlandığında**
    - Bir işlem, tüm görevlerini tamamladığında ve sonlandığında (örneğin, `exit(0)` fonksiyonu ile) CPU'yu serbest bırakır ve işlem tamamen sistemden çıkar.

---

### **Preemptive (Kesintili) ve Non-preemptive (Kesintisiz) Zamanlama**

- **Kesintisiz Zamanlama (Non-preemptive):**
    
    İşlemler gönüllü olarak CPU'yu bırakır. Yani işlem ya bekleme durumuna geçtiğinde ya da sonlandığında CPU'yu serbest bırakır. Örneğin, işlem çalışırken G/Ç beklemeye geçtiğinde veya sonlandığında CPU'dan çıkar.
    
- **Kesintili Zamanlama (Preemptive):**
    
    Bir işlem, CPU'yu zorla bırakmak zorunda kalabilir. CPU başka bir işlem için önceliklendirilirse, mevcut işlem CPU'dan çıkarılır. Bu genellikle etkileşimli sistemlerde, yani kullanıcının döngüde olduğu sistemlerde görülür. Örneğin, kullanıcının bir tuşa basması gibi etkileşimlerde bu işlem devreye girebilir.
    

---

### **Zamanlama Kriterleri (Scheduling Criteria)**

Zamanlama algoritmaları, sistem performansını optimize etmeye yönelik birkaç farklı kriteri dikkate alır:

1. **CPU Kullanımı (CPU Utilization):**
    
    CPU'nun mümkün olduğunca meşgul tutulması istenir. İşletim sistemi, CPU'nun boş kalmaması için işlemleri sürekli olarak sıraya koyar ve CPU'yu etkin bir şekilde kullanmaya çalışır.
    
2. **Verim (Throughput):**
    
    Birim zamanda tamamlanan işlem sayısını ifade eder. Yani, belirli bir zaman diliminde kaç işlem tamamlandığı bu kriterle ölçülür. Verimin yüksek olması, sistemin daha fazla işlemi tamamladığını gösterir.
    
3. **Tamamlanma Süresi (Turnaround Time):**
    
    Bir işlemin baştan sona kadar geçen süresini ifade eder. Yani, bir işlemin başlamasından tamamen bitirilmesine kadar olan zaman, o işlemin yaşam süresi olarak tanımlanır.
    
4. **Bekleme Süresi (Waiting Time):**
    
    Bir işlemin hazır kuyruğunda beklediği süredir. İşlem hazır durumda CPU'yu kullanmak için sırada beklerken geçen süre, işlem süresinin bir alt kümesidir.
    
5. **Yanıt Süresi (Response Time):**
    
    Bir işlemin isteği yapıldıktan sonra, ilk yanıtın üretilmesine kadar geçen süredir. Özellikle etkileşimli sistemlerde yanıt süresi çok önemlidir. Örneğin, kullanıcı iki tam sayı girdiğinde, sonucun mümkün olan en kısa sürede dönmesi beklenir. Bu yüzden, yanıt süresi kısa olmalıdır.
    

---

### **Zamanlama Kriterleri ile Amaçlar**

- **CPU Kullanımını Maksimize Etmek:**
    
    CPU'nun boş kalmaması ve sürekli iş yapması amaçlanır. Bu, CPU'nun verimli kullanılmasını sağlar.
    
- **Verimi Maksimize Etmek:**
    
    Birim zamanda tamamlanan işlem sayısını artırmak, sistemin çok daha fazla iş yapmasını sağlar.
    
- **Tamamlanma Süresini Minimize Etmek:**
    
    İşlemler ne kadar kısa sürede tamamlanırsa, sistem o kadar hızlı olur. Tamamlanma süresinin minimize edilmesi, işlemlerin toplam süresinin azalmasına yardımcı olur.
    
- **Bekleme Süresini Minimize Etmek:**
    
    İşlemler ne kadar az beklerse, o kadar hızlı çalışır. Bekleme süresinin azaltılması, işlemlerin daha çabuk işleme alınmasına olanak sağlar.
    
- **Yanıt Süresini Minimize Etmek:**
    
    Etkileşimli sistemlerde, kullanıcının girdisine hızlı bir yanıt vermek önemlidir. Yanıt süresinin minimize edilmesi, sistemin kullanıcılara daha hızlı geri dönüş yapmasını sağlar.
    

---

**Zamanlama Metrikleri ve Performans**

Zamanlama algoritmalarının performansı çeşitli metriklerle ölçülür. En yaygın kullanılan metriklerden biri **Tamamlanma Süresi (Turnaround Time)**'dir. Bu metrik, bir işin tamamlandığı zaman ile sistemde işin geldiği zaman arasındaki farkı gösterir. Yani:

$$
T_{\text{turnaround}} = T_{\text{completion}} - T_{\text{arrival}}
$$

Bu metrik, bir işlemin ne kadar sürede tamamlandığını gösterir. **Adalet (Fairness)** ise başka bir önemli metrik olarak karşımıza çıkar. Performans ile adalet çoğu zaman birbirine zıt amaçlar olabilir. Performans, sistemin etkinliğini artırmak için işlerin hızlı tamamlanmasına odaklanırken, adalet her işin adil bir şekilde CPU kaynağını kullanabilmesini amaçlar.

---

### **İlk Giren İlk Çıkar (First In, First Out - FIFO)**

**İlk Gelen İlk Hizmet Alır (First Come, First Served - FCFS)**, uygulanması oldukça basit bir zamanlama algoritmasıdır. İşlemler, sisteme geldikleri sıraya göre CPU'yu kullanırlar. Bu algoritmada, işlemler sırayla tamamlanır ve bir iş bitmeden diğerine geçilmez. Bir örnek üzerinden inceleyelim:

- İşlemler sırasıyla A, B ve C; her biri 10 saniye çalışacak:

$$
T_{\text{turnaround average}} = \frac{(10 + 20 + 30)}{3} = 20 \, \text{sn}
$$

**Ortalama Tamamlanma Süresi (Average Turnaround Time)**, işlemlerin çalışma sürelerine göre hesaplanır. Bu algoritma, basit ve anlaşılır olmasına rağmen, her zaman en iyi performansı göstermez.

---

### **Konvoy Etkisi (Convoy Effect)**

FIFO algoritması her zaman iyi bir seçenek olmayabilir. **Konvoy etkisi** adı verilen bir sorun oluşabilir. Bu sorun, sistemde uzun süren bir işin, ardından gelen kısa işlerin CPU'ya ulaşmasını geciktirmesidir. Örneğin:

- A işlemi 100 saniye, B ve C işlemleri 10 saniye sürecek şekilde çalışıyor:

$$
T_{\text{turnaround average}} = \frac{(100 + 110 + 120)}{3} = 110 \, \text{sn}
$$

Burada uzun süren A işlemi, ardından gelen kısa işlemlerin başlamasını ciddi anlamda geciktirir. Bu durumda FIFO algoritmasının yetersiz kaldığı ve kısa süreli işlemleri gereksiz yere beklettiği görülür.

---

### **İlk Gelen İlk Hizmet (FCFS) Zamanlaması**

FCFS, **kesintisiz (non-preemptive)** bir CPU zamanlayıcısıdır. Bu, bir iş başladığında CPU'yu tamamen kullanır ve iş bitene kadar başka bir işlem devreye girmez. Bu nedenle FCFS algoritması, daha adaletsiz bir yöntem olarak kabul edilebilir, çünkü CPU kaynağını etkili bir şekilde kullanmaz. Ayrıca uzun süren işlemler, kısa süren işlemleri engelleyebilir ve sistem performansını olumsuz etkileyebilir.

---

**Özetle**, FCFS basit ve anlaşılır bir algoritma olmasına rağmen, uzun işlemler kısa işlemleri beklettiği için performans açısından her zaman en iyi seçenek değildir. Konvoy etkisi gibi sorunlar nedeniyle özellikle kullanıcı etkileşimli sistemlerde yetersiz kalabilir.

---

**Shortest Job First (SJF) Zamanlama Algoritması**

**Shortest Job First (SJF)**, yani "En Kısa İş Önce" algoritması, adı üstünde, en kısa süre gerektiren işi ilk sıraya koyar ve sırasıyla diğer kısa işleri çalıştırır. Bu algoritma, **kesintisiz (non-preemptive)** bir zamanlayıcıdır, yani bir iş başladığında o iş tamamlanana kadar CPU'da kalır ve başka bir işlem devreye girmez. Bu durum, uzun işlemlerin beklemesine neden olabilir, ancak **bekleme süresini en aza indirmek** için optimal bir çözümdür.

---

### **Örnek: İşlerin Aynı Anda Gelmesi Durumu**

Eğer tüm işler aynı anda gelirse (örneğin A, B, ve C), sistem, en kısa işlerden başlayarak sıralar:

- A: 100 saniye sürecek,
- B: 10 saniye sürecek,
- C: 10 saniye sürecek.

Bu durumda, algoritma ilk olarak en kısa işlemleri (B ve C) tamamlar, ardından en uzun işlem olan A'yı çalıştırır. Böylece:

$$
T_{\text{turnaround average}} = \frac{(10 + 20 + 120)}{3} = 50 \, \text{sn}
$$

Görüldüğü üzere, algoritma ortalama tamamlanma süresini ciddi anlamda düşürür. Ancak, SJF’nin bir dezavantajı, **uzun süreli işlemlerin bekletilmesi** ve bu işlemlerin CPU kaynağına geç ulaşmasıdır.

---

### **İşlerin Farklı Zamanlarda Gelmesi Durumu**

Eğer işlerin gelişi zamanla farklılık gösterirse, algoritma daha farklı çalışır. Örneğin:

- A işlemi t=0'da gelir ve 100 saniye çalışır,
- B ve C işlemleri t=10'da gelir ve her biri 10 saniye sürer.

Bu durumda SJF algoritması yine en kısa işlerden başlayarak işlem sıralamasını yapar. A işinin tamamlanmasını beklemeden, B ve C işlemleri CPU'yu alır. Bu durumda ortalama tamamlanma süresi:

$$
T_{\text{turnaround average}} = \frac{(100 + 110 - 10 + (120 - 10))}{3} = 103.33 \, \text{sn}
$$

---

### **SJF Algoritmasının Artıları ve Eksileri**

**Avantajlar:**

- **Minimum Bekleme Süresi**: SJF, en kısa işleri önce çalıştırdığı için bekleme süresini minimuma indirir. Bu anlamda **optimal** bir çözümdür.
- Özellikle **bilimsel ve büyük veri analizleri** gibi belirli uygulamalarda, en kısa işlerin önce yapılması sistem verimliliğini artırır.

**Dezavantajlar:**

- **Starvasyon (Aç Kalma)**: Çok uzun süren işlemler, sürekli kısa işlemler gelirse, CPU'ya hiç erişemeyebilir. Bu duruma **starvasyon** denir.
- **CPU Patlama Süresinin Tahmini**: SJF algoritmasının en büyük sorunu, bir işlemin CPU'da ne kadar süre kalacağını önceden tahmin etmektir. Bu tahminler genellikle işlem geçmişine göre yapılır, ancak her zaman doğru olmayabilir.

---

### **Geçmiş Davranışla CPU Patlama Süresi Tahmini**

SJF algoritmasında, bir işlemin **CPU patlama süresi** önceden tahmin edilmeye çalışılır. Bunun için önceki CPU kullanım sürelerine bakılır ve bu süreler üzerinden **üstel ortalama (exponential averaging)** gibi yöntemlerle tahmin yapılır. Bu tahminler için genellikle şu formül kullanılır:

$$
T_{\text{next burst}} = \alpha \times T_{\text{previous burst}} + (1 - \alpha) \times T_{\text{previous estimate}}
$$

Burada **α** genellikle 0.5 olarak alınır. Bu yöntemle, bir program birden fazla kez çalıştırılırsa, bu işlem süreleri üzerinden tahminler yapılabilir.

---

**Sonuç olarak**, SJF, minimum bekleme süresi sağlama açısından ideal bir zamanlama algoritmasıdır, ancak starvasyon ve CPU patlama süresinin doğru tahmin edilememesi gibi dezavantajları da vardır. Sistemde işler ne kadar doğru tahmin edilebilirse, o kadar verimli çalışır.

---

### **Shortest Time-to-Completion First (STCF) – Preemptive Shortest Job First (PSJF)**

**STCF**, aynı zamanda **Preemptive Shortest Job First (PSJF)** olarak da bilinir. SJF algoritmasına kıyasla, bu algoritma kesintili çalışır. Bir iş yeni geldiğinde, o işin kalan süreleri ve mevcut işlerin kalan süreleri kıyaslanır ve **en kısa kalan süreye sahip iş** CPU'da çalıştırılır.

---

### **STCF Örneği:**

- A işlemi t=0'da gelir ve 100 saniye sürecektir.
- B ve C işlemleri t=10'da gelir ve her biri 10 saniye sürecektir.

STCF algoritması, B ve C'nin gelmesiyle birlikte A'yı CPU'dan çıkarır ve B ve C işlemlerini önce çalıştırır. Bu süreç sonucunda **ortalama tamamlanma süresi** şu şekilde hesaplanır:

$$
T_{\text{turnaround average}} = \frac{(120 - 0) + (20 - 10) + (30 - 10)}{3} = 50 \, \text{sn}
$$

---

### **Cevap Süresi (Response Time) ve STCF**

**Response time**, bir işin sisteme geldiği andan CPU'da ilk kez çalıştığı ana kadar geçen süredir. STCF ve benzeri algoritmalar, cevap süresi açısından çok iyi değildir çünkü kısa işler CPU'ya hemen erişemez. Cevap süresi şu şekilde hesaplanır:

$$
T_{\text{response}} = T_{\text{firstrun}} - T_{\text{arrival}}
$$

---

### **Zaman Paylaşımlı Sistemler ve Yeni Metrik: Response Time**

Zaman paylaşımlı makinelerin (time-shared systems) ortaya çıkmasıyla birlikte, kullanıcılar sistemden **etkileşimli performans** talep etmeye başladılar ve böylece yeni bir metrik doğdu: **Cevap Süresi (Response Time)**. Cevap süresine duyarlı bir zamanlayıcı nasıl oluşturabiliriz? İşte bu noktada **Round Robin (RR)** gibi algoritmalar devreye girer.

---

### **Round Robin (RR) Zamanlama**

**Round Robin (RR)**, **zaman dilimi (time slice)** ile çalışan bir zamanlama algoritmasıdır. Her bir iş, belirli bir süre boyunca CPU'da çalıştırılır ve ardından sıradaki iş devralır. Bu işlem tüm işler tamamlanana kadar tekrarlanır. **Zaman dilimi**, bazen **schedule quantum** olarak adlandırılır. Zaman dilimi, CPU'nun kesme periyodunun bir katı olmalıdır.

RR algoritması adil olsa da, **tamamlanma süresi** gibi performans metrikleri açısından genellikle kötü sonuç verir.

---

### **Round Robin (RR) ve SJF Karşılaştırması**

- **SJF**, özellikle cevap süresi açısından kötü olabilir, çünkü işlemler birbiri ardına çalıştırılır ve kısa işler bile bekleyebilir.
- **RR**, cevap süresi açısından oldukça iyidir çünkü her iş sırayla CPU'ya erişir, bu da kullanıcıya hızlı bir geri dönüş sağlar.

---

**Sonuç olarak**, **RR** etkileşimli sistemler için daha uygundur, çünkü **cevap süresi** iyileşir. Ancak, **SJF** veya **STCF** algoritmaları uzun süreli işlemler için daha uygun olabilir çünkü **ortalama tamamlanma süresi** minimize edilir.

---

### **Zaman Diliminin (Time Slice) Uzunluğunun Önemi**

**Zaman diliminin uzunluğu**, **Round Robin (RR)** gibi zaman paylaşımlı sistemler için kritik bir parametredir. Zaman dilimi kısaldıkça:

- **Daha iyi cevap süresi** elde edilir.
- Ancak, **context switching (bağlam değiştirme)** maliyeti artar ve bu durum performansı olumsuz etkileyebilir.

Zaman dilimi uzadıkça:

- **Bağlam değiştirme maliyeti** azaltılabilir (amortize edilebilir).
- Ancak, bu sefer **cevap süresi** kötüleşir.

Bu nedenle, sistem tasarımcısı için **zaman diliminin uzunluğunu** belirlemek, **performans** ve **cevap süresi** arasında bir denge kurmayı gerektirir.

---

### **Zamanlayıcı Türleri ve Performans Kriterleri**

İki tür zamanlayıcı geliştirdik:

1. **SJF ve STCF** (en kısa iş ilk): **Tamamlanma süresini (turnaround time)** optimize eder, ancak **cevap süresi** açısından kötüdür.
2. **RR** (Round Robin): **Cevap süresini** optimize eder, ancak **tamamlanma süresi** açısından kötüdür.

Ancak hala gevşetilmesi gereken iki varsayım var:

- Varsayım 4: İşler I/O işlemi yapmaz.
- Varsayım 5: İşlerin çalışma süreleri bilinir.

---

### **I/O Entegrasyonu (Incorporating I/O)**

Varsayım 3'ü gevşetelim: **Tüm programlar I/O işlemi yapar.**

Örnek:

- A ve B her biri 50ms CPU zamanı gerektirir.
- A, 10ms çalıştıktan sonra bir **I/O isteği** başlatır (I/O işlemi 10ms sürer).
- B sadece CPU'yu kullanır ve I/O işlemi yapmaz.

Bu durumda, **zamanlayıcı (scheduler)** ilk olarak A'yı çalıştırır, ardından B'yi CPU'ya alır. **A'nın I/O işlemi tamamlandığında** ise bir **kesme (interrupt)** oluşturulur ve A tekrar **ready state (hazır duruma)** geçer.

---

### **Shortest Remaining Job First (SRJF)**

**SRJF**, adil olmayan kesintili bir CPU zamanlayıcıdır ve **SJF'nin preemptive versiyonudur**. SRJF'nin temel mantığı:

- **En kısa süreli işi** çalıştırmak.
- **CPU burst tahminleri** hala gereklidir.
- Bir iş (A) çalışırken, daha kısa süreye sahip yeni bir iş (B) geldiğinde, A işlemine ara verilir ve B çalıştırılır.

---

### **Öncelikli Zamanlama (Priority Scheduling)**

**Priority Scheduling**, adil olmayan bir CPU zamanlayıcıdır ve her işleme bir **öncelik numarası** (integer) atanır.

- **En yüksek önceliğe sahip** iş CPU'yu alır (en küçük sayıya sahip olan iş en yüksek önceliğe sahiptir).
- **Preemptive**: Daha yüksek öncelikli bir iş geldiğinde, CPU'da çalışan iş kesilir.
- **Non-preemptive**: İşler kesilmez, CPU'da çalışmayı tamamlarlar.

**SJF**, bir çeşit **öncelikli zamanlama** algoritmasıdır. Bu algoritmada, öncelik, bir sonraki **CPU burst süresi** tahminine dayalıdır.

---

### **Öncelikli Zamanlamanın Sorunu: Starvation (Aç Kalma)**

**Düşük öncelikli** işler uzun süre CPU'yu alamaz ve bu duruma **starvation** denir. Bunu çözmek için **aging** kullanılır. Bu yöntemle, işlem süresi uzadıkça, bir işlemin **önceliği** zamanla artırılır.

---

# ÖZET

### 1. **İş Yükü Varsayımları (Workload Assumptions)**

Burada zamanlama algoritmalarıyla ilgili birkaç varsayım yapılıyor:

- **Tüm işler eşit sürede çalışır**: Yani her bir iş (process) aynı miktarda CPU süresi kullanıyor. Bu durum, basit zamanlama modelleri için kullanılabilir.
- **Tüm işler aynı anda sisteme gelir**: Yani, işlerin başlama zamanları farklı değildir; hepsi aynı anda başlamaktadır.
- **İşler sadece CPU kullanır, I/O kullanmaz**: Giriş/Çıkış (I/O) işlemleri yoktur, bu da işlemlerin CPU üzerinde kesintisiz çalışabileceğini varsayar.
- **Her işin çalışma süresi önceden bilinir**: İşlerin ne kadar süreceği bilindiğinde, zamanlama algoritmaları daha kolay planlama yapabilir.

Bu varsayımlar genellikle akademik modellerde veya temel algoritma incelemelerinde kullanılır. Ancak gerçek dünyada işler farklı zamanlarda gelir, I/O işlemleri çok önemlidir ve işlemlerin ne kadar süreceği her zaman kesin değildir.

### 2. **İşlem Zamanlayıcı (Process Scheduler)**

Zamanlayıcı, işlemlerin CPU üzerinde nasıl yürütüleceğini belirler. **Context switch** denilen işlem, bir işlemin durdurulup başka bir işleme geçilmesini sağlar. Bu, her bir işleme sanki kendi işlemcisi varmış gibi bir illüzyon verir. Zamanlayıcı şu kriterlere dikkat eder:

- **CPU'nun olabildiğince meşgul kalmasını sağlamak**: CPU, boşta kalmadan sürekli işlem yürütmeli.
- **İşlemlere adil davranmak**: Her işin belirli bir sürede CPU'yu kullanma fırsatı olmalıdır.

**Thread**'ler (iş parçacıkları) de zamanlanabilir varlıklardır. Yani, zamanlama algoritmaları hem süreçler (processes) hem de thread'ler için geçerlidir.

### 3. **Context Switch (Bağlam Değişimi)**

Context switch, bir işlemin durdurulup başka bir işleme geçilmesi demektir. Bu işlem:

- **Yeni işlemlerin CPU'da çalışmasını sağlar**.
- Ancak **yüksek maliyetlidir**, çünkü bağlam değiştirilirken CPU, işlemler için doğrudan bir iş yapmaz, sadece durumu koruyup başka bir işlemin durumu ile değiştirilir.
- **Kullanıcı kodu** ve **çekirdek kodu** arasında geçiş yapılır. İşlem bağlamı çekirdek modunda tutulurken, kullanıcı kodu CPU’da işlem yapar.

### 4. **İşlem Zamanlayıcısı ve Kuyruklar**

İşlem zamanlayıcıları, birçok işin aynı anda yürütüldüğü bir sistemde, her işin CPU'da çalışmasını düzenler. Zamanlayıcı, **işlem kuyrukları** tutar:

- **İş kuyruğu**: Sistemdeki tüm işlemler.
- **Hazır kuyruk**: CPU’da çalışmaya hazır olan işlemler.
- **Cihaz kuyrukları**: I/O cihazı bekleyen işlemler.

İşlemler bu kuyruklar arasında geçiş yapar; örneğin, bir işlem CPU'da çalışırken bir I/O işlemi başlatabilir ve I/O kuyruğuna alınır.

### 5. **Zamanlayıcı Türleri**

- **Uzun dönem zamanlayıcı** (Long-term scheduler): İşleri hazır kuyruğuna getirir. Bu zamanlayıcı, hangi işlemlerin belleğe yükleneceğine karar verir ve genellikle yavaş çalışır (saniyeler ya da dakikalar sürebilir).
- **Kısa dönem zamanlayıcı** (Short-term scheduler): Hangi işlemin CPU’yu kullanacağına karar verir. Bu zamanlayıcı hızlı çalışmalıdır, çünkü işlemciyi sürekli meşgul tutmak zorundadır.

### 6. **Zamanlama Kriterleri**

Bir sistemde işlemci zamanlaması yapılırken şu kriterler göz önünde bulundurulur:

- **CPU kullanımı**: CPU'nun olabildiğince meşgul kalması.
- **İş bitirme oranı (Throughput)**: Belirli bir zaman diliminde kaç işlemin tamamlandığı.
- **Bekleme süresi**: Bir işlemin hazır kuyrukta ne kadar beklediği.
- **Tepki süresi**: Bir işlemin başlatılmasından ilk tepkinin alınmasına kadar geçen süre.

### 7. **Zamanlama Algoritmaları**

Zamanlama algoritmaları, işlemlerin CPU'da nasıl sıraya konacağını belirler:

- **İlk Gelen İlk Hizmet Alır (FIFO/FCFS)**: İşler geldikleri sıraya göre çalıştırılır. Çok basit bir algoritmadır, ancak "konvoy etkisi" denen bir sorun yaratabilir. Örneğin, uzun süreli bir iş, arkasındaki kısa süreli işlerin beklemesine neden olabilir.
- **En Kısa İş Önce (SJF)**: En kısa CPU süresine sahip iş önce çalıştırılır. Optimal bir bekleme süresi sağlar, ancak işlemlerin CPU sürelerini tahmin etmek zor olabilir.
- **En Kısa Tamamlama Süresi İlk (STCF)**: SJF algoritmasının öncelikli versiyonudur. Yeni gelen kısa bir iş, CPU'daki mevcut işi kesip CPU'yu alabilir.
- **Round Robin (RR)**: İşler belirli bir süre diliminde sırayla çalıştırılır. Bu algoritma adildir, ancak işlerin tamamlanma süresi açısından verimsiz olabilir.
- **Öncelikli Zamanlama (Priority Scheduling)**: İşlere bir öncelik değeri atanır ve CPU, en yüksek önceliğe sahip işe verilir. Bu algoritmada, düşük öncelikli işler "açlık" yaşayabilir, yani hiç çalıştırılmayabilir. Bu sorunu çözmek için **yaşlandırma (aging)** yöntemi kullanılabilir; zamanla düşük öncelikli işlerin önceliği artırılır.

### 8. **Zaman Dilimi ve Tepki Süresi**

- **Zaman diliminin uzunluğu** önemlidir: Kısa dilim daha iyi tepki süresi sağlar, ancak çok sık context switch yapılması nedeniyle verim düşer. Uzun dilimlerde ise tepki süresi kötüleşir, ancak context switch maliyeti daha az olur.
- **Tepki süresi ve tamamlanma süresi arasında bir denge kurmak** zordur. SJF gibi algoritmalar tamamlanma süresini optimize ederken, RR gibi algoritmalar tepki süresini iyileştirir.

### 9. **I/O'nun Dâhil Edilmesi**

Gerçek dünyada işlemler genellikle I/O işlemleri gerçekleştirir. I/O işlemleri sırasında CPU'nun boşta kalmaması için, zamanlayıcı diğer işlemleri çalıştırmalıdır. Bir işlem I/O isteğinde bulunduğunda, **bloke edilir** ve I/O tamamlandığında yeniden hazır hale gelir.

### 10. **Öncelikli Zamanlama**

**Öncelikli zamanlama**, bir işleme öncelik numarası atanarak yapılır. Küçük numaralar daha yüksek öncelik anlamına gelir. Ancak düşük öncelikli işler hiç çalıştırılmayabilir (açlık), bu yüzden yaşlandırma teknikleri kullanılır.

Bu temel konular, **işlemci zamanlaması** ve **işlem performansını** optimize etmek için kullanılan tekniklerdir. Algoritmaların her biri belirli bir kriteri optimize etmeye çalışırken, genellikle diğer kriterlerde ödünler vermek zorunda kalırlar.

---