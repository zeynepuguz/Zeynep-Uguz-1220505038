# Zeynep-Uguz-1220505038
 

## İkili Ağaçta İyi Düğümlerin Sayısını Bulan Program


**Programın Amacı**

Bu program, bir ikili ağaçta kökten herhangi bir x düğümüne gidilen yolda eğer x'ten büyük bir değer yoksa x iyi düğüm olarak adlandırılır ve bu iyi düğümleri bulmak ve saymak için oluşturulmuştur.


**Kullanılan Dil ve Araçlar**

Bu program C dilinde yazılmıştır. Ayrıca programın doğru çalışması için studio.h ve stdlib.h kütüphaneleri kullanılmıştır.


**Nasıl Kullanılır**

Programı çalıştırmak için, kodun main dosyasını derleyin ve oluşan programı çalıştırın. Program çalıştığında, bir ikili ağaç oluşturulacak ve iyi düğümlerin sayısını hesaplayacaktır.


**Nasıl Çalışır**

Program, öncelikle "node" adında bir yapı tanımlıyor, bu yapı bir ikili ağaç düğümünü temsil ediyor ve verileri ve işaretçileri içeriyor. Daha sonra, "tree" adında bir "node" yapısından oluşan bir ağaç yapısı tanımlanıyor.

Bir "olustur" fonksiyonu, bir düğümü oluşturmak için kullanılır. Bu fonksiyon, bellekten yeterli miktarda yer ayırır, yeni düğümün verisini ve alt düğümlerini ayarlar, ve son olarak oluşturulan yeni düğümü geri döndürür.

Ana fonksiyon, bir ağaç oluşturur ve verilerini atar. Daha sonra, "iyiDugumleriSay" fonksiyonu kullanılarak, ağaçtaki iyi düğümlerin sayısı hesaplanır ve ekrana yazdırılır.

"iyiDugumleriSay" fonksiyonu, ağacın kökü ve önceki maksimum düğüm değeri (ilk başta, bu kökün verisi olarak ayarlanır) alır. Eğer kök null ise, iyi düğüm sayısı 0 olarak döndürülür. Aksi takdirde, iyi düğüm sayısını tutmak için bir sayaç oluşturulur. Eğer kökün değeri önceki maksimum değerden büyükse, bu bir iyi düğümdür ve sayaç bir artırılır ve düğümün değeri ekrana yazdırılır. Ardından, düğümün sol ve sağ alt ağaçları da taranarak iyi düğümlerin sayısı hesaplanır ve sayaçla birleştirilir. Son olarak, iyi düğüm sayısı geri döndürülür.

Sonuç olarak, program, verilen ikili ağaçta bulunan iyi düğümlerin sayısını hesaplar ve ekrana yazdırır.

**Kullanılan Yapılar**

Programda, ikili ağaç yapısını oluşturmak için aşağıdaki yapı kullanılmıştır:

`struct node {
  int data;
  struct node* left;
  struct node* right;
};`

Ayrıca, ağaç yapısını daha iyi kullanmak için typedef kullanılmıştır:

`typedef struct node tree;`

**Örnekler**

Aşağıdaki gibi bir ikili ağaç düşünüldüğünde:

![image](https://user-images.githubusercontent.com/122873468/230490654-ac7efe70-b490-4cdd-80cf-6f2aee14aca6.png)


Bu ikili ağaçta iyi düğümler 5, 20, 21, ve 10 olacaktır. Program bu iyi düğümleri ekrana yazdıracak ve toplam iyi düğüm sayısını hesaplayıp ekrana yazdıracaktır.
