package project_2023_02_14;

public class Problemsolve2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String str = "12345";
		
		int sum = 0;
		
		for(int i = 0 ; i < str.length(); i++)
		{
			sum += str.charAt(i) - 48;
		}
		
		System.out.println("sum = " + sum);
	}

}
