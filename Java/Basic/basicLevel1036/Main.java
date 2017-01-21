package basicLevel1036;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		char c = in.next().charAt(0);
		in.close();

		int col = (int) (n/ 2.0 + 0.5);
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < n; j++) {
				if (i == 0 || j == 0 || j == n-1 || i == col - 1) {
					System.out.print(c);
				} else {
					System.out.print(' ');
				}
			}
			System.out.println();
		}
	}

}
