package advancedLevel1001;

import java.util.Scanner;
import java.util.Stack;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		int b = in.nextInt();
		in.close();

		int ans = a + b;
		if (ans < 0) {
			System.out.print("-");
			ans = -ans;
		}

		Stack<Integer> stack = new Stack<>();
		do {
			stack.push(ans % 1000);
			ans /= 1000;
		} while (ans >= 1000);

		if (ans != 0) {
			System.out.print(ans);
			while (!stack.isEmpty()) {
				System.out.printf(",%03d", stack.pop());
			}
		} else {
			System.out.print(stack.pop());
			while (!stack.isEmpty()) {
				System.out.printf(",%03d", stack.pop());
			}
		}
	}
}
