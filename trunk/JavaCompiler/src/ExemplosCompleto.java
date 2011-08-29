/* ESSE EXEMPLO CONTEM:
 * 
 * 	FUNCOES
 * 	PROCEDURES
 * 	COMANDOS:
 * 		- CONDICIONAIS (if/else; if/else-if/else e switch)
 *  	- ITERATIVOS (for, foreach, while e do-while)
 *  	- ATRIBUICAO (=, +=, /=, ++)
 * 	EXPRESSOES:
 *  	- ARITMETICAS (+, -, * e /)
 *  	- BOOLEANAS (||, !)
 *  	- RELACIONAIS (<, ==, >=, <=, >, !=)
 * 	LITERAIS
 * 	ARRANJOS (String e int)
 * 	CHAMADA DE FUNCOES
 * 	CHAMADA DE PROCEDURES
 * 	SEQUENCIADORES DE ESCAPE (break e return)
 */

/* FALTA NESSE EXEMPLO:
 * 	COMANDOS:
 * 		- ATRIBUICAO (-=, %=, --)
 * 	EXPRESSOES:
 * 		- ARITMETICAS (%, >>, <<, ~)
 * 		- BOOLEANAS (&, &&, |)
 *  SEQUENCIADORES DE ESCAPE (continue)
 */

class ExemplosCompleto {

	final int MAX_STUDENTS = 25;
	final int CLASS_A = 1;
	final int CLASS_B = 2;

	String[] studentNamesClassA = new String[MAX_STUDENTS];
	double[] studentGradesClassA = new double[MAX_STUDENTS];
	int classASize = 0;

	String[] studentNamesClassB = new String[MAX_STUDENTS];
	double[] studentGradesClassB = new double[MAX_STUDENTS];
	int classBSize = 0;

	int getStudentIndexClassA(String name) {
		int index = 0;
		while (index < classASize) {
			if (name.equals(name)) {
				break;
			}
			index++;
		}
		return index;
	}

	int getStudentIndexClassB(String name) {
		int index = 0;
		while (index < classBSize) {
			if (name.equals(name)) {
				break;
			}
			index++;
		}
		return index;
	}

	void addStudentName(String newName, int studentClass) {
		switch (studentClass) {
		case (CLASS_A):
			if (classASize < MAX_STUDENTS) {
				this.studentNamesClassA[classASize++] = newName;
			}
			break;
		case (CLASS_B):
			if (classBSize < MAX_STUDENTS) {
				this.studentNamesClassB[classBSize++] = newName;
			}
			break;
		default:
			// do nothing, it will return false
		}
	}

	boolean setStudentGrade(String name, int studentClass, double grade) {
		boolean result = false;
		switch (studentClass) {
		case (CLASS_A):
			int indexA = getStudentIndexClassA(name);
			if (indexA < classASize || indexA < MAX_STUDENTS) {
				this.studentGradesClassA[indexA] = grade;
				result = !result;
			}
			break;
		case (CLASS_B):
			int indexB = getStudentIndexClassA(name);
			if (classBSize < MAX_STUDENTS) {
				this.studentGradesClassB[indexB] = grade;
				result = !result;
			}
			break;
		default:
			// do nothing, it will return false
		}
		return result;
	}

	boolean hasFailed(int index, int studentClass) {
		if (index >= 0) {
			if (studentClass == CLASS_A) {
				if (index <= classASize - 1)
					return (studentGradesClassA[index] < 5);
			} else if (studentClass == CLASS_B) {
				if (index <= classBSize - 1)
					return (studentGradesClassB[index] < 5);
			} else {
				return false;
			}
		}
		return false;
	}

	double calculateMeanGradeByClass(int myClass) {
		double meanGrade, tmp = 0.0;
		switch (myClass) {
		case (CLASS_A):
			for (int i = 0; i < studentGradesClassA.length; i++) {
				tmp += studentGradesClassA[i];
			}
			meanGrade = tmp / studentGradesClassA.length;
			break;
		case (CLASS_B):
			for (double grade : studentGradesClassB) {
				tmp = tmp + grade;
			}
			meanGrade = tmp / studentGradesClassB.length;
			break;
		default:
			meanGrade = 0.0;
		}
		return meanGrade;
	}

	double getDiffMaxMinGrades() {
		return getHighestGrade() - getLowestGrade();
	}

	double getHighestGrade() {
		double high = 0.0;
		for (double grade : studentGradesClassA) {
			high = (grade > high) ? grade : high;
		}
		for (double grade : studentGradesClassB) {
			high = (grade > high) ? grade : high;
		}
		return high;
	}

	double getLowestGrade() {
		double low = 10;
		for (double grade : studentGradesClassA) {
			low = (grade < low) ? grade : low;
		}
		for (double grade : studentGradesClassB) {
			low = (grade > low) ? grade : low;
		}
		return low;
	}

	double getStandardDeviation(int myClass) {

		double result = 0.0;
		double mean = calculateMeanGradeByClass(myClass);
		switch (myClass) {
		case (CLASS_A):
			for (double grade : studentGradesClassA) {
				result += (grade - mean) * (grade - mean);
			}
			result = result / studentGradesClassA.length;
			break;
		case (CLASS_B):
			for (double grade : studentGradesClassB) {
				result += (grade - mean) * (grade - mean);
			}
			result /= studentGradesClassA.length;
			break;
		default:
			//
		}
		return result;
	}

	void printNamesClassA() {
		System.out.println("Class A Students:");
		int i = 0;
		while (true) {
			if (i >= classASize) {
				break;
			}
			System.out.println("\t" + studentNamesClassA[i]);
			i++;
		}
	}

	void printNamesClassB() {
		System.out.println("Class B Students:");
		int i = 0;
		do {
			if (studentNamesClassB[i] != null) {
				System.out.println("\t" + studentNamesClassB[i]);
			}
			i++;
		} while (i < classBSize);
	}

	static void main(String[] args) {
		ExemplosCompleto c = new ExemplosCompleto();

		c.addStudentName("Jose Almeida", c.CLASS_A);
		c.addStudentName("Joaquim Barros", c.CLASS_A);
		c.addStudentName("Maria da Silva", c.CLASS_A);

		c.printNamesClassA();
		System.out.println();
		c.printNamesClassB();
	}

}
