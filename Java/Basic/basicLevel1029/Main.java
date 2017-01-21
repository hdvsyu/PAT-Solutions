package basicLevel1029;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		String should = in.nextLine().toUpperCase();
		String reality = in.nextLine().toUpperCase();
		in.close();

		Set<Character> set = new HashSet<>();
		int i = 0, j = 0;
		while (i < should.length()) {
			char c = should.charAt(i++);
			if (j < reality.length()) {
				if (c != reality.charAt(j)) {
					if (!set.contains(c)) {
						System.out.print(c);
						set.add(c);
					}
				} else {
					j++;
				}
			} else {
				if (!set.contains(c)) {
					System.out.print(c);
					set.add(c);
				}
			}
		}
	}

}
