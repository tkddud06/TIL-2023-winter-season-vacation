package project_2023_02_15;

public class problemsolve1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] answer = { 1, 4, 4, 3, 1, 4, 4, 2, 1, 3, 2};
		int[] counter = new int[4];
		
		for(int i = 0; i < answer.length; i++)
		{
			counter[answer[i]-1]++;
		}
		
		for(int i = 0; i < counter.length; i++)
		{
			System.out.print(counter[i]);
			for(int j = 0; j < counter[i]; j++)
			{
				System.out.print('*');
			}
			System.out.println();
		}
	}

}
