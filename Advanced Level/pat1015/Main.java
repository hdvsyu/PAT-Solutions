package pat1015;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		boolean[] primer = new boolean[100000];
		setPrimer(primer);

		while (true) {
			int num = in.nextInt();

			if (num < 0) {
				break;
			}

			int radix = in.nextInt();

			if (primer[num]) {
				int newNum = 0;
				do {
					newNum = newNum * radix + num % radix;
					num /= radix;
				} while (num != 0);

				if (primer[newNum]) {
					System.out.println("Yes");
				} else {
					System.out.println("No");
				}
			} else {
				System.out.println("No");
			}
		}

		in.close();
	}

	public static void setPrimer(boolean[] primer) {
		for (int i = 0; i < primer.length; i++) {
			primer[i] = true;
		}

		primer[0] = primer[1] = false;

		for (int i = 2; i < primer.length; i++) {
			for (int j = 2; j * i < primer.length; j++) {
				primer[j * i] = false;
			}
		}
	}

}
