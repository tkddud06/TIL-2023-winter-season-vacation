package sec03.exam01;

public class SmartPhone extends Phone {
	//������
	public SmartPhone(String owner) {
		super(owner);
	}
	//�޼ҵ�
	public void internetSearch() {
		System.out.println("���ͳ� �˻��� �մϴ�.");
	}
	//�������̵�
	@Override
	public int update() {
		System.out.println("����Ʈ�� ����Ʈ���� ������Ʈ�� �����߽��ϴ�.");
		return 20230221;
	}
}
