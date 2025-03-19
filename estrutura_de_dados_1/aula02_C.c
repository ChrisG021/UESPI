#include<stdio.h>

int main(void){
    int f,k,n;

    printf("Digite um número inteiro: ");
    scanf("%d",&n);
    f = 1;
    k = 1;
    /*calculando fatorial */
    while(1){
        if(k <= n){
            f*=k;
            k++;
        }else{
            break;
        }
    }      
    printf("Resultado de %d! : %d",n,f);

    return 0;
}

