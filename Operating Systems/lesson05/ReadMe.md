# 5. Hafta

**CPU'nun Verimli Bir Şekilde Sanallaştırılması ve Kontrol Altında Tutulması**

İşletim sistemlerinin CPU'yu verimli bir şekilde sanallaştırması ve kontrol altında tutması, modern çoklu görev (multitasking) ortamlarının temel bir gerekliliğidir. Bu süreç, aynı fiziksel CPU'yu birden çok süreç arasında zaman paylaşımı yoluyla paylaşmayı sağlar. Bunu yaparken iki temel sorun vardır:

1. **Performans:** Sanallaştırma işlemi, sistemde aşırı yük (overhead) oluşturmadan nasıl gerçekleştirilebilir?
2. **Kontrol:** CPU'nun verimli çalışmasını sağlarken, işletim sisteminin CPU üzerindeki kontrolünü nasıl koruyabiliriz?

### CPU Sanallaştırmanın Performans ve Kontrol Sorunu

### 1. **Performans Sorunu**

CPU sanallaştırma işlemi sırasında, performansın düşmemesi çok önemlidir. Her bir süreç, işletim sistemi tarafından yönetilen bir "sanal CPU" kullanıyor gibi görünmelidir. Ancak, bu sanal CPU aslında fiziksel CPU'ya zaman dilimleri ile atanır. CPU'nun her bir süreç için görev değiştirme (context switch) yapması ve her değişim sırasında, süreçlerin durumlarının kaydedilmesi, geri yüklenmesi işlemleri belli bir zaman maliyeti (overhead) getirir.

**Çözüm Önerileri:**

- **Verimli Görev Değişimi:** Zaman paylaşımlı sistemlerde, görev değişimlerinin (context switches) minimum zaman kaybıyla yapılması için optimize edilmiş algoritmalar kullanılır. İşletim sistemi her süreç için CPU kullanımı, bellek durumu, program sayacı ve diğer verileri saklayıp gerektiğinde bu durumu geri yükler.
- **Donanım Destekli Sanallaştırma:** Modern işlemciler, sanallaştırma için donanım düzeyinde destek sunar (örneğin, Intel VT-x ve AMD-V). Bu sayede, sanal makinelerin çalıştırılması ve yönetilmesi daha az maliyetle yapılır.

### 2. **Kontrol Sorunu**

İşletim sistemi, CPU üzerinde tam kontrole sahip olmalıdır. Aksi takdirde, bir süreç CPU'yu ele geçirip tüm kaynakları tüketebilir ya da erişim yetkisi olmayan verilere erişebilir. Bu nedenle, işletim sistemi CPU üzerinde güçlü bir kontrol mekanizması kurmalıdır.

**Çözüm Önerileri:**

- **Korumalı Mod (Protected Mode):** İşletim sistemi, CPU'yu korumalı modda çalıştırır. Bu modda, kullanıcı süreçleri yalnızca belirli kaynaklara erişebilir ve tüm sistem kaynakları (CPU, bellek, I/O cihazları) üzerinde doğrudan erişim hakkına sahip olmazlar. Eğer bir süreç yasaklanmış bir kaynağa erişmeye çalışırsa, bir kesme (interrupt) tetiklenir ve işletim sistemi devreye girer.
- **Zamanlayıcı Kesmesi (Timer Interrupt):** İşletim sistemi, bir zamanlayıcı kullanarak CPU'daki her sürecin belirli bir süre çalışmasını sağlar. Bu süre dolduğunda, bir kesme tetiklenir ve işletim sistemi başka bir sürece geçiş yapar. Böylece hiçbir süreç CPU'yu sonsuza kadar işgal edemez.
- **Kullanıcı Modu ve Çekirdek Modu Ayrımı:** Modern işlemcilerde, kullanıcı süreçleri "kullanıcı modu"nda çalışırken işletim sistemi "çekirdek modu"nda çalışır. Bu ayrım, kullanıcı süreçlerinin sistem kaynaklarına doğrudan erişimini engeller ve işletim sistemine kaynakları yönetme yetkisi verir.

### Sanallaştırmanın Temel Kontrol Mekanizmaları

