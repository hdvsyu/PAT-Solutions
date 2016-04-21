package basicLevel1003;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		in.nextLine();
		String[] s = new String[n];

		for (int i = 0; i < n; i++) {
			boolean isOther = false;
			s[i] = new String(in.nextLine());
			for (int j = 0; j < s[i].length(); j++) {
				if (s[i].charAt(j) != 'P' && s[i].charAt(j) != 'A' && s[i].charAt(j) != 'T') {
					System.out.println("NO");
					isOther = true;
					break;
				}
			}

			if (isOther == false) {
				// if all the character are only P A and T
				if (isTrue(s[i])) {
					System.out.println("YES");
				} else {
					System.out.println("NO");
				}

			}
		}
		in.close();
	}

	public static boolean isTrue(String s) {

		// refine the a b and c three substring.
		int p = s.indexOf('P');
		int t = s.indexOf('T');

		if (p > t) {
			return false;
		}

		String a = null;
		String b = null;
		String c = null;
		if (p != -1) {
			a = s.substring(0, p);
		} else {
			return false;
		}

		if (t != -1) {
			c = s.substring(t + 1, s.length());
		} else {
			return false;
		}

		b = s.substring(p + 1, t);

		if (a.contains("P") || a.contains("T") || b.contains("T") || b.contains("P") || c.contains("P")
				|| c.contains("T")) {
			return false;
		}

		if (c.length() < a.length()) {
			return false;
		}

		// it assume that the substring not have other character.
		if (b.length() == 0) {
			// b must not be empty.
			return false;
		}

		if (a.equals(c) && a.equals("")) {
			return true;
		}

		int times = 0;
		for (int i = 0; i <= c.length() - a.length(); i += a.length()) {
			if (a.equals(c.substring(i, i + a.length()))) {
				times++;
			}
		}

		if (times == b.length()) {
			return true;
		} else {
			return false;
		}
	}
}
