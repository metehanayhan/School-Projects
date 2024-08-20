//METEHAN AYHAN

/*input.txt dosyas�ndan veriler okunur huffman algoritmas�na g�re s�k��t�r�l�r ve compress.txt adl� dosyan�n i�ine yaz�l�r.. ,
daha sonra bu s�k���k dosya decode edilerek ��z�mlenir ve eski haline getirilip output.txt dosyas�na yaz�l�r...*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100   // Maksimum Huffman agaci yuksekligi

// Huffman agaci icin min heap d�gm� yapisi..
struct MinHeapNode
{
    char data; // Karakter verisi
    unsigned freq; // Karakterin frekans�
    struct MinHeapNode *left, *right; // Sol ve sa� alt a�a�lar� g�steren i�aret�iler bunlar
};

// Min heap yap�s�
struct MinHeap
{
    unsigned size; // Min heap boyutu
    unsigned kapasite; // Min heap kapasitesi
    struct MinHeapNode **array; // Min heap dizisi
};

// Yeni bir min heap d���m� olu�turmak icin fonksiyon
struct MinHeapNode* newNode(char data, unsigned freq)
{
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// Yeni bir min heap olu�turma fonksiyonu
struct MinHeap* createMinHeap(unsigned kapasite)
{
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->kapasite = kapasite;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->kapasite * sizeof(struct MinHeapNode*));
    return minHeap;
}

// �ki min heap d���m�n�n yerini de�i�tiriyoruz..
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
    struct MinHeapNode* t = *a;

    *a = *b;
    *b = t;
}

// Min heap'i yeniden d�zenler
void minHeapify(struct MinHeap* minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    // Sol �ocuk d���m� en k���kse
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

// Sa� �ocuk d���m� en k���kse
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

// K�k d���m en k���k de�ilse
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

// Min heap'ten en k���k eleman� ��kar�r
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
    // Min heap'te sadece bir eleman varsa
    struct MinHeapNode* temp = minHeap->array[0];
    // Min heap'in son eleman�n� k�k d���m� yap
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    // Min heap'i yeniden d�zenle
    minHeapify(minHeap, 0);
    return temp;
}

// Min heap'e yeni bir d���m ekler
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

// Min heap'i olu�turur ve yap�land�r�r
void buildMinHeap(struct MinHeap* minHeap)
{
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// Diziyi ekrana yazd�r�r
void printArr(int arr[], int n)
{
    int i;
    // Diziyi ekrana yazd�r
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}

// Bir d���m�n yaprak olup olmad���n� kontrol eder
int isLeaf(struct MinHeapNode* root)
{
    return !(root->left) && !(root->right);
}

// Min heap olu�turur ve yap�land�r�r
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size)
{
    struct MinHeap* minHeap = createMinHeap(size);

// Min heap dizisine d���mleri ekle
    for (int i = 0; i < size; ++i)
        // Yeni bir d���m olu�tur ve min heap'e ekle
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}


// Huffman a�ac�n� olu�turur
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size)
{
    // Yeni bir i� d���m olu�turur
    struct MinHeapNode *left, *right, *top;

    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
    // Min heap'te sadece bir d���m kalana kadar
    while (!isSizeOne(minHeap))
    {
        left = extractMin(minHeap); // En k���k frekansa sahip d���m� ��kar
        right = extractMin(minHeap);

        top = newNode('$', left->freq + right->freq); // Yeni bir i� d���m olu�turur
        top->left = left; // En k���k iki frekans� i�eren d���mleri sol ve sa� alt a�a� yap
        top->right = right;
        insertMinHeap(minHeap, top); // Yeni d���m� min heap'e ekle
    }

    return extractMin(minHeap);
}



void printCodes(struct MinHeapNode* root, int arr[], int top)
{
// Huffman kodlar�n� ekrana yazd�r�r
    if (root->left)   // Sol alt a�ac� ziyaret et
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right)   // Sa� alt a�ac� ziyaret et
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (isLeaf(root))   // E�er yaprak d���mse, karakteri ve kodu yazd�r
    {
        printf("%c: ", root->data);
        printArr(arr, top);
    }
}

// Huffman kodlar�n� ekrana yazd�r�r
void HuffmanCodes(char data[], int freq[], int size)   // Huffman a�ac�n� olu�tur
{
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);

    int arr[MAX_TREE_HT], top = 0; // Huffman kodlar�n� ekrana yazd�r

    printCodes(root, arr, top); // Huffman a�ac�n� serbest b�rak
}

// Huffman kodlar�n� dosyaya yazd�r�r
void printCodesToFile(struct MinHeapNode* root, int arr[], int top, FILE* file)
{
    if (root->left)   // Sol alt a�ac� ziyaret et
    {
        arr[top] = 0;
        printCodesToFile(root->left, arr, top + 1, file);
    }

    if (root->right)   // Sa� alt a�ac� ziyaret et
    {
        arr[top] = 1;
        printCodesToFile(root->right, arr, top + 1, file);
    }

    if (isLeaf(root))   // E�er yaprak d���mse, karakteri ve kodu yazd�r
    {
        fprintf(file, "%c: ", root->data);
        for (int i = 0; i < top; ++i)
            fprintf(file, "%d", arr[i]);
        fprintf(file, "\n");
    }
}

// Huffman kodlar�n� dosyaya yazd�r�r
void HuffmanCodesToFile(char data[], int freq[], int size)
{
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size); // Huffman a�ac�n� olu�tur

    int arr[MAX_TREE_HT], top = 0;

    // Huffman kodlar�n� dosyaya yazd�r
    FILE *file = fopen("compress.txt", "wt");
    if (file == NULL)
    {
        printf("Dosya a��lamad�.\n");
        return;
    }
    // Huffman kodlar�n� dosyaya yazd�r
    printCodesToFile(root, arr, top, file);
    fclose(file);
}

// Huffman kodlar�n� dosyadan okur
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
        printf("%s dosyas� a��lamad�.\n", filename);
        return NULL;
    }

    // Kodlar i�in bellekte yer ay�r
    HuffmanCode* codes = malloc(sizeof(HuffmanCode) * 256);
    *size = 0;

    // Dosyadan kodlar� oku
    while (fscanf(file, "%c: %s\n", &codes[*size].character, codes[*size].code) != EOF)
    {
        (*size)++;
    }

    // Dosyay� kapat
    fclose(file);

    return codes;
}

// Kod dizisini karaktere �evirir
char decodeCharacter(HuffmanCode* codes, int size, char* code)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(codes[i].code, code) == 0)
        {
            return codes[i].character;
        }
    }


    return '\0';  // E�er kod ��z�mlenemezse, NULL karakter d�nd�r
}

// Kodlar� dosyadan oku ve ��z
void decodeAndWriteToFile(HuffmanCode* codes, int size, char* filename)
{
    FILE* inputFile = fopen(filename, "rt");
    // Dosya a��lamazsa hata mesaj� yazd�r ve fonksiyondan ��k
    if (inputFile == NULL)
    {
        printf("%s dosyas� a��lamad�.\n", filename);
        return;
    }

    // Dosyay� yazmak i�in a��yoruz
    FILE* outputFile = fopen("output.txt", "wt");
    if (outputFile == NULL)
    {
        printf("output.txt dosyas� a��lamad�.\n");
        return;
    }

// Kodlar� oku ve ��z

    char code[10];
    while (fscanf(inputFile, "%s\n", code) != EOF)
    {
        char character = decodeCharacter(codes, size, code);
        if (character != '\0')    // E�er kod ��z�mlenebildiyse, karakteri dosyaya yaz
        {
            fprintf(outputFile, "%c", character);
        }
    }

    fclose(inputFile);
    fclose(outputFile);
}

// Preorder s�ralamas�n� yazd�r�r
void printPreorder(struct MinHeapNode* node)
{
    if (node == NULL)
        return;

    // k�k d���m� ve frekans� yazd�r
    printf("%c(%u) ", node->data, node->freq);

    // sol alt a�ac� ziyaret et
    printPreorder(node->left);

    // sa� alt a�ac� ziyaret et
    printPreorder(node->right);
}


// Ana fonksiyon
int main()
{

    // Karakterler ve frekanslar�
    char arr[256];
    int freq[256];
    int size = 0;

    // Dosyay� a�
    FILE *file = fopen("input.txt", "rt");
    if (file == NULL)
    {
        printf("Dosya acilamadi..\n");
        return 1;
    }

    // Karakterleri ve frekanslar� hesapla
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

    // Frekanslara g�re Huffman a�ac�n� yeniden olu�tur
    struct MinHeapNode* root = buildHuffmanTree(arr, freq, size);

    // Preorder s�ralamas�n� yazd�r
    printf("Frekansa gore Preorder siralamasi: ");
    printPreorder(root);
    printf("\n");
    printf("Huffman kodlari dosyaya yazildi.\n");
    printf("Huffman kodlari dosyadan okunup cozuldu ve output.txt dosyasina yazildi.\n");
    printf("--------------------------------------------\n");
    printf("Not: input.txt icinde ALGORITHMS yaziyor..");
    printf("Her karaktere karsilik gelen bit dizileri:\n");


    // Huffman kodlar�n� dosyaya yaz
    HuffmanCodesToFile(arr, freq, size);

    // Huffman kodlar�n� dosyadan oku ve ��z
    int huffSize;
    HuffmanCode* codes = readHuffmanCodes("compress.txt", &huffSize);

    if (codes != NULL)
    {
        decodeAndWriteToFile(codes, huffSize, "compress.txt");
        free(codes);
    }

    // Huffman kodlar�n� ekrana yaz
    HuffmanCodes(arr, freq, size);
    printf("--------------------------------------------\n");

    return 0;
}
