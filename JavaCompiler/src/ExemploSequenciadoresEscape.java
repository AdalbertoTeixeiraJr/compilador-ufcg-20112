
class ExemploSequenciadoresEscape {

	/** 
	 *  BREAK
	 */
	void calculateTable(int value){
		int mult = 1;
		while(true){
			if(mult > 10) break;
			else {
				System.out.println(value + " * " + mult + " = " + (value*mult) );
				mult++;
			}
		}
		
	}
	
	
	/**
	 * RETURN
	 */
	int calculateSquare(int x){
		return x*x;		
	}
	
	
	
	/**
	 * CONTINUE
	 */
	void calculateSquares(int initialValue, int finalValue){
		for(int i = initialValue; i <= finalValue; i++){
			if(i==0) continue;
			else	System.out.println("Square (" + i + ") : " + (i*i) );
		}		
	}
	
	
	
	public static void main(String[] args) {
		ExemploSequenciadoresEscape e = new ExemploSequenciadoresEscape();
		e.calculateTable(4);
		System.out.println(e.calculateSquare(7));
		e.calculateSquares(-4, 7);
	}

}

