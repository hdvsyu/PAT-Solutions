package basicLevel1008;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);

		int size = in.nextInt();
		int cnt = in.nextInt();
		int[] array = new int[size];

		for (int i = 0; i < array.length; i++) {
			array[i] = in.nextInt();
		}

		in.close();

		for (int i = 0; i < cnt; i++) {
			int temp = array[array.length - 1];
			for (int j = array.length - 1; j > 0; j--) {
				array[j] = array[j - 1];
			}
			array[0] = temp;
		}

		for (int i = 0; i < array.length; i++) {
			System.out.print(array[i]);
			if (i != array.length - 1) {
				System.out.print(" ");
			}
		}
	}

}
