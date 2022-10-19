#include <stdio.h>
#include <stdlib.h>

struct n{

        int x;
        struct n* next; // daha yeni oluşturduğumuz bir veri tipi oldugundan struct koymak gerekiyor bir isim alana kadar.

    };

typedef struct n node;


struct k{

        int x;
        struct k* next; // daha yeni oluşturduğumuz bir veri tipi oldugundan struct koymak gerekiyor bir isim alana kadar.

    };

typedef struct k dugum;


void olustur(dugum* root,int deger){

    dugum* iter = root;

    for(int i = 0; i<deger;i++){

        iter->next= (dugum*) malloc(sizeof(dugum)); // iterin nextinin gösterdiği yere bir tane daha veri ekleyecek.
        iter->next->x = 100*(i+1);
        iter = iter->next;
    }
}

void oku(dugum* root,int deger){
        int i = 1,j = 0;
        while(j<deger){

            printf("%d . eleman : %d\n",i,root->x);
            root = root->next; 
            j++;
            i++;
        }
}

int main(){

        /* node* root;

        root = (node*) malloc(sizeof(node));
        root ->x = 10;
        root -> next = (node*) malloc(sizeof(node));
        root->next->x = 20;
        root ->next->next = (node*) malloc(sizeof(node));

        root ->next->next->x = 30;
        node* iter = root;

        for(int i = 0; i<3;i++){

            printf("%d inci eleman : %d\n",i,iter->x);
            iter = iter->next;
        } */

        // Şimdide yaptigimiz islemi bir de fonksiyonla yapalım.
        // Hem degerleri fonksiyonla olusturalim hem de okumayı fonksiyonla olusturalım.


        dugum* kok = (dugum*)malloc(sizeof(dugum));
        kok->x =0;

        printf("%u\n",kok);
        olustur(kok,5);
        oku(kok,5);
        printf("\n%u",kok);

    return 0;
}
