package sec01.exam02;

public class A {
	//인스턴스 필드
	B field1 = new B();  // 바깥 클래스의 인스턴스 필드 필드1             
	C field2 = new C();               
	
	//인스턴스 메소드
	void method1() {
		B var1 = new B();
		C var2 = new C();
	}
	
	//정적 필드 초기화
	//static B field3 = new B(); // 정적필드에는 인스턴스 멤버 클래스 할당 x
	static C field4 = new C();
	
	//정적 메소드
	static void method2() {
		//B var1 = new B();
		C var2 = new C();
	}
	
	//인스턴스 멤버 클래스
	class B {}
	//정적 멤버 클래스
	static class C {}	
}

