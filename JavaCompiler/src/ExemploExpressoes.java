class ExemploExpressoes {

	/**
	 * +, -, /, *, uso de parenteses.
	 */
	static void expAritmeticas() {
		int a = 1 + 3;
		int b = a - 4;
		int c = 3 * (-4);
		int d = c / 2;
		int e = 14 % 3;
		int f = e + 5 - 1 + b;
		a = (b + c);
		b = (1 + 3) - c;
		a = (b + 4) * (5 - c);
		f = ((a + b) / 2);
	}

	/**
	 * |, &, !, &&, ||.
	 */
	static void expBooleanas() {
		boolean a = true;
		boolean b = false;
		boolean c = (a | b);
		boolean d = c & true;
		d = a && !b;
		boolean e = d || (b & c);
	}

	/**
	 * &, |, ^, ~.
	 */
	static void expBooleanasBitWise() {
		int a = 10;
		int b = 2;
		int c = a & b;
		int d = a | b;
		int e = a ^ b;
		int f = ~e;
	}

	public static void main(String[] args) {

		ExemploExpressoes.expAritmeticas();
		ExemploExpressoes.expBooleanas();
		ExemploExpressoes.expBooleanasBitWise();
	}
}
