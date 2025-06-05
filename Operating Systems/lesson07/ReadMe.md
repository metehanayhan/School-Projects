# 7. Hafta

### Multi-Level Feedback Queue (MLFQ)

**Multi-Level Feedback Queue (MLFQ)**, geçmişteki performansa dayalı olarak gelecekteki işlerin sürelerini tahmin eden bir zamanlayıcıdır. MLFQ, işlemci zamanlamasında esnekliği ve verimliliği artırmak amacıyla çeşitli öncelik seviyelerine sahip birden fazla kuyruk kullanır. İşlemler, daha önceki davranışlarına dayanarak, uygun bir öncelik seviyesine atanır.

### Amaçlar

- **Tamamlanma Süresini Optimize Etmek**: Kısa süreli işleri öncelikli olarak çalıştırarak toplam bekleme süresini azaltmak.
- **Tepki Süresini Minimize Etmek**: İşlerin ne kadar süre çalışacağını önceden bilmeden hızlı bir şekilde yanıt vermek.

### MLFQ: Temel Kurallar

**MLFQ, birden fazla ayrı kuyruktan oluşur**:

- Her kuyruk, farklı bir öncelik seviyesi ile atanır.
- Bir iş çalışmaya hazır olduğunda tek bir kuyruğa yerleştirilir.
- Yüksek öncelikli bir kuyrukta bulunan işler, daha düşük öncelikli kuyruklardaki işlere göre önceliklidir.
- Aynı kuyruktaki işler arasında **Round Robin** (RR) zamanlama kullanılır.

### MLFQ Kuralları

1. **Kural 1**: Eğer A'nın önceliği B'den yüksekse, A çalıştırılır; B çalıştırılmaz.
2. **Kural 2**: Eğer A ve B'nin öncelikleri eşitse, her iki iş de RR ile çalıştırılır.

### MLFQ: Öncelik Değiştirme

MLFQ öncelik ayarlama algoritması şu şekildedir:

1. **Kural 3**: Bir iş sisteme girdiğinde en yüksek öncelik seviyesine atanır.
2. **Kural 4a**: Eğer bir iş, zaman dilimini tamamen kullanırsa, önceliği düşürülür (yani daha alt bir kuyruğa geçer).
3. **Kural 4b**: Eğer bir iş, zaman dilimi dolmadan CPU'yu bırakırsa, mevcut öncelik seviyesinde kalır.

Bu kurallar, MLFQ'yu **Shortest Job First (SJF)** algoritmasına yakınlaştırır.

### MLFQ Örneği: Tek Uzun Süreli İş

Örnek olarak, 10 ms zaman dilimi olan üç kuyruklu bir zamanlayıcı düşünelim. Aşağıdaki şekilde bir uzun süreli işin zaman dilimi içinde nasıl çalıştırıldığını görebiliriz:

```lua
Q2   --  (Düşük öncelikli kuyruk)
Q1       --  (Orta öncelikli kuyruk)
Q0           ----------  (Yüksek öncelikli kuyruk)
       0   5  10   15  20
            0   0    0     0
```

### Açıklama

- İş, başlangıçta **Q0** (yüksek öncelikli kuyruk) üzerinde başlatılır.
- Eğer iş, 10 ms'lik zaman dilimini tamamlamadan CPU'yu bırakırsa, aynı kuyrukta kalır. Ancak zaman dilimini tamamladığında önceliği düşer ve bir sonraki zaman diliminde **Q1**'e geçer.
- Bu durum, uzun süreli bir işin çalışmasını yönetirken kısa işlerin daha hızlı bir şekilde çalıştırılmasını sağlar.

### Sonuç

**MLFQ**, işlemci zamanlayıcılarında daha iyi tepki süreleri ve işlemci kullanımı sağlamak için dinamik bir yaklaşım sunar. Kısa süreli işlerin hızlı bir şekilde işlenmesi, uzun süreli işler için daha az bekleme süresi sağlar ve bu sayede kullanıcı deneyimini iyileştirir. MLFQ, zamanlama sürecinde işlerin geçmiş performansına göre önceliklendirilmesini sağlayarak esnekliği artırır.

---

### Çok Seviyeli Geri Bildirim Kuyruğu (MLFQ) Zamanlama

Çok Seviyeli Geri Bildirim Kuyruğu (MLFQ), süreçleri yönetmek için tasarlanmış karmaşık bir zamanlama algoritmasıdır. Bu algoritma, hem dönüş süresini (turnaround time) hem de yanıt süresini (response time) optimize etmeyi hedefler. İşte MLFQ'nin ana özellikleri, kuralları ve daha basit zamanlama algoritmalarının sınırlamalarını nasıl aşabileceği hakkında detaylı bir açıklama.

### **MLFQ'nin Hedefleri**

