class ExemploExpressoesAritmeticasBooleanas {

	/* +, -, /, *, uso de parenteses */
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

	/* |, &, !, &&, || */
	static void expBooleanas() {
		boolean a = true;
		boolean b = false;
		boolean c = (a || b);
		boolean d = c && true;
		boolean e = d || (b&& c);
	}

	/* &, |, ^, ~ */
	static void expBooleanasBitWise() {
		int a = 10;
		int c = a & a;
		int d = a | c;
		int e = a ^ d;
		a = ~a;
	}

	public static void main(String[] args) {
		ExemploExpressoesAritmeticasBooleanas.expAritmeticas();
		ExemploExpressoesAritmeticasBooleanas.expBooleanas();
		ExemploExpressoesAritmeticasBooleanas.expBooleanasBitWise();
	}
}
