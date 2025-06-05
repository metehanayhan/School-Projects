# 14. Hafta

# Interlude: Thread API

### **Thread API: Thread Creation (İş Parçacığı Oluşturma)**

İş parçacıkları, bir programın aynı anda birden fazla görevi gerçekleştirmesine olanak tanır. Bu başlık altında iş parçacıklarının nasıl oluşturulacağını ve kontrol edileceğini açıklıyoruz.

---

### **1. Thread Oluşturma: Temel Kavramlar**

### **Fonksiyon:** `pthread_create`

- **Tanım:**
    - Bir iş parçacığı oluşturmak için kullanılır.
    - Yeni bir iş parçacığı oluşturur ve belirtilen fonksiyonu bu iş parçacığında çalıştırır.
- **Fonksiyonun Prototipi:**
    
    ```c
    int pthread_create(
        pthread_t *thread,
        const pthread_attr_t *attr,
        void *(*start_routine)(void *),
        void *arg
    );
    ```
    
- **Parametreler:**
    1. **`thread`:**
        - Oluşturulan iş parçacığını temsil eden bir değişken.
        - Tipi `pthread_t`.
    2. **`attr`:**
        - İş parçacığına özgü özellikleri belirler.
        - Örneğin, yığın boyutu (stack size), zamanlama önceliği (scheduling priority) gibi.
        - **Varsayılan değer için NULL kullanılır.**
    3. **`start_routine`:**
        - İş parçacığının çalıştıracağı fonksiyon.
        - Tipi: `void *(*)(void *)`.
    4. **`arg`:**
        - İş parçacığına argüman olarak iletilecek veri.
        - Tipi: `void *`, bu da herhangi bir veri türünü iş parçacığına iletmeye olanak tanır.
- **Dönüş Değeri:**
    - Başarıyla iş parçacığı oluşturulursa **0** döndürür.
    - Hata durumunda hata kodunu döndürür.

---

### **2. Basit Thread Oluşturma Örneği**

```c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *mythread(void *arg) {
    printf("Thread says: %s\n", (char *)arg);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // İş parçacıklarını oluştur
    pthread_create(&thread1, NULL, mythread, "Hello from thread 1");
    pthread_create(&thread2, NULL, mythread, "Hello from thread 2");

    // İş parçacıklarını tamamlanana kadar bekle
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Main thread finished.\n");
    return 0;
}
```

### **Çıktı:**

```arduino
Thread says: Hello from thread 1
Thread says: Hello from thread 2
Main thread finished.
```

---

### **3. İş Parçacığı Fonksiyonu Argümanları**

**İş parçacığına özel argümanlar iletmek için `void *` kullanılır.**

### **Örnek: Bir Tamsayı Argümanı Geçme**

```c
#include <pthread.h>
#include <stdio.h>void *mythread(void *arg) {
    int num = *((int *)arg); // Argümanı al ve tamsayıya çevir
    printf("Thread received: %d\n", num);
    return NULL;
}

int main() {
    pthread_t thread;
    int num = 42;

    // İş parçacığı oluştur ve argüman olarak bir tamsayı geçir
    pthread_create(&thread, NULL, mythread, &num);
    pthread_join(thread, NULL);

    printf("Main thread finished.\n");
    return 0;
}
```

### **Çıktı:**

```arduino
Thread received: 42
Main thread finished.
```

---

### **4. Özel Veri Yapıları ile Argüman Geçme**

Birden fazla veri geçirmek istiyorsanız, bir yapı (struct) kullanabilirsiniz.

### **Örnek: Yapı Argümanı**

```c
#include <pthread.h>
#include <stdio.h>

typedef struct {
    int id;
    char message[50];
} ThreadData;

void *mythread(void *arg) {
    ThreadData *data = (ThreadData *)arg; // Argümanı yapıya çevir
    printf("Thread %d says: %s\n", data->id, data->message);
    return NULL;
}

int main() {
    pthread_t thread;
    ThreadData data = {1, "Hello from thread!"};

    // İş parçacığı oluştur ve argüman olarak yapı geçir
    pthread_create(&thread, NULL, mythread, &data);
    pthread_join(thread, NULL);

    printf("Main thread finished.\n");
    return 0;
}
```

### **Çıktı:**

```arduino
Thread 1 says: Hello from thread!
Main thread finished.
```

---

### **5. İş Parçacıklarının Özelliklerini Belirlemek**

İş parçacığı oluştururken özelliklerini (örneğin yığın boyutu) belirlemek için `pthread_attr_t` kullanabilirsiniz.

### **Örnek: İş Parçacığı Özellikleri**

```c
#include <pthread.h>
#include <stdio.h>

void *mythread(void *arg) {
    printf("Thread is running.\n");
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_attr_t attr;

    // İş parçacığı özelliği başlat
    pthread_attr_init(&attr);

    // Yığın boyutunu belirle
    pthread_attr_setstacksize(&attr, 1024 * 1024); // 1 MB

    // İş parçacığı oluştur
    pthread_create(&thread, &attr, mythread, NULL);
    pthread_join(thread, NULL);

    // Özellikleri yok et
    pthread_attr_destroy(&attr);

    printf("Main thread finished.\n");
    return 0;
}
```

---

### **Özet**

1. **`pthread_create`:** İş parçacığı oluşturmak için kullanılır.
2. **Parametreler:**
    - İş parçacığı değişkeni (`pthread_t`),
    - İş parçacığı özellikleri (`pthread_attr_t`),
    - Çalıştırılacak fonksiyon (`start_routine`),
    - Fonksiyona iletilecek argüman (`arg`).
3. **Argüman Türleri:**
    - `void *` türü ile herhangi bir veri tipini iş parçacığına iletebilirsiniz.
4. **Özelleştirme:**
    - İş parçacığının yığın boyutunu veya diğer özelliklerini belirlemek için `pthread_attr_t` kullanılabilir.

---

### **Örnek: İş Parçacığı Oluşturma ve Argüman Geçme**

Aşağıdaki örnek, bir iş parçacığının nasıl oluşturulacağını ve iş parçacığına argümanların nasıl iletileceğini göstermektedir.

---

### **Kod**

```c
#include <pthread.h>
#include <stdio.h>

// Argümanları taşımak için bir yapı tanımlıyoruz
typedef struct myarg_t {
    int a;
    int b;
} myarg_t;

// İş parçacığının çalıştıracağı fonksiyon
void *mythread(void *arg) {
    myarg_t *m = (myarg_t *) arg; // Argümanı doğru türe çevir
    printf("İş parçacığı aldı: a = %d, b = %d\n", m->a, m->b);
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t p;         // İş parçacığı değişkeni
    int rc;              // İş parçacığı oluşturma sonucu
    myarg_t args;        // İş parçacığına iletilecek argümanlar

    // Argüman değerlerini ayarla
    args.a = 10;
    args.b = 20;

    // İş parçacığını oluştur ve argümanları ilet
    rc = pthread_create(&p, NULL, mythread, &args);
    if (rc != 0) {
        printf("Hata: pthread_create başarısız oldu\n");
        return -1;
    }

    // İş parçacığının tamamlanmasını bekle
    pthread_join(p, NULL);

    printf("Ana iş parçacığı bitti.\n");
    return 0;
}
```

---

### **Kodun Açıklaması**

### **1. Argümanları Taşımak için Yapı Kullanımı**

- `myarg_t` adında bir yapı tanımlanmıştır.
- Bu yapı, birden fazla argümanı (örneğin, `a` ve `b`) tek bir değişkende toplamak için kullanılır.
- Her iş parçacığına bir `myarg_t` yapısı gönderilebilir.

### **2. İş Parçacığı Fonksiyonu**

```c
void *mythread(void *arg)
```

- Bu fonksiyon, iş parçacığı tarafından yürütülecek koddur.
- Parametre olarak bir `void *` alır, bu da herhangi bir türde veri iletilebileceği anlamına gelir.
- Fonksiyon içinde, `arg` doğru türe (`myarg_t *`) çevrilerek erişilir.

### **3. Argümanların Ayarlanması ve Geçirilmesi**

- `args` adında bir `myarg_t` değişkeni tanımlanır.
- `args.a` ve `args.b` değerleri ayarlanır (`args.a = 10; args.b = 20`).
- `pthread_create` çağrısında bu yapı adresi (`&args`) iş parçacığına iletilir.

### **4. İş Parçacığının Oluşturulması**

```c
pthread_create(&p, NULL, mythread, &args);
```

- `&p`: İş parçacığının kimliğini saklayacak değişkenin adresi.
- `NULL`: İş parçacığı için varsayılan özellikler kullanılır.
- `mythread`: İş parçacığının çalıştıracağı fonksiyon.
- `&args`: Fonksiyona iletilecek argümanların adresi.

### **5. İş Parçacığının Tamamlanmasını Bekleme**

```c
pthread_join(p, NULL);
```

- Bu fonksiyon, ana iş parçacığının, oluşturulan iş parçacığı bitene kadar beklemesini sağlar.

---

### **Programın Çıktısı**

Program çalıştırıldığında şu çıktıyı alırsınız:

```less
İş parçacığı aldı: a = 10, b = 20
Ana iş parçacığı bitti.
```

---

### **Dikkat Edilmesi Gerekenler**

1. **Paylaşılan Argümanlar:**
    - `args` değişkeni, ana iş parçacığında tanımlanmıştır ve iş parçacığı tarafından kullanılır. İş parçacığı çalışırken `args` üzerinde başka işlemler yapılmamalıdır.
2. **Kritik Bölge ve Eşzamanlılık:**
    - Eğer aynı argüman birden fazla iş parçacığı tarafından kullanılacaksa, veri yarış durumlarını (**race condition**) engellemek için senkronizasyon mekanizmaları (örneğin, kilit) kullanılmalıdır.

---

