package advancedLevelpat1051;

import java.util.Scanner;
import java.util.Stack;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int m = in.nextInt();
		int n = in.nextInt();
		int k = in.nextInt();

		for (int i = 0; i < k; i++) {
			int[] array = new int[n];
			for (int j = 0; j < n; j++) {
				array[j] = in.nextInt();
			}
			
			Stack<Integer> stack = new Stack<>();
			int num = 1;
			stack.add(num);
			
			
			int index = 0;
			while (stack.size() <= m && num != n+1) {
				if (stack.peek() == array[index]) {
					stack.pop();
					index++;
				}
				stack.push(++num);

			}

			if (stack.size() > m) {
				System.out.println("NO");
			} else {
				System.out.println("YES");
			}
		}
		in.close();
	}

}
