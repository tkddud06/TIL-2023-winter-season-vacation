package CarMoveProject;

public class NewTire implements Tire {
	int recent_roll = 0;
	
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
