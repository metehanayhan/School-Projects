# 9. Hafta

### **Bellek Sanallaştırması (Memory Virtualization) Nedir?**

- **Tanım:** İşletim sistemi, fiziksel belleğini (RAM) sanallaştırır, yani fiziksel belleği her bir işlem için bir **yanılsama** olarak sunar.
- **Nasıl çalışır?**
    - Her bir işlem (process), kendine aitmiş gibi görünen **özel bir bellek alanı** kullanır.
    - Sanki her işlem, fiziksel belleğin tamamını kullanıyormuş gibi bir görüntü oluşur.
    - Bu, işlemciler ve programlar için büyük bir kolaylık sağlar.

---

### **Bellek Sanallaştırmasının Avantajları**

1. **Programlama kolaylığı sağlar:**
    - Geliştiriciler, birden fazla işlemle uğraşırken karmaşık bellek yönetimiyle ilgilenmek zorunda kalmaz.
2. **Zaman ve alan açısından bellek verimliliği:**
    - İşlemlerin gereksiz bellek kullanımı önlenir.
    - Boş alanlar daha verimli şekilde kullanılır.
3. **Yalıtım (Isolation) garantisi:**
    - İşlemler, birbirlerinin bellek alanlarına yanlışlıkla erişemez.
    - İşletim sistemi ve işlemler arasında koruma sağlanır.
    - **Hata koruması:** Yanlışlıkla yapılan bellek erişimlerinin (örneğin başka bir işlemin belleğine) önüne geçilir.

---

### **İşletim Sistemlerinde Bellek Yönetimi – İlk Yıllar**

- **Nasıl çalışıyordu?**
    - Bellekte sadece bir işlem yükleniyordu.
    - Bellek alanı, işlem tamamlanana kadar başka hiçbir işlem tarafından kullanılamıyordu.
- **Dezavantajlar:**
    - **Düşük verimlilik:** İşlem bitene kadar bellek başka işler için kullanılamaz.
    - **Bellek israfı:** Belleğin büyük bir kısmı boş kalabilir.

---

### **Güncel Sistemler – Çoklu Programlama ve Zaman Paylaşımlı İşletim**

- **Ne değişti?**
    - **Birden fazla işlem bellekte aynı anda bulunabilir.**
    - İşlemler kısa bir süre çalıştırılır ve sonra diğerine geçilir (zaman paylaşımı).
- **Avantajlar:**
    - **Verimlilik artışı:** Belleğin kullanımı ve işlemci zamanı daha iyi değerlendirilir.
- **Sorunlar:**
    - Bellek erişimlerinde **koruma problemleri** oluşabilir:
        - Bir işlem başka bir işlemin bellek alanına yanlışlıkla erişebilir (hatalı bellek erişimi).

---

### **Sonuç**

Bellek sanallaştırması, günümüz işletim sistemlerinin en önemli özelliklerinden biridir. Hem programlama kolaylığı hem de bellek yönetimindeki verimlilik için kritik bir rol oynar. Ayrıca işlemler arası yalıtım ve koruma sayesinde, modern bilgisayar sistemlerinde güvenliği artırır.

---

### **Address Space (Adres Alanı)**

**Adres Alanı Nedir?**

- İşletim sistemi, fiziksel belleği soyutlayan bir **adres alanı** oluşturur.
- **Adres alanı**, çalışan bir işlemle ilgili tüm bilgileri içerir:
    - **Program kodu:** Çalışan programın komutları.
    - **Heap:** Dinamik olarak tahsis edilen bellek alanı.
    - **Stack:** Geri dönüş adresleri, yerel değişkenler ve fonksiyon parametrelerini saklar.

---

### **Adres Alanının Yapısı**

Adres alanı genellikle aşağıdaki bileşenlerden oluşur:

1. **Program Kodu (Code/Metin Bölümü):**
    - Programın çalıştırılabilir talimatları burada saklanır.
    - Bu bölüm genellikle sabittir ve değişmez (salt okunur).
