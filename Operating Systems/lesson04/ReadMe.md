# 4. Hafta

### 1. **fork()**

`fork()` sistem çağrısı, mevcut bir süreci kopyalayarak yeni bir süreç oluşturmak için kullanılır. Bu yeni süreç "child process" (çocuk süreç) olarak adlandırılır ve çağrıyı yapan süreç ise "parent process" (ebeveyn süreç) olarak bilinir. Çocuk süreç, ebeveyn sürecin tam bir kopyasıdır ancak farklı bir Süreç Kimliği (PID) ile çalışır.

Bu çağrı, özellikle çoklu görev yönetiminde kullanılır. Örneğin, bir uygulamanın paralel olarak çalıştırılması gerektiğinde `fork()` çağrısı kullanılarak bu uygulamanın yeni bir örneği oluşturulabilir. Önemli bir nokta da, `fork()` çağrısı yapıldığında, aynı işlem iki farklı süreç tarafından farklı sonuçlar dönebilir. Ebeveyn süreç için `fork()`'un dönüş değeri çocuk sürecin PID'si iken, çocuk süreç için dönüş değeri sıfır olur.

---

### 2. **exec()**

`exec()` ailesi (örn. `execve()`, `execl()` gibi) bir süreci tamamen yeni bir programla değiştirir. Yani, çağrıyı yapan süreç sonlandırılmadan, mevcut bellekte çalışan programın yerine yeni bir program yüklenir ve çalıştırılır.

Örneğin, `fork()` ile bir çocuk süreç yaratıldıktan sonra, bu çocuk sürecin farklı bir program çalıştırması gerektiğinde `exec()` çağrısı yapılır. Bu çağrı, sürecin belleğindeki tüm kodu ve verileri yeni bir programla değiştirir, böylece aynı PID ile tamamen yeni bir işlem başlatılmış olur.

---

### 3. **wait()**

`wait()` sistem çağrısı, bir ebeveyn sürecin, çocuk süreçlerinden birinin tamamlanmasını beklemesini sağlar. Ebeveyn süreç, `wait()` çağrısı yaptıktan sonra, belirtilen bir çocuk süreç sonlanana kadar duraklar. Çocuk süreç sonlandığında, ebeveyn sürece geri dönüş yapılır ve sonlanma durumu hakkında bilgi sağlanır.

Bu fonksiyon, sistemde süreç yönetimini etkin bir şekilde sağlamak ve gereksiz kaynak tüketimini önlemek amacıyla kullanılır.

---

### 4. **fork() ve exec() Ayrımı**

`fork()` ve `exec()` genellikle birlikte kullanılır ancak farklı işlevlere sahiptir. `fork()` mevcut bir süreci kopyalayarak yeni bir süreç oluşturur, `exec()` ise bu yeni sürecin içinde tamamen yeni bir program başlatır. Tipik bir kullanımda, `fork()` ile yeni bir süreç oluşturulur ve ardından `exec()` ile bu süreçte farklı bir program çalıştırılır. Bu ayrım, çoklu görev ve süreç kontrolü açısından oldukça önemlidir.

---

### 5. **G/Ç Yönlendirme (IO Redirection)**

Girdi ve çıktının yönlendirilmesi, komut satırında bir programın standart giriş, çıkış ve hata akışlarını değiştirmek için kullanılan bir tekniktir. Örneğin, bir komutun çıktısını ekrana yazdırmak yerine bir dosyaya kaydetmek için çıktı yönlendirme yapılabilir.

Örnek:

- `command > output.txt` komutu, `command` adlı programın çıktısını ekrana yazmak yerine "output.txt" dosyasına yönlendirir.
- Benzer şekilde, giriş yönlendirmesi `command < input.txt` şeklinde yapılabilir.

Bu yöntem, komut satırında daha karmaşık işlemleri ve otomasyonları mümkün kılar.

---

### 6. **pipe (Boru)**

`pipe`, iki süreç arasında veri alışverişi yapmanın bir yoludur. Bir süreçten diğerine veri akışını sağlar. `pipe` genellikle iki komutun birbirine bağlanarak birinin çıktısının diğerinin girdisi olarak kullanılmasında işe yarar.

Örnek:

- `command1 | command2` komutu, `command1` adlı komutun çıktısını `command2` adlı komutun girdisi olarak kullanır. Bu sayede işlemler arasında veri akışı sağlanır.

Boru, süreçler arası iletişim (IPC) sağlama yollarından biridir ve özellikle çoklu süreç uygulamalarında yaygın olarak kullanılır.

---

### 7. **Süreç (Process)**

Bir süreç, çalışmakta olan bir programın bir örneğidir. Bir sistemde her an birden fazla aktif süreç bulunur. Ancak aynı anda yalnızca bir süreç işlemciyi kullanabilir. Her süreç, sanki tüm işlemci ve bellek kendisine aitmiş gibi çalışır. İşletim sistemi süreçler arasında geçiş yaparak çoklu görev yürütülmesini sağlar.

---

### 8. **Süreç Yaratma (Spawning Processes)**

Süreç yaratma, `fork()` sistem çağrısı ile gerçekleştirilir. Bu çağrı, bir ebeveyn sürecin yeni bir çocuk süreç oluşturmasını sağlar. Bu çağrıda, bir defa çağrı yapılmasına rağmen iki geri dönüş değeri alınır: bir tanesi ebeveyn süreç için, diğeri ise çocuk süreç için.

---

### 9. **Süreç Tamamlanması (Process Completion)**

Bir süreç, `exit()` çağrısı ile sonlandırılır. Bu sistem çağrısı, sürecin sonlandırılması ve sistem kaynaklarının serbest bırakılması için kullanılır. `exit()` çağrısı yapıldığında, geri dönüş değeri alınmaz çünkü süreç tamamen sona erer.

---

### 10. **Süreç Toplama ve Bekleme (Reaping and Waiting for Processes)**

Ebeveyn süreç, çocuk süreçlerin tamamlanmasını beklemek ve sistem kaynaklarını serbest bırakmak için `wait()` ya da `waitpid()` fonksiyonlarını kullanır. Bu fonksiyonlar, çocuk sürecin sonlanıp sonlanmadığını kontrol eder ve süreç sonlandığında ebeveyn sürece geri dönüş yapılır.

---

### 11. **Program Yükleme ve Çalıştırma (Loading and Running Programs)**

Bir programın yüklendikten sonra çalıştırılması `exec()` sistem çağrısı ile yapılır. Bu çağrı, mevcut sürecin belleğine yeni bir program yükleyerek çalıştırır. Bu çağrıda genellikle geri dönüş yapılmaz çünkü süreç tamamen yeni bir programa dönüştürülür.

---

### Yeni Süreç Oluşturma (Creating Processes)

İşletim sistemlerinde yeni bir süreç oluşturma işlemi, genellikle `fork()` sistem çağrısı ile yapılır. Bu çağrı, bir ebeveyn sürecin yeni bir çocuk süreç yaratmasını sağlar. Aşağıda bu sürecin nasıl çalıştığını açıklıyorum:

---

### 1. **Ebeveyn Süreç (Parent Process) Yeni Bir Çocuk Süreç Oluşturur**

Ebeveyn süreç, `fork()` fonksiyonu çağrıldığında bir çocuk süreç (child process) oluşturur. Bu sistem çağrısı, tek bir kez çağrılmasına rağmen iki farklı geri dönüş değeri verir:

- **Çocuk süreç için:** `fork()` sıfır (0) değeri döner.
- **Ebeveyn süreç için:** `fork()` çocuk sürecin Süreç Kimliği'ni (PID) döner.

Bu, süreç yaratma işlemindeki en kafa karıştırıcı noktalardan biridir. Çünkü `fork()` çağrısı bir kez yapılır, ancak iki farklı süreç için iki farklı sonuçla geri döner.

