#include <stdio.h>

int main(void) {
    float salmin, sal, count_s, vale_t; 

    printf("Digite o salario minimo atual: ");
    scanf("%f", &salmin);

    printf("Digite o seu salario: ");
    scanf("%f", &sal);

    count_s = sal / salmin;      // Quantidade de salários mínimos recebidos
    vale_t = salmin * 0.08;      // Vale-transporte (8% do salário mínimo)

    printf("O usuario ganha %.2f salario(s) minimo(s) com vale de R$%.2f", count_s, vale_t);

    return 0;
}
