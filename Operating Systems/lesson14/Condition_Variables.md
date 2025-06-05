# Condition Variables

### **Condition Variables (Koşul Değişkenleri)**

### **Neden Koşul Değişkenleri?**

- Bir iş parçacığının, belirli bir **koşulun doğru olup olmadığını** kontrol etmeden çalışmaya devam etmemesi gereken durumlar vardır.
- Örneğin, bir **ebeveyn iş parçacığı** bir **çocuk iş parçacığının** tamamlanmasını beklemek isteyebilir.
- Basit döngü (spin) kullanmak etkisizdir çünkü CPU kaynakları boşa harcanır. **Koşul değişkenleri** bu durumu çözmek için kullanılır.

---

### **Koşul Değişkenlerinin İşleyişi**

### **1. Tanım:**

- **Koşul Değişkeni (Condition Variable):**
    - Bir iş parçacığının, bir koşul gerçekleşene kadar beklemesine izin verir.
    - Bu süreçte, iş parçacığı **uyutulur (sleep)** ve CPU kaynaklarını harcamaz.

### **2. Temel Parçalar:**

1. **Koşul Değişkeni (`c`):**
    - İş parçacıkları üzerinde bekler.
2. **Durum Değişkeni (`m`):**
    - Koşulu temsil eder (örneğin, bir bayrak ya da durum değişkeni).
3. **Kilit (`L`):**
    - Durum değişkenini korur. Koşul kontrol edilirken yalnızca bir iş parçacığı bu durumu değiştirebilir.

### **3. İşlemler:**

1. **Bekleme (`wait`):**
    - İş parçacığı, belirtilen koşul gerçekleşene kadar uyutulur.
    - Uyandığında, durumu tekrar kontrol etmek için kilidi yeniden edinir.
2. **Sinyal (`signal`):**
    - Bir başka iş parçacığı, koşulu karşılandığını belirterek bekleyen bir iş parçacığını uyandırır.

---

### **Örnek: Bir Ebeveyn İş Parçacığı Çocuğunu Bekliyor**

### **İdeal Çıktı:**

```
parent: begin
child
parent: end
```

### **Sorun: Spin-Wait Yaklaşımı**

- **Kod:**

```c
volatile int done = 0;

void *child(void *arg) {
    printf("child\n");
    done = 1; // Koşulu değiştir
    return NULL;
}

int main(int argc, char *argv[]) {
    printf("parent: begin\n");
    pthread_t c;
    pthread_create(&c, NULL, child, NULL); // Çocuk iş parçacığını oluştur
    while (done == 0); // Spin-wait (çok verimsiz)
    printf("parent: end\n");
    return 0;
}
```

- **Sorun:**
    - **Spin-wait** sırasında CPU kaynakları boşa harcanır.
    - Bu yaklaşım büyük ölçekli sistemlerde etkisizdir.

---

### **Koşul Değişkenleri ile Çözüm**

### **Koşul Değişkenleri Kullanımı:**

1. **İlan ve Başlatma:**
    
    ```c
    pthread_cond_t cond = PTHREAD_COND_INITIALIZER;  // Koşul değişkeni
    pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; // Kilit
    ```
    
2. **Çocuk İş Parçacığı:**
    - Koşulu günceller ve sinyal gönderir:
    
    ```c
    void *child(void *arg) {
        printf("child\n");
        pthread_mutex_lock(&lock);  // Kilidi edin
        done = 1;                   // Koşulu değiştir
        pthread_cond_signal(&cond); // Sinyal gönder
        pthread_mutex_unlock(&lock); // Kilidi bırak
        return NULL;
    }
    ```
    
3. **Ebeveyn İş Parçacığı:**
    - Koşulu kontrol eder ve bekler:
    
    ```c
    int main(int argc, char *argv[]) {
        printf("parent: begin\n");
        pthread_t c;
        pthread_create(&c, NULL, child, NULL); // Çocuk iş parçacığını oluştur
    
        pthread_mutex_lock(&lock);  // Kilidi edin
        while (done == 0) {         // Koşulu kontrol et
            pthread_cond_wait(&cond, &lock); // Koşulu bekle
        }
        pthread_mutex_unlock(&lock); // Kilidi bırak
    
        printf("parent: end\n");
        return 0;
    }
    ```
    

