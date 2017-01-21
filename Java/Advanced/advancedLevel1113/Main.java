package advancedLevel1113;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(bufferedReader.readLine());
		String[] numbers = bufferedReader.readLine().split(" ");
		int[] nums = new int[n];
		for (int i = 0; i < nums.length; i++) {
			nums[i] = Integer.parseInt(numbers[i]);
		}
		bufferedReader.close();
		// Arrays.sort(nums);
		qsort(nums);

		int s2 = 0, s1 = 0;
		if (n % 2 == 0) {
			System.out.print("0 ");
		} else {
			System.out.print("1 ");
			s2 = nums[n / 2];
		}

		for (int i = 0; i < n / 2; i++) {
			s1 += nums[i];
			s2 += nums[n - i - 1];
		}
		System.out.println(s2 - s1);
	}

	public static void qsort(int[] nums) {
		qsort(nums, 0, nums.length - 1);
	}

	public static void qsort(int[] nums, int p, int r) {
		if (p < r) {
			int q = partition(nums, p, r);
			qsort(nums, p, q - 1);
			qsort(nums, q + 1, r);
		}
	}

	public static int partition(int[] nums, int p, int r) {
		int x = nums[r], i = p;
		for (int j = p; j < r; j++) {
			if (nums[j] <= x) {
				int temp = nums[j];
				nums[j] = nums[i];
				nums[i] = temp;
				i++;
			}
		}
		int temp = nums[i];
		nums[i] = nums[r];
		nums[r] = temp;
		return i;
	}
}
