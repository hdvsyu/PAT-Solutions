package advancedLevel1007;

import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] nums = new int[n];
		for (int i = 0; i < n; i++) {
			nums[i] = in.nextInt();
		}
		in.close();
	
		int maxSum = -1, left = 0, right = 0, tempSum = 0, tempLeft = 0;
		for (int i = 0; i < n; i++) {
			tempSum += nums[i];
			if (tempSum > maxSum) {
				maxSum = tempSum;
				left = tempLeft;
				right = i;
			} else if (tempSum < 0) {
				tempSum = 0;
				tempLeft = i+1;
			}
		}
		if (havePositive(nums)) {
			System.out.print(maxSum + " " + nums[left] + " " + nums[right]);
		} else {
			System.out.println("0 "+ nums[0] + " " + nums[n - 1]);
		}
	}

	public static boolean havePositive(int[] nums) {
		for (int i = 0; i < nums.length; i++) {
			if (nums[i] >= 0) {
				return true;
			}
		}
		return false;
	}
}
