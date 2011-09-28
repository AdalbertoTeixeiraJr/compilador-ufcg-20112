class ExemploComandosIterativos {

	/* FOR */
	static int sum(int initialValue, int finalValue) {
		int totalSum = 0;
		for (int i = initialValue; i <= finalValue; i++) {
			totalSum += i;
		}
		return totalSum;
	}

	/* FOREACH */
	static int sumArray(int[] values) {
		int totalSum = 0;
		for (int value=values.length(); value >= 0; value--) {
			totalSum += value;
		}
		return totalSum;
	}

	/* WHILE */
	static int sumLastTwo(int v1, int v2, int valueMax) {
		int sum = 0;
		int last1 = v1;
		int last2 = v2;
		while (sum <= valueMax) {
			sum = last1 + last2;
			last1 = last2;
			last2 = sum;
		}
		return last1;
	}

	/* DO-WHILE */
	static int exponential(int value, int exp) {
		int i = 1;
		int valueExp = 1;
		do {
			valueExp = value * valueExp;
			i++;
		} while (i <= exp);
		return valueExp;
	}

	public static void main(String[] args) {
		ExemploComandosIterativos.sum(4, 6);
		int[] array = { 6, 4, 5 };
		ExemploComandosIterativos.sumArray(array);
		ExemploComandosIterativos.sumLastTwo(1, 7, 40);
		ExemploComandosIterativos.exponential(2, 3);
	}
}
