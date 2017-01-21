package basicLevel1005;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.TreeSet;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int k = in.nextInt();
		int[] n = new int[k];
		@SuppressWarnings("rawtypes")
		TreeSet[] treeSets = new TreeSet[k];
		for (int i = 0; i < k; i++) {
			n[i] = in.nextInt();
			treeSets[i] = new TreeSet<Integer>(getNumber(n[i]));
		}
		in.close();

		LinkedList<Integer> list = new LinkedList<Integer>();
		for (int i = 0; i < k; i++) {
			if (isMajor(n[i], treeSets, i)) {
				list.add(n[i]);
			}
		}

		int[] array = new int[list.size()];
		for (int i = 0; i < array.length; i++) {
			array[i] = list.get(i);
		}

		Arrays.sort(array);

		for (int i = array.length - 1; i > 0; i--) {
			System.out.print(array[i] + " ");
		}
		System.out.print(array[0]);
	}

	public static boolean isMajor(int n, @SuppressWarnings("rawtypes") TreeSet[] treeSets, int index) {
		for (int i = 0; i < treeSets.length; i++) {
			if (i != index && treeSets[i].contains(n)) {
				return false;
			}
		}
		return true;
	}

	public static TreeSet<Integer> getNumber(int n) {
		TreeSet<Integer> treeSet = new TreeSet<Integer>();
		treeSet.add(n);
		while (n != 1) {
			if (n % 2 == 0) {
				n = n / 2;
			} else {

				n = (3 * n + 1) / 2;
			}

			treeSet.add(n);
		}
		return treeSet;
	}
}