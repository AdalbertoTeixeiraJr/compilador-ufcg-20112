class ExemploComandosAtribuicao {

	/**
	 * = += ++
	 */
	static int sumCresc(int initialValue, int finalValue) {
		int sum = 0;
		int i = initialValue;
		while (i <= finalValue) {
			sum += i;
			i++;
		}
		return sum;
	}

	/**
	 * --
	 */
	static int sumDecresc(int initialValue, int finalValue) {
		int sum = 0;
		int i = initialValue;
		while (i >= finalValue) {
			sum += i;
			i--;
		}
		return sum;
	}

	/**
	 * -=
	 */
	static int decrement(int initialValue, int dec, int times) {
		int total = initialValue;
		for (int i = 0; i < times; i++)
			total -= dec;
		return total;
	}

	/**
	 * *=
	 */
	static int exp(int value, int exp) {
		int total = 1;
		for (int i = 0; i < exp; i++)
			total *= value;
		return total;
	}

	/**
	 * /=
	 */
	static int div(int value, int div, int times) {
		int finalValue = value;
		for (int i = 0; i < times; i++) {
			finalValue /= div;
			System.out.println(finalValue);
		}
		return finalValue;
	}

	/**
	 * %=
	 */
	static int mod(int value, int div) {
		value %= div;
		return value;
	}

	public static void main(String[] args) {
		System.out.println(ExemploComandosAtribuicao.sumCresc(2, 6));
		System.out.println(ExemploComandosAtribuicao.sumDecresc(8, 4));
		System.out.println(ExemploComandosAtribuicao.decrement(10, 2, 3));
		System.out.println(ExemploComandosAtribuicao.exp(2, 5));
		System.out.println(ExemploComandosAtribuicao.div(16, 2, 3));
		System.out.println(ExemploComandosAtribuicao.mod(10, 4));
	}
}