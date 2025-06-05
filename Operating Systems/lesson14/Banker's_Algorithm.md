# Banker's Algorithm

**Sistemin Başlangıç Durumu**

| **Process** | **Max (Maks)** | **Allocation (Tahsis)** | **Need (Gerekli)** | **Available (Mevcut)** |
| --- | --- | --- | --- | --- |
| **P1** | **(7, 5, 3)** | **(0, 1, 0)** | **(7, 4, 3)** | **(3, 3, 2)** |
| **P2** | **(3, 2, 2)** | **(2, 0, 0)** | **(1, 2, 2)** |  |
| **P3** | **(9, 0, 2)** | **(3, 0, 2)** | **(6, 0, 0)** |  |
| **P4** | **(2, 2, 2)** | **(2, 1, 1)** | **(0, 1, 1)** |  |
| **P5** | **(4, 3, 3)** | **(0, 0, 2)** | **(4, 3, 1)** |  |

**Adım 1: Sistem Güvenli Mi?**

1. **Mevcut kaynaklar: (3, 3, 2)**
2. **İşlemleri sırayla kontrol et:**
    - **P2: Gerekli kaynak (1, 2, 2) ≤ Mevcut (3, 3, 2) → P2 tamamlanır. Yeni mevcut kaynaklar: (3 + 2, 3 + 0, 2 + 0) = (5, 3, 2).**
    - **P4: Gerekli kaynak (0, 1, 1) ≤ Mevcut (5, 3, 2) → P4 tamamlanır. Yeni mevcut kaynaklar: (5 + 2, 3 + 1, 2 + 1) = (7, 4, 3).**
    - **P1: Gerekli kaynak (7, 4, 3) ≤ Mevcut (7, 4, 3) → P1 tamamlanır. Yeni mevcut kaynaklar: (7 + 0, 4 + 1, 3 + 0) = (7, 5, 3).**
    - **P3: Gerekli kaynak (6, 0, 0) ≤ Mevcut (7, 5, 3) → P3 tamamlanır. Yeni mevcut kaynaklar: (7 + 3, 5 + 0, 3 + 2) = (10, 5, 5).**
    - **P5: Gerekli kaynak (4, 3, 1) ≤ Mevcut (10, 5, 5) → P5 tamamlanır.**

**Güvenli işlem sırası: P2 → P4 → P1 → P3 → P5 Sistem güvenlidir.**

- **Deadlock’u önler:** Güvenli durum kontrolüyle kaynak tahsisi, güvensiz durumların oluşmasını engeller.
- **Kaynak kullanımını optimize eder:** Kaynakları yalnızca güvenli olduğunda tahsis eder, sistemin verimliliğini artırır.
- **Eşzamanlı sistemlerde kritik bir araçtır.**

![image.png](Banker's%20Algorithm%20167e67fac61d803f8a4afb0319246962/image.png)

### **Banker's Algorithm ile Sistem Güvenliği Analizi**

Bu analizde, verilen sistemin güvenli durumda olup olmadığını kontrol ederiz. **Banker's Algorithm** bu amaçla kullanılan bir yöntemdir ve aşağıdaki adımları içerir.

---

### **Sistemin Başlangıç Durumu**

### **Tablo:**

| Process | Max (Maks) | Allocation (Tahsis) | Need (Gerekli) | Available (Mevcut) |
| --- | --- | --- | --- | --- |
| P1 | (7, 5, 3) | (0, 1, 0) | (7, 4, 3) | (3, 3, 2) |
| P2 | (3, 2, 2) | (2, 0, 0) | (1, 2, 2) |  |
| P3 | (9, 0, 2) | (3, 0, 2) | (6, 0, 0) |  |
| P4 | (2, 2, 2) | (2, 1, 1) | (0, 1, 1) |  |
| P5 | (4, 3, 3) | (0, 0, 2) | (4, 3, 1) |  |

---

### **Adım Adım Güvenli Durum Analizi**

### **Adım 1: Başlangıç Mevcut Kaynaklar**

- **Available:** (3, 3, 2)

### **Adım 2: İşlemleri Kontrol Et**

1. **P2 (Gerekli: (1, 2, 2))**
    - **Koşul:** (1, 2, 2) ≤ (3, 3, 2) → Doğru.
    - **Tamamlanır:** Yeni mevcut kaynaklar:**(3 + 2, 3 + 0, 2 + 0) = (5, 3, 2)**
2. **P4 (Gerekli: (0, 1, 1))**
    - **Koşul:** (0, 1, 1) ≤ (5, 3, 2) → Doğru.
    - **Tamamlanır:** Yeni mevcut kaynaklar:**(5 + 2, 3 + 1, 2 + 1) = (7, 4, 3)**
3. **P1 (Gerekli: (7, 4, 3))**
    - **Koşul:** (7, 4, 3) ≤ (7, 4, 3) → Doğru.
    - **Tamamlanır:** Yeni mevcut kaynaklar:**(7 + 0, 4 + 1, 3 + 0) = (7, 5, 3)**
4. **P3 (Gerekli: (6, 0, 0))**
    - **Koşul:** (6, 0, 0) ≤ (7, 5, 3) → Doğru.
    - **Tamamlanır:** Yeni mevcut kaynaklar:**(7 + 3, 5 + 0, 3 + 2) = (10, 5, 5)**
5. **P5 (Gerekli: (4, 3, 1))**
    - **Koşul:** (4, 3, 1) ≤ (10, 5, 5) → Doğru.
    - **Tamamlanır:** Yeni mevcut kaynaklar:**(10 + 0, 5 + 0, 5 + 2) = (10, 5, 7)**

---

### **Güvenli İşlem Sırası**

- **P2 → P4 → P1 → P3 → P5**

---

### **Sistem Güvenli Mi?**

- **Evet**, sistem güvenlidir çünkü her işlem güvenli bir şekilde tamamlanabiliyor ve bir deadlock durumu oluşmuyor.

---

### **Banker's Algorithm'ın Avantajları**

1. **Deadlock'u Önleme:**
    - Güvenli durum kontrolü yaparak kaynak tahsisini güvensiz bir durumda engeller.
2. **Kaynak Yönetimi:**
    - Kaynakları yalnızca güvenli olduğunda tahsis ederek sistemin verimliliğini artırır.
3. **Eşzamanlılık:**
    - Eşzamanlı sistemlerde kaynak paylaşımını güvenilir bir şekilde yönetir.

---

### **Sonuç**

Bu analiz, sistemin güvenli durumda olduğunu ve işlemlerin belirlenen sırayla tamamlanabileceğini gösterir. Banker's Algorithm, deadlock'u önlemek ve kaynak kullanımını optimize etmek için güçlü bir yöntemdir.