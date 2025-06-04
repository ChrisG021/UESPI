#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

/**
 * @brief Estrutura de um nó da lista encadeada.
 *
 * Cada nó armazena um inteiro (`info`) e um ponteiro para o próximo nó
 * (`prox`).  O último nó da lista deve ter `prox == NULL`.
 */
typedef struct List {
    int          info;  ///< Valor armazenado no nó
    struct List *prox;  ///< Próximo nó da lista (ou NULL)
} List;

/**
 * @brief Cria uma lista vazia.
 *
 * @return Ponteiro NULL, representando lista vazia.
 *
 * @note Não há alocação dinâmica aqui; a função apenas devolve NULL
 *       para sinalizar que a lista ainda não possui nós.
 */
List *list_init(void);

/**
 * @brief Insere um novo valor no início da lista.
 *
 * @param l Lista original (pode ser NULL).
 * @param i Valor inteiro a ser armazenado.
 *
 * @return Ponteiro para a nova cabeça da lista.
 *
 * @warning A função aloca memória com `malloc`.  Certifique-se de
 *          liberar toda a lista com `free` (ou função equivalente)
 *          quando ela não for mais necessária para evitar *memory leak*.
 */
List *list_insert(List *l, int i);

/**
 * @brief Imprime todos os elementos da lista, um por linha.
 *
 * @param list Cabeça da lista (pode ser NULL).
 *
 */
void list_print( List *list);

/**
 * @brief Verifica se a lista está vazia.
 *
 * @param list Cabeça da lista.
 * @return `true` se `list == NULL`, caso contrário `false`.
 */
int list_empty( List *list);

/**
 * @brief Procura o primeiro nó que contenha o valor @p v.
 *
 * @param list Cabeça da lista.
 * @param v    Valor a ser procurado.
 *
 * @return Ponteiro para o nó encontrado ou NULL se não existir.
 */
List *list_search(List *list, int v);
/**
 *  @brief Procura o primeiro nó que contenha o valor @p v e retira.
 * 
 *  @param list Cabeça da lista
 *  @param v    valor a ser procurado
 * 
 *  @return Ponteiro para o nó sem o elemento ou ,caso não encontre, a lista sem alteração
 */
List *list_pop(List *list, int v);

/** 
 *  @brief Libera o espaço da memoria de todos os elementos da lista
 * 
 *  @param list Cabeça da lista
 * 
 *  @return Sem retorno
 */
void list_free(List *list);
#endif /* LIST_H */