1. **Kesme (Interrupt) ve İstisnalar (Exceptions):**
    - İşletim sistemi, CPU'daki kontrolünü kesmeler ve istisnalar yoluyla sağlar. Örneğin, zamanlayıcı kesmesiyle (timer interrupt) belirli zaman aralıklarında süreçler arasında geçiş yapılır. Bir süreç, yasadışı bir işlem gerçekleştirmeye çalıştığında (örneğin, yetkisiz bir bellek bölgesine erişim), bir istisna (exception) meydana gelir ve işletim sistemi devreye girer.
2. **Görev Değişimi (Context Switch):**
    - İşletim sistemi, bir sürecin yürütmesini durdurup başka bir süreci çalıştırarak CPU'yu farklı süreçler arasında paylaştırır. Görev değişimi sırasında her sürecin mevcut durumu (CPU kayıtları, bellek işaretçileri, program sayacı vb.) saklanır ve yeni çalıştırılan sürecin durumu geri yüklenir.
3. **Zamanlama Algoritmaları:**
    - İşletim sistemi, CPU zamanını verimli bir şekilde dağıtmak için çeşitli zamanlama algoritmaları kullanır. En yaygın kullanılan algoritmalar arasında "Round Robin", "Shortest Job Next" ve "Priority Scheduling" yer alır. Bu algoritmalar, CPU'nun farklı süreçler arasında nasıl paylaştırılacağını belirler.

### Sonuç

İşletim sistemi, CPU'yu sanallaştırarak farklı süreçlerin aynı anda çalışmasını sağlar. Ancak bu süreçte, performansı düşürmeden ve CPU üzerindeki kontrolü kaybetmeden çalışmak büyük bir zorluktur. İşletim sistemi, donanım ve yazılım destekli çeşitli mekanizmalar kullanarak bu zorlukların üstesinden gelir ve CPU'nun güvenli ve verimli bir şekilde paylaşılmasını sağlar.

---

**Doğrudan Yürütme (Direct Execution)**

Doğrudan yürütme, bir programın doğrudan CPU üzerinde çalıştırılmasıdır. Bu durumda işletim sistemi (OS), sürecin başlatılması, çalıştırılması ve sonlandırılmasına rehberlik eder. İşlem, OS'nin süreci başlatması ve daha sonra CPU'yu bu sürecin kontrolüne vermesiyle gerçekleşir. Ancak OS'nin kontrolü tamamen kaybetmemesi için bazı kısıtlamalar ve güvenlik mekanizmaları gerekir.

### İşletim Sistemi Adımları:

1. **Process list'e giriş oluşturma:** İşletim sistemi, çalıştırılacak program için bir işlem listesi kaydı oluşturur. Bu liste, programın durumunu izlemek için kullanılır.
2. **Program için hafıza ayırma:** İşletim sistemi, programın çalıştırılabilmesi için bellek tahsis eder. Bu bellek alanı, programın kodu ve veri yapıları için kullanılacaktır.
3. **Programı belleğe yükleme:** Programın makine kodları ve gerekli verileri belleğe yüklenir. Programın çalışabilmesi için kod ve veri segmentleri uygun yerlere yerleştirilir.
4. **Stack’i argc ve argv ile ayarlama:** Programın komut satırı argümanları (`argc`, `argv`) stack (yığın) üzerine yerleştirilir, böylece program bunlara erişebilir.
5. **Kayıtları sıfırlama:** CPU'nun kayıtları temizlenir, böylece yeni program çalıştırılmaya hazır hale gelir.
6. **main() fonksiyonunu çağırma:** Programın yürütülmesi, `main()` fonksiyonunun çağrılmasıyla başlar. İşletim sistemi, kontrolü programın `main()` fonksiyonuna devreder.

### Program Çalışması:

1. **main() fonksiyonunu çalıştırma:** Programın ana fonksiyonu yürütülür. Bu süreç boyunca CPU programın komutlarını doğrudan yürütür.
2. **main()'den geri dönme:** Program yürütmesini tamamladığında, `main()` fonksiyonundan döner ve program sonlandırılmaya hazırlanır.

### İşletim Sistemi Adımları (Program Sonlandırılması):

1. **Programın belleğini serbest bırakma:** Program sona erdiğinde, işletim sistemi program için tahsis edilmiş olan belleği serbest bırakır.
2. **Process list’ten çıkarma:** Programın sonlandırılmasıyla birlikte, işlem listesinde bulunan kayıt silinir ve program tamamen kapatılır.

### Kontrolün Korunması:

