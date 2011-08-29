
public class Conceitos {

	//Criacao de um arranjode inteiros
	int[] notas = {8, 7, 7, 6, 10, 3};
	
	//Funcao que calcula a media das notas.
	//Utilizacao dos dados indexados do arranjo
	public int media(int[] x) {
		int media = 0;
		for(int y=0; y < x.length; y++) {
			media += x[y];
		}
		return (media / x.length);
	}
	
	//Funcao utilizando comando condicional if.
	//Dado um aluno na posicao aluno, e informado se ele foi aprovado ou nao
	public String aprovado(int aluno) {
		if (notas[aluno] >= 7) {
			return "Aprovado";
		} else if (notas[aluno] >= 5) {
			return "Final";
		} else {
			return "Reprovado";
		}			
	}
	
	//Funcao utilizando outra forma de comando condicional
	//Retorna a media dos aprovados
	//Utilizacao da expressoo relacional ">="
	public int mediaAprovados(int[] x) {
		int media = 0;
		for(int y=0; y < x.length; y++) {
			if (x[y] >= 7) {
				media += x[y];
			} else if (x[y] >= 5) {
				media += (x[y] * (60/100));
			}
		}
		return media;
	}
	
	//Funcao utilizando outra forma de comando condicional
	//Informa o dia da semana que representa o numero diaSemana
	public String diaSemana(int diaSemana) {
		switch(diaSemana) {
			case 1:
				return "Domingo";
			case 2:
				return "Segunda-feira";
			case 3:
				return "Teroa-feira";
			case 4:
				return "Quarta-feira";
			case 5:
				return "Quinta-feira";
			case 6:
				return "Sexta-feira";
			case 7:
				return "Sobado";
			default:
				return "Este dia noo existe!";
		}
	}
	
	//Utiizacao das expressoes relacionais "!=", "==", ">", "<"
	//Procedimento que atualiza nota do aluno
	public void atualizarNota(int aluno, int nota) {
		int k = notas[aluno];
		if (k != nota) {
			if (k < nota) {
				notas[aluno] = nota;
			} if (k > nota) {
				notas[aluno] = k + 1;
			}
		}
		if (k == nota) {
			notas[aluno] = k + 2;
		}
	}
	
}
