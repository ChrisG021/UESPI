#include<stdio.h>

int main(void){
    int i = 1;
    int num ;
    int res = 0;

    /*Input do usuario*/
    printf("Digite o numero desejado:");scanf("%d",&num);

    /*geração das linhas */
    while(i < 11){
        res = i * num;
        printf("%d X %d = %d\n", i, num, res);  // Use %d for integers
        i++;
    }
    return 0;
}
