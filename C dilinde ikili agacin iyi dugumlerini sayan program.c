#include <stdio.h>
#include <stdlib.h>
 
 /* AMA� : �kili a�a�ta iyi d���mleri sayan program� olu�turmak. Burada iyi d���mden kas�t, k�kten herhangi bir x d���m�ne gidilen yolda e�er x'ten b�y�k bir de�er yoksa x iyi d���m olarak adland�r�l�r.
 Bu kod, tan�ma g�re iyi d���mleri bulmak ve onlar�n say�s�n� hesaplamak i�in olu�turulmu�tur.*/

struct node{ // ikili a�a� d���mlerini ve verilerini tan�mlad�m.
 int data;
 struct node*left;
 struct node*right;
};

typedef struct node tree;//struct node tipinden olu�an bir tree yap�s� tan�mlad�m.
//��erisinde veri tutan data de�i�keni, adres bilgisi tutan left ve right isimli iki i�aret�isi bulunmaktad�r
 tree* olustur(int data) { //ikili a�ac�n d���mlerini olu�turmas�n� sa�layan fonksiyonu tan�mlad�m.
  tree *newNode = (tree*)malloc(sizeof(struct node));  // Bellekten yeterli miktarda yer ay�rmas�n� sa�lad�m.
  newNode -> data = data;  // D���m�n verisini atad�m.
  newNode -> left = NULL;  // Yeni d���m�n alt d���mlerini null olarak ayarlad�m.
  newNode -> right = NULL;
 return newNode;   // Olu�turulan yeni d���m geri d�nd�r�l�yor
 }

 // �kili a�a�ta iyi d���m say�s�n� hesaplayan ve bu iyi d���mlerin hangileri oldu�unu ekrana yazd�ran fonksiyonu tan�mlad�m.
 int iyiDugumleriSay(tree* root, int maxDugum) {
    if (root == NULL) {   // E�er a�ac�n k�k� null ise iyi d���m say�s� 0 olarak d�nd�r�l�r
        return 0;
    }
    int iyiDugumSayisi = 0; // iyi d���mlerin say�s�n� tutmas� i�in bir saya� tan�mlad�m.
    if (root->data >= maxDugum) {  // E�er d���m�n de�eri, �nceki maksimum de�erden b�y�kse bu bir iyi d���md�r.
        iyiDugumSayisi++;   // iyi d���m say�s� bir art�r�l�r.
        printf("%d ", root->data);   // D���m�n de�eri ekrana yazd�r�l�r.
        maxDugum = root->data;  // D���m�n de�eri yeni maksimum olarak atan�r.
    }
    iyiDugumSayisi += iyiDugumleriSay(root->left, maxDugum);  // Sol ve sa� alt a�a�lar da taranarak iyi d���mlerin say�s�n� hesaplat�p saya�la birle�tirmesini sa�lad�m.
    iyiDugumSayisi += iyiDugumleriSay(root->right, maxDugum);
    return iyiDugumSayisi; // �yi d���mlerin say�s� geri d�nd�r�l�r.
 }

int main()
 {
     // Yeni bir a�a� olu�turup ve verilerini atad�m.
    tree* root = olustur(5);
    root->left = olustur(3);
    root->right = olustur(10);
    root->left->left = olustur(20);
    root->left->right = olustur(21);
    root->right->left = olustur(1);
    root->right->right = olustur(6);

    printf("Iyi Dugumler : "); // iyi d���mlerin de�erlerini ekrana yazd�rd�m.
    int iyiDugumSayisi = iyiDugumleriSay(root, root->data);  // �yi d���mlerin say�s�n� hesaplat�p ekrana yazd�rmas�n� sa�lad�m.
    printf("\n\nBu ikili agacta bulunan iyi dugum sayisi: %d \n", iyiDugumSayisi);
    
    /*�yi d���m olarak 5 20 21 ve 10 de�erlerini ekrana yazacak.
	5  => K�k olarak olu�turdum ve kendisinden �nce herhangi bir de�er bulunmaz. Yani kendisinden �nce b�y�k bir de�er olamayaca�� i�in iyi d���m olarak kabul edilmi�tir.
	20 => 5->3->20 yolu izlenerek 20 say�s�na ula��l�r ve kendisinden �nceki hi�bir de�er ondan b�y�k olmad��� i�in iyi d���m olarak kabul edilmi�tir.
	21 => 5->3->21 yolu izlenerek 21 say�s�na ula��l�r ve kendisinden �nceki hi�bir de�er ondan b�y�k olmad��� i�in iyi d���m olarak kabul edilmi�tir.
	10 => 5->10 yolu izlenerek 10 say�s�na ula��l�r ve kendisinden �nceki hi�bir de�er ondan b�y�k olmad��� i�in iyi d���m olarak kabul edilmi�tir.
	3  => 5->3 yolu izlenerek 3 say�s�na ula��l�r ve kendisinden �nceki (5) d���m� ondan b�y�k oldu�u i�in iyi d���m olarak kabul edilemez.
	1  => 5->10->1 yolu izlenerek 1 say�s�na ula��l�r ve kendisinden �nceki (5 ve 10) d���m� ondan b�y�k oldu�u i�in iyi d���m olarak kabul edilemez.
	6  => 5->10->6 yolu izlenerek 6 say�s�na ula��l�r ve kendisinden �nceki (10) d���m� ondan b�y�k oldu�u i�in iyi d���m olarak kabul edilemez.
	*/

 return 0;
 }

