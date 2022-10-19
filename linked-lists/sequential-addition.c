#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


typedef struct n{
    int x;
    struct n* next;
}NODE;

void sirali_ekle(NODE*,int);
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

    sirali_ekle(root,n_variable);



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

sirali_ekle(NODE* root, int eleman){

    NODE* temp = (NODE*) malloc(sizeof(NODE));
    temp->x = eleman;
    NODE* iter = root;

    while(1){

        if(iter->next->x>eleman){

            temp->next = iter->next;
            iter->next = temp;
            return;
        }

        iter = iter->next;
    }

}