Aşağıda, **iş parçacığının tamamlanmasını bekleme (pthread_join)** işlevini açıklayan kodun düzgün bir biçimde yazılmış versiyonu ve detaylı açıklamaları verilmiştir.

---

### **Thread Tamamlanmasını Bekleme**

### **`pthread_join` Fonksiyonu**

- **Amaç:**
    - Ana iş parçacığının, belirtilen iş parçacığının tamamlanmasını beklemesini sağlar.
- **Prototip:**
    
    ```c
    int pthread_join(pthread_t thread, void **value_ptr);
    ```
    
- **Parametreler:**
    1. **`thread`:**
        - Beklenecek iş parçacığının kimliği.
    2. **`value_ptr`:**
        - İş parçacığı tarafından döndürülen değeri saklamak için kullanılan bir işaretçi.

---

### **Kod: İş Parçacığının Dönüş Değeri ile Kullanımı**

```c
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// Argümanları taşımak için bir yapı
typedef struct myarg_t {
    int a;
    int b;
} myarg_t;

// İş parçacığının döndüreceği değer için bir yapı
typedef struct myret_t {
    int x;
    int y;
} myret_t;

// İş parçacığının çalıştırdığı fonksiyon
void *mythread(void *arg) {
    myarg_t *m = (myarg_t *) arg; // Argümanı doğru türe çevir
    printf("İş parçacığı argümanları: a = %d, b = %d\n", m->a, m->b);

    // İş parçacığının döndürmek için değer ayarlaması
    myret_t *r = malloc(sizeof(myret_t));
    r->x = 1;  // Örnek bir değer
    r->y = 2;  // Örnek bir değer
    return (void *)r; // Dönen değer
}

int main(int argc, char *argv[]) {
    pthread_t p;          // İş parçacığı değişkeni
    myret_t *m;           // İş parçacığından dönen değeri saklamak için işaretçi
    myarg_t args;         // İş parçacığına gönderilecek argüman

    // Argümanları ayarla
    args.a = 10;
    args.b = 20;

    // İş parçacığını oluştur
    pthread_create(&p, NULL, mythread, &args);

    // İş parçacığının tamamlanmasını bekle
    pthread_join(p, (void **)&m);

    // İş parçacığının döndürdüğü değeri al ve yazdır
    printf("İş parçacığından dönen değerler: x = %d, y = %d\n", m->x, m->y);

    // Belleği serbest bırak
    free(m);

    printf("Ana iş parçacığı tamamlandı.\n");
    return 0;
}
```

---

### **Kodun Açıklaması**

### **1. Argümanların Kullanımı**

- **`myarg_t`:**
    - İş parçacığına birden fazla argüman göndermek için kullanılır.
    - `args.a` ve `args.b` ana iş parçacığı tarafından doldurulur ve iş parçacığına iletilir.

### **2. İş Parçacığının Döndürdüğü Değer**

- **`myret_t`:**
    - İş parçacığı, ana iş parçacığına döndürülecek iki değer (`x` ve `y`) içerir.
    - `malloc` ile bellekte dinamik olarak oluşturulur ve iş parçacığı tamamlandığında döndürülür.

### **3. `pthread_create` ile İş Parçacığı Oluşturma**

- **`pthread_create`:**
    - İş parçacığını oluşturur ve `mythread` fonksiyonunu yürütür.
    - `args` adresi, `mythread` fonksiyonuna argüman olarak geçirilir.

### **4. `pthread_join` ile Bekleme**

- **`pthread_join(p, (void **)&m);`:**
    - İş parçacığının tamamlanmasını bekler.
    - İş parçacığının dönüş değeri (dinamik olarak tahsis edilmiş `myret_t`) `m` işaretçisine atanır.

### **5. Bellek Yönetimi**

- İş parçacığı tarafından döndürülen dinamik belleğin (`m`) serbest bırakılması (`free`) önemlidir, aksi takdirde bellek sızıntısı oluşur.

---

### **Programın Çıktısı**

Programın çalıştırılmasından sonra alacağınız çıktı şu şekilde olacaktır:

```less
İş parçacığı argümanları: a = 10, b = 20
İş parçacığından dönen değerler: x = 1, y = 2
Ana iş parçacığı tamamlandı.
```

---

### **Önemli Notlar**

1. **Bellek Yönetimi:**
    - İş parçacığı tarafından döndürülen bellek (`malloc`) mutlaka serbest bırakılmalıdır.
2. **Argüman ve Dönüş Değerleri:**
    - İş parçacıklarının argümanları ve dönüş değerleri için doğru veri türü kullanılmalıdır.
3. **Senkronizasyon:**
    - `pthread_join` işlevi, ana iş parçacığının alt iş parçacıklarının tamamlanmasını beklemesini sağlar ve senkronizasyon için önemlidir.

---

### **Tehlikeli Kod (Dangerous Code)**

İş parçacıkları oluşturulurken veya değer döndürülürken dikkat edilmesi gereken bazı durumlar vardır. **İş parçacıkları tarafından döndürülen değerler geçerli bir bellek alanında saklanmalı ve uygun şekilde yönetilmelidir.** Aksi takdirde bellek hataları oluşabilir.

---

### **1. Tehlikeli Kod Örneği**

```c
void *mythread(void *arg) {
    myarg_t *m = (myarg_t *)arg;
    printf("%d %d\n", m->a, m->b);

    myret_t r;  // STACKTE TAHİS EDİLDİ
    r.x = 1;
    r.y = 2;

    return (void *)&r;  // DÖNDÜRÜLEN DEĞER STACKTE

```

### **Problemin Kaynağı**

- **`myret_t r`**:
    - `r` değişkeni **stack üzerinde** tahsis edilmiştir.
    - İş parçacığı sona erdiğinde, **stack alanı serbest bırakılır**. Bu nedenle, `r`'ye bir işaretçi döndürmek belirsiz davranışa (undefined behavior) neden olur.

### **Çözüm**

- Dinamik bellek tahsisi kullanılarak `r` heap üzerinde tahsis edilmelidir:
    
    ```c
    myret_t *r = malloc(sizeof(myret_t));
    r->x = 1;
    r->y = 2;
    return (void *)r;
    ```
    

---

### **2. Daha Basit Bir Argüman Geçişi Örneği**

Bu örnekte, iş parçacığına tek bir tamsayı argüman geçirilir ve basit bir değer döndürülür.

### **Kod:**

```c
#include <pthread.h>
#include <stdio.h>

void *mythread(void *arg) {
    int m = (int)arg;  // Argümanı al ve tamsayıya çevir
    printf("İş parçacığı argüman aldı: %d\n", m);

    return (void *)(m + 1);  // Argümanın 1 fazlasını döndür
}

int main(int argc, char *argv[]) {
    pthread_t p;       // İş parçacığı değişkeni
    int rc;            // Dönüş kodu
    void *ret;         // İş parçacığı dönen değer

    // İş parçacığını oluştur
    rc = pthread_create(&p, NULL, mythread, (void *)100);
    if (rc != 0) {
        printf("Hata: pthread_create başarısız oldu\n");
        return -1;
    }

    // İş parçacığının tamamlanmasını bekle
    pthread_join(p, &ret);

    // İş parçacığından dönen değeri yazdır
    printf("İş parçacığından dönen değer: %d\n", (int)ret);

    return 0;
}
```

---

### **Kodun Açıklaması**

### **1. Argüman Geçişi**

- **Argüman Türü:**
    - İş parçacığına tek bir `int` argüman geçiriliyor.
    - Bu argüman, `void *` olarak iletiliyor ve iş parçacığında `int`'e dönüştürülüyor:
        
        ```c
        int m = (int)arg;
        ```
        

### **2. İş Parçacığının Döndürdüğü Değer**

- İş parçacığı, kendisine iletilen argümanın 1 fazlasını döndürüyor:
    
    ```c
    return (void *)(m + 1);
    ```
    
- **Not:** Döndürülen değer, doğrudan bir tamsayı (integer) olduğu için ek bellek tahsisi gerekmez.

### **3. İş Parçacığını Bekleme ve Dönen Değeri Alma**

- `pthread_join` ile iş parçacığının tamamlanması bekleniyor ve döndürülen değer `ret` işaretçisine atanıyor:
    
    ```c
    pthread_join(p, &ret);
    ```
    
- Dönen değer yazdırılmadan önce `void *`'dan `int`'e dönüştürülüyor:
    
    ```c
    printf("İş parçacığından dönen değer: %d\n", (int)ret);
    ```
    

---

### **Programın Çıktısı**

Eğer bu kod çalıştırılırsa, çıktısı şu şekilde olur:

```lua
İş parçacığı argüman aldı: 100
İş parçacığından dönen değer: 101
```

---

### **3. Önemli Notlar**

1. **Stack ile Heap Ayrımı:**
    - İş parçacığına döndürülen değer stack üzerinde değil, **heap üzerinde tahsis edilmelidir**.
    - Stack üzerinde tahsis edilen bellek, iş parçacığı sona erdiğinde geçersiz hale gelir.
2. **`void *` Kullanımı:**
    - İş parçacığına her türden veri (`int`, `struct`, vs.) `void *` ile aktarılabilir.
    - İlgili türe çevirmek için uygun bir cast işlemi gereklidir.
3. **Dönen Belleğin Yönetimi:**
    - Eğer iş parçacığı dinamik bir bellek tahsis etmişse (`malloc`), bu belleğin ana iş parçacığı tarafından serbest bırakılması gerekir.

---

### **Locks (Kilitler)**

Kilitler, kritik bölgelerde **karşılıklı dışlama (mutual exclusion)** sağlayarak birden fazla iş parçacığının aynı anda paylaşılan bir kaynağa erişmesini engeller. Bu mekanizma, yarış durumlarını (**race condition**) önlemek için kullanılır.

---

