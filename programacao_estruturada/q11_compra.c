#include <stdio.h>

int main(void) {
    double price;
    int parc;
    char op;

    // Solicita o valor da compra
    printf("Valor da compra: ");
    scanf("%lf", &price);

    // Pergunta se a compra será parcelada ou à vista
    printf("Parcelado ou à vista?[p/a]: ");
    scanf(" %c", &op); // O espaço antes de %c é para evitar o problema do '\n' residual

    if (op == 'a') {
        // Se for à vista, o valor não altera
        printf("Valor a ser pago: R$%.2f\n", price);
    } else {
        // Se for parcelado, pergunta o número de parcelas
        printf("Quantas parcelas?\nObs: min 2, max 6 parcelas com juros: ");
        scanf("%d", &parc);

        // Verifica o número de parcelas e aplica os juros
        switch (parc) {
            case 2:
                price *= 1.1; // Juros de 10% para 2 parcelas
                break;
            case 3:
                price *= 1.2; // Juros de 20% para 3 parcelas
                break;
            case 4:
            case 5:
            case 6:
                price *= 1.3; // Juros de 30% para 4 a 6 parcelas
                break;
            default:
                printf("ERRO: Número de parcelas inválido. O número de parcelas deve ser entre 2 e 6.\n");
                return 1; // Encerra o programa em caso de erro
        }

        // Exibe o valor parcelado com juros
        printf("Valor parcelado com juros: R$%.2f\n", price);
    }

    return 0;
}
