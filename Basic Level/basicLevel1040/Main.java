package basicLevel1040;

//have three test point failure.
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		String string = in.nextLine();
		in.close();

		long[] p = new long[string.length()];
		long[] t = new long[string.length()];
		for (int i = 0; i < string.length(); i++) {
			int j = string.length() - 1 - i;

			if (string.charAt(i) == 'P') {
				if (i == 0) {
					p[i] = 1;
				} else {
					p[i] = p[i - 1] + 1;
				}
			} else {
				if (i == 0) {
					p[i] = 0;
				} else {
					p[i] = p[i - 1];
				}
			}

			if (string.charAt(j) == 'T') {

				if (j == string.length() - 1) {
					t[j] = 1;
				} else {
					t[j] = t[j + 1] + 1;
				}
			} else {
				if (j == string.length() - 1) {
					t[j] = 0;
				} else {
					t[j] = t[j + 1];
				}
			}
		}
		
		double total = 0;
		for (int i = 1; i < string.length() - 1; i++) {
			if (string.charAt(i) == 'A') {
				total = (total + (p[i] * t[i]) % 1000000007) % 1000000007;
			}
		}
		
		System.out.printf("%.0f", total);
 	}

}
