#include <stdio.h>
#include <stdlib.h>
 
 /* AMAÇ : Ýkili aðaçta iyi düðümleri sayan programý oluþturmak. Burada iyi düðümden kasýt, kökten herhangi bir x düðümüne gidilen yolda eðer x'ten büyük bir deðer yoksa x iyi düðüm olarak adlandýrýlýr.
 Bu kod, tanýma göre iyi düðümleri bulmak ve onlarýn sayýsýný hesaplamak için oluþturulmuþtur.*/

struct node{ // ikili aðaç düðümlerini ve verilerini tanýmladým.
 int data;
 struct node*left;
 struct node*right;
};

typedef struct node tree;//struct node tipinden oluþan bir tree yapýsý tanýmladým.
//Ýçerisinde veri tutan data deðiþkeni, adres bilgisi tutan left ve right isimli iki iþaretçisi bulunmaktadýr
 tree* olustur(int data) { //ikili aðacýn düðümlerini oluþturmasýný saðlayan fonksiyonu tanýmladým.
  tree *newNode = (tree*)malloc(sizeof(struct node));  // Bellekten yeterli miktarda yer ayýrmasýný saðladým.
  newNode -> data = data;  // Düðümün verisini atadým.
  newNode -> left = NULL;  // Yeni düðümün alt düðümlerini null olarak ayarladým.
  newNode -> right = NULL;
 return newNode;   // Oluþturulan yeni düðüm geri döndürülüyor
 }

 // Ýkili aðaçta iyi düðüm sayýsýný hesaplayan ve bu iyi düðümlerin hangileri olduðunu ekrana yazdýran fonksiyonu tanýmladým.
 int iyiDugumleriSay(tree* root, int maxDugum) {
    if (root == NULL) {   // Eðer aðacýn kökü null ise iyi düðüm sayýsý 0 olarak döndürülür
        return 0;
    }
    int iyiDugumSayisi = 0; // iyi düðümlerin sayýsýný tutmasý için bir sayaç tanýmladým.
    if (root->data >= maxDugum) {  // Eðer düðümün deðeri, önceki maksimum deðerden büyükse bu bir iyi düðümdür.
        iyiDugumSayisi++;   // iyi düðüm sayýsý bir artýrýlýr.
        printf("%d ", root->data);   // Düðümün deðeri ekrana yazdýrýlýr.
        maxDugum = root->data;  // Düðümün deðeri yeni maksimum olarak atanýr.
    }
    iyiDugumSayisi += iyiDugumleriSay(root->left, maxDugum);  // Sol ve sað alt aðaçlar da taranarak iyi düðümlerin sayýsýný hesaplatýp sayaçla birleþtirmesini saðladým.
    iyiDugumSayisi += iyiDugumleriSay(root->right, maxDugum);
    return iyiDugumSayisi; // Ýyi düðümlerin sayýsý geri döndürülür.
 }

int main()
 {
     // Yeni bir aðaç oluþturup ve verilerini atadým.
    tree* root = olustur(5);
    root->left = olustur(3);
    root->right = olustur(10);
    root->left->left = olustur(20);
    root->left->right = olustur(21);
    root->right->left = olustur(1);
    root->right->right = olustur(6);

    printf("Iyi Dugumler : "); // iyi düðümlerin deðerlerini ekrana yazdýrdým.
    int iyiDugumSayisi = iyiDugumleriSay(root, root->data);  // Ýyi düðümlerin sayýsýný hesaplatýp ekrana yazdýrmasýný saðladým.
    printf("\n\nBu ikili agacta bulunan iyi dugum sayisi: %d \n", iyiDugumSayisi);
    
    /*Ýyi düðüm olarak 5 20 21 ve 10 deðerlerini ekrana yazacak.
	5  => Kök olarak oluþturdum ve kendisinden önce herhangi bir deðer bulunmaz. Yani kendisinden önce büyük bir deðer olamayacaðý için iyi düðüm olarak kabul edilmiþtir.
	20 => 5->3->20 yolu izlenerek 20 sayýsýna ulaþýlýr ve kendisinden önceki hiçbir deðer ondan büyük olmadýðý için iyi düðüm olarak kabul edilmiþtir.
	21 => 5->3->21 yolu izlenerek 21 sayýsýna ulaþýlýr ve kendisinden önceki hiçbir deðer ondan büyük olmadýðý için iyi düðüm olarak kabul edilmiþtir.
	10 => 5->10 yolu izlenerek 10 sayýsýna ulaþýlýr ve kendisinden önceki hiçbir deðer ondan büyük olmadýðý için iyi düðüm olarak kabul edilmiþtir.
	3  => 5->3 yolu izlenerek 3 sayýsýna ulaþýlýr ve kendisinden önceki (5) düðümü ondan büyük olduðu için iyi düðüm olarak kabul edilemez.
	1  => 5->10->1 yolu izlenerek 1 sayýsýna ulaþýlýr ve kendisinden önceki (5 ve 10) düðümü ondan büyük olduðu için iyi düðüm olarak kabul edilemez.
	6  => 5->10->6 yolu izlenerek 6 sayýsýna ulaþýlýr ve kendisinden önceki (10) düðümü ondan büyük olduðu için iyi düðüm olarak kabul edilemez.
	*/

 return 0;
 }

