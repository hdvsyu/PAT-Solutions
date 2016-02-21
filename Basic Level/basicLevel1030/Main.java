package basicLevel1030;

//use c plus plus is only test point five is failed.
import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int p = in.nextInt();
		int[] array = new int[n];
		for (int i = 0; i < array.length; i++) {
			array[i] = in.nextInt();
		}
		in.close();
		
		Arrays.sort(array);
		int i = 0, j = n-1;
		while (array[j] > array[i] * p) {
			if (array[j-1] <= array[i] * p) {
				j--;
				break;
			}
			
			if (array[j] <= array[i+1] * p) {
				i++;
				break;
			}
			
			i++;
			j--;
		}
		
		System.out.println(j - i + 1);
	}

}
