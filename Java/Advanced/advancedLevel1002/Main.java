package advancedLevel1002;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int k = in.nextInt();
		
		double[] array = new double[10001];
		for (int i = 0; i < k; i++) {
			array[in.nextInt()] += in.nextDouble();
		}
		
		k = in.nextInt();
		for (int i = 0; i < k; i++) {
			array[in.nextInt()] += in.nextDouble();
		}
		in.close();
		
		int cnt = 0;
		for (int i = 0; i < 1001; i++) {
			if (array[i] != 0) {
				cnt++;
			}
		}
		System.out.print(cnt);
		
		for (int i = 1000; i >= 0; i--) {
			if (array[i] != 0) {
				System.out.printf(" %d %.1f", i, array[i]);
			}
		}
	}
}