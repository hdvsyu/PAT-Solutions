package advancedLevel1115;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
	private static List<Node> list = new ArrayList<Node>();
	private static int h = 0;

	public static void main(String[] args) throws IOException {
		// 先把所有的节点都插入都二叉搜索树当中，记录高度，并放到一个容器里面便于查找
		// 然后找到容器里面的节点，找到最后两层的节点
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(bufferedReader.readLine());
		String[] values = bufferedReader.readLine().split(" ");
		if (n >= 1 && n <= 1000) {
			Node root = new Node(Integer.parseInt(values[0]), 1);
			list.add(root);
			h = 1;
			for (int i = 1; i < values.length; i++) {
				insertNode(root, Integer.parseInt(values[i]), 1);
			}
			int n1 = 0, n2 = 0;
			for (Node node : list) {
				if (node.height == h) {
					n1++;
				} else if (node.height == h - 1) {
					n2++;
				}
			}
			
			System.out.println(n1 + " + " + n2 + " = " + (n1 + n2));
		}
	}

	/**
	 * 二叉搜索树的插入
	 * @param root 根节点
	 * @param val 要插入节点的值
	 * @param high 这个节点所处的高度
	 */
	public static void insertNode(Node root, int val, int high) {
		if (val <= root.val) {
			if (root.left != null) {
				insertNode(root.left, val, high + 1);
			} else {
				root.left = new Node(val, high + 1);
				h = h < root.left.height ? root.left.height : h;
				list.add(root.left);
				return;
			}
		} else {
			if (root.right != null) {
				insertNode(root.right, val, high + 1);
			} else {
				root.right = new Node(val, high + 1);
				h = h < root.right.height ? root.right.height : h;
				list.add(root.right);
				return;
			}
		}
	}
}

class Node {
	Node left, right;
	int val, height;

	public Node(int val, int height) {
		this.val = val;
		this.height = height;
		this.left = this.right = null;
	}
}