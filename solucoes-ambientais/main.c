#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//registro das industrias
typedef struct{
    char nome[151];
    char cpf[15];
    char rg[20];
    char nomeEmpresa[50];
    char cnpj[19];
    char dataAbertura[11];
    char rua[101];
    char numero[11];
    char bairro[51];
    char cidade[51];
    char estado[3];
    char cep[10];
    char email[101];
    char telefone[16];
}industria;

//corpo principal
int main(){
    setlocale(LC_ALL, "Portuguese");
    int escolha = 1;

    //tela inicial (após cadastro)
    printf("--------------------------------------\n");
    printf("             TELA INICIAL               \n");
    printf("--------------------------------------\n");
    printf("1. Ver dados das indústrias\n");
    printf("2. Cadastrar uma nova indústria\n");
    printf("3. Atualizar dados mensais de resíduos\n");
    printf("4. Gerar relatórios\n");
    printf("5. Sair\n");

    while(escolha){
        printf("Escolha uma opção: ");
        int opcao;
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                //ver dados das indústrias
                break;
            case 2:
                //cadastrar uma nova indústria
                break;
            case 3:
                //atualizar dados mensais de resíduos
                break;
            case 4:
                //gerar relatórios
                break;
            case 5:
                //sair
                break;
        }
    }
    return 0;
}
