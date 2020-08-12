#include <stdio.h>
#include <string.h>


// constantes
#define AULAS 36
#define MAXALUNOS 10

// struct do tipo aluno
typedef struct {
	int matricula;
	char nome[50];
	float notas[4];
	int faltas;
} aluno;

// variaveis globais
aluno alunos[MAXALUNOS];
int quantAlunos;

FILE *alunosArq;
FILE *quantAlunosArq;


// assinatura de funcoes
void exibirMenu(int *ptr);
void listarAlunosCadastrados();
void cadastrarAluno();
void removerAluno();
void atualizarAluno();
void consultarAluno();
void listarAprovados();
void listarReprovadosMedia();
void listarReprovadosFalta();
int menuDeOrdem();
void ordenaMatricula();
void ordenaMedia();
void ordenaAlfabeto();
void exibirCadastrados();
void exibirAprovado();
void exibirReprovadosMedia();
void exibirReprovadosFalta();
int procuraMatricula(int matricula);
void inserirDadosAluno(int posicao);
void lerArquivos();
void atualizarArquivos();
float calculaMedia(int posicao);
float calculaFrequencia(int posicao);
int informeMatricula();

int main() {
	
	lerArquivos();
	
	int opcao;
		
		printf("===================================================\n");
		printf("------------SISTEMA DE GESTAO DE ALUNOS------------\n");
		printf("===================================================\n");
		printf("                                         versao 2.0\n");
	do {
		
		exibirMenu(&opcao);
		
		switch(opcao) {
			
			case 1:
				cadastrarAluno();
				break;
			
			case 2:
				removerAluno();
				break;
			
			case 3:
				atualizarAluno();
				break;
			
			case 4:
				consultarAluno();
				break;
			
			case 5:
				listarAlunosCadastrados();
				break;
			
			case 6:
				listarAprovados();
				break;
			
			case 7:
				listarReprovadosMedia();
				break;
			
			case 8:
				listarReprovadosFalta();
				break;
			
			case 9:
				printf("\n Saindo...\n");
				break;
			
			default:
				printf("\n****************************************\n");
				printf(" Opcao INVALIDA! Tente Novamente.\n\n");
		}
		
	}while(opcao != 9);
		
	printf("\n===================================================");
	printf("\n Programa encerrado. Volte sempre!");
	printf("\n===================================================");
	
	return 0;
}


void exibirMenu(int *op) {
	
	printf("------------------Menu Principal-------------------\n");
	printf(" Escolha Uma Opcao para:\n");
	printf(" 1 - Cadastrar Aluno\n");
	printf(" 2 - Remover Aluno\n");
	printf(" 3 - Atualizar Dados de Aluno\n");
	printf(" 4 - Consultar Dados de Aluno\n");
	printf(" 5 - Listar Alunos Cadastrados\n");
	printf(" 6 - Listar Alunos Aprovados\n");
	printf(" 7 - Listar Alunos Reprovados Por Media\n");
	printf(" 8 - Listar Alunos Reprovados Por Faltas\n");
	printf(" 9 - Sair\n");
	printf(" Informe o numero da opcao: ");
	scanf("%d", op);
	
} 

void cadastrarAluno() {
	
	printf("\n===================================================\n");
	printf("---------------Cadastrando Novo Aluno--------------\n\n");
	
	
	int numMatricula;
	int posMatricula;
	
	if(quantAlunos == MAXALUNOS) {
		printf(" **A turma esta completa.\n\n");
	}
	
	else {
		
		numMatricula = informeMatricula();
		
		posMatricula = procuraMatricula(numMatricula);
		
		if(posMatricula>=0)
			printf(" **Esta matricula ja esta cadastrada!\n\n");
			
		else {
			alunos[quantAlunos].matricula = numMatricula;
			
			inserirDadosAluno(quantAlunos);
			
			printf(" Aluno cadastrado.\n\n");
			
			quantAlunos++;
			
			atualizarArquivos();
		}
	}
}

void removerAluno() {
	
	printf("\n===================================================\n");
	printf("------------------Removendo Aluno------------------\n\n");

	int numMatricula;
	int posMatricula;
	
	if(quantAlunos==0)
		printf(" **A turma nao possui alunos.\n\n");
		
	else {
		
		numMatricula = informeMatricula();
		
		posMatricula = procuraMatricula(numMatricula);
	
		if(posMatricula<0)
			printf(" **Matricula nao encontrada.\n\n");
		
		else {
			for(int i=posMatricula; i<quantAlunos; i++){
				alunos[i]=alunos[i+1];
			}
			quantAlunos--;
			printf(" O aluno foi removido.\n\n");
			
			atualizarArquivos();
		}
	}
}

