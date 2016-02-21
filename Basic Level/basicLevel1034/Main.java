package basicLevel1034;
//two test point failure.
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		String[] input = in.nextLine().split("[\\s/]");
		in.close();
		int a1 = Integer.parseInt(input[0]);
		int b1 = Integer.parseInt(input[1]);
		int a2 = Integer.parseInt(input[2]);
		int b2 = Integer.parseInt(input[3]);

		if (b1 != 0 && b2 != 0) {
			add(a1, b1, a2, b2);
			minus(a1, b1, a2, b2);
			mutilply(a1, b1, a2, b2);
			divide(a1, b1, a2, b2);
		}
	}

	public static void tackle(int a, int b) {
		if (a == 0) {
			System.out.print(0);
			return;
		}

		boolean isMinus = a > 0 ? false : true;
		if (isMinus) {
			System.out.print("(-");
			a = -a;
		}

		int gcd = getGcd(a, b);
		a = a / gcd;
		b = b / gcd;
		if (a % b == 0) {
			System.out.print(a / b);
		} else if (Math.abs(a) > b) {
			System.out.print(a / b + " " + (a % b) % b + "/" + b);
		} else if (a == b) {
			System.out.print(1);
		} else {
			System.out.print(a + "/" + b);
		}

		if (isMinus) {
			System.out.print(")");
		}

	}

	public static void divide(int a1, int b1, int a2, int b2) {
		tackle(a1, b1);
		System.out.print(" / ");
		tackle(a2, b2);
		System.out.print(" = ");
		if (a2 == 0) {
			System.out.print("Inf");
		} else if (a2 < 0) {
			tackle(-1 * a1 * b2, -1 * a2 * b1);
		} else {
			tackle(a1 * b2, a2 * b1);
		}
	}
	
	public static void mutilply(int a1, int b1, int a2, int b2) {
		tackle(a1, b1);
		System.out.print(" * ");
		tackle(a2, b2);
		System.out.print(" = ");
		tackle(a1 * a2, b1 * b2);
		System.out.println();
	}
	
	public static void minus(int a1, int b1, int a2, int b2) {
		tackle(a1, b1);
		System.out.print(" - ");
		tackle(a2, b2);
		System.out.print(" = ");
		tackle(a1 * b2 - a2 * b1, b1 * b2);
		System.out.println();
	}

	public static void add(int a1, int b1, int a2, int b2) {
		tackle(a1, b1);
		System.out.print(" + ");
		tackle(a2, b2);
		System.out.print(" = ");
		tackle(a1 * b2 + a2 * b1, b1 * b2);
		System.out.println();
	}

	public static int getGcd(int a, int b) {
		while (a % b != 0) {
			int temp = a % b;
			a = b;
			b = temp;
		}
		return b;
	}
}
