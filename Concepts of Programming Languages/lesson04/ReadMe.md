# 4. Hafta

### Operatör Önceliği (Precedence)

Programlama dillerinde ifade edilen matematiksel işlemler, operatörlerin öncelik sıralaması ile değerlendirilir. **Operatör önceliği**, bir ifade içerisindeki işleçlerin (operatörlerin) hangi sırayla hesaplanacağını belirler. Bu, ifadelerde hangi işlemin önce yapılacağını netleştiren bir kural sistemidir. Örneğin, matematikte çarpma ve bölme işlemleri toplama ve çıkarmadan önce yapılır; benzer şekilde programlama dillerinde de belirli operatörler diğerlerinden önce işlenir.

### x + y * z İfadesinin Semantik Durumu

Bu ifade incelendiğinde, burada toplama (`+`) ve çarpma (`*`) operatörlerinin yer aldığı görülür. Semantik açıdan, bu ifadenin nasıl değerlendirileceği **operatörlerin değerlendirme sırası** ile ilgilidir.

Operatörlerin değerlendirme sırasını belirlemek için programlama dilleri, her operatöre farklı **öncelik seviyeleri** atar. Örneğin, çarpma operatörü (`*`), toplama operatöründen (`+`) daha yüksek bir önceliğe sahip olabilir. Bu, şu anlama gelir: `x + y * z` ifadesinde önce `y * z` hesaplanacak, ardından bu sonuca `x` değeri eklenecektir. Bu tür sorular, operatör önceliklerinin dilde nasıl tanımlandığına göre cevaplanır.

Bir dilin sözdizimi (syntax) ve dilbilgisi (grammar), operatörlerin nasıl işleneceğini belirler. Dilbilgisi kuralları, bir ifadenin anlamının bir kısmını **ayrıştırma ağacı** (parse tree) üzerinden çıkarılabilecek şekilde tanımlanır.

### Düşük ve Yüksek Üretim (Low and High Precedence)

Bir ayrıştırma ağacında, düşük ve yüksek üretilme durumu operatörlerin öncelik sıralamasını belirler. Örneğin, Şekil 3.2'deki ayrıştırma ağacında, çarpma operatörünün ağacın içinde daha düşük bir seviyede yer alması, bu operatörün toplama operatöründen daha yüksek önceliğe sahip olduğunu gösterir. Bu, çarpma işleminin toplama işleminden önce yapılacağı anlamına gelir.

Ancak, farklı bir ayrıştırma ağacı durumu gösteriliyorsa, bu durumda **çelişkili ya da tutarsız öncelik bilgisi** ortaya çıkabilir. Yani operatörlerin sırası net olarak belirlenmemiş olabilir.

### Örnek 3.2: A + B * C ve A * B + C

Bu örnekler, farklı operatör önceliklerine sahip ifadelerin nasıl işleneceğine dair bilgi verir. İlk ifade olan `A + B * C` ifadesinde, çarpma operatörünün toplama operatöründen önce geldiğini varsayarsak, `B * C` işlemi önce yapılır, ardından `A` değeri bu sonuca eklenir.

İkinci ifade olan `A * B + C` ifadesinde ise yine önce çarpma işlemi (`A * B`) yapılır, ardından toplama işlemi (`+ C`) gerçekleştirilir.

### Tutarlı Bir Öncelik Sağlamak

Bir programlama dilinin, sembollerin sıraya bakılmaksızın tutarlı bir şekilde işlenmesini sağlayacak şekilde tanımlanması mümkündür. Bunun için, operatörlerin farklı öncelik seviyelerini temsil eden dilbilgisi kuralları kullanılır. Örneğin, hem toplama (`+`) hem de çarpma (`*`) operatörlerinin yer aldığı bir ifadede, bu operatörler için ayrı **non-terminal semboller** ve kurallar kullanılabilir.

Bu durumda, her iki operatörün de aynı `<expr>` (ifade) non-terminal sembolü ile temsil edilmesi yerine, farklı seviyelerde üç farklı non-terminal sembolü kullanılır. Bu da dilbilgisinin, operatörleri ayrıştırma ağacında farklı seviyelere zorlamasına olanak tanır.