### **Koşul Değişkenlerinin Akışı:**

1. Ebeveyn iş parçacığı kilidi edinir ve `done` değişkenini kontrol eder.
2. Eğer `done == 0`, ebeveyn iş parçacığı `pthread_cond_wait` ile uyutulur.
3. Çocuk iş parçacığı tamamlandığında, `pthread_cond_signal` ile ebeveyni uyandırır.
4. Ebeveyn uyandığında, kilidi yeniden edinir ve koşulu tekrar kontrol eder.

---

### **Koşul Değişkenleri ile İlgili Önemli Detaylar**

1. **`pthread_cond_wait`:**
    - İş parçacığını uyutur ve kilidi serbest bırakır.
    - Uyandığında, kilidi tekrar edinir.
2. **`pthread_cond_signal`:**
    - Bekleyen bir iş parçacığını uyandırır.
    - Eğer hiç bekleyen iş parçacığı yoksa, hiçbir şey yapmaz.
3. **Kilit Kullanımı:**
    - Durum değişkenleri genellikle kilitlerle korunur, çünkü koşul kontrol edilirken başka iş parçacıkları bu durumu değiştirebilir.

---

### **Koşul Değişkenlerinin Avantajları**

1. **Kaynak Tasarrufu:**
    - Spin-wait sırasında işlemci kaynakları harcanmaz.
    - Uyuyan iş parçacıklarına öncelik verilir.
2. **Adillik:**
    - Uyutulan iş parçacıkları sırasıyla uyandırılır, böylece starvation önlenir.
3. **Kolay Kullanım:**
    - POSIX API'leri, koşul değişkenlerini kolay bir şekilde kullanmayı sağlar.

---

### **Sonuç ve Özet**

### **Koşul Değişkenleri ile Bekleme ve Sinyal Gönderme:**

1. **Koşulu Bekleme (`pthread_cond_wait`):**
    - İş parçacığı, belirli bir koşul gerçekleşene kadar uyutulur.
    - Uyandığında durumu tekrar kontrol eder.
2. **Sinyal Gönderme (`pthread_cond_signal`):**
    - Bekleyen bir iş parçacığını uyandırır.

### **Temel Yapılar:**

- Koşul değişkenleri (`cond`), durum değişkenleri (`state`), ve kilitler (`lock`) bir arada kullanılır.

### **Örnek Durumlar:**

- Bir iş parçacığının başka bir iş parçacığının tamamlanmasını beklemesi (**join**).
- Üretici/tüketici problemleri gibi senkronizasyon gerektiren durumlar.

---

### **Parent Waiting for Child: Condition Variables Kullanımı**

Bu örnek, bir ebeveyn iş parçacığının bir çocuk iş parçacığının tamamlanmasını beklediği bir senaryoyu ele alır. Koşul değişkenleri bu tür bir senkronizasyon problemini çözmek için kullanılır. Şimdi adım adım bu senaryoyu ve uygulamasını açıklayalım.

---

### **Temel Yapı ve İşleyiş**

### **Ebeveyn (Parent) İş Parçacığı:**

1. **Çocuk iş parçacığını oluşturur** ve kendi çalışmasına devam eder.
2. `thr_join()` fonksiyonunu çağırarak çocuğun tamamlanmasını bekler.
    - **Kilit edinilir**.
    - **`done` değişkeni kontrol edilir** (çocuğun tamamlanıp tamamlanmadığını belirler).
    - Eğer çocuk tamamlanmamışsa:
        - İş parçacığı uyutulur (`pthread_cond_wait` ile).
        - Kilit serbest bırakılır.
    - Çocuk tamamlandığında, iş parçacığı uyandırılır ve kilit tekrar edinilir.

### **Çocuk (Child) İş Parçacığı:**

1. Bir mesaj basar.
2. `thr_exit()` fonksiyonunu çağırarak ebeveyni uyandırır.
    - **Kilit edinilir**.
    - `done` değişkeni güncellenir.
    - `pthread_cond_signal` ile ebeveyn uyandırılır.

---

### **Kod Uygulaması**

### **Veri Yapıları:**

