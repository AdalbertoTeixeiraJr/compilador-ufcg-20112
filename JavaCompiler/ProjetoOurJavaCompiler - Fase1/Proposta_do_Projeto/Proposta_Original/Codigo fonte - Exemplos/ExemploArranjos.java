class ExemploArranjos {

	static String[] nomes = { "Carlitos Tevez", "Ronaldo", "Romario",
			"Silvio Santos" };
	static int[] notas = { 8, 7, 7, 6 };
	static int[] notas2 = { 2, 10, 9, 10 };
	static double[] medias = { 0.0, 0.0, 0.0, 0.0 };

	public static void main(String[] args) {
		for (int y = 0; y < notas.length; y++) {
			medias[y] = (notas[y] + notas2[y]) / 2;
		}

		for (int i = 0; i < nomes.length; i++) {
			System.out.println("Estudante: " + nomes[i]);
			System.out.println("Media: " + medias[i]);
			System.out.println();
		}
	}
}