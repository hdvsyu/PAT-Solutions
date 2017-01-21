package basicLevel1009;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);

		String[] temp = in.nextLine().split(" ");

		for (int i = temp.length - 1; i >= 0; i--) {
			System.out.print(temp[i]);
			if (i != 0) {
				System.out.print(" ");
			}
		}

		in.close();
	}

}