### Ayrıştırma Ağacının Düzenlenmesi

Eğer `<expr>` ifadesi (root symbol) kök sembolü olarak kullanılıyorsa, toplama operatörü (`+`) ayrıştırma ağacının tepesine zorlanabilir. Bu, toplama operatörünün en üstte yer almasını sağlar. Çarpma operatörü (`*`) ise, ağacın daha alt seviyelerinde yer alır.

Örneğin, `<expr>` doğrudan yalnızca toplama operatörlerini üretirken, toplama operatörünün sağ operandı için yeni bir non-terminal sembolü olan `<term>` kullanılabilir. Daha sonra `<term>`, çarpma operatörünü üretir ve bu işlem sırasında `<term>` sol operandı, yeni bir non-terminal sembolü olan `<factor>` ise sağ operandı temsil eder.

Bu şekilde çarpma işlemi, ayrıştırma ağacında her zaman toplama işlemine göre daha aşağıda bulunur. Bu da çarpma operatörünün toplama operatöründen daha önce işlenmesini garanti eder, çünkü başlangıç sembolüne (`<expr>`) olan uzaklığı daha fazladır.

### Özet

Operatör önceliği, programlama dillerinde işlemlerin nasıl sıralandığını ve hangi işlemlerin önce yapıldığını belirleyen önemli bir kavramdır. Ayrıştırma ağacının yapısı ve dilbilgisi kuralları, bu önceliği açıklar. Çarpma gibi daha yüksek önceliğe sahip işlemler, toplama gibi düşük öncelikli işlemlerden önce işlenir. Bu öncelik, dilbilgisindeki non-terminal sembollerin ve kuralların dikkatli düzenlenmesi ile sağlanır.

---

### Operatörlerin Birleşmesi (Associativity of Operators)

Operatörlerin birleşmesi, bir ifade içerisinde birden fazla aynı önceliğe sahip operatör bulunduğunda hangi sırada işleneceklerinin belirlenmesiyle ilgilidir. Operatörlerin **birleşmesi** iki farklı şekilde olabilir: **sol birleşme** (left associativity) ve **sağ birleşme** (right associativity). Bu kavramlar, aynı önceliğe sahip operatörlerin sol ya da sağdan başlayarak işlenmesini belirler.

### Sol Rekürsiyon ve Sol Birleşme

Bir dilbilgisi kuralı, sol tarafındaki sembolün (LHS) sağ tarafında (RHS) da ilk sırada yer alması durumunda **sol rekürsif** (left recursive) olarak adlandırılır. Sol rekürsiyon, bir operatörün **sol birleşimli** olduğunu belirtir. Sol birleşimli operatörler, soldan sağa doğru işlenir. Örneğin, toplama (`+`) ve çarpma (`*`) operatörlerinin sol birleşimli olması, bu işlemlerin soldan sağa doğru sırasıyla işleneceğini ifade eder.

### Örnek 3.4: Sol Birleşim

Dilbilgisinde sol rekürsiyonun varlığı, operatörlerin sol birleşimli olmasına neden olur. Örneğin, `A + B + C` ifadesini ele alalım. Bu ifade şu şekilde işlenir:

1. Önce `A + B` hesaplanır.
2. Sonra bu sonuca `+ C` eklenir.

Bu tür bir sol birleşim, toplama ve çarpma gibi operatörlerde sıklıkla kullanılır.

Ancak, sol rekürsiyonun bazı önemli **sözdizimsel analiz algoritmalarının** (syntax analysis algorithms) kullanılmasına izin vermediği bir durum vardır. Bu algoritmalar, sol rekürsiyon içeren dilbilgisini işleyemezler. Bu durumda, dilbilgisi sol rekürsiyondan arındırılmalıdır. Ancak, bu da dilbilgisinin bazı operatörlerin sol birleşimli olduğunu tam olarak belirtmesini engeller. Yani, sol rekürsiyon kaldırıldığında operatörün sol birleşimli olduğu bilgisi tam olarak ifade edilemeyebilir.