### **1. Kilitlerin Kullanımı**

### **Kritik Bölge ve Karşılıklı Dışlama**

- Bir **kritik bölge**, aynı anda yalnızca bir iş parçacığının erişmesi gereken kod parçalarıdır.
- **`pthread_mutex_lock`** ve **`pthread_mutex_unlock`** işlevleri ile kilit oluşturularak kritik bölge güvence altına alınır.

---

### **2. Kilit Kullanımı İçin Temel Arayüz**

### **Fonksiyonlar:**

1. **`pthread_mutex_lock`:** Kilit alma (Lock).
    - Eğer kilit başka bir iş parçacığı tarafından tutulmuyorsa, çağrıyı yapan iş parçacığı kilidi alır ve kritik bölgeye girer.
    - Eğer kilit zaten tutuluyorsa, iş parçacığı kilidi alana kadar bekler.
    
    ```c
    int pthread_mutex_lock(pthread_mutex_t *mutex);
    ```
    
2. **`pthread_mutex_unlock`:** Kilit bırakma (Unlock).
    - Kritik bölgeden çıktıktan sonra kilidi bırakır.
    
    ```c
    int pthread_mutex_unlock(pthread_mutex_t *mutex);
    ```
    

### **Kilit Tanımı ve Kullanımı:**

```c
pthread_mutex_t lock;             // Kilit tanımlanır

pthread_mutex_lock(&lock);        // Kilit alınır (kritik bölgeye giriş)
x = x + 1;                        // Kritik bölge (örnek işlem)
pthread_mutex_unlock(&lock);      // Kilit bırakılır (kritik bölgeden çıkış)
```

---

### **3. Kilitlerin Doğru Başlatılması**

### **Statik Başlatma**

- **`PTHREAD_MUTEX_INITIALIZER`** makrosu kullanılarak doğrudan başlatma yapılabilir.
    
    ```c
    pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
    ```
    

### **Dinamik Başlatma**

- **`pthread_mutex_init`** fonksiyonu ile kilit başlatılır.
    
    ```c
    pthread_mutex_t lock;
    int rc = pthread_mutex_init(&lock, NULL);
    if (rc != 0) {
        printf("Kilit başlatma başarısız oldu.\n");
        exit(-1);
    }
    ```
    

### **Kilitlerin Yok Edilmesi**

- Program sonunda kilitlerin bellekten serbest bırakılması gerekir.
    
    ```c
    pthread_mutex_destroy(&lock);
    ```
    

---

### **4. Hata Kontrolü**

- **`pthread_mutex_lock`** ve **`pthread_mutex_unlock`** çağrıları hata kodu döndürebilir. Hatalar kontrol edilmelidir.
- Basit bir kontrol mekanizması:
    
    ```c
    void Pthread_mutex_lock(pthread_mutex_t *mutex) {
        int rc = pthread_mutex_lock(mutex);
        assert(rc == 0);  // Hata durumunda program sonlanır
    }
    ```
    

---

### **5. Özel Fonksiyonlar**

### **`pthread_mutex_trylock`**

- Kilidi almaya çalışır ancak kilit zaten tutuluyorsa **hata döndürür** (beklemez).
    
    ```c
    int pthread_mutex_trylock(pthread_mutex_t *mutex);
    ```
    

### **`pthread_mutex_timedlock`**

- Kilidi almak için belirli bir süre bekler. Bu süre dolarsa başarısız olur.
    
    ```c
    int pthread_mutex_timedlock(pthread_mutex_t *mutex, const struct timespec *abs_timeout);
    ```
    

---

### **6. Örnek: Temel Kullanım**

```c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t lock;  // Kilit tanımlandı
int counter = 0;

void *increment(void *arg) {
    for (int i = 0; i < 100000; i++) {
        pthread_mutex_lock(&lock);  // Kilit al
        counter++;                  // Kritik bölge
        pthread_mutex_unlock(&lock);  // Kilit bırak
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Kilit başlatma
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Kilit başlatma başarısız oldu.\n");
        return -1;
    }

    // İş parçacıkları oluştur
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    // İş parçacıklarının tamamlanmasını bekle
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Sonuç
    printf("Counter değeri: %d\n", counter);

    // Kilit yok etme
    pthread_mutex_destroy(&lock);

    return 0;
}
```

---

### **Kod Açıklaması**

1. **`pthread_mutex_t lock`:**
    - Kilit tanımlandı ve programın geri kalanında kritik bölgeyi korumak için kullanıldı.
2. **`pthread_mutex_init`:**
    - Kilit dinamik olarak başlatıldı.
3. **Kritik Bölge:**
    - `pthread_mutex_lock` ve `pthread_mutex_unlock` ile korundu.
    - İş parçacıkları `counter` değişkenine eşzamanlı olarak erişmeye çalışırsa, kilit yarış durumlarını engeller.
4. **Sonuç:**
    - Kilit sayesinde `counter` değişkeninin doğru bir şekilde artırılması sağlandı.

---

### **Program Çıktısı**

```
Counter değeri: 200000
```

- İki iş parçacığı toplamda `200000` kez artırma işlemi yaptı ve sonuç doğru şekilde hesaplandı.

---

### **Notlar**

1. **Kilitlerin Kullanım Amacı:**
    - Kritik bölgeye eşzamanlı erişimi engelleyerek veri tutarlılığını sağlamak.
2. **Hata Kontrolü:**
    - `pthread_mutex_lock` ve `pthread_mutex_unlock` fonksiyonlarının hata kodları kontrol edilmelidir.
3. **Kilitlerin Doğru Yönetimi:**
    - Kilit başlatılmalı ve program sonunda yok edilmelidir.

---

### **Condition Variables (Koşul Değişkenleri)**

**Condition variables**, iş parçacıkları arasında sinyal gönderme veya iletişim kurma gereksinimi olduğunda kullanılır. Bu değişkenler, bir iş parçacığının bir olayın gerçekleşmesini beklemesi ve diğer iş parçacıklarının bu olayı tetiklemesi için kullanılabilir.

---

### **1. Temel Fonksiyonlar**

### **1.1. `pthread_cond_wait`**

- **Amaç:**
    - İş parçacığını beklemeye alır.
    - Koşul gerçekleştiğinde diğer iş parçacıkları tarafından uyandırılır.
- **Prototip:**
    
    ```c
    int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex);
    ```
    
- **Çalışma Prensibi:**
    1. `pthread_cond_wait` çağrıldığında, iş parçacığı kilidi bırakır ve beklemeye başlar.
    2. Uyandırıldığında, iş parçacığı kilidi tekrar alır ve çalışmaya devam eder.

### **1.2. `pthread_cond_signal`**

- **Amaç:**
    - Bekleyen iş parçacıklarından en az birini uyandırır.
- **Prototip:**
    
    ```c
    int pthread_cond_signal(pthread_cond_t *cond);
    ```
    

---

### **2. Kullanım Örnekleri**

### **2.1. Temel Kullanım**

**Senaryo:**

- Bir iş parçacığı bir koşul gerçekleşene kadar bekler (`pthread_cond_wait`).
- Diğer iş parçacığı koşulu sağlar ve bekleyen iş parçacığını uyandırır (`pthread_cond_signal`).

**Kod Örneği:**

```c
#include <pthread.h>
#include <stdio.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int shared_data = 0; // Paylaşılan veri

void *waiting_thread(void *arg) {
    pthread_mutex_lock(&lock); // Kilit al
    while (shared_data == 0) {
        printf("İş parçacığı bekliyor...\n");
        pthread_cond_wait(&cond, &lock); // Koşul değişkenini bekle
    }
    printf("İş parçacığı uyandı! shared_data = %d\n", shared_data);
    pthread_mutex_unlock(&lock); // Kilit bırak
    return NULL;
}

void *signaling_thread(void *arg) {
    pthread_mutex_lock(&lock); // Kilit al
    shared_data = 42; // Koşulu sağla
    printf("Koşul sağlandı! shared_data = %d\n", shared_data);
    pthread_cond_signal(&cond); // Bekleyen iş parçacığını uyandır
    pthread_mutex_unlock(&lock); // Kilit bırak
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // İş parçacıklarını oluştur
    pthread_create(&t1, NULL, waiting_thread, NULL);
    pthread_create(&t2, NULL, signaling_thread, NULL);

    // İş parçacıklarının tamamlanmasını bekle
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
```

---

### **2.2. Kod Açıklaması**

1. **`pthread_mutex_t lock`:**
    - Koşul değişkenleri ile birlikte çalışmak için bir kilit gereklidir.
    - Paylaşılan veriye aynı anda yalnızca bir iş parçacığının erişmesini sağlar.
2. **`pthread_cond_t cond`:**
    - Bekleme ve sinyal mekanizması için kullanılır.
3. **`pthread_cond_wait`:**
    - `shared_data == 0` durumunda bekleyen iş parçacığı, `pthread_cond_wait` ile uyutulur.
4. **`pthread_cond_signal`:**
    - `shared_data` güncellendikten sonra bekleyen iş parçacığına sinyal gönderilir.

---

### **Çıktı**

Program çalıştırıldığında şu şekilde bir çıktı alırsınız:

```css
İş parçacığı bekliyor...
Koşul sağlandı! shared_data = 42
İş parçacığı uyandı! shared_data = 42
```

---

### **3. Önemli Notlar**

### **3.1. Koşulu Yeniden Kontrol Etme**

- `pthread_cond_wait` çağrısında bekleyen iş parçacığı uyandırıldığında, **koşulu yeniden kontrol etmelidir**.
- Bu nedenle, koşul bir `while` döngüsü içinde kontrol edilmelidir:
    
    ```c
    while (shared_data == 0) {
        pthread_cond_wait(&cond, &lock);
    }
    ```
    

### **3.2. Yanlış Kullanım**

