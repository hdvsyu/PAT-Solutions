package advancedLevelpat1008;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] floors = new int[n];
		for (int i = 0; i < n; i++) {
			floors[i] = in.nextInt();
		}
		in.close();

		int time = floors[0] * 6; // the first floor must be upward.
		time += 5 * n; // every floor have to spend four seconds
						// to stop.
		for (int i = 1; i < n; i++) {
			if (floors[i] > floors[i - 1]) {
				// It upward.
				time += (floors[i] - floors[i - 1]) * 6;
			} else {
				// It downward.
				time += (floors[i - 1] - floors[i]) * 4;
			}
		}

		System.out.println(time);
	}

}
