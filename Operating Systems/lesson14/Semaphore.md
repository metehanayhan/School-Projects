# Semaphore

### **Semaphore: Temel Tanım**

### **Semafor Nedir?**

- Bir **tamsayı (integer)** değeri olan bir senkronizasyon nesnesidir.
- İş parçacıklarının (threads) ortak kaynaklara erişimini senkronize etmek ve kontrol etmek için kullanılır.

### **İki Temel İşlev:**

1. **`sem_wait`:**
    - Semaforun değerini **bir azaltır**.
    - Eğer semaforun değeri sıfır veya negatifse, iş parçacığı beklemeye alınır (uyutulur).
2. **`sem_post`:**
    - Semaforun değerini **bir artırır**.
    - Eğer bekleyen bir iş parçacığı varsa, bu iş parçacığı uyandırılır.

### **Başlatma:**

- Semafor, `sem_init` ile başlatılır.
- Örneğin:
    
    ```c
    sem_t s;
    sem_init(&s, 0, 1); // 1 başlangıç değeriyle semaforu başlat
    ```
    

---

### **Semaphore Kullanımı**

### **`sem_wait`:**

- Semafor değeri pozitifse, iş parçacığı hemen devam eder.
- Semafor değeri sıfır veya negatifse, iş parçacığı uyutulur ve semaforun serbest bırakılmasını bekler.

```c
int sem_wait(sem_t *s) {
    // Semaforun değerini bir azalt
    // Eğer değer negatifse, iş parçacığını uyut
}
```

### **`sem_post`:**

- Semaforun değerini bir artırır.
- Eğer bekleyen bir iş parçacığı varsa, onu uyandırır.

```c
int sem_post(sem_t *s) {
    // Semaforun değerini bir artır
    // Eğer bekleyen iş parçacığı varsa, onu uyandır
}
```

---

### **Binary Semaphore (İkil Semafor) ile Kilitler**

- İkil semaforlar, **kilitler (locks)** gibi çalışır.
- Semaforun başlangıç değeri **1** olarak ayarlanır.
- **`sem_wait`**: Kritik bölgeye giriş.
- **`sem_post`**: Kritik bölgeden çıkış.

### **Kod:**

```c
sem_t m;
sem_init(&m, 0, 1); // Semaforu 1 ile başlat

void critical_section() {
    sem_wait(&m); // Kilidi edin
    // Kritik bölge
    sem_post(&m); // Kilidi serbest bırak
}
```

---

### **Semaforlar ve Koşul Değişkenleri**

- Semaforlar, koşul değişkenleri gibi kullanılabilir.
- Semaforun başlangıç değeri **0** olarak ayarlanır.
- İş parçacıkları, semaforun sinyali (`sem_post`) verilene kadar bekler.

### **Ebeveyn ve Çocuk Senaryosu:**

```c
sem_t s;

void *child(void *arg) {
    printf("child\n");
    sem_post(&s); // Sinyal gönder: Çocuk tamamlandı
    return NULL;
}

int main() {
    sem_init(&s, 0, 0); // Başlangıç değeri 0
    printf("parent: begin\n");
    pthread_t c;
    pthread_create(&c, NULL, child, NULL); // Çocuk iş parçacığını oluştur
    sem_wait(&s); // Çocuk iş parçacığını bekle
    printf("parent: end\n");
    return 0;
}
```

**Çıktı:**

```
parent: begin
child
parent: end
```

---

### **Producer/Consumer Problemi: İlk Çözüm**

### **Temel Fikir:**

- **Üretici (Producer):**
    - Tampon boş olduğunda veri ekler.
- **Tüketici (Consumer):**
    - Tampon dolu olduğunda veri alır.

### **Kod:**

```c
int buffer[MAX];
int fill = 0;
int use = 0;

void put(int value) {
    buffer[fill] = value;         // Veriyi tampona koy
    fill = (fill + 1) % MAX;      // Sonraki konumu ayarla
}

int get() {
    int tmp = buffer[use];        // Tampondan veri al
    use = (use + 1) % MAX;        // Sonraki konumu ayarla
    return tmp;
}
```

