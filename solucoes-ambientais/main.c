#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    //suporte acentua��o
    setlocale(LC_ALL, "Portuguese");

    int escolha = 1;

    //registro das industrias
    typedef struct{
        char nome[50];
        char cpf[15];
        char rg[20];
        char nomeEmpresa[50];
        char cnpj[19];
        char razaoSocial[151];
        char dataAbertura[11];
        char rua[101];
        char numero[11];
        char bairro[51];
        char cidade[51];
        char estado[3];
        char cep[10];
    }industria;

    //tela inicial (ap�s cadastro)
    printf("--------------------------------------\n");
    printf("             TELA INICIAL               \n");
    printf("--------------------------------------\n");
    printf("1. ver dados das ind�strias\n");
    printf("2. cadastrar uma nova ind�stria\n");
    printf("3. atualizar dados mensais de res�duos\n");
    printf("4. gerar relat�rios\n");
    printf("5. sair\n");

    while(escolha){
        printf("Escolha uma op��o: ");
        int opcao;
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                //ver dados das ind�strias
                break;
            case 2:
                //cadastrar uma nova ind�stria
                break;
            case 3:
                //atualizar dados mensais de res�duos
                break;
            case 4:
                //gerar relat�rios
                break;
            case 5:
                //sair
                break;
        }
    }



    return 0;
}
