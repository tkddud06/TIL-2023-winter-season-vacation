package sec03.exam01;

public class PhoneExample {
	public static void main(String[] args) {
		//Phone phone = new Phone(); //(x)
		
		//�ٸ�, �ڵ� Ÿ�� ��ȯ�� ���� ����� �� ����
		Phone phone = new SmartPhone("��ν�");
		phone.turnOn();
		
		SmartPhone smartPhone = new SmartPhone("ȫ�浿");
		
		smartPhone.turnOn();
		smartPhone.internetSearch();
		smartPhone.turnOff();
		int updateday = smartPhone.update();
		System.out.println(updateday);
	}
}
