#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct 
{
    char nameofanimal[30];
    char nameofowner[30];
    char species[30];
    char symptom[30];
    char diagnostic[30];
    int age;
}pet;

int main(){

int option_access = 0;
int option_menu = 0;
FILE *file;

printf("  \n");
printf("========================+++++++++++++++++++++++========================\n");
printf("=======================+++ !!! BEM VINDO !!! +++=======================\n");
printf("========================+++++++++++++++++++++++========================\n");
printf("  \n");

printf("------------> Deseja acessar o menu? (1)Sim (-1)Nao: \n");
scanf("%d", &option_access);

system("cls");
    if(option_access == -1){

        printf("Ate mais!!!\n");
        exit(1);

    }

    else if(option_access == 1){
        
        do{

            printf("========================+++++++++++++++++++++++========================\n");
            printf("======================++++++ !!! MENU !!! +++++++======================\n");
            printf("========================+++++++++++++++++++++++========================\n");
            printf("  \n");

            printf("----> (1)Cadastrar\n----> (2)Consultar\n----> (3)Alterar\n----> (4)Remover\n----> (5)Exibir\n----> (6)Sair\n");
            printf("  \n");

            printf("------------> Digite o a opcao desejada: ");
            scanf("%d", &option_menu);

        
            system("cls");

                switch(option_menu){
                
                case 1:
                    register_pet();
                    break;
                
                case 2:
                    consult_pet();
                    break;

                case 3:
                    change_pet();
                    break;

                case 4:
                    remove_pet();
                    break;

                case 5:
                    display_pet();
                    break;

                case 6:

                    printf("========================+++++++++++++++++++++++========================\n");
                    printf("====================++++++ !!! ATE MAIS !!! +++++++====================\n");
                    printf("========================+++++++++++++++++++++++========================\n");
                    printf("  \n");
                    break;

                default:
                    printf("Voce digitou uma opcao invalida...\n");
                    printf("  \n");
                    break;

                }

            }while(option_menu != 6); 
        }
}

int register_pet(){

FILE *file;
char codigo[100];
char nameregister[100];

printf("============================ AREA DE REGISTRO ============================\n");
printf("  \n");

printf("------------>Digite o codigo de seu animal: ");
scanf("%s", &codigo);
sprintf(nameregister,"%s.txt", codigo);    

system("cls");

file = fopen(nameregister, "w");

    if(file == NULL){

        printf("Erro ao cadastrar...\n");
        printf(" \n");
        return 1;
                        
    }

setbuf(stdin, 0);
printf("Digite o nome de seu pet: ");
fgets(pet.nameofanimal, sizeof(pet.nameofanimal), stdin);

printf("Digite o nome do dono: ");
fgets(pet.nameofowner, sizeof(pet.nameofowner), stdin);

printf("Digite a especie do seu pet: ");
fgets(pet.species, sizeof(pet.species), stdin);

printf("Digite os sintomas do seu pet: ");
fgets(pet.symptom, sizeof(pet.symptom), stdin);

printf("Digite o diagnostico do seu pet: ");
fgets(pet.diagnostic, sizeof(pet.diagnostic), stdin);

printf("Digite a idade do seu pet: ");
scanf("%d", &pet.age);

int result = fprintf(file, "Nome:%sDono:%sEspecie:%sSintomas:%sDiagnostico:%sIdade:%d\n", pet.nameofanimal, pet.nameofowner, pet.species, pet.symptom, pet.diagnostic, pet.age);
    
    if(result < 0){

        printf("Erro ao cadastrar...\n");
        printf(" \n");

    }

fclose(file);

file = fopen("Cadastro.txt", "a");

    if(file == NULL){

        printf("Erro ao cadastrar...\n");
        printf(" \n");
        return 1;
                
    }

fprintf(file, "Cadastro%s\n", nameregister);

fclose(file);

system("cls");
return 0;

}

int consult_pet(){

FILE *file;
char codigo[100];
char nameregister[100];

printf("============================ AREA DE CONSULTA ============================\n");
printf("  \n");

printf("------------> Digite qual registro voce quer acessar: ");
printf("  \n");
scanf("%s", &codigo);

sprintf(nameregister,"%s.txt", codigo);

system("cls");

file = fopen(nameregister, "r");

    if(file == NULL){

        printf("Erro ao consultar...\n");
        printf(" \n");
        return(1);
        
    }

char r;

while ((r = fgetc(file)) != EOF) {

    printf("%c", r);
}
printf(" \n");

fclose(file);

return 0;

}

int change_pet(){

FILE *file;
char codigo[100];
char nameregister[100];

printf("============================ AREA DE ALTERACAO ============================\n");
printf("  \n");

printf("------------> Digite o codigo que deseja alterar: ");
scanf("%s", &codigo);
sprintf(nameregister,"%s.txt", codigo);

system("cls");

int verification = remove(nameregister);

    if(verification != 0){

        printf("Erro ao alterar o arquivo...\n");
        printf(" \n");
        return 1;
        
    }
            
file = fopen(nameregister, "w");

    if(file == NULL){

        printf("Erro ao cadastrar novo arquivo...\n");
        printf(" \n");
        return 1;
                        
    }

setbuf(stdin, 0);
printf("Digite o nome de seu pet: ");
fgets(pet.nameofanimal, sizeof(pet.nameofanimal), stdin);

printf("Digite o nome do dono: ");
fgets(pet.nameofowner, sizeof(pet.nameofowner), stdin);

printf("Digite a especie do seu pet: ");
fgets(pet.species, sizeof(pet.species), stdin);

printf("Digite os sintomas do seu pet: ");
fgets(pet.symptom, sizeof(pet.symptom), stdin);

printf("Digite o diagnostico do seu pet: ");
fgets(pet.diagnostic, sizeof(pet.diagnostic), stdin);

printf("Digite a idade do seu pet: ");
scanf("%d", &pet.age);

int result = fprintf(file, "Nome:%sDono:%sEspecie:%sSintomas:%sDiagnostico:%sIdade:%d\n", pet.nameofanimal, pet.nameofowner, pet.species, pet.symptom, pet.diagnostic, pet.age);
    
    if(result < 0){

        printf("Erro ao cadastrar novo arquivo...\n");
        printf(" \n");

        return 1;
        
    }

fclose(file);

system("cls");
return 0;

}

int remove_pet(){

char codigo[100];
char nameregister[100];
char nameregister2[100];

printf("============================ AREA DE REMOCAO ============================\n");
printf("  \n");

printf("------------> Digite o codigo que deseja remover: ");
scanf("%s", &codigo);
sprintf(nameregister,"%s.txt", codigo);

system("cls");

int verification = remove(nameregister);

    if(verification != 0){

        printf("Erro ao remover o arquivo...\n");
        printf(" \n");

        return 1;

    }

    system("cls");
    return 0;

}

int display_pet(){

FILE *file;

printf("============================ AREA DE EXIBICAO ============================\n");
printf("  \n");

file = fopen("Cadastro.txt", "r");

    if(file == NULL){

        printf("Erro a exibir arquivo...\n");
        printf(" \n");
        return 1;
                        
    }

char r;
    while ((r = fgetc(file)) != EOF) {

        printf("%c", r);
    }

    printf(" \n");
    
    fclose(file);

    return 0;

}
    

    

    
