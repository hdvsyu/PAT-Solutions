package basicLevel1025;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int firstAddress = in.nextInt();
		int n = in.nextInt();
		int k = in.nextInt();
		Node[] list = new Node[100000];
		for (int i = 0; i < n; i++) {
			Node temp = new Node(in.nextInt(), in.nextInt(), in.nextInt());
			list[temp.address] = temp;
		}
		in.close();

		List<Node> array = new ArrayList<>();
		link(list, firstAddress, array);

		reverse(array, k);

		for (int i = 0; i < array.size() - 1; i++) {
			System.out.printf("%05d %d %05d\n", array.get(i).address, array.get(i).data, array.get(i + 1).address);
		}
		int end = array.size() - 1;
		System.out.printf("%05d %d -1", array.get(end).address, array.get(end).data);
	}

	public static void reverse(List<Node> array, int k) {
		for (int i = 0; i + k <= array.size(); i += k) {
			for (int m = i + k - 1, n = i; m >= n; m--, n++) {
				Node temp = array.get(n);
				array.set(n, array.get(m));
				array.set(m, temp);
			}
		}
	}

	public static void link(Node[] list, int firstAddress, List<Node> array) {
		while (firstAddress != -1) {
			array.add(list[firstAddress]);
			firstAddress = list[firstAddress].next;
		}
	}
}

class Node {
	int address;
	int data;
	int next;

	Node(int address, int data, int next) {
		this.address = address;
		this.data = data;
		this.next = next;
	}
}