Bu doğrudan yürütme modeli teorik olarak basit ve etkili görünse de, işletim sistemi üzerinde tam kontrol olmadan çalıştırılan programlar ciddi sorunlara yol açabilir. OS'nin kontrolü kaybetmesi, bir programın süresiz olarak çalışmasına veya sisteme zarar verebilecek işlemler yapmasına neden olabilir.

İşte bu yüzden işletim sistemleri, programları çalıştırırken bazı kısıtlamalar ve güvenlik önlemleri kullanır. Eğer işletim sistemi bu kontrolleri sağlamazsa, OS bir kütüphaneden başka bir şey olmaz ve kontrolü tamamen programlara devretmiş olur. İşletim sistemi kontrolü kaybederse:

- Bir program sonsuza kadar çalışarak CPU'yu ele geçirebilir.
- Program, diğer süreçlerin bellek alanlarına izinsiz erişim sağlayabilir.
- Sistemde kaynak tükenmesine ve çökmesine sebep olabilir.

### Kontrol Mekanizmaları:

1. **Zamanlayıcı Kesmesi (Timer Interrupt):** İşletim sistemi, zamanlayıcı kullanarak her programın belirli bir süre CPU'da çalışmasını sağlar. Süre dolduğunda bir kesme meydana gelir ve işletim sistemi kontrolü geri alır. Bu, hiçbir programın CPU üzerinde sınırsız süre kalmasını önler.
2. **Kullanıcı Modu ve Çekirdek Modu Ayrımı:** Programlar kullanıcı modunda çalışırken, işletim sistemi çekirdek modunda çalışır. Bu ayrım, programların sistem kaynaklarına doğrudan erişmesini engeller ve OS'yi sistem üzerinde yetkili kılar.
3. **Görev Değişimi (Context Switch):** İşletim sistemi, bir süreçten diğerine geçerken, programların durumu kaydedilir ve geri yüklenir. Bu şekilde, birden fazla programın aynı CPU'yu paylaşmasına olanak tanınır.

### Sonuç:

Doğrudan yürütme, programların CPU üzerinde çalıştırılması için basit ve hızlı bir yöntemdir, ancak OS'nin kontrolünü kaybetmeden programları yönetebilmesi önemlidir. Bu nedenle, işletim sistemleri çeşitli kontrol mekanizmaları ve güvenlik önlemleri kullanarak CPU'nun sanallaştırılmasını sağlar.

---

**Doğrudan Yürütme Protokolü (Kısıtlamalar Olmadan)**

Doğrudan yürütme, işletim sisteminin (OS) bir programı doğrudan CPU'da çalıştırdığı bir yöntemdir ve hız avantajı sağlar. Ancak, bu yöntemin iki temel sorunu vardır: kullanıcı süreçlerinin kısıtlanmış işlemler yapmasını engellemek ve işletim sisteminin CPU üzerindeki kontrolünü geri almasını sağlamak. Bu sorunlar, sistem çökmelerini veya güvenlik ihlallerini önlemek için dikkatle ele alınmalıdır.

### **Doğrudan Yürütmenin Adımları:**

1. **Süreç Yaratma:** İşletim sistemi, işlem listesinde süreç için bir giriş oluşturur.
2. **Bellek Tahsisi:** Süreç için gerekli bellek tahsis edilir.
3. **Program Yükleme:** Program kodu diskten belleğe yüklenir.
4. **Giriş Noktası Bulma:** İşletim sistemi, programın başlangıç noktası olan `main()` fonksiyonunu bulur.
5. **Çalıştırma Başlangıcı:** Program çalışmaya başlar.

Doğrudan yürütme, programın CPU'da herhangi bir ek adım olmadan çalışması nedeniyle verimlidir. Ancak bu yöntemde **iki büyük sorun** ortaya çıkar:

---

### **Sorun 1: Kısıtlanmış İşlemler**

Programların donanım, G/Ç cihazları veya bellek yönetimi gibi sistem kaynaklarına doğrudan erişimi olmamalıdır. Kısıtlama olmadan herhangi bir süreç:

- Diskte G/Ç isteği yapabilir.
- İzin verilenden daha fazla CPU veya bellek kaynağına erişebilir.
- Kritik sistem kaynaklarını değiştirebilir, bu da sistemin güvenliğini riske atar.

### **Çözüm 1: Her Şeye İzin Ver (Kötü Çözüm)**

