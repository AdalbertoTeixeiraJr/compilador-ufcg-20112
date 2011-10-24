class ExemploArranjos {

	static final String[] nomes = { "Carlitos Tevez", "Ronaldo", "Romario", "Silvio Santos" };
	static final int[] notas = { 8, 7, 7, 6 };
	static final int[] notas2 = { 2, 10, 9, 10 };
	static double[][] medias = { { 0.0d}, { 0.0d, 0.0d} };

	public static void main(String[] args) {
		for (int y = 0; y < 4; y++) {
			int media = (ExemploArranjos.notas[0]) / 2;
		}

		for (int i = 0; i < 4; i++) {
			String a = "Estudante: " + ExemploArranjos.nomes[i];
			String b = "Media: " + ExemploArranjos.medias[i];
		}
	}
}
