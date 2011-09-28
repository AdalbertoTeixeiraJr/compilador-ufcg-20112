class ExemploExpressoesRelacionais {

	static final int[] notas = { 8, 7, 7, 6, 10, 3 };

	/* >=, <= */
	static int mediaAprovados() {
		int media = 0;
		for (int y = 0; y < notas.length; y++) {
			if (notas[y] >= 7) {
				media += notas[y];
			} else if (notas[y] <= 5) {
				media += (notas[y] * (60 / 100));
			}
		}
		return media;
	}

	/* !=, ==, >, < */
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
	
	public static void main(String[] args) {
		ExemploExpressoesRelacionais.mediaAprovados();
		ExemploExpressoesRelacionais.atualizarNota(1, 10);
	}
}
