// Neste código, os dados dos funcionários são guardados em uma estrutura de Lista Encadeada.
#include <stdio.h>
#include <stdlib.h>
int ID = 1;
int amount = 0;

typedef struct FUNC{
    
    int ID;
    int age;
    float salary;
    struct FUNC* nextFunc;
    
}functionary;



 functionary* newFunctionary() {

int age;
float salary;


printf("Digite sua idade: \n");
scanf("%d", &age);

printf("Digite seu salário: \n");
scanf("%f", &salary);
 printf("------------------------------\n");

functionary* novo = (functionary *) malloc (sizeof(functionary));

novo->ID = ID;
novo-> age = age;
novo->salary = salary;
novo->nextFunc = NULL;

ID++;
amount++;
return novo;
}

int isVoid(functionary* LISTA){
    int opc = (LISTA->nextFunc) == NULL ? 1 : 0;
    
    return opc;
}

void putOnEnding(functionary* LISTA) {

functionary* novo = newFunctionary();

functionary* tmp = LISTA;

while(tmp->nextFunc != NULL) {
tmp = tmp->nextFunc;
}
tmp->nextFunc = novo;
}

 void putNewHead(functionary* LISTA) {

functionary* novo = newFunctionary();

if (LISTA->nextFunc == NULL){
    LISTA->nextFunc = novo;
} else {

functionary* tmp;

tmp = LISTA->nextFunc;
LISTA->nextFunc = novo;
novo->nextFunc = tmp;

}

} 


void printAll( functionary* LIST){
    
if(isVoid(LIST)){
    printf("Lista vazia! Adicione funcionários! \n");
    printf("------------------------------\n");
} else {

printf("FUNCIONÁRIOS DA EMPRESA: \n");
int count;
functionary* tmp = LIST->nextFunc;

for (count = 1; count <= amount; count++){

printf("%d - ID: %d, Idade: %d, Salário: %.3f \n", count, tmp->ID, tmp->age, tmp->salary);

tmp = tmp->nextFunc;
}
printf("------------------------------\n");
} 

}

void removeFirst(functionary* LISTA){
    functionary* tmp = LISTA->nextFunc;
    LISTA->nextFunc = tmp->nextFunc;
    free(tmp);
    
    amount--;
}

void removeLast (functionary* LISTA){
    functionary* penultimo = LISTA->nextFunc;
    functionary* ultimo = penultimo->nextFunc;
    
    while(ultimo->nextFunc != NULL){
        penultimo = penultimo->nextFunc;
        ultimo = ultimo->nextFunc;
    }
    penultimo->nextFunc = NULL;
    free(ultimo);
    amount--;
}

void putItem(functionary* LISTA){
    
    if(isVoid(LISTA)){
        printf("Lista vazia, adicione o primeiro item: \n");
        putNewHead(LISTA);
    } else {
    functionary* novo = newFunctionary();
    functionary* tmp = LISTA->nextFunc;
    functionary* tmp_storage;
    int func, i;
    
    do{
    printf("Deseja adicionar um item em qual posição?");
    scanf("%d", &func);
    if ((func > amount+1) || (func < 1))
    printf("Valor fora da Lista, por favor escolha um novo.");
    } while((func > amount+1)||(func < 1));
    
    
    for(i = 1; i < func-1; i++){
        tmp = tmp->nextFunc;
    }
    
    tmp_storage = tmp->nextFunc;
    tmp->nextFunc = novo;
    novo->nextFunc = tmp_storage;
     printf("------------------------------\n");
    } 
}

void removeItemById(functionary* LISTA){
    
    if(isVoid(LISTA)){
        printf("Lista vazia! \n");
    } else {
    functionary* tmp = LISTA->nextFunc;
    functionary* tmp_storage = LISTA;
    int id_to_remove;
    
    printf("Deseja eliminar da lista o usuário com qual ID?");
    scanf("%d", &id_to_remove);
    printf("------------------------------\n");
    
     
    while(tmp->ID != id_to_remove){
        tmp = tmp->nextFunc;
        tmp_storage = tmp;
    }
    
    if(tmp->ID != id_to_remove){
        printf("ID não encontrado no sistema.\n");
    } else {
    
    tmp_storage->nextFunc = tmp->nextFunc;
    free(tmp);
    amount--;
    } 
    printf("------------------------------\n");
    }
    
}

void removeItemByIndex(functionary* LISTA){
    if(isVoid(LISTA)){
        printf("Lista vazia! \n");
        printf("------------------------------\n");
        
    } else {
    functionary* tmp = LISTA->nextFunc;
    functionary* tmp_storage;
    int index_to_remove, i;
    
    printf("Deseja eliminar da lista o usuário com qual index?");
    scanf("%d", &index_to_remove);
    
    for (i = 1; i < index_to_remove-1; i++){
        tmp = tmp->nextFunc;
    }
    
    tmp_storage = tmp->nextFunc;
    tmp->nextFunc = tmp_storage->nextFunc;
    free(tmp_storage);
    amount--;
    }
    
}

void printFunctionaryById(functionary* LISTA){
    functionary* tmp = LISTA->nextFunc;
    if (tmp == NULL) {
        printf("Adicione funcionários antes!");
    } else {
    int whichId;
    
    printf("Digite o ID do funcionário: ");
    scanf("%d", &whichId);
    
    while((tmp->ID != whichId) && (tmp->nextFunc != NULL)){
        tmp = tmp->nextFunc;
    }
    
    if(tmp->ID == whichId){
        printf("ID do funcionário: %d \n Idade: %d \n Salário: %.3f", tmp->ID, tmp->age, tmp->salary);
        printf("------------------------------\n");
    } else {
        printf ("ID não encontrado no sistema. \n");
        printf("------------------------------\n");
    }
    
    }
    
    
}

void menu(functionary* LISTA) {

int opt = 1;

printf("SISTEMA DE FUNCIONÁRIOS \n");
printf("------------------------------\n");

do {

printf("Que operação deseja realizar?\n");
printf("|1 - Ver Lista de Funcionários\n|2 - adicionar funcionário no início da Lista \n|3 - adicionar funcionário no fim da Lista \n|4 - adicionar funcionário em uma posição específica da Lista \n|5 - remover funcionário do início da Lista \n|6 - remover funcionário do fim da Lista \n|7 - remover funcionário pelo ID \n|8 - remover funcionário pela posição da lista \n|9 - ver funcionário em específico \n|0 - sair do programa\n");

scanf("%d", &opt);

printf("------------------------------\n");

switch(opt) {

case 0:

printf("Volte sempre!");
break;

case 1: 
        printAll(LISTA);
        break;
case 2:
         putNewHead(LISTA);
         break;
case 3:
         putOnEnding(LISTA);
         break;
case 4:
        putItem(LISTA);
        break;
case 5:
        removeFirst(LISTA);
        break;
case 6:
        removeLast(LISTA);
        break;
case 7:
        removeItemById(LISTA);
        break;
case 8: 
        removeItemByIndex(LISTA);
        break;
case 9:
        printFunctionaryById(LISTA);
        break;
default:
       printf("opção inválida, digite novamente.\n");
       
          

}

}while(opt);


}

int main() {

functionary* LIST;

LIST->nextFunc = NULL;

menu(LIST);

return 0;
}
