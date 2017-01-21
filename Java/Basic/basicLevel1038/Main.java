package basicLevel1038;

// The test point four is runtime is outed.
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		int[] score = new int [101];
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		in.nextLine();
		
		
		String[] input = in.nextLine().split(" ");
		
		for (int i = 0; i < n; i++) {
			int temp = Integer.parseInt(input[i]);
			score[temp]++;
		}
		int k = in.nextInt();
		for (int i = 0; i < k-1; i++) {
			int temp = in.nextInt();
			System.out.print(score[temp] + " ");
		}
		int tmep = in.nextInt();
		System.out.print(score[tmep]);
		in.close();
	}

}
