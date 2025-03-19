#include<stdio.h>

int main(void){
    int i = 1;
    int res = 0;
    while(i < 11){
        res = i * 5;
        printf("%d X 5 = %d\n", i, res);  // Use %d for integers
        i++;
    }
    return 0;
}
