package problem_student;

public class Student {
	String name = "홍길동";
	int ban = 2;
	int no = 31;
	int kor = 77;
	int eng = 89;
	int math = 99;
	
	public int getTotal()
	{
		return kor + eng + math;
	}
	
	public float getAverage()
	{
		return (int)(getTotal() / 3.0f * 10 + 0.5f) / 10f;
	}
}
