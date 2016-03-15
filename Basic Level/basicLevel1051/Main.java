package basicLevel1051;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);

		double r1 = in.nextDouble();
		double p1 = in.nextDouble();
		double r2 = in.nextDouble();
		double p2 = in.nextDouble();

		in.close();
		double a = r1 * Math.cos(p1) * r2 * Math.cos(p2) - r1 * Math.sin(p1) * r2 * Math.sin(p2);
		double b = r1 * Math.sin(p1) * r2 * Math.cos(p2) + r2 * Math.sin(p2) * r1 * Math.cos(p1);

		if (Math.abs(a) <= 0.001) {
			System.out.print("0.00");
		} else {
			System.out.printf("%.2f", a);
		}

		if (b > 0) {
			System.out.printf("+%.2fi", b);
		} else if (Math.abs(b) <= 0.001) {
			System.out.print("+0.00i");
		} else {
			System.out.printf("%.2fi", b);
		}
	}

}