```c
int done = 0;                            // Durum değişkeni
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER; // Kilit
pthread_cond_t c = PTHREAD_COND_INITIALIZER;   // Koşul değişkeni
```

### **Çocuk İş Parçacığı Fonksiyonu (`thr_exit`):**

```c
void thr_exit() {
    pthread_mutex_lock(&m);       // Kilidi edin
    done = 1;                     // Durum değişkenini güncelle
    pthread_cond_signal(&c);      // Bekleyen iş parçacığını uyandır
    pthread_mutex_unlock(&m);     // Kilidi serbest bırak
}
```

### **Ebeveyn Bekleme Fonksiyonu (`thr_join`):**

```c
void thr_join() {
    pthread_mutex_lock(&m);       // Kilidi edin
    while (done == 0) {           // Koşulu kontrol et
        pthread_cond_wait(&c, &m); // Koşul gerçekleşene kadar bekle
    }
    pthread_mutex_unlock(&m);     // Kilidi serbest bırak
}
```

### **Ana Program (`main`):**

```c
int main(int argc, char *argv[]) {
    printf("parent: begin\n");
    pthread_t p;
    pthread_create(&p, NULL, child, NULL); // Çocuk iş parçacığını oluştur
    thr_join();                           // Çocuğun tamamlanmasını bekle
    printf("parent: end\n");
    return 0;
}
```

---

### **Durum Değişkeni `done`'ın Önemi**

### **Senaryo:**

- Eğer `done` değişkeni kullanılmazsa, şu sorun ortaya çıkabilir:
    1. Çocuk iş parçacığı hemen tamamlanır ve `pthread_cond_signal` çağırır.
    2. Ancak ebeveyn iş parçacığı henüz uyutulmamış olabilir.
    3. Ebeveyn iş parçacığı, `pthread_cond_wait` çağrıldığında sonsuza kadar uyuyabilir (çünkü kimse onu uyandırmaz).

### **`done` ile Bu Sorunun Çözümü:**

- `done` bir **durum kontrolü** sağlar.
- Eğer çocuk iş parçacığı erken tamamlanırsa, `done` güncellenir ve ebeveyn `pthread_cond_wait` yerine doğrudan çalışmasına devam eder.

---

### **Yanlış Uygulama ve Yarış Durumu (Race Condition)**

### **Sorun:**

- Ebeveyn iş parçacığı `thr_join` çağırır ve `done == 0` durumunu kontrol eder.
- Ancak tam bu sırada çocuk iş parçacığı `done = 1` yapar ve `pthread_cond_signal` çağırır.
- Ebeveyn `pthread_cond_wait`'e geçtiğinde kimse onu uyandırmaz ve sonsuza kadar uyur.

### **Bu Sorunun Çözümü:**

- Durum değişkeni `done` kullanılmalı ve doğru sırada kontrol edilmeli.

---

### **Üretici/Tüketici Problemi (Bounded Buffer)**

### **Tanım:**

- **Üretici:** Veri üretir ve bir tampon (buffer) içine yerleştirir.
- **Tüketici:** Tampondan veri çeker ve işler.

### **Senaryo:**

- Çok iş parçacıklı bir web sunucusunda:
    - Üretici, HTTP isteklerini bir çalışma kuyruğuna koyar.
    - Tüketici iş parçacıkları bu istekleri sırayla alır ve işler.

### **Tamponun Özellikleri:**

- **Sınırlı bir tampon (Bounded Buffer):**
    - Tampon doluysa üretici bekler.
    - Tampon boşsa tüketici bekler.
- **Senkrone erişim:** Tampon, birden fazla iş parçacığı tarafından paylaşılır ve bu nedenle senkronizasyon gereklidir.

---

### **Bounded Buffer Kod Taslağı**

### **Veri Yapıları:**

```c
int buffer[BUFFER_SIZE];
int count = 0; // Tampondaki eleman sayısı
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t not_full = PTHREAD_COND_INITIALIZER;
```

### **Üretici:**

```c
void produce(int item) {
    pthread_mutex_lock(&m);
    while (count == BUFFER_SIZE) {
        pthread_cond_wait(&not_full, &m); // Tampon doluysa bekle
    }
    buffer[count++] = item; // Ürünü tampona koy
    pthread_cond_signal(&not_empty); // Tüketiciyi uyandır
    pthread_mutex_unlock(&m);
}
```