---

### **Semafor ile Çözüm**

### **Veri Yapıları:**

```c
sem_t empty;  // Boş tampon sayısı
sem_t full;   // Dolu tampon sayısı
sem_t mutex;  // Kritik bölgeyi korumak için semafor
```

### **Üretici:**

```c
void *producer(void *arg) {
    int loops = *(int *)arg;
    for (int i = 0; i < loops; i++) {
        sem_wait(&empty);  // Boş tampon varsa devam et
        sem_wait(&mutex);  // Kritik bölgeye giriş
        put(i);            // Veriyi tampona koy
        sem_post(&mutex);  // Kritik bölgeden çıkış
        sem_post(&full);   // Tüketiciyi uyandır
    }
    return NULL;
}
```

### **Tüketici:**

```c
void *consumer(void *arg) {
    for (int i = 0; i < *(int *)arg; i++) {
        sem_wait(&full);   // Dolu tampon varsa devam et
        sem_wait(&mutex);  // Kritik bölgeye giriş
        int tmp = get();   // Tampondan veri al
        sem_post(&mutex);  // Kritik bölgeden çıkış
        sem_post(&empty);  // Üreticiyi uyandır
        printf("%d\n", tmp);
    }
    return NULL;
}
```

### **Ana Program:**

```c
int main() {
    sem_init(&empty, 0, MAX); // Başlangıçta tüm tamponlar boş
    sem_init(&full, 0, 0);    // Başlangıçta dolu tampon yok
    sem_init(&mutex, 0, 1);   // Mutex semaforu

    pthread_t p, c;
    int loops = 10;
    pthread_create(&p, NULL, producer, &loops);
    pthread_create(&c, NULL, consumer, &loops);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    return 0;
}
```

---

### **Çözümün Avantajları**

1. **Senkronizasyon:**
    - **`empty`**: Üreticinin boş tampon olup olmadığını kontrol etmesini sağlar.
    - **`full`**: Tüketicinin dolu tampon olup olmadığını kontrol etmesini sağlar.
    - **`mutex`**: Kritik bölgeyi korur ve yarış durumlarını önler.
2. **Verimlilik:**
    - Boşta bekleyen iş parçacıkları uyutularak işlemci kaynakları korunur.

---

### **Sorunlar ve Geliştirmeler**

### **Yarış Durumu:**

- Eğer birden fazla üretici veya tüketici varsa, tamponun aynı anda değiştirilmesi yarış durumlarına yol açabilir.
- **Çözüm:** Kritik bölgeyi `sem_wait(&mutex)` ve `sem_post(&mutex)` ile korumak.

### **Geliştirme:**

- Daha fazla tampon yuvası ekleyerek eşzamanlı üretim ve tüketim sağlanabilir.

---

### **Sonuç ve Özet**

1. **Semaforlar:**
    - Senkronizasyon için güçlü araçlardır.
    - Hem kilitler (binary semaphore) hem de koşul değişkenleri yerine kullanılabilir.
2. **Producer/Consumer Problemi:**
    - Semaforlar, boş ve dolu tampon durumlarını yönetmek için kullanılır.
    - Kritik bölgeyi korumak için ek bir semafor (`mutex`) gereklidir.
3. **Verimlilik:**
    - İş parçacıkları bekleme sırasında uyutulur ve kaynaklar korunur.

---

### **Adding Mutual Exclusion to Producer/Consumer Problem**

### **Sorun: Yarış Durumu**

- Üretici ve tüketici, aynı tampon üzerinde eşzamanlı çalışırsa, yarış durumu oluşur.
- Tampona veri eklerken (`put`) ve tampondan veri alırken (`get`), işlemler kritik bir bölgedir.
- Bu kritik bölgeyi korumak için mutual exclusion (karşılıklı dışlama) sağlanmalıdır.

### **Hatalı Çözüm: Deadlock**

- İlk denemede, `mutex` semaforunun hatalı yerleştirilmesi **deadlock** oluşmasına yol açar.

### **Deadlock Senaryosu:**

