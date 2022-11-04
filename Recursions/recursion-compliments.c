#include <stdio.h>
#include <stdlib.h>

// Reversing a word using recursion

int toplam = 0;
int toplam2 = 0;
int toplam3 = 0;

void reverse_word(char* kelime){

    if(*kelime == '\0'){
        return;
    }

    toplam2++;
    reverse_word(kelime+1);
    printf("%c",*kelime);
}

int cift_topla(int x){

    if(x == 0){
        return 0;
    }
    return x + cift_topla(x-2);
}


int f(int x){

    if(x == 1 || x == 2){
        return 1;
    }
    toplam++;
    return f(x-1) + f(x-2); // Son olarak yine bu deger bize döneceğinden toplamımız bu olacak.
}

int factoriyel(int x){

    if(x == 1){
        return 1;
    }
    toplam3++;
    return x*factoriyel(x-1);
}

int main(){

    char* m = "\nibrahim";
    reverse_word(m);

    printf("deger: %d\n",f(6));
    printf("ilk fonk. %d kere calisti.\n",toplam2);
    printf("Bu fonksiyon %d kere calisti.\n",toplam);
    int deger  = factoriyel(5);
    printf("fact(5) = %d ,Ucuncu fonk %d kere calisti.\n",deger,toplam3);

    int cift_toplam = cift_topla(10);
    printf("Cift(10) = %d",cift_toplam);

    return 0;
}
