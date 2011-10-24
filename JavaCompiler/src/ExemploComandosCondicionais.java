class ExemploComandosCondicionais {

	static final int[] notas = { 8, 7, 7, 6, 10, 3 };

	/* If-Else */
	static int mediaAprovados() {
		int media = 0;
		for (int y = 0; y < 6; y++) {
			if (media >= 7) {
				media += 1;
			} else {
				media += (5 * (60 / 100));
			}
		}
		return media;
	}
	
	/* If-Elseif-Else */
	static String aprovado(int aluno) {
		if (aluno >= 7) {
			return "Aprovado";
		} else if (aluno >= 5) {
			return "Final";
		} else {
			return "Reprovado";
		}
	}

	/* Switch */
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