2. **Heap:**
    - **Dinamik bellek tahsisi** için kullanılır. Örnek:
        - C dilinde `malloc()` fonksiyonu.
        - Nesne yönelimli dillerde `new` operatörü.
    - Heap, program çalışırken yukarıya doğru büyür (dinamik bellek ihtiyacına göre genişler).
3. **Stack:**
    - **Yerel değişkenleri**, **fonksiyon argümanlarını** ve **geri dönüş adreslerini** saklar.
    - Stack, aşağıya doğru büyür (yani heap ile ters yönde).

---

### **Adres Alanı Örneği**

Örnek bir adres alanı görseli:

```rust
0KB         -> Program Code (Kod Bölümü)
1KB         -> (Free/Boş Alan)
16KB        -> Heap
(free)      -> (Boş Alan)
Stack       -> Stack
```

---

### **Sanal Adres (Virtual Address)**

- **Sanal adres nedir?**
    - Çalışan bir programdaki her adres bir **sanal adrestir**.
    - İşletim sistemi, bu sanal adresleri fiziksel bellekteki adreslere çevirir.
    - **Adres çevirme (Address Translation):**
        - İşletim sistemi, bellek yönetim birimini (MMU - Memory Management Unit) kullanarak, sanal adresleri fiziksel adreslere dönüştürür.

---

### **Basit Bir Program ile Sanal Adres Örneği**

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("Kodun adresi : %p\n", (void *) main);          // Program kodunun adresi
    printf("Heap'in adresi : %p\n", (void *) malloc(1));  // Dinamik bellek adresi
    int x = 3;
    printf("Stack'in adresi : %p\n", (void *) &x);        // Stack üzerindeki değişken adresi
    return x;
}
```

**Program Çıktısı (64-bit Linux makinesinde):**

```yaml
Kodun adresi : 0x40057d
Heap'in adresi : 0xcf2010
Stack'in adresi : 0x7fff9ca45fcc
```

---

### **Çıktının Adres Alanı ile İlişkisi**

- **Kod Bölümü (Code/Text):**
    - Adres: `0x40057d`
    - Programın çalıştırılabilir talimatlarının saklandığı alan.
- **Heap:**
    - Adres: `0xcf2010`
    - Dinamik bellek tahsisiyle ilgili bellek bölgesi.
- **Stack:**
    - Adres: `0x7fff9ca45fcc`
    - Fonksiyonların yerel değişkenleri ve geri dönüş adreslerinin saklandığı alan.

---

### **Adres Alanı Görseli**

Bir programın çalışırken sahip olduğu adres alanı:

```scss
0x400000    -> Kod Bölümü (Code/Text)
(free)      -> (Boş Alan)
0xcf2000    -> Heap Başlangıcı
(dinamik)   -> Heap (Büyür)
(free)      -> (Boş Alan)
0x7fff9ca49000 -> Stack Başlangıcı
(dinamik)   -> Stack (Azalır)
```

---

### **Sonuç**

- **Adres alanı**, işletim sistemi tarafından fiziksel belleğin soyut bir görünümüdür.
- Belleğin farklı bölümleri (kod, heap, stack) sanallaştırılmış adresler üzerinden çalışır.
- Sanal adresler, fiziksel bellek ile doğrudan ilişkili değildir; işletim sistemi, sanal adresleri fiziksel adreslere çevirir.

---

---

### **Bellek Yönetimi – `malloc()` ve `free()`**

Bu bölümde, C dilinde bellek yönetimi ile ilgili önemli işlevleri detaylı bir şekilde ele alacağız: `malloc()` ve `free()`.

---

### **`malloc()` Nedir?**

- `malloc()` (memory allocation), heap üzerinde bir bellek bloğu tahsis eder.
- **Kullanım Amacı:**
    - Dinamik olarak bellek tahsis etmek ve bu belleği bir işaretici (pointer) aracılığıyla kullanmak.

---

### **`malloc()` Fonksiyonunun Yapısı**

```c
#include <stdlib.h>
void* malloc(size_t size);
```

- **Parametre:**
    - `size_t size`: Tahsis edilecek bellek bloğunun boyutu (bayt cinsinden).
    - `size_t`: İşaretsiz (unsigned) bir tam sayı türüdür.
- **Dönüş Değeri:**
    - Başarılı olursa: Tahsis edilen bellek bloğunun adresini döner (void pointer).
    - Başarısız olursa: `NULL` işaretçisi döner.

---

### **Örnek Kullanım**

```c
#include <stdlib.h>
#include <stdio.h>

