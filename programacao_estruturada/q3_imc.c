#include <stdio.h>

int main(void) {
    float w,h,imc;

    printf("insira seu peso: ");
    scanf("%f",&w);

    printf("Insira sua altura: ");
    scanf("%f",&h);

    imc = (w)/(h*h);
    
    if(imc < 20)
    {
        printf("Abaixo do peso");
    }else if (imc <= 25)
    {
        printf("Peso normal");
    }else if (imc <= 30)
    {
        printf("sobrepeso");
    }else if(imc <= 40)
    {
        printf("Obeso");
    }else
    {
        printf("Obeso morbido");
    }
    
    

    return 0;
}