- Bir koşulu yalnızca bir kez kontrol etmek (`if` kullanarak) hatalı sonuçlara yol açabilir:
    
    ```c
    if (shared_data == 0) {
        pthread_cond_wait(&cond, &lock); // Yanlış kullanım
    }
    ```
    

---

### **4. Kilit ve Koşul Değişkenlerini Başlatma**

### **Statik Başlatma**

```c
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
```

### **Dinamik Başlatma**

```c
pthread_mutex_t lock;
pthread_cond_t cond;

pthread_mutex_init(&lock, NULL);
pthread_cond_init(&cond, NULL);
```

### **Kilit ve Koşul Değişkenlerini Yok Etme**

- Programın sonunda, kilit ve koşul değişkenlerini serbest bırakın:
    
    ```c
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);
    ```
    

---

### **5. İleri Konular**

### **5.1. `pthread_cond_signal` ve `pthread_cond_broadcast`**

- **`pthread_cond_signal`:**
    - Bekleyen iş parçacıklarından yalnızca birini uyandırır.
- **`pthread_cond_broadcast`:**
    - Bekleyen tüm iş parçacıklarını uyandırır.

---

### **6. Derleme**

- **`pthread.h`** başlık dosyası eklenmelidir.
- Program, `pthread` bayrağı ile derlenmelidir:
    
    ```bash
    gcc -o main main.c -pthread
    ```
    

---

### **Özet**

| **Fonksiyon** | **Açıklama** |
| --- | --- |
| **`pthread_cond_wait`** | İş parçacığını uyutmak için kullanılır ve koşul sağlandığında uyanır. |
| **`pthread_cond_signal`** | Bekleyen iş parçacıklarından birini uyandırır. |
| **`pthread_cond_broadcast`** | Bekleyen tüm iş parçacıklarını uyandırır. |
| **`pthread_mutex_lock`** | Kilit alır ve kritik bölgeye erişimi kontrol eder. |
| **`pthread_mutex_unlock`** | Kilidi serbest bırakır. |

---

---

# Locks Slaytı

Locks (kilitler) konusu, çok iş parçacıklı (multi-threaded) programlama ve eşzamanlılık (concurrency) ile ilgilidir. Şimdi bu notlarda geçen her bir ifadeyi detaylıca açıklayalım ve temelinden başlayarak bu konuyu anlamanıza yardımcı olalım.

---

### **Locks Nedir ve Neden Önemlidir?**

1. **Kritik Bölge (Critical Section)**: Birden fazla iş parçacığının (threads) aynı anda erişip değiştirebileceği bir paylaşılan kaynak üzerinde çalışan kod parçasıdır. Örneğin:
    
    ```c
    balance = balance + 1;
    ```
    
    Burada, `balance` değişkenine aynı anda birden fazla iş parçacığı erişirse tutarsız sonuçlar oluşabilir.
    
2. **Atomiclik**: Atomic işlemler, bölünemez ve kesintiye uğramaz şekilde gerçekleştirilir. Yani, ya tamamen yapılır ya da hiç yapılmaz. Amaç, kritik bölgeyi bir iş parçacığının "tek başına" çalıştırmasını sağlamaktır.
3. **Locks**: Kritik bölgeyi güvenli hale getirmek için kullanılır. Bir kilit, bir iş parçacığının kritik bölgeye erişmesine izin verirken diğerlerini bekletir. Bu şekilde veri tutarlılığı sağlanır.

---

### **Kod Parçasını Anlamak**

Kod şu şekilde başlıyor:

```c
lock_t mutex; // Küresel olarak tanımlanan bir kilit (mutex)
```

- `lock_t mutex`: Bu, bir kilit objesidir. Genellikle bu tür kilitler için `mutex` (mutual exclusion) adı verilir. Paylaşılan bir değişkene erişimi kontrol eder.

### **Adım 1: Kilidi Tanımlama**

Kilit nesnesi, küresel bir değişken olarak tanımlanır. Çünkü birden fazla iş parçacığı tarafından kullanılacaktır.

### **Adım 2: Kilidi Edinme (Locking)**

```c
lock(&mutex);
```

- `lock()` fonksiyonu, kritik bölgeye erişmeden önce çağrılır. Eğer başka bir iş parçacığı bu kilidi tutuyorsa, bu iş parçacığı kilidin serbest bırakılmasını bekler.

### **Adım 3: Kritik Bölgeyi Çalıştırma**

```c
balance = balance + 1;
```

- Burada, `balance` değişkeni güncellenir. Ancak bu işlem yalnızca kilit edinildikten sonra yapılır, bu nedenle veri tutarsızlığı oluşmaz.

### **Adım 4: Kilidi Serbest Bırakma (Unlocking)**

```c
unlock(&mutex);
```

- Kritik bölgedeki işlem tamamlandıktan sonra `unlock()` çağrılır ve kilit serbest bırakılır. Böylece, başka bir iş parçacığı kritik bölgeye erişebilir.

---

### **Kodun Genel İşleyişi**

Tam kod akışı şu şekildedir:

1. Küresel bir kilit tanımlanır: `lock_t mutex`.
2. Kritik bölgeye erişimden önce `lock(&mutex)` ile kilit edinilir.
3. Kritik bölge çalıştırılır: `balance = balance + 1`.
4. İşlem tamamlandığında kilit serbest bırakılır: `unlock(&mutex)`.

Bu süreçte:

- **Eşzamanlılık Sorunları Önlenir**: Aynı anda birden fazla iş parçacığının `balance` değişkenini değiştirmesi engellenir.
- **Veri Tutarlılığı Sağlanır**: `balance` her zaman doğru şekilde güncellenir.

---

### **Neden Kilit Kullanıyoruz?**

### **Örnek Sorun:**

İki iş parçacığının aynı anda çalıştığını düşünelim ve her biri `balance` değişkenini 1 artırmaya çalışıyor.

1. İş Parçacığı 1: `balance` değerini okur (örneğin, 100).
2. İş Parçacığı 2: `balance` değerini okur (hala 100, çünkü İş Parçacığı 1 güncelleme yapmadı).
3. İş Parçacığı 1: `balance` değerini 101 olarak yazar.
4. İş Parçacığı 2: `balance` değerini 101 olarak yazar.

Beklenen sonuç: `balance = 102`.
Gerçek sonuç: `balance = 101` (Bir güncelleme kayboldu!).

Kilitler, bu tür durumların önüne geçmek için kullanılır.

---

### **Basit ve Karmaşık Örneklerle Anlama**

### **Basit Örnek:**

Bir iş parçacığı şu şekilde çalışır:

```c
lock(&mutex);
balance = balance + 1;
unlock(&mutex);
```

Diğer iş parçacıkları kilidi serbest bırakana kadar bekler. Bu sırada herhangi bir veri tutarsızlığı oluşmaz.

### **Karmaşık Örnek:**

Birden fazla iş parçacığı ve birden fazla kilit kullanımı olduğunda bu işlemler daha dikkatli yönetilmelidir. Yanlış kilitleme "deadlock" gibi sorunlara yol açabilir (örneğin, iki iş parçacığı birbirini bekler ve program durur).

---

### **Lock Variables (Kilit Değişkenleri)**

Bir kilit değişkeni, kilidin durumunu (state) tutar ve bu durum iki şekilde olabilir:

1. **Available (Boş/Unlocked)**:
    - Hiçbir iş parçacığı (thread) kilidi tutmaz.
    - Kilit serbest durumdadır ve başka bir iş parçacığı tarafından alınabilir.
2. **Acquired (Tutulan/Locked)**:
    - Tam olarak **bir iş parçacığı** kilidi tutar.
    - Bu iş parçacığı, kilit değişkenine sahip olduğu için kritik bölgeye girer.
    - Diğer iş parçacıkları kilidi serbest bırakılana kadar bekler.

---

### **Lock İşlevinin Anlamı ve Semantiği**

**`lock()` Fonksiyonu:**

- Kilidi edinmeyi ("acquire") dener.
- Eğer **başka bir iş parçacığı kilidi tutmuyorsa**, bu iş parçacığı kilidi alır ve kritik bölgeye girer.
    - Bu durumda, iş parçacığı **kilidin sahibi (owner)** olarak adlandırılır.
- Eğer kilit başka bir iş parçacığı tarafından tutuluyorsa:
    - İş parçacığı **beklemeye alınır** (kilit serbest bırakılana kadar).

**Kritik Bölge ve Diğer İş Parçacıkları:**

- Bir iş parçacığı kilidi edinip kritik bölgeye girdiğinde:
    - Diğer iş parçacıkları, aynı kilit serbest bırakılana kadar kritik bölgeye giremez.

---

### **Pthread Locks ve `pthread_mutex`**

**Pthread Kütüphanesi:**

- POSIX standardına uygun iş parçacıkları yönetimi sağlar.
- Kilitler için kullanılan veri yapısı: **`pthread_mutex_t`**

### **Kullanım Amaçları:**

- İş parçacıkları arasında **karşılıklı dışlama (mutual exclusion)** sağlamak.
- Eşzamanlılık sorunlarını önlemek için paylaşılan kaynakları kontrol etmek.

### **Farklı Kilitlerle Çalışma:**

- Farklı paylaşılan değişkenleri korumak için farklı kilitler kullanılabilir.
    - Bu, eşzamanlılığı (concurrency) artırır ve daha **ince ayrıntılı kontrol (fine-grained locking)** sağlar.

---

### **Pthread Mutex Kullanımı**

Bir kilit oluşturma ve kullanma adımları:

### **1. Kilit Tanımlama ve Başlatma**

```c
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
```

- **`pthread_mutex_t`**: Kilit için kullanılan veri tipi.
- **`PTHREAD_MUTEX_INITIALIZER`**: Kilidi başlangıç durumuna (boş/serbest) ayarlar.

