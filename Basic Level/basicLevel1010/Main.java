package basicLevel1010;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		boolean isHaveOutput = false;
		while (in.hasNext()) {
			int expon = in.nextInt();
			int coef = in.nextInt();
			
			if (expon * coef != 0) {
				if (isHaveOutput) {
					System.out.print(" ");
				} else {
					isHaveOutput = true;
				}
				
				System.out.print(expon * coef + " " + (coef - 1));
			}
		}
		in.close();
		
		if (!isHaveOutput) {
			System.out.print("0 0");
		}
	}
}