---

### 2. **Çocuk Süreç, Ebeveyn Sürecin Bir Kopyasıdır**

Oluşturulan çocuk süreç, ebeveyn sürecin neredeyse aynısıdır. Ancak önemli bazı farklılıklar ve bağımsızlıklar vardır:

- **Ayrı Bellek Alanı:** Çocuk süreç, ebeveyn sürecin sanal adres alanının bir kopyasını alır, ancak bu kopya ayrıdır. Yani, ebeveyn ve çocuk süreçler birbirinden bağımsız bellek alanlarına sahiptir.
- **Dosya Tanıtıcıları:** Çocuk süreç, ebeveyn sürecin açık dosya tanıtıcılarının kopyalarını alır. Ancak, bu dosya tanıtıcılar da bağımsız olarak kullanılabilir.
- **Farklı PID:** Her süreç, işletim sistemi tarafından atanan benzersiz bir Süreç Kimliği (PID) ile tanımlanır. Bu nedenle, çocuk sürecin PID'si ebeveyn sürecinkinden farklıdır.

---

### 3. **Bağımsızlık**

Yeni oluşturulan çocuk süreç, oluşturulduktan sonra bağımsız hale gelir. Çocuk sürecin belleği, kayıtları ve program sayacı (PC) ebeveyn sürecinkilerle aynı başlar, ancak süreçler bağımsız olarak çalışır.

Bu bağımsızlık, çoklu süreçlerin aynı anda yürütülebilmesine olanak sağlar. Örneğin, bir ebeveyn süreç arka planda bir görev çalıştırmak istiyorsa, `fork()` ile yeni bir çocuk süreç oluşturabilir ve bu süreç bağımsız olarak işini yapabilir.

---

### 4. **Çocuk ve Ebeveyn Süreç Arasındaki Farklılıklar**

- **Bellek:** Her iki süreç de ayrı bellek alanlarına sahiptir, ancak başlangıçta içerik aynıdır.
- **Kayıtlar ve Program Sayacı (PC):** Çocuk sürecin kayıtları ve program sayacı da başlangıçta ebeveynin kopyasıdır. Ancak bu değerler süreç ilerledikçe farklılık gösterir.
- **PID:** Çocuk süreç ve ebeveyn süreç, farklı Süreç Kimliklerine sahiptir.

---

### 5. **`fork()` Nasıl Çalışır?**

`fork()` çağrısı, yeni bir çocuk süreç oluşturur ve ebeveyn sürece çocuk sürecin PID'sini döner. Çocuk süreç ise sıfır (0) döner. Bu özellik, genellikle süreçlerin birbirinden bağımsız işlemler yapabilmesini sağlamak için kullanılır.

Bu mekanizma, çoklu görev yönetiminde temel bir rol oynar ve işletim sistemi süreç yönetiminin bel kemiğini oluşturur.

---

### fork() ve Süreç Grafikleriyle Modelleme (Modeling fork with Process Graphs)

**Süreç Grafikleri (Process Graphs):**

Süreç grafikleri, bir eşzamanlı programda ifadelerin kısmi sıralamasını yakalamak için kullanılan yararlı bir araçtır. Bu grafikler, süreçler arasındaki bağımsız ve bağımlı ilişkileri görselleştirmenizi sağlar.

- **Düğüm (Vertex):** Her düğüm, bir ifadenin yürütülmesini temsil eder.
- **Kenarlar (Edges):** `a -> b` şeklindeki bir kenar, `a` ifadesinin `b` ifadesinden önce yürütüldüğünü gösterir.
- **Etiketler:** Kenarlar, değişkenlerin güncel değerleriyle etiketlenebilir. Örneğin, `printf` ifadeleri, çıktılarıyla etiketlenebilir.
- **Başlangıç Düğümü:** Her grafik, giriş kenarı olmayan bir düğümle başlar (yani, başlangıç ifadesi).
- **Topolojik Sıralama:** Grafiğin herhangi bir topolojik sıralaması, tüm kenarların soldan sağa doğru işaret ettiği bir tam sıralamaya karşılık gelir. Yani, tüm ifadeler sıralı bir şekilde gerçekleşir.

Bu tür grafikler, `fork()` çağrısı gibi eşzamanlı işlemler sırasında hangi süreçlerin hangi sırayla yürütüldüğünü anlamak için kullanışlıdır. Örneğin, ebeveyn süreç ve çocuk süreç arasındaki işlem sırasını modellemek için bir süreç grafiği oluşturulabilir. `fork()` çağrısının nasıl iki farklı süreç yarattığını ve bunların birbirinden bağımsız veya bağımlı işlemler yaptığını bu grafiklerle görselleştirebiliriz.

---

### wait(): Çocuk Süreçlerle Eşzamanlama (Synchronizing with Children)

**`wait()` Fonksiyonu:**

`wait()` fonksiyonu, ebeveyn sürecin çocuk süreçlerden birinin sonlanmasını beklemesini sağlar. Ebeveyn süreç, bu fonksiyonu çağırarak çocuk süreç tamamlanana kadar duraklar.

- **Bekleme ve Geri Dönme:** Ebeveyn süreç, `wait()` fonksiyonunu çağırdıktan sonra çocuk sürecin çalışıp bitmesini bekler. Çocuk süreç sonlanmadan önce `wait()` fonksiyonu geri dönmez.
- **Bağımsızlık:** Ebeveyn ve çocuk süreçler birbirinden bağımsızdır; birinin diğerini beklemesi zorunlu değildir. Ancak bazı durumlarda, uygulama ebeveyn sürecin çocuk süreç tamamlanmadan sonlanmasını istemeyebilir. Bu durumda, ebeveyn süreç `wait()` ile çocuk sürecin bitmesini bekler.

---

### wait(): Çocuk Sürecin Sonlanmasını Toplama (Reaping the Child Process)

**Ebeveyn Sürecin Beklemesi:**

Ebeveyn süreç, bir çocuk sürecin sonlanmasını beklemek için `wait()` fonksiyonunu çağırabilir. Bu fonksiyon, şu şekilde çalışır:

- **Süreç Askıya Alınır:** Ebeveyn süreç, çocuk süreçlerden biri sonlanana kadar askıya alınır.
- **Dönüş Değeri:** `wait()` fonksiyonunun dönüş değeri, sonlanan çocuk sürecin PID’sidir.
- **Çıkış Durumu:** Eğer `child_status` boş değilse (yani NULL değilse), bu parametrenin işaret ettiği tamsayı, çocuk sürecin neden sonlandığını ve çıkış durumunu gösterir.

Çıkış durumunu kontrol etmek için `wait.h` başlık dosyasında tanımlanmış bazı makrolar vardır:

- **WIFEXITED:** Çocuk sürecin normal şekilde sonlanıp sonlanmadığını kontrol eder.
- **WEXITSTATUS:** Çocuk sürecin çıkış durumunu alır.
- **WIFSIGNALED:** Çocuk sürecin bir sinyal nedeniyle sonlanıp sonlanmadığını kontrol eder.
- **WTERMSIG:** Çocuğu sonlandıran sinyalin kodunu alır.
- **WIFSTOPPED:** Çocuk sürecin durdurulup durdurulmadığını kontrol eder.
- **WSTOPSIG:** Çocuğu durduran sinyalin kodunu alır.
- **WIFCONTINUED:** Durmuş bir sürecin devam edip etmediğini kontrol eder.

---

### execve(): Program Yükleme ve Çalıştırma (Loading and Running Programs)

