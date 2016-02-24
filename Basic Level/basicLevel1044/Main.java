package basicLevel1044;

import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		// low digit.
		final String[] lowDigit = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov",
				"dec" };

		// high digit.
		final String[] highDigit = { "", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer",
				"jou" };

		// string to number
		Map<String, Integer> map = new HashMap<>();
		for (int i = 0; i < lowDigit.length; i++) {
			map.put(lowDigit[i], i);
		}

		for (int i = 0; i < highDigit.length; i++) {
			map.put(highDigit[i], 13 + i);
		}

		int n = in.nextInt();

		for (int i = 0; i < n; i++) {
			int numInteger = 0;
			String numString = null;

			try {
				numInteger = in.nextInt();
			} catch (InputMismatchException inputMismatchException) {
				numString = in.nextLine();
			} finally {

				if (numString == null) {
					// the input is numbers.
					if (numInteger < 13) {
						System.out.println(lowDigit[numInteger]);
					} else {
						if (numInteger % 13 == 0) {
							System.out.println(highDigit[numInteger / 13]);
						} else {
							System.out.println(highDigit[numInteger / 13] + " " + lowDigit[numInteger % 13]);
						}
					}
				} else {
					// the input is characters.
					String[] tempString = numString.split(" "); // split the
																// input

					// if the length of tempString is 2, it must combine be high
					// and low
					if (tempString.length == 2) {
						System.out.println((map.get(tempString[0]) - 13) * 13 + map.get(tempString[1]));
					} else {
						// maybe high or low

						// map.get(Object) >= 13 is high
						if (map.get(tempString[0]) >= 13) {
							System.out.println((map.get(tempString[0]) - 13) * 13);
						} else {
							System.out.println(map.get(tempString[0]));
						}
					}
				}
			}
		}
		in.close();
	}
}