### **Tüketici:**

```c
int consume() {
    pthread_mutex_lock(&m);
    while (count == 0) {
        pthread_cond_wait(&not_empty, &m); // Tampon boşsa bekle
    }
    int item = buffer[--count]; // Tampondan eleman al
    pthread_cond_signal(&not_full); // Üreticiyi uyandır
    pthread_mutex_unlock(&m);
    return item;
}
```

---

### **Özet**

1. **Koşul Değişkenleri:**
    - Bir iş parçacığının belirli bir koşul gerçekleşene kadar beklemesini sağlar.
    - `done` gibi durum değişkenleri yarış durumlarını önlemek için önemlidir.
2. **Bounded Buffer:**
    - Üretici/tüketici problemi koşul değişkenleri ve kilitler kullanılarak çözülebilir.
    - Üretici/tüketici, tamponun dolu/boş olma durumuna göre çalışır.

---

### **Producer/Consumer Problemi (Version 1)**

Bu problemde, bir üretici (producer) ve bir tüketici (consumer), paylaşılan bir tampon üzerinde senkronize bir şekilde çalışır. İlk versiyon, tek bir üretici ve tek bir tüketici için tasarlanmıştır.

---

### **Version 1: Basit Üretici/Tüketici**

### **Veri Yapıları:**

```c
int buffer;        // Paylaşılan tampon
int count = 0;     // Tampon durumu: 0 -> boş, 1 -> dolu
```

### **`put()` Fonksiyonu:**

```c
void put(int value) {
    assert(count == 0); // Tampon boş olmalı
    count = 1;          // Tampon dolu olarak işaretle
    buffer = value;      // Tampona veri ekle
}
```

### **`get()` Fonksiyonu:**

```c
int get() {
    assert(count == 1); // Tampon dolu olmalı
    count = 0;          // Tamponu boş olarak işaretle
    return buffer;      // Tampondan veri al
}
```

### **İşleyiş:**

1. Üretici, sadece tampon boşken veri ekler (`count == 0`).
2. Tüketici, sadece tampon doluyken veri çeker (`count == 1`).

---

### **Version 1: Üretici ve Tüketici İş Parçacıkları**

### **Üretici İş Parçacığı:**

```c
void *producer(void *arg) {
    int loops = (int)arg; // Döngü sayısını al
    for (int i = 0; i < loops; i++) {
        put(i); // Tampona veri ekle
    }
    return NULL;
}
```

### **Tüketici İş Parçacığı:**

```c
void *consumer(void *arg) {
    while (1) {
        int tmp = get();         // Tampondan veri al
        printf("%d\n", tmp);     // Veriyi yazdır
    }
    return NULL;
}
```

---

### **Version 2: Koşul Değişkenleri ile Tek Üretici ve Tüketici**

Bu versiyonda, **koşul değişkenleri** kullanılarak üretici ve tüketici senkronize edilir. Hem üretici hem de tüketici, tamponun dolu ya da boş olma durumuna göre bekler.

### **Veri Yapıları:**

```c
int buffer;                 // Paylaşılan tampon
int count = 0;              // Tampon durumu
pthread_cond_t cond;        // Koşul değişkeni
pthread_mutex_t mutex;      // Kilit
```

---

### **Üretici Fonksiyonu:**

```c
void *producer(void *arg) {
    int loops = (int)arg; // Döngü sayısını al
    for (int i = 0; i < loops; i++) {
        pthread_mutex_lock(&mutex);          // Kilidi edin
        while (count == 1) {                 // Eğer tampon doluysa bekle
            pthread_cond_wait(&cond, &mutex);
        }
        put(i);                              // Tampona veri ekle
        pthread_cond_signal(&cond);          // Tüketiciyi uyandır
        pthread_mutex_unlock(&mutex);        // Kilidi bırak
    }
    return NULL;
}
```

---

### **Tüketici Fonksiyonu:**

