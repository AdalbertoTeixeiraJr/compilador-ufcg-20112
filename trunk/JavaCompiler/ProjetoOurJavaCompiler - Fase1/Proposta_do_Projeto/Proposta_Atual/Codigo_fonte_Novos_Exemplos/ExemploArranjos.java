class ExemploArranjos {

	static final String[] nomes = { "Carlitos Tevez", "Ronaldo", "Romario", "Silvio Santos" };
	static final int[] notas = { 8, 7, 7, 6 };
	static final int[] notas2 = { 2, 10, 9, 10 };
	static transient double[] medias = { 0.0, 0.0, 0.0, 0.0 };

	public static void main(String[] args) {
		for (int y = 0; y < notas.length; y++) {
			medias[y] = (notas[y] + notas2[y]) / 2;
		}

		for (int i = 0; i < nomes.length; i++) {
			String a = "Estudante: " + nomes[i];
			String b = "Media: " + medias[i];
		}
	}
}