`execve()` sistem çağrısı, mevcut sürecin belleğini tamamen yeni bir programla değiştirmek için kullanılır. Yani, çağrıyı yapan süreç sona ermeden, mevcut süreç belleğine yeni bir ikili dosya yüklenir ve çalıştırılır. Bu yeni program, mevcut süreçle aynı PID'yi ve bazı sistem kaynaklarını paylaşır, ancak bellek içeriği tamamen değiştirilir.

---

### **execve() Nasıl Çalışır?**

**Fonksiyon Prototipi:**

```c
int execve(char *filename, char *argv[], char *envp[]);
```

- **`filename`:** Çalıştırılacak dosyanın adı (örneğin, bir programın ikili dosyası veya bir betik dosyası).
- **`argv[]`:** Argüman listesi. Bu liste, çalıştırılacak programa parametreler sağlar. Geleneksel olarak, `argv[0]`, çalıştırılan programın dosya adıyla aynı olur.
- **`envp[]`:** Ortam değişkenleri listesi. Bu liste, `"ad=değer"` formatında olan ortam değişkenlerini içerir (örneğin, `USER=droh`).

`execve()` çağrıldığında, şu işlemler gerçekleşir:

1. **Yeni İkili Dosyanın Yüklenmesi:** İşletim sistemi, belirtilen `filename`'deki yeni ikili (binary) dosyayı belleğe yükler.
2. **Yeni Yığın (Stack) ve Yığın Alanı (Heap) Başlatılır:** Yeni programın çalışması için gerekli olan bellek alanları (yığın ve yığın alanı) başlatılır.
3. **Program Başlatılır:** Yeni program, giriş noktası olan `main()` fonksiyonundan itibaren çalıştırılır.

---

### **execve() Ne Yapar?**

- **Belleği Yeniden Yazar:** Mevcut sürecin tüm kodunu, verilerini ve yığınını (stack) yeni bir programla değiştirir.
- **PID ve Dosyalar:** Süreç, aynı PID ile çalışmaya devam eder ve açık olan dosya tanıtıcıları korunur.
- **Sinyal Durumu:** Süreç, sinyal bağlamını korur.
- **Geri Dönmez:** `execve()` başarılı olduğunda geri dönüş yapmaz, çünkü artık yeni bir program çalışıyordur. Yalnızca bir hata oluştuğunda geri döner.

---

### **Betik Dosyaları (Script Files):**

Eğer çalıştırılan dosya bir betik dosyasıysa (örneğin `#!/bin/bash` ile başlayan bir betik), işletim sistemi bu betiği belirtilen yorumlayıcı (interpreter) ile çalıştırır. Bu dosyanın başındaki `#!` ifadesi, hangi yorumlayıcının kullanılacağını belirtir.

---

### fork() ve execve(): Birlikte Kullanımı

- **`fork()` ve `execve()` Arasındaki Fark:**
    
    `fork()` yeni bir süreç oluşturur, ancak mevcut bellek alanını kopyalar. `execve()`, yeni bir süreç oluşturmaz, mevcut sürecin belleğini yeni bir programla değiştirir.
    
- **Yeni Program Başlatmak:**
    
    Yeni bir program başlatmak için önce `fork()` ile bir çocuk süreç oluşturulur ve ardından çocuk süreç içinde `execve()` çağrılarak bu sürecin belleği yeni bir programla değiştirilir. Bu kombinasyon, çok sık kullanılan bir yöntemdir çünkü bu sayede yeni program, mevcut süreci sonlandırmadan paralel olarak başlatılabilir.
    

---

### **Örnek Kullanım:**

```c
if (fork() == 0) { // Çocuk süreç
    char *args[] = { "/bin/ls", "-l", NULL };
    execve("/bin/ls", args, NULL);  // Yeni program başlat
    // execve başarılı olursa bu satıra geri dönmez
    perror("execve failed");
} else { // Ebeveyn süreç
    wait(NULL); // Çocuk sürecin tamamlanmasını bekle
}
```

Bu örnekte, `fork()` ile bir çocuk süreç oluşturulur ve ardından bu çocuk süreç, `execve()` çağrısı ile yeni bir program (burada `ls -l`) çalıştırır.

---

### execve(): Belleği Değiştirme ve Yeni Program Çalıştırma

**Belleği Değiştirme:**

`execve()` fonksiyonu çağrıldığında, mevcut belleğin içeriği, yeni bir ikili dosyadan (binary file) gelen yeni bellek içeriğiyle değiştirilir. Bu, eski programın tamamen silinmesi ve yeni programın belleğe yüklenmesi anlamına gelir.

- **Geri Dönmez:** `execve()` başarılı bir şekilde çağrıldığında, çağrıyı yapan süreç geri dönmez. Bunun yerine yeni program çalıştırılmaya başlanır. Eğer bir hata olursa, sadece o zaman `execve()` bir hata kodu ile geri döner.

---

### fork() ve exec() Ayrımı: Neden Birleştirmiyoruz?

**Neden `fork()` ve `exec()` Ayrı?**

Bir süreci başlatırken neden tek bir `fork-and-exec()` yerine `fork()` ve `exec()` ayrı olarak kullanılıyor sorusu sıkça sorulur. Bu iki sistem çağrısının ayrı tutulmasının birkaç önemli nedeni vardır:

1. **Süreç Ayarlarını Değiştirme:**
    
    `fork()` ile çocuk süreç oluşturulduktan sonra, yeni bir program çalıştırmadan önce çeşitli ayarları değiştirme imkânı elde edilir. Bu, özellikle dosya tanıtıcıları, sinyaller, veya diğer sistem kaynakları üzerinde değişiklik yapmak için kullanışlıdır.
    
2. **Giriş/Çıkış Yönlendirmesi ve Boru (Pipe) Kullanımı:**
    
    Yeni bir program çalıştırılmadan önce giriş ve çıkış yönlendirmesi (I/O redirection) veya borular (pipes) gibi işlemler yapılabilir. Örneğin, bir komutun çıktısını bir dosyaya yazdırmak ya da bir komutun çıktısını başka bir komuta yönlendirmek için `fork()` ve `exec()` arasında bu ayarlamaları yapmak gerekir.
    

---

### Giriş/Çıkış Yönlendirme (I/O Redirection)

- **Giriş/Çıkış Yönlendirme Nedir?**
    
    Bir programın çıktısını (örneğin, terminal ekranı yerine) bir dosyaya yönlendirmek veya bir programın girişini (örneğin, klavye yerine) bir dosyadan almak için giriş/çıkış yönlendirmesi kullanılır.
    
- **Örnek:**
    
    ```bash
    wc w3.c > newfile.txt
    ```
    
    Bu komut, `w3.c` dosyasındaki satır, kelime ve karakter sayısını hesaplar ve bu sonucu `newfile.txt` dosyasına yazar. İşte bu işlemi yapmak için kabuk (shell) programı şu adımları takip eder:
    
    1. **`fork()` Çağrısı:** Kabuk, bir çocuk süreç oluşturur.
    2. **Çıkış Yönlendirmesi:** Yeni çocuk süreçte, `STDOUT` (standart çıkış, yani terminal ekranı) kapatılır. Bunun yerine yeni bir dosya (`newfile.txt`) açılır ve bu dosya, çıktıyı almak için kullanılır.
    3. **`exec()` Çağrısı:** Çocuk süreç, `wc` komutunu `exec()` ile çalıştırır ve `wc` komutunun çıktısı `newfile.txt` dosyasına yazılır.

---

### Borular (Pipes)

- **Boru Nedir?**
    
    Boru (pipe), bir komutun çıktısını başka bir komutun girişi olarak yönlendirmek için kullanılır. Kabuk programlama dünyasında borular, temel bir araçtır.
    
- **Örnek:**
    
    ```bash
    echo "hello world" | wc
    ```
    
    Bu komut, `echo` komutunun çıktısını `wc` komutunun girişine boru ile aktarır. `echo` komutu "hello world" yazdırır ve bu çıktı, `wc` komutuna gönderilir. `wc`, bu çıktıyı analiz ederek satır, kelime ve karakter sayısını hesaplar.
    

