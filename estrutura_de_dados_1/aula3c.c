#include<stdio.h>

int main(void){
    int n[]={5, 12, 23, 34, 45, 56, 67, 78, 89, 90, 
        21, 32, 43, 54, 65, 76, 87, 98, 11, 22};
    int i;
    int mai,men;
    float ave;
    mai= men = n[0];

    for(i = 0; i<20; i++){
        /*Fun*/
        if (n[i]> mai){
            mai = n[i];
        }
        if(n[i]<men){
            men = n[i];
        }
        ave +=n[i];
    } 

    printf("maior numero: %d",mai);
    printf("\nmenor numero: %d",men);

    ave = ave/20;
    printf("\nMedia: %d",ave);

    return 0;
}
