#include<stdio.h>

int main(void){
    float temp;

    printf("Digite a temperatura em ºC: \n");
    scanf("%g",&temp);

    if(temp >= 30){
        printf("Ta quente");
    } else{
        if(temp > 20){
            printf("Ta agradavel");
        }else{
            printf("Ta frio");
        };
    };
    return 0;
}