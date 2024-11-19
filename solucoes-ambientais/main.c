//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>

//REGISTROS
typedef struct{
    int ano;
    int mes;
    float residuos_mensal[6];
    float custo_mensal[6];
}dados_mensais;

typedef struct{
    char nome_responsavel[151];
    char cpf[15];
    char rg[20];
    char nome_empresa[50];
    char cnpj[19];
    char nome_fantasia[50];
    char data_abertura[11];
    char rua[101];
    char numero[11];
    char bairro[51];
    char cidade[51];
    char estado[3];
    char cep[10];
    char email[101];
    char telefone[16];

    dados_mensais residuos_mensais[6]; //atualizações mensais por empresa
    int total_meses;
}industria;

//CRIPTOGRAFIA
void criptografar_dados(void *dados, size_t tamanho, const char *chave) {
    size_t chave_len = strlen(chave);
    size_t i;
    unsigned char *dados_char = (unsigned char *)dados;

    for (i = 0; i < tamanho; i++) {
        dados_char[i] ^= chave[i % chave_len];  // XOR com a chave, byte a byte
    }
}

//CARREGAR OS DADOS SALVOS 
void carregar_dados(industria empresas[], int *contador) {
    const char *chave = "chave-secreta";  // Chave de criptografia simples
    FILE *arquivo = fopen("industria_dados.bin", "rb");
    if (arquivo == NULL) {
        printf("Nenhum dado salvo encontrado.\n");
        *contador = 0;
        return;
    }
    fread(contador, sizeof(int), 1, arquivo);
    fread(empresas, sizeof(industria), *contador, arquivo);
    // DESCRIPTOGRAFA OS DADOS 
    criptografar_dados(empresas, sizeof(industria) * (*contador), chave);
    fclose(arquivo);
    printf("Dados carregados com sucesso!\n");
}

//SALVAR OS DADOS 
void salvar_dados(industria empresas[], int contador) {
    const char *chave = "chave-secreta";  // CHAVE DA CRIPTOGRAFIA	
    FILE *arquivo = fopen("industria_dados.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar.\n");
        return;
    }

    // Criptografar os dados antes de salvar
    criptografar_dados(empresas, sizeof(industria) * contador, chave);
    fwrite(&contador, sizeof(int), 1, arquivo);
    // Salva as indústrias criptografadas
    fwrite(empresas, sizeof(industria), contador, arquivo);
    // Reverte a criptografia após salvar
    criptografar_dados(empresas, sizeof(industria) * contador, chave);
    fclose(arquivo);
    printf("Dados salvos com sucesso!\n");
}

