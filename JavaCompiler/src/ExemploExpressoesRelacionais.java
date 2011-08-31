class ExemploExpressoesRelacionais {

	static int[] notas = { 8, 7, 7, 6, 10, 3 };

	/**
	 * Utilizacao da expressao relacional ">="
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
	 *  Utiizacao das expressoes relacionais "!=", "==", ">", "<"
	 * Procedimento que atualiza nota do aluno
	 */
	static void atualizarNota(int aluno, int nota) {
		int k = notas[aluno];
		if (k != nota) {
			if (k < nota) {
				notas[aluno] = nota;
			}
			if (k > nota) {
				notas[aluno] = k + 1;
			}
		}
		if (k == nota) {
			notas[aluno] = k + 2;
		}
	}
}