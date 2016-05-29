package advancedLevel1007;
//have errors.
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		
		int n = in.nextInt();
		int[] number = new int[n];
		boolean isAllMinus = true;
		for (int i = 0; i < n; i++) {
			number[i] = in.nextInt();
			if (isAllMinus && number[i] >= 0) {
				isAllMinus = false;
			}
		}
		in.close();
		
		if (isAllMinus) {
			System.out.println(0 + "" + number[0] + ""  +  number[n-1]);
			return;
		}
		int maxSum = 0;
		int first = 0, end = 0;
		int tempSum = 0;
		int tempFirst = 0;
		for (int i = 0; i < n; i++) {
			tempSum += number[i];
			if (tempSum > maxSum) {
				maxSum = tempSum;
				first = tempFirst;
				end = i;
			} else if (tempSum < 0) {
				tempSum = 0;
				tempFirst = i+1;
			}
		}
		
		System.out.print(maxSum + " " + first + " " + end);
	}

}
