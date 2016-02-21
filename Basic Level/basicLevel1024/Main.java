package basicLevel1024;

//errors
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		String[] sci = in.nextLine().split("[.E]");
		in.close();

		if (sci[0].charAt(0) == '-') {
			System.out.print("-");
		}

		if (sci[2].charAt(0) == '-') {
			int cnt = Integer.parseInt(sci[2].substring(1));
			if (cnt > 1) {
				System.out.print("0.");
				for (int i = 1; i < cnt; i++) {
					System.out.print("0");
				}
			}
			System.out.print(sci[0].substring(1) + sci[1]);
		} else {
			// sci[2].charAt(0) == '+'
			int cnt = Integer.parseInt(sci[2].substring(1));
			System.out.print(sci[0].substring(1) + sci[1]);
			cnt = cnt - sci[2].length();
			for (int i = 0; i <= cnt; i++) {
				System.out.print("0");
			}
		}
	}

}
