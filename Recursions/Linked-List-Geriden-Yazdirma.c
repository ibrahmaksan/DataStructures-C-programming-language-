#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int x;
    struct n* next;

}Node;

int main(){

    Node* root = (Node*) malloc(sizeof(Node));

    root->x = 10;
    root->next = (Node*) malloc(sizeof(Node));

    root->next->x = 20;
    root->next->next = (Node*) malloc(sizeof(Node));

    root->next->next->x = 30;
    root->next->next->next = NULL;

    oku(root);
    return 0;
}


void oku(Node* root){

    if(root == NULL){
        return; // böyle de null döner;
    }

    else{
        oku(root->next);
        printf("buradyim/n");
        printf("Deger: %d\n",root->x);
    }
}