1. **Tüketici**:
    - `mutex` semaforunu alır.
    - Tampon dolu değilse, `sem_wait(&full)` çağrısında bekler (bloklanır).
    - Ancak, `mutex` semaforunu bırakmadığı için üretici de beklemeye alınır.
2. **Üretici**:
    - `mutex` semaforunu almayı dener, ancak tüketici bu semaforu bırakmadığı için üretici de bloklanır.

**Sonuç:** İki iş parçacığı birbirini bekler ve işlem ilerlemez (**deadlock**).

---

### **Çözüm: Mutual Exclusion'u Doğru Yere Taşıma**

### **Doğru Çözüm:**

- `mutex` semaforunu yalnızca **kritik bölgeyi korumak** için kullanmalıyız.
- Tamponun doluluğunu/boşluğunu kontrol eden semaforlardan (`empty`, `full`) önce `mutex` kullanılmamalıdır.

---

### **Çözüm Kod: Doğru Yerleştirme**

### **Üretici:**

```c
void *producer(void *arg) {
    int loops = *(int *)arg;
    for (int i = 0; i < loops; i++) {
        sem_wait(&empty);         // Tamponda boş yer var mı? (p1)
        sem_wait(&mutex);         // Kritik bölgeye giriş (p1.5)
        put(i);                   // Tampona veri ekle (p2)
        sem_post(&mutex);         // Kritik bölgeden çıkış (p2.5)
        sem_post(&full);          // Dolu tampon sayısını artır (p3)
    }
    return NULL;
}
```

### **Tüketici:**

```c
void *consumer(void *arg) {
    int loops = *(int *)arg;
    for (int i = 0; i < loops; i++) {
        sem_wait(&full);          // Tamponda dolu yer var mı? (c1)
        sem_wait(&mutex);         // Kritik bölgeye giriş (c1.5)
        int tmp = get();          // Tampondan veri al (c2)
        sem_post(&mutex);         // Kritik bölgeden çıkış (c2.5)
        sem_post(&empty);         // Boş tampon sayısını artır (c3)
        printf("%d\n", tmp);
    }
    return NULL;
}
```

### **Ana Program:**

```c
int main(int argc, char *argv[]) {
    sem_init(&empty, 0, MAX);  // Başlangıçta tüm tamponlar boş
    sem_init(&full, 0, 0);     // Başlangıçta dolu tampon yok
    sem_init(&mutex, 0, 1);    // Mutex semaforu (binary semaphore)

    pthread_t prod, cons;
    int loops = 10;
    pthread_create(&prod, NULL, producer, &loops);
    pthread_create(&cons, NULL, consumer, &loops);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    return 0;
}
```

---

### **Reader/Writer Locks**

### **Sorun:**

- Bir veri yapısı üzerinde eşzamanlı **okuma (read)** ve **yazma (write)** işlemleri yapılırken:
    - **Yazma işlemi** veriyi değiştirdiği için yalnızca bir iş parçacığı çalışabilir.
    - **Okuma işlemi** veriyi değiştirmez, bu nedenle birden fazla iş parçacığı aynı anda okuyabilir.

### **Reader/Writer Locks:**

- Özel bir kilit türüdür:
    - **Reader Lock**: Veriyi yalnızca okuyan iş parçacıkları kullanır.
        - Eğer hiçbir yazma işlemi yapılmıyorsa, birden fazla okuyucu çalışabilir.
    - **Writer Lock**: Veriyi değiştiren iş parçacıkları kullanır.
        - Sadece bir yazıcı aynı anda çalışabilir ve diğer tüm işlemleri engeller.

### **Reader/Writer Lock Mantığı:**

1. **Reader:**
    - Okuma işlemine başlamadan önce **reader counter** artırılır.
    - Eğer aktif bir yazıcı yoksa, okuyucu işlemi devam eder.
    - Okuma işlemi bittiğinde, **reader counter** azaltılır.
2. **Writer:**
    - Yazma işlemi başlamadan önce, tüm okuyucu ve yazıcıların bitmesini bekler.
    - Yazma işlemi tamamlandığında, kilidi serbest bırakır.

