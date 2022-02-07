#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

char nome[200];
char cpf[50];
char sexo[3];
int idade;
int main();


struct elemento{
	char pergunta[256];
	int pontuacao;
};

	struct elemento questoes[] = {
		{.pergunta = "Tem febre: ", .pontuacao = 5},
		{.pergunta = "Tem dor de cabeça: ", .pontuacao = 1},
		{.pergunta = "Tem secre��o nasal ou espirros: ", .pontuacao = 1},
		{.pergunta = "Tem dor/irrita��o na garanta: ", .pontuacao = 1},
		{.pergunta = "Tem tosse seca: ", .pontuacao = 3},
		{.pergunta = "Tem dificuldade respirat�ria: ", .pontuacao = 10},
		{.pergunta = "Tem dores no corpo: ", .pontuacao = 1},
		{.pergunta = "Tem diarr�ia: ", .pontuacao = 1},
		{.pergunta = "Esteve em contato, nos ultimos 14 dias, com um diagnosticado com COVID-19: ", .pontuacao = 10},
		{.pergunta = "Esteve em locais com grande aglomera��o: ", .pontuacao = 3},
	};



void perguntas(){
	
	int i = 0;
	int soma = 0;
	char res;
	setlocale(LC_ALL, "Portuguese");
	
	FILE *arquivoTxt;
	arquivoTxt = fopen("cadastroPaciente.txt", "a");
	
	if (arquivoTxt==NULL)
	{
		printf("Erro ao criar arquivo");
	}
	
	system("cls");
	
	printf("Responda as perguntas abaixo com S para Sim ou N para N�o\n");
	printf("-------------------------------------------------------------\n");
	for(i = 0; i <10; i++){
		printf("%s", questoes[i].pergunta);
		scanf("%c", &res);
		fflush(stdin);
		fprintf(arquivoTxt, "%s %c\n",questoes[i].pergunta, res);
		if (res == 'S' || res == 's'){
			soma = soma + questoes[i].pontuacao;
		}
	}
	fprintf(arquivoTxt, "Pontua��o total: %d\n", soma);	
	fclose(arquivoTxt);
	
	system("cls");
	if (soma >= 0 && soma <10){
		printf("Voc� somou %d pontos e deve se encaminhar para a ala de Baixo Risco\n", soma);
	}
	
	if (soma >= 10 && soma <20){
		printf("Voc� somou %d pontos e deve se encaminhar para a ala de Medio Risco\n", soma);
	}
	if (soma >= 20){
		printf("Voc� somou %d pontos e deve se encaminhar para a ala de Alto Risco\n", soma);
	}
	
	soma = 0;
	system("pause");
	main();
}

void cadastrarPaciente(){
	setlocale(LC_ALL, "Portuguese");
	
	FILE *arquivoTxt;
	arquivoTxt = fopen("cadastroPaciente.txt", "a");
	
	if (arquivoTxt==NULL)
	{
		printf("Erro ao criar arquivo");
	}
	
	printf("Informe o nome do paciente:\n");
	gets(nome);
	fflush(stdin);
	
	printf("Informe o CPF do paciente:\n");
	gets(cpf);
	fflush(stdin);
	
	printf("Informe o sexo do paciente (M/F):\n");
	gets(sexo);
	fflush(stdin);
		
	printf("Informe a idade do paciente:\n");
	scanf("%d", &idade);
	fflush(stdin);
	
	fprintf(arquivoTxt, "\nNome: %s\nCPF: %s\nSexo: %s\nIdade: %d\n", nome,cpf,sexo,idade);	
	fclose(arquivoTxt);
	
	printf("Dados gravados com sucesso\n");
	system("pause");
	perguntas();

}


int main() {	
	setlocale(LC_ALL, "Portuguese");
	int opcao;
	
	system("cls");
	printf("---------Menu---------\n\n");
	printf("1 - Cadastrar Paciente\n");
	printf("0 - Sair\n");
	printf("Por favor, selecione uma op��o\n --->");
	scanf("%i", &opcao);
	fflush(stdin);
	
	switch(opcao){
		case 0:
			printf("\n Finalizando o programa...");
			break;
		case 1:
			cadastrarPaciente();
			break;	
			
		default:
			printf("Escolha uma op��o correta\n");
			system("pause");
			main();
			break;
	}	
		
	return 0;
}
