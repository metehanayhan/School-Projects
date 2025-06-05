# 1. Hafta

### **İşletim Sistemi Nedir?**

Bir **işletim sistemi (OS)**, donanım ve uygulama yazılımları arasında bir köprü görevi gören, bir bilgisayarın tüm kaynaklarını yöneten yazılımdır. Kullanıcılar, işletim sistemini doğrudan görmezler ama her komut ve işlem arka planda işletim sistemi tarafından yürütülür. Temel işlevleri şunlardır:

- **Donanım ve yazılım arasında bir arayüz sağlar:** Uygulamalar ve kullanıcılar donanıma doğrudan erişemezler; işletim sistemi, uygulamaların donanım kaynaklarına erişmesini sağlayan bir arayüz sunar.
- **Kaynakları yönetir:** İşletim sistemi, CPU (merkezi işlem birimi), bellek (RAM), depolama birimleri (hard disk, SSD) gibi sınırlı kaynakları yönetir ve verimli bir şekilde dağıtır.
- **Süreçleri yönetir:** Bilgisayarda birden fazla işlem aynı anda çalışabilir. İşletim sistemi, bu süreçlerin ne zaman ve nasıl çalışacağını organize eder.
- **Erişim kontrollerini sağlar:** İşletim sistemi, hangi kullanıcının veya uygulamanın hangi kaynaklara erişebileceğini belirleyen güvenlik politikalarını uygular.

---

### **İşletim Sisteminin Rolü - Bir Analoji**

Bir işletim sistemini bir restorandaki **garsona** benzetebiliriz:

- Garson (işletim sistemi) her müşteriyle (uygulamalar) ayrı ayrı ilgilenir.
- Menüdeki yemekleri (sistem kaynakları) müşterilere sunar.
- Müşteri siparişlerini alır (uygulama talepleri) ve mutfağa (donanıma) iletir.
- Doğru yemeği doğru müşteriye (kaynağı doğru uygulamaya) teslim eder.
- Siparişlerin (işlemlerin) doğru bir sırayla yürütüldüğünden emin olur ve müşteriler arasında karışıklığı önler.
- Her masanın hesabını (kaynak kullanımını) tutar ve ödemeleri yönetir (erişim kontrolü ve kaynak yönetimi).

---

### **İşletim Sisteminin Bileşenleri**

İşletim sistemlerinin tasarımı üç ana bileşen üzerine kuruludur. Bu bileşenler **sanallaştırma, eşzamanlılık (concurrency) ve kalıcılık (persistence)** olarak adlandırılır. Ayrıca güvenlik, tüm bu bileşenleri kapsayan bir üst katman olarak işletim sistemine entegre edilmiştir.

```c
                          **güvenlik
sanallaştırma | eşzamanlılık (concurrency) | kalıcılık (persistence)**
```

### **1. Sanallaştırma (Virtualization)**

**Sanallaştırma**, işletim sisteminin, her uygulamanın kendine özel bir sistemde çalışıyormuş gibi hissetmesini sağlar. Bu, işletim sisteminin kaynakları soyutlayarak uygulamalara sunmasıyla yapılır. Kaynaklar sınırlı olmasına rağmen, işletim sistemi her uygulamaya bu kaynakların tam anlamıyla kendi kullanımında olduğunu hissettirir.

- **CPU Sanallaştırması:** İşletim sistemi, her uygulamanın işlemciyi sanki sadece kendisi kullanıyormuş gibi düşünmesini sağlar. Gerçekte, CPU birden fazla uygulama arasında paylaştırılır ve her biri sırasıyla işlemci süresini kullanır.
- **Bellek Sanallaştırması:** İşletim sistemi, her uygulamanın sınırsız bir bellek alanına sahip olduğu yanılsamasını yaratır. Bu, bellek yönetimi teknikleri (örneğin, sanal bellek) ile sağlanır.
- **Zorluk:** Fiziksel kaynakların sınırlı olmasıdır. İşletim sistemi, bu kaynakları verimli bir şekilde paylaştırmalı ve her uygulamaya yeterli kaynak sağlamalıdır.

Örnek: Bir bilgisayarda aynı anda birden fazla programın çalışması, her birinin işlemci ve bellek kullanımını işletim sistemi aracılığıyla paylaştığı anlamına gelir.

### **2. Eşzamanlılık (Concurrency)**

Eşzamanlılık, birden fazla işlem veya olayın aynı anda meydana geldiği durumu ifade eder. Bir bilgisayarda, birçok süreç aynı anda çalışır ve işletim sistemi bu süreçlerin birbirini engellemeden çalışmasını sağlar. Burada iki tür süreç söz konusudur:

