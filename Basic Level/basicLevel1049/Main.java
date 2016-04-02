package basicLevel1049;

//最后两个测试点运行超时
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		double total = 0.0;
		double array;
		for (int i = 0; i < n; i++) {
			array = in.nextDouble();
			total += array * (i + 1) * (n - i);
		}
		in.close();
		
		System.out.printf("%.2f", total);
	}
}
