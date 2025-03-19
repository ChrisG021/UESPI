#include <stdio.h>

// Estrutura para armazenar dados do funcionário
struct pessoa {
    char* nome;  // Nome do funcionário
    float sal;   // Salário bruto
};

int main(void) {
    struct pessoa pessoa;  // Declara a variável 'pessoa'
    float sal_liq;          // Salário líquido após o desconto

    // Solicita o nome do funcionário
    printf("Nome do funcionário: ");
    scanf("%s", pessoa.nome);//n usar pointer para char* vulgo str

    // Solicita o salário bruto
    printf("Salario bruto: ");
    scanf("%f", &pessoa.sal);

    // Calcula o salário líquido (desconto de 10%)
    sal_liq = pessoa.sal * 0.9;

    // Exibe o nome e o salário líquido
    printf("O funcionario %s recebe: R$%.2f\n", pessoa.nome, sal_liq);

    return 0;
}