### Sol Birleşim ve Derleyici

Her ne kadar dilbilgisi sol birleşim konusunda kesin bir bilgi sunmasa da, **derleyici** (compiler) bu birleşim kuralını zorlayabilir. Yani, dilbilgisi sol birleşimi net olarak ifade etmese bile, derleyici bu işlemi sol birleşimli olarak gerçekleştirebilir.

### Sağ Birleşim ve Sağ Rekürsiyon

Bazı dillerde, üstel alma operatörü (`^`) gibi operatörler **sağ birleşimli** (right associative) olabilir. Sağ birleşim, bir ifadenin sağdan sola doğru işleneceğini belirtir. Sağ birleşimi ifade etmek için **sağ rekürsiyon** (right recursion) kullanılır.

Sağ rekürsif bir dilbilgisi kuralı, LHS (sol tarafındaki sembol) sağ tarafın (RHS) en sonunda yer alıyorsa **sağ rekürsif** olarak adlandırılır. Bu durumda operatörler sağdan sola işlenir. Örneğin, üstel alma operatörü sağ birleşimli olduğunda, `2 ^ 3 ^ 2` ifadesi şu şekilde işlenir:

1. Önce `3 ^ 2` hesaplanır.
2. Sonra bu sonucun üssü olarak `2 ^` işlenir.

### Özet

Operatörlerin birleşmesi, aynı önceliğe sahip operatörlerin hangi sırayla işleneceğini belirler. Sol rekürsiyon, bir operatörün sol birleşimli olduğunu ifade ederken, sağ rekürsiyon sağ birleşimli operatörleri gösterir. Sol rekürsiyon dilbilgisine dahil edildiğinde, bazı sözdizimsel analiz algoritmalarını kullanma imkanı ortadan kalkar. Ancak, derleyici bu birleşim kurallarını dilbilgisinden bağımsız olarak uygulayabilir. Sağ birleşim durumunda ise sağ rekürsiyon dilbilgisinde kullanılır ve operatörler sağdan sola doğru işlenir.

---

### **If-Then-Else İçin Tam Gramer**

Bu başlık altında, `if-then-else` ifadelerinin tanımlandığı bir dilbilgisinin kurallarını inceleyeceğiz. **BNF** (Backus-Naur Form) kullanılarak tanımlanan bu dilbilgisi kuralları, Ada gibi programlama dillerindeki `if-then-else` yapılarını temsil eder. Ancak bu gramer kurallarında **belirsizlik** (ambiguity) problemi ortaya çıkabilir ve bu problemi çözmek için **belirsiz olmayan** (unambiguous) bir dilbilgisi geliştirilmesi gerekir.

### **Belirsiz Dilbilgisi Problemi**

Belirli dilbilgisi kuralları, bir dilde bazı ifadelerin farklı şekillerde yorumlanmasına izin verebilir. Bu, **belirsizlik** (ambiguity) olarak adlandırılır. Eğer bir ifade birden fazla **ayrıştırma ağacı** (parse tree) ile temsil edilebiliyorsa, bu gramer belirsizdir. Örneğin, aşağıdaki gramer kuralları:

- `stmt` → `if logic_expr then stmt`
- `stmt` → `if logic_expr then stmt else stmt`

Bu kurallar, bir `if` ifadesinin hem `else` ifadesine sahip olup olmaması durumunu temsil eder, ancak **belirsiz** bir şekilde. Bu belirsizlik, şu gibi bir ifade için ortaya çıkar:

```arduino
if logic_expr then if logic_expr then stmt else stmt
```

Bu ifadeyi farklı şekillerde ayrıştırabilirsiniz. Örneğin, `else` ifadesinin hangi `then` ile eşleştiği net değildir. Ayrıştırma ağaçları bu belirsizliği açıkça gösterir.

### **Belirsizliğin Sebebi ve Çözümü**