int main() {
    int *x = malloc(10 * sizeof(int));  // 10 adet int için bellek tahsisi
    if (x == NULL) {
        printf("Bellek tahsisi başarısız!\n");
        return 1;
    }
    printf("Bellek tahsisi başarılı!\n");
    free(x);  // Tahsis edilen belleği serbest bırak
    return 0;
}
```

---

### **`sizeof()` ile Dinamik Bellek Tahsisi**

- **`sizeof` Operatörü:**
    - Bir değişkenin ya da türün bellek boyutunu bayt cinsinden hesaplar.
    - Dinamik tahsislerde, direkt bir sayı yazmak yerine `sizeof()` kullanmak daha güvenlidir.

---

### **Örnekler**

1. **Dinamik Tahsis ile**
    
    ```c
    int *x = malloc(10 * sizeof(int));  // 10 int'lik bellek tahsisi
    printf("%zu\n", sizeof(x));         // İşaretçinin boyutu (örneğin 4 veya 8 bayt)
    ```
    
2. **Statik Tahsis ile**
    
    ```c
    int x[10];                          // 10 int'lik statik dizi
    printf("%zu\n", sizeof(x));         // Dizi boyutu (örneğin 40 bayt)
    ```
    

> Not: Dinamik tahsiste işaretçinin boyutu dönerken, statik tahsiste dizinin tüm boyutu döner.
> 

---

### **`free()` Nedir?**

- Dinamik olarak tahsis edilmiş bellek alanını **serbest bırakır**.
- Bellek, kullanılabilir duruma geri döner.

---

### **`free()` Fonksiyonunun Yapısı**

```c
#include <stdlib.h>
void free(void* ptr);
```

- **Parametre:**
    - `void *ptr`: `malloc()` ile tahsis edilmiş bir işaretçi.
- **Dönüş Değeri:**
    - Hiçbir şey döndürmez.

---

### **`free()` Kullanımı**

```c
int *x = malloc(10 * sizeof(int));
if (x != NULL) {
    // x kullanımı
    free(x);  // Bellek serbest bırakılıyor
}
```

---

### **Bellek Tahsisi Yapmayı Unutma**

### **Hatalı Kod**

```c
char *src = "hello";  // Karakter dizisi
char *dst;            // Bellek tahsis edilmedi
strcpy(dst, src);     // Bellek tahsisi yapılmadığı için hata (segfault)
```

**Sorun:**

- `dst` işaretçisine bellek tahsis edilmediği için kopyalama işlemi başarısız olur ve program çöker.

---

### **Doğru Kod**

```c
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    char *src = "hello";                     // Karakter dizisi
    char *dst = malloc(strlen(src) + 1);    // Bellek tahsisi (strlen + 1)
    if (dst == NULL) {
        printf("Bellek tahsisi başarısız!\n");
        return 1;
    }
    strcpy(dst, src);                        // src'nin içeriğini dst'ye kopyala
    printf("dst: %s\n", dst);                // Sonuç: "hello"
    free(dst);                               // Tahsis edilen belleği serbest bırak
    return 0;
}
```

**Doğru Çalışma:**

- `malloc()` ile `dst` için yeterli bellek ayrıldı.
- `strcpy()` işlemi düzgün çalışır.

---

### **Sonuç**

- `malloc()` ve `free()` dinamik bellek yönetimi için kullanılan temel araçlardır.
- Bellek tahsisi yapmadan bir işaretçiyi kullanmaya çalışmak ciddi hatalara neden olabilir.
- Dinamik bellek kullanımında `malloc()` ile tahsis edilen belleği, kullanımdan sonra mutlaka `free()` ile serbest bırakmalısınız.

---

### **Bellek Yönetimi – Sorunlar ve Çözümler**

Bu bölümde dinamik bellek yönetiminde karşılaşılan yaygın sorunları ve ek bellek API'lerini ele alacağız. Her sorunu detaylı bir şekilde inceleyip, neden oluştuğunu ve nasıl düzeltileceğini açıklayacağız.

---

### **1. Yeterli Bellek Tahsis Etmeme (Not Allocating Enough Memory)**

### **Hatalı Kod**

```c
char *src = "hello";                   // Karakter dizisi
char *dst = (char *)malloc(strlen(src)); // Bellek tahsisi yetersiz
strcpy(dst, src);                      // Kopyalama
```

- **Sorun:**
    - `malloc(strlen(src))` yalnızca `"hello"` stringinin karakterlerini tahsis eder, ancak sonlandırıcı karakter `\0` için yer bırakmaz.
    - Bu durum yetersiz tahsise yol açar.
- **Sonuç:**
    - Program çoğu zaman doğru çalışabilir, çünkü belleğin geri kalan kısmına erişilebilir. Ancak bu davranış **belirli durumlarda** hatalara neden olabilir.

### **Doğru Kod**

```c
char *dst = (char *)malloc(strlen(src) + 1); // +1, '\0' için yer ayırır
strcpy(dst, src);
```

---

### **2. Belleği Başlatmayı Unutma (Forgetting to Initialize)**

### **Hatalı Kod**

```c
int *x = (int *)malloc(sizeof(int)); // Bellek tahsis edildi
printf("*x = %d\n", *x);             // Başlatılmamış belleğe erişim
```

- **Sorun:**
    - `malloc()` tahsis edilen belleği sıfırlamaz; bu nedenle `x` rastgele bir değer içerir.

### **Çözüm**

Belleği sıfırlamak için ya `calloc()` kullanın ya da tahsis ettikten sonra elle sıfırlayın.

**Doğru Kod (calloc ile):**

```c
int *x = (int *)calloc(1, sizeof(int)); // Bellek sıfırlanmış şekilde tahsis edilir
printf("*x = %d\n", *x);               // Değer: 0
```

**Doğru Kod (elle sıfırlama):**

```c
int *x = (int *)malloc(sizeof(int));
*x = 0;  // Elle sıfırlama
```

---

### **3. Bellek Sızıntısı (Memory Leak)**

### **Hatalı Kod**

```c
while (1) {
    malloc(4); // Bellek tahsis ediliyor ama serbest bırakılmıyor
}
```

- **Sorun:**
    - Her `malloc()` çağrısı ile bellek tahsis edilir, ancak hiçbir zaman `free()` çağrılmaz.
    - Bu, programın belleği tükenene kadar çalışmasına ve OS tarafından sonlandırılmasına neden olur.

### **Çözüm**

Tahsis edilen her belleği kullanımdan sonra `free()` ile serbest bırakın.

---

### **4. Geçersiz İşaretçi (Dangling Pointer)**

- **Tanım:**
    - Bellek serbest bırakıldıktan sonra, o belleğe erişmeye çalışmak "geçersiz işaretçi" hatasına yol açar.

### **Hatalı Kod**

```c
int *x = (int *)malloc(sizeof(int)); // Bellek tahsis edildi
free(x);                             // Bellek serbest bırakıldı
*x = 42;                             // Serbest bırakılmış belleğe erişim
```

### **Çözüm**

Belleği serbest bıraktıktan sonra işaretçiyi `NULL` olarak ayarlayın:

```c
free(x);
x = NULL; // Artık geçerli bir işaretçi değil
```

---

### **5. Yanlış `free()` Kullanımı**

### **Aynı Belleği Tekrar Serbest Bırakma**

```c
int *x = (int *)malloc(sizeof(int));
free(x);  // Serbest bırakıldı
free(x);  // Tekrar serbest bırakma (tanımsız davranış)
```

- **Sorun:**
    - Aynı bellek bloğunu birden fazla kez serbest bırakmak tanımsız davranışa neden olur.

### **Serbest Bırakılmayan Belleği Serbest Bırakma**

```c
int *x = (int *)malloc(sizeof(int));
free(x + 12); // malloc() ile tahsis edilmeyen bir belleği serbest bırakma
```

- **Sorun:**
    - `malloc()` tarafından tahsis edilmeyen bir adresi `free()` ile serbest bırakmaya çalışmak hatalara yol açar.

---

### **6. Diğer Bellek API'leri**

### **`calloc()`**

- **Tanım:**
    - Belleği tahsis eder ve sıfırlar.
- **Kullanım:**

```c
#include <stdlib.h>
void *calloc(size_t num, size_t size);