Süreçlere tüm sistem kaynaklarına sınırsız erişim vermek basit bir çözüm gibi görünebilir, ancak bu ciddi güvenlik sorunlarına yol açar:

- Programlar veri bozabilir veya veri kaybına neden olabilir.
- CPU veya belleği tekeline alabilir, bu da performansın düşmesine veya sistemin çökmesine neden olur.

**Örnek:**

- Kötü yazılmış bir program, sahibi olmadığı bir dosyayı değiştirmeye çalışarak dosya sisteminde bozulmalara neden olabilir.

### **Çözüm 2: Korumalı Kontrol Aktarımı (Kullanıcı Modu ve Çekirdek Modu)**

İşletim sistemleri, sistem kaynaklarını korumak için **kullanıcı modu** ve **çekirdek modu** arasında bir ayrım yapar.

- **Kullanıcı Modu:**
    - Normal programlar (uygulamalar) kullanıcı modunda çalışır.
    - Kullanıcı modunda çalışan programlar donanıma (örn. CPU, G/Ç cihazları) doğrudan erişemez.
    - Kısıtlanmış işlemler (G/Ç istekleri gibi) engellenir.
    - Eğer bir kullanıcı programı kısıtlanmış bir işlem yapmaya çalışırsa, CPU bir hata (exception) yükseltir ve işletim sistemi muhtemelen programı sonlandırır.
- **Çekirdek Modu:**
    - İşletim sistemi çekirdek modunda çalışır ve donanım kaynaklarına tam erişimi vardır.
    - Çekirdek modunda çalışan kod, G/Ç istekleri gibi kısıtlı işlemleri yapabilir ve her türlü sınırlı talimatı yürütebilir.
    - Sadece güvenilir kodlar (işletim sistemi kodları) çekirdek modunda çalışabilir.

**Neden gereklidir?**
Kullanıcı modu ve çekirdek modu arasındaki ayrım, kullanıcı programlarının sistem operasyonlarını bozmasını veya sistemin kararlılığını tehlikeye atmasını engeller.

---

### **Sorun 2: CPU Kontrolünü Geri Alma**

Doğrudan yürütmenin bir diğer sorunu, işletim sisteminin CPU'yu geri almak istediğinde nasıl kontrolü sağlayacağıdır. Örneğin, bir kullanıcı programı sonsuz bir döngüye girerse (`while (1)`), CPU'yu sürekli meşgul edebilir.

### **Ne yanlış olabilir?**

- Bir kullanıcı programı CPU'yu sonsuza kadar kullanarak diğer programların çalışmasını engelleyebilir.

### **Çözüm: Zamanlayıcı Kesintileri ve Bağlam Değiştirme (Context Switching)**

İşletim sistemi, kontrolü sağlamak için şu mekanizmaları kullanır:

1. **Zamanlayıcı Kesintileri:** İşletim sistemi, belirli bir süre sonra CPU'yu kesmek için bir donanım zamanlayıcı ayarlar. Zamanlayıcı çalıştığında kontrol işletim sistemine geçer ve başka bir süreci zamanlamasına izin verir.
2. **Bağlam Değiştirme:** Zamanlayıcı kesintisi sırasında işletim sistemi, mevcut sürecin durumunu (bağlam) kaydeder ve başka bir sürece geçer. Bu, CPU'nun birden fazla program arasında adil şekilde kullanılmasını sağlar.

---

### **Korumalı Kontrol Aktarımı**

1. **Mod Değiştirme:**
    - İşletim sistemi, bir programın kısıtlı bir işlem yapması gerektiğini tespit ettiğinde (örneğin, bir G/Ç isteği), CPU'yu **kullanıcı modundan** **çekirdek moduna** geçirir.
    - Kısıtlanmış işlem çekirdek modunda işletim sistemi tarafından gerçekleştirilir.
    - İşlem tamamlandıktan sonra işletim sistemi tekrar kullanıcı moduna geçer ve normal program yürütmeye devam eder.
2. **Sistem Çağrıları:**
    - Programlar, işletim sisteminden hizmet talep etmek için sistem çağrılarını (`read()`, `write()`, `malloc()`) kullanır.
    - Bir sistem çağrısı, kontrolü kullanıcı programından işletim sistemine aktarır, bu sayede işletim sistemi kısıtlı işlemleri güvenli bir şekilde program adına yapabilir.

---

### **Özet:**