**Belirsizlik**, bir `if-then-else` ifadesinde `else` ifadesinin hangi `then` ile eşleşeceğinin belirsiz olmasından kaynaklanır. Bu sorunu çözmek için programlama dillerinde genellikle şu kural uygulanır:

- **Bir `else` ifadesi, kendisinden önce gelen en yakın `then` ile eşleşir.**

Bu kural sayesinde, `else` ifadesinin hangi `then` ile eşleştiği kesin olarak belirlenir ve belirsizlik ortadan kalkar.

Bu durumda, **iki farklı tür if** yapısı ayırt edilmelidir:

1. **Matched if:** Bir `then` ve ona karşılık gelen `else` ifadesiyle eşleşen `if` yapıları.
2. **Unmatched if:** Bir `then` ifadesine sahip ancak `else` ifadesi olmayan `if` yapıları.

Bu ayrım sayesinde gramerimizi belirsizlikten kurtarabiliriz.

### **Belirsiz Olmayan Dilbilgisi**

Belirsizliği ortadan kaldırmak için, farklı kategorilerde ifadeler kullanmalıyız: **matched** (eşleşmiş) ve **unmatched** (eşleşmemiş). Böylece her tür `if` ifadesi dilbilgisinde farklı bir şekilde temsil edilecektir.

**Tam gramer şu şekildedir:**

- `stmt` → `matched` | `unmatched`
- `matched` → `if logic_expr then matched else matched`
    - (Bu kural, `else` ifadesi ile eşleşen `then` ifadelerini temsil eder.)
- `matched` → herhangi bir `if` dışı ifade
- `unmatched` → `if logic_expr then stmt`
    - (Bu kural, `else` ifadesi olmayan `then` ifadelerini temsil eder.)
- `unmatched` → `if logic_expr then matched else unmatched`
    - (Bu kural, bir `then` ifadesiyle eşleşmiş `else` ifadesi ile `unmatched` yapısını tanımlar.)

### **Örnek**

Bu dilbilgisine göre, aşağıdaki sentential form (cümle biçimi) için sadece **tek bir ayrıştırma ağacı** vardır:

```arduino
if logic_expr then if logic_expr then stmt else stmt
```

Bu durumda, en yakın `then` ifadesi ile `else` ifadesi eşleşecektir. İkinci `if` ifadesi, `else` olmadan bir `unmatched` if yapısı olarak tanımlanacaktır.

### **Sonuç**

Belirsiz olmayan bu gramer, `if-then-else` ifadelerinin dilbilgisi kurallarını açıkça tanımlar ve belirsizliği ortadan kaldırır. Bu sayede, `if` yapıları arasındaki ilişkiler netleşir ve her `else` ifadesinin hangi `then` ifadesiyle eşleşeceği kesin olarak belirlenir.

---

### **Genişletilmiş BNF (EBNF - Extended BNF)**

BNF (Backus-Naur Form) dili, bir dilin sözdizimini tanımlamada yaygın olarak kullanılan bir araçtır. Ancak BNF, bazı durumlarda karmaşık ve zor okunabilir hale gelebilir. Bu yüzden BNF'nin **Genişletilmiş** versiyonu olan **EBNF** (Extended BNF), okunabilirliği ve yazılabilirliği artırmak için bazı eklerle zenginleştirilmiştir. Ancak bu eklentiler, BNF'nin tanımlama gücünü doğrudan geliştirmez; sadece **okunabilirliği** ve **yazılabilirliği** artırmaya yöneliktir.

### **EBNF'nin Ekleri**

EBNF, çeşitli versiyonlarda bulunabilir ancak genel olarak üç önemli eklenti içerir:

1. **İsteğe bağlı öğeleri belirtmek için köşeli parantezler**:
    - Bir dilde bir öğenin isteğe bağlı olup olmadığını belirtmek için köşeli parantezler kullanılır. Bu, bir ifade içinde belirli bir kısmın yer alıp almamasını ifade eder.
    - Örnek: Bir `if-else` ifadesi şu şekilde tanımlanabilir:Burada, `else statement` isteğe bağlıdır. Köşeli parantezler olmadan, bu yapı şu iki kural ile açıklanmak zorunda kalır:
        
        ```r
        if_stmt → if (expression) statement [else statement]
        ```
        
        ```r
        if_stmt → if (expression) statement
        if_stmt → if (expression) statement else statement
        ```
        
