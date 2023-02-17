package CalculatorUse;

import Calculatorfactory.*;

public class Calculatorusercompany {

	public static void main(String[] args) {
		
		
		// TODO Auto-generated method stub
		Calculator_1 c2 = new Calculator_1("com", "Black");
		System.out.println("serialnum : " + c2.getserial());
		
		System.out.println(c2.getallinfo());

		
		c2.use_where = "company";
		
		System.out.println(c2.getallinfo());
		
		System.out.println(c2.plus(2, 4) + " | " + c2.plus(3.2, 4.6));
		System.out.println(c2.minus(7, 4) + " | " + c2.minus(7.7f, 4.2f));


	}

}
