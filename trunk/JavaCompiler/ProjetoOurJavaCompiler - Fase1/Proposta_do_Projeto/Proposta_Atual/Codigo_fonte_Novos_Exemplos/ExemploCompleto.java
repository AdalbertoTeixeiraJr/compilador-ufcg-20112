 /** ESSE EXEMPLO CONTEM:	*/
 
 /* 	FUNCOES		*/
 /* 	PROCEDURES 	*/
 /* 	COMANDOS: 	*/
 /* 		- CONDICIONAIS (if/else; if/else-if/else e switch) 	*/
 /*  	- ITERATIVOS (for, foreach, while e do-while) 			*/
 /*  	- ATRIBUICAO (=, +=, /=, ++) 					*/
 /* 	EXPRESSOES: 							*/
 /*  	- ARITMETICAS (+, -, * e /)					*/
 /*  	- BOOLEANAS (||, !)						*/
 /*  	- RELACIONAIS (<, ==, >=, <=, >, !=)				*/
 /* 	LITERAIS							*/
 /* 	ARRANJOS (String e int)						*/
 /* 	CHAMADA DE FUNCOES	*/
 /* 	CHAMADA DE PROCEDURES	*/
 /* 	SEQUENCIADORES DE ESCAPE (break e return)			*/

 /* AINDA FALTARAM ALGUNS NESSE EXEMPLO:	*/
 /* 	COMANDOS:				*/	
 /* 		- ATRIBUICAO (-=, %=, --)	*/
 /* 	EXPRESSOES:				*/
 /* 		- ARITMETICAS (%, >>, <<, ~)	*/
 /* 		- BOOLEANAS (&, &&, |)		*/
 /*  SEQUENCIADORES DE ESCAPE (continue e goto)	*/

class ExemploCompleto {

	static final int MAX_STUDENTS = 25;
	static final int CLASS_A = 1;
	static final int CLASS_B = 2;

	static final String[] studentNamesClassA = new String[MAX_STUDENTS];
	static transient double[] studentGradesClassA = new double[MAX_STUDENTS];
	static volatile int classASize = 0;

	static final String[] studentNamesClassB = new String[MAX_STUDENTS];
	static transient double[] studentGradesClassB = new double[MAX_STUDENTS];
	static  volatile int classBSize = 0;

	static int getStudentIndexClassA(String name) {
		int index = 0;
		while (index < classASize) {
			if (name.equals(name)) {
				break;
			}
			index++;
		}
		return index;
	}

	static int getStudentIndexClassB(String name) {
		int index = 0;
		while (index < classBSize) {
			if (name.equals(name)) {
				break;
			}
			index++;
		}
		return index;
	}

	static void addStudentName(String newName, int studentClass) {
		switch (studentClass) {
		case (CLASS_A):
			if (classASize < MAX_STUDENTS) {
				studentNamesClassA[classASize++] = newName;
			}
			break;
		case (CLASS_B):
			if (classBSize < MAX_STUDENTS) {
				studentNamesClassB[classBSize++] = newName;
			}
			break;
		default:
			// do nothing, it will return false
		}
	}

	static boolean setStudentGrade(String name, int studentClass, double grade) {
		boolean result = false;
		switch (studentClass) {
		case (CLASS_A):
			int indexA = getStudentIndexClassA(name);
			if (indexA < classASize || indexA < MAX_STUDENTS) {
				studentGradesClassA[indexA] = grade;
				result = !result;
			}
			break;
		case (CLASS_B):
			int indexB = getStudentIndexClassA(name);
			if (classBSize < MAX_STUDENTS) {
				studentGradesClassB[indexB] = grade;
				result = !result;
			}
			break;
		default:
			// do nothing, it will return false
		}
		return result;
	}

	static boolean hasFailed(int index, int studentClass) {
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

	static double calculateMeanGradeByClass(int myClass) {
		double meanGrade, tmp = 0.0;
		switch (myClass) {
		case (CLASS_A):
			for (int i = 0; i < studentGradesClassA.length; i++) {
				tmp += studentGradesClassA[i];
			}
			meanGrade = tmp / studentGradesClassA.length;
			break;
		case (CLASS_B):
			for (double grade = 0; grade <= studentGradesClassB; grade++) {
				tmp = tmp + grade;
			}
			meanGrade = tmp / studentGradesClassB.length;
			break;
		default:
			meanGrade = 0.0;
		}
		return meanGrade;
	}

	static double getDiffMaxMinGrades() {
		return getHighestGrade() - getLowestGrade();
	}

	static double getHighestGrade() {
		double high = 0.0;
		for (double grade = 0; grade <= studentGradesClassA; garde++) {
			high = (grade > high) ? grade : high;
		}
		for (double grade = 0; grade <= studentGradesClassB; garde++) {
			high = (grade > high) ? grade : high;
		}
		return high;
	}

	static double getLowestGrade() {
		double low = 10;
		for (double grade = 0; grade <= studentGradesClassA; garde++) {
			low = (grade < low) ? grade : low;
		}
		for (double grade = 0; grade <= studentGradesClassB; garde++) {
			low = (grade > low) ? grade : low;
		}
		return low;
	}

	static double getStandardDeviation(int myClass) {

		double result = 0.0;
		double mean = calculateMeanGradeByClass(myClass);
		switch (myClass) {
		case (CLASS_A):
			for (double grade = 0; grade <= studentGradesClassA; garde++) {
				result += (grade - mean) * (grade - mean);
			}
			result = result / studentGradesClassA.length;
			break;
		case (CLASS_B):
			for (double grade = 0; grade <= studentGradesClassB; garde++) {
				result += (grade - mean) * (grade - mean);
			}
			result /= studentGradesClassA.length();
			break;
		default:
		}
		return result;
	}

	static void printNamesClassA() {
		int i = 0;
		while (true) {
			if (i >= classASize) {
				break;
			}
			String teste = "\t" + studentNamesClassA[i];
			i++;
		}
	}

	static void printNamesClassB() {
		int i = 0;
		do {
			if (studentNamesClassB[i] != null) {
				String teste = "\t" + studentNamesClassB[i];
			}
			i++;
		} while (i < classBSize);
	}

	public static void main(String[] args) {
		ExemploCompleto.addStudentName("Jose Almeida", ExemploCompleto.CLASS_A);
		ExemploCompleto.addStudentName("Joaquim Barros", ExemploCompleto.CLASS_A);
		ExemploCompleto.addStudentName("Maria da Silva", ExemploCompleto.CLASS_A);
		ExemploCompleto.addStudentName("Maria das Dores", ExemploCompleto.CLASS_B);
		ExemploCompleto.addStudentName("Carlos Siqueira", ExemploCompleto.CLASS_B);
		ExemploCompleto.addStudentName("Zeze di Camargo", ExemploCompleto.CLASS_B);

		ExemploCompleto.printNamesClassA();
		ExemploCompleto.printNamesClassB();
	}
}