```c
void *consumer(void *arg) {
    for (int i = 0; i < *(int *)arg; i++) {
        pthread_mutex_lock(&mutex);          // Kilidi edin
        while (count == 0) {                 // Eğer tampon boşsa bekle
            pthread_cond_wait(&cond, &mutex);
        }
        int tmp = get();                     // Tampondan veri al
        pthread_cond_signal(&cond);          // Üreticiyi uyandır
        pthread_mutex_unlock(&mutex);        // Kilidi bırak
        printf("%d\n", tmp);                 // Veriyi yazdır
    }
    return NULL;
}
```

---

### **İşleyiş Açıklaması:**

1. **Üretici:**
    - Kilidi edinir.
    - Eğer tampon doluysa (`count == 1`), koşul değişkeniyle beklemeye geçer.
    - Tampon boşaldığında, veriyi ekler ve tüketiciyi uyandırır.
2. **Tüketici:**
    - Kilidi edinir.
    - Eğer tampon boşsa (`count == 0`), koşul değişkeniyle beklemeye geçer.
    - Tampon dolduğunda, veriyi alır ve üreticiyi uyandırır.

---

### **Version 3: Birden Fazla Üretici ve Tüketici**

### **Sorun:**

- Birden fazla üretici ve tüketici olduğu durumlarda, tek bir koşul değişkeni yetersizdir.
- Üreticiler ve tüketiciler arasında yarış durumu ortaya çıkabilir.

### **Çözüm: İki Koşul Değişkeni**

- **`not_full`:** Tampon dolu olduğunda üreticiler için bir bekleme kuyruğu.
- **`not_empty`:** Tampon boş olduğunda tüketiciler için bir bekleme kuyruğu.

### **Veri Yapıları:**

```c
int buffer[BUFFER_SIZE];    // Tampon
int count = 0;              // Tampondaki öğe sayısı
pthread_cond_t not_full;    // Tampon doluyken üreticiler bekler
pthread_cond_t not_empty;   // Tampon boşken tüketiciler bekler
pthread_mutex_t mutex;      // Kilit
```

---

### **Üretici Fonksiyonu:**

```c
void *producer(void *arg) {
    int loops = (int)arg;
    for (int i = 0; i < loops; i++) {
        pthread_mutex_lock(&mutex);
        while (count == BUFFER_SIZE) {       // Tampon doluysa bekle
            pthread_cond_wait(&not_full, &mutex);
        }
        buffer[count++] = i;                // Tampona veri ekle
        pthread_cond_signal(&not_empty);    // Tüketiciyi uyandır
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
```

---

### **Tüketici Fonksiyonu:**

```c
void *consumer(void *arg) {
    for (int i = 0; i < *(int *)arg; i++) {
        pthread_mutex_lock(&mutex);
        while (count == 0) {                 // Tampon boşsa bekle
            pthread_cond_wait(&not_empty, &mutex);
        }
        int tmp = buffer[--count];           // Tampondan veri al
        pthread_cond_signal(&not_full);      // Üreticiyi uyandır
        pthread_mutex_unlock(&mutex);
        printf("%d\n", tmp);
    }
    return NULL;
}
```

---

### **Sonuç ve Özet**

1. **Version 1:**
    - Tek üretici ve tek tüketici için basit bir çözüm.
    - Koşul değişkenleri olmadan, spin-wait ile çalışır.
2. **Version 2:**
    - Koşul değişkenleri kullanarak senkronizasyon sağlar.
    - Daha verimli ve kaynak dostudur.
3. **Version 3:**
    - Birden fazla üretici ve tüketici senaryosu için uygundur.
    - İki koşul değişkeni (`not_full` ve `not_empty`) ile daha iyi kontrol sağlar.

---

### **Producer/Consumer Problemi: Broken Solution (Version 1)**

Bu problemde, tek bir koşul değişkeni kullanılarak üretici ve tüketici iş parçacıkları arasında senkronizasyon sağlanmaya çalışılır. Ancak **yarış durumları (race conditions)** ve **uyumsuz tampon durumları** nedeniyle hatalar meydana gelir.

---

### **Sorunun Kökeni: Mesa ve Hoare Semantik Farkı**

### **Mesa Semantics:**

- **Woken thread (uyandırılan iş parçacığı):**
    - Uyandırıldığında **garanti verilmez** ki tampon hâlâ beklenen durumdadır.
    - Uyandırılan iş parçacığı çalışmadan önce başka bir iş parçacığı tampon durumunu değiştirebilir.