//FUNÇÃO DE CADASTRAR UMA INDÚSTRIA
void cadastrar_industria(industria empresas[], int*contador){
    if (*contador >= 100) {
        printf("Limite de cadastro atingido.\n");
        return;
    }

    printf("--------------------------------------\n");
    printf("          CADASTRO INDÚSTRIA          \n");
    printf("--------------------------------------\n");
    printf("--RESPONSÁVEL--\n");
    printf("Nome: ");
    getchar();
    fgets(empresas[*contador].nome_responsavel, sizeof(empresas[*contador].nome_responsavel), stdin);
    empresas[*contador].nome_responsavel[strcspn(empresas[*contador].nome_responsavel, "\n")] = 0;

    printf("CPF: ");
    fgets(empresas[*contador].cpf, sizeof(empresas[*contador].cpf), stdin);
    empresas[*contador].cpf[strcspn(empresas[*contador].cpf, "\n")] = 0;

    printf("RG: ");
    getchar();
    fgets(empresas[*contador].rg, sizeof(empresas[*contador].rg), stdin);
    empresas[*contador].rg[strcspn(empresas[*contador].rg, "\n")] = 0;

    printf("\n--DADOS DA EMPRESA--\n");
    printf("Nome da Empresa/Razão Social: ");
    fgets(empresas[*contador].nome_empresa, sizeof(empresas[*contador].nome_empresa), stdin);
    empresas[*contador].nome_empresa[strcspn(empresas[*contador].nome_empresa, "\n")] = 0;

    printf("CNPJ: ");
    fgets(empresas[*contador].cnpj, sizeof(empresas[*contador].cnpj), stdin);
    empresas[*contador].cnpj[strcspn(empresas[*contador].cnpj, "\n")] = 0;

    printf("Nome Fantasia: ");
    fgets(empresas[*contador].nome_fantasia, sizeof(empresas[*contador].nome_fantasia), stdin);
    empresas[*contador].nome_fantasia[strcspn(empresas[*contador].nome_fantasia, "\n")] = 0;

    printf("Data de abertura: ");
    getchar();
    fgets(empresas[*contador].data_abertura, sizeof(empresas[*contador].data_abertura), stdin);
    empresas[*contador].data_abertura[strcspn(empresas[*contador].data_abertura, "\n")] = 0;

    printf("\n--ENDEREÇO--\n");
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
    getchar();
    fgets(empresas[*contador].cep, sizeof(empresas[*contador].cep), stdin);
    empresas[*contador].cep[strcspn(empresas[*contador].cep, "\n")] = 0;

    printf("\n--CONTATO--\n");
    printf("E-mail: ");
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

//FUNÇÃO DE PROCURAR UMA INDÚSTRIA
void procura(industria empresas[], int contador){
    if (contador == 0) {
        printf("Nenhuma indústria cadastrada.\n");
        getch();
        system("cls");
        return;
    }
    int i;
    for ( i = 0; i < contador; i++) {
        printf("-%s\n", empresas[i].nome_empresa);
    }
}

//FUNÇÃO INCREMENTAL DE VERIFICAÇÃO DE DADOS DA INDUSTRIA
void dados_empresa(industria empresas[], int contador){
 	printf("--------------------------------------\n");
    printf("        INDUSTRIAS CADASTRADAS        \n");
    printf("--------------------------------------\n");
    printf("            --INDUSTRIAS--            \n");
    procura(empresas, contador);
	if (contador == 0){
		return;
	}
    printf("--------------------------------------\n");
    printf("Digite o nome da indústria que deseja verificar os dados: ");
    getchar();
	char nome_busca[50];
    fgets(nome_busca, sizeof(nome_busca), stdin);
    nome_busca[strcspn(nome_busca, "\n")] = 0;

    int i, encontrou = 0;
    for ( i = 0; i < contador; i++) {
        if (strcmp(empresas[i].nome_empresa, nome_busca) == 0) {
            encontrou = 1;

            printf("\n--------------------------------------\n");
            printf("      DADOS DA INDUSTRIA: %s       \n", empresas[i].nome_empresa);
            printf("--------------------------------------\n");
            printf("--RESPONSÁVEL--\n");
            printf("Nome do Responsável: %s\n", empresas[i].nome_responsavel);
            printf("CPF: %s\n", empresas[i].cpf);
            printf("RG: %s\n", empresas[i].rg);

            printf("\n--DADOS DA EMPRESA--\n");
            printf("Nome da Empresa/Razão Social: %s\n", empresas[i].nome_empresa);
            printf("CNPJ: %s\n", empresas[i].cnpj);
            printf("Nome Fantasia: %s\n", empresas[i].nome_fantasia);
            printf("Data de Abertura: %s\n", empresas[i].data_abertura);

            printf("\n--ENDEREÇO--\n");
            printf("Endereço: Rua %s, Número %s, Bairro %s, Cidade %s, Estado %s, CEP %s\n",
                   empresas[i].rua, empresas[i].numero, empresas[i].bairro,
                   empresas[i].cidade, empresas[i].estado, empresas[i].cep);

            printf("\n--CONTATO--\n");
            printf("E-mail: %s\n", empresas[i].email);
            printf("Telefone: %s\n", empresas[i].telefone);
            printf("--------------------------------------\n");
            getch();
            system("cls");
        }
    }
    if (encontrou == 0) {
        printf("Indústria com nome '%s' não encontrada.\n", nome_busca);
    }
}

//FUNÇÃO DE ATUALIZAÇÕES MENSAIS
void atualizar_dados_mensais(industria empresas[], int contador) {
    printf("--------------------------------------\n");
    printf("            ATUALIZAR DADOS           \n");
    printf("          MENSAIS DE RESÍDUOS         \n");
    printf("--------------------------------------\n");
    printf("            --INDUSTRIAS--            \n");
    procura(empresas, contador);
	if (contador == 0){
		return;
	}
    printf("--------------------------------------\n");
    printf("Digite o nome da indústria que deseja atualizar : ");
    getchar();
	char nome_busca[50];
    fgets(nome_busca, sizeof(nome_busca), stdin);
    nome_busca[strcspn(nome_busca, "\n")] = 0;

    int i, encontrou = 0;
    for (i = 0; i < contador; i++) {
        if (strcmp(empresas[i].nome_empresa, nome_busca) == 0) {
            encontrou = 1;

            int mes;
            printf("Digite o mês (1-12): ");
            scanf("%d", &mes);

            printf("Digite a quantidade de resíduos tratados (em toneladas): ");
            scanf("%f", &empresas[i].residuos_mensais[mes - 1].residuos_mensal[mes - 1]);

            printf("Digite o custo estimado (R$): ");
            scanf("%f", &empresas[i].residuos_mensais[mes - 1].custo_mensal[mes - 1]);



            printf("Atualização mensal adicionada com sucesso.\n");
            getch();
            system("cls");
            return;
        }
    }
    if (encontrou == 0) {
        printf("Indústria com nome '%s' não encontrada.\n", nome_busca);
    }
}

//FUNÇÃO DE GERAR RELATÓRIO SEMESTRAL
void insumo_semestral(industria empresas[], int contador){
    printf("--------------------------------------\n");
    printf("          RELATÓRIO INDIVIDUAL        \n");
    printf("--------------------------------------\n");
    printf("            --INDUSTRIAS--            \n");
    procura(empresas, contador);
	if (contador == 0){
		return;
	}
    printf("--------------------------------------\n");
    printf("Digite o nome da indústria que deseja gerar um relatório: ");
    getchar();
	char nome_busca[50];
    fgets(nome_busca, sizeof(nome_busca), stdin);
    nome_busca[strcspn(nome_busca, "\n")] = 0;

    int i, encontrou = 0;
    for (i = 0; i < contador; i++) {
        if (strcmp(empresas[i].nome_empresa, nome_busca) == 0) {
            encontrou = 1;

            // Cálculo de resíduos e custos totais
            float total_residuos = 0.0, total_custos = 0.0;
            int mes;
            for ( mes = 0; mes < 6; mes++) {
                total_residuos += empresas[i].residuos_mensais[mes].residuos_mensal[mes];
                total_custos += empresas[i].residuos_mensais[mes].custo_mensal[mes];
            }

            printf("\n--------------------------------------\n");
            printf("Relatório Semestral da Indústria: %s\n", empresas[i].nome_empresa);
            printf("Total de insumos tratados semestralmente: %.2f\n", total_residuos);
            printf("Total de gastos semestrais: R$ %.2f\n", total_custos);
            getch();
            system("cls");
            return;
        }
    }
    if (encontrou == 0) {
        printf("Indústria com nome '%s' não encontrada.\n", nome_busca);
    }

}

//FUNÇÃO DE GERAR RELATÓRIO GLOBAL
void relatorio_global(industria empresas[], int contador){
    printf("--------------------------------------\n");
    printf("           RELATÓRIO GLOBAL           \n");
    printf("--------------------------------------\n");
    
    //
    //
    //
    
    printf("Indústrias que MAIS produziram no último semestre: \n");
    printf("Indústrias que MENOS produziram no último semestre: \n");
    printf("Indústria com MAIOR aporte financeiro semestral: \n");
    printf("Indústria com MENOR aporte financeiro semestral: \n");
    printf("Região onde estão localizadas as indústrias que tratam um maior volume de resíduos industriais: \n");
	
	getch();
    system("cls");
    return;
}



//FUNÇÃO DE INICIALIZAÇÃO DE GERAR RELATÓRIOS
void gerar_relatorios(industria empresas[], int contador){
    int opcao;

    do{

        printf("--------------------------------------\n");
        printf("            GERAR RELATÓRIOS          \n");
        printf("--------------------------------------\n");
        if (contador == 0) {
        printf("Nenhuma indústria cadastrada.\n");
        getch();
        system("cls");
        return;
        }
        printf("1. Relatório Individual\n");
        printf("2. Relatório Global\n");
        printf("3. Sair\n");
        printf("Selecione uma opção: ");
        scanf("%d", &opcao);


        if(opcao < 1 || opcao > 3){
            printf("Opção inválida");
            getchar();
            system("cls");
        }
        system("cls");

        switch(opcao){
            case 1:
                insumo_semestral(empresas, contador);
                getch();
                system("cls");
                break;
            case 2:
                printf("Global"); //criar função
                getch();
                system("cls");
                break;
            case 3:
                printf("Saindo...");
                getch();
                system("cls");
                return;
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                getchar();
                system("cls");
                break;
        }
    } while(opcao != 3);

}

//PROGRAMA PRINCIPAL
int main(){
    setlocale(LC_ALL, "portuguese");
    industria empresas[100];
    int contador = 0;
    char user_veri[20];
    char user[] = "Admin";
    int senha_veri, senha_correta, user_correto, i, a;
    int senha[] = {12345};
    carregar_dados(empresas, &contador);// CARREGA OS DADOS SALVOS

    //LOGIN
    do{
        printf("--------------------------------------\n");
        printf("                 NOME                 \n");
        printf("    STARTUP DE SOLUÇÕES AMBIENTAIS    \n");
        printf("--------------------------------------\n");
        printf("                LOGIN                 \n");
        printf("Usuário: ");
        scanf("%s", user_veri);
        printf("\nSenha: ");
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
            printf("\nPressione 'enter' para entrar no sistema");
        } else {
            printf("Senha ou Usuário incorretos!\n");
        }
        getch();
	    system("cls");
    } while (user_correto == 0 || senha_correta == 0);

    //TELA INICIAL
    do{
        printf("--------------------------------------\n");
        printf("             TELA INICIAL               \n");
        printf("--------------------------------------\n");
        printf("1. Ver dados das indústrias\n");
        printf("2. Cadastrar uma nova indústria\n");
        printf("3. Atualizar dados mensais de resíduos\n");
        printf("4. Gerar relatórios\n");
        printf("5. Sair\n");
        printf("Selecione uma opção: ");
        scanf("%d", &a);

        if(a < 1 || a > 5){
            printf("Opção inválida");
            getchar();
            system("cls");
        }
        system("cls");

        switch(a){
            case 1:
                dados_empresa(empresas, contador);
                break;
            case 2:
                cadastrar_industria(empresas, &contador);
                break;
            case 3:
                atualizar_dados_mensais(empresas, contador);
                break;
            case 4:
                gerar_relatorios(empresas, contador);
                break;
            case 5:
            	salvar_dados(empresas, contador);//SALVA OS DADOS ANTES DE FECHAR O PROGRAMA
                printf("Saindo...");
                return 0;
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                getchar();
                system("cls");
                break;
        }
    } while(a != 5);


    return 0;
}
