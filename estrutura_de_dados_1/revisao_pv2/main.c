#include<stdio.h>
#include<stdlib.h>
#include"list.c"

int main(void){
    List* list;
    list = list_init();
    list = list_insert(list,23);
    list = list_insert(list,95);
    list = list_insert(list,10);
    list = list_insert(list,15);
    list = list_insert(list,67);

    //se voce notar, a ordem é o ultimo que entra é o primeiro que sai
    //tanto que na impressão ele vai 45 45 23 nao 23 95 45 sacou?
    list_print(list);
    //se tiver vazia 1, senao 0 
    // cond ? true : false
    printf("\n%s", list_empty(list) ? "Lista vazia" : "Lista com valores inseridos");//utilizei operador ternário

    List* aux = list_search(list,10);
    list_print(aux);
    
    list = list_pop(list,95);
    list_print(list);


    list_free(list);
    return 0;
}