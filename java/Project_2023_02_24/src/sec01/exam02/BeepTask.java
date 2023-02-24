package sec01.exam02;

// import java.awt.Toolkit;

public class BeepTask implements Runnable {	
	public void run() {		
		// Toolkit toolkit = Toolkit.getDefaultToolkit();	
		for(int i=0; i<1000; i++) {		
			//toolkit.beep();
			System.out.println("¶Ë");
			try { Thread.sleep(100); } catch(Exception e) {}
		}
	}
}

