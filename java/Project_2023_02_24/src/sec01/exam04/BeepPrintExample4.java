package sec01.exam04;

public class BeepPrintExample4 {
	public static void main(String[] args) {
		Thread thread = new BeepThread();
		Thread thread2 = new Thread2();
		Thread thread3 = new Thread() {
			@Override
			public void run() {
				for(int i = 0 ; i < 50; i++) {
					System.out.println("¶×");
					try { Thread.sleep(100); } catch (Exception e) {}
				}
			}
		};
		thread3.start();
		thread2.start();
		thread.start();		
		
		for(int i=0; i<50; i++) {
			System.out.println("¶ò");
			try { Thread.sleep(100); } catch(Exception e) {}
		}
	}
}