1. **Doğrudan yürütme** hızlıdır, ancak uygun şekilde yönetilmezse sistemi tehlikeye atabilir.
2. **Kullanıcı Modu vs. Çekirdek Modu** kullanıcı programlarının sistem kaynaklarına erişimini kısıtlamak ve işletim sisteminin kontrolü sağlamasını garanti altına almak için gereklidir.
3. **Zamanlayıcı kesintileri** ve **bağlam değiştirme** bir sürecin CPU'yu uzun süre kullanması durumunda kontrolün işletim sistemine geri dönmesini sağlar.
4. **Korumalı kontrol aktarımı**, kullanıcı programlarının işletim sistemi aracılığıyla sistem kaynaklarına güvenli bir şekilde erişmesini sağlar, bu da performans ve güvenlik arasında denge kurar.

İşletim sistemi, CPU'nun sanallaştırılmasını verimli bir şekilde yönetirken, kontrolü elde tutmayı bu mekanizmalarla sağlar.

---

**Sistem Çağrısı (System Call)**

Bir kullanıcı süreci, ayrıcalıklı bir işlem yapmak istediğinde (örneğin, diske okuma veya yazma gibi), doğrudan donanıma erişemez çünkü bu tür işlemler işletim sistemi tarafından korunur. Bu nedenle, modern donanımlar **sistem çağrısı** adı verilen bir mekanizma sağlar. Sistem çağrısı, kullanıcının ayrıcalıklı işlemleri güvenli bir şekilde yapmasını sağlar.

### **Sistem Çağrısının Amacı:**

Sistem çağrısı, işletim sisteminin belirli işlevsellikleri dikkatlice kullanıcı programlarına sunmasına olanak tanır. Bu işlevler şunları içerebilir:

- **Dosya sistemine erişim:** Bir dosya okuma, yazma veya silme gibi işlemler.
- **Süreç oluşturma ve yok etme:** Yeni süreçler yaratma (örn. `fork()`) ve süreçleri sonlandırma.
- **Diğer süreçlerle iletişim:** Süreçler arasında veri alışverişi (örn. pipe, message queue).
- **Daha fazla bellek tahsisi:** Programın daha fazla belleğe ihtiyaç duyduğunda bunu işletim sisteminden talep etmesi (örn. `malloc()`).

---

### **Sistem Çağrıları Neden Prosedür Çağrıları Gibi Görünür?**

Bir sistem çağrısı, tipik bir prosedür çağrısı gibi görünür; bu, bir programın normal bir fonksiyonu çağırdığı gibi çağrılır. Örneğin, C dilinde bir sistem çağrısı şu şekilde yapılabilir:

```c
read(fd, buffer, size);
```

Bu, tıpkı başka bir fonksiyonu çağırmak gibidir. Ancak, sistem çağrısının arka planında daha karmaşık işlemler gerçekleşir.

### **Nasıl Çalışır?**

1. **Kullanıcı programı bir sistem çağrısı yapar:** Program, bir sistem fonksiyonunu (örn. `read()`, `write()`, `open()`) çağırdığında, bu fonksiyon işletim sistemine erişmek için kullanılır.
2. **Mod Değişikliği:** Sistem çağrısı yapıldığında, CPU **kullanıcı modundan** **çekirdek moduna** geçer. Bu, işletim sisteminin ayrıcalıklı işlemleri güvenli bir şekilde gerçekleştirmesini sağlar.
3. **İşletim sistemi kontrolü alır:** Çekirdek modunda olan işletim sistemi, kullanıcı programının talebini işler, diskte okuma yapar, bellek tahsis eder veya bir dosyayı açar.
4. **Sonuç geri döner:** İşlem tamamlandıktan sonra, işletim sistemi kontrolü tekrar kullanıcı programına geri verir ve mod tekrar **kullanıcı moduna** döner.

Bu nedenle, sistem çağrıları yüzeyde bir prosedür çağrısı gibi görünse de, aslında kullanıcı ve çekirdek arasında bir kontrol transferi içerir.

---

### **Sistem Çağrısı ile Prosedür Çağrısı Arasındaki Fark:**

1. **Prosedür Çağrısı:** Normal bir prosedür çağrısı (fonksiyon çağrısı) sadece kullanıcının belleği içinde çalışır ve doğrudan donanıma erişmez.
2. **Sistem Çağrısı:** Sistem çağrısı, işletim sistemi çekirdeğine bir talep iletir. İşletim sistemi, bu talebi işleyip sonucunu kullanıcıya geri döner.

