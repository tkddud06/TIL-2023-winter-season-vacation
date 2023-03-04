package Calculatorfactory;

public class Calculator_1 {
	private int serial_num;
	final static int model_num = 111;
	final int made_in_when = 20230217;
	final String color;
	public String use_where;
	

	public Calculator_1(String use_where, String color)
	{
		this(0, use_where, color);
	}
	
	Calculator_1(int serial_num, String use_where, String color)
	{
		this.serial_num = serial_num;
		this.use_where = use_where;
		this.color = color;
	}
	
	public String getallinfo()
	{
		return "serial : " + serial_num + " | model_num : " + model_num + " | use_where : " + use_where + " | made_in_when : " + made_in_when + " | color : " + color;
	}
	
	public int getserial()
	{
		return serial_num;
	}
	
	void setserial(int serial_num)
	{
		this.serial_num = serial_num;
	}
	
	public int plus(int a, int b)
	{
		return a + b;
	}
	
	public double plus(double a, double b)
	{
		return a + b;
	}
	
	public float plus(float a, float b)
	{
		return a + b;
		
	}
	
	
	public int minus(int a, int b)
	{
		return a - b;
	}
	
	public double minus(double a, double b)
	{
		return a - b;
	}
	
	public float minus(float a, float b)
	{
		return a - b;
	}
}
