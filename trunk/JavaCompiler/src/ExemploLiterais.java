class ExemploLiterais {

	/**
	 * Literais dos seguintes tipos: <br>
	 * char, string, boolean, int, long, float e double
	 */
	public static void main(String[] args) {

		char c1 = 'a', c2 = 'z';
		char c3 = '1', c4 = '0';
		char c5 = '\n', c6 = '\t', c7 = '\b', c8 = '\r', c9 = '\f', c10 = '\\', c11 = '\'';
		String s1 = "Compiladores", s2 = "X", s3 = "\"Compiladores\"", s4 = "Compil\\a\\dores";
		boolean b1 = true, b2 = false;
		int i1 = 190, i2 = 1800000;
		long l1 = -9019090910909190L, l2 = 18000009019019019L;
		float f1 = 1.0f, f2 = -6.09090f, f3 = 6.5E32f, f4 = -3333.5E-12f, f5 = 908E18f, f6 = 7.010101010101f;
		double d1 = 1.0, d2 = -6.09090, d3 = 6.5E32, d4 = -3333.5E-12, d5 = 908E188, d6 = 7.010101010101;

		if (true) {
			if (!false) {
				if ("Professores".length() > 10 && 'd' > 'a'
						&& "Compilar".charAt(0) == 'C') {
					System.out.println("JavaCompiler \\o/ Java Compiler");
					if (d1 > d2 || c2 > c3) {
						System.out.println(s1 + " " + s2 + " " + s3);
					}
				}
			}
		}
	}
}