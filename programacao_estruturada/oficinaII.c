#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int age;
    char name[100];
} Person;

int countAges(Person persons[]);

int main(void){
    Person persons[10];

    for (int i = 0; i < 10; i++) {
        printf("Digite o nome da pessoa: \n");
        scanf(" %s", persons[i].name);  

        printf("Digite a idade: \n");
        scanf("%d", &persons[i].age);
    }

    int count = countAges(persons);

    if (count >= 6) {
        printf("grupo predominante de adultos\n");
    } else if (count == 5) {
        printf("grupo em equilibrio de adultos e menores\n");
    } else {
        printf("grupo predominante de menores\n");
    }

    return 0;
}

int countAges(Person persons[]) {
    int count = 0;

    for (int i = 0; i < 10; i++) {
        if (persons[i].age >= 18) {
            count++;
        }
    }

    return count;   
}