void atualizarAluno() {
	
	printf("\n===================================================\n");
	printf("------------Atualizando dados de Aluno-------------\n\n");
	
	int numMatricula;
	int posMatricula;
	
	if(quantAlunos==0)
		printf(" **A turma nao possui alunos.\n\n");
	
	else {
		
		numMatricula = informeMatricula();
		
		posMatricula = procuraMatricula(numMatricula);
	
		if(posMatricula<0)
			printf(" **Matricula nao encontrada.\n\n");
		
		else {
			inserirDadosAluno(posMatricula);
			printf(" Os dados do aluno foram atualizados.\n\n");
			atualizarArquivos();
		}
	}
}

void consultarAluno() {
	printf("\n===================================================\n");
	printf("------------Consultando dados de Aluno-------------\n\n");
	
	int numMatricula;
	int posMatricula;
	
	if(quantAlunos==0)
		printf(" **A turma nao possui alunos.\n\n");
	
	else {
		
		numMatricula = informeMatricula();
		
		posMatricula = procuraMatricula(numMatricula);
	
		if(posMatricula<0)
			printf(" **Matricula nao encontrada.\n\n");
		
		else {
			
			printf("\n Matricula.: %d\n", alunos[posMatricula].matricula);
			printf(" Nome......: %s\n", alunos[posMatricula].nome);
			for(int i=0; i<4; i++) {
			printf(" %da nota...: %.1f\n", i+1, alunos[posMatricula].notas[i]);
			}
			printf(" Media.....: %.1f\n", calculaMedia(posMatricula));
			printf(" Faltas....: %d\n", alunos[posMatricula].faltas);
			printf(" Frequencia: %.0f%%\n\n", calculaFrequencia(posMatricula));
		}
	}
}

// Esta funcao recebe uma matricula e retorna
// a posicao do aluno caso a matricula esteja
// cadastrada. Caso contrario retorna -1.
int procuraMatricula(int matricula) {
	
	int posicao = -1;
	
	for(int i=0; i<quantAlunos; i++) {
		if(alunos[i].matricula == matricula)
			posicao = i;
	}
	
	return posicao;
}


// Esta funcao e responssavel por casdastrar
// ou atualizar nome, notas e faltas de aluno.
void inserirDadosAluno(int posicao) {
	
	int notaAux;
	int faltasAux;
	
	printf(" Informe o nome do aluno: ");
	getchar();
	gets(alunos[posicao].nome);
	
	do {
		printf(" Informe a primeira nota: ");
		scanf("%f", &alunos[posicao].notas[0]);
		notaAux = alunos[posicao].notas[0];
		if(notaAux>10 || notaAux<0) 
			printf(" **Nota INVALIDA! (maior que 10 ou menor que 0)\n");
	} while(notaAux>10 || notaAux< 0);
	
	do {
		printf(" Informe a segunda nota: ");
		scanf("%f", &alunos[posicao].notas[1]);
		notaAux = alunos[posicao].notas[1];
		if(notaAux>10 || notaAux<0) 
			printf(" **Nota INVALIDA! (maior que 10 ou menor que 0)\n");
	} while(notaAux>10 || notaAux< 0);
	
	do {
		printf(" Informe a terceira nota: ");
		scanf("%f", &alunos[posicao].notas[2]);
		notaAux = alunos[posicao].notas[2];
		if(notaAux>10 || notaAux<0) 
			printf(" **Nota INVALIDA! (maior que 10 ou menor que 0)\n");
	} while(notaAux>10 || notaAux< 0); 
	
	do {
		printf(" Informe a quarta nota: ");
		scanf("%f", &alunos[posicao].notas[3]);
		notaAux = alunos[posicao].notas[3];
		if(notaAux>10 || notaAux<0) 
			printf(" **Nota INVALIDA! (maior que 10 ou menor que 0)\n");
	} while(notaAux>10 || notaAux< 0);
	
	do {
		printf(" Informe o numero de faltas: ");
		scanf("%d", &alunos[posicao].faltas);
		faltasAux = alunos[posicao].faltas;
		if(faltasAux>AULAS || faltasAux<0)
			printf(" **faltas INVALIDA! (maior que quantidade de aulas ou menor que 0)\n");
	} while(faltasAux>AULAS || faltasAux<0);
}

