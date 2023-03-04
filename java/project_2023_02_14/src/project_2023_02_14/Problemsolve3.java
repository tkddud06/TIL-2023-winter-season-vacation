package project_2023_02_14;

import java.util.Scanner;

import java.util.Random;

public class Problemsolve3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		Random ran = new Random();
		
		int answer = ran.nextInt(100) + 1;
		int input = 0;
		int count = 0;
		
		do {
			count++;
			System.out.print("1과 100 사이의 값을 입력하세요 : ");
			input = scanner.nextInt();
			
			if (answer == input)
			{
				System.out.println("정답입니다. \n시도한 횟수 :" + count);
				break;
			}
			else if(answer < input)
			{
				System.out.println("더 작은 수를 입력하세요.");
			}
			else
			{
				System.out.println("더 큰 수를 입력하세요.");
			}
			
		} while(true);
		scanner.close();
	}

}
