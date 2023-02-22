package Phone;

public class Example {
	public static void main(String[] args) {
		User user = new User();
		
		IPhone iphone = new IPhone();
		GalaxyPhone galaxyphone = new GalaxyPhone();
		
		user.turnonofftest(iphone);
		user.turnonofftest(galaxyphone);
	}
}
