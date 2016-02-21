package basicLevel1033;

//have a test point failure.
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		String badKeyInput = in.nextLine();
		String testKey = in.nextLine();
		in.close();
		Set<Character> badKeySet = new HashSet<>();
		for (int i = 0; i < badKeyInput.length(); i++) {
			badKeySet.add(badKeyInput.charAt(i));
		}
		
		boolean isCanUpper = !badKeySet.contains('+');
		
		Set<Character> outputSet = new HashSet<>();
		for (int i = 0; i < testKey.length(); i++) {
			char c = testKey.charAt(i);
			
			if (isCanUpper) {
				if (!badKeySet.contains(c)) {
					System.out.print(c);
					outputSet.add(c);
				}
			} else {
				if (!Character.isUpperCase(c) && !badKeySet.contains(Character.toUpperCase(c))) {
					System.out.print(c);
					outputSet.add(c);
				}
			}
		}
		
		if (outputSet.size() == 0) {
			System.out.println();
		}
	}

}
