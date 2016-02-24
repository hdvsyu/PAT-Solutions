package advancedLevelpat1027;

// 将10进制转换为13进制
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("#");
		trans(in.nextInt());
		trans(in.nextInt());
		trans(in.nextInt());
		in.close();
	}
	
	public static void trans(int num) {
		int a = num / 13;
		
		switch (a) {
		case 10:
			System.out.print('A');
			break;
		case 11:
			System.out.print('B');
			break;
		case 12:
			System.out.print('C');
			break;
		default:
			System.out.print(a);
			break;
		}
		
		a = num % 13;
		switch (a) {
		case 10:
			System.out.print('A');
			break;
		case 11:
			System.out.print('B');
			break;
		case 12:
			System.out.print('C');
			break;
		default:
			System.out.print(a);
			break;
		}
	}
}