---

### Kabuk Programlamasında Boru ve Yönlendirme

Kabuk (shell), bu gibi işlemleri `fork()` ve `exec()` kullanarak gerçekleştirir. Örneğin:

1. **`fork()` İle Süreç Oluşturma:** Kabuk, her komut için yeni bir çocuk süreç oluşturur.
2. **Çıkışı Yönlendirme:** Çocuk süreç, `STDOUT`’u kapatır ve çıktı dosyasını açar ya da bir boru kullanarak çıktıyı başka bir sürece yönlendirir.
3. **`exec()` İle Komutu Çalıştırma:** Son olarak, çocuk süreç `exec()` kullanarak komutu çalıştırır.

Bu adımlar sayesinde komutlar arka arkaya çalıştırılabilir ve çıktıları yönlendirilip işlenebilir.

---

### Linux İşlem Hiyerarşisi

Linux işletim sisteminde, her süreç belirli bir hiyerarşi içinde çalışır. Bu hiyerarşi, süreçlerin birbirleriyle nasıl ilişkilendirildiğini ve kaynakların nasıl paylaşıldığını gösterir. Bu hiyerarşiyi anlamak için bazı temel terimlere bakalım:

- **`init` Süreci (PID 1):**
    
    Linux'taki tüm süreçlerin köküdür ve sistem başlatıldığında ilk çalışan süreçtir. Diğer tüm süreçler, doğrudan veya dolaylı olarak bu süreçten türetilir. `init` süreci, diğer süreçlerin ebeveynidir.
    
- **Daemon Süreçleri:**
    
    Arka planda çalışan, kullanıcılarla doğrudan etkileşimde olmayan hizmet süreçleridir. Örneğin, bir web sunucusu hizmeti (`httpd`) bir daemon sürecidir. Bu süreçler genellikle `init` sürecinden türetilir.
    
- **Login Shell (Giriş Kabukları):**
    
    Kullanıcıların oturum açtıktan sonra çalıştırdıkları kabuk süreçleridir (örneğin, `bash` veya `zsh`). Giriş kabuğu, kullanıcının komutları çalıştırdığı ana süreçtir ve bu süreçten çocuk süreçler türetilebilir.
    

### **Süreç Hiyerarşisini Görüntülemek:**

Linux'ta süreç hiyerarşisini görmek için `pstree` komutu kullanılabilir. Bu komut, mevcut süreçlerin ağaç yapısındaki ilişkilerini gösterir:

```bash
pstree
```

Bu komutla, `init` sürecinden itibaren hangi süreçlerin hangi çocuk süreçleri oluşturduğunu görebilirsiniz.

---

### Dosya Tanıtıcı ve Dosya Tanıtıcı Tablosu

Bir süreç, dosyalara, dizinlere, borulara veya cihazlara erişmek için **dosya tanıtıcılarını** kullanır. Dosya tanıtıcıları, işletim sisteminin dosya sistemine erişim sağlamak için kullandığı sayısal değerlerdir.

### **Dosya Tanıtıcı Nedir?**

- **Dosya Tanıtıcısı:**Bir dosya, boru, dizin veya cihazı temsil eden bir tam sayıdır. Örneğin, bir süreç bir dosya açtığında, işletim sistemi bu dosyayı temsil eden bir dosya tanıtıcısı verir.

### **Standart Dosya Tanıtıcıları:**

Linux'ta her sürecin varsayılan olarak 3 dosya tanıtıcısı vardır:

1. **Dosya Tanıtıcısı 0:** **Standart Giriş (STDIN)** – Klavyeden veya bir dosyadan gelen girdileri temsil eder.
2. **Dosya Tanıtıcısı 1:** **Standart Çıkış (STDOUT)** – Ekrana veya bir dosyaya yönlendirilen çıktıları temsil eder.
3. **Dosya Tanıtıcısı 2:** **Standart Hata (STDERR)** – Hata mesajlarını ekrana veya başka bir hedefe yönlendiren dosya tanıtıcısıdır.

### **Dosya Tanıtıcı Tablosu:**

Her sürecin kendi **dosya tanıtıcı tablosu** vardır. Bu tablo, sürecin hangi dosyaları veya kaynakları kullanmakta olduğunu takip eder. Her bir dosya tanıtıcısı, bu tabloda bir girdiye karşılık gelir ve o dosya veya kaynağa karşılık gelen sistem kaynaklarına erişimi sağlar

---

### Dosya Tanıtıcıları ve Sistem Çağrıları

Dosya tanıtıcıları, işletim sistemi ile dosyalar, borular (pipes), dizinler veya cihazlar arasında bağlantı kurmamızı sağlayan önemli araçlardır. İşletim sistemi, dosya sistemine erişim sağlamak için çeşitli sistem çağrılarını kullanır. Şimdi bunları daha detaylı inceleyelim:

---

### **open(): Dosya Açma**

`open()` sistem çağrısı, bir dosya açmak veya yeni bir dosya oluşturmak için kullanılır.

- **Yeni Bir Dosya Nesnesi Ayırır:**
    
    İşletim sistemi, açılan dosya için bir dosya nesnesi oluşturur. Bu nesne, dosya hakkında bilgi (dosya konumu, erişim hakları vb.) içerir.
    
- **Yeni Bir Dosya Tanıtıcısı Ayırır:**
    
    Açılan dosyayı temsil eden yeni bir dosya tanıtıcısı (integer) oluşturulur. Bu tanıtıcı, dosya tanıtıcı tablosuna eklenir.
    
    - Tanıtıcı olarak, mevcut tablodaki en küçük "boş" dosya tanıtıcısı kullanılır.

**Örnek:**

```c
int fd = open("myfile.txt", O_RDONLY);
```

Bu kod, `myfile.txt` dosyasını yalnızca okuma modunda açar ve bu dosya için bir dosya tanıtıcısı döner.

---

### **close(): Dosya Kapatma**

`close()` sistem çağrısı, belirtilen dosya tanıtıcısını kapatır ve bu tanıtıcının temsil ettiği dosya nesnesini serbest bırakır.

- **Dosya Tanıtıcısını Serbest Bırakır:**
    
    Belirtilen dosya tanıtıcısı dosya tanıtıcı tablosundan çıkarılır.
    
- **Dosya Nesnesini Serbest Bırakır:**
    
    Eğer başka hiçbir süreç bu dosya nesnesine erişmiyorsa, dosya nesnesi de serbest bırakılır (deallocate edilir).
    

**Örnek:**

```c
close(fd);
```

Bu kod, `fd` ile temsil edilen dosya tanıtıcısını kapatır.

---

### **fork(): Dosya Tanıtıcı Tablosunun Kopyalanması**

`fork()` sistem çağrısı, bir ebeveyn süreçten bir çocuk süreç oluşturur. Çocuk süreç, ebeveyn sürecin tam bir kopyasıdır ve dosya tanıtıcı tablosu da dahil olmak üzere tüm sistem kaynaklarını kopyalar.

- **Dosya Tanıtıcı Tablosu Kopyalanır:**Ebeveyn sürecin açık dosya tanıtıcıları, çocuk sürece de kopyalanır. Ancak her iki süreç de aynı dosya nesnesine erişir.

---

### **exec(): Dosya Tanıtıcılarını Koruma**

`exec()` sistem çağrısı, mevcut sürecin belleğini yeni bir programla değiştirir. Ancak, dosya tanıtıcı tablosu korunur. Yani, `exec()` çağrısı yapıldığında, yeni program mevcut dosya tanıtıcılarıyla çalışmaya devam eder.

---

### Boru (pipe): Süreçler Arası Veri Aktarımı