int *arr = (int *)calloc(10, sizeof(int)); // 10 int için sıfırlı bellek
```

---

### **`realloc()`**

- **Tanım:**
    - Mevcut bir bellek bloğunun boyutunu değiştirir.
- **Kullanım:**

```c
#include <stdlib.h>
void *realloc(void *ptr, size_t size);

int *arr = (int *)malloc(5 * sizeof(int)); // 5 int'lik bellek
arr = (int *)realloc(arr, 10 * sizeof(int)); // Boyutu artır
```

---

### **7. Sistem Çağrıları (`brk` ve `sbrk`)**

- **Heap Bellek Yönetimi:**
    - OS, heap belleğini genişletmek için `brk` ve `sbrk` sistem çağrılarını kullanır.
    - Bu çağrılar, programcılar tarafından **doğrudan çağrılmamalıdır**.

### **Kullanım:**

```c
#include <unistd.h>

int brk(void *addr);           // Heap sonunu belirtilen adrese ayarlar
void *sbrk(intptr_t increment); // Heap'i belirtilen miktarda genişletir
```

**Not:**

Bu çağrılar, düşük seviyeli belleği yönetmek için kullanılır, ancak modern programlarda `malloc()` veya `calloc()` gibi standart kütüphaneler tercih edilir.

---

### **Sonuç**

Bu notlarda, dinamik bellek yönetiminde karşılaşılan yaygın sorunları ve bunların nasıl çözülebileceğini detaylı bir şekilde öğrendik:

1. **Yetersiz bellek tahsisi:** `malloc` için doğru boyut kullanımı.
2. **Başlatmayı unutma:** `calloc` veya manuel sıfırlama.
3. **Bellek sızıntıları:** `free()` çağrısını ihmal etmeme.
4. **Geçersiz işaretçiler:** `free` sonrası işaretçinin `NULL` yapılması.

---

### **Sistem Çağrıları: mmap ve munmap**

### **1. `mmap` Nedir?**

`mmap` (memory map), bir bellek bölgesi tahsis etmek veya bir dosyayı bellekle eşleştirmek için kullanılan güçlü bir sistem çağrısıdır.

### **`mmap` Fonksiyon Tanımı**

```c
#include <sys/mman.h>
void *mmap(void *ptr, size_t length, int prot, int flags, int fd, off_t offset);
```

- **Argümanlar:**
    - **`void *ptr`:** Eşlenmiş bellek bölgesinin başlangıç adresi.
        - `NULL` verilirse, OS uygun bir adres tahsis eder.
    - **`size_t length`:** Tahsis edilecek bellek bloğunun boyutu (byte olarak).
    - **`int prot`:** Bellek bölgesinin koruma izinleri:
        - `PROT_READ` → Okuma izni.
        - `PROT_WRITE` → Yazma izni.
        - `PROT_EXEC` → Kod çalıştırma izni.
        - `PROT_NONE` → Hiçbir izin verilmez.
    - **`int flags`:** Eşlemenin özelliklerini belirler:
        - `MAP_SHARED` → Değişiklikler diske yazılır ve diğer işlemlerle paylaşılır.
        - `MAP_PRIVATE` → Değişiklikler yalnızca işlem için görünür.
        - `MAP_ANONYMOUS` → Dosyaya dayalı değil, bellek tahsisi için kullanılır.
    - **`int fd`:** Dosya tanıtıcısı. Eğer `MAP_ANONYMOUS` kullanılıyorsa, `1` olarak ayarlanır.
    - **`off_t offset`:** Dosyadaki başlangıç noktası (byte olarak).
- **Dönen Değer:**
    - Başarılı → Tahsis edilen bellek bölgesinin başlangıç adresi.
    - Başarısız → `MAP_FAILED` (genellikle `(void *)-1`).

---

### **2. Dosya Destekli Bellek Bölgesi (File-Backed Region)**

Dosya destekli bellek bölgeleri, bir dosyanın içeriğini belleğe eşler ve bu içerik üzerinde işlem yapmanıza olanak tanır.

### **Örnek: Dosya Destekli Bölge Oluşturma**

```c
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd = open("example.txt", O_RDWR);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    void *ptr = mmap(NULL, 40, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Bellek bölgesine veri yazma
    snprintf((char *)ptr, 40, "Merhaba Dünya!\n");

    // Belleği serbest bırakma ve dosyayı kapatma
    munmap(ptr, 40);
    close(fd);

    return 0;
}
```

- **Çıktı:**
    - `"example.txt"` dosyasına `"Merhaba Dünya!\n"` yazılır.

---

### **3. Anonim Bellek Bölgesi (Anonymous Region)**

Anonim bölgeler, dosyaya dayalı değil; yalnızca bellek tahsisi için kullanılır.

### **Örnek: Anonim Bölge Oluşturma**

```c

