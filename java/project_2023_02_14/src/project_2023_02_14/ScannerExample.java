package project_2023_02_14;

import java.util.Scanner;

public class ScannerExample {

	public static void main(String[] args) throws Exception { // 이건 뭔지 모르겠다
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in); // new == 클래스를 인스턴스화 하는 명령어
		String inputData;
		
		while(true)
		{
			inputData = scanner.nextLine();
			System.out.println("입력된 문자열 ㅣ \"" + inputData + "\"");
			if(inputData.equals("q")) // strcmp같은 놈임. )
			{
				break;
			}
		}
		System.out.println("종료");
		scanner.close();
	}
	
}
