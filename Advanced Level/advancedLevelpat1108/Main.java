package advancedLevelpat1108;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		double y = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			String s = in.next();

			double x = 0;
			try {
				x = Double.parseDouble(s);

				double temp = Double.parseDouble(String.format("%.2f", x));
				if (x > 1000 || x < -1000 || Math.abs(temp - x) > 0.001) {
					throw new NumberFormatException();
				} else {
					cnt++;
					y += x;
				}
			} catch (NumberFormatException e) {
				System.out.println("ERROR: " + s + " is not a legal number");
			}
		}
		in.close();

		if (cnt == 0) {
			System.out.println("The average of 0 numbers is Undefined");
		} else if (cnt == 1) {
			System.out.printf("The average of 1 number is %.2f", y);
		} else {
			System.out.printf("The average of %d numbers is %.2f", cnt, y / cnt);
		}
	}

}
