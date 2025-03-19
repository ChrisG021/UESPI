#include <stdio.h>

int main(void) {
    int n[] = {5, 12, 23, 34, 45, 56, 67, 78, 89, 90, 
               21, 32, 43, 54, 65, 76, 87, 98, 11, 22};
    int i = 0;
    int mai, men;
    float ave = 0;  // Inicializando a variável

    mai = men = n[0];

    do {
        if (n[i] > mai) {
            mai = n[i];
        }
        if (n[i] < men) {
            men = n[i];
        }
        ave += n[i];
        i++;
    } while (i < 20);  // Corrigido para 20 elementos

    ave = ave / 20; // Calcular a média corretamente

    printf("Maior numero: %d\n", mai);
    printf("Menor numero: %d\n", men);
    printf("Media: %.2f\n", ave);  // %.2f para exibir duas casas decimais

    return 0;
}