1. **Dönüş Süresini Optimize Etmek**: MLFQ, daha kısa işlerin (job) öncelikli olarak çalıştırılmasını hedefleyerek, sistemdeki süreçlerin toplam geçirdiği süreyi azaltmayı amaçlar.
2. **Yanıt Süresini Minimize Etmek**: Etkileşimli işlerin (interactive jobs) hızlı yanıt almasını sağlamak için, iş uzunluğu hakkında önceden bilgiye ihtiyaç duymadan çalışmayı hedefler.

### **MLFQ'nin Temel Yapısı**

- **Birden Fazla Kuyruk**: MLFQ, her birine farklı öncelik seviyeleri atanmış birkaç belirgin kuyruktan oluşur. Yüksek öncelikli kuyruklar, düşük öncelikli kuyruklardan önce işlenir.
- **Her İş İçin Tek Kuyruk**: Her iş yalnızca bir kuyrukta bulunabilir. Hazır durumda olan iş, en yüksek öncelikli kuyruktan seçilerek çalıştırılır.
- **Dairevi Zamanlama (Round-Robin)**: Aynı öncelik kuyruklarındaki işler, dairesel bir şekilde zamanlanır, böylece her iş adil bir CPU süresi alır.

### **MLFQ Kuralları**

1. **Kural 1**: Eğer A kuyruklu bir işin önceliği, B kuyruklu bir işin önceliğinden yüksekse, A çalışır, B çalışmaz.
2. **Kural 2**: Eğer iki iş aynı öncelik kuyrukundaysa, bunlar dairesel (RR) olarak çalıştırılır.
3. **Kural 3**: Sisteme yeni bir iş girdiğinde, en yüksek öncelik kuyrukuna yerleştirilir.
4. **Öncelik Ayarlaması**:
    - **Kural 4a**: Eğer bir iş, çalıştığı süre içinde tüm zaman dilimini (time slice) tüketirse, önceliği düşürülür ve daha düşük öncelikli bir kuyruktan geçer.
    - **Kural 4b**: Eğer bir iş, zaman dilimini tamamlamadan CPU’yu bırakırsa, öncelik seviyesini korur.

Bu ayarlama mekanizması, MLFQ'nin Kısa İş Önceliği (SJF) davranışını taklit etmesine olanak tanır.

### **Örnek Senaryolar**

1. **Tek Uzun Süreli İş**:
    - A işinin (uzun süreli iş) CPU’yu önemli ölçüde meşgul ettiği bir durumu düşünelim. A işinin çalışması devam ederken, daha düşük öncelikli kuyruktaki işler CPU süresinden yoksun kalır.
    - Zamanla, A işi CPU kaynaklarını monopolize ederek, sistemin yanıt verme hızını olumsuz etkileyebilir.
2. **Kısa İşin Gelişi**:
    - Eğer B işi (kısa etkileşimli iş), A işi çalışırken sisteme girerse, MLFQ, B işinin daha yüksek öncelikli bir kuyrukta olması durumunda A işini geçerek çalıştırmasına izin verir.
    - Bu, daha kısa işlerin hızla işlenmesini sağlar, bekleme sürelerini azaltır ve genel yanıt süresini iyileştirir.
3. **Karışık I/O ve CPU-Ağır İş Yükleri**:
    - A işinin (uzun süreli CPU-ağır) ve B işinin (1 ms CPU süresi gerektiren etkileşimli iş) bulunduğu bir durumu göz önünde bulundurun.
    - Bu durumda, MLFQ, etkileşimli işin yüksek öncelikte kalmasını sağlar, böylece I/O taleplerini verimli bir şekilde yönetir ve uzun süreli işi daha düşük öncelikte tutar.

### **Temel MLFQ ile İlgili Sorunlar**

- **Açlık (Starvation)**: Eğer sistemde çok fazla etkileşimli iş varsa, uzun süreli işler CPU süresi alamaz ve bu da önemli gecikmelere yol açabilir.
- **Zamanlayıcıyı Kandırma**: Bazı süreçler, zaman diliminin sonuna yaklaşırken I/O talepleri vererek zamanlayıcıyı kandırabilirler. Böylece yüksek öncelikli kuyrukta kalabilirler.
- **Davranış Değişiklikleri**: İşler zamanla davranışlarını değiştirebilir; CPU-ağır bir süreç, I/O-ağır bir süreç haline gelebilir, bu da zamanlama kararlarını karmaşık hale getirir.

### **Öncelik Artırma Mekanizması**

- **Kural 5**: Açlık sorununu aşmak için, belirli bir zaman diliminde (S) tüm işler en yüksek öncelik kuyruğuna taşınır. Bu, uzun süreli işlerin sonunda CPU süresi almasını sağlar.

