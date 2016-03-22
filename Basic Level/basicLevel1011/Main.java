package basicLevel1011;

import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		BigInteger[][] number = new BigInteger[t][3];
		for (int i = 0; i < t; i++) {
			for (int j = 0; j < 3; j++) {
				number[i][j] = new BigInteger(in.next());
			}
		}
		in.close();

		for (int i = 0; i < t; i++) {
			System.out
					.println("Case #" + (i + 1) + ": " + (number[i][0].add(number[i][1]).compareTo(number[i][2]) == 1));
		}
	}
}