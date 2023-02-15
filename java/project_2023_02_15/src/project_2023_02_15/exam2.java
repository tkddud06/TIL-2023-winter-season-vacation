package project_2023_02_15;

public class exam2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] scores;
		scores = new int[] { 83, 90, 87 };
		int sum1 = 0;
		for(int i=0; i<3; i++) {
			sum1 += scores[i];
		}
		System.out.println("총합 : " + sum1);	
		
		int sum2 = add( new int[] { 83, 90, 87 } );  // 해당 부분에서 new int[]를 빼면 에러가 난다.
		// 자바에서는 1차원 배열을 넘겨줄때는, 무조건 해당 형식으로 넘겨야 한다. 그렇지 않으면 에러가 난다.
		// c언어에서는 지들끼리 데이터를 복사해주고 말았지만(콜바이밸류는 값자체, 콜바이레퍼런스는 결국 주소복사)
		// , 자바에서는 무조건 객체로써 만들어서 넘겨야 한다.
		System.out.println("총합 : " + sum2);	
		System.out.println();
	}
	
	public static int add(int[] scores) {
		int sum = 0;
		for(int i=0; i<3; i++) {
			sum += scores[i];
		}
		return sum;

	}

}