### **Hoare Semantics:**

- Uyandırılan iş parçacığı **hemen çalışır**.
- Bu semantik, daha güçlü bir garanti sağlar ancak modern sistemlerde uygulanması karmaşıktır.
- Mesa semantics, çoğu sistemde kullanılır çünkü daha esnektir.

---

### **Koşul Değişkenlerinde `while` Kullanımı**

Bir koşul değişkeni ile bekleyen iş parçacıkları, uyandırıldıklarında **tampon durumunu tekrar kontrol etmelidir**.

### **Neden `while` Kullanılır?**

- Uyandırılan iş parçacığı, tampon durumunu tekrar kontrol eder.
- Eğer durum hâlâ beklenen koşula uygun değilse (örneğin tampon dolu ya da boş), iş parçacığı yeniden uyutulur.

---

### **Kod İncelemesi: Single CV ile Çalışma**

### **Üretici:**

```c
void *producer(void *arg) {
    int loops = (int)arg;
    for (int i = 0; i < loops; i++) {
        pthread_mutex_lock(&mutex);          // p1: Kilidi edin
        while (count == 1) {                 // p2: Tampon doluysa bekle
            pthread_cond_wait(&cond, &mutex); // p3
        }
        put(i);                              // p4: Tampona veri ekle
        pthread_cond_signal(&cond);          // p5: Tüketiciyi uyandır
        pthread_mutex_unlock(&mutex);        // p6: Kilidi bırak
    }
    return NULL;
}
```

### **Tüketici:**

```c
void *consumer(void *arg) {
    for (int i = 0; i < *(int *)arg; i++) {
        pthread_mutex_lock(&mutex);          // c1: Kilidi edin
        while (count == 0) {                 // c2: Tampon boşsa bekle
            pthread_cond_wait(&cond, &mutex); // c3
        }
        int tmp = get();                     // c4: Tampondan veri al
        pthread_cond_signal(&cond);          // c5: Üreticiyi uyandır
        pthread_mutex_unlock(&mutex);        // c6: Kilidi bırak
        printf("%d\n", tmp);
    }
    return NULL;
}
```

---

### **Sorun: Yarış Durumu**

### **Sorunun Açıklaması:**

1. Üretici, tüketiciyi uyandırır (`pthread_cond_signal`).
2. Ancak, uyandırılan tüketici iş parçacığı çalışmadan önce başka bir tüketici iş parçacığı tamponu değiştirebilir.
3. Uyandırılan iş parçacığı çalıştığında tampon beklediği durumda olmayabilir.

---

### **Çözüm: İki Koşul Değişkeni**

### **Yapı:**

- **Koşul Değişkenleri:**
    - **`empty`:** Üreticiler bekler, tüketiciler uyandırır.
    - **`fill`:** Tüketiciler bekler, üreticiler uyandırır.
- Bu, tamponun dolu ya da boş olma durumuna göre iş parçacıklarının doğru şekilde beklemesini ve uyandırılmasını sağlar.

---

### **Kod İncelemesi: İki Koşul Değişkeni ile Çözüm**

### **Veri Yapıları:**

```c
pthread_cond_t empty = PTHREAD_COND_INITIALIZER; // Üreticiler için koşul
pthread_cond_t fill = PTHREAD_COND_INITIALIZER;  // Tüketiciler için koşul
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Kilit
int buffer;
int count = 0;
```

### **Üretici:**

```c
void *producer(void *arg) {
    int loops = (int)arg;
    for (int i = 0; i < loops; i++) {
        pthread_mutex_lock(&mutex);              // Kilidi edin
        while (count == 1) {                     // Tampon doluysa bekle
            pthread_cond_wait(&empty, &mutex);   // Üreticiler boş olmasını bekler
        }
        put(i);                                  // Tampona veri ekle
        pthread_cond_signal(&fill);              // Tüketiciyi uyandır
        pthread_mutex_unlock(&mutex);            // Kilidi bırak
    }
    return NULL;
}
```

### **Tüketici:**