### **Daha İyi Hesaplama Kuralları**

- Zamanlayıcının "kandırılmasını" önlemek için:
    - **Kural 4’ün Yeniden Yazılması**: Bir iş, bir düzeyde zaman allotmanını (time allotment) kullandığında, kaç kez CPU'yu bıraktığına bakılmaksızın önceliği düşer.

### **MLFQ'yi Ayarlama ve Diğer Sorunlar**

- **Yüksek Öncelikli Kuyruklar**: Kısa zaman dilimleri (örneğin, 10 ms) kullanmalıdır, böylece etkileşimli görevler için hızlı bir yanıt sağlanır.
- **Düşük Öncelikli Kuyruklar**: Daha uzun zaman dilimleri (örneğin, 100 ms) kullanabilirler, böylece genel verimliliği artırırken yanıt süresinden ödün vermez.

### Sonuç

Çok Seviyeli Geri Bildirim Kuyruğu (MLFQ) zamanlama algoritması, dinamik öncelik ayarlamaları ve birden fazla kuyruğun bir arada var olmasına olanak tanıyarak farklı türdeki işlerin ihtiyaçlarını etkili bir şekilde dengelemeyi başarır. Hem dönüş süresini hem de yanıt süresini optimize etmeye çalışırken, açlık ve CPU kullanım verimliliği gibi potansiyel sorunları da ele alır. Öncelik ayarlamaları ve periyodik artışlar ile MLFQ, karmaşık iş yükü ortamlarında sistem adaletini ve verimliliğini korumayı hedefler.

---

### Temel MLFQ ile İlgili Problemler

**Açlık (Starvation)**:

- Eğer sistemde "çok fazla" etkileşimli iş varsa, uzun süreli işler CPU süresi alamaz. Bu, uzun süreli işlemlerin hiç çalıştırılamamasına yol açar. Özellikle, sürekli olarak etkileşimli işler geldiğinde, daha uzun süreli işlemler arka planda kalabilir ve açlık durumuna düşebilir.

**Zamanlayıcıyı Kandırma**:

- Zaman diliminin (time slice) %99'unu kullandıktan sonra bir I/O işlemi başlatmak, işin daha yüksek bir öncelik kazanmasına neden olabilir. Bu durumda, işlem zaman dilimini tam olarak kullanmamış olur ve zamanlayıcıyı kandırarak daha fazla CPU süresi elde edebilir. Bu durum, CPU kullanımını artırırken, sistemin genel verimliliğini düşürür.

### Solaris MLFQ Uygulaması

**Zaman Paylaşımı Zamanlama Sınıfı (TS)**:

- Solaris, MLFQ'yi 60 kuyrukla uyguluyor. Her bir kuyruğun zaman dilimi, yavaş yavaş artar.
    - En yüksek öncelikli kuyruk: 20 ms
    - En düşük öncelikli kuyruk: birkaç yüz milisaniye
- Öncelikler, her yaklaşık 1 saniyede bir artırılır. Bu mekanizma, sistemdeki işlerin adil bir şekilde yönetilmesini sağlamaya yardımcı olur.

### FreeBSD Zamanlayıcısı (4.3)

- FreeBSD, kuyruksuz bir MLFQ yaklaşımı benimser. Bunun yerine, bir formül kullanarak bir işlemin önceliğini hesaplar:
    - İşlemin ne kadar CPU süresi kullandığını dikkate alır.
    - Öncelik artırma işlemi, zamanla azalır.
    - Kullanıcının önerilerine (nice) göre ayarlamalar yapar.
- Verimlilik sağlamak için kuyruklar kullanılabilir. Bu yapı, CPU süresi kullanımını optimize etmeye yardımcı olur.

### MLFQ Özeti

MLFQ'nın gelişmiş kuralları şunlardır:

