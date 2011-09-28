class ExemploLiterais {

	/**
	 * char, string, boolean, int, long, float e double
	 */
	public static void main(String[] args) {

		char c1 = 'a', c2 = 'z';
		char c3 = '1', c4 = '0';
		char c5 = 'n', c6 = 't', c7 = 'b';
		char c8 = 'r', c9 = 'f', c10 = '\';
		String s1 = "Compiladores", s2 = "X";
		String s3 = " Compiladores Java ";
		boolean b1 = true, b2 = false;
		int i1 = 190, i2 = 1800000;
		long l1 = -9019090910909190L, l2 = 18000009019019019L;
		float f1 = 1.0f, f2 = -6.09090f, f3 = 6.5E32f;
		float f4 = -3333.5E-12f, f5 = 908E18f, f6 = 7.010101010101f;
		double d1 = 1.0, d2 = -6.09090, d3 = 6.5E32;
		double d4 = -3333.5E-12, d5 = 908E188, d6 = 7.010101010101;

		if (true) {
			if (!false) {
				if ("Professores".length() > 10 && 'd' > 'a'
						&& "Compilar".charAt(0) == 'C') {
					String compiler = "JavaCompiler \\o/ Java Compiler";
					if (d1 > d2 || c2 > c3) {
						String concat = s1 + " " + s2 + " " + s3;
					}
				}
			}
		}
	}
}
