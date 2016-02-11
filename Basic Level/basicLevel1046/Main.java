package basicLevel1046;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int jia = 0, yi = 0;
		for (int i = 0; i < n; i++) {
			int jwhj = in.nextInt();
			int jwhw = in.nextInt();
			int yihj = in.nextInt();
			int yihw = in.nextInt();
			
			int sum = jwhj + yihj;
			if (jwhw == sum && yihw != sum) {
				yi++;
			} else if (jwhw != sum && yihw == sum) {
				jia++;
			}
		}
		in.close();
		
		System.out.println(jia + " " + yi);
	}

}
