package basicLevel1027;

//have two point failure.
//i am so tired.
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int total = in.nextInt();
		String s = in.next();
		in.close();

		int cnt = 0;
		int dimension = 2 * (int) Math.sqrt((total + 1) / 2) - 1;
		for (int i = 0; i < dimension; i++) {
			for (int j = 0; j < dimension; j++) {
				if ((j >= i && j < dimension - i) || (j <= i && j >= dimension - i - 1)) {
					cnt++;
					System.out.print(s);
				} else {
					System.out.print(" ");
				}
			}

			System.out.println();
		}

		System.out.println(total - cnt);
	}

}