Boru (pipe), bir sürecin çıktısını (STDOUT), başka bir sürecin girişi (STDIN) olarak yönlendirmek için kullanılır. UNIX kabuklarının en önemli yeniliklerinden biridir.

- **Borunun Uygulanması:**
    
    Bir boru, `dup()` ve `pipe()` sistem çağrıları kullanılarak uygulanır. `pipe()`, iki süreç arasında bir veri aktarım kanalı oluşturur.
    
- **Borunun Çalışma Mantığı:**
    
    ```bash
    echo "hello world" | wc
    ```
    
    Yukarıdaki komutta, `echo` komutunun çıktısı (`hello world`), `wc` komutuna boru ile yönlendirilir. `echo` komutunun STDOUT'u, `wc` komutunun STDIN'ine aktarılır.
    

---

### **dup(): Dosya Tanıtıcısını Kopyalama**

`dup()` sistem çağrısı, mevcut bir dosya tanıtıcısını kopyalar. Yeni kopyalanan dosya tanıtıcısı, aynı dosya nesnesine işaret eder.

- **Örnek Kullanım:**Bu kod, `fd` ile temsil edilen dosya tanıtıcısını kopyalar ve yeni bir dosya tanıtıcısı (`new_fd`) döndürür. Hem `fd` hem de `new_fd` aynı dosya nesnesini paylaşır.
    
    ```c
    int new_fd = dup(fd);
    ```
    

---

### `pipe()`: Özel Bir Dosya Türü

`pipe()` sistem çağrısı, süreçler arasında veri aktarımını sağlayan özel bir dosya türüdür. Bu mekanizma, **çekirdek tamponu** üzerinden veri alışverişi yapmak için iki dosya tanıtıcısı sunar:

- **p[0]**: Okuma ucu (read end) – Veri bu uçtan okunur.
- **p[1]**: Yazma ucu (write end) – Veri bu uçtan yazılır.

**`pipe()` Özellikleri:**

- **Okuyucu Bloke Olur:** Eğer okunacak veri yoksa, okuyucu süreç (read end) bloklanır, yani veri gelene kadar bekler. Bu, işlem sürecini senkronize etmeye yardımcı olur.
- Yazıcı süreç, veri yolladıkça okuyucu süreç veri alır ve iki süreç eş zamanlı olarak çalışabilir.

**Örnek:**

```c
int fd[2];
pipe(fd);
```

Bu kod, `fd[0]` dosya tanıtıcısını okuma ucu, `fd[1]` dosya tanıtıcısını ise yazma ucu olarak atayan bir boru oluşturur.

---

### `pipe()` ve G/Ç Yönlendirme (IO Redirection) Arasındaki Farklar

Boru (pipe) ve G/Ç yönlendirme, komut çıktısını başka bir komuta veya dosyaya yönlendirme yöntemleridir, ancak borular belirli avantajlara sahiptir.

### **Avantajları:**

1. **Kendi Kendini Temizleme:**
    - **Boru:** Borular otomatik olarak temizlenir. Veri aktarımı tamamlandığında, çekirdek tamponu otomatik olarak serbest bırakılır.
    - **G/Ç Yönlendirme:** Geçici dosya kullanıldığında, dosyanın kullanıcı tarafından manuel olarak silinmesi gerekir.
    
    **Örnek:**
    
    ```bash
    echo "hello world" | wc
    ```
    
    Bu komutta, `echo` komutunun çıktısı doğrudan `wc` komutuna yönlendirilir ve boru kapatıldığında geçici olarak kullanılan kaynaklar otomatik olarak serbest bırakılır.
    
2. **Disk Alanı Tasarrufu:**
    - **Boru:** Borular, çekirdek tamponu kullanarak veri aktarır, bu nedenle diskte geçici dosya oluşturmazlar. Bu, sınırsız veri aktarımını mümkün kılar (çekirdek tamponu döngüsel olarak kullanılır).
    - **G/Ç Yönlendirme:** Yönlendirme ile kullanılan geçici dosya yeterli disk alanına ihtiyaç duyar. Büyük veri aktarımı için disk alanı sınırlayıcı olabilir.
    
    **Örnek:**
    
    ```bash
    echo "hello world" > /tmp/xyz
    wc < /tmp/xyz
    ```
    
    Bu komutta, `echo` çıktısı `/tmp/xyz` adlı geçici dosyaya yazılır ve sonra `wc` bu dosyadan okur. Bu yöntemde disk alanı kullanılır.
    
3. **Paralel Çalışma:**
    - **Boru:** Borular, yazıcı ve okuyucu süreçlerin eşzamanlı çalışmasına olanak tanır. Bir süreç veri yazarken diğeri aynı anda veriyi okuyabilir.
    - **G/Ç Yönlendirme:** Yönlendirme ile bir süreç (örneğin yazıcı) tamamlanmadan diğeri başlayamaz. İlk süreç bitene kadar beklemek zorundadır.
    
    **Örnek:**
    
    ```bash
    echo "hello world" | wc
    ```
    
    Bu komutta, `echo` komutu veri yazarken, `wc` komutu aynı anda veriyi okuyabilir.
    

---

### Boruların Uygulanması (`pipe()` ve `dup()`)

Borular, genellikle `dup()` sistemi ile birlikte kullanılır. `dup()` sistemi, dosya tanıtıcısını çoğaltarak farklı süreçlerde aynı dosya üzerinde işlem yapmayı sağlar. `pipe()` ile veri akışını sağlarken, `dup()` ile bu akışı yönlendirebiliriz.

Borular, özellikle UNIX kabuk programlamasının önemli bir parçasıdır ve süreçler arası veri iletişimini kolaylaştırır.

---

### Süreçler Arası İletişim (IPC)

**Süreçler Arası İletişim (Inter-Process Communication, IPC)**, işbirliği yapan süreçlerin veya iş parçacıklarının (threads) birbiriyle veri alışverişi yapması için kullanılan yöntemdir. IPC, çoklu süreçlerin veya iş parçacıklarının birlikte çalışması gerektiği durumlarda kullanılır.

IPC mekanizmaları, **aynı bilgisayarda çalışan süreçler** arasında veya **ağ üzerinden birden fazla bilgisayarda çalışan süreçler** arasında iletişim sağlayabilir.

---

### IPC'nin Ana Kullanım Alanları

1. **Veri Aktarımı (Data Transfer):**
    
    Süreçlerin, birinden diğerine veri göndermesi veya paylaşmasıdır. Örneğin, bir süreçten elde edilen çıktı başka bir sürece girdi olarak aktarılabilir.
    
2. **Veri Paylaşımı (Sharing Data):**
    
    Birden fazla sürecin aynı veriyi paylaşarak kullanması durumudur. Bu, özellikle işbirliği yapan süreçler arasında verimli veri alışverişi sağlamak için kullanılır.
    
3. **Olay Bildirimi (Event Notification):**
    
    Bir süreçte meydana gelen bir olayın diğer süreçlere bildirilmesidir. Bu, süreçlerin belirli olaylara tepki vermesini sağlar (örneğin, bir dosyanın kapanması veya bir kaynağın kullanıma açılması).
    
4. **Kaynak Paylaşımı (Resource Sharing):**
    
    Birden fazla sürecin aynı kaynağı (örneğin dosya, bellek alanı veya cihaz) paylaşmasıdır. IPC, bu kaynakların etkin bir şekilde yönetilmesini sağlar.
    
5. **Süreç Kontrolü (Process Control):**
    
    Bir sürecin diğer süreçleri başlatması, durdurması veya kontrol etmesidir. Örneğin, bir süreç, başka bir süreci başlattığında onun durumunu izleyebilir ve gerektiğinde durdurabilir.
    

---

### IPC'nin Uygulama Yöntemleri