---

### **Sistem Çağrısının Avantajları:**

- **Güvenlik:** İşletim sistemi, kısıtlı işlemleri sadece kendisi yapar ve programların güvenliğini sağlar.
- **Kontrol:** İşletim sistemi, kaynakları (disk, bellek, CPU) kontrol eder ve hangi programın ne kadar kaynak kullanacağını belirler.
- **Hız:** Sistem çağrıları kullanıcıya hızlı ve verimli erişim sağlar.

**Sistem çağrıları**, işletim sisteminin kullanıcı programlarıyla iletişim kurmasına olanak tanır ve ayrıcalıklı işlemleri güvenli ve kontrollü bir şekilde gerçekleştirmeye yardımcı olur.

---

### Sistem Çağrısının Ana Konsepti

Sistem çağrıları, kullanıcı programlarının çekirdek (kernel) düzeyinde belirli işlemleri güvenli bir şekilde gerçekleştirmesine olanak tanır. Bu işlemler, donanım kaynaklarına erişimi gerektiren ve kullanıcı programlarına doğrudan verilmemesi gereken yetkileri içerir. Sistemde bu tür ayrıcalıklı işlemlerin yapılması, **trap** adı verilen bir mekanizma ile sağlanır.

### **Trap Talimatı (Trap Instruction)**

Trap, işlemcinin bir programı çekirdek moduna geçirmesine ve sistem çağrısının gerçekleştirilmesine olanak tanır. **Trap talimatı** aşağıdaki adımlarla işler:

1. **Ayrıcalık Düzeyini Artırma (Raise Privilege Level to Kernel Mode):**
    - Trap talimatı ile kullanıcı modundaki program çekirdek moduna geçirilir ve bu geçiş işlemcinin donanımı tarafından gerçekleştirilir.
2. **Kayıtların Saklanması (Save Registers at Kernel Stack):**
    - **EIP (Instruction Pointer)**, **CS (Code Segment)**, **EFLAGS (Flags)**, **ESP (Stack Pointer)**, ve **SS (Stack Segment)** gibi işlemci kayıtları çekirdek yığınına (kernel stack) kaydedilir. Böylece, daha sonra aynı noktadan devam edilebilir.
3. **Çekirdek Koduna Yönlendirme (Locate Destination in Kernel):**
    - Sistem, çekirdek modunda çalışacak doğru kodu bulur ve o kod parçasına atlar. Bu, genellikle **trap handler** olarak bilinen kesme işleyicisi tarafından yapılır.
4. **Kesme Numarası (Interrupt Number):**
    - Sistem çağrısının gerçekleşmesi için belirli bir kesme numarası kullanılır. Örneğin:
        - **xv6** için kesme numarası: `0x64`
        - **Pintos** için kesme numarası: `0x30`
    
    Örneğin, `int 0x64` talimatı ile `xv6`'da bir sistem çağrısı başlatılır.
    

### **Return-from-Trap Instruction**

- Sistem çağrısı tamamlandıktan sonra, **return-from-trap** talimatı ile işlemci tekrar kullanıcı moduna döner. Bu işlem sırasında aşağıdaki adımlar takip edilir:
    - **Ayrıcalık Seviyesini Düşürme (Reduce Privilege Level)**: Kullanıcı moduna geri dönülür.
    - **Kayıtları Geri Yükleme (Restore Registers)**: Kayıtlar kernel stack'ten geri yüklenir ve kullanıcı programı kaldığı yerden devam eder.

### **Trap Kodunun Çalıştırılması**

Bir **trap** tetiklendiğinde, işlemcinin hangi kodu çalıştıracağını belirlemek için **trap handler** (kesme işleyicisi) devreye girer.

### **Trap Kaynakları (Sources of Trap)**

Trap'lar birçok kaynaktan gelebilir:

- **Disk IO Tamamlanması (Completion of Disk IO)**
- **Klavye Kesmesi (Keyboard Interrupt)**
- **Sistem Çağrısı (System Call)**

### **Trap İşleyicisi (Trap Handler)**

Trap işleyicisi, belirli bir kesme numarasıyla (trap number) ilişkilendirilmiş olan kod parçasıdır. Bu işleyici, trap gerçekleştiğinde ne yapılacağını belirler.

### **Trap Tablosu (Trap Table)**

