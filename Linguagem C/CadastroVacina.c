#include<stdio.h>
#include<stdlib.h>
#include<string.h> 


struct cadastroStruct {
    char nome[50];
    char cpf[50];
    char vacina[50];
    char lote[50];
    char data[50];
    
};

struct cadastroStruct cadastro[1];
int indexRegister = 0;

void cleanStdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
    fflush(stdin);
}

void lista() {
    for (int i = 0; i < indexRegister; i++) {
        printf("---------------------\n");
        printf("Nome: %s\n", cadastro[i].nome);
        printf("CPF: %s\n", cadastro[i].cpf);
        printf("Vacina: %s\n", cadastro[i].vacina);
        printf("Lote: %s\n", cadastro[i].lote );
        printf("Data : %s\n", cadastro[i].data);
         printf("---------------------\n");
    }
    getchar();
}

void cadastroPessoa(){
    int op = 1;
    do{
        printf("\nDigite o nome: ");
        scanf("%15[^\n]", cadastro[indexRegister].nome);
         cleanStdin();

        printf("\nDigite o CPF: ");
        scanf("%15[^\n]", cadastro[indexRegister].cpf);
         cleanStdin();

        printf("\nDigite a vacina: ");
        scanf("%15[^\n]", cadastro[indexRegister].vacina);
         cleanStdin();

        printf("\nDigite o lote: ");
        scanf("%15[^\n]", cadastro[indexRegister].lote);
         cleanStdin();

        printf("\nDigite a data (formato dd/mm/aaaa): ");
        scanf("%15[^\n]", cadastro[indexRegister].data);
         cleanStdin();

        indexRegister = indexRegister + 1;

        printf("\nDigite 1 para continuar ou outro valor para sair: ");
        scanf("%d",&op);

        cleanStdin();
    }while(op==1);
}

void pesquisarCadastro() {
    int op;
    char pesquisa[15];
    do {        
        printf("\nDigite o CPF: ");
        scanf("%s", &pesquisa);
        cleanStdin();
        for(int i = 0; i < indexRegister; i++){
            if(strcmp(cadastro[i].cpf, pesquisa) == 0)
            {
                printf("---------------------\n");
                printf("\nNome: %s\n", cadastro[i].nome);
                printf("CPF: %s\n", cadastro[i].cpf);
                printf("Vacina: %s\n", cadastro[i].vacina);
                printf("Lote: %s\n", cadastro[i].lote);
                printf("Data: %s\n", cadastro[i].data);
                printf("---------------------\n");
            }
            break;
        }
        printf("\nDigite 1 para continuar pesquisando ou tecle ENTER para sair: ");
     scanf("%d", &op);
    cleanStdin();
    }while(op==1);
    
}

int main (void) {
    int op;
    do{
        system("cls");
        printf("\n----Menu----\n1 - Cadastrar\n2 - Listar Todos\n3 - Pesquisar\n4 - Sair\n------------\n");
        scanf("%d", &op);
        cleanStdin();

        switch(op){
            case 1:
                cadastroPessoa();
                break;
            case 2:
                lista();
                cleanStdin();
                break;
            case 3:
                pesquisarCadastro();
                cleanStdin();
                break; 
            case 4:
                system("exit");
                break;
            default:
                printf("Opção inválida.");
                cleanStdin();
                break;
        }
    }while(op!=4);

    return 0;
}