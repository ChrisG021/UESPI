#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definir a estrutura para o ponto
typedef struct {
    int x, y;
} Point;

// Definir a estrutura para o círculo
typedef struct {
    float radius;
    Point* center; // Posição do centro
} Circle;

// Função para calcular a área do círculo
float calcularArea(Circle* circle);
int validarInsercao(Circle* c,Point* p);
float PI = 3.141592;

int main() {
    // Alocar memória para o círculo
    Point *p = (Point*)malloc(sizeof(Point));
    Circle* circle = (Circle*)malloc(sizeof(Circle));
    
    if (circle == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Alocar memória para o centro
    circle->center = (Point*)malloc(sizeof(Point));
    
    if (circle->center == NULL) {
        printf("Erro ao alocar memória para o centro.\n");
        free(circle); 
        return 1; 
    }

    // Solicitar entrada do usuário
    printf("Digite valor do raio: ");
    scanf("%f", &circle->radius);

    printf("Digite a coordenada x do centro: ");
    scanf("%d", &circle->center->x);

    printf("Digite a coordenada y do centro: ");
    scanf("%d", &circle->center->y);

    printf("Digite a coordenada x  do ponto a ser inserido: ");
    scanf("%d",&p->x);

    printf("Digite a coordenada y  do ponto a ser inserido: ");
    scanf("%d",&p->y);
    // Calcular a área do círculo
    float areaCircle = calcularArea(circle);
    
    // Imprimir a área
    printf("Area do circulo: %.2f\n", areaCircle);
    printf("Cordenada do centro:\n x = %d\n y = %d\n",circle->center->x,circle->center->y);
    int res = validarInsercao(circle,p);
    switch(res){
        case 1:
            printf("Ponto fora do circulo");
            break;
        case 2:
            printf("Ponto dentro do circulo");
            break;
        case 0:
            printf("Ponto em cima da circunferencia");
            break;
        
    }

    free(circle->center);
    free(circle);

    return 0;
}

int validarInsercao(Circle* c,Point* p){
    //a formula que vou usar , pitagoras
    //d^2 = (xp-xc)2 - (yp-yc)2
    float d = sqrt((p->x - c->center->x)*(p->x - c->center->x) - (p->y - c->center->y)*(p->y - c->center->y));
    // printf("%f",d);//test
    if(d > c->radius){
        return 1;
    }else if(d < c->radius){
        return 2;
    }else{
        return 0;
}
}
float calcularArea(Circle* c){
    return PI * c->radius * c->radius;
}
