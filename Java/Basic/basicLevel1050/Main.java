package basicLevel1050;

// 超时了，看C++的。
import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int N = in.nextInt();

		int[] a = new int[N];
		for (int i = 0; i < N; i++) {
			a[i] = in.nextInt();
		}

		in.close();
		
		Arrays.sort(a);

		int m = 1, n = 1;
		int min = 100001;
		
		// i is n
		for (int i = 1; i <= Math.sqrt(N); i++) {
			if (N % i == 0) {
				// j is m
				int j = N / i;

				// m - n is the most small.
				if (min > j - i) {
					m = j;
					n = i;
					min = m - n;
				}
			}
		}

		int[][] matrix = new int[m][n];
		int index = N - 1;
		int i = 0, j = 0;
		while (index >= 0) {
			// right.
			for (; index >= 0 && j < n && matrix[i][j] == 0; j++) {
				matrix[i][j] = a[index--];
			}
			i++;
			j--;

			// down.
			for (; index >= 0 && i < m && matrix[i][j] == 0; i++) {
				matrix[i][j] = a[index--];
			}

			i--;
			j--;

			// left.
			for (; index >= 0 && j >= 0 && matrix[i][j] == 0; j--) {
				matrix[i][j] = a[index--];
			}
			i--;
			j++;

			// up.
			for (; index >= 0 && i >= 0 && matrix[i][j] == 0; i--) {
				matrix[i][j] = a[index--];
			}
			i++;
			j++;
		}

		for (int p = 0; p < m; p++) {
			System.out.print(matrix[p][0]);
			for (int q = 1; q < n; q++) {
				System.out.print(" " + matrix[p][q]);
			}

			System.out.println("");
		}
	}

}
