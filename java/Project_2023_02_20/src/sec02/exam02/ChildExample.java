package sec02.exam02;

public class ChildExample {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Child child = new Child();
		
		Parent parent = child;
		
		Parent p = new Parent();
		
		p.method2();
		
		parent.method1();
		
		parent.method2();
	}

}
