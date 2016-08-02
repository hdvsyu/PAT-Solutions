package advancedLevel1084;

// 分别用两个指针指向original字符串和typedOut字符串，然后比较两个指针指向的字符是否相等，这里要注意判断边界条件。
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String original = in.nextLine().toUpperCase();
		String typedOut = in.nextLine().toUpperCase();
		in.close();
		Set<Character> set = new HashSet<>();
		int i = 0, j = 0;
		while (i != original.length() || j != typedOut.length()) {

			if (j == typedOut.length()) {
				for (; i != original.length(); i++) {
					if (!set.contains(original.charAt(i))) {
						System.out.print(original.charAt(i));
						set.add(original.charAt(i));
					}
				}
				break;
			}

			if (original.charAt(i) != typedOut.charAt(j)) {
				if (!set.contains(original.charAt(i))) {
					System.out.print(original.charAt(i));
					set.add(original.charAt(i));
				}
				i++;
			} else {
				i++;
				j++;
			}
		}
	}
}
