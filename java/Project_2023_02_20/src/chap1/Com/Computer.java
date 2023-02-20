package chap1.Com;

public class Computer extends Calculator {
	
	@Override
	double areaCircle(double r)
	{
		System.out.println("컴터가 실행");
		return 3.141592 * r * r;
	}
}
