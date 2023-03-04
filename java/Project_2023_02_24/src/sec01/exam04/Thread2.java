package sec01.exam04;

public class Thread2 extends Thread {
	@Override
	public void run() {
		for(int i = 0; i < 50; i++) {
			System.out.println("¶¯");
			try { Thread.sleep(100); } catch (Exception e) {} 
		}
	}
}
