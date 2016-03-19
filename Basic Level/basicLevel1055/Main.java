package basicLevel1055;

import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int k = in.nextInt();
		People[] peoples = new People[n];
		for (int i = 0; i < n; i++) {
			peoples[i] = new People(in.next(), in.nextInt());
		}
		in.close();

		Arrays.sort(peoples);

		int per = n / k;
		for (int i = k; i >= 1; i--) {
			int len = 0;
			int index = 0;
			if (i == k) {	
				len = n - k * per + per;
				index = n-1;
			} else {
				len = per;
				index = i * per - 1;
			}
			
			People[] temp = new People[len];
			int left = len / 2;
			int right = len / 2;
			temp[left] = peoples[index--];
			left--;
			right++;
			while (left >= 0 && right < len) {
				temp[left--] = peoples[index--];
				temp[right++] = peoples[index--];
			}
			
			if (left >= 0) {
				temp[left] = peoples[index];
			} else if (right < len) {
				temp[right] = peoples[index];
			}
			
			for (int j = 0; j < len - 1; j++) {
				System.out.print(temp[j].name + " ");
			}
			System.out.println(temp[len - 1].name);
		}
	}

}

class People implements Comparable<People> {
	String name;
	int high;

	public People(String name, int high) {
		this.name = name;
		this.high = high;
	}

	@Override
	public int compareTo(People o) {
		if (this.high < o.high) {
			return -1;
		} else if (this.high > o.high) {
			return 1;
		} else {
			return -this.name.compareTo(o.name);
		}
	}
}