- **Bağımsız Süreçler:** Bu süreçler birbirlerinden tamamen bağımsız çalışır. İşletim sistemi, bu süreçlerin birbirinden habersiz çalışmasını sağlar. Örneğin, tarayıcınızda video izlerken arka planda dosya indiriyor olabilirsiniz.
- **Bağımlı Süreçler:** Bu süreçler birbirleriyle iletişim kurar ve senkronize olur. İşletim sistemi, bu süreçler arasındaki eşzamanlılığı doğru bir şekilde yönetir. Senkronizasyon ve iletişim araçları bu süreçler için sağlanır (örneğin, mutex'ler, semaforlar).
- **Zorluk:** Doğru senkronizasyon araçlarını sağlamak ve süreçlerin birbiriyle çakışmasını önlemektir.

Örnek: Aynı anda birden fazla uygulama çalıştırdığınızda, işletim sistemi her bir işlemin kendi işini yapmasına izin verirken diğer işlemlerle çakışmalarını engeller.

### **3. Kalıcılık (Persistence)**

**Kalıcılık**, bilgilerin bir sürecin yaşam süresinden daha uzun süreli olmasını ifade eder. Bilgisayarda bazı veriler, sistem kapatıldığında bile kaybolmaz. Bu tür verilerin kalıcılığını sağlamak için işletim sistemi dosya sistemleri ve depolama yönetimi gibi araçlar kullanır.

- **Dosya Sistemleri:** İşletim sistemi, verilerin nasıl saklandığını soyutlar ve kullanıcıların verileri bir dosya sistemi aracılığıyla organize etmesine olanak tanır.
- **Dayanıklılık:** İşletim sistemi, beklenmedik hatalar (örneğin, elektrik kesintisi) gibi durumlara karşı veri kaybını en aza indirmeye çalışır.
- **Erişim Kontrolü:** İşletim sistemi, kullanıcıların veya uygulamaların hangi dosyalara erişebileceğini belirler ve güvenlik sağlar.
- **Zorluk:** Doğru kimlik doğrulama ve yetkilendirme mekanizmaları oluşturarak veri güvenliğini sağlamaktır.

Örnek: Bilgisayarınızı kapatsanız bile, kaydettiğiniz belgeler sabit diskte kalır ve işletim sistemi yeniden açıldığında bu verilere erişebilirsiniz.

---

### **Güvenlik Katmanı**

Güvenlik, işletim sisteminin tüm bileşenlerini kapsayan çok önemli bir katmandır. İşletim sistemi, uygulamaların ve kullanıcıların kaynaklara erişimini kontrol eder, verilerin ve sistemin yetkisiz erişimden korunmasını sağlar.

- **Kimlik Doğrulama:** Kullanıcıların kimliklerini doğrulamak için şifreler, biyometrik veriler veya güvenlik sertifikaları kullanır.
- **Yetkilendirme:** Kullanıcılara ve uygulamalara, belirli kaynaklara erişim izni verir.
- **Veri Koruma:** Verilerin yetkisiz kişilere karşı korunmasını sağlar ve güvenlik açıklarına karşı sistemi güncel tutar.

---

### **Neden İşletim Sistemi Çalışmalısınız?**

İşletim sistemlerini öğrenmek, birçok açıdan faydalıdır:

- **İşletim Sistemi Geliştirme:** İşletim sistemi geliştirebilir, değiştirebilir veya mevcut bir işletim sistemini yönetebilirsiniz. Sistem yöneticileri, sistem kaynaklarını optimize etmek için işletim sistemi prensiplerini anlamalıdır.
- **Tasarım Kararlarını Anlamak:** İşletim sistemlerinin nasıl tasarlandığını öğrenmek, gelecekteki yazılım projelerinde daha bilinçli kararlar vermenizi sağlar.
- **Performans Optimizasyonu:** Sistemin hangi parçalarının performans açısından kritik olduğunu anladığınızda, uygulamaların daha verimli çalışmasını sağlamak için optimizasyon yapabilirsiniz.
- **Karmaşık Sistemleri Anlamak:** Bir işletim sistemi, birçok bileşeni bir arada yöneten karmaşık bir yazılım sistemidir. İşletim sistemlerini öğrenmek, diğer karmaşık yazılım sistemlerinin nasıl çalıştığını anlamanızı kolaylaştırır.
- **Daha İyi Bir Programcı Olmak:** İşletim sistemleri, donanımın nasıl yönetildiğini ve yazılımların nasıl çalıştığını anlamanızı sağlar. Bu, sizi daha yetenekli ve bilgili bir programcı yapar.

---