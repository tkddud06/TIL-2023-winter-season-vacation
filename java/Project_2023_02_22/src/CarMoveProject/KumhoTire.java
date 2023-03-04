package CarMoveProject;

public class KumhoTire implements Tire {
	int recent_roll = 3;
	
	@Override
	public boolean roll() {
		recent_roll++;
		if (recent_roll > Tire.MAX_ROLL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}