```c
void *consumer(void *arg) {
    for (int i = 0; i < *(int *)arg; i++) {
        pthread_mutex_lock(&mutex);              // Kilidi edin
        while (count == 0) {                     // Tampon boşsa bekle
            pthread_cond_wait(&fill, &mutex);    // Tüketiciler dolmasını bekler
        }
        int tmp = get();                         // Tampondan veri al
        pthread_cond_signal(&empty);             // Üreticiyi uyandır
        pthread_mutex_unlock(&mutex);            // Kilidi bırak
        printf("%d\n", tmp);
    }
    return NULL;
}
```

---

### **Çözümün İşleyişi**

1. **Üretici:**
    - Eğer tampon doluysa, `empty` koşul değişkeni ile bekler.
    - Tüketici bir öğe aldığında, üreticiyi uyandırır (`pthread_cond_signal(&empty)`).
2. **Tüketici:**
    - Eğer tampon boşsa, `fill` koşul değişkeni ile bekler.
    - Üretici bir öğe eklediğinde, tüketiciyi uyandırır (`pthread_cond_signal(&fill)`).
3. **Yarış Durumu Engellenir:**
    - Uyandırılan iş parçacıkları tampon durumunu tekrar kontrol eder (`while` döngüsü).
    - İki koşul değişkeni, iş parçacıklarının doğru senkronize olmasını sağlar.

---

### **Sonuç ve Özet**

1. **Mesa Semantics:** Uyandırılan iş parçacığı çalışmadan önce tampon durumu değişebilir. Bu yüzden, tampon durumunu kontrol etmek için `while` döngüsü kullanılmalıdır.
2. **Single CV ve Yarış Durumu:**
    - Tek bir koşul değişkeniyle, uyandırılan iş parçacıkları arasında yarış durumu meydana gelebilir.
3. **İki Koşul Değişkeni Çözümü:**
    - `empty`: Üreticiler için.
    - `fill`: Tüketiciler için.
    - Bu, hem üreticilerin hem de tüketicilerin tampon durumuna göre doğru şekilde beklemesini ve uyandırılmasını sağlar.

---

### **The Final Producer/Consumer Solution**

Bu çözüm, **daha fazla eşzamanlılık (concurrency)** ve **verimlilik** sağlamak için birden fazla tampon yuvası (buffer slots) ekler. Artık aynı anda birden fazla üretici veya tüketici çalışabilir ve bağlam değiştirme (context switching) maliyetleri azalır.

---

### **Tampon Yapısı ve İşlevler**

### **Veri Yapıları:**

```c
int buffer[MAX];   // Sabit boyutlu tampon
int fill = 0;      // Tampona veri eklemek için kullanılan indeks
int use = 0;       // Tampondan veri almak için kullanılan indeks
int count = 0;     // Tampondaki dolu öğe sayısı
```

---

### **`put()` Fonksiyonu:**

```c
void put(int value) {
    buffer[fill] = value;              // Veriyi tampona ekle
    fill = (fill + 1) % MAX;           // `fill` indeksini döngüsel şekilde güncelle
    count++;                           // Tampondaki öğe sayısını artır
}
```

### **`get()` Fonksiyonu:**

```c
int get() {
    int tmp = buffer[use];             // Tampondan veriyi al
    use = (use + 1) % MAX;             // `use` indeksini döngüsel şekilde güncelle
    count--;                           // Tampondaki öğe sayısını azalt
    return tmp;                        // Veriyi döndür
}
```

---

### **Üretici ve Tüketici İş Parçacıkları**

### **Üretici:**

```c
void *producer(void *arg) {
    int loops = (int)arg;
    for (int i = 0; i < loops; i++) {
        pthread_mutex_lock(&mutex);              // Kilidi edin
        while (count == MAX) {                   // Eğer tampon doluysa bekle
            pthread_cond_wait(&empty, &mutex);   // `empty` koşul değişkeni ile bekle
        }
        put(i);                                  // Tampona veri ekle
        pthread_cond_signal(&fill);              // Tüketiciyi uyandır
        pthread_mutex_unlock(&mutex);            // Kilidi serbest bırak
    }
    return NULL;
}
```

### **Tüketici:**

