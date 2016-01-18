package basicLevel1014;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		String one = in.nextLine();
		String two = in.nextLine();
		String three = in.nextLine();
		String four = in.nextLine();
		in.close();

		boolean isDay = false;
		boolean isHour = false;
		for (int i = 0; i < one.length() && i < two.length(); i++) {

			if (one.charAt(i) == two.charAt(i)) {
				if (((one.charAt(i) >= 'A' && one.charAt(i) <= 'N') || Character.isDigit(one.charAt(i))) && !isHour
						&& isDay) {
					isHour = true;
					if (one.charAt(i) >= '0' && one.charAt(i) <= '9') {
						System.out.print("0" + one.charAt(i));
					} else {
						System.out.print(one.charAt(i) - 'A' + 10);
					}
				}

				if (one.charAt(i) >= 'A' && one.charAt(i) <= 'G' && !isDay) {
					isDay = true;
					switch (one.charAt(i)) {
					case 'A':
						System.out.print("MON ");
						break;
					case 'B':
						System.out.print("TUE ");
						break;
					case 'C':
						System.out.print("WED ");
						break;
					case 'D':
						System.out.print("THU ");
						break;
					case 'E':
						System.out.print("FRI ");
						break;
					case 'F':
						System.out.print("SAT ");
						break;
					case 'G':
						System.out.print("SUN ");
						break;
					}
				}

			}
		}

		for (int i = 0; i < three.length() && i < four.length(); i++) {
			if ((Character.isUpperCase(three.charAt(i)) || Character.isLowerCase(three.charAt(i)))
					&& three.charAt(i) == four.charAt(i)) {
				System.out.printf(":%02d", i);
			}
		}

	}

}
