import java.util.Scanner;

public class Main {
	
	// Variaveis globais
	public static final int MAX_ALUNOS = 10; // limite maximo 10 alunos.
	public static int quantAlunos = 0;
	public static Aluno alunos[] = new Aluno[MAX_ALUNOS]; 
	public static Scanner input = new Scanner(System.in);
	
	// Instanciando um aluno
	public static void instanciarObjeto() {
		System.out.println("-- Instanciando Aluno --");
		
		if(quantAlunos == MAX_ALUNOS) {
			System.out.println("Impossivel instanciar. Turma cheia!!!");
			return ;	
		}
		
		System.out.println("Informe a matrícula do aluno: ");
		String matricula = input.nextLine();
		
		System.out.println("Informe o nome do aluno: ");
		String nome = input.nextLine();
		
		System.out.println("Informe o codigo do curso: ");
		int curso = input.nextInt();
		input.nextLine();
		
		Aluno a = new Aluno(matricula, nome, curso);
		System.out.println("Aluno cadastrado com sucesso.");
		alunos[quantAlunos] = a;
		quantAlunos++;
	}
	
	// Imprimir matriz string com os dados do alunos
	public static String[][] criarMatriz() {
		String[][] matrizDados = new String[quantAlunos][3];
		
		for(int i=0; i< quantAlunos; i++) {
			matrizDados[i][0] = alunos[i].getMatricula();
			matrizDados[i][1] = alunos[i].getNome();
			matrizDados[i][2] = Integer.toString(alunos[i].getCurso());
		}
		return matrizDados;
	}
	
	public static void imprimirMatriz(String[][] matrizDados) {
		for(int i=0; i<quantAlunos; i++) {
			System.out.println(matrizDados[i][0]+"  "+matrizDados[i][1]+"  " + matrizDados[i][2]);
		}
	}
	
	public static void imprimirMatrizDados() {
		if(quantAlunos == 0) {
			System.out.println("A turma não possui alunos!!!");
			return ;
		}
		System.out.println("-- Imprimindo Dados Dos Alunos --");
		System.out.println("Matrícula | Nome | Código do curso");
		String m[][] = criarMatriz();
		imprimirMatriz(m);
	}
	
	// Alterar conteudo de um objeto
	public static int pegarIndiceMatricula() {
		String matricula;
		System.out.println("Informe a matricula do aluno:");
		matricula = input.nextLine();
		for(int i=0; i< quantAlunos; i++) {
			if(matricula.equals(alunos[i].getMatricula()))
				return i;
		}
		return -1;
	}
	
	public static void alterarObjeto() {
		if(quantAlunos == 0) {
			System.out.println("A turma não possui alunos!!!");
			return ;
		}
		System.out.println("-- Alterando Dados de Aluno --");
		int matricula = pegarIndiceMatricula();
		if(matricula != -1) {
			System.out.println("Informe o nome do aluno:");
			String nome = input.nextLine();
			alunos[matricula].setNome(nome);
			System.out.println("Informe o codigo do curso:");
			int curso = input.nextInt();
			alunos[matricula].setCurso(curso);
			System.out.println("Dados alterados com sucesso.");
		}
		else {
			System.out.println("Matricula nao encontrada!!!");
		}
	}
	
	// Apagandos dados de um objeto aluno
	public static void apagarObjeto() {
		if(quantAlunos == 0) {
			System.out.println("A turma não possui alunos!!!");
			return ;
		}
		System.out.println("-- Apagando Dados de Aluno --");
		int matricula = pegarIndiceMatricula();
		if(matricula != -1) {
			for(int i= matricula; i< quantAlunos-1; i++) {
				alunos[i] = alunos[i+1];
			}
			System.out.println("Aluno removido com sucesso.");
			quantAlunos--;
		}
		else {
			System.out.println("Matricula nao encontrda!!!");
		}
	}
	
	public static void menu() {
		int opcao;
		do {
			System.out.println("\n-----MENU DE OPÇÔES-----");
			System.out.println("1. Instanciar aluno");
			System.out.println("2. Criar matriz e imprimir");
			System.out.println("3. Alterar aluno");
			System.out.println("4. Excluir aluno");
			System.out.println("5. Sair");
			opcao = input.nextInt();
			input.nextLine();
			
			switch(opcao) {
				case 1: 
					instanciarObjeto();
					break;
				case 2:
					imprimirMatrizDados();
					break;
				case 3:
					alterarObjeto();
					break;
				case 4:
					apagarObjeto();
					break;
				case 5:
					System.out.println("Programa encerrado.");
					break;
				default:
					System.out.println("Opção invállida. Tente novamente!!!");
			}
			
		} while(opcao != 5);
	}
	
	public static void main(String[] args) {
		menu();
	}
}
