package MiniProject;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Thread thread1 = new Thread() {
			int sec = 0;
			public void run() {
				while(sec < 3600) {
					try { Thread.sleep(1000); } catch (Exception e) {}
					sec++;
					if (sec % 60 == 0)
					{
						continue;
					}
					System.out.println(sec%60 + "초");
				}
			}
		};
		Thread exit = new Thread() {
			public void run() {
			Scanner sc = new Scanner(System.in);
			System.out.println("아무 키나 입력하면 종료");
			String temp = sc.nextLine();
			System.out.println("종료합니다.");
			sc.close();
			return; // 이거 종료시 다른거 종료되게 못하나.
			}
		};
		thread1.start();
		exit.start();
		
		int minute = 0;
		while(minute < 60){
		try { Thread.sleep(60000); } catch (Exception e) {}
		minute++;
		System.out.println(minute + "분");
		}
	}
	
}