```c
void *consumer(void *arg) {
    for (int i = 0; i < *(int *)arg; i++) {
        pthread_mutex_lock(&mutex);              // Kilidi edin
        while (count == 0) {                     // Eğer tampon boşsa bekle
            pthread_cond_wait(&fill, &mutex);    // `fill` koşul değişkeni ile bekle
        }
        int tmp = get();                         // Tampondan veri al
        pthread_cond_signal(&empty);             // Üreticiyi uyandır
        pthread_mutex_unlock(&mutex);            // Kilidi serbest bırak
        printf("%d\n", tmp);                     // Veriyi yazdır
    }
    return NULL;
}
```

---

### **Çalışma Mantığı**

1. **Üretici:**
    - Tampon doluysa (`count == MAX`), `empty` koşul değişkeni ile bekler.
    - Tüketici bir öğe aldığında, üretici çalışmaya devam eder.
2. **Tüketici:**
    - Tampon boşsa (`count == 0`), `fill` koşul değişkeni ile bekler.
    - Üretici bir öğe eklediğinde, tüketici çalışmaya devam eder.

---

### **Eşzamanlılık ve Verimlilik**

1. **Daha Fazla Tampon Yuvası:**
    - Birden fazla öğe depolamak mümkün olduğu için üretici ve tüketici arasında daha az bekleme süresi olur.
2. **Döngüsel İndeksleme:**
    - `fill` ve `use` indeksleri döngüsel şekilde (`% MAX`) güncellenir. Bu, tamponun baştan sona kullanılmasını sağlar.
3. **Koşul Değişkenleri:**
    - Üreticiler ve tüketiciler, yalnızca tampon durumu izin verdiğinde çalışır. Bu, işlemci kaynaklarının verimli kullanılmasını sağlar.

---

### **Covering Conditions (Dinamik Koşullar)**

### **Sorun:**

Bir iş parçacığı belirli bir kaynağı (örneğin, bellek) tahsis etmek için beklerken başka bir iş parçacığı daha küçük bir kaynak tahsisi için bekliyor olabilir. Örneğin:

- **Thread TaT_aTa​:** 100 birim bellek tahsis etmeyi bekliyor.
- **Thread TbT_bTb​:** 10 birim bellek tahsis etmeyi bekliyor.
- **Thread TcT_cTc​:** 50 birim bellek serbest bırakıyor.
- Bu durumda, hangi iş parçacığının uyandırılması gerektiği bir sorun teşkil eder.

---

### **Çözüm: Broadcast Kullanımı**

1. **`pthread_cond_signal`:**
    - Bekleyen yalnızca bir iş parçacığını uyandırır.
    - Ancak bu iş parçacığı yanlış koşulda olabilir ve tekrar uyuyabilir.
2. **`pthread_cond_broadcast`:**
    - Tüm bekleyen iş parçacıklarını uyandırır.
    - Her iş parçacığı kendi koşulunu kontrol eder ve koşul sağlanmadıysa tekrar uyur.

### **Kod:**

```c
void allocate(int size) {
    pthread_mutex_lock(&m);
    while (bytesLeft < size) {              // Yeterli bellek yoksa bekle
        pthread_cond_wait(&c, &m);
    }
    bytesLeft -= size;                      // Belleği tahsis et
    pthread_mutex_unlock(&m);
}

void free(void *ptr, int size) {
    pthread_mutex_lock(&m);
    bytesLeft += size;                      // Belleği serbest bırak
    pthread_cond_broadcast(&c);             // Tüm bekleyen iş parçacıklarını uyandır
    pthread_mutex_unlock(&m);
}
```

### **Avantaj ve Dezavantajlar:**

- **Avantaj:** Tüm bekleyen iş parçacıkları koşulu kontrol eder ve uygun olan çalışmaya devam eder.
- **Dezavantaj:** Gereksiz iş parçacıkları da uyandırılır, bu da performans maliyetine neden olabilir.

---

### **Sonuç ve Özet**

1. **Tampon Yuvası Sayısını Artırma:**
    - Daha fazla eşzamanlılık ve verimlilik sağlar.
    - Döngüsel indeksleme tampon kullanımını optimize eder.
2. **Dinamik Koşullar:**
    - `pthread_cond_broadcast`, bekleyen tüm iş parçacıklarını uyandırır, ancak maliyeti yüksektir.
3. **Son Çözüm:**
    - Koşul değişkenlerini ve döngüsel tampon yapısını birleştirerek hem verimlilik hem de eşzamanlılık artırılır.

---