Trap tablosu, trap işleyicilerinin adreslerini içerir. Donanım, işletim sistemine bu tablonun nerede olduğunu bildirir. Bu bilgi, işletim sistemi önyüklenirken donanım tarafından işletim sistemine iletilir. Bu talimat (trap tablosunun konumunu bildirme) ayrıcalıklı bir talimattır ve kullanıcı modunda çalıştırılamaz.

### **Sistem Çağrısının İcadı**

**ATLAS** (1962-1971) adlı süper bilgisayar, dünyanın ilk sanal belleği (paging) ve sistem çağrılarını (extracode) destekleyen sistemlerinden biriydi. Bu dönemde geliştirilen sistem çağrıları, günümüzdeki modern işletim sistemlerinin temelini oluşturur.

---

### Sınırlı Yönlendirilmiş Çalıştırma (Limited Direction Execution)

Sınırlı yönlendirilmiş çalıştırma, bir işletim sistemi (OS) ile donanım arasında belirli bir kontrol mekanizması sağlayarak kullanıcı programlarının çalıştırılmasını yönetir. Bu süreçte, OS'nin donanımla etkileşimi ve işlem yönetimi önemli bir rol oynar.

### **OS'nin Başlangıcı ve Donanım**

1. **Boot Sırasında OS (Kernel Modu):**
    - Donanım, **trap tablosunu** başlatır. Bu tablo, sistem çağrılarını (system calls) işlemek için gerekli olan işleyicilerin adreslerini içerir.
    - **Syscall handler** adresini kaydeder.

### **OS'nin Çalışması ve Program**

1. **Çalışma Sırasında OS (Kernel Modu):**
    - Kullanıcı programı (user mode) çalışmaya başlar.
    - Ana fonksiyon (`main()`) çağrılır.
2. **Sistem Çağrısının Yapılması:**
    - Kullanıcı programı, bir sistem çağrısı yapmak istediğinde, **trap** işlemi ile OS'ye geçer.
    - Çekirdek yığından (kernel stack) kayıtlar geri yüklenir.
    - Kullanıcı moduna geçiş yapılır ve `main` fonksiyonuna geri dönülür.

### **Süreç Girişi ve Bellek Yönetimi**

1. **Yeni Süreç Girişi:**
    - OS, yeni bir süreç için süreç listesine bir giriş oluşturur.
    - Program için bellek tahsis edilir.
    - Program kodu belleğe yüklenir.
    - Kullanıcı yığını, `argv` ile ayarlanır.
    - Çekirdek yığına, kayıtlar ve program sayacı (PC) doldurulur.
2. **Ana Fonksiyondan Çıkış:**
    - `main` fonksiyonundan dönüş yapıldığında, bir çıkış işlemi (`exit()`) ile **trap** meydana gelir.
    - Kayıtlar çekirdek yığından geri yüklenir ve kullanıcı moduna geçiş yapılır.
3. **Belleğin Serbest Bırakılması:**
    - İşlem belleği serbest bırakılır.
    - Süreç listesinde işlem silinir.

### **Süreçler Arası Geçiş Sorunu (Problem 2)**

İşletim sistemi, CPU'yu kontrol altına alarak süreçler arasında nasıl geçiş yapar?

### **Kooperatif Yaklaşım: Sistem Çağrılarını Bekleme**

- Süreçler, `yield` gibi sistem çağrılarını yaparak CPU'yu periyodik olarak bırakır.
- OS, başka bir görevi çalıştırma kararı alır.
- Uygulama, yasadışı bir işlem yaptığında da kontrolü OS'ye devreder (örneğin, sıfıra bölme, erişim izni olmayan bir belleğe erişim denemesi).
- Örneğin: Eski Macintosh OS ve Xerox Alto sistemlerinde, bir süreç sonsuz döngüde takılabilir ve bu durumda makinayı yeniden başlatmak gerekebilir.

### **Kooperatif Olmayan Yaklaşım: OS Kontrol Alır**

- **Zamanlayıcı kesmesi (Timer Interrupt)**:
    - OS, boot sırasında bir zamanlayıcı başlatır.
    - Zamanlayıcı, her birkaç milisaniyede bir kesme oluşturur.
    - Kesme oluştuğunda, mevcut çalışan süreç askıya alınır ve süreç durumu kaydedilir.
    - OS içindeki önceden yapılandırılmış bir kesme işleyicisi çalışır.
    - Zamanlayıcı kesmesi, OS'nin CPU üzerinde tekrar çalışabilme yeteneği sağlar.

