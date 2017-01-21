package advancedLevel1104;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(bufferedReader.readLine());
		String[] nums = bufferedReader.readLine().split(" ");
		bufferedReader.close();
		double sum = 0.0;
		for (int i = 1; i <= n; i++) {
			sum += Double.parseDouble(nums[i - 1]) * i * (n - i + 1);
		}
		System.out.printf("%.2f", sum);
	}

}
