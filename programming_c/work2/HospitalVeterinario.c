#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Register
{
    char nameofanimal[16];
    char nameofowner[16];
    char species[16];
    int age;
    char symptom[20];
    char diagnostic[40];
};

int main(){

struct Register pet;
int option = 0;

printf("===================== MENU ====================\n");
printf("----> (1)Cadastrar\n----> (2)Consultar\n----> (3)Alterar\n----> (4)Remover\n----> (5)Exibir\n");
printf("Digite o a opcao desejada: \n");

scanf("%d", &option);

if(option == 1){

    FILE *arq;
    arq = fopen("cadastrar.txt", "w");

    if(arq == NULL){

        printf("Erro ao cadastrar...\n");
        exit(1);
        
    }

    setbuf(arq, 0);

    printf("Digite o nome de seu pet: ");
    scanf("Nome: %s", pet.nameofanimal);
        fprintf(arq,"%s\n", pet.nameofanimal);

    printf("Digite o nome do dono: ");
    scanf("Dono: %s", pet.nameofowner);
        fprintf(arq,"%s\n", pet.nameofowner);

    printf("Digite a especie do seu pet: ");
    scanf("Especie: %s", pet.species);
        fprintf(arq,"%s\n", pet.species);
       
    printf("Digite a idade do seu pet: ");
    scanf("Idade: %d", &pet.age);
        fprintf(arq,"%d\n", pet.age);

    printf("Digite os sintomas do seu pet: ");
    scanf("Sintomas: %s", pet.symptom);
        fprintf(arq,"%s\n", pet.symptom);

    printf("Digite o diagnostico do seu pet: ");
    scanf("Diagnostico: %s", pet.diagnostic);
        fprintf(arq,"%s\n", pet.diagnostic);
 
    fclose(arq);
       
    }

}
