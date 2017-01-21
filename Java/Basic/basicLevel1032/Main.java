package basicLevel1032;

//I use c plus plus passed the test
//Use java have one test point failure.
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] scores = new int[n+1];
		int maxIndex = 1;
		for (int i = 0; i < n; i++) {
			int index = in.nextInt();
			scores[index] += in.nextInt();
			
			if (scores[maxIndex] < scores[index]) {
				maxIndex = index;
			}
		}
		in.close();
		
		System.out.println(maxIndex + " " + scores[maxIndex]);
	}

}
