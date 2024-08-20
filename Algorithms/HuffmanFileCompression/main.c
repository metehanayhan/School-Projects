//METEHAN AYHAN

/*input.txt dosyasýndan veriler okunur huffman algoritmasýna göre sýkýþtýrýlýr ve compress.txt adlý dosyanýn içine yazýlýr.. ,
daha sonra bu sýkýþýk dosya decode edilerek çözümlenir ve eski haline getirilip output.txt dosyasýna yazýlýr...*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100   // Maksimum Huffman agaci yuksekligi

// Huffman agaci icin min heap dügmü yapisi..
struct MinHeapNode
{
    char data; // Karakter verisi
    unsigned freq; // Karakterin frekansý
    struct MinHeapNode *left, *right; // Sol ve sað alt aðaçlarý gösteren iþaretçiler bunlar
};

// Min heap yapýsý
struct MinHeap
{
    unsigned size; // Min heap boyutu
    unsigned kapasite; // Min heap kapasitesi
    struct MinHeapNode **array; // Min heap dizisi
};

// Yeni bir min heap düðümü oluþturmak icin fonksiyon
struct MinHeapNode* newNode(char data, unsigned freq)
{
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// Yeni bir min heap oluþturma fonksiyonu
struct MinHeap* createMinHeap(unsigned kapasite)
{
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->kapasite = kapasite;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->kapasite * sizeof(struct MinHeapNode*));
    return minHeap;
}

// Ýki min heap düðümünün yerini deðiþtiriyoruz..
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
    struct MinHeapNode* t = *a;

    *a = *b;
    *b = t;
}

// Min heap'i yeniden düzenler
void minHeapify(struct MinHeap* minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    // Sol çocuk düðümü en küçükse
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

// Sað çocuk düðümü en küçükse
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

// Kök düðüm en küçük deðilse
    if (smallest != idx)
    {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Min heap boyutunu kontrol eder
int isSizeOne(struct MinHeap* minHeap)
{
    return (minHeap->size == 1);
}

// Min heap'ten en küçük elemaný çýkarýr
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
    // Min heap'te sadece bir eleman varsa
    struct MinHeapNode* temp = minHeap->array[0];
    // Min heap'in son elemanýný kök düðümü yap
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    // Min heap'i yeniden düzenle
    minHeapify(minHeap, 0);
    return temp;
}

// Min heap'e yeni bir düðüm ekler
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode)
{
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq)
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// Min heap'i oluþturur ve yapýlandýrýr
void buildMinHeap(struct MinHeap* minHeap)
{
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// Diziyi ekrana yazdýrýr
void printArr(int arr[], int n)
{
    int i;
    // Diziyi ekrana yazdýr
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}

// Bir düðümün yaprak olup olmadýðýný kontrol eder
int isLeaf(struct MinHeapNode* root)
{
    return !(root->left) && !(root->right);
}

// Min heap oluþturur ve yapýlandýrýr
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size)
{
    struct MinHeap* minHeap = createMinHeap(size);

// Min heap dizisine düðümleri ekle
    for (int i = 0; i < size; ++i)
        // Yeni bir düðüm oluþtur ve min heap'e ekle
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}


// Huffman aðacýný oluþturur
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size)
{
    // Yeni bir iç düðüm oluþturur
    struct MinHeapNode *left, *right, *top;

    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
    // Min heap'te sadece bir düðüm kalana kadar
    while (!isSizeOne(minHeap))
    {
        left = extractMin(minHeap); // En küçük frekansa sahip düðümü çýkar
        right = extractMin(minHeap);

        top = newNode('$', left->freq + right->freq); // Yeni bir iç düðüm oluþturur
        top->left = left; // En küçük iki frekansý içeren düðümleri sol ve sað alt aðaç yap
        top->right = right;
        insertMinHeap(minHeap, top); // Yeni düðümü min heap'e ekle
    }

    return extractMin(minHeap);
}



void printCodes(struct MinHeapNode* root, int arr[], int top)
{
// Huffman kodlarýný ekrana yazdýrýr
    if (root->left)   // Sol alt aðacý ziyaret et
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right)   // Sað alt aðacý ziyaret et
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (isLeaf(root))   // Eðer yaprak düðümse, karakteri ve kodu yazdýr
    {
        printf("%c: ", root->data);
        printArr(arr, top);
    }
}

// Huffman kodlarýný ekrana yazdýrýr
void HuffmanCodes(char data[], int freq[], int size)   // Huffman aðacýný oluþtur
{
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);

    int arr[MAX_TREE_HT], top = 0; // Huffman kodlarýný ekrana yazdýr

    printCodes(root, arr, top); // Huffman aðacýný serbest býrak
}

// Huffman kodlarýný dosyaya yazdýrýr
void printCodesToFile(struct MinHeapNode* root, int arr[], int top, FILE* file)
{
    if (root->left)   // Sol alt aðacý ziyaret et
    {
        arr[top] = 0;
        printCodesToFile(root->left, arr, top + 1, file);
    }

    if (root->right)   // Sað alt aðacý ziyaret et
    {
        arr[top] = 1;
        printCodesToFile(root->right, arr, top + 1, file);
    }

    if (isLeaf(root))   // Eðer yaprak düðümse, karakteri ve kodu yazdýr
    {
        fprintf(file, "%c: ", root->data);
        for (int i = 0; i < top; ++i)
            fprintf(file, "%d", arr[i]);
        fprintf(file, "\n");
    }
}

// Huffman kodlarýný dosyaya yazdýrýr
void HuffmanCodesToFile(char data[], int freq[], int size)
{
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size); // Huffman aðacýný oluþtur

    int arr[MAX_TREE_HT], top = 0;

    // Huffman kodlarýný dosyaya yazdýr
    FILE *file = fopen("compress.txt", "wt");
    if (file == NULL)
    {
        printf("Dosya açýlamadý.\n");
        return;
    }
    // Huffman kodlarýný dosyaya yazdýr
    printCodesToFile(root, arr, top, file);
    fclose(file);
}

// Huffman kodlarýný dosyadan okur
typedef struct
{
    char character;
    char code[10];
} HuffmanCode;

HuffmanCode* readHuffmanCodes(char* filename, int* size)
{
    FILE* file = fopen(filename, "rt");
    if (file == NULL)
    {
        printf("%s dosyasý açýlamadý.\n", filename);
        return NULL;
    }

    // Kodlar için bellekte yer ayýr
    HuffmanCode* codes = malloc(sizeof(HuffmanCode) * 256);
    *size = 0;

    // Dosyadan kodlarý oku
    while (fscanf(file, "%c: %s\n", &codes[*size].character, codes[*size].code) != EOF)
    {
        (*size)++;
    }

    // Dosyayý kapat
    fclose(file);

    return codes;
}

// Kod dizisini karaktere çevirir
char decodeCharacter(HuffmanCode* codes, int size, char* code)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(codes[i].code, code) == 0)
        {
            return codes[i].character;
        }
    }


    return '\0';  // Eðer kod çözümlenemezse, NULL karakter döndür
}

// Kodlarý dosyadan oku ve çöz
void decodeAndWriteToFile(HuffmanCode* codes, int size, char* filename)
{
    FILE* inputFile = fopen(filename, "rt");
    // Dosya açýlamazsa hata mesajý yazdýr ve fonksiyondan çýk
    if (inputFile == NULL)
    {
        printf("%s dosyasý açýlamadý.\n", filename);
        return;
    }

    // Dosyayý yazmak için açýyoruz
    FILE* outputFile = fopen("output.txt", "wt");
    if (outputFile == NULL)
    {
        printf("output.txt dosyasý açýlamadý.\n");
        return;
    }

// Kodlarý oku ve çöz

    char code[10];
    while (fscanf(inputFile, "%s\n", code) != EOF)
    {
        char character = decodeCharacter(codes, size, code);
        if (character != '\0')    // Eðer kod çözümlenebildiyse, karakteri dosyaya yaz
        {
            fprintf(outputFile, "%c", character);
        }
    }

    fclose(inputFile);
    fclose(outputFile);
}

// Preorder sýralamasýný yazdýrýr
void printPreorder(struct MinHeapNode* node)
{
    if (node == NULL)
        return;

    // kök düðümü ve frekansý yazdýr
    printf("%c(%u) ", node->data, node->freq);

    // sol alt aðacý ziyaret et
    printPreorder(node->left);

    // sað alt aðacý ziyaret et
    printPreorder(node->right);
}


// Ana fonksiyon
int main()
{

    // Karakterler ve frekanslarý
    char arr[256];
    int freq[256];
    int size = 0;

    // Dosyayý aç
    FILE *file = fopen("input.txt", "rt");
    if (file == NULL)
    {
        printf("Dosya acilamadi..\n");
        return 1;
    }

    // Karakterleri ve frekanslarý hesapla
    int c;
    while ((c = fgetc(file)) != EOF)
    {
        int found = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == c)
            {
                freq[i]++;
                found = 1;
                break;
            }
        }
        if (!found)
        {
            arr[size] = c;
            freq[size] = 1;
            size++;
        }
    }
    fclose(file);

    // Frekanslara göre Huffman aðacýný yeniden oluþtur
    struct MinHeapNode* root = buildHuffmanTree(arr, freq, size);

    // Preorder sýralamasýný yazdýr
    printf("Frekansa gore Preorder siralamasi: ");
    printPreorder(root);
    printf("\n");
    printf("Huffman kodlari dosyaya yazildi.\n");
    printf("Huffman kodlari dosyadan okunup cozuldu ve output.txt dosyasina yazildi.\n");
    printf("--------------------------------------------\n");
    printf("Not: input.txt icinde ALGORITHMS yaziyor..");
    printf("Her karaktere karsilik gelen bit dizileri:\n");


    // Huffman kodlarýný dosyaya yaz
    HuffmanCodesToFile(arr, freq, size);

    // Huffman kodlarýný dosyadan oku ve çöz
    int huffSize;
    HuffmanCode* codes = readHuffmanCodes("compress.txt", &huffSize);

    if (codes != NULL)
    {
        decodeAndWriteToFile(codes, huffSize, "compress.txt");
        free(codes);
    }

    // Huffman kodlarýný ekrana yaz
    HuffmanCodes(arr, freq, size);
    printf("--------------------------------------------\n");

    return 0;
}
