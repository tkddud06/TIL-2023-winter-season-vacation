package sec01.exam02;

public class A {
	//�ν��Ͻ� �ʵ�
	B field1 = new B();  // �ٱ� Ŭ������ �ν��Ͻ� �ʵ� �ʵ�1             
	C field2 = new C();               
	
	//�ν��Ͻ� �޼ҵ�
	void method1() {
		B var1 = new B();
		C var2 = new C();
	}
	
	//���� �ʵ� �ʱ�ȭ
	//static B field3 = new B(); // �����ʵ忡�� �ν��Ͻ� ��� Ŭ���� �Ҵ� x
	static C field4 = new C();
	
	//���� �޼ҵ�
	static void method2() {
		//B var1 = new B();
		C var2 = new C();
	}
	
	//�ν��Ͻ� ��� Ŭ����
	class B {}
	//���� ��� Ŭ����
	static class C {}	
}

