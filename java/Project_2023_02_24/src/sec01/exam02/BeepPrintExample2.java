package sec01.exam02;

public class BeepPrintExample2 {
	public static void main(String[] args) {
		Runnable beepTask = new BeepTask();
		Thread thread = new Thread(beepTask);
		Thread thread2 = new Thread(new AnotherTask());
		Thread thread3 = new Thread(new Runnable() {
			@Override
			public void run() {
				for(int i = 0; i< 1000; i++) {
					System.out.println("¶¥");
					try { Thread.sleep(100); } catch(Exception e) {}
				}
			}
			});
		
		thread.start();
		thread2.start();
		thread3.start();
		for(int i=0; i<1000; i++) {
			System.out.println("¶ò");
			try { Thread.sleep(100); } catch(Exception e) {}
		}
	}	
}
 

