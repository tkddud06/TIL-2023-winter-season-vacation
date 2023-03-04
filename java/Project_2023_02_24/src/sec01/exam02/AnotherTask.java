package sec01.exam02;

public class AnotherTask implements Runnable {
	public void run() {
	for(int i = 0 ; i < 1000; i++) {
		System.out.println("¶º");
		try { Thread.sleep(100); } catch(Exception e) {}
	}
	}
}
