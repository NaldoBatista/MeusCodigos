/*
Estruturas do Projeto
	
1 estrutura para represetar os carros;
1 estrutura para represetar os funcionarios;
1 estrutara de pilha para representar o estacionamenro com 1 portao;
1 estrutura de pllha para representar o lado de fora do estacionamento;
1 estrutura de lista para representar lista de fucionarios;
1 estrurura de de fila personalizada para representar o estacionamento com 2 portoes;

Ideia de Funcionamento

Para 1 portão: 
Adicionar carro sempre no topo da pilha de estacionamento
(no caso pelo portao) e remover carro pelo topo, se o carro
removido for o carro que ira sair, ele vai embora, senao adiciona
a pilha do lado de fora(que simula a rua). Ao final desse processo
os carros da pilha de fora voltam para o estacionamento.

Para 2 portoes:
Adicionar carro sempre no inicio da fila de estacionamento
(portao 1) e remover carro pela extremidade mais proxima
(portao 1 ou 2) , se o carro removido for o carro que ira sair, 
ele vai embora, senao adiciona a pilha do lado de fora
(que simula a rua). Ao final desse processo os carros 
da pilha de fora voltam para o estacionamento pelo portao
em que sairam.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXVAGAS 3

// VARÁVEIS GLOBAIS
int numManobras = 0;
float arrecadacao = 0;
int numPortoes = 1;

// Estrutura para funcionarios e suas funcoes.
typedef struct funcionario {
	char nome[20];
	int matricula;
	int idade;
	struct funcionario *prox;
} Func;

Func* criarFuncionario() {
	Func *f = (Func*) malloc(sizeof(Func));
	return f;
}

// Estrutura para carro e suas funcoes.
typedef struct carro {
	char placa[10];
	int horaEntrada;
	struct carro *ant;
	struct carro *prox;
} Carro;

Carro* criarCarro() {
	Carro *c = (Carro*) malloc(sizeof(Carro));
	return c;
}


// Estrutura para Pilha de carros dentro de estacionamento.
typedef struct pilhaEstacionamento {
	Carro *topo;
	int numCarros;
} PE;

PE* criarPilhaEstacionamento() {
	PE *p = (PE*) malloc(sizeof(PE));
	return p;
}

void inicializarPilhaEstacionamento(PE *p) {
	p->topo = NULL;
	p->numCarros = 0;
}

void adicionarCarroEstacionamento(Carro *c, PE *p) {
	c->prox = p->topo;
	p->topo = c;
	p->numCarros++;
}

Carro* retirarCarroEstacionamento(PE *p) {
	if(p->topo == NULL)
		return NULL;
	Carro *aux =  p->topo;
	p->topo = p->topo->prox;
	p->numCarros--;
	return aux;
}

int buscarCarroEstacionamento(char *placa,PE *p) {
	Carro *aux = p->topo;
	while(aux != NULL) {
		if(strcmp(aux->placa, placa) == 0)
			return 1;
		aux = aux->prox;
	}
	return 0;
} 

int buscarHoraEntrada(char *placa, PE *p) {
	Carro *aux = p->topo;
	while(aux != NULL) {
		if(strcmp(aux->placa, placa) == 0)
			return aux->horaEntrada;
		aux = aux->prox;
	}
	return -1;
}

void imprimirEstacionamento(PE *p) {
	if(p->topo == NULL) {
		printf(" Estacionamento vazio.\n");
		return;
	}
	Carro *aux = p->topo;
	printf(" Portao1 ## | ");
	while(aux != NULL) {
		printf(" Placa: %s |", aux->placa);
		aux = aux->prox;
	}
	printf("\n");
}


// Estrutura para pilha do lado de fora do estacionamento.
typedef struct pilhaLadoFora {
	Carro *topo;
	
} PF;

PF* criarPilhaFora() {
	PF *p = (PF*) malloc(sizeof(PF));
	return p;
}

void inicializarPilhaFora(PF *p) {
	p->topo = NULL;
}

void adicionarCarroFora(Carro *c, PF *p) {
	c->prox = p->topo;
	p->topo = c;
}

void adicionarCarroLadoFora(Carro *c, PF *p) {
	c->prox = p->topo;
	p->topo = c;
}

Carro* retirarCarroFora(PF *p) {
	if(p->topo == NULL) 
		return NULL;
	Carro *aux = p->topo;
	p->topo = p->topo->prox;
	return aux;
}

void imprimirFora(PF *p) {
	Carro *aux = p->topo;
	while(aux != NULL) {
		printf(" %s \n", aux->placa);
		aux = aux->prox;
	}
}

// Estrutura de lista circular para funcinarios.
typedef struct listaFuncinarios {
	Func *inicio;
	Func *fim;
	Func *manobrista;
} LF;

LF* criarListaFuncionarios() {
	LF *l = (LF*) malloc(sizeof(LF));
	return l;
}

void inicializarListaFuncionarios(LF *l) {
	l->inicio = NULL;
	l->fim = NULL;
	l->manobrista = NULL;
} 

void adicionarFuncionario(Func *f, LF *l) {
	if(l->inicio == NULL) {
		l->inicio = f;
		l->fim = f;
		l->manobrista = f;
		f->prox = l->inicio;
	}
	else {
		l->fim->prox = f;
		f->prox = l->inicio;
		l->fim = f;
	}
}

void imprimirFuncionarios(LF *l) {
	if(l->inicio == NULL) {
		printf("A lista esta vazia.\n");
		return;
	}
	Func *aux = l->inicio;
	do {
		printf("nome: %s, idade: %d, matricula: %d\n", aux->nome, aux->idade, aux->matricula);
		aux = aux->prox;
	} while(aux != l->inicio);
}

void ordenarFuncionariosIdade(LF *lf) {
	Func *func1 = lf->inicio;
	Func *func2;
	char nomeAux[50];
	int matriAux;
	int idadeAux;
	do {
		func2 = lf->inicio;
		do {
			if(func2->idade > func2->prox->idade) {
				strcpy(nomeAux, func2->nome);
				matriAux = func2->matricula;
				idadeAux = func2->idade;
				strcpy(func2->nome, func2->prox->nome);
				func2->matricula = func2->prox->matricula;
				func2->idade = func2->prox->idade;
				strcpy(func2->prox->nome, nomeAux);
				func2->prox->matricula = matriAux;
				func2->prox->idade = idadeAux;
			}
			func2 = func2->prox;
		} while( func2 != lf->fim);
		
		func1 = func1->prox;
	} while(func1 != lf->inicio);
	
}

void ordenarFuncionariosMatricula(LF *lf) {
	Func *func1 = lf->inicio;
	Func *func2;
	char nomeAux[50];
	int matriAux;
	int idadeAux;
	do {
		func2 = lf->inicio;
		do {
			if(func2->matricula > func2->prox->matricula) {
				strcpy(nomeAux, func2->nome);
				matriAux = func2->matricula;
				idadeAux = func2->idade;
				strcpy(func2->nome, func2->prox->nome);
				func2->matricula = func2->prox->matricula;
				func2->idade = func2->prox->idade;
				strcpy(func2->prox->nome, nomeAux);
				func2->prox->matricula = matriAux;
				func2->prox->idade = idadeAux;
			}
			func2 = func2->prox;
		} while( func2 != lf->fim);
		
		func1 = func1->prox;
	} while(func1 != lf->inicio);
	
}

void ordenarFuncionariosNome(LF *lf) {
	Func *func1 = lf->inicio;
	Func *func2;
	char nomeAux[50];
	int matriAux;
	int idadeAux;
	do {
		func2 = lf->inicio;
		do {
			if(strcmp(func2->nome, func2->prox->nome) > 0) {
				strcpy(nomeAux, func2->nome);
				matriAux = func2->matricula;
				idadeAux = func2->idade;
				strcpy(func2->nome, func2->prox->nome);
				func2->matricula = func2->prox->matricula;
				func2->idade = func2->prox->idade;
				strcpy(func2->prox->nome, nomeAux);
				func2->prox->matricula = matriAux;
				func2->prox->idade = idadeAux;
			}
			func2 = func2->prox;
		}while( func2 != lf->fim);
		
		func1 = func1->prox;
	} while(func1 != lf->inicio);
	
}

// Estrutua de fila para estacionamento com 2 portoes.

typedef struct filaEstacionamento2Portoes {
	Carro *fim;
	Carro *inicio;
	int numCarros;
} FE;

FE* criarFilaEstacionamento() {
	FE *fe = (FE*) malloc(sizeof(FE));
	return fe;
}

void inicializarFilaEstacionamento(FE *fe) {
	fe->fim = NULL;
	fe->inicio = NULL;
	fe->numCarros = 0;
}

void adicionarCarroFilaEstacionamento(Carro *c, FE *fe) {
	if(fe->inicio == NULL) {
		c->ant = NULL;
		c->prox = NULL;
		fe->fim = c;
		fe->inicio = c;
	}
	else {
		c->ant = NULL;
		c->prox = fe->inicio;
		fe->inicio->ant = c;
		fe->inicio = c;
	}
	fe->numCarros++;
}

void adicionarCarroFinalFila(Carro *c, FE *fe) {
	if(fe->inicio == NULL) {
		fe->inicio = c;
		fe->fim = c;
		c->ant = NULL;
		c->prox = NULL;
	} 
	else {
		fe->fim->prox = c;
		c->ant = fe->fim;
		c->prox = NULL;
		fe->fim = c;
	}
	fe->numCarros++;
}

Carro* retirarCarroFilaPeloInicio(FE *fe) {
	Carro *aux = fe->inicio;
	if(aux == fe->fim) {
		fe->inicio = NULL;
		fe->fim = NULL;
		fe->numCarros--;
	}
	else {
		fe->inicio = aux->prox;
		fe->inicio->ant = NULL;
		fe->numCarros--;
	}
	return aux;
}

Carro* retirarCarroFilaPeloFim(FE *fe) {
	Carro *aux = fe->fim;
	if(aux == fe->inicio) {
		fe->inicio = NULL;
		fe->fim = NULL;
		fe->numCarros--;
	}
	else {
		fe->fim = aux->ant;
		fe->fim->prox = NULL;
		fe->numCarros--;
	}
	return aux;
	
}

int buscarPosicaoCarroFila(char *placa, FE *fe) {
	int posicao = 1;
	Carro *aux = fe->inicio;
	while(aux != NULL) {
		if(strcmp(placa, aux->placa) == 0) {
			return posicao;
		}
		aux = aux->prox;
		posicao++;
	}
	return -1;
}

int buscarHoraEntradaFilaEstacionamento(char *placa, FE *fe) {
	Carro *aux = fe->inicio;
	while(aux != NULL) {
		if(strcmp(aux->placa, placa) == 0)
			return aux->horaEntrada;
		aux = aux->prox;
	}
	return -1;
}

void imprimirFilaEstacionamento(FE *fe) {
	if(fe->inicio == NULL) {
		printf(" Estacionamento vazio.\n");
		return;
	}
	Carro *aux = fe->inicio;
	printf(" Portao1 ## |");
	while(aux != NULL) {
		printf(" Placa: %s |", aux->placa);
		aux = aux->prox;
	}
	printf(" ## Portao2\n");
}

// FUNCOES DO PROGRAMA

void entrarCarroEstacionamento(PE* pe, LF* lf ) {
	if(pe->numCarros == MAXVAGAS) {
		printf("O estacionamento esta lotado!\n");
		return;
	}
	Carro *car = criarCarro();
	
	printf("Informe a placa do carro: ");
	scanf(" %[^\n]", car->placa);
	
	printf("Informe a hora da entrada: ");
	scanf("%d", &car->horaEntrada);
	
	printf(" O carro de placa %s entrou.\n", car->placa);
	printf(" O funcionario %s manobrou o carro para dentro.\n", lf->manobrista->nome);
	printf(" Total de carros: %d\n", pe->numCarros);
	if(pe->numCarros == MAXVAGAS)
		printf(" O estacionamento esta lotado!\n");
	lf->manobrista = lf->manobrista->prox;
	numManobras++;
}

void sairCarroEstacionamento(PE *pe, LF *lf) {
	char placa[10];
	printf("Informe a placa do carro: ");
	getchar();
	scanf("%s", placa);
	
	int busca = buscarCarroEstacionamento(placa, pe);
	if(busca == 0) {
		printf(" Esse carro nao foi encontrado\n");
		return;
	}
	int horaEntrada = buscarHoraEntrada(placa, pe);
	int horaSaida;
	
	do {
		printf("Hora de entrada %dh\n", horaEntrada);
		printf("Informe o horario de saida (24h): ");
		scanf("%d", &horaSaida);
		if(horaSaida < horaEntrada)
			printf(" ERRO! hora de saida menor que hora de entrada.\n");
	} while(horaSaida < horaEntrada);
	if(horaEntrada == horaSaida)
		arrecadacao += 12;
	else
		arrecadacao += (horaSaida - horaEntrada) * 12;

	PF *pf = criarPilhaFora();
	inicializarPilhaFora(pf);
	
	Carro *aux;
	do {
		aux = retirarCarroEstacionamento(pe);
		printf(" O carro de placa %s foi manobrado para fora pelo funcionario %s.\n", aux->placa, lf->manobrista->nome);
		lf->manobrista = lf->manobrista->prox;
		numManobras++;
		if(strcmp(aux->placa, placa) == 0) {
			printf(" O carro de placa %s foi embora.\n", aux->placa);
		}
		else {
			adicionarCarroFora(aux, pf);
		}
		
	} while(strcmp(aux->placa, placa) != 0);
	free(aux);
	
	Carro *aux2;
	do {
		aux2 = retirarCarroFora(pf);
		if(aux2 != NULL) {
			adicionarCarroEstacionamento(aux2, pe);
			printf(" O carro de placa %s foi manobrado para dentro pelo funcionario %s.\n", aux2->placa, lf->manobrista->nome);
			lf->manobrista = lf->manobrista->prox;
			numManobras++;
		}
	} while(aux2 != NULL);
	free(aux2);
	printf(" Total de carros: %d\n", pe->numCarros);
}

void entrarCarroEstacionamento2Portoes(FE *fe, LF *lf) {
	if(fe->numCarros == MAXVAGAS) {
		printf("O estacionamento esta lotado!\n");
		return;
	}
	Carro *car = criarCarro();
	
	printf("Informe a placa do carro: ");
	scanf(" %[^\n]", car->placa);
	
	printf("Informe a hora da entrada: ");
	scanf("%d", &car->horaEntrada);
	
	adicionarCarroFilaEstacionamento(car, fe);
	
	printf(" O carro de placa %s entrou.\n", car->placa);
	printf(" O funcionario %s manobrou o carro para dentro.\n", lf->manobrista->nome);
	printf(" Total de carros: %d\n", fe->numCarros);
	if(fe->numCarros == MAXVAGAS)
		printf(" O estacionamento esta lotado!\n");
	lf->manobrista = lf->manobrista->prox;
	numManobras++;
}

void sairCarroEstacionamento2Portoes(FE *fe, LF *lf) {
	char placa[10];
	int posicaoCarro;
	
	printf("Informe a placa do carro: ");
	scanf(" %s", placa);
	
	posicaoCarro = buscarPosicaoCarroFila(placa, fe);
	if(posicaoCarro < 0) {
		printf(" Esse carro nao foi encontrado!\n");
		return;
	}
	int horaEntrada = buscarHoraEntradaFilaEstacionamento(placa, fe);
	int horaSaida;
	do {
		printf("Hora de entrada %dh\n", horaEntrada);
		printf("Informe o horario de saida (24h): ");
		scanf("%d", &horaSaida);
		if(horaSaida < horaEntrada)
			printf(" ERRO! hora de saida menor que hora de entrada.\n");
	} while(horaSaida < horaEntrada);
	
	if(horaEntrada == horaSaida)
		arrecadacao += 12;
	else
		arrecadacao += (horaSaida - horaEntrada) * 12;
		
	int meioFilaEstacionamento = fe->numCarros/2;
	
	PF *pf = criarPilhaFora();
	inicializarPilhaFora(pf);
	Carro *aux;

	//printf("Posicao carro: %d\n", posicaoCarro);
	//printf("Meio fila: %d\n", meioFilaEstacionamento);
	
	if(posicaoCarro <= meioFilaEstacionamento) {
		do {
			aux = retirarCarroFilaPeloInicio(fe);
			printf(" O carro de placa %s foi manobrado para fora pelo funcionario %s.\n", aux->placa, lf->manobrista->nome);
			lf->manobrista = lf->manobrista->prox;
			numManobras++;
			
			if(strcmp(aux->placa, placa) == 0) {
				printf(" O carro de placa %s foi embora.\n", aux->placa);
			}
			else {
				adicionarCarroFora(aux, pf);
			}
			
		} while(strcmp(aux->placa, placa) != 0);
		free(aux);
		
		Carro *aux2;
		do {
			aux2 = retirarCarroFora(pf);
			if(aux2 != NULL) {
				adicionarCarroFilaEstacionamento(aux2, fe);
				printf(" O carro de placa %s foi manobrado para dentro pelo funcionario %s.\n", aux2->placa, lf->manobrista->nome);
				lf->manobrista = lf->manobrista->prox;
				numManobras++;
			}
				
		} while(aux2 != NULL);
		free(aux2);
		
		printf(" Total de carros: %d\n", fe->numCarros);
	}
	
	else {
		do {
			aux = retirarCarroFilaPeloFim(fe);
			printf(" O carro de placa %s foi manobrado para fora pelo funcionario %s.\n", aux->placa, lf->manobrista->nome);
			lf->manobrista = lf->manobrista->prox;
			numManobras++;
			
			if(strcmp(aux->placa, placa) == 0) {
				printf(" O carro de placa %s foi embora.\n", aux->placa);
			}
			else {
				adicionarCarroFora(aux, pf);
			}
			
		} while(strcmp(aux->placa, placa) != 0);
		free(aux);
		
		Carro *aux2;
	
		do {
			aux2 = retirarCarroFora(pf);
			if(aux2 != NULL) {
				adicionarCarroFinalFila(aux2, fe);
				printf(" O carro de placa %s foi manobrado para dentro pelo funcionario %s.\n", aux2->placa, lf->manobrista->nome);
				lf->manobrista = lf->manobrista->prox;
				numManobras++;
			}
				
		} while(aux2 != NULL);
		free(aux2);
		
		printf(" Total de carros: %d\n", fe->numCarros);
	}
}

void cadastrarFuncionario(LF *lf) {
	Func *f = criarFuncionario();
	printf("Informe o nome do funcionario: ");
	scanf(" %[^\n]", f->nome);
	printf("Informe a matricula do funcionario: ");
	scanf("%d", &f->matricula);
	printf("Informe a idade do funcionario: ");
	scanf("%d", &f->idade);
	adicionarFuncionario(f, lf);
	printf("Funcionario cadastrado.\n");
}

void menuDeOpcoes(PE* pe, PF *pf, FE* fe, LF *lf) {
	int opcao;
	do {
		printf(" \n== Informacoes do sitema ==\n");
		if(numPortoes == 1) {
			printf("O estacionamento tem apenas um portao de acesso.\n");
			printf("Total de carros: %d\n", pe->numCarros);
			printf("Numero de manobras: %d\n", numManobras);
			printf("Arrecadacao: R$ %.2f\n\n", arrecadacao);
			imprimirEstacionamento(pe);
		}
		else {
			printf("O estacionamento tem dois portoes de acesso.\n");
			printf("Total de carros: %d\n", fe->numCarros);
			printf("Numero de manobras: %d\n", numManobras);
			printf("Arrecadacao: R$ %.2f\n\n", arrecadacao);
			imprimirFilaEstacionamento(fe);
		}
		printf(" \n== Menu SW Gereciamento de Carros ==\n");
		printf("1- Etrar Carro\n");
		printf("2- Sair Carro\n");
		printf("3- Cadastrar Funcionario\n");
		printf("4- Ordenar Funcionarios\n");
		printf("5- Sair\n");
		scanf("%d", &opcao);
		
		switch(opcao) {
			case(1):
				printf("== Entrada de Carros ==\n");
				if(numPortoes == 1) {
					entrarCarroEstacionamento(pe,lf);
				}
				else {
					entrarCarroEstacionamento2Portoes(fe, lf);
				}
				break;
			
			case(2):
				printf("== Saida de Carros ==\n");
				if(numPortoes == 1) {
					sairCarroEstacionamento(pe,lf);
				}
				else {
					sairCarroEstacionamento2Portoes(fe, lf);
				}
				break;
			
			case(3):
				printf("== Cadastrar Funcionario ==\n");
				cadastrarFuncionario(lf);
				break;
			
			case(4):
				printf("== Ordenar Funcionarios ==\n");
				int op;
				printf("1- Ordenar por nome\n");
				printf("2- Ordenar por idade\n");
				printf("3- Ordenar por matricula\n");
				scanf("%d", &op);
				if(op == 1) {
					ordenarFuncionariosNome(lf);
					imprimirFuncionarios(lf);
				}
				else if(op == 2) {
					ordenarFuncionariosIdade(lf);
					imprimirFuncionarios(lf);
				}
				else if(op == 3) {
					ordenarFuncionariosMatricula(lf);
					imprimirFuncionarios(lf);
				}
				else {
					printf("Opcao invalida!\n");
				}
				
				break;
			
			case(5):
				printf(" Encerrando Programa...\n");
				break;
			
			default:
				printf(" Opcao invalida! Tente novamente.");
		}
	} while(opcao != 5);
	
}


int main() {
	
	// estacionamento
	PE *pe = criarPilhaEstacionamento();
	inicializarPilhaEstacionamento(pe);
	
	// lado fora
	PF *pf = criarPilhaFora();
	inicializarPilhaFora(pf);
	
	Carro *c1 = criarCarro();
	strcpy(c1->placa, "MUI1211");
	c1->horaEntrada = 1;
	adicionarCarroEstacionamento(c1, pe);
	
	Carro *c2 = criarCarro();
	strcpy(c2->placa, "BCC3456");
	c2->horaEntrada = 1;
	adicionarCarroEstacionamento(c2, pe);
	
	
    /// Lista funcionario
    Func *f1 = criarFuncionario();
	strcpy(f1->nome, "Pereira");
	f1->idade = 67;
	f1->matricula = 5555;
	
	Func *f2 = criarFuncionario();
	strcpy(f2->nome, "Robervaldo");
	f2->idade = 30;
	f2->matricula = 2222;
	
	Func *f3 = criarFuncionario();
	strcpy(f3->nome, "Juquinha");
	f3->idade = 12;
	f3->matricula = 6666;
	
	LF *lf = criarListaFuncionarios();
	inicializarListaFuncionarios(lf);

	adicionarFuncionario(f1, lf);
	adicionarFuncionario(f2, lf);
	adicionarFuncionario(f3, lf);

	// Fila Estacionamento
	FE *fe = criarFilaEstacionamento();
	inicializarFilaEstacionamento(fe);
	adicionarCarroFilaEstacionamento(c1, fe);
	adicionarCarroFilaEstacionamento(c2, fe);
	//imprimirFilaEstacionamento(fe);
	
	menuDeOpcoes(pe, pf, fe, lf);
	
	return 0;
}

