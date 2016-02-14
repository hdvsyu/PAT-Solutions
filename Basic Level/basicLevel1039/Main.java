package basicLevel1039;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		char[] sales = in.nextLine().toCharArray();
		char[] bought = in.nextLine().toCharArray();
		in.close();

		Arrays.sort(sales);
		Arrays.sort(bought);

		int debt = 0;
		for (int i = 0, j = 0; j < bought.length;) {
			if (i != sales.length) {

				if (sales[i] == bought[j]) {
					i++;
					j++;
				} else if (sales[i] > bought[j]) {
					j++;
					debt++;
				} else {
					// sales[i] < bought[j];
					i++;

					if (i == sales.length) {
						debt += sales.length - i;
					}
				}
			} else {
				debt += bought.length - j;
				break;
			}
		}

		if (debt == 0) {
			System.out.println("Yes " + (sales.length - bought.length));
		} else {
			System.out.println("No " + debt);
		}
	}
}