package sec03.exam01;

public class PhoneExample {
	public static void main(String[] args) {
		//Phone phone = new Phone(); //(x)
		
		//다만, 자동 타입 변환을 통해 만드는 건 가능
		Phone phone = new SmartPhone("김민식");
		phone.turnOn();
		
		SmartPhone smartPhone = new SmartPhone("홍길동");
		
		smartPhone.turnOn();
		smartPhone.internetSearch();
		smartPhone.turnOff();
		int updateday = smartPhone.update();
		System.out.println(updateday);
	}
}
