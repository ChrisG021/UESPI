#include<stdio.h>
struct cad_func
{
    float sal;
    int cargo;
};


int main(void){
    struct cad_func func;
    float sal_a;
    
    printf("Digite seu salario: ");scanf("%f",&func.sal);
    printf("Digite o codigo do cargo: ");scanf("%d",&func.cargo);

    sal_a = func.sal;

    switch (func.cargo)
    {
    case 101:
        func.sal *= 1.10;
        break;
    case 102:
        func.sal *=1.20;
        break;
    default:
        func.sal *=1.40;
        break;
    }

    printf("salario novo R$%.2f \n salario antigo R$%.2f \n Diferenca de salario R$%.2f",func.sal,sal_a, func.sal-sal_a);

}