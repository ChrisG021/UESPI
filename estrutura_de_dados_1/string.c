#include<stdio.h>
#include<stdlib.h>
typedef struct{
    char*  name;
    char  sex;
}Person;
void gerarRg(Person *p,int cpf);
int main(){ 
    Person *person;
    person = (Person*)malloc(sizeof(Person));//alocação dinamica 
    person->name = "Felipe";//person.name 
    person->sex = 'f';//person.sex se n fosse ponteiro

    gerarRg(person,999383);
    
    return 0;
}

void gerarRg(Person *p,int cpf){
    //lembrar de usar -> para puxar  atributo de um ponteiro de struct
    printf("Nome: %s\nSexo: %c\nCPF: %d",p->name,p->sex,cpf);
}