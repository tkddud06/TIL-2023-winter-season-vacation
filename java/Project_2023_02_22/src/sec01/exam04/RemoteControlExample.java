package sec01.exam04;

public class RemoteControlExample {
	public static void main(String[] args) {
		RemoteControl rc;
		rc = new Television();
		rc = new Audio();
		
		rc.turnOn();
		rc.setVolume(12); // rc�ӿ��� �ұ��ϰ�, �ڽ��� �ʵ嵵 ����� �� �ֳ�. �ִϸ�������Ʈ ���� ���ص�.
		// System.out.println(rc.volume); // �̰� �� �ȵǳ�. ����? �Լ�Ÿ�� ���ٸ� �Ǵ°ɱ�?
	}
}
