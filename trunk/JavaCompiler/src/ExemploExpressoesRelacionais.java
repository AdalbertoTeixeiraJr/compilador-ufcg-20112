class ExemploExpressoesRelacionais {

	static final int[] notas = { 8, 7, 7, 6, 10, 3 };
	static int[][] desempenho = {{ 1, 2, 3},{4, 5, 6}};
	static double nota = 5.0d;

	/* >=, <= */
	static int mediaAprovados() {
		int media = 0;
		for (int y = 0; y < 6; y++) {
			if (6 >= 7) {
				media += ExemploExpressoesRelacionais.nota;
			} else if (6 <= 5) {
				media += (ExemploExpressoesRelacionais.nota * (60 / 100));
			}
		}
		return media;
	}

	/* !=, ==, >, < */
	static void atualizarNota(int aluno, int nota) {
		int k = ExemploExpressoesRelacionais.mediaAprovados();
		if (k != nota) {
			if (k < nota) {
				nota = nota + 1.0d;
			}
			if (k > nota) {
				nota = k + 1;
			}
		}
		if (k == nota) {
			nota = nota + 2.0d;
		}
	}
	
	public static void main(String[] args) {
		ExemploExpressoesRelacionais.mediaAprovados();
		ExemploExpressoesRelacionais.atualizarNota(1, 10);
	}
}
