package AnimalProject;

public class Example {
	
	public static void Animalspeak(Animal animal) {
		animal.sound();
	}
	
	public static void main(String[] args) {
	
		Cat cat = new Cat();
		Dog dog = new Dog();
		
		//1
		cat.sound();
		dog.sound();
		//
		
		
		Animal animal1 = cat;
		Animal animal2 = dog;
		//2
		animal1.sound();
		animal2.sound();
		//
		
		
		//3
		Animalspeak(cat);
		Animalspeak(dog);
		//
	}
}
