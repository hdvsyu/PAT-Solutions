package basicLevel1022;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);

		int a = in.nextInt();
		int b = in.nextInt();
		int d = in.nextInt();

		in.close();
		String aString = "";
		do {
			aString += a % d;
			a /= d;
		} while (a != 0);

		String bString = "";
		do {
			bString += b % d;
			b /= d;
		} while (b != 0);

		// We add a with b and print it.
		StringBuilder result = new StringBuilder();
		if (aString.length() > bString.length()) {
			int temp = 0;
			for (int i = 0; i < bString.length(); i++) {
				result.append((temp + aString.charAt(i) - '0' + bString.charAt(i) - '0') % d);
				temp = (temp + aString.charAt(i) - '0' + bString.charAt(i) - '0') / d;
			}
			
			if (temp != 0) {
				for (int i = bString.length(); i < aString.length(); i++) {
					result.append((aString.charAt(i) - '0' + temp) % d);
					temp = (aString.charAt(i) - '0' + temp) / d;
				}
				
				if (temp != 0) {
					result.append(temp);
				}
			}

		} else {

			int temp = 0;
			for (int i = 0; i < aString.length(); i++) {
				result.append((temp + aString.charAt(i) - '0' + bString.charAt(i) - '0') % d);
				temp = (temp + aString.charAt(i) - '0' + bString.charAt(i) - '0') / d;
			}
			
			if (temp != 0) {
				for (int i = aString.length(); i < bString.length(); i++) {
					result.append((aString.charAt(i) - '0' + temp) % d);
					temp = (aString.charAt(i) - '0' + temp) / d;
				}
				
				if (temp != 0) {
					result.append(temp);
				}
			}
		}
		
		System.out.println(result.reverse());

	}

}
