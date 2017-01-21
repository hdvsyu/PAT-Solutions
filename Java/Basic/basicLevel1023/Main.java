package basicLevel1023;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int[] times = new int[10];
		for (int i = 0; i < 10; i++) {
			times[i] = in.nextInt();
		}
		in.close();

		StringBuilder s = new StringBuilder();
		for (int i = 1; i < 10; i++) {
			if (times[i] != 0) {
				s.append(i);
				times[i]--;
				break;
			}
		}

		for (int j = 0; j < 10; j++) {
			while (times[j] != 0) {
				s.append(j);
				times[j]--;
			}
		}

		System.out.println(s);

	}
}