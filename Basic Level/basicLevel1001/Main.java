package basicLevel1001;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int number = in.nextInt();
		in.close();
		int cnt = 0;
		while (number != 1) {
			if (number % 2 != 0) {
				number = 3 * number + 1;
			}
			
			number /= 2;
			cnt++;
		}
		System.out.println(cnt);
	}

}
