package basicLevel1028;

//errors
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		People[] peoples = new People[n];
		List<People> list = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			peoples[i] = new People(in.next(), in.next());
			if (peoples[i].isVaild) {
				list.add(peoples[i]);
			}
		}
		in.close();

		System.out.print(list.size() + " ");

		Arrays.sort(peoples);
		int i = n-1;
		while (!peoples[i].isVaild) {
			i--;
		}
		System.out.print(peoples[i].name + " ");
		
		i = 0;
		while (!peoples[i].isVaild) {
			i++;
		}
		System.out.print(peoples[i].name);
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
