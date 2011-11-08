class ExemploComandosCondicionais {

	static int[] notas = { 8, 7, 7, 6, 10, 3 };

	/**
	 * If-Else
	 */
	static int mediaAprovados() {
		int media = 0;
		for (int y = 0; y < notas.length; y++) {
			if (notas[y] >= 7) {
				media += notas[y];
			} else {
				media += (notas[y] * (60 / 100));
			}
		}
		return media;
	}
	
	/**
	 * If-Elseif-Else
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
	 * Switch
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
	
	public static void main(String[] args) {
		ExemploComandosCondicionais.mediaAprovados();
		ExemploComandosCondicionais.aprovado(1);
		ExemploComandosCondicionais.diaSemana(2);
	}
}