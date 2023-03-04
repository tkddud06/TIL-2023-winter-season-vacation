package CarMoveProject;

public class Car {
	int Car_run_km = 0;
	Tire frontleft = new HankookTire();
	Tire frontright = new KumhoTire();
	Tire backleft = new NewTire();
	Tire backright = new HankookTire();

	public void runandrepair() {
		boolean fl, fr, bl, br;
		System.out.println("차랑 달림");
		Car_run_km++;
		System.out.println("총 " + Car_run_km + "km 달림");
		fl = frontleft.roll();
		fr = frontright.roll();
		bl = backleft.roll();
		br = backright.roll();
		if (!fl)
		{
			System.out.println("왼쪽앞타이어 손상, 새타이어로 교체");
			frontleft = new NewTire();
		}
		if (!fr)
		{
			System.out.println("오른쪽앞타이어 손상, 새타이어로 교체");
			frontright = new NewTire();
		}
		if (!bl)
		{
			System.out.println("왼쪽뒤타이어 손상, 새타이어로 교체");
			backleft = new NewTire();
		}
		if (!br)
		{
			System.out.println("오른쪽뒤타이어 손상, 새타이어로 교체");
			backright = new NewTire();
		}
		System.out.println("-------------------------------");
	}
}
