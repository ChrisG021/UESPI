#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "circle.h"

int main(void){
    Circle* c = createCircle(10,10,6);
    printf("area do circulo: %.2f\n",area(c));
    float x = 2;
    float y = 5;
    int vInsertion = validateInsertion(c,x,y);
    printf("Teste de insercao do ponto (%.f,%.f)\n",x,y);
    switch (vInsertion)
    {
    case 0 :
        printf("Ponto inserido na circunferencia.\n");
        break;
    case 1 :
        printf("Ponto inserido fora.\n");
        break;
    case 2 :
        printf("Ponto inserido dentro.\n");
        break;
    default:
        break;
    }

    freeCircle(c);
    return 0;

}b