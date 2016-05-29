package advancedLevelpat1052;

import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		Node[] nodes = new Node[n];
		Main main = new Main();
		for (int i = 0; i < n; i++) {
			nodes[i] = main.new Node(in.next(), in.nextInt(), in.next());
		}
		in.close();

		Arrays.sort(nodes);
		System.out.println(n + " " + nodes[0].preAddress);
		for (int i = 0; i < n - 1; i++) {
			System.out.println(nodes[i].preAddress + " " + nodes[i].num + " " + nodes[i + 1].preAddress);
		}
		System.out.print(nodes[n - 1].preAddress + " " + nodes[n - 1].num + " -1");
	}

	private class Node implements Comparable<Node> {

		String preAddress;
		int num;
		String nextAddress;

		public Node(String preAddress, int num, String nextAddress) {
			this.nextAddress = nextAddress;
			this.preAddress = preAddress;
			this.num = num;
		}

		@Override
		public int compareTo(Node o) {
			if (this.num > o.num) {
				return -1;
			} else if (this.num == o.num) {
				return 0;
			} else {
				return 1;
			}
		}

	}
}
