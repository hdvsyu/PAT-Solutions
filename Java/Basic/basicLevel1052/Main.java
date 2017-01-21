package basicLevel1052;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		List<String> hand = parse(in.nextLine());
		List<String> eye = parse(in.nextLine());
		List<String> mouth = parse(in.nextLine());

		int k = in.nextInt();
		for (int i = 0; i < k; i++) {
			int[] num = new int[5];
			num[0] = in.nextInt();
			num[1] = in.nextInt();
			num[2] = in.nextInt();
			num[3] = in.nextInt();
			num[4] = in.nextInt();

			if (num[0] >= hand.size() || num[0] < 1 || num[4] >= hand.size() || num[4] < 1 || num[1] >= eye.size()
					|| num[1] < 1 || num[3] >= eye.size() || num[3] < 1 || num[2] >= mouth.size() || num[2] < 1) {
				System.out.println("Are you kidding me? @\\/@");
				continue;
			}

			System.out.println(hand.get(num[0]) + "(" + eye.get(num[1]) + mouth.get(num[2]) + eye.get(num[3]) + ")"
					+ hand.get(num[4]));
		}
		in.close();
	}

	public static List<String> parse(String s) {
		boolean isStart = false;
		List<String> list = new ArrayList<>();
		String temp = "";
		list.add(temp);
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '[') {
				isStart = true;
			} else if (s.charAt(i) == ']') {
				isStart = false;
				list.add(temp);
				temp = "";
			} else {
				if (isStart) {
					temp += s.charAt(i);
				}
			}
		}
		return list;
	}

}
