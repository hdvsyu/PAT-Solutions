package pat1042;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		// use string to hold the input
		String string = in.nextLine();

		// create a array which length is 26
		int[] array = new int[26];
		for (int i = 0; i < string.length(); i++) {
			char c = string.charAt(i);

			if (c >= 'a' && c <= 'z') {
				array[c - 'a']++;
			} else if (c >= 'A' && c <= 'Z') {
				array[c - 'A']++;
			} else {
				//except character
				//like number, coin sign and other letters.
			}
		}

		in.close();
		
		int maxIndex = 0;
		for (int i = 1; i < array.length; i++) {
			if (array[i] > array[maxIndex]) {
				maxIndex = i;
			}
		}
		
		System.out.println((char)(maxIndex + 'a') + " " + array[maxIndex]);
	}

}
