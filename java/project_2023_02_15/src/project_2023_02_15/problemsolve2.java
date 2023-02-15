package project_2023_02_15;

public class problemsolve2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int [][] score = {
				{100, 100, 100},
				{20, 20, 20},
				{30, 30, 30},
				{40, 40, 40},
				{50, 50, 50}
		};
		
		int[][] result = new int[score.length+1][score[0].length+1];
		
		for(int i = 0; i < score.length; i++)
		{
			int sum = 0;
			for(int j = 0; j < score[i].length; j++)
			{
				result[i][j] = score[i][j];
				sum += score[i][j];
			}
			result[i][result[i].length-1] = sum;
		}
		
		for(int i = 0; i < score[0].length; i++)
		{
			int sum = 0;
			for(int j = 0; j < score.length; j++)
			{
				sum += score[j][i];
			}
			result[result.length-1][i] = sum;
		}
		
		
		for (int i = 0; i < result.length; i++)
		{
			for(int j = 0; j < result[i].length; j++)
			{
				System.out.printf("%4d", result[i][j]);
			}
			System.out.println();
		}
	}
// 하다맘. 휴대폰 이미지 참고. sum을 이용 않고, 각 자리별로 바로바로 해결해서 한 포문으로 끝낼수 있네.
}
