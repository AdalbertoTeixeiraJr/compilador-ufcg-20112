class ExemploComandosCondicionais {

	static int[] notas = { 8, 7, 7, 6, 10, 3 };

	/**
	 * Funcao utilizando comando condicional if. Dado um aluno na posicao aluno,
	 * e informado se ele foi aprovado ou nao
	 */
	static String aprovado(int aluno) {
		if (notas[aluno] >= 7) {
			return "Aprovado";
		} else if (notas[aluno] >= 5) {
			return "Final";
		} else {
			return "Reprovado";
		}
	}

	/**
	 * Funcao utilizando outra forma de comando condicional Retorna a media dos
	 * aprovados
	 */
	static int mediaAprovados(int[] x) {
		int media = 0;
		for (int y = 0; y < x.length; y++) {
			if (x[y] >= 7) {
				media += x[y];
			} else if (x[y] >= 5) {
				media += (x[y] * (60 / 100));
			}
		}
		return media;
	}

	/**
	 * Funcao utilizando outra forma de comando condicional Informa o dia da
	 * semana que representa o numero diaSemana
	 */
	static String diaSemana(int diaSemana) {
		switch (diaSemana) {
		case 1:
			return "Domingo";
		case 2:
			return "Segunda-feira";
		case 3:
			return "Terca-feira";
		case 4:
			return "Quarta-feira";
		case 5:
			return "Quinta-feira";
		case 6:
			return "Sexta-feira";
		case 7:
			return "Sabado";
		default:
			return "Este dia nao existe!";
		}
	}
}