2. **Sınırsız tekrar için süslü parantezler**:
    - Bir öğenin sıfır ya da daha fazla sayıda tekrar edebileceğini göstermek için süslü parantezler kullanılır. Bu, dilde **iterasyon** (tekrar) yapısını ifade eder ve özyineleme kullanmadan listeler oluşturmak için kullanılabilir.
    - Örnek: Virgülle ayrılmış bir tanımlayıcı listesi şu şekilde tanımlanabilir:Burada süslü parantezler, herhangi bir sayıda `identifier` öğesinin virgülle ayrılarak tekrarlanabileceğini belirtir. Bu, özyineleme yerine basit bir iterasyon biçimi sağlar.
        
        ```
        identifier_list → {identifier ,}
        ```
        
3. **Alternatif seçenekler için normal parantezler ve OR operatörü**:
    - Birden fazla seçeneğin bulunduğu durumlarda, seçim yapılacak öğeler normal parantezler içinde belirtilir ve aralarında OR (`|`) operatörü kullanılır.
    - Örnek: Bir ifade listesi için, şu seçenekler sunulabilir:Burada `expression`, ya `term` ya da `factor` olabilir.
        
        ```bash
        expression → (term | factor)
        ```
        

### **EBNF'deki Metasemboller**

EBNF'de üç tür parantez metasembol olarak kullanılır:

- **Köşeli parantezler** (`[]`): İsteğe bağlı ifadeleri gösterir. İfade varsa kullanılır, yoksa atlanır.
- **Süslü parantezler** (`{}`): İfade sıfır ya da daha fazla kez tekrar edilebilir.
- **Normal parantezler** (`()`): Seçenek sunar ve OR (`|`) operatörü ile bir grup içinden bir seçim yapılmasını sağlar.

Bu semboller dilde terminal semboller değildir; dilin gramer yapısını tanımlamaya yönelik araçlardır. Ancak, bu semboller bazen terminal sembol olarak da kullanılabilir. Eğer bu semboller terminal sembol olarak kullanılıyorsa, genellikle **altı çizilerek** ya da **tırnak işareti** içinde gösterilir.

### **Örnek EBNF Kullanımı**

Bir EBNF dilbilgisinde parantez ve çoklu seçimlerin nasıl kullanıldığını gösteren bir örnek şu şekilde olabilir:

```scss
stmt → if (logic_expr) then stmt [else stmt]
```

Burada `else stmt` kısmı isteğe bağlıdır ve köşeli parantezler kullanılarak belirtilmiştir. Aynı şekilde, alternatif seçeneklerin belirtildiği bir durumda normal parantezler ve OR operatörü kullanılabilir.

### **Gramerler ve Tanıyıcılar (Recognizers)**

Belirli bir dilin grameri, bu dil için bir **tanıyıcı** (recognizer) oluşturmak için kullanılabilir. Bir dilbilgisi verildiğinde, o dilbilgisinin oluşturduğu dili tanıyan bir tanıyıcı algoritma geliştirmek mümkündür. Bu tanıyıcılar, belirli bir dilin sözdizimi analizini gerçekleştirir.

Bu bağlamda, programlama dillerinin geliştirilmesi sırasında tanıyıcılar oldukça değerli araçlardır. Yeni bir dilin **derleyicisinin** (compiler) sözdizim analizini hızlı bir şekilde oluşturmak için kullanılan **yacc** gibi araçlar, programlama dillerinin gelişiminde önemli rol oynar.

- `Yacc`, "Yet Another Compiler Compiler" ifadesinin kısaltmasıdır ve bir sözdizimi üretici aracıdır. Bu tür sistemler, bir dilin gramerini kullanarak o dilin derleyici ya da yorumlayıcısının bir bölümünü hızlı bir şekilde oluşturmayı sağlar.

---