### **Kod Taslağı:**

```c
int reader_count = 0;
sem_t mutex;  // Reader counter'ı korur
sem_t rwlock; // Writer lock

void reader() {
    sem_wait(&mutex);
    reader_count++;
    if (reader_count == 1) {
        sem_wait(&rwlock); // İlk okuyucu yazıcıyı engeller
    }
    sem_post(&mutex);

    // Okuma işlemi
    printf("Reading...\n");

    sem_wait(&mutex);
    reader_count--;
    if (reader_count == 0) {
        sem_post(&rwlock); // Son okuyucu yazıcıyı serbest bırakır
    }
    sem_post(&mutex);
}

void writer() {
    sem_wait(&rwlock); // Yazıcı kilidi edinir

    // Yazma işlemi
    printf("Writing...\n");

    sem_post(&rwlock); // Yazıcı kilidi serbest bırakır
}
```

---

### **Sonuç ve Özet**

1. **Producer/Consumer Problemi:**
    - Tampon erişimi sırasında yarış durumlarını önlemek için `mutex` kullanılır.
    - `mutex` doğru konumda kullanılmazsa deadlock oluşabilir.
    - Semaforlar, tamponun doluluğunu/boşluğunu ve kritik bölgeyi yönetmek için kullanılır.
2. **Reader/Writer Locks:**
    - Aynı anda birden fazla okuyucuya izin verir, ancak yazma işlemleri sırasında tüm erişimleri engeller.
    - Reader/Writer Locks, eşzamanlı okuma işlemlerinin performansını artırır.

---

### **Reader-Writer Locks (Okuyucu-Yazıcı Kilitleri)**

### **Temel Fikir:**

- **Yazıcılar (Writers):**
    - Aynı anda sadece bir yazıcı kritik bölgeye erişebilir.
- **Okuyucular (Readers):**
    - Yazıcı olmadığı sürece birden fazla okuyucu kritik bölgeye erişebilir.

---

### **Reader-Writer Lock Yapısı**

### **Veri Yapısı:**

```c
typedef struct rwlock_t {
    sem_t lock;        // Reader sayacını korumak için ikili semafor
    sem_t writelock;   // Tek yazıcıya izin veren semafor
    int readers;       // Aktif okuyucuların sayısı
} rwlock_t;
```

### **Kilit Başlatma:**

```c
void rwlock_init(rwlock_t *rw) {
    rw->readers = 0;
    sem_init(&rw->lock, 0, 1);       // Reader sayacını koruyan semafor
    sem_init(&rw->writelock, 0, 1); // Yazıcı kilidi
}
```

---

### **Reader İşlemleri**

### **Okuma Kilidini Almak:**

```c
void rwlock_acquire_readlock(rwlock_t *rw) {
    sem_wait(&rw->lock);              // Reader sayacını koruyan semafor
    rw->readers++;
    if (rw->readers == 1) {           // İlk okuyucu yazıcıyı engeller
        sem_wait(&rw->writelock);
    }
    sem_post(&rw->lock);              // Semaforu serbest bırak
}
```

### **Okuma Kilidini Bırakmak:**

```c
void rwlock_release_readlock(rwlock_t *rw) {
    sem_wait(&rw->lock);
    rw->readers--;
    if (rw->readers == 0) {           // Son okuyucu yazıcıyı serbest bırakır
        sem_post(&rw->writelock);
    }
    sem_post(&rw->lock);
}
```

---

### **Writer İşlemleri**

### **Yazma Kilidini Almak:**

```c
void rwlock_acquire_writelock(rwlock_t *rw) {
    sem_wait(&rw->writelock);         // Yazıcı kilidini edin
}
```

### **Yazma Kilidini Bırakmak:**

```c
void rwlock_release_writelock(rwlock_t *rw) {
    sem_post(&rw->writelock);         // Yazıcı kilidini serbest bırak
}
```

---

### **Reader-Writer Lock Sorunları**

### **Adillik Sorunu:**

