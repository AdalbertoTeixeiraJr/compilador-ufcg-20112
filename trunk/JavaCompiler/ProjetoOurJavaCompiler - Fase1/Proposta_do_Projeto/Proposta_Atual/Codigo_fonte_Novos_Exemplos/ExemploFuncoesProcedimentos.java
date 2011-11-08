class ExemploFuncoesProcedimentos {

	static volatile int x = 0;
	static transient int[] y = { 1, 2, 3 };

	static int funcao1() {
		return 10;
	}

	static String funcao2() {
		return "string";
	}

	static int funcao3(int a) {
		return a;
	}

	static String funcao4(String b) {
		return b;
	}

	static double funcao5() {
		return 5.5;
	}

	static boolean funcao6(boolean a) {
		return true;
	}

	static int[] funcao7() {
		return y;
	}

	static void procedure1() {
		int x = 5 + 4;
	}

	static void procedure2() {
		y[1] = 55;
	}

	public static void main(String[] args) {
		ExemploFuncoesProcedimentos.funcao1();
		ExemploFuncoesProcedimentos.funcao2();
		ExemploFuncoesProcedimentos.funcao3(999);
		ExemploFuncoesProcedimentos.funcao4("Ola!");
		ExemploFuncoesProcedimentos.funcao5();
		ExemploFuncoesProcedimentos.funcao6(false);
		ExemploFuncoesProcedimentos.funcao7();
		ExemploFuncoesProcedimentos.procedure1();
		ExemploFuncoesProcedimentos.procedure2();
	}
}
