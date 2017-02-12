package advancedLevel1035;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		List<People> list = new ArrayList<>();

		for (int i = 0; i < n; i++) {
			String user = in.next();
			String password = in.next();

			String check = instead(password);
			if (!check.equals(password)) {
				list.add(new People(user, check));
			}
		}
		in.close();


		if (list.size() == 0) {

			if (n == 1) {
				System.out.println("There is 1 account and no account is modified");
			} else {
				System.out.println("There are " + n + " accounts and no account is modified");
			}
		} else {
			System.out.println(list.size());
			for (int i = 0; i < list.size(); i++) {
				if (i != 0) {
					System.out.println();
				}
				People temp = list.get(i);
				System.out.print(temp.user + " " + temp.password);
			}
		}
	}

	public static String instead(String password) {
		char[] temp = password.toCharArray();
		for (int i = 0; i < temp.length; i++) {
			switch (temp[i]) {
			case '1':
				temp[i] = '@';
				break;
			case '0':
				temp[i] = '%';
				break;
			case 'l':
				temp[i] = 'L';
				break;
			case 'O':
				temp[i] = 'o';
				break;
			}
		}

		return new String(temp);
	}
}

class People {
	String user;
	String password;

	public People(String user, String password) {
		this.user = user;
		this.password = password;
	}
}
