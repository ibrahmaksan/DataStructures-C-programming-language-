#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


typedef struct n{
    int x;
    struct n* next;
}NODE;

void araya_ekle(NODE*,int,int);
void olustur(NODE*,int);
void oku(NODE*);

int main(){

    NODE* root = (NODE*) malloc(sizeof(NODE));
    int v_count;
    printf("How many elements do you want to store ? : ");
    scanf("%d",&v_count);

    olustur(root,v_count);

    int n_variable;
    printf("Which integer value do you want to store ? : ");
    scanf("%d",&n_variable);
    int indis;
    printf("Which index ? :");
    scanf("%d",&indis);

    araya_ekle(root,indis,n_variable);

    printf("Values: \n");
    oku(root);

}

olustur(NODE* root, int eleman_sayisi){

        NODE* iter = root;
        root->x = 10;

        for(int i = 0; i<eleman_sayisi; i++){

            iter->next = (NODE*)malloc(sizeof(NODE));
            iter->next->x = (i+2)*10;
            iter = iter->next;
        }
        iter->next = NULL; // bunu yapmamız gerek çünkü çoğu compilerda aslında NULL olması gerekirken bizim compiler buraya ramde rastgele bir
        // adres veriyor. Elle atama yapmamız gerekiyor yani.
}

oku(NODE* root){

    NODE* iter = root;
    int i = 1;

    while(iter->next != NULL){
        printf("%d. Element : %d\n",i,iter->x);
        iter = iter->next;
        Sleep(500);
        i++;
    }
}

araya_ekle(NODE* root, int eleman_sira,int sayi){

       NODE* temp = (NODE*) malloc(sizeof(NODE));
       NODE* iter = root;

       for(int i = 0; i<eleman_sira-1;i++){ // -2 koymamın sebebi verilen degerle uyuşmasını saglamak.
            iter = iter->next;
       }

        temp->next = iter->next;// olusturdugum bos kutunun next degeri iterin gosterdiği kutunun adresinin nextinin gosterdiği deger olsun.
        temp->x = sayi;
        iter->next = temp; // iter in next degeri de tempin adresini gostersin ki sıra bozulmasın.
}
