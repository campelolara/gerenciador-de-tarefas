#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char nome_responsavel[50];
    char nome_empresa[50];
    char cnpj[14];
    char razao_social[50];
    char nome_fantasia[50];
    char data_abertura[8];
    char rua[50];
    int numero[5];
    char bairro[50];
    char cidade[30];
    char estado[30];
    int cep[8];
    char email[30];
    int telefone[9];
 }Industria;

void cadastrar_industria(Industria empresas[], int *contador) {
    if (*contador >= 100) {
        printf("Limite de cadastro atingido.\n");
        return;
    }
    
    printf("CADASTRO DE IND�STRIA\n");
    printf("RESPONS�VEL\n");
    printf("Nome: ");
    getchar();
    fgets(empresas[*contador].nome_responsavel, sizeof(empresas[*contador].nome_responsavel), stdin);
    empresas[*contador].nome_responsavel[strcspn(empresas[*contador].nome_responsavel, "\n")] = 0; 

	printf("DADOS DA EMPRESA\n");
	printf("Nome da Empresa: ");
    fgets(empresas[*contador].nome_empresa, sizeof(empresas[*contador].nome_empresa), stdin);
    empresas[*contador].nome_empresa[strcspn(empresas[*contador].nome_empresa, "\n")] = 0;
	
	
    printf("CNPJ: ");
    fgets(empresas[*contador].cnpj, sizeof(empresas[*contador].cnpj), stdin);
    empresas[*contador].cnpj[strcspn(empresas[*contador].cnpj, "\n")] = 0;

	printf("Raz�o Social: ");
    fgets(empresas[*contador].razao_social, sizeof(empresas[*contador].razao_social), stdin);
    empresas[*contador].razao_social[strcspn(empresas[*contador].razao_social, "\n")] = 0;
    
    printf("Nome fantasia: ");
    fgets(empresas[*contador].nome_fantasia, sizeof(empresas[*contador].nome_fantasia), stdin);
    empresas[*contador].nome_fantasia[strcspn(empresas[*contador].nome_fantasia, "\n")] = 0;
    
    printf("Data de abertura: ");
    fgets(empresas[*contador].data_abertura, sizeof(empresas[*contador].data_abertura), stdin);
    empresas[*contador].data_abertura[strcspn(empresas[*contador].data_abertura, "\n")] = 0;
    
    printf("ENDERE�O\n");
    printf("Rua: ");
    fgets(empresas[*contador].rua, sizeof(empresas[*contador].rua), stdin);
    empresas[*contador].rua[strcspn(empresas[*contador].rua, "\n")] = 0;
    
    printf("N�mero: ");
    fgets(empresas[*contador].numero, sizeof(empresas[*contador].numero), stdin);
    empresas[*contador].numero[strcspn(empresas[*contador].numero, "\n")] = 0;
    
    printf("Bairro: ");
    fgets(empresas[*contador].bairro, sizeof(empresas[*contador].bairro), stdin);
    empresas[*contador].bairro[strcspn(empresas[*contador].bairro, "\n")] = 0;
    
    printf("Cidade: ");
    fgets(empresas[*contador].cidade, sizeof(empresas[*contador].cidade), stdin);
    empresas[*contador].cidade[strcspn(empresas[*contador].cidade, "\n")] = 0;
    
    printf("Estado: ");
    fgets(empresas[*contador].estado, sizeof(empresas[*contador].estado), stdin);
    empresas[*contador].estado[strcspn(empresas[*contador].estado, "\n")] = 0;
    
    printf("CEP: ");
    fgets(empresas[*contador].cep, sizeof(empresas[*contador].cep), stdin);
    empresas[*contador].cep[strcspn(empresas[*contador].cep, "\n")] = 0;
    
    printf("CONTATO\n");
    printf("e-mail: ");
    fgets(empresas[*contador].email, sizeof(empresas[*contador].email), stdin);
    empresas[*contador].email[strcspn(empresas[*contador].email, "\n")] = 0;
    
    printf("Telefone: ");
    fgets(empresas[*contador].telefone, sizeof(empresas[*contador].telefone), stdin);
    empresas[*contador].telefone[strcspn(empresas[*contador].telefone, "\n")] = 0;
    
    printf("Ind�stria cadastrada com sucesso!\n");
    (*contador)++;
}




int main() {
    setlocale(LC_ALL, "portuguese");
	Industria empresas[100];
    int contador = 0;    
    char user_veri[20];
    char user[] = "Admin";
    int senha_veri, senha_correta, user_correto, i, a ;
    int senha[] = {12345};
   
    do {
    	 printf("STARTUP DE SOLU��ES AMBIENTAIS\n"),
    	printf("LOGIN\n");
        printf("Usu�rio:");
        scanf("%s", user_veri);
        printf("\nSenha:");
        scanf("%d", &senha_veri);

        user_correto = 0;
        senha_correta = 0;

        if (strcmp(user_veri, user) == 0) {
            user_correto = 1;
        } else {
            user_correto = 0;
        }

        if (senha_veri == senha[0]) {
            senha_correta = 1;
        } else {
            senha_correta = 0;
        }

        if (senha_correta == 1 && user_correto == 1) {
            printf("Login bem-sucedido!\n");
        } else {
            printf("Senha ou Usu�rio incorretos!\n");
        }
        getch();
	 system("cls");
    } while (user_correto == 0 || senha_correta == 0);

	do{
    printf("Tela Inicial\n");
    printf("1.Ver dados das ind�strias cadastradas\n");
    printf("2.Cadastrar uma nova ind�stria\n");
    printf("3.Atualizar dados mensais de res�duos\n");
    printf("4.Gerar relat�rios\n");
    printf("5.Sair\n");
    scanf("%d", &a);
    if (a<=0 || a>=5){
    	printf("Op��o inv�lida");
	} else{
		printf("Op��o %d selecionada", a);
	}
	getch();
    system("cls");
} while(a<=0 || a>=5);
    switch(a){
    	case 1:
    		printf("macarena");
    		break;
    	case 2:	
    	cadastrar_industria(empresas, &contador);
    		break;
    	case 3:
    		printf("arroz");
    		break;
    	case 4:
    		printf("maskeiko");
    		break;
    	case 5:
    		printf("muchas gracias");
    		break;
	}
    
    return 0;
}