Süreçler arası iletişim (IPC), **ağ bağlantısı üzerinden** veya **aynı sistemde çalışan süreçler** arasında gerçekleştirilebilir. Seçilecek yöntem, iletişim band genişliği, gecikme süresi ve iletilen veri türüne bağlı olarak değişir.

IPC’nin yaygın yöntemleri şunlardır:

- **Boru (Pipe):**
    
    Aynı bilgisayarda çalışan süreçler arasında bir veri yolu sağlar. Bir süreç borunun yazma ucuna veri yazarken, diğer süreç okuma ucundan bu veriyi alır.
    
- **Paylaşılan Bellek (Shared Memory):**
    
    Süreçlerin aynı bellek alanını paylaşarak veri alışverişi yapmasını sağlar. Bu yöntem, büyük miktarda veri paylaşımı gerektiğinde en verimli IPC yöntemlerinden biridir.
    
- **Mesaj Kuyruğu (Message Queue):**
    
    Süreçler arasında mesaj tabanlı veri aktarımı sağlar. Bu, birbirinden bağımsız süreçlerin iletişim kurmasını kolaylaştırır.
    
- **Sinyaller (Signals):**
    
    Bir süreçte meydana gelen olayları diğer süreçlere bildirmek için kullanılan küçük mesajlardır. Özellikle olay bildiriminde yaygındır.
    
- **Soketler (Sockets):**
    
    Ağ üzerinden farklı bilgisayarlarda çalışan süreçler arasında iletişim sağlar. İnternet tabanlı uygulamalar için sıkça kullanılır.
    

---

### IPC'nin Önemi

Süreçler arası iletişim, özellikle çok çekirdekli sistemlerde ve paralel işlem yapan uygulamalarda kritik bir rol oynar. IPC, süreçlerin koordineli bir şekilde çalışmasını sağlar, verimli kaynak kullanımı ve veri paylaşımı için gerekli mekanizmaları sunar. Bu nedenle, modern işletim sistemleri ve dağıtık sistemlerde temel bir kavramdır.

---

### IPC Mekanizmaları

**Süreçler Arası İletişim (IPC)**, işbirliği yapan süreçler arasında veri alışverişi ve iletişimi sağlamak için çeşitli mekanizmalar sunar. Bu mekanizmalar, süreçlerin verimli bir şekilde iletişim kurmasına, veri paylaşmasına ve kaynakları yönetmesine olanak tanır. İşte yaygın IPC mekanizmaları:

1. **Sinyaller (Signals):**
    
    Süreçler arasında basit bildirimler iletmek için kullanılır. Belirli olayların meydana geldiğini bildirmek için bir sinyal gönderilir.
    
2. **Boru (Pipes):**
    - **İsimsiz Borular (Unnamed Pipes):**İki süreç arasında veri akışı sağlamak için kullanılır. Bir süreç tarafından yazılan veriler, diğer süreç tarafından okunabilir.
    - **İsimli Borular (Named Pipes / FIFOs):**İki veya daha fazla süreç arasında veri iletimi için kullanılan ve isimlendirilmiş borulardır. Süreçler boruya isimleriyle erişebilir.
3. **Mesaj Kuyrukları (Message Queues):**
    
    Süreçler arasında mesaj tabanlı veri aktarımı sağlar. Mesajlar kuyrukta saklanır ve süreçler sırayla bu mesajları alabilir.
    
4. **Paylaşılan Bellek (Shared Memory):**
    
    Süreçlerin aynı bellek alanını paylaşarak hızlı bir şekilde veri alışverişi yapmasını sağlar. Bu yöntem, büyük miktarda veri iletimi için en verimli IPC yöntemlerinden biridir.
    
5. **Bellek Haritalı Dosyalar (Memory Mapped Files):**
    
    Dosya içeriğinin bir bellek adresine eşlenmesi ile süreçlerin dosyayı doğrudan okumasını veya yazmasını sağlar.
    
6. **Semaphore (Semaphore):**
    
    Süreçler arasında senkronizasyon sağlamak için kullanılır. Çoklu süreçlerin ortak kaynaklara erişimini kontrol etmek için yararlıdır.
    
7. **Ağ Üzerinden Uzak Süreçler:**
    - **Uzak Prosedür Çağrıları (Remote Procedure Calls - RPC):**Farklı makinelerdeki süreçler arasında iletişim sağlamak için kullanılır. Bir süreç, diğer bir süreçte belirli bir işlevi çağırabilir.
    - **Soketler (Sockets):**Ağ üzerindeki farklı bilgisayarlarda çalışan süreçler arasında veri iletimi sağlar. Soketler, TCP veya UDP protokollerini kullanarak iletişim kurar.

---

### (İsimsiz) Borular (Unnamed Pipes)

**İsimsiz Borular**, süreçler arasında bir byte akışı sağlayan bir IPC mekanizmasıdır. Bir süreç tarafından yazılan byte'lar, diğer bir süreç tarafından okunabilir.

### **Uygulama Alanları:**

- **Kabuk Programlama (Shell Scripting):**Bir programın çıktısını diğer bir programa yönlendirmek için yaygın olarak kullanılır. Örneğin:Burada, `cat` komutunun çıktısı `sort` komutuna yönlendirilir.
    
    ```bash
    cat file1 file2 | sort
    ```
    

### **Sınırlamalar:**

- **Bağlı Süreçler:**Borular, yalnızca ilişkili süreçler (ebeveyn-çocuk veya kardeş süreçler) arasında kullanılabilir.
- **Baskı Yapma (Broadcasting):**Borular, çoklu okuyucular veya yazarlar arasında yayılma yapamaz.
- **Veri Yapısı:**Borudaki veri, bir byte akışı şeklindedir ve yapısal bir özellik taşımaz. Bu nedenle, birkaç okuyucu veya yazar arasında ayrım yapmak mümkün değildir.

### **Uygulama:**

- **İçsel Çekirdek Tamponları, Soket Tamponları veya STREAM Arayüzü:**Borular, bu yapıların kullanımı ile uygulanır. Bu sayede veri akışı sağlanır.

---

### Borular (Pipes)

**Borular**, süreçler arası iletişim (IPC) için kullanılan temel mekanizmalardan biridir. Bir boru, verilerin bir sürecin çıkışından diğer bir sürecin girişi olarak akmasını sağlayan bir veri yapısıdır. Borular, çekirdek (kernel) düzeyinde oluşturulurlar ve genellikle iki süreç arasında bir yönlü veri akışı sağlamak için kullanılır.

---

### Boru Oluşturma

Boru oluşturmak için kullanılan sistem çağrısı:

```c
int pipe(int *fd);
```

Bu çağrı, bir boru oluşturur ve iki dosya tanımlayıcısını (`fd`) geri döner:

- **`fd[0]`**: Okuma için açılır (read end).
- **`fd[1]`**: Yazma için açılır (write end).

### Kullanım Örneği:

1. Bir süreç boruyu oluşturur.
2. Süreç, `fork()` sistem çağrısını kullanarak kendisini çoğaltır.
3. Ebeveyn süreç, `fd[1]` üzerinden veri yazar; çocuk süreç ise `fd[0]` üzerinden veriyi okur.

Boru, veri akışının tek yönlü olmasını sağlar. Örneğin:

```bash
who | sort | ipr
```

Bu örnekte, `who` komutunun çıktısı, `sort` komutuna girdi olarak yönlendirilir, ve ardından `ipr` komutuna geçer.

---

### Boru ile Dosya Arasındaki Farklar

- **Veri Yapısı:**
    
    Bir boru, çekirdek düzeyinde bir veri yapısıdır. Veriler, geçici olarak çekirdek tamponlarında saklanır. Borular üzerinde rastgele erişim (seek) yoktur; veriler sıralı bir akış şeklinde okunur ve yazılır.
    