#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    size_t size = 40; // Tahsis edilen bellek boyutu
    void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    if (ptr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // Bellek bölgesine veri yazma
    snprintf((char *)ptr, size, "Anonim Bellek Kullanıldı!");

    // Veriyi ekrana yazdırma
    printf("%s\n", (char *)ptr);

    // Bellek serbest bırakma
    munmap(ptr, size);

    return 0;
}
```

- **Çıktı:**
    - `"Anonim Bellek Kullanıldı!"` ekrana yazdırılır.

---

### **4. `munmap` Kullanımı**

`munmap`, `mmap` ile tahsis edilen bellek bölgelerini serbest bırakmak için kullanılır.

### **Fonksiyon Tanımı**

```c
#include <sys/mman.h>
int munmap(void *ptr, size_t length);
```

- **Argümanlar:**
    - **`void *ptr`:** Serbest bırakılacak bellek bölgesinin adresi.
    - **`size_t length`:** Serbest bırakılacak bölgenin boyutu.
- **Dönen Değer:**
    - Başarılı → `0`.
    - Başarısız → `1` ve `errno` ayarlanır.

### **Örnek**

```c
munmap(ptr, 40); // 40 byte’lık bellek bölgesini serbest bırak
```

---

### **5. Özet**

| **Fonksiyon** | **Açıklama** |
| --- | --- |
| `malloc()` | Bellek tahsis eder (başlatılmamış). |
| `calloc()` | Bellek tahsis eder ve sıfırlar. |
| `realloc()` | Mevcut bellek bloğunu yeniden boyutlandırır. |
| `mmap()` | Bellek veya dosya destekli bir bellek bölgesi oluşturur. |
| `munmap()` | Tahsis edilen bellek bölgesini serbest bırakır. |

### **Kıyaslama: `malloc` ve `mmap`**

| Özellik | `malloc` | `mmap` |
| --- | --- | --- |
| **Performans** | Daha hızlı, heap üzerinde çalışır. | Daha yavaş, doğrudan sistem çağrısı. |
| **Kapsam** | Yalnızca bellek tahsisi. | Dosya veya bellek tahsisi. |
| **Kullanım Alanı** | Küçük, kısa ömürlü bellek blokları. | Büyük veya uzun ömürlü bellek blokları. |

---