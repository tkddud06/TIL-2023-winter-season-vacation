package sec03.exam01;

public class SmartPhone extends Phone {
	//생성자
	public SmartPhone(String owner) {
		super(owner);
	}
	//메소드
	public void internetSearch() {
		System.out.println("인터넷 검색을 합니다.");
	}
	//오버라이드
	@Override
	public int update() {
		System.out.println("스마트폰 소프트웨어 업데이트를 진행했습니다.");
		return 20230221;
	}
}
