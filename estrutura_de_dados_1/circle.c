#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "circle.h"

#define PI 3.14

Circle* createCircle(float x, float y, float radius) {
    Circle* circle = (Circle*)malloc(sizeof(Circle));

    if (circle == NULL) {
        printf("Erro ao alocar memória para o círculo.\n");
        exit(1);
    }

    circle->center.x = x;
    circle->center.y = y;
    circle->radius = radius;
    return circle;
}

float area(Circle* c) {
    return PI * (c->radius * c->radius);
}

void freeCircle(Circle* c) {
    if (c != NULL) {
        free(c);
        printf("MEMÓRIA LIBERADA\n");
    }
}

int validateInsertion(Circle* c, float x, float y) {
    float d = sqrt((x - c->center.x)*(x - c->center.x) + (y - c->center.y)*(y - c->center.y));

    if (d > c->radius) {
        return 1; // Fora do círculo
    } else if (d < c->radius) {
        return 2; // Dentro do círculo
    } else {
        return 0; // Na borda do círculo
    }
}
