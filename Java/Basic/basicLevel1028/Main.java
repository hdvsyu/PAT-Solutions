package basicLevel1028;

// 测试点4运行超时
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		People max = new People("", "2014/09/06");
		People min = new People("", "1814/09/06");
		int isValid = 0;
		for (int i = 0; i < n; i++) {
			People p = new People(in.next(), in.next());
			if (p.isVaild) {
				max = max.compareTo(p) > 0 ? max : p;
				min = min.compareTo(p) < 0 ? min : p;
				isValid++;
			}
			
		}
		in.close();

		if (isValid == 0) {
			System.out.println(0);
		} else {
			System.out.println(isValid + " " + max.name + " " + min.name);
		}
	}

}

class People implements Comparable<People>{
	String name;
	int year;
	int month;
	int day;
	boolean isVaild;

	public People(String name, String date) {
		this.name = name;
		String[] d = date.split("/");
		year = Integer.parseInt(d[0]);
		month = Integer.parseInt(d[1]);
		day = Integer.parseInt(d[2]);

		if (year > 2014) {
			isVaild = false;
		} else if (year == 2014) {
			if (month > 9) {
				isVaild = false;
			} else if (month == 9) {
				if (day > 6) {
					isVaild = false;
				} else {
					isVaild = true;
				}
			} else {
				isVaild = true;
			}
		} else if (year < 2214 && year > 1814) {
			isVaild = true;
		} else if (year < 1814) {
			isVaild = false;
		} else if (year == 1814) {
			if (month < 9) {
				isVaild = false;
			} else if (month == 9) {
				if (day >= 6) {
					isVaild = true;
				} else {
					isVaild = false;
				}
			} else {
				isVaild = true;
			}
		} else {
			isVaild = false;
		}
	}

	@Override
	public int compareTo(People o) {
		if (this.year > o.year) {
			return -1;
		} else if (this.year < o.year) {
			return 1;
		} else {
			if (this.month > o.month) {
				return -1;
			} else if (this.month < o.month) {
				return 1;
			} else {
				if (this.day < o.day) {
					return 1;
				} else if (this.day > o.day) {
					return -1;
				} else {
					return 0;
				}
			}
		}
	}

}
