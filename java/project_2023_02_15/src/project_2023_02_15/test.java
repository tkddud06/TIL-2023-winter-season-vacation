package project_2023_02_15;

public class test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String strVar1 = "신민철";
		String strVar2 = "신민철";
		
		if(strVar1 == strVar2) {
			System.out.println("1이랑 2는 같음");
		}
		else {
			System.out.println("1이랑 2는 다름");
		}
		
		if(strVar1.equals(strVar2)) {
			System.out.println("1이랑 2는 내용물이 같음");
		}
		
		String Strvar3 = new String("신민철");
		String Strvar4 = new String("신민철");
		
		if(Strvar3 == Strvar4) {
			System.out.println("3이랑 4는 같음");
		}
		else {
			System.out.println("3이랑 4는 다름");
		}
		
		if(Strvar3.equals(Strvar4)) {
			System.out.println("3이랑 4는 내용물이 같음");
		}
		
		if(strVar1 == Strvar4) {
			System.out.println("1이랑 4는 같음");
		}
		else {
			System.out.println("1이랑 4는 다름");
		}
		
		if(strVar1.equals(Strvar4)) {
			System.out.println("1이랑 4는 내용물이 같음");
		}
	}

}
