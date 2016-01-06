package pat1005;

import java.util.Scanner;
import java.util.Stack;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		String string = in.nextLine();
		int sum = 0;
		for (int i = 0; i < string.length(); i++) {
			sum += string.charAt(i) - '0';
		}
		in.close();

		Stack<String> stack = new Stack<>();
		do {
			stack.push(matcher(sum % 10));
			sum /= 10;
		} while (sum != 0);
		
		while (stack.size() != 1) {
			System.out.print(stack.pop() + " ");
		}
		System.out.print(stack.pop());
	}

	public static String matcher(int unit) {

		switch (unit) {
		case 1:
			return "one";
		case 2:
			return "two";
		case 3:
			return "three";
		case 4:
			return "four";
		case 5:
			return "five";
		case 6:
			return "six";
		case 7:
			return "seven";
		case 8:
			return "eight";
		case 9:
			return "nine";
		default:
			return "zero";
		}
	}
}