- **Boru Oluşturma:**
    
    Borular, yukarıda belirtilen `pipe()` sistem çağrısı ile oluşturulur. `filedes`, boyutu 2 olan bir dizi (array) olarak tanımlanır.
    
- **Dosya Tanımlayıcıları:**
    - **`filedes[0]`**: Okuma için açılır.
    - **`filedes[1]`**: Yazma için açılır.
    
    Bazı sistemler, iki yönlü (bidirectional) boruları destekler, bu durumda her iki uç da okunabilir/yazılabilir.
    
- **Tampon Boyutu:**
    
    Tipik boru tampon boyutu 512 bayt (POSIX tarafından tanımlanan minimum limit) olarak belirlenmiştir. Okuma ve yazma işlemleri, tampon dolu olduğunda engellenebilir.
    

---

### Boru Kullanımında Dikkat Edilmesi Gerekenler

- Borular, yalnızca ilişkili süreçler (ebeveyn-çocuk veya kardeş süreçler) arasında kullanılabilir.
- Borular, çoklu okuyucu veya yazar ile yayılamaz.
- Veri yapısı olarak bir byte akışı sağlar; dolayısıyla yapılandırılmış bir veri akışı sağlamaz.

---

### Sonuç

Borular, UNIX tabanlı sistemlerde süreçler arası veri aktarımı için kritik bir araçtır. Veri akışını basit ve etkili bir şekilde yönetir, ancak sınırlamaları ve kullanım koşulları göz önünde bulundurularak dikkatli bir şekilde kullanılmalıdır.

---

### Boru (Pipe) ile İletişim Örneği

```c
#include <unistd.h>#include <stdio.h>int main(void) {
    int n;                      // Okunan byte sayısını takip etmek için değişken
    int fd[2];                  // Borunun her iki ucunu tutan dosya tanımlayıcıları
    pid_t pid;                  // Çocuk sürecin PID'sini tutan değişken
    char line[80];              // Borudan okunan metni saklayacak tampon (buffer)

    // Boru oluşturma
    if (pipe(fd) < 0) {
        perror("pipe error");   // Boru oluşturulamazsa hata mesajı basılır
        return 1;               // Hata durumunda program sonlandırılır
    }

    // fork ile süreç bölme
    if ((pid = fork()) < 0) {
        perror("fork error");   // fork başarısız olursa hata mesajı basılır
        return 1;
    }
    // Çocuk süreç kodu
    else if (pid == 0) {
        close(fd[0]);           // Çocuk süreç, okuma ucunu kapatır
        // Borunun yazma ucuna veri yazar
        write(fd[1], "hello world\n", 12);
    }
    // Ebeveyn süreç kodu
    else {
        close(fd[1]);           // Ebeveyn süreç, yazma ucunu kapatır
        // Borunun okuma ucundan veri okur
        n = read(fd[0], line, 80);
        // Okunan veriyi ekrana yazdırır
        write(1, line, n);
    }

    return 0;
}
```

---

### Adım Adım Açıklamalar

### 1. `pipe(fd)`

Bu sistem çağrısı bir boru oluşturur ve `fd[0]` ile `fd[1]` dosya tanımlayıcılarını doldurur. Bu dosya tanımlayıcılar:

- **`fd[0]`**: Borunun okuma ucu.
- **`fd[1]`**: Borunun yazma ucu.

Eğer `pipe(fd)` çağrısı başarılı olmazsa, `perror("pipe error")` ile bir hata mesajı basılır ve program sonlandırılır.

### 2. `fork()`

`fork()` sistem çağrısı ile süreç ikiye bölünür:

- **Ebeveyn Süreç**: `fork()` geri dönüş değeri, çocuk sürecin PID'si olur.
- **Çocuk Süreç**: `fork()` geri dönüş değeri 0 olur.

Eğer `fork()` başarısız olursa, `perror("fork error")` hata mesajı ile program sonlandırılır.

### 3. Çocuk Süreç:

Çocuk süreç, borunun okuma ucunu kapatır çünkü sadece yazma işlemi yapacaktır. Ardından, `write(fd[1], "hello world\n", 12)` ile boruya "hello world\n" mesajını yazar.

### 4. Ebeveyn Süreç:

Ebeveyn süreç, borunun yazma ucunu kapatır çünkü sadece okuma işlemi yapacaktır. `read(fd[0], line, 80)` ile borudan veriyi okur ve okunan bayt sayısını `n` değişkenine kaydeder. Son olarak, `write(1, line, n)` ile ekrana (`fd 1 = stdout`) okunan mesajı yazdırır.

---

### Çalışma Prensibi

1. Ebeveyn süreç, boru oluşturur ve `fork()` ile kendisini ikiye böler.
2. Çocuk süreç, borunun yazma ucunu kullanarak bir mesaj yazar.
3. Ebeveyn süreç, borunun okuma ucundan bu mesajı okur ve ekrana yazdırır.
4. Veri akışı tek yönlüdür; yazma işlemi çocuk süreçten, okuma işlemi ebeveyn süreçten yapılır.

---

### Önemli Noktalar

- **`close(fd[0])` ve `close(fd[1])` kullanımı**: Süreçlerin, kullanmadıkları boru uçlarını kapatmaları önemlidir. Aksi takdirde, veri akışı ve boru kullanımı verimli olmaz.
- **`write()` ve `read()`**: Bu sistem çağrıları boru aracılığıyla veri yazma ve okuma işlemlerini gerçekleştirir. `write()` çağrısı, boruya veriyi yazar; `read()` çağrısı ise borudan veriyi okur.
- **Tampon (Buffer) Boyutu**: Bu örnekte, 80 baytlık bir tampon kullanılmıştır. Bu, borudan okunan verilerin saklanacağı yerdir.

---

### 1. **Fork Sonrası Dosya Tanımlayıcıları (fd)**

Bir süreç `fork()` sistem çağrısını kullandığında, süreç ikiye bölünür ve her iki süreç de aynı dosya tanımlayıcı tablosuna sahip olur. Fakat, her süreç kendi bellek alanında çalıştığı için bu dosya tanımlayıcılar birbirinden bağımsızdır.

- **fd 0**: Standart giriş (stdin)
- **fd 1**: Standart çıkış (stdout)
- **fd 2**: Standart hata (stderr)
- **fd 3 ve 4**: `pipe()` çağrısı sonucu oluşan dosya tanımlayıcıları.

Bu dosya tanımlayıcıları **pipe** aracılığıyla ebeveyn ve çocuk süreçleri arasında veri iletişimi sağlar.

---

### 2. **Pipe ile Veri İletimi**

- **`pipe()` sistem çağrısı**, iki uçlu bir boru oluşturur. Bu uçlar `fd[0]` (okuma) ve `fd[1]` (yazma) olarak adlandırılır.
- **Ebeveyn sürecin çocuk sürece veri göndermesi** için:
    - Ebeveyn süreç yazma ucunu (fd[1]) kullanır.
    - Çocuk süreç ise okuma ucunu (fd[0]) kullanarak veriyi alır.

### Örnek: İki Yönlü İletişim

Eğer iki yönlü bir iletişim gerekiyorsa, yani hem ebeveyn hem de çocuk süreç veri alışverişi yapacaksa, iki ayrı boru oluşturulması gerekmektedir. Bir boru ebeveyn sürecin yazması ve çocuk sürecin okuması için, diğer boru ise bunun tam tersi şekilde çalışabilir.

- **Tek yönlü iletişim**: Ebeveyn veri yazar, çocuk veri okur.
- **İki yönlü iletişim**: Ebeveyn ve çocuk arasında hem okuma hem yazma yapılabilir.

Sistemlerde bazı borular çift yönlü (bidirectional) olabilir, bu durumda tek bir boru ile iki yönlü iletişim sağlanabilir.

