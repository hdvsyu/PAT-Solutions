package advancedLevel1108;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(bufferedReader.readLine());
		double sum = 0;
		int cnt = 0;
		String[] numbers = bufferedReader.readLine().split(" ");
		bufferedReader.close();
		for (int i = 0; i < n; i++) {
			try {
				double legal = Double.parseDouble(numbers[i]);
				if (legal > 1000 || legal < -1000 || Math.abs((Double.parseDouble(String.format("%.2f", legal)) - legal)) >= 0.001) {
					throw new NumberFormatException();
				}
				cnt++;
				sum += legal;
			} catch (NumberFormatException numberFormatException) {
				System.out.println("ERROR: " + numbers[i] + " is not a legal number");
			}
		}
		if (cnt == 1) {
			System.out.printf("The average of 1 number is %.2f", sum);
		} else if (cnt == 0) {
			System.out.print("The average of 0 numbers is Undefined");
		} else {
			System.out.printf("The average of %d numbers is %.2f", cnt, sum / cnt);
		}
    }
}
