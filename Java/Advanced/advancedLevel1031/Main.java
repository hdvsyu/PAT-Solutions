package advancedLevel1031;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
		String string = bufferedReader.readLine();
		bufferedReader.close();
		int n = (string.length() + 2) / 3 - 1;
		for (int i = 0; i < n; i++) {
			System.out.print(string.charAt(i));
			for (int j = 0; j < string.length() - 2 * n - 2; j++) {
				System.out.print(" ");
			}
			System.out.println(string.charAt(string.length() - 1 - i));
		}
		System.out.println(string.substring(n, string.length() - n));
	}
}
