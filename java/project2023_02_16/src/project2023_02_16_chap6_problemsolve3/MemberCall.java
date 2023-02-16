package project2023_02_16_chap6_problemsolve3;

public class MemberCall {
	int iv = 10;
	static int cv = 20;
	
	int iv2 = cv;
	
	// MemberCall ddd = new MemberCall();

	static int cv2= 33; // 라인 A 에러 발생. static 필드가, 인스턴스 필드를 사용하려 했기 때문.
	// 여긴 ddd.iv 쓰는 같은 방법이 안되네. 흠.??
	
	static void staticMethod1 () {
		System.out.println(cv);
		MemberCall a = new MemberCall();
		System.out.println(a.iv); // 라인 B 에러 발생. static 메소드가, 인스턴스 필드를 사용하려 했기 때문.
		// 해당 방법처럼, 객체를 만들어 쓰는 수밖에 없음.
	}
	
	void instanceMethod1 () {
		System.out.println(cv);
		System.out.println(iv);
	}
	
	static void staticMethod2() {
		MemberCall a = new MemberCall();
		// 해당 방법처럼, 객체를 만들어 쓰는 수밖에 없음.
		staticMethod1();
		a.instanceMethod1(); // 라인 D 에러 발생. static 메소드가, 인스턴스 메소드를 사용하려 했기 때문.
	}
	
	void instanceMethod2() {
		staticMethod1();
		instanceMethod1();
	}
}
