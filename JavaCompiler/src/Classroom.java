
/* FIZEMOS:
 * 
 * FUNCOES
 * PROCEDURES
 * COMANDOS:
 * 	- CONDICIONAIS (if/else; if/elseif/else e switch)
 *  - ITERATIVOS (for, foreach, while e do-while)
 *  - ATRIBUICAO (=, +=, /=, ++)
 * EXPRESSÕES:
 *  - ARITMETICAS (+, -, * e /)
 *  - BOOLEANAS ()
 *  - RELACIONAIS (<, ==, >=, <= e >)
 * LITERAIS
 * ARRANJOS (String e int)
 * CHAMADA DE FUNCOES
 * SEQUENCIADORES DE ESCAPE (break e return)
 */

/* NAO FIZEMOS:
 * COMANDOS:
 * - ATRIBUICAO (-=, %=, --)
 * EXPRESSÕES:
 * - ARITMETICAS (%, >>, <<, ~)
 * - BOOLEANAS (&, &&, |, ||, !)
 * - RELACIONAIS (!=)
 * CHAMADA DE PROCEDURES
 * 
 */
public class Classroom {

	final int MAX_STUDENTS = 25;
	final int CLASS_A = 1;
	final int CLASS_B = 2;

	String[] studentNamesClassA = new String[MAX_STUDENTS];
	double[] studentGradesClassA = new double[MAX_STUDENTS];

	String[] studentNamesClassB = new String[MAX_STUDENTS];
	double[] studentGradesClassB = new double[MAX_STUDENTS];

	public void setStudentNamesClassA(String[] studentNames) {
		this.studentNamesClassA = studentNames;
	}

	public void setStudentNamesClassB(String[] studentNames) {
		this.studentNamesClassB = studentNames;
	}

	public void fillStudentNames() {

	}

	public void fillStudentGrades() {

	}

	public boolean hasFailed(int index, int studentClass) {
		if (index >= 0 && index <= MAX_STUDENTS - 1) {
			if (studentClass == CLASS_A) {
				return (studentGradesClassA[index] < 5);
			} else if (studentClass == CLASS_B) {
				return (studentGradesClassB[index] < 5);
			} else {
				return false;
			}
		}
		return false;
	}

	public double calculateMeanGradeByClass(int myClass) {
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

	public void printNamesClassA() {
		int i = 0;
		while (true) {
			if (i < MAX_STUDENTS){
				break;
			}
			System.out.println("Nome: " + studentNamesClassA[i]);
		}
	}

	public void printNamesClassB() {
		int i = 0;
		do {
			System.out.println("Nome: " + studentNamesClassB[i]);
		} while (i < MAX_STUDENTS);
	}

	public double getDiffMaxMinGrades() {
		return getHighestGrade() - getLowestGrade();
	}

	public double getHighestGrade() {
		double high = 0.0;
		for (double grade : studentGradesClassA) {
			high = (grade > high) ? grade : high;
		}
		for (double grade : studentGradesClassB) {
			high = (grade > high) ? grade : high;
		}
		return high;
	}

	public double getLowestGrade() {
		double low = 10;
		for (double grade : studentGradesClassA) {
			low = (grade < low) ? grade : low;
		}
		for (double grade : studentGradesClassB) {
			low = (grade > low) ? grade : low;
		}
		return low;
	}

	public double getStandardDeviation(int myClass) {

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

}
