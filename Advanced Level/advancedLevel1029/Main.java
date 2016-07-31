package advancedLevel1029;

import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class Main {
	public static void main(String[] args) {
		Set<Double> set = new TreeSet<>();
		Scanner in = new Scanner(System.in);
		int n1 = in.nextInt();
		for (int i = 0; i < n1; i++) {
			set.add(in.nextDouble());
		}
		
		int n2 = in.nextInt();
		for (int i = 0; i < n2; i++) {
			set.add(in.nextDouble());
		}
		in.close();
		
		int mid = (n1 + n2 - 1) / 2;
		
		int i = 0;
		for (Double a : set) {
			if (i == mid) {
				System.out.printf("%.0f", a);
				break;
			}
			i++;
		}
	}
}
