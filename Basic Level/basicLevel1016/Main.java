package basicLevel1016;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		String A = in.next();
		int da = in.nextInt();
		String B = in.next();
		int db = in.nextInt();
		in.close();
		
		long pa = 0;
		for (int i = 0; i < A.length(); i++) {
			if (A.charAt(i) - '0' == da) {
				pa = pa * 10 + (A.charAt(i) - '0');
			}
		}
		
		long pb = 0;
		for (int i = 0; i < B.length(); i++) {
			if (B.charAt(i) - '0' == db) {
				pb = pb * 10 + (B.charAt(i) - '0');
			}
		}
		
		System.out.print(pa + pb);
	}

}
