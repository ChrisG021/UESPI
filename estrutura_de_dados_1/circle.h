#ifndef CIRCLE_H
#define CIRCLE_H

// Estrutura que representa um ponto no plano cartesiano
typedef struct Point {
    float x, y;
} Point;

// Estrutura que representa um círculo
typedef struct Circle {
    Point center;
    float radius;
} Circle;

// Cria um novo círculo com centro (x, y) e raio informado
Circle* createCircle(float x, float y, float radius);

// Libera a memória alocada para o círculo
void freeCircle(Circle* c);

// Retorna a área do círculo
float area(Circle* c);

// Valida se um ponto (x, y) está:
//   - fora do círculo (retorna 1),
//   - dentro do círculo (retorna 2),
//   - ou na borda do círculo (retorna 0)
int validateInsertion(Circle* c, float x, float y);

#endif
