package advancedLevel1100;

import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		final String[] lowDigit = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov",
				"dec" };
		final String[] highDigit = { "", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer",
				"jou" };
		Map<String, Integer> map = new HashMap<String, Integer>();
		for (int i = 0; i < lowDigit.length; i++) {
			map.put(lowDigit[i], i);
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
					String[] tempString = numString.split(" ");
					if (tempString.length == 2) {
						System.out.println((map.get(tempString[0]) - 13) * 13 + map.get(tempString[1]));
					} else {
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
