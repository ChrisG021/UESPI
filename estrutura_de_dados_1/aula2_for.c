#include<stdio.h>
int fact();
int main(void){
    int n,f;
    
    do{
        printf("Digite um numero inteiro positivo: ");
        scanf("%d",&n);
    }while(n<0);
    f = fact(n);
    printf("O resultado de %d! : %lu",n,f);


    return 0;
}

int fact(int n){

    unsigned long int f = 1;
    int k;

    for(k=1; k<=n ;k++ ){
        f*=k;
    }
    return f;
}