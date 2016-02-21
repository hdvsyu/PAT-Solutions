package basicLevel1048;

import java.util.Scanner;
import java.util.Stack;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		String a = in.next();
		String b = in.next();
		in.close();

		int i = a.length() - 1;
		int j = b.length() - 1;

		// 让A和B的长度相等
		if (i > j) {
			// A比B长
			int c = i - j;
			while (c != 0) {
				b = "0" + b;
				c--;
			}
		} else if (i < j) {
			// B比A长
			int c = j - i;
			while (c != 0) {
				a = "0" + a;
				c--;
			}
		}
		
		int index = b.length() - 1; // index = a.length() - 1
		boolean isOdd = true;
		Stack<String> stack = new Stack<>();
		while (index >= 0) {
			if (isOdd) {
				// 奇数位
				isOdd = false;
				int cNumber = a.charAt(index) - '0' + b.charAt(index) - '0';
				String r = null;
				switch (cNumber) {
				case 10:
					r = "J";
					break;
				case 11:
					r = "Q";
					break;
				case 12:
					r = "K";
				default:
					r = "" + cNumber % 13;
					break;
				}
				
				stack.push(r);
			} else {
				// 偶数位
				isOdd = true;
				int cNumber = (b.charAt(index) - '0' - a.charAt(index) + '0' + 10) % 10;
				String r = "" + cNumber;
				stack.push(r);
			}
			
			index--;
		}
		
		while (!stack.isEmpty()) {
			System.out.print(stack.pop());
		}
 	}

}
