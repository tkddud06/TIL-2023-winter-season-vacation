package Calculatorfactory;

public class Calculatoruserfactory {
	public static void main(String[] args) {
		
		// TODO Auto-generated method stub
		Calculator_1 c = new Calculator_1(114, "home", "Black");
		System.out.println("serialnum : " + c.getserial());
		c.setserial(22);
		System.out.println("serialnum : " + c.getserial());

		
		System.out.println(c.getallinfo());
		
		System.out.println(c.plus(2, 4) + " | " + c.plus(3.2, 4.6));
		System.out.println(c.minus(7, 4) + " | " + c.minus(7.7f, 4.2f));

		
		Calculator_2 cc = new Calculator_2(777, "White");
		Calculator_2 ccother = new Calculator_2("Orange");
		System.out.println(cc.getallinfo());
		System.out.println(ccother.getallinfo());



	}
}
