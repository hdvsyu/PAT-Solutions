package basicLevel1053;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		double e = in.nextDouble();
		int d = in.nextInt();
		int mustEmpty = 0;
		int maybeEmpty = 0;
		for (int i = 0; i < n; i++) {
			int k = in.nextInt();
			int cnt = 0;
			if (k > d) {
				for (int j = 0; j < k; j++) {
					double temp = in.nextDouble();
					if (temp < e) {
						cnt++;
					}
				}
				
				if (cnt > k / 2) {
					mustEmpty++;
				}
			} else {
				for (int j = 0; j < k; j++) {
					double temp = in.nextDouble();
					if (temp < e) {
						cnt++;
					}
				}
				
				if (cnt > k / 2) {
					maybeEmpty++;
				}
			}
		}
		in.close();
		
		System.out.printf("%.1f%% %.1f%%", maybeEmpty * 1.0 / n * 100, mustEmpty * 1.0 / n * 100);
	}

}
