package basicLevel1031;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		boolean isAllPassed = true;
		for (int i = 0; i < n; i++) {
			String number = in.next();
			if (!check(number.substring(0, 17), number.charAt(17))) {
				isAllPassed = false;
				System.out.println(number);
			}
		}
		in.close();
		
		if (isAllPassed) {
			System.out.println("All passed");
		}
	}

	public static boolean check(String sub, char m) {
		
		int[] value = {
				7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4,2	
		};
		
		int sum = 0;
		for (int i = 0; i < sub.length(); i++) {
			sum += value[i] * (sub.charAt(i) - '0');
		}
		
		char[] z = {
				'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'
		};
		
		if (m == z[sum % 11]) {
			return true;
		}
		return false;
	}

}
