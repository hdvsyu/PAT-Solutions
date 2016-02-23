package basicLevel1045;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] array = new int[n];
		for (int i = 0; i < n; i++) {
			array[i] = in.nextInt();
		}
		in.close();

		int[] min = new int[n];
		min[0] = 0;
		for (int i = 1; i < n; i++) {
			min[i] = min[i - 1] < array[i - 1] ? min[i - 1] : array[i - 1];
		}

		int[] max = new int[n];
		max[n - 1] = Integer.MAX_VALUE;
		for (int i = n - 2; i >= 0; i--) {
			max[i] = max[i + 1] > array[i + 1] ? max[i + 1] : array[i + 1];
		}

		List<Integer> list = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			if (array[i] > min[i] && array[i] < max[i]) {
				list.add(array[i]);
			}
		}

		System.out.println(list.size());
		System.out.print(list.get(0));
		for (int i = 1; i < list.size(); i++) {
			System.out.print(" " + list.get(i));
		}
	}
}