- Okuyucuların sürekli kritik bölgeye girmesi durumunda yazıcıların açlığa uğraması (**writer starvation**) mümkündür.
- Çözüm:
    - Yazıcı bekliyorsa, yeni okuyucuların kilidi almasını engelleyen bir mekanizma eklenebilir.

---

### **Dining Philosophers Problemi**

### **Tanım:**

- Beş filozof bir masanın etrafında oturur ve yemek yemek için solundaki ve sağındaki çatalları kullanır.
- Çatallar ortak kaynaklardır ve senkronizasyon gerektirir.

### **Sorunlar:**

1. **Deadlock:**
    - Her filozof aynı anda bir çatalı alırsa, diğer çatalı almak için bekler ve sonsuza kadar bekler (deadlock).
2. **Starvation:**
    - Bazı filozoflar yemek yiyemeyebilir.
3. **Yüksek Eşzamanlılık:**
    - Çatışmaları en aza indirerek, mümkün olduğunca çok filozofun aynı anda yemek yemesi sağlanmalıdır.

---

### **Dining Philosophers Çözüm 1: Basit Semaforlar**

### **Kod:**

```c
sem_t forks[5];

void getforks(int p) {
    sem_wait(&forks[left(p)]);
    sem_wait(&forks[right(p)]);
}

void putforks(int p) {
    sem_post(&forks[left(p)]);
    sem_post(&forks[right(p)]);
}
```

### **Sorun:**

- Deadlock oluşabilir çünkü filozoflar aynı anda bir çatal alıp diğer çatal için bekler.

---

### **Dining Philosophers Çözüm 2: Deadlock'u Önlemek**

### **Fikir:**

- Belirli bir filozof (örneğin, filozof 4) çatalları ters sırada alır.
- Bu, döngüsel bekleme (circular wait) durumunu kırar.

### **Kod:**

```c
void getforks(int p) {
    if (p == 4) {
        sem_wait(&forks[right(p)]);
        sem_wait(&forks[left(p)]);
    } else {
        sem_wait(&forks[left(p)]);
        sem_wait(&forks[right(p)]);
    }
}
```

---

### **Zemaphore (Koşul Değişkeni ile Semaphore)**

### **Tanım:**

- Semaforun koşul değişkenleri ve kilitlerle birleştirilmiş bir versiyonudur.
- **Avantaj:** Semaforun sıfırın altına düşmesine izin verilmez, bu da basit ve güvenli bir implementasyon sağlar.

### **Zemaphore Veri Yapısı:**

```c
typedef struct Zem_t {
    int value;
    pthread_cond_t cond;
    pthread_mutex_t lock;
} Zem_t;
```

### **Zemaphore Başlatma:**

```c
void Zem_init(Zem_t *s, int value) {
    s->value = value;
    pthread_cond_init(&s->cond, NULL);
    pthread_mutex_init(&s->lock, NULL);
}
```

### **Zemaphore `wait`:**

```c
void Zem_wait(Zem_t *s) {
    pthread_mutex_lock(&s->lock);
    while (s->value <= 0) {
        pthread_cond_wait(&s->cond, &s->lock);
    }
    s->value--;
    pthread_mutex_unlock(&s->lock);
}
```

### **Zemaphore `post`:**

```c
void Zem_post(Zem_t *s) {
    pthread_mutex_lock(&s->lock);
    s->value++;
    pthread_cond_signal(&s->cond);
    pthread_mutex_unlock(&s->lock);
}
```

---

### **Sonuç ve Özet**

1. **Reader-Writer Locks:**
    - Aynı anda birden fazla okuyucuya izin verir, ancak yazıcı yalnız çalışır.
    - Yazıcı açlığı sorununu çözmek için ek mekanizmalar gerekebilir.
2. **Dining Philosophers:**
    - Deadlock'u önlemek için çatallar farklı sırada alınabilir.
    - Adil bir çözümle, her filozofun yemek yemesi sağlanabilir.
3. **Zemaphore:**
    - Koşul değişkenleri ve semaforların birleştirilmiş bir versiyonudur.
    - Güvenli ve basit bir implementasyon sağlar.

---