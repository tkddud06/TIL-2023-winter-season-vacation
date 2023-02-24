package sec01.exam04;

// import java.awt.Toolkit;

public class BeepThread extends Thread {
	@Override
	public void run() {		
		// Toolkit toolkit = Toolkit.getDefaultToolkit();	
		for(int i=0; i<50; i++) {		
			// toolkit.beep();
			System.out.println("¶¥");
			try { Thread.sleep(100); } catch(Exception e) {}
		}
	}
}

