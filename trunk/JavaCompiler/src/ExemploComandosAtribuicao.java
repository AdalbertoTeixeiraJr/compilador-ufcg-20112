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
		ExemploComandosAtribuicao.sumCresc(2, 6);
		ExemploComandosAtribuicao.sumDecresc(8, 4);
		ExemploComandosAtribuicao.decrement(10, 2, 3);
		ExemploComandosAtribuicao.exp(2, 5);
		ExemploComandosAtribuicao.div(16, 2, 3);
		ExemploComandosAtribuicao.mod(10, 4);
	}
}
