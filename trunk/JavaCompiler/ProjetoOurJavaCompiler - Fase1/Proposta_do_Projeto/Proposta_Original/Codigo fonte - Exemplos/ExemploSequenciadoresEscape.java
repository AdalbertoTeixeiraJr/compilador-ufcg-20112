class ExemploSequenciadoresEscape {

	/**
	 * BREAK
	 */
	static void calculateTable(int value) {
		int mult = 1;
		while (true) {
			if (mult > 10)
				break;
			else {
				System.out.println(value + " * " + mult + " = "
						+ (value * mult));
				mult++;
			}
		}
	}

	/**
	 * GOTO
	 */
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
						System.out.println(value + " * " + mult + " = "
								+ (value * mult));
						mult++;
					}
				}
			}
		}
	}

	/**
	 * RETURN
	 */
	static int calculateSquare(int x) {
		return x * x;
	}

	/**
	 * CONTINUE
	 */
	static void calculateSquares(int initialValue, int finalValue) {
		for (int i = initialValue; i <= finalValue; i++) {
			if (i == 0)
				continue;
			else
				System.out.println("Square (" + i + ") : " + (i * i));
		}
	}

	public static void main(String[] args) {

		ExemploSequenciadoresEscape.calculateTable(4);
		ExemploSequenciadoresEscape.increaseGrade(-1);
		System.out.println(ExemploSequenciadoresEscape.calculateSquare(7));
		ExemploSequenciadoresEscape.calculateSquares(-4, 7);
	}
}