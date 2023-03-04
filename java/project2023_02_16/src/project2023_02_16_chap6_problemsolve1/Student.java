package project2023_02_16_chap6_problemsolve1;

public class Student {
	String name;
	int ban;
	int no;
	int kor;
	int eng;
	int math;
	
	Student(){
		this.name = "홍길동";
		this.ban = 1;
		this.no = 22;
		this.kor = 33;
		this.eng = 45;
		this.math = 66;
	}
	
	Student(String name, int ban, int no){
		this.name = name;
		this.ban = ban;
		this.no = no;
	}
	
	Student(String name){
		this.name = name;
	}
	
	Student(String name, int ban, int no, int kor, int eng, int math){
		this.name = name;
		this.ban = ban;
		this.no = no;
		this.kor = kor;
		this.eng = eng;
		this.math = math;
	}
	
	int getTotal() {
		return kor + eng + math;
	}
	
	float getAverage() {
		return (int)(getTotal() / 3f * 10 + 0.5f) / 10f;
	}
	
	String info(){
		String s = name + ", " + ban + ", " + no + ", " + kor + ", " + eng + ", " + math + ", " + getTotal() + ", "+ getAverage();
		
		return s;
		}
}
