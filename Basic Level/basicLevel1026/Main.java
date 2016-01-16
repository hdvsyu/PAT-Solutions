package basicLevel1026;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int c1 = in.nextInt();
		int c2 = in.nextInt();
		in.close();
		
		int seconds = (int)((c2 - c1) * 1.0 / 100 + 0.5);
		System.out.printf("%02d:%02d:%02d", seconds / 3600, seconds / 60 % 60, seconds % 60);
	}

}
