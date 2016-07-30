package advancedLevel1102;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;

public class Main {
	private static boolean isSpace = false;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(bufferedReader.readLine());
		List<Node> nodes = new ArrayList<Node>();
		Set<Integer> root = new HashSet<Integer>();
		for (int i = 0; i < n; i++) {
			root.add(i);
			String[] lr = bufferedReader.readLine().split(" ");
			int left = lr[1].equals("-") ? -1 : Integer.parseInt(lr[1]);
			int right = lr[0].equals("-") ? -1 : Integer.parseInt(lr[0]);
			nodes.add(new Node(left, right, i));
		}
		bufferedReader.close();
		for (Node node : nodes) {
			root.remove(node.left);
			root.remove(node.right);
		}

		String rs = root.toString();
		int r = Integer.parseInt(rs.substring(1, rs.length() - 1));
		levelOrder(nodes, r);
		System.out.println();
		inOrder(nodes, r);
	}

	public static void inOrder(List<Node> nodes, int r) {
		Node node = nodes.get(r);
		if (node.left != -1) {
			inOrder(nodes, node.left);
		}
		if (!isSpace) {
			System.out.print(node.val);
			isSpace = true;
		} else {
			System.out.print(" " + node.val);
		}
		if (node.right != -1) {
			inOrder(nodes, node.right);
		}
	}

	public static void levelOrder(List<Node> nodes, int r) {
		LinkedList<Integer> level = new LinkedList<Integer>();
		level.addLast(r);
		System.out.print(r);
		while (!level.isEmpty()) {
			int v = level.poll();
			if (nodes.get(v).left != -1) {
				level.addLast(nodes.get(v).left);
				System.out.print(" " + nodes.get(v).left);
			}
			if (nodes.get(v).right != -1) {
				level.addLast(nodes.get(v).right);
				System.out.print(" " + nodes.get(v).right);
			}
		}
	}
}

class Node {
	int left, right, val;

	public Node(int left, int right, int val) {
		this.left = left;
		this.right = right;
		this.val = val;
	}
}