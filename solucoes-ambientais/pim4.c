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
    char numero[5];
    char bairro[50];
    char cidade[30];
    char estado[30];
    char cep[8];
    char email[30];
    char telefone[9];
 }Industria;
 
 

void cadastrar_industria(Industria empresas[], int *contador) {
    if (*contador >= 100) {
        printf("Limite de cadastro atingido.\n");
        return;
    }
    
    printf("CADASTRO DE INDÚSTRIA\n");
    printf("RESPONSÁVEL\n");
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

	printf("Razão Social: ");
    fgets(empresas[*contador].razao_social, sizeof(empresas[*contador].razao_social), stdin);
    empresas[*contador].razao_social[strcspn(empresas[*contador].razao_social, "\n")] = 0;
    
    printf("Nome fantasia: ");
    fgets(empresas[*contador].nome_fantasia, sizeof(empresas[*contador].nome_fantasia), stdin);
    empresas[*contador].nome_fantasia[strcspn(empresas[*contador].nome_fantasia, "\n")] = 0;
    
    printf("Data de abertura: ");
    fgets(empresas[*contador].data_abertura, sizeof(empresas[*contador].data_abertura), stdin);
    empresas[*contador].data_abertura[strcspn(empresas[*contador].data_abertura, "\n")] = 0;
    
    printf("ENDEREÇO\n");
    printf("Rua: ");
    fgets(empresas[*contador].rua, sizeof(empresas[*contador].rua), stdin);
    empresas[*contador].rua[strcspn(empresas[*contador].rua, "\n")] = 0;
    
    printf("Número: ");
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
    
    printf("Indústria cadastrada com sucesso!\n");
    getch();
    system("cls");
    (*contador)++;
}



void procurar_empresa(Industria empresas[], int contador){
 	if (contador == 0) {
        printf("Nenhuma empresa cadastrada.\n");
        getch();
        system("cls");
        return;
    }
	char nome_busca[50];
    printf("Digite o nome da empresa que deseja buscar: ");
    getchar();
    fgets(nome_busca, sizeof(nome_busca), stdin);
    nome_busca[strcspn(nome_busca, "\n")] = 0;
    
    int i, encontrou = 0;
    for ( i = 0; i < contador; i++) {
        if (strcmp(empresas[i].nome_empresa, nome_busca) == 0) {
            encontrou = 1;
            printf("\n--- Dados da Empresa ---\n");
            printf("Nome do Responsável: %s\n", empresas[i].nome_responsavel);
            printf("Nome da Empresa: %s\n", empresas[i].nome_empresa);
            printf("CNPJ: %s\n", empresas[i].cnpj);
            printf("Razão Social: %s\n", empresas[i].razao_social);
            printf("Nome Fantasia: %s\n", empresas[i].nome_fantasia);
            printf("Data de Abertura: %s\n", empresas[i].data_abertura);
            printf("Endereço: Rua %s, Número %s, Bairro %s, Cidade %s, Estado %s, CEP %s\n",
                   empresas[i].rua, empresas[i].numero, empresas[i].bairro,
                   empresas[i].cidade, empresas[i].estado, empresas[i].cep);
            printf("E-mail: %s\n", empresas[i].email);
            printf("Telefone: %s\n", empresas[i].telefone);
            printf("------------------------\n");
            getch();
            system("cls");
        }
    }

    if (encontrou == 0) {
        printf("Empresa com nome '%s' não encontrada.\n", nome_busca);
    }
}


int main() {
    setlocale(LC_ALL, "portuguese");
	Industria empresas[100];
    int contador = 0;    
    char user_veri[20];
    char user[] = "Admin";
    int senha_veri, senha_correta, user_correto, i, a = 0 ;
    int senha[] = {12345};
   
    do {
    	 printf("STARTUP DE SOLUÇÕES AMBIENTAIS\n"),
    	printf("LOGIN\n");
        printf("Usuário:");
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
            printf("Senha ou Usuário incorretos!\n");
        }
        getch();
	 system("cls");
    } while (user_correto == 0 || senha_correta == 0);


	while(a !=5){
	do{
    printf("Tela Inicial\n");
    printf("1.Ver dados das indústrias cadastradas\n");
    printf("2.Cadastrar uma nova indústria\n");
    printf("3.Atualizar dados mensais de resíduos\n");
    printf("4.Gerar relatórios\n");
    printf("5.Sair\n");
    scanf("%d", &a);
    if (a<0 || a>5){
    	printf("Opção inválida");
	} else{
		printf("Opção %d selecionada", a);
	}
	getch();
    system("cls");
} while(a<0 || a>5);
    switch(a){
    	case 1:
    		procurar_empresa(empresas, contador);
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
}
    return 0;
}
