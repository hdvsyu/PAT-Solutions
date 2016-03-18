package basicLevel1024;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		String[] sci = in.nextLine().split("[.E]");
		in.close();

		int eff = Integer.parseInt(sci[0]);
		int pow = Integer.parseInt(sci[2]);
		if (pow >= 0) {
			System.out.print(eff);
			
			boolean havePoint = true;
			if (sci[1].length() <= pow) {
				havePoint = false;
			}
			int i = 0;
			for (i = 0; i < sci[1].length() && pow != 0; i++, pow--) {
				System.out.print(sci[1].charAt(i));
			}
			
			if (havePoint) {
				System.out.print(".");
				for (; i < sci[1].length(); i++) {
					System.out.print(sci[1].charAt(i));
				}
			}
			
			while (pow != 0) {
				System.out.print("0");
				pow--;
			}
			
		} else {
			if (eff < 0) {
				System.out.print("-");
				eff = -eff;
			}
			
			System.out.print("0.");
			for (int i = 1; i < Math.abs(pow); i++) {
				System.out.print("0");
			}
			System.out.print(eff);
			System.out.print(sci[1]);
		}
	}

}