Bu iki yaklaşım, işletim sistemlerinin kullanıcı programlarını etkili bir şekilde yönetmesine ve kontrol altında tutmasına yardımcı olur.

---

### Zamanlayıcı Kesmesi (Timer Interrupt)

Zamanlayıcı kesmesi, işletim sisteminin CPU'yu periyodik olarak kesmesine olanak tanıyan bir mekanizmadır. Bu, sistem kaynaklarının daha verimli kullanılmasını sağlar ve süreçlerin zamanlamasını yönetir.

### **Zamanlayıcı Kesmesinin Programlanması**

- **Tek CPU için**: PIT (Programlanabilir Aralık Zamanlayıcı) kullanılır.
- **Birden Fazla CPU için**: APIC (Gelişmiş Programlanabilir Kesme Kontrolörü) kullanılır.
    - **LAPIC**: Her işlemci için yerel APIC.
    - **IO APIC**: Sistem veriyolu üzerindeki giriş/çıkış APIC.

### **Zamanlayıcı Çalışma Döngüsü**

```c
while (1) {
    i = INTERVAL; // Zamanlayıcı aralığını ayarla
    while (--i > 0); // Zamanlayıcıyı beklet
    raise interrupt; // Kesme sinyalini gönder
}
```

### **Bağlamı Kaydetme ve Geri Yükleme (Saving and Restoring Context)**

Zamanlayıcı kesmesi meydana geldiğinde, işletim sistemi bir **şema değişimi** (context switch) gerçekleştirir. Bu, hangi sürecin çalışmaya devam edeceğine karar verilmesini sağlar.

### **Bağlam Değişimi (Context Switch)**

- Düşük seviyeli bir montaj kodu parçası.
- **Kayıtların Kaydedilmesi**:
    - Geçerli sürecin genel amaçlı kayıt değerleri, çekirdek yığına (kernel stack) kaydedilir.
    - Program sayacı (PC) ve çekirdek yığın işaretçisi (kernel stack pointer) gibi değerler.
- **Yeni Sürecin Kayıtlarının Geri Yüklenmesi**:
    - Bir sonraki çalışacak süreç için kayıtlar, çekirdek yığından geri yüklenir.
    - Geçiş yapılacak sürecin çekirdek yığına (kernel stack) geçilir.

### **Sınırlı Doğrudan Çalıştırma Protokolü (Limited Direct Execution Protocol)**

### **Zamanlayıcı Kesmesi İşleyişi**

1. **OS Başlatıldığında (Kernel Modu)**:
    - Donanım, **trap tablosunu** başlatır.
    - Sistem çağrı işleyicisi ve zamanlayıcı işleyicisinin adresini kaydeder.
2. **OS Çalışırken (Kernel Modu)**:
    - Zamanlayıcı başlatılır.
    - Zamanlayıcı, belirli bir süre sonra CPU'yu keser (örneğin, X ms sonra).
3. **Kesme meydana geldiğinde**:
    - Kayıtlar (A) çekirdek yığına kaydedilir.
    - Çekirdek moduna geçilir ve kesme işleyicisine yönlendirilir.

### **Kesme İşleyicisinin Çalışması**

- **Kesmeyi İşleme**:
    - `switch()` rutinini çağırır.
    - Kayıtlar (A), işlem yapısı (proc-struct) içine kaydedilir.
    - Kayıtlar (B), işlem yapısından geri yüklenir.
    - Çekirdek yığın (k-stack) B'ye geçilir.
- **Kesmeden Dönüş**:
    - Kayıtlar (B), B'nin çekirdek yığınından geri yüklenir.
    - Kullanıcı moduna geçilir.
    - İşlem B'nin program sayacına (PC) yönlendirilir.

### **Eşzamanlılık Konusu**

- Kesme veya tuzak işleme sırasında başka bir kesme meydana gelirse ne olur?
- **İşletim sistemi**, bu durumları yönetir:
    - Kesme işlenirken kesmeleri devre dışı bırakır.
    - İç veri yapılarının eşzamanlı erişimini korumak için çeşitli karmaşık kilitleme şemaları kullanır.

Bu mekanizmalar, işletim sisteminin kaynakları etkili bir şekilde yönetmesini ve birden fazla sürecin verimli bir şekilde çalışmasını sağlar.

---