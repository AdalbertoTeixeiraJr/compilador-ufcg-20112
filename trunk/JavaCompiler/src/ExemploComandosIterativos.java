
class ExemploComandosIterativos {

	/**
	 * FOR
	 */
	int sum (int initialValue, int finalValue){
		int totalSum = 0;
		for(int i = initialValue; i <= finalValue; i++ ){
			totalSum += i;
		}
		return totalSum;
		
	}
	
	/**
	 * FOREACH 
	 */
	int sumArray (int[] values){
		int totalSum = 0;
		for(int value : values){
			totalSum += value;
		}
		return totalSum;
	}
	
	/**
	 * WHILE
	 */
	int sumLastTwo(int v1, int v2, int valueMax){
		int sum = 0;
		int last1 = v1;
		int last2 = v2;
		while(sum <= valueMax){
			sum = last1 + last2;
			last1 = last2;
			last2 = sum;			
		}
		return last1;
	}
	
	/**
	 * DO-WHILE
	 */
	int exponential(int value, int exp){
		int i = 1;
		int valueExp = 1;
		do{
			valueExp = value * valueExp;
			i++;
		} while(i <= exp);
		return valueExp;
	}
	
	public static void main(String[] args) {
		ExemploComandosIterativos e = new ExemploComandosIterativos();
		System.out.println(e.sum(4,6));
		int[] array = {6,4,5};
		System.out.println(e.sumArray(array) );
		System.out.println(e.sumLastTwo(1, 7, 40));
		System.out.println(e.exponential(2, 3));
	}
	
	
}
