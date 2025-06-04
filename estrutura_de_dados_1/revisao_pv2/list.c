#include "list.h"
#include <stdlib.h>
#include <stdio.h>


List *list_init(void)
{
    return NULL;
}

List* list_insert(List *l,int i){
    List* aux =(List *)malloc(sizeof(List)); 
    aux->info = i;
    aux->prox = l;
    return aux;
}

void list_print(List* list){
    List * aux;
    // aux vai ser uma copia de list, que percorrera todas as posições da lista
    printf("\n===============LISTA===============\n");
    for ( aux=list; aux!=NULL; aux = aux->prox)
    {
       printf("info:%d\n",aux->info);
    }
    printf("===================================\n");
    free(aux);
}

int list_empty(List* list){
    return (list==NULL);
}

List* list_search(List* list, int v){
    List* aux;
    for (aux = list; aux!=NULL; aux = aux->prox)
    {
        if (aux->info == v)
        {
           return aux;
        }
        
    }
    free(aux);
    return NULL;
}

List * list_pop(List* list,int v){
    List* ant = NULL;
    List* aux = list;

    while (aux!= NULL && aux->info !=v)
    {
        ant  = aux;
        aux = aux->prox;
    }

    /*
        verificando agora
    */
   if (aux == NULL)return list;
    //Não achou o elemento
    
    if(ant == NULL){
        /* retira o elemento do inicio */
        list = aux->prox;
    }else{/* retira o elemento no meio da lista */
        ant->prox = aux->prox;
   }
   free(aux);
   return list;
}

void list_free(List *list){
    List* aux = list;
    while (aux!= NULL)
    {
        List * t = aux->prox; // guarda a referencia
        free(aux);  //libera 
        aux = t;    //faz aux apontar pra referencia armazenada
    }
    printf("MEMORIA LIBERADA!!!!!!!!!!!!");
}