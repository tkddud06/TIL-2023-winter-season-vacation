package AnimalProject;

public class Cat extends Animal {
	int a = 3;
	
	public void sound() {
		System.out.println("냐옹");
		this.a = 1;
		System.out.println(a);
	}
}
