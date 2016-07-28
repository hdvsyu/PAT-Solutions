package advancedLevel1110;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = Integer.parseInt(in.nextLine());
		if (n >= 1) {
			List<Node> nodes = new ArrayList<Node>();
			Set<Integer> root = new HashSet<Integer>();
			for (int i = 0; i < n; i++) {
				root.add(i); // 把所有的节点加入set容器里面
				String[] s = in.nextLine().split(" ");
				int left = s[0].equals("-") ? -1 : Integer.parseInt(s[0]),
						right = s[1].equals("-") ? -1 : Integer.parseInt(s[1]);
				nodes.add(new Node(left, right));
			}
			in.close();

			for (Node node : nodes) { // 把没有出现的子节点删除掉，剩下的一个就是根节点了
				root.remove(node.left);
				root.remove(node.right);
			}

			int[] t = new int[33]; // 用数组来表示二叉树
			String s = root.toString();
			t[0] = Integer.parseInt(s.substring(1, s.length() - 1)); // 根节点就是二叉树的0号位置
			LinkedList<Integer> val = new LinkedList<Integer>();
			val.add(t[0]);
			int j = 1;
			while (j < n) { // 把所有的节点加入到二叉树中
				int r = val.poll();
				Node node = nodes.get(r);
				val.addLast(node.left);
				val.addLast(node.right);
				t[j++] = node.left;
				t[j++] = node.right;
			}
			String result = haveMinusOne(t, n) ? ("NO " + t[0]) : ("YES " + t[n - 1]); // 如果二叉树中有-1，则它不是一棵完全二叉树
			System.out.println(result);
		}
	}

	public static boolean haveMinusOne(int[] t, int n) {
		for (int i = 0; i < n; i++) {
			if (t[i] == -1) {
				return true;
			}
		}
		return false;
	}
}

class Node {
	int left, right;
	public Node(int left, int right) {
		this.left = left;
		this.right = right;
	}
}