package testpackage1;

public class A {
	//필드
	A a1 = new A(true);
	A a2 = new A(1);
	A a3 = new A("문자열");

	//생성자	
	public A(boolean b) {}
	A(int b) {}
	private A(String s) {} 

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		A a1 = new A(true);
	}
}