### **2. Kilidi Edinme (Lock)**

```c
pthread_mutex_lock(&lock);
```

- Bu işlev, kilidi edinir.
- Eğer kilit başka bir iş parçacığı tarafından tutuluyorsa, bu işlev **kilit serbest bırakılana kadar bekler**.

### **3. Kritik Bölge**

```c
balance = balance + 1;
```

- İş parçacığı, kritik bölgeye girer ve paylaşılan kaynağı değiştirir.

### **4. Kilidi Serbest Bırakma (Unlock)**

```c
pthread_mutex_unlock(&lock);
```

- Kilidi serbest bırakır.
- Bekleyen diğer iş parçacıkları, kilidi alıp kritik bölgeye girebilir.

---

### **Verimli Kilitler (Efficient Locks)**

Bir kilidin verimli olması için şu özelliklere sahip olması gerekir:

1. **Düşük Maliyetli Karşılıklı Dışlama (Low-Cost Mutual Exclusion):**
    - İş parçacıkları arasındaki erişim kontrolünü yüksek performansla sağlar.
2. **Donanım ve İşletim Sistemi Desteği:**
    - Kilitlerin hızlı ve güvenli çalışması için işlemci (CPU) ve işletim sistemi tarafından sağlanan özel mekanizmalar kullanılır. Örneğin:
        - **Atomic işlemler**
        - **Test-and-Set** veya **Compare-and-Swap** gibi işlemler.

---

### **Pthread Mutex Örnek Kod**

Aşağıdaki örnek, birden fazla iş parçacığının bir değişkeni güvenli bir şekilde artırmasını sağlar:

```c
#include <pthread.h>
#include <stdio.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; // Kilidi başlat

int balance = 0; // Paylaşılan değişken

void *increment_balance(void *arg) {
    pthread_mutex_lock(&lock); // Kilidi edin
    balance = balance + 1;     // Kritik bölge
    pthread_mutex_unlock(&lock); // Kilidi serbest bırak
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, increment_balance, NULL); // İlk iş parçacığı
    pthread_create(&t2, NULL, increment_balance, NULL); // İkinci iş parçacığı

    pthread_join(t1, NULL); // İş parçacığının tamamlanmasını bekle
    pthread_join(t2, NULL);

    printf("Final balance: %d\n", balance); // Sonuç: 2
    return 0;
}
```

### **Kod Açıklaması:**

1. `pthread_mutex_t lock` ile kilit tanımlandı ve başlatıldı.
2. `pthread_mutex_lock` ile kilit edinildi, kritik bölgeye erişildi.
3. Kritik bölge tamamlandıktan sonra `pthread_mutex_unlock` ile kilit serbest bırakıldı.
4. İki iş parçacığı (t1 ve t2), `balance` değişkenini artırdı ve her işlem güvenli şekilde gerçekleştirildi.

---

### **Özet**

- **Kilit değişkeni**, kritik bölgeye erişimi kontrol eder.
- **Pthread kilitleri**, iş parçacıkları arasında karşılıklı dışlama sağlar.
- Kilidi etkin bir şekilde kullanarak veri tutarlılığı sağlanabilir ve eşzamanlılık sorunları önlenir.
- Verimli kilitler, donanım ve işletim sistemi desteği ile düşük maliyetli karşılıklı dışlama sunar.

---

## **Kilitleri Değerlendirme (Evaluating Locks)**

Bir kilit mekanizmasını değerlendirirken şu temel kriterler dikkate alınır:

1. **Mutual Exclusion (Karşılıklı Dışlama):**
    - Kilit, birden fazla iş parçacığının aynı anda kritik bölgeye girmesini önlemelidir.
    - Bu, kilidin temel işlevselliğidir ve kilidin doğru çalışıp çalışmadığını belirler.
2. **Fairness (Adillik):**
    - Kilit için yarışan iş parçacıklarının adil bir şekilde erişim elde etmesi gerekir.
    - Adil olmayan bir kilit mekanizması, bazı iş parçacıklarının kilidi sürekli olarak alamamasıyla sonuçlanabilir. Bu duruma **starvation (açlık)** denir.
3. **Performance (Performans):**
    - Kilitlerin kullanılması, programın performansına ek yük bindirir.
    - İyi bir kilit mekanizması, düşük zaman maliyetine sahip olmalıdır.

---

## **Kesintileri Kontrol Etme (Controlling Interrupts)**

### **Kesintileri Devre Dışı Bırakarak Karşılıklı Dışlama**

**Yaklaşım:**

- **Kesintileri devre dışı bırakmak**, kritik bölgeye yalnızca bir iş parçacığının girmesini garanti etmek için kullanılan eski bir yöntemdir.
- **Tek işlemcili sistemler** için uygun bir çözüm olarak geliştirilmiştir.

**Kod Örneği:**

```c
void lock() {
    DisableInterrupts();
}

void unlock() {
    EnableInterrupts();
}
```

- `DisableInterrupts()` ile kritik bölgeye giriş yapılır ve diğer iş parçacıkları engellenir.
- `EnableInterrupts()` ile kritik bölgeden çıkılır ve kesintiler yeniden etkinleştirilir.

### **Bu Yöntemin Sorunları:**

1. **Güven Sorunu:**
    - Açgözlü veya kötü niyetli bir program, kesintileri sürekli devre dışı bırakarak işlemciyi tek başına kullanabilir.
2. **Çok İşlemcili Sistemlerde Çalışmaz:**
    - Çok işlemcili sistemlerde kesintileri devre dışı bırakmak, diğer işlemcilerin kritik bölgeye erişimini engellemez.
3. **Modern CPU'larda Yavaşlama:**
    - Modern işlemcilerde kesintilerin devre dışı bırakılması veya etkinleştirilmesi işlemi yavaştır ve performansı olumsuz etkiler.

---

## **Donanım Desteğinin Gerekliliği (Why Hardware Support is Needed?)**

**İlk Deneme: Basit Bir Bayrak Kullanımı**

Bir bayrak (flag) değişkeni kullanılarak kilidin durumunun tutulması hedeflenir.

**Kod Örneği:**

```c
typedef struct lock_t {
    int flag;
} lock_t;

void init(lock_t* mutex) {
    mutex->flag = 0; // 0: Kilit boş, 1: Kilit dolu
}

void lock(lock_t* mutex) {
    while (mutex->flag == 1) {
        // Spin wait: Kilit boşalana kadar bekle
    }
    mutex->flag = 1; // Kilidi al
}

void unlock(lock_t* mutex) {
    mutex->flag = 0; // Kilidi bırak
}
```

### **Bu Yaklaşımın Sorunları:**

1. **Race Condition (Yarış Durumu):**
    - Aynı anda iki iş parçacığı `lock()` fonksiyonuna girerse, ikisi de `mutex->flag == 1` kontrolünden geçebilir ve kilidi aynı anda alabilir.
    - Bu durumda karşılıklı dışlama sağlanamaz.
2. **Spin-Wait Performans Sorunu:**
    - Kilit doluyken iş parçacıkları **boşta bekler (spin wait)** ve işlemci kaynaklarını boşa harcar.

---

## **Donanım Destekli Kilitler**

Donanım desteği, bu tür sorunların çözümünde hayati önem taşır. Modern işlemciler, atomik (kesintisiz) işlemler için özel komutlar sağlar. Örneğin:

### **Atomik İşlemler ile Kilitleme**

1. **Test-and-Set:**
    - Atomik olarak bir değişkenin değerini okur ve yeni bir değer atar.
    - Diğer iş parçacıkları, bu işlem tamamlanana kadar bekler.
2. **Compare-and-Swap:**
    - Belirli bir değişkenin değerini kontrol eder ve belirli bir koşula bağlı olarak değiştirir.

**Örnek: Test-and-Set ile Kilit**

```c
int test_and_set(int* target) {
    int old = *target;
    *target = 1;
    return old;
}

void lock(int* mutex) {
    while (test_and_set(mutex) == 1) {
        // Spin wait
    }
}

void unlock(int* mutex) {
    *mutex = 0;
}
```

- `test_and_set()` fonksiyonu atomik bir işlemdir, bu nedenle yarış durumu oluşmaz.
- Kritik bölgeye yalnızca bir iş parçacığı girebilir.

---

## **Özet ve Öneriler**

1. **Kilitleri Değerlendirme:**
    - Karşılıklı dışlama, adillik ve performans kriterleri göz önünde bulundurulmalıdır.
2. **Kesintileri Devre Dışı Bırakma:**
    - Tek işlemcili sistemler için basit bir yöntemdir ancak modern sistemlerde kullanılamaz.
3. **Bayrak Tabanlı Kilitler:**
    - Temel bir yöntemdir, ancak yarış durumu ve performans sorunlarına yol açabilir.
4. **Donanım Destekli Kilitler:**
    - Modern işlemcilerdeki atomik işlemler, etkili ve güvenilir kilitleme sağlar.

---

### **Neden Donanım Desteği Gerekli?**

### **Sorun 1: Karşılıklı Dışlama (Mutual Exclusion) Sağlanamıyor**

Kilit bayrağını (`flag`) temel alan bir kilitleme mekanizmasında, birden fazla iş parçacığı aynı anda kilidi almaya çalışabilir. Aşağıdaki durum bunun nasıl gerçekleştiğini gösteriyor:

**Başlangıç Durumu:** `flag = 0` (kilit boş)

**İşleyiş:**

1. **Thread 1** `lock()` çağrısını yapar ve `while (flag == 1)` kontrolünü geçer (çünkü `flag = 0`).
2. Bir **kesinti (interrupt)** meydana gelir ve kontrol **Thread 2**'ye geçer.
3. **Thread 2** de `lock()` çağrısını yapar ve aynı kontrolü geçer (`flag == 0`).
4. **Thread 2**, `flag` değerini `1` olarak ayarlar.
5. Kontrol tekrar **Thread 1**'e döner ve **Thread 1** de `flag` değerini `1` olarak ayarlar.

