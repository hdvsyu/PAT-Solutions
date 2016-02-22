package basicLevel1033;

// 测试点4错误
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		String badKeyInput = in.nextLine();
		String testKey = in.nextLine();
		in.close();
		
		// 判断上档键是否在坏掉的键盘里面
		boolean noShiftKey = true;
		Set<Character> set = new HashSet<>(); // 将坏掉的键放入散列表里面，方便查找
		for (int i = 0; i < badKeyInput.length(); i++) {
			char c = badKeyInput.charAt(i);
			if (c =='+') {
				noShiftKey = false;
			}
			set.add(c);
			set.add(Character.toLowerCase(c));
		}
		
		if (noShiftKey) {
			// 上档键不在坏掉的键里面，可以输出大写的
			for (int i = 0; i < testKey.length(); i++) {
				char c = testKey.charAt(i);
				if (!set.contains(c)) {
					System.out.print(c);
				}
			}
		} else {
			// 上档键在坏掉的键，如果是大写的，则不输出
			for (int i = 0; i < testKey.length(); i++) {
				char c = testKey.charAt(i);
				if (!Character.isUpperCase(c) && !set.contains(c)) {
					System.out.print(c);
				} 
			}
		}
		
	}

}
