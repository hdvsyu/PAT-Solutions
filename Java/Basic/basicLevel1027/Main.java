package basicLevel1027;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		char c = in.next().charAt(0);
		in.close();

		int w = (int) Math.sqrt((n + 1) / 2);
		for (int i = 0; i < 2 * w - 1; i++) {
			for (int j = 0; j < 2 * w - 1; j++) {
				if ((i > j && i + j < 2 * w - 2) || (i < j && i + j > 2 * w - 2)) {
					if (i > j && i + j < 2 * w - 2)
						System.out.print(" ");
				} else {
					System.out.print(c);
				}
			}

			System.out.println();
		}
		
		System.out.println(n - 2 * w * w + 1);
	}
}