1. **Kural 1**: Eğer A'nın önceliği B'den yüksekse, A çalışır (B çalışmaz).
2. **Kural 2**: Eğer A'nın önceliği B ile eşitse, A ve B dairesel olarak (RR) çalıştırılır.
3. **Kural 3**: Bir iş sisteme girdiğinde, en yüksek öncelik kuyruğuna yerleştirilir.
4. **Kural 4**: Bir iş, belirli bir seviyede zaman allotmanını kullandığında (CPU'yu kaç kez bıraktığına bakılmaksızın), önceliği düşer (daha düşük bir kuyrukta yer alır).
5. **Kural 5**: Belirli bir zaman diliminde (S) tüm işler en yüksek kuyruk seviyesine taşınır.

### MLFQ'nin Güzel Yanları

- MLFQ, bir işlemin CPU kullanımına dair önceden bilgiye ihtiyaç duymaz. Bu, sistemin dinamik bir şekilde iş yükünü yönetmesini sağlar.
- Bir program zamanla davranışını değiştirebilir; örneğin, başlangıçta CPU-ağır olan bir işlem, zamanla I/O-ağır bir iş haline gelebilir. MLFQ, bu tür değişiklikleri yönetme yeteneğine sahiptir ve böylece sistemin verimliliğini artırır.

MLFQ, etkileşimli işlemler ile uzun süreli işlemler arasında bir denge sağlayarak sistemdeki kaynakların verimli kullanılmasını hedefler. Bu sayede, hem hızlı yanıt süreleri sağlanır hem de işlerin adil bir şekilde çalıştırılması sağlanır.

---

### Orantılı Paylaşım Zamanlayıcısı (Proportional Share Scheduler)

### Temel Özellikler

- **Adil Paylaşım Zamanlayıcısı (Fair-share Scheduler)**:
    - Her işin belirli bir CPU zamanı yüzdesini almasını garanti eder.
    - Bu tür zamanlayıcılar, genellikle dönüş süresi (turnaround time) veya yanıt süresi (response time) için optimize edilmemiştir. Yani, daha çok kaynakların adil bir şekilde dağıtımını hedefler.

### Temel Kavramlar

### Biletler (Tickets)

- **Biletler**, bir işlemin alması gereken kaynak payını temsil eder.
- Bir işlem, sahip olduğu biletlerin yüzdesine göre sistem kaynağının ne kadarını alacağını belirler.

### Örnek

- **İki işlem**: A ve B
    - **İşlem A**: 75 bilet → %75 CPU süresi alır.
    - **İşlem B**: 25 bilet → %25 CPU süresi alır.

Bu durumda, toplam bilet sayısı 100 olduğundan, A işlemi toplam CPU süresinin %75’ini, B ise %25’ini alacaktır.

### Lotarya Zamanlaması (Lottery Scheduling)

- Zamanlayıcı, **kazanma biletini** rastgele seçer.
- Kazanan biletin ait olduğu işlem yüklenir ve çalıştırılır.

### Örnek

- Toplam **100 bilet** var.
    - **İşlem A**: 75 bilet (0 ~ 74 aralığında)
    - **İşlem B**: 25 bilet (75 ~ 99 aralığında)

**İşlem A** ve **İşlem B** uzun süre yarışırsa, zamanla her iki işlemin de istenen yüzdeleri alma olasılığı artar.

### Zamanlayıcı Sonuçları

- Zamanlayıcı, kazanan biletleri şu şekilde belirlemiştir: 63, 85, 70, 39, 76, 17, 29, 41, 36, 39, 10, 99, 68, 83, 63.
- Bu kazanan biletlerin sonucunda işlerin çalıştırılması şöyle olur:

| Zaman Dilimi | İşlem |
| --- | --- |
| 1 | A |
| 2 | B |
| 3 | A |
| 4 | A |
| 5 | B |
| 6 | A |
| 7 | A |
| 8 | B |
| 9 | A |
| 10 | B |
| 11 | A |

### Özet

Orantılı paylaşım zamanlayıcıları, sistem kaynaklarının adil bir şekilde dağıtılmasını sağlamak için etkili bir yöntemdir. Bilet sisteminin kullanılması, her bir işlemin CPU süresi üzerindeki payını belirlerken, lotarya zamanlamasıyla bu payın gerçek zamanlı olarak yönetilmesini sağlar. Bu tür zamanlayıcılar, daha uzun süreli yarışmalarda, işlem yüzdelerinin istikrarlı bir şekilde elde edilmesine yardımcı olur.

---

### Bilet Mekanizmaları (Ticket Mechanisms)

Bilet mekanizmaları, işlem kaynaklarının adil dağıtımını sağlamak için kullanılan esnek bir sistemdir. Bu sistemde, işlemler arasında kaynakların nasıl paylaşıldığını belirleyen biletler kullanılır.

### Bilet Para Birimi (Ticket Currency)

- **Kullanıcı, biletlerini kendi işleri arasında istediği gibi dağıtabilir.**
    - Bu, kullanıcının kendi yerel para birimi ile biletleri tahsis etmesine olanak tanır.
- **Sistem, bu yerel para birimlerini doğru küresel değere dönüştürür.**

### Örnek:

- **Toplam 200 bilet (Küresel Para Birimi)**:
    - **İşlem A**: 100 bilet alır.
    - **İşlem B**: 100 bilet alır.

**Kullanıcı A'nın işlemleri**:

- 500 (A'nın para birimi) A1'e → 50 (küresel para birimi) bilet
- 500 (A'nın para birimi) A2'ye → 50 (küresel para birimi) bilet

**Kullanıcı B'nin işlemleri**:

- 10 (B'nin para birimi) B1'e → 100 (küresel para birimi) bilet

### Bilet Transferi (Ticket Transfer)

- **Bir işlem, geçici olarak biletlerini başka bir işleme devredebilir.**
    - Bu, özellikle bir işlem başka bir işlemin daha fazla kaynağa ihtiyacı olduğunda yararlıdır.

### Bilet Enflasyonu (Ticket Inflation)

- **Bir işlem, sahip olduğu bilet sayısını geçici olarak artırabilir veya azaltabilir.**
    - Eğer herhangi bir işlem daha fazla CPU süresine ihtiyaç duyuyorsa, biletlerini artırabilir.
    - Bu, işlemin daha fazla kaynak talep etmesine olanak tanır, böylece sistemdeki diğer işlemlerle daha fazla rekabet edebilir.

### Özet

Bilet mekanizmaları, kullanıcıların ve işlemlerin kaynakları daha adil bir şekilde dağıtmasına olanak tanırken, aynı zamanda esneklik sağlar. Kullanıcılar, kendi para birimleri üzerinden biletleri yönetebilir ve transfer edebilir, bu da kaynakların dinamik ve verimli bir şekilde dağıtılmasına yardımcı olur. Ayrıca, bilet enflasyonu, bir işleme gerekli olduğunda daha fazla kaynak tahsis etme imkanı tanır, bu da sistemin performansını artırabilir.

---

### Uygulama (Implementation)

### Örnek Senaryo

Aşağıda, A, B ve C adında üç işlem bulunan bir örnek verilmektedir. İşlemler, bilet büyüklüğüne göre sıralanmış bir listede tutulur; yani en yüksek bilet sayısına sahip işlem listede önce gelir.

```
head
Job: A
Tix: 100
Job: B
Tix: 50
Job: C
Tix: 250
NULL
```

```c
1 // counter: used to track if we’ve found the winner yet
2 int counter = 0;
3
4 // winner: use some call to a random number generator to
5 // get a value, between 0 and the total # of tickets
6 int winner = getrandom(0, totaltickets);
7
8 // current: use this to walk through the list of jobs
9 node_t *current = head;
10
11 // loop until the sum of ticket values is > the winner
12 while (current) {
13 counter = counter + current->tickets;
14 if (counter > winner)
15 break; // found the winner
16 current = current->next;
17 }
18 // ’current’ is the winner: schedule it...
```

### İşlem Adımları

1. **Counter Değişkeni:** Bir kazanan bulup bulmadığımızı takip etmek için kullanılan bir sayaç.
    
    ```c
    int counter = 0;
    ```
    
2. **Kazanan Belirleme:**
    - **Random Sayı Üretme:** Toplam bilet sayısına göre 0 ile toplam bilet sayısı arasında bir değer elde etmek için rastgele bir sayı üretecek bir çağrı yapılır.
    
    ```c
    int winner = getrandom(0, totaltickets);
    ```
    
3. **Liste Üzerinde Yürüyüş:**
    - **Current Değişkeni:** İşlemler listesinde gezinmek için kullanılır.
    
    ```c
    node_t *current = head;
    ```
    
4. **Kazananı Bulma Döngüsü:**
    - **Bilet Değerlerinin Toplamını Hesaplama:** Toplam bilet değerinin kazanan değerini aşana kadar devam eden bir döngü.
    
    ```c
    while (current) {
        counter = counter + current->tickets;
        if (counter > winner)
            break; // kazanan bulundu
        current = current->next;
    }
    ```
    
5. **Kazanan İşlemi Planlama:**
    - **Kazanan:** 'current' değişkeni artık kazanan işlemi temsil eder, bu işlem planlanır.

---

### Adaletsizlik Ölçütü (Unfairness Metric)

- **U:** İlk işlemin tamamlanma süresi ile ikinci işlemin tamamlanma süresi arasındaki oran.

### Örnek:

- İki işleme bakalım; her iki işlemin de çalışma süresi 10 birim olsun:
    - **İlk İşlem:** Zaman 10'da tamamlanır.
    - **İkinci İşlem:** Zaman 20'de tamamlanır.

**Hesaplama:**

```
U = (İlk İşlem Tamamlanma Süresi) / (İkinci İşlem Tamamlanma Süresi)
U = 10 / 20 = 0.5
```

- U değeri, her iki işlem de neredeyse aynı zamanda tamamlandığında 1'e yakın olacaktır.

### Özet

Bu uygulama, kaynakların adil bir şekilde dağıtımını sağlamak için bilet sisteminin nasıl işlediğini göstermektedir. Kazananın belirlenmesi, rastgele bir sayı ile yapılır ve adaletsizlik ölçütü, sistemin ne kadar adil çalıştığını değerlendirmek için kullanılır. Uygulamanın mantığı, her işlem için tahsis edilen bilet sayısının, o işlemin CPU sürelerini nasıl etkilediğini gösterir.

---

### Lottery Adalet Çalışması (Lottery Fairness Study)

- **İki İşlem:** Her iki işlem de aynı sayıda (100) bilete sahiptir.
- **Kısa Süreli İşlemler:** İşlem uzunluğu çok kısa olduğunda, ortalama adaletsizlik oldukça şiddetli olabilir.

---

### Deterministik Yaklaşım: Stride Scheduling

### Stride Hesabı

Her bir işlemin stride'ı, **(büyük bir sayı) / (işlemin bilet sayısı)** formülüyle hesaplanır.

- **Örnek:** Büyük sayı = 10,000
    - İşlem A'nın 100 bileti var → A'nın stride'ı 100 olur.
    - İşlem B'nin 50 bileti var → B'nin stride'ı 200 olur.

### İşlem Çalıştırma

Bir işlem çalıştığında, onun için bir sayaç (pass value) artırılır.

- **Çalıştırılacak İşlem Seçimi:** En düşük pass value'ya sahip olan işlem seçilir.

**Pseudo kod uygulaması:**

```c
current = remove_min(queue); // minimum pass olan işlemi seç
schedule(current); // kaynak kullanımı için işlemi çalıştır
current->pass += current->stride; // bir sonraki pass değerini hesapla
insert(queue, current); // işlemi kuyruğa geri ekle
```

### Stride Scheduling Özellikleri

- **Per İşlem Pass Değeri:** Her işlem için pass değerinin korunması gerekmektedir.
- **Yeni Bir İşlem Girerse:** Eğer yeni bir işlem pass değeri 0 ile girerse, CPU'yu tekelleştirebilir!
- **Biletleme Sistemi Avantajı:** Biletleme sisteminin avantajı, her işlem için ayrı bir durum (state) tutma gerekliliği olmamasıdır.

---

### Pass Değerleri

**Örnek:**

- **İşlem A (stride: 100)**
    - Pass: 100, 200, 300, 400, 500
- **İşlem B (stride: 200)**
    - Pass: 200, 400, 600, 800, 1000
- **İşlem C (stride: 40)**
    - Pass: 40, 80, 120, 160, 200

**Kim Çalışıyor?**

- İşlem sırası: A, B, C, C, C, A, C, C, …

---

### Linux Tamamen Adil Zamanlama (Completely Fair Scheduling - CFS)

- **CFS:** Linux'un mevcut CPU zamanlayıcısıdır.
- **Sabit Zaman Dilimi Yoktur:** CFS, bir işlemin zaman dilimini işlemci oranına göre atar.
- **Öncelik:** Nice değeri kullanılarak önceliği kontrol etme imkanı sağlar.
- **Verimli Veri Yapısı:** Verimli arama, ekleme ve silme işlemleri için kırmızı-siyah ağaç (red-black tree) kullanır.

### Temel Özellikler

- **Sanal Çalışma Zamanı (vruntime):**
    - Bir işlemin ne kadar süre çalıştığını gösterir.
    - Her işlem için ayrı bir değişkendir.
    - Gerçek zamanla orantılı olarak artırılır.
    - CFS, bir sonraki çalıştırılacak işlem olarak en düşük vruntime'a sahip olanı seçer.
- **Zamanlama Gecikmesi (sched_latency):**
    - Tipik bir değer 48 milisaniyedir.
    - İşlemin zaman dilimi = sched_latency / (işlem sayısı)

### Örnek Senaryo

- **Basit Örnek:**
    - 4 işlem (A, B, C, D) ve ardından 2 işlem (C, D) tamamlanır.
- **Minimum Granürlük (min_granularity):**
    - Minimum zaman dilimi 6 ms'dir.
    - Çok fazla zamanın zamanlama yüküne harcanmasını önlemek için önemlidir, özellikle çok sayıda işlem çalışırken.

---

### Ağırlık (Weight) ve Nice Değeri

### Nice Değeri

- **CFS'nin Kontrolü:** CFS, işlem önceliğini kontrol etmeyi sağlar.
- **Nice Parametresi:** Integer bir değer olup -20 ile +19 arasında ayarlanabilir.
- **Ağırlık Haritası:** Nice değeri, bir ağırlığa dönüştürülür (değerin kendisi önemli değildir).

---

### Ağırlıklandırma (Niceness)

### Yeni Zaman Dilimi Formülü

Yeni zaman dilimi formülü şu şekildedir:

$$
\text{time\_slice}_k = \frac{\text{weight}_k}{\sum_{n=0}^{k-1} \text{weight}_i} \cdot \text{sched\_latency}
$$

### Basit Örnek

- **İşlem A:** Nice değeri -5, ağırlığı 3121, zaman dilimi 36 ms.
- **İşlem B:** Nice değeri 0, ağırlığı 1024, zaman dilimi 12 ms.

| İşlem | Nice Değeri | Ağırlık | Zaman Dilimi |
| --- | --- | --- | --- |
| A | -5 | 3121 | 36 ms |
| B | 0 | 1024 | 12 ms |

---

### Ağırlık ile vruntime

### vruntime Formülü

Gerçek çalışma süresini hesaplamak için vruntime formülü:

$$
\text{vruntime}_i = \text{vruntime}_i + \left(\frac{\text{weight}_0}{\text{weight}_i}\right) \cdot \text{runtime}_i
$$

### Basit Örnek

| İşlem | Nice Değeri | Ağırlık | Birikmiş Değer |
| --- | --- | --- | --- |
| A | -5 | 3121 | 1 * runtime |
| B | 0 | 1024 | 3 * runtime |

---

### Bekleme Kuyruğu Yapısı

### Kırmızı-Siyah Ağaç (Red-Black Tree)

- **Dengeli İkili Ağaç:** En kötü durumda bile ekleme işlemlerini yönetebilir.
- **Düzenleme:** Kırmızı-siyah ağacın zamanlama karmaşıklığı O(log n) olarak hesaplanır.
- **Minimum Virtual Runtime Bulma:** Minimum sanal çalışma zamanına sahip işlemi verimli bir şekilde bulur.
- **Çalışan İşlemler:** Sadece çalışan (veya çalıştırılabilir) işlemler burada tutulur.

---

### G/Ç ve Uyku İşlemleri

### G/Ç ve Uyku İşlemleri ile İlgili Yönetim

- **CPU Tekelleşmesini Önleme:** Bazı işlemlerin, uyuduktan sonra önemli ölçüde düşük vruntime'a sahip olmaları durumunda CPU'yu tekel haline getirmesini önler.
- **vruntime Ayarlama:** İşlem uyanırken, vruntime'ı ağaçta bulunan en düşük değere ayarlama.
- **Kısa Süreli Uykular:** Kısa süreli uyku sürelerine sahip olan işlemler, CPU'nun adil paylaşımını elde edemeyebilirler.

---

Bu yapılandırmalar, CFS'nin işlemler arasında adaleti sağlamasını, ağırlıklandırmayı ve uyku durumundaki işlemleri nasıl yönettiğini açıklamaktadır. Kırmızı-siyah ağaç yapısı, sistemin etkin bir şekilde işlem yönetimi gerçekleştirmesine olanak tanırken, nice değerleri, işlem önceliklerini dinamik olarak ayarlamak için kullanılır.

---

# ÖZET

# İşletim Sistemleri: Planlama ve Zamanlama Yöntemleri

## İçindekiler

1. Giriş
    - İşletim Sisteminin Temel İşlevleri
    - Zamanlama ve Planlama Nedir?
2. Çok Düzeyli Kuyruk Zamanlaması (MLFQ)
    - MLFQ'nun Temel İlkeleri
    - MLFQ'da Starvasyon
    - MLFQ Uygulamaları
    - MLFQ'daki Problemler
    - MLFQ Güzelleştirme ve Tuning
3. Orantılı Paylaşım Zamanlayıcıları
    - Temel Kavramlar
    - Bilet Mekanizmaları
    - Loteri Zamanlaması
    - Stride Zamanlaması
4. Tamamen Adil Zamanlama (CFS)
    - CFS'nin Temel İlkeleri
    - Ağırlıklandırma ve Nice Değeri
    - vruntime Hesaplama
    - Kırmızı-Siyah Ağaç Yapısı
    - G/Ç ve Uyku İşlemleri
5. Sonuç
    - Zamanlama Stratejilerinin Özetlenmesi
    - Gelecek Araştırma Alanları

---

## 1. Giriş

### İşletim Sisteminin Temel İşlevleri

İşletim sistemleri, bir bilgisayar sisteminin temel bileşenidir ve kullanıcıların donanım kaynaklarını etkili bir şekilde kullanmalarını sağlar. Temel işlevleri arasında süreç yönetimi, bellek yönetimi, dosya sistemi yönetimi ve cihaz yönetimi bulunur.

### Zamanlama ve Planlama Nedir?

Zamanlama, işletim sisteminin CPU kaynaklarını nasıl yöneteceğini belirler. Planlama ise süreçlerin nasıl sıralanacağına dair kuralları belirler. Etkili bir zamanlama algoritması, sistem performansını artırırken adaletli bir kaynak dağılımı sağlamalıdır.

---

## 2. Çok Düzeyli Kuyruk Zamanlaması (MLFQ)

### MLFQ'nun Temel İlkeleri

Çok Düzeyli Kuyruk Zamanlaması (MLFQ), işlemleri önceliklerine göre sıralayan bir zamanlama algoritmasıdır. MLFQ, işlemleri farklı öncelik seviyelerine göre birden fazla kuyruğa ayırarak çalışır. Yüksek öncelikli işlemler, düşük öncelikli işlemlerden daha fazla CPU süresi alır.

### MLFQ'da Starvasyon

MLFQ, çok fazla etkileşimli işlem olduğunda starvasyona yol açabilir. Uzun süre çalışan bir işlem, yeterince CPU süresi alamayabilir. Bu durum, adil bir kaynak dağılımını tehlikeye atar.

### MLFQ Uygulamaları

MLFQ, etkileşimli ve uzun süreli CPU işlemlerinin bir arada çalıştığı sistemlerde kullanılır. İşlemler, zaman dilimleri boyunca farklı öncelik kuyruklarına geçiş yaparlar.

### MLFQ'daki Problemler

MLFQ'nun bazı problemleri arasında starvasyon, zaman dilimi kötüye kullanma ve adalet eksikliği bulunmaktadır. Zaman dilimi kötüye kullanma, bir işlemin zaman diliminin büyük bir kısmını kullanıp ardından bir G/Ç işlemi yaparak önceliğini artırmasıdır.

### MLFQ Güzelleştirme ve Tuning

MLFQ sistemleri, belirli sürelerde tüm işlemleri en yüksek kuyruk seviyesine taşıyarak starvasyonun önüne geçebilir. Ayrıca, yüksek öncelikli kuyruklar için kısa zaman dilimleri ve düşük öncelikli kuyruklar için daha uzun zaman dilimleri atanabilir.

---

## 3. Orantılı Paylaşım Zamanlayıcıları

### Temel Kavramlar

Orantılı paylaşım zamanlayıcıları, her işin belirli bir CPU zamanını almasını garanti eder. Bu tür zamanlayıcılar, dönüş süresi veya yanıt süresi üzerinde optimize edilmemiştir.

### Bilet Mekanizmaları

Biletler, bir işlemin alacağı kaynak payını temsil eder. Örneğin, A işlemi 75 bilet alıyorsa, CPU'nun %75'ini alır.

### Loteri Zamanlaması

Zamanlayıcı, rastgele bir bilet seçerek kazanan işlemi belirler. Örneğin, 100 bilet varsa, A işlemi 75 bilet alıyorsa, 0-74 arası değerler A'ya, 75-99 arası değerler B'ye aittir.

### Stride Zamanlaması

Her işlemin bir stride değeri vardır ve bu değer, işlemin önceliğini belirler. İşlem çalıştığında, bir pass değeri artırılır ve en düşük pass değerine sahip işlem seçilir.

---

## 4. Tamamen Adil Zamanlama (CFS)

### CFS'nin Temel İlkeleri

CFS, Linux'taki mevcut CPU zamanlayıcısıdır. Sabit zaman dilimleri yerine, işlemlerin CPU zaman dilimlerini iş yüklerine göre ayarlar.

### Ağırlıklandırma ve Nice Değeri

CFS, işlem önceliğini kontrol etmeyi sağlar. Nice değeri, -20 ile +19 arasında ayarlanabilir ve bu değer, işlemin ağırlığını belirler.

### vruntime Hesaplama

vruntime, işlemin ne kadar süre çalıştığını gösterir ve fiziksel zamanla orantılı olarak artar. CFS, en düşük vruntime'a sahip işlemi çalıştırır.

### Kırmızı-Siyah Ağaç Yapısı

CFS, işlemleri verimli bir şekilde bulmak, eklemek ve silmek için kırmızı-siyah ağaç yapısını kullanır. Bu yapının zamanlama karmaşıklığı O(log n) olarak hesaplanır.

### G/Ç ve Uyku İşlemleri

CFS, kısa süreli G/Ç ve uyku işlemlerinin CPU'yu tekel haline getirmesini önler. Uyandıktan sonra işlemin vruntime'ı minimum değere ayarlanır.

---

## 5. Sonuç

### Zamanlama Stratejilerinin Özetlenmesi

Bu kitapta, MLFQ, orantılı paylaşım zamanlayıcıları ve CFS gibi farklı zamanlama stratejilerini inceledik. Her bir stratejinin avantajları ve dezavantajları bulunmaktadır.

### Gelecek Araştırma Alanları

Zamanlama algoritmalarının daha adil ve verimli hale getirilmesi için yeni yöntemlerin araştırılması önemlidir. Gelecekte, işlemci mimarileri ve sistemlerin karmaşıklığı arttıkça, daha etkili zamanlama stratejilerine ihtiyaç duyulacaktır.

[Daha Detaylı](https://www.notion.so/Daha-Detayl-12fe67fac61d8062a289e9b3187fbdf5?pvs=21)