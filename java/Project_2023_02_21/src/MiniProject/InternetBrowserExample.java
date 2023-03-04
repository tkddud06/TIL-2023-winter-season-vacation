package MiniProject;

public class InternetBrowserExample {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		User man = new User();
		
		InternetBrowser ib = new InternetBrowser();
		Firefox ff = new Firefox();
		Chrome c = new Chrome();
		Whale w = new Whale();
		
		man.internetuse(ib);
		man.internetuse(w);
		man.internetuse(c);
		man.internetuse(ff);
	}

}