Sonuç olarak:

- İki iş parçacığı aynı anda `flag = 1` olarak ayarladı.
- Karşılıklı dışlama ihlal edildi ve kritik bölgeye birden fazla iş parçacığı girdi.

### **Sorun 2: Spin-Waiting (Bekleme Süresi)**

Spin-waiting, bir iş parçacığının kilidin serbest bırakılmasını beklerken işlemciyi meşgul etmesidir. Örneğin:

```c
while (flag == 1);
```

Bu kod parçası, kilit serbest bırakılana kadar sürekli döngüde kalır ve işlemci kaynaklarını boşa harcar. Çok iş parçacıklı uygulamalarda bu durum performans sorunlarına yol açar.

---

### **Donanım Desteği ile Çözüm**

Donanım desteği, **atomik işlemler** sayesinde bu sorunları çözebilir. İşlemciler, atomik işlemleri gerçekleştirmek için özel komutlar sağlar. Bunlardan biri **Test-and-Set (Atomic Exchange)** talimatıdır.

---

### **Test-and-Set (Atomic Exchange)**

### **Nasıl Çalışır?**

- Bu talimat, bir değişkenin mevcut değerini kontrol eder (**test**), aynı anda bu değeri yeni bir değerle günceller (**set**). Bu işlem **atomik** olarak gerçekleştirilir; yani bölünemez ve kesintiye uğramaz.

### **Test-and-Set İşlevinin Mantığı:**

```c
int TestAndSet(int *ptr, int new) {
    int old = *ptr; // ptr’nin eski değerini oku
    *ptr = new;     // ptr’ye yeni değeri ata
    return old;     // Eski değeri geri döndür
}
```

- `ptr`: Kilit bayrağı (örneğin `flag`).
- `new`: Ayarlanacak yeni değer (genellikle `1`).
- İşlev, eski değeri döndürerek kilidin önceki durumunu belirtir.

### **Özellikler:**

1. Atomik olarak çalışır (kesintiye uğramaz).
2. Yarış durumlarını önler.
3. Aynı anda birden fazla iş parçacığının kilidi almasını engeller.

---

### **Test-and-Set Kullanarak Basit Spin-Lock**

Test-and-Set atomik işlemi kullanılarak bir spin-lock mekanizması şu şekilde oluşturulabilir:

### **Kod:**

```c
typedef struct lock_t {
    int flag;
} lock_t;

void init(lock_t *lock) {
    lock->flag = 0; // 0: Kilit boş
}

void lock(lock_t *lock) {
    while (TestAndSet(&lock->flag, 1) == 1) {
        // Spin wait: Kilit boşalana kadar bekle
    }
}

void unlock(lock_t *lock) {
    lock->flag = 0; // Kilidi serbest bırak
}
```

### **Adım Adım İşleyiş:**

1. `init()`: Kilit başlatılır (`flag = 0`).
2. `lock()`:
    - `TestAndSet(&lock->flag, 1)` çağrılır.
    - Eğer `flag == 0` ise:
        - `TestAndSet()` eski değeri `0` olarak döndürür ve `flag` değerini `1` yapar.
        - İş parçacığı kilidi alır.
    - Eğer `flag == 1` ise:
        - `TestAndSet()` eski değeri `1` olarak döndürür ve iş parçacığı döngüde bekler (spin-wait).
3. `unlock()`:
    - `flag` değerini `0` yaparak kilidi serbest bırakır.

---

### **Tek İşlemcili Sistemlerde Sorun:**

Tek işlemcili sistemlerde spin-waiting sırasında başka bir iş parçacığı kilidi serbest bırakamaz, çünkü işlemci sadece bir iş parçacığını çalıştırabilir. Bu nedenle:

- Bir **preemptive scheduler** (kesintiye dayalı zamanlayıcı) gereklidir. Bu, işlemcinin bir iş parçacığını belirli bir süre sonra otomatik olarak başka bir iş parçacığıyla değiştirmesini sağlar.

---

### **Özet ve Avantajlar**

- **Test-and-Set** atomik işlemi, yarış durumlarını ve spin-waiting sorunlarını çözer.
- **Donanım desteği** olmadan, yarış durumları veya yüksek bekleme süreleri gibi problemler yaşanabilir.
- Atomik işlemler, kilitlerin güvenilir ve etkili bir şekilde çalışmasını sağlar.

---

### **Spin Lock'ların Değerlendirilmesi**

**Spin Lock Nedir?**

- Spin lock, bir iş parçacığının kritik bölgeye erişmek için sürekli döngüde beklemesi (spin-wait) anlamına gelir. Kilit serbest bırakılana kadar iş parçacığı işlemciyi meşgul etmeye devam eder.

### **1. Doğruluk (Correctness):**

- **Evet**, spin lock yalnızca bir iş parçacığının kritik bölgeye girmesine izin verir.
- **Karşılıklı dışlama (Mutual Exclusion)** sağlar.

### **2. Adillik (Fairness):**

- **Hayır**, spin lock adil değildir.
- Bir iş parçacığı sonsuza kadar döngüde bekleyebilir (**starvation**).
- Adillik garantisi verilmediği için bazı iş parçacıkları kilidi sürekli olarak alamayabilir.

### **3. Performans (Performance):**

- **Tek İşlemcili Sistemler:** Performans maliyeti yüksektir. Çünkü spin-wait sırasında işlemci tamamen meşgul olur ve başka işler yapılamaz.
- **Çok İşlemcili Sistemler:** Eğer iş parçacığı sayısı işlemci sayısına yakınsa, spin lock makul performans sergileyebilir. Ancak daha fazla iş parçacığı olduğunda performans kaybı yaşanır.

---

### **Compare-and-Swap (CAS)**

**Compare-and-Swap Nedir?**

- Donanım destekli bir atomik işlemdir.
- Belirtilen bir adresin (örneğin, bir kilit bayrağı) mevcut değerini kontrol eder ve belirli bir koşula göre yeni bir değerle günceller.
- Bu işlem atomik olarak gerçekleştirilir, yani başka bir iş parçacığı bu sürece müdahale edemez.

### **CAS İşlevinin Çalışma Mantığı:**

```c
int CompareAndSwap(int *ptr, int expected, int new) {
    int actual = *ptr;        // Mevcut değeri oku
    if (actual == expected) { // Eğer mevcut değer beklenen değere eşitse
        *ptr = new;           // Yeni değeri ata
    }
    return actual;            // Mevcut değeri döndür
}
```

### **Parametreler:**

1. `ptr`: Bellekteki bir adres (örneğin, kilit bayrağı).
2. `expected`: Beklenen değer (örneğin, `0`, kilidin boş olduğunu ifade eder).
3. `new`: Yeni değer (örneğin, `1`, kilidin dolu olduğunu ifade eder).

### **İşleyiş:**

1. `ptr` adresindeki mevcut değeri kontrol eder.
2. Eğer mevcut değer `expected` ile eşleşirse, `ptr` adresine `new` değeri atanır.
3. Mevcut değer döndürülür, böylece işlem başarılı mı, başarısız mı anlaşılır.

---

### **CAS Kullanarak Spin Lock**

### **Kod:**

```c
void lock(lock_t *lock) {
    while (CompareAndSwap(&lock->flag, 0, 1) == 1) {
        // Spin wait: Kilit serbest bırakılana kadar bekle
    }
}

void unlock(lock_t *lock) {
    lock->flag = 0; // Kilidi serbest bırak
}
```

### **İşleyiş:**

1. `lock()` fonksiyonu:
    - `CompareAndSwap` ile `flag` değerini kontrol eder.
    - Eğer `flag == 0` ise (`expected` değerine eşit):
        - `flag` değeri `1` yapılır (kilit alınır).
    - Eğer `flag == 1` ise:
        - İş parçacığı spin-wait ile bekler.
2. `unlock()` fonksiyonu:
    - `flag` değerini `0` yaparak kilidi serbest bırakır.

---

### **C'de x86 İçin Compare-and-Swap**

Donanım destekli CAS işlemi, işlemci mimarisine göre değişiklik gösterebilir. Örneğin, x86 işlemcilerde bu işlem şu şekilde gerçekleştirilir:

### **Kod:**

```c
char CompareAndSwap(int *ptr, int old, int new) {
    unsigned char ret;
    __asm__ __volatile__(
        "lock\n"                // Bellek erişimini kilitle
        "cmpxchgl %2, %1\n"     // Mevcut değeri kontrol et ve güncelle
        "sete %0\n"             // Sonucu ret değişkenine ata
        : "=q" (ret), "=m" (*ptr)
        : "r" (new), "m" (*ptr), "a" (old)
        : "memory"
    );
    return ret;
}
```

### **Açıklama:**

- `cmpxchgl`: Compare-and-Swap işlemini gerçekleştirir.
- `lock`: İşlemi atomik hale getirir.
- `sete`: İşlem sonucunu (başarılı veya başarısız) döndürür.

### **Kullanım Örneği:**

```c
lock_t lock;
lock.flag = 0;

void lock(lock_t *lock) {
    while (CompareAndSwap(&lock->flag, 0, 1) == 0) {
        // Spin wait
    }
}

void unlock(lock_t *lock) {
    lock->flag = 0;
}
```

---

### **Spin Lock ve CAS Karşılaştırması**

| **Özellik** | **Spin Lock (Test-and-Set)** | **Compare-and-Swap (CAS)** |
| --- | --- | --- |
| **Doğruluk** | Sağlar | Sağlar |
| **Adillik** | Sağlamaz | Sağlamaz |
| **Performans** | Yüksek bekleme maliyeti | Daha verimli |
| **Donanım Desteği** | Gerekir | Gerekir |
| **Karmaşıklık** | Basit | Daha karmaşık |

