package advancedLevelpat1050;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String s1 = in.nextLine();
		String s2 = in.nextLine();
		in.close();
		
		Set<Character> set = new HashSet<>();
		for (int i = 0; i < s2.length(); i++) {
			set.add(s2.charAt(i));
		}
		
		for (int i = 0; i < s1.length(); i++) {
			char c = s1.charAt(i);
			if (!set.contains(c)) {
				System.out.print(c);
			}
		}
	}
}