---

### 3. **Dosya Tanımlayıcılarının Kapatılması (close())**

Her süreç, kullanmayacağı boru uçlarını **kapatmalıdır**. Eğer bir uç açık kalırsa, veri akışı düzgün çalışmayabilir ve iletişim hataları oluşabilir. Özellikle aşağıdaki durumlar önemlidir:

- Ebeveyn süreç, sadece yazma işlemi yapacaksa, okuma ucunu (fd[0]) kapatmalıdır.
- Çocuk süreç, sadece okuma işlemi yapacaksa, yazma ucunu (fd[1]) kapatmalıdır.

---

### 4. **Sinyaller (Signals)**

Sinyaller, süreçlere olay bildirimleri göndermek için kullanılan küçük mesajlardır. Sinyaller donanımsal kesmelere (interrupts) benzer, ancak işletim sistemi (OS) tarafından süreçlere gönderilirler. Örneğin:

- **Donanım kesmeleri**: OS'ye donanım olaylarını bildirir.
- **Sinyaller**: İşletim sistemi, bir süreçte bir olay meydana geldiğinde süreçlere sinyal gönderir.

### Sinyal Türleri ve ID'leri

Sinyaller, küçük tamsayı kimlik numaralarıyla (ID) tanımlanır. Bu sinyaller süreçleri durdurabilir, yeniden başlatabilir veya belirli bir olayın gerçekleştiğini bildirebilir. Bazı sinyal örnekleri şunlardır:

- **SIGKILL**: Süreci zorla sonlandırır (engellenemez).
- **SIGSTOP**: Süreci durdurur (engellenemez).
- **SIGALRM**: Bir zamanlayıcı sinyali.
- **SIGCHLD**: Çocuk süreçlerden birinin sona erdiğini ebeveyne bildirir.

### Sinyal İşleme

Bir süreç bir sinyal aldığında, genellikle varsayılan davranışla ya sonlandırılır ya da bir sinyal işleyici (signal handler) kullanarak belirli bir işlem gerçekleştirebilir.

---

### 5. **Sinyal Gönderme (Sending a Signal)**

Bir sinyal gönderildiğinde, çekirdek (kernel) bu sinyali hedef sürece iletir. Sinyaller, çeşitli olaylar sonucunda başlatılabilir:

- **Donanım olayı**: Bir matematiksel hata (örneğin, sıfıra bölme) gibi.
- **İşletim sistemi olayı**: Çocuk süreçlerin sonlanması (SIGCHLD).
- **Kullanıcı girişi**: Klavyeden bir giriş (Ctrl+C ile SIGINT).

Sinyal durumu, süreç kontrol bloğunda (PCB) saklanır ve bu sinyallerin beklediği ya da engellendiği belirtilir.

---

### Özet

1. **Fork ve Pipe**: Süreçler arası iletişimde kullanılır.
2. **Dosya Tanımlayıcıları**: Pipe ile okuma/yazma işlemleri yapılır.
3. **Sinyaller**: İşletim sistemi tarafından süreçlere gönderilen küçük mesajlardır.

---

```python
int p[2];
char *argv[2];

argv[0] = "wc";
argv[1] = 0;

pipe(p);
if(fork() == 0){
  close(0);
  dup(p[0]);
  close(p[0]);
  close(p[1]);
  exec("/bin/wc", argv);
}
else{
  close(p[0]);
  write(p[1],"hello world\n",12);
  close(p[1]);
}
```

Bu kod, bir **pipe** (boru) kullanarak iki süreç arasında veri aktarımı gerçekleştiren bir örnektir. Ebeveyn süreç (parent process) ve çocuk süreç (child process) arasında bir boru oluşturulur, ardından çocuk sürece veri gönderilir ve bu veri **wc** (word count) komutuyla işlenir. Kodun adım adım açıklamasına bakalım.

### Adım Adım Açıklama:

### 1. **pipe(p);**

```c
int p[2];
pipe(p);
```

Bu adımda `pipe()` sistem çağrısı ile bir boru oluşturulur. Bu boru, iki dosya tanımlayıcı (file descriptor) içerir:

- `p[0]`: Okuma ucu (read end).
- `p[1]`: Yazma ucu (write end).

Borudan veri akışı, yazma ucuna yazılan verinin, okuma ucundan okunmasıyla gerçekleşir.

### 2. **fork() sistemi ile süreç oluşturma:**

```c
if(fork() == 0)
```

`fork()` sistemi kullanılarak bir çocuk süreç oluşturulur. Eğer `fork()` işlemi başarılı olursa, ebeveyn süreç için `fork()` işlemi 0 olmayan bir değer döndürür, çocuk süreç için ise 0 döner. Bu kontrol, çocuk süreci ve ebeveyn süreci ayırmak için kullanılır:

- **Eğer `fork()` sonucu 0 ise**, kod çocuk süreçte çalışır.
- **Eğer `fork()` sonucu 0 değilse**, kod ebeveyn süreçte çalışır.

### 3. **Çocuk Süreç (Child Process):**

```c
close(0); // Standart girişi kapat
dup(p[0]); // Borunun okuma ucunu standart girişe kopyala (p[0] -> fd 0)
close(p[0]); // Okuma ucunu kapat
close(p[1]); // Yazma ucunu kapat
exec("/bin/wc", argv); // wc programını çalıştır
```

Çocuk süreç, aşağıdaki adımları izler:

- **close(0);**: Standart girişi (stdin) kapatır. Bu, dosya tanımlayıcı 0'ın serbest bırakılması anlamına gelir.
- **dup(p[0]);**: `dup()` sistem çağrısı, borunun okuma ucunu (p[0]) standart girişe (fd 0) kopyalar. Bu sayede, `p[0]` artık dosya tanımlayıcı 0 üzerinden erişilebilir.
- **close(p[0]);**: Artık `p[0]` dosya tanımlayıcı kopyalandığı için, orijinal `p[0]` kapatılır.
- **close(p[1]);**: Borunun yazma ucu çocuk süreç tarafından kullanılmadığı için kapatılır.
- **exec("/bin/wc", argv);**: `exec()` sistem çağrısı ile `wc` programı çalıştırılır. Bu, çocuk sürecin mevcut adres alanını (yani, kendi kodunu) `wc` programının adres alanı ile değiştirir.

### 4. **Ebeveyn Süreç (Parent Process):**

```c
close(p[0]); // Okuma ucunu kapat
write(p[1], "hello world\n", 12); // Yazma ucuna veri gönder
close(p[1]); // Yazma ucunu kapat
```

Ebeveyn süreç ise aşağıdaki işlemleri gerçekleştirir:

- **close(p[0]);**: Ebeveyn süreç, borunun okuma ucunu kullanmayacağı için onu kapatır.
- **write(p[1], "hello world\n", 12);**: Borunun yazma ucuna `"hello world\n"` verisini yazar.
- **close(p[1]);**: Yazma işlemi tamamlandıktan sonra yazma ucu da kapatılır.

Bu aşamada, yazılan veri borunun okuma ucuna iletilir ve çocuk süreç `wc` komutunu çalıştırarak bu veriyi okur ve işler. `wc` komutu, gönderilen metindeki satır, kelime ve karakter sayısını ekrana yazar.

### Sonuç:

Bu kod, bir **pipe** ile veri akışı sağlayan basit bir örnek. Ebeveyn süreç, çocuk sürece `"hello world\n"` metnini gönderir ve çocuk süreç de bu metni alıp **wc** komutunu kullanarak kelime, satır ve karakter sayısını hesaplar.

Bu mekanizmanın amacı, bir süreçten diğerine veri aktarımı yaparken, bu veriyi bir **pipe** aracılığıyla iletmektir.

---