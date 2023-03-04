package project_2023_02_15;


public class exam5 {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		if(args.length != 2) {
			System.out.println("값 부족함");
			System.exit(0);
		}
		
		String strnum1 = args[0];
		String strnum2 = args[1];
		
		int num1 = Integer.parseInt(strnum1);
		int num2 = Integer.parseInt(strnum2);
		
		int result = num1 + num2;
		System.out.println(num1 + " + " + num2 + " = " + result);
	}

}