---

### **Özet**

- **Spin Lock'lar**, doğru çalışsa da adillik ve performans sorunlarına sahiptir.
- **Compare-and-Swap**, atomik işlemler kullanarak daha verimli bir kilit mekanizması sağlar.
- Modern işlemciler, CAS gibi atomik talimatlarla donanım destekli eşzamanlılık sağlar.
- CAS, spin-waiting sırasında kaynak israfını azaltır ve karşılıklı dışlamayı garanti eder.

---

Bu notlarda, **Load Linked (LL)** ve **Store Conditional (SC)** talimatları, **Fetch-and-Add** işlemi, ve **Ticket Lock** gibi farklı donanım destekli kilitleme mekanizmaları açıklanıyor. Şimdi her bir yöntemi detaylı bir şekilde açıklayalım.

---

### **Load Linked (LL) ve Store Conditional (SC)**

**LL/SC Nedir?**

- **Load Linked (LL):** Bir adresin (örneğin, bir bayrak ya da kilit) mevcut değerini yükler ve bu değeri takip eder.
- **Store Conditional (SC):** Eğer `LL` ile yüklendikten sonra bu adres başka bir iş parçacığı tarafından değiştirilmemişse, yeni bir değer yazmayı sağlar.

### **LL/SC Mantığı:**

1. **Load Linked (LL):**
    - Adresin mevcut değerini okur.
    - Bu adres üzerinde bir "bağlantı" (link) kurar.
2. **Store Conditional (SC):**
    - Adresin değeri başka bir iş parçacığı tarafından değiştirilmemişse:
        - Değeri günceller ve `1` döndürür (başarılı).
    - Eğer değer değiştirilmişse:
        - Değeri güncellemez ve `0` döndürür (başarısız).

### **LL/SC'nin Çalışma Mantığı:**

```c
int LoadLinked(int *ptr) {
    return *ptr; // Adresin mevcut değerini yükle
}

int StoreConditional(int *ptr, int value) {
    if (no_one_updated(ptr_since_LL)) {
        *ptr = value;  // Değeri güncelle
        return 1;      // Başarılı
    } else {
        return 0;      // Başarısız
    }
}
```

---

### **LL/SC Kullanarak Kilit Oluşturma**

LL/SC talimatları ile basit bir kilit oluşturabiliriz. Bu mekanizma, birden fazla iş parçacığının aynı anda kritik bölgeye girmesini engeller.

### **Kod:**

```c
void lock(lock_t *lock) {
    while (1) {
        while (LoadLinked(&lock->flag) == 1) {
            // Spin: Kilit boşalana kadar bekle
        }
        if (StoreConditional(&lock->flag, 1) == 1) {
            return; // Kilidi başarıyla al
        }
        // Başarısız olursa tekrar dene
    }
}

void unlock(lock_t *lock) {
    lock->flag = 0; // Kilidi serbest bırak
}
```

### **İşleyiş:**

1. `LoadLinked` ile `flag` değerini kontrol eder.
2. Eğer `flag == 0` (kilit boşsa), `StoreConditional` ile `flag` değerini `1` yapmayı dener.
3. Eğer `StoreConditional` başarılı olursa, iş parçacığı kilidi alır.
4. `unlock()` çağrıldığında, `flag` `0` yapılır ve diğer iş parçacıkları kilidi alabilir.

---

### **Fetch-and-Add**

**Fetch-and-Add Nedir?**

- **Atomik bir işlem**dir.
- Bir adresin mevcut değerini okur, bu değeri bir artış miktarı kadar artırır ve eski değeri döndürür.

### **Kod:**

```c
int FetchAndAdd(int *ptr) {
    int old = *ptr;    // Mevcut değeri oku
    *ptr = old + 1;    // Değeri artır
    return old;        // Eski değeri döndür
}
```

### **Kullanım Amaçları:**

- **Adil kilitler (fair locks)** oluşturmak.
- İş parçacıklarının sırasını takip etmek (örneğin, Ticket Lock).

---

### **Ticket Lock**

**Ticket Lock Nedir?**

- **Adil bir kilit mekanizmasıdır.**
- Her iş parçacığı, bir "bilet" numarası alır.
- İş parçacıkları, "sıra" numaralarına göre kritik bölgeye girer. Böylece starvation (açlık) önlenir.

### **Kod:**

```c
typedef struct lock_t {
    int ticket;  // Yeni bilet numarası
    int turn;    // Sırası gelen iş parçacığının numarası
} lock_t;

void lock_init(lock_t *lock) {
    lock->ticket = 0;
    lock->turn = 0;
}

void lock(lock_t *lock) {
    int myturn = FetchAndAdd(&lock->ticket); // Bilet numarası al
    while (lock->turn != myturn) {
        // Spin: Sıra bana gelene kadar bekle
    }
}

void unlock(lock_t *lock) {
    lock->turn++; // Sırayı bir sonraki iş parçacığına ver
}
```

### **İşleyiş:**

1. Her iş parçacığı `FetchAndAdd` ile bir bilet alır (`ticket`).
2. İş parçacığı, `turn` değişkenindeki numaranın kendi bilet numarasına eşit olmasını bekler.
3. İş parçacığı kritik bölgeyi tamamladığında, `unlock()` çağrılır ve `turn` değeri artırılarak sıradaki iş parçacığına geçiş yapılır.

### **Adillik ve Performans:**

- **Adillik:** Ticket Lock, iş parçacıklarının sırasını garanti eder.
- **Performans:** Çok iş parçacıklı sistemlerde etkili çalışır ancak spin-wait sırasında işlemci kaynakları harcanabilir.

---

### **Özet**

### **LL/SC (Load Linked ve Store Conditional):**

- Bellekte bir adresin değişmediğini kontrol etmek ve atomik güncelleme yapmak için kullanılır.
- Yarış durumlarını önler ve güvenilir bir kilit mekanizması sağlar.

### **Fetch-and-Add:**

- Atomik olarak bir değeri artırır ve eski değeri döndürür.
- Adil kilitler oluşturmak için kullanılabilir.

### **Ticket Lock:**

- İş parçacıkları için adillik sağlar ve starvation sorununu önler.
- Sıralı bir kilit mekanizmasıdır, ancak spin-wait sırasında işlemci kaynakları harcanabilir.

---

Bu notlar, **spin-lock'ların sorunları**, **OS desteğiyle spin-waiting'in nasıl optimize edilebileceği**, ve **uyuyan kilitler (sleeping locks)** gibi gelişmiş yaklaşımları ele alıyor. Şimdi her bir bölümü detaylıca açıklayalım.

---

## **Spin-Lock'ların Sorunları**

### **Sorun: Çok Fazla Döngü (So Much Spinning)**

- **Spin-lock'ların Temel Sorunu:**
    - Spin-lock'lar, kritik bölgeye erişmek için kilit beklenirken sürekli döngüye girer.
    - Bu, işlemciyi meşgul eder ve kaynak israfına yol açar.
- **Verimlilik Eksikliği:**
    - Eğer bir iş parçacığı uzun süre kilit bekliyorsa, işlemci bir **zaman dilimini (time slice)** boşa harcar.
    - Bu, özellikle çok işlemcili sistemlerde büyük bir sorun haline gelir.

---

## **Spin-Lock'larda Döngüyü Azaltma**

### **Yaklaşım 1: Yield (CPU'dan Vazgeçme)**

- **Nasıl Çalışır:**
    - İş parçacığı spin-wait sırasında CPU'yu diğer iş parçacıklarına bırakır.
    - **`yield()`** çağrısı, OS'ye bu iş parçacığının çalışmasını durdurup, hazır durumdaki diğer iş parçacıklarını çalıştırma fırsatı verir.
- **Avantajlar:**
    - İşlemci kaynaklarının boşa harcanmasını önler.
    - OS, iş parçacığını **çalışan durumdan (running state)** çıkarıp **hazır duruma (ready state)** geçirir.
- **Dezavantajlar:**
    - **Bağlam değiştirme (context switch)** maliyetlidir.
    - Starvation (açlık) hâlâ olasıdır; bazı iş parçacıkları kilidi alamayabilir.

### **Kod Örneği: Yield ile Spin-Lock**

```c
void lock() {
    while (TestAndSet(&flag, 1) == 1) {
        yield(); // CPU'dan vazgeç
    }
}

void unlock() {
    flag = 0; // Kilidi serbest bırak
}
```

---

### **Yaklaşım 2: Kuyruklar Kullanarak Beklemek (Sleeping Instead of Spinning)**

### **Temel Fikir:**

- **Spin-wait** yerine, bekleyen iş parçacıkları bir kuyruğa alınır ve uyutulur.
- **`park()`**: İş parçacığını uyutur.
- **`unpark(threadID)`**: Belirli bir iş parçacığını uyandırır.

### **Neden Kuyruk Kullanılır?**

- Kuyruk, hangi iş parçacıklarının kritik bölgeye erişim için beklediğini izler.
- **Adillik sağlar:** Kuyruktaki sıraya göre iş parçacıkları uyandırılır, böylece starvation önlenir.

---

### **Kuyruklarla Çalışan Kilitlerin Uygulaması**

### **Veri Yapısı:**

```c
typedef struct lock_t {
    int flag;      // Kilidin durumu (1: dolu, 0: boş)
    int guard;     // Kuyruğu korumak için bir spin-lock
    queue_t *q;    // Bekleyen iş parçacıkları kuyruğu
} lock_t;
```

### **Kilit Başlatma:**

```c
void lock_init(lock_t *m) {
    m->flag = 0;       // Kilit başlangıçta boş
    m->guard = 0;      // Kuyruk koruyucu başlangıçta boş
    queue_init(m->q);  // Kuyruğu başlat
}
```

### **Kilit Alma (Lock):**

