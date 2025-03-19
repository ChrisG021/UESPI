#include <stdio.h>

int main(void) {
    int t;
    float sal;

    printf("Digite seu salario: ");
    scanf("%f",&sal);

    printf("Quanto tempo de empresa voce tem? ");
    scanf("%d",&t);

    if(t >= 5)
    {
        sal *= 1.20; 
    }else{
        sal *=1.10;
    }

    printf("PARABENS voce obteve um bonus por %d anos de contribuicao na empresa \n Novo salario R$%.2f",t,sal);

    return 0;
}
