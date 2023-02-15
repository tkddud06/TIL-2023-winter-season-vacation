package project_2023_02_14;

import java.util.Scanner;

public class Problemsolve5 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		System.out.print("수를 입력하세요 : ");
		int money = scanner.nextInt();
		int fh = 0, oh = 0, f = 0, o = 0;
		
		while (money >= 500)
		{
				money -= 500;
				fh++;
		}
		while (money >= 100)
		{
				money -= 100;
				oh++;	
		}
		while (money >= 50)
		{
				money -= 50;
				f++;	
		}
		while (money >= 10)
		{
				money -= 10;
				o++;
		}
		
		System.out.printf("500원 : %d\n100원 : %d\n50원 : %d\n10원 : %d",fh,oh,f,o);
		scanner.close();
	}

}
