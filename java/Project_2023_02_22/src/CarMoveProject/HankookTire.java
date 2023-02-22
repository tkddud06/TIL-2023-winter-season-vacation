package CarMoveProject;

public class HankookTire implements Tire {

	int recent_roll = 4;
	
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