void listarAlunosCadastrados() {
	
	printf("\n===================================================\n");
	printf("------------Listando Alunos Cadastrados------------\n");
	
	if(quantAlunos == 0) {
		printf("\n **A turma nao possui alunos.\n\n");
	}
	
	else {
		int opcao;
		opcao = menuDeOrdem();
		
		switch(opcao) {
			
			case 1:
				ordenaMatricula();
				exibirCadastrados();
				break;
			case 2:
				ordenaMedia();
				exibirCadastrados();
				break;
			case 3:
				ordenaAlfabeto();
				exibirCadastrados();
				break;
		}
	}
}


// arquivo
void lerArquivos() {
	
	quantAlunosArq = fopen("quantAlunos.txt", "r");
	fscanf(quantAlunosArq, "%d", &quantAlunos);
	
	alunosArq = fopen("alunos.txt", "r");
	
	fread(&alunos, sizeof(aluno), quantAlunos, alunosArq);
	
	fclose(quantAlunosArq);
	fclose(alunosArq);
}
// arquivo
void atualizarArquivos() {
	
	quantAlunosArq = fopen("quantAlunos.txt", "w");
	fprintf(quantAlunosArq, "%d", quantAlunos);
	
	alunosArq = fopen("alunos.txt", "w");
	
	fwrite(&alunos, sizeof(aluno), quantAlunos, alunosArq);
	
	fclose(quantAlunosArq);
	fclose(alunosArq);
	
}

float calculaMedia(int posicao) {
	
	float media;
	media = (alunos[posicao].notas[0]+alunos[posicao].notas[1]+alunos[posicao].notas[2]+alunos[posicao].notas[3])/4;
	return media;
}

float calculaFrequencia(int posicao) {

	float freq;
	float faltas = alunos[posicao].faltas;
	
	freq = 100 - (faltas / (36.0/100));
	
	return freq;
}

int menuDeOrdem() {
	
	int opcao;
	
	do {
		
		printf("\n 1 - Listar por matricula\n");
		printf(" 2 - Listar por media\n");
		printf(" 3 - Listar por ordem alfabetica\n");
		printf(" Informe o numero da opcao: ");
		scanf("%d", &opcao);
		if(opcao != 1 && opcao != 2 && opcao != 3)
			printf(" **Opcao INVALIDA. Tente novamente!\n");
		
	} while(opcao != 1 && opcao != 2 && opcao != 3);
	
	return opcao;
}

void listarAprovados() {
	
	printf("\n===================================================\n");
	printf("-------------Listando Alunos Aprovados-------------\n");
	
	if(quantAlunos == 0) {
		printf("\n **A turma nao possui alunos.\n\n");
	}
	
	else {
		int opcao;
		opcao = menuDeOrdem();
		
		switch(opcao) {
			
			case 1:
				ordenaMatricula();
				exibirAprovado();
				break;
			case 2:
				ordenaMedia();
				exibirAprovado();
				break;
			case 3:
				ordenaAlfabeto();
				exibirAprovado();
				break;
		}
	}
}

void listarReprovadosMedia() {
	
	printf("\n===================================================\n");
	printf("-------Listando Alunos Reprovados Por Media--------\n");
	
	if(quantAlunos == 0) {
		printf("\n **A turma nao possui alunos.\n\n");
	}
	
	else {
		int opcao;
		opcao = menuDeOrdem();
		
		switch(opcao) {
			
			case 1:
				ordenaMatricula();
				exibirReprovadosMedia();
				break;
			case 2:
				ordenaMedia();
				exibirReprovadosMedia();
				break;
			case 3:
				ordenaAlfabeto();
				exibirReprovadosMedia();
				break;
		}
	}
}

void listarReprovadosFalta() {
	
	printf("\n===================================================\n");
	printf("-------Listando Alunos Reprovados Por Falta--------\n");
	
	if(quantAlunos == 0) {
		printf("\n **A turma nao possui alunos.\n\n");
	}
	
	else {
		int opcao;
		opcao = menuDeOrdem();
		
		switch(opcao) {
			
			case 1:
				ordenaMatricula();
				exibirReprovadosFalta();
				break;
			case 2:
				ordenaMedia();
				exibirReprovadosFalta();
				break;
			case 3:
				ordenaAlfabeto();
				exibirReprovadosFalta();
				break;
		}
	}
}

void ordenaMatricula() {
	// bubblesort
	aluno tmp;
	
	for(int i=0; i< quantAlunos; i++)
		for(int j=0; j< quantAlunos-i-1; j++) {
			if(alunos[j].matricula>alunos[j+1].matricula) {
				tmp = alunos[j+1];
				alunos[j+1] = alunos[j];
				alunos[j] = tmp;
			}
		}
}

