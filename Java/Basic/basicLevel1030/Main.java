package basicLevel1030;
//测试点4超时
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int p = in.nextInt();
		
		int[] array = new int[n];
		for (int i = 0; i < n; i++) {
			array[i] = in.nextInt();
		}
		in.close();
		
		Arrays.sort(array);
		
		int cnt = 1;
	    for (int i = n-1; i >= 1; i--) {
	        int temp = 1;
	        int M = array[i];
	        for (int j = i-cnt; j >= 0 && M * 1.0 / array[j] <= p ; j--) {
	            temp = i - j + 1;
	        }
	        cnt = cnt > temp ? cnt : temp;
	    }
		
		System.out.println(cnt);
	}
}