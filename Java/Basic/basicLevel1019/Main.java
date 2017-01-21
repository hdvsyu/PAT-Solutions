package basicLevel1019;

import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		
		int number = in.nextInt();
		in.close();

		while (true) {
			int d = desc(number);
			int i = incr(number);
			number = i - d;
			if (number == 0) {
				System.out.printf("%04d - %04d = %04d\n", i, d, number);
				break;
			}
			
			if (number == 6174) {
				System.out.printf("%04d - %04d = %04d\n", i, d, number);
				break;
			}
			System.out.printf("%04d - %04d = %04d\n", i, d, number);
		}
	}

	public static int desc(int number) {
		char[] array = String.format("%04d", number).toCharArray();
		Arrays.sort(array);
		int temp = 0;
		for (int i = 0; i < 4; i++) {
			temp = temp * 10 + (array[i] - '0');
		}
		return temp;
	}
	
	public static int incr(int number) {
		char[] array = String.format("%04d", number).toCharArray();
		Arrays.sort(array);
		int temp = 0;
		for (int i = 3; i >= 0; i--) {
			temp = temp * 10 + (array[i] - '0');
		}
		return temp;
	}
}