void ordenaMedia() {
	// bubblesort
	aluno tmp;
	
	for(int i=0; i< quantAlunos; i++)
		for(int j=0; j< quantAlunos-i-1; j++) {
			if(calculaMedia(j)>calculaMedia(j+1)) {
				tmp = alunos[j+1];
				alunos[j+1] = alunos[j];
				alunos[j] = tmp;
			}
		}

}

void ordenaAlfabeto() {
	// bubblesort
	aluno tmp;
	
	for(int i=0; i< quantAlunos; i++)
		for(int j=0; j< quantAlunos-i-1; j++) {
			if(strcmp(alunos[j].nome, alunos[j+1].nome) > 0) {
				tmp = alunos[j+1];
				alunos[j+1] = alunos[j];
				alunos[j] = tmp;
			}
		}
}

void exibirAprovado() {
	
	printf("\n");
	
	int cont, barra;
	cont = 0;
	barra=0;

	while(cont < quantAlunos) {
		
		if(calculaMedia(cont)>=7 && calculaFrequencia(cont)>=60) {
			
			if(barra == 1)
				printf("---------------------------------------------------\n");
			
			printf(" Matricula.: %d\n", alunos[cont].matricula);
			printf(" Nome......: %s\n", alunos[cont].nome);
			for(int i=0; i<4; i++) {
			printf(" %da nota...: %.1f\n", i+1, alunos[cont].notas[i]);
			}
			printf(" Media.....: %.1f\n", calculaMedia(cont));
			printf(" Frequencia: %.0f%%\n", calculaFrequencia(cont));
			
			barra=1;
		}
		
		cont++;
	}
	printf("\n");
}

void exibirReprovadosMedia() {
	
	printf("\n");
	
	int cont, barra;
	cont = 0;
	barra=0;

	while(cont < quantAlunos) {
		
		if(calculaMedia(cont)< 7) {
			
			if(barra == 1)
				printf("---------------------------------------------------\n");
			
			printf(" Matricula.: %d\n", alunos[cont].matricula);
			printf(" Nome......: %s\n", alunos[cont].nome);
			for(int i=0; i<4; i++) {
			printf(" %da nota...: %.1f\n", i+1, alunos[cont].notas[i]);
			}
			printf(" Media.....: %.1f\n", calculaMedia(cont));
			printf(" Frequencia: %.0f%%\n", calculaFrequencia(cont));
			
			barra=1;
		}
		
		cont++;
	}
	printf("\n");

}

void exibirReprovadosFalta() {
	printf("\n");
	
	int cont, barra;
	cont = 0;
	barra=0;

	while(cont < quantAlunos) {
		
		if(calculaFrequencia(cont)< 60) {
			
			if(barra == 1)
				printf("---------------------------------------------------\n");
			
			printf(" Matricula.: %d\n", alunos[cont].matricula);
			printf(" Nome......: %s\n", alunos[cont].nome);
			for(int i=0; i<4; i++) {
			printf(" %da nota...: %.1f\n", i+1, alunos[cont].notas[i]);
			}
			printf(" Media.....: %.1f\n", calculaMedia(cont));
			printf(" Frequencia: %.0f%%\n", calculaFrequencia(cont));
			
			barra=1;
		}
		
		cont++;
	}
	printf("\n");
}

void exibirCadastrados() {
	
	printf("\n");
	
	int cont, barra;
	cont = 0;
	barra=0;

	while(cont < quantAlunos) {
			
		if(barra == 1)
			printf("---------------------------------------------------\n");
		
		printf(" Matricula.: %d\n", alunos[cont].matricula);
		printf(" Nome......: %s\n", alunos[cont].nome);
		for(int i=0; i<4; i++) {
		printf(" %da nota...: %.1f\n", i+1, alunos[cont].notas[i]);
		}
		printf(" Media.....: %.1f\n", calculaMedia(cont));
		printf(" Frequencia: %.0f%%\n", calculaFrequencia(cont));
		
		barra=1;
		cont++;
	}
	
	printf("\n");
}

int informeMatricula() {
	
	int numMatricula;
	
	do {
		
		printf(" Informe a matricula do aluno: Ex 20200001 ");
		scanf("%d", &numMatricula);
		if(numMatricula< 10000000 || numMatricula> 99999999)
			printf(" **Matricula INALIDA! Tente novamente.\n\n");
	
	} while(numMatricula< 10000000 || numMatricula> 99999999);
		
	return numMatricula;
}
