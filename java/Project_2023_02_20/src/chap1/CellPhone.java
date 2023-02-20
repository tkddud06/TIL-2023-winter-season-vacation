package chap1;

public class CellPhone {
	String model;
	String color;
	
	void powerOn() {System.out.println("킨다"); }
	void powerOff() {System.out.println("끈다"); }
	void bell() { System.out.println("벨울린다"); }
	void sendVoice(String message) { System.out.println("자기: " + message); }	
	void receiveVoice(String message) { System.out.println("상대방: " + message); }	
	void hangUp() { System.out.println("전화를 끊습니다."); }

}
