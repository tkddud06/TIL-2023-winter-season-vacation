package sec01.exam04;

public class RemoteControlExample {
	public static void main(String[] args) {
		RemoteControl rc;
		rc = new Television();
		rc = new Audio();
		
		rc.turnOn();
		rc.setVolume(12); // rc임에도 불구하고, 자식의 필드도 사용할 수 있네. 애니멀프로젝트 보면 이해됨.
		// System.out.println(rc.volume); // 이건 또 안되네. 뭘까? 함수타고 접근만 되는걸까?
	}
}
