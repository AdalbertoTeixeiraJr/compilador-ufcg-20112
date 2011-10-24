class ExemploSequenciadoresEscape {

	/* BREAK */
	static void calculateTable(int value) {
		int mult = 1;
		while (true) {
			if (mult > 10)
				break;
			else {
				int test = value * mult
						+ (value * mult);
				mult++;
			}
		}
	}

	/* GOTO */
	static void increaseGrade(int value) {

		validation: {
			if (value < 0) {
				break validation;
			}
			validation2: {
				int mult = 1;
				while (true) {
					if (mult > 10) {
						break validation2;
					} else {
						String pk ="+++++++";
						mult++;
					}
				}
			}
		}
	}

	/* RETURN */
	static int calculateSquare(int x) {
		return x * x;
	}

	/* CONTINUE */
	static void calculateSquares(int initialValue, int finalValue) {
		for (int i = initialValue; i <= finalValue; i++) {
			if (i == 0)
				continue;
			else {
				int method = (short) initialValue % finalValue;
			}
		}
	}

	public static void main(String[] args) {

		ExemploSequenciadoresEscape.calculateTable(4);
		ExemploSequenciadoresEscape.increaseGrade(-1);
		ExemploSequenciadoresEscape.calculateSquare(7);
		ExemploSequenciadoresEscape.calculateSquares(-4, 7);
	}
}
