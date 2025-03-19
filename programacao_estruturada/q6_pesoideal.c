#include <stdio.h>

int main(void) {
    float h, res;
    char op;

    // Solicita o gênero do usuário
    printf("Selecione seu gênero: [m/f] ");
    scanf(" %c", &op);  // Adiciona um espaço antes de %c para limpar o buffer de entrada, evitar que seja lido pelo compilador

    // Solicita a altura do usuário
    printf("Insira sua altura: ");
    scanf("%f", &h);

    // Calcula o peso ideal com base no gênero
    switch (op) {
        case 'm':
        case 'M':
            res = (62.1 * h) - 44.7;  // Fórmula para homens
            printf("Valor ideal de peso: %.2f\n", res);
            break;
        case 'f':
        case 'F':
            res = (72.7 * h) - 58;  // Fórmula para mulheres
            printf("Valor ideal de peso: %.2f\n", res);
            break;
        default:
            printf("ERRO NOS DADOS FORNECIDOS\n");  // Caso o gênero não seja válido
            break;
    }

    return 0;
}