```c
void lock(lock_t *m) {
    while (TestAndSet(&m->guard, 1) == 1) {
        // Kuyruk koruyucuyu edinmek için spin-wait
    }

    if (m->flag == 0) {
        m->flag = 1;  // Kilit alındı
        m->guard = 0; // Kuyruk koruyucu serbest bırakıldı
    } else {
        queue_add(m->q, gettid()); // İş parçacığını kuyruğa ekle
        m->guard = 0;              // Kuyruk koruyucu serbest bırakıldı
        park();                    // İş parçacığını uyut
    }
}
```

### **Kilit Bırakma (Unlock):**

```c
void unlock(lock_t *m) {
    while (TestAndSet(&m->guard, 1) == 1) {
        // Kuyruk koruyucuyu edinmek için spin-wait
    }

    if (queue_empty(m->q)) {
        m->flag = 0;  // Kilidi serbest bırak
    } else {
        unpark(queue_remove(m->q)); // Kuyruktan iş parçacığını çıkar ve uyandır
    }
    m->guard = 0; // Kuyruk koruyucu serbest bırakıldı
}
```

### **İşleyiş:**

1. **Kilit Alma:**
    - Eğer kilit boşsa (`flag == 0`), iş parçacığı kilidi alır ve kritik bölgeye girer.
    - Eğer kilit doluysa, iş parçacığı kuyruğa eklenir ve uyutulur.
2. **Kilit Bırakma:**
    - Eğer kuyruk boşsa, kilit serbest bırakılır (`flag = 0`).
    - Eğer kuyrukta bekleyen iş parçacıkları varsa, sıradaki iş parçacığı uyandırılır.

---

### **Fetch-and-Add ile Ticket Lock Kullanımı**

Kuyruk mantığını **Fetch-and-Add** ile birleştirerek **adillik** ve **verimlilik** sağlanabilir.

### **Kod:**

```c
typedef struct lock_t {
    int ticket;  // Alınan bilet sayısı
    int turn;    // Kritik bölgeye girmesi gereken bilet
} lock_t;

void lock_init(lock_t *lock) {
    lock->ticket = 0;
    lock->turn = 0;
}

void lock(lock_t *lock) {
    int myturn = FetchAndAdd(&lock->ticket); // Bilet al
    while (lock->turn != myturn) {
        park(); // Kritik bölge sırası gelene kadar uyut
    }
}

void unlock(lock_t *lock) {
    lock->turn++; // Sıradaki iş parçacığına geç
    unpark(next_thread_in_queue()); // Kuyruktaki sıradaki iş parçacığını uyandır
}
```

---

### **Özet**

1. **Spin-Lock'ların Sorunları:**
    - İşlemci kaynaklarının boşa harcanması.
    - Starvation (adillik eksikliği).
2. **Yield Yaklaşımı:**
    - İş parçacığı CPU'dan vazgeçerek diğer iş parçacıklarının çalışmasını sağlar.
    - Performans iyileşir, ancak bağlam değiştirme maliyeti artar.
3. **Kuyruklarla Bekleme:**
    - Bekleyen iş parçacıkları uyutulur, işlemci kaynakları boşa harcanmaz.
    - Adillik ve verimlilik artar.
4. **Fetch-and-Add ile Ticket Lock:**
    - Adil bir şekilde iş parçacıkları sıralanır.
    - Kuyruklarla birlikte kullanıldığında hem adillik hem de performans sağlanır.

---

Bu notlar, **wake-up/waiting yarış durumu**, **Futex** mekanizmaları, **iki aşamalı kilitler (two-phase locks)** ve bunların donanım ve işletim sistemi destekli çözümlerini ele alıyor. Şimdi bu konuları detaylıca açıklayalım.

---

## **Wakeup/Waiting Yarış Durumu**

### **Sorun:**

- Bir iş parçacığı (Thread B) kilit beklerken uyutulmaya hazırlanır (`park()`), ancak tam bu sırada başka bir iş parçacığı (Thread A) kilidi serbest bırakır ve `unpark()` çağrısı yapar.
- Bu durum, **Thread B'nin sonsuza kadar uyumasına (sleep forever)** neden olabilir, çünkü `unpark()` çağrısı `park()`'tan önce gerçekleşmiş olur.

### **Solaris Çözümü:**

- **setpark():** Bir iş parçacığı `park()` çağrısına geçmeden hemen önce çağrılır.
    - Eğer `unpark()` çağrısı `park()` öncesinde yapılırsa, iş parçacığı uyutulmaz ve `park()` hemen döner.

### **Kod Değişikliği:**

```c
queue_add(m->q, gettid()); // Kuyruğa ekle
setpark();                // Uyutulmaya hazırlan
m->guard = 0;             // Koruma kilidini serbest bırak
park();                   // İş parçacığını uyut
```

---

## **Futex (Fast User-Space Mutex)**

### **Linux'taki Çözüm:**

- Linux, düşük seviyeli bir kilitleme mekanizması olan **futex** sağlar.
- **Futex**, kullanıcı düzeyinde hızlı kilitleme için işletim sistemi destekli uyutma/uyandırma mekanizmasıdır.

### **Futex İşlevleri:**

1. **`futex_wait(address, expected)`**
    - İş parçacığını uyutur.
    - Eğer `address` üzerindeki değer `expected` değerine eşit değilse, işlem başarısız olur ve iş parçacığı uyutulmaz.
2. **`futex_wake(address)`**
    - Belirtilen adreste bekleyen iş parçacıklarından birini uyandırır.

### **Veri Yapısı:**

- Futex, genellikle tek bir `int` değer ile ifade edilir:
    - **En Yüksek Bit (Bit 31):** Kilidin dolu olup olmadığını belirtir.
    - **Diğer Bitler:** Bekleyen iş parçacıklarının sayısını izler.

---

### **Linux Tabanlı Futex Kilitler**

### **Kilidi Alma (mutex_lock):**

```c
void mutex_lock(int *mutex) {
    int v;
    if (atomic_bit_test_set(mutex, 31) == 0) {
        return; // Hızlı yol: Kilit alındı
    }
    atomic_increment(mutex); // Bekleyen iş parçacığı sayısını artır

    while (1) {
        if (atomic_bit_test_set(mutex, 31) == 0) {
            atomic_decrement(mutex); // Kilidi al ve bekleme sayısını azalt
            return;
        }
        v = *mutex;
        if (v >= 0) {
            continue; // Kilit hala alınmış
        }
        futex_wait(mutex, v); // Uyut
    }
}
```

### **Kilidi Bırakma (mutex_unlock):**

```c
void mutex_unlock(int *mutex) {
    if (atomic_add_zero(mutex, 0x80000000)) {
        return; // Bekleyen başka iş parçacığı yoksa sadece kilidi serbest bırak
    }
    futex_wake(mutex); // Bekleyen bir iş parçacığını uyandır
}
```

### **İşleyiş:**

1. Kilit alınırken **atomic_bit_test_set** hızlı bir yol sunar. Eğer kilit boşsa, hemen alınır.
2. Kilit doluysa, iş parçacığı bekleyenler arasına eklenir ve gerekirse uyutulur.
3. Kilit serbest bırakıldığında, bekleyen iş parçacıkları uyandırılır.

---

## **İki Aşamalı Kilitler (Two-Phase Locks)**

### **Temel Fikir:**

- Spin-wait ve uyuma mekanizmalarını birleştirir.
- Eğer kilit kısa sürede serbest bırakılacaksa, spin-wait yapılır.
- Eğer spin-wait sırasında kilit alınamazsa, iş parçacığı uyutulur.

### **Aşamalar:**

1. **Birinci Aşama (Spin-Wait):**
    - İş parçacığı, kilidi almak için kısa bir süre döngüye girer.
    - Eğer kilit alınamazsa ikinci aşamaya geçilir.
2. **İkinci Aşama (Uyuma):**
    - İş parçacığı uyutulur.
    - Kilit serbest bırakıldığında, uyuyan iş parçacıkları uyandırılır.

### **Avantajlar:**

- Spin-wait, kilidin kısa sürede serbest bırakılacağı durumlarda etkili bir çözümdür.
- Uzun süre beklemelerde işlemci kaynakları boşa harcanmaz, çünkü iş parçacığı uyutulur.

---

## **Donanım ve OS Destekleri Özeti**

### **Donanım Destekli Kilitleme:**

1. **Test-and-Set:**
    - Atomik olarak bir değeri test eder ve günceller.
    - Basit ancak spin-wait ile kaynak israfına neden olabilir.
2. **Compare-and-Swap (CAS):**
    - Bir değeri karşılaştırır ve belirli bir koşula göre günceller.
    - Yarış durumlarını önler.
3. **Load Linked ve Store Conditional (LL/SC):**
    - Adresin durumunu takip eder ve atomik olarak günceller.

### **OS Destekli Kilitleme:**

1. **park/unpark/setpark:**
    - İş parçacıklarını uyutma ve uyandırma mekanizmaları.
    - Wakeup/waiting yarış durumlarını çözer.
2. **Futex:**
    - Kullanıcı düzeyinde hızlı kilitleme.
    - Bekleyen iş parçacıklarını uyutma ve uyandırma mekanizmalarını destekler.
3. **Two-Phase Locks:**
    - Spin-wait ve uyutma mekanizmalarını birleştirir.

---

### **Özet**

- **Wakeup/Waiting Yarış Durumu:**
    - `setpark()` gibi OS çağrıları ile çözülür.
- **Futex:**
    - Linux'ta yaygın olarak kullanılır. Kullanıcı düzeyinde hızlıdır, ancak gerektiğinde OS desteğini kullanır.
- **İki Aşamalı Kilitler:**
    - Spin-wait ve uyutma yaklaşımlarını birleştirerek performans ve kaynak verimliliğini artırır.

---