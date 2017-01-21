package basicLevel1045;
// 只过了第一个测试点
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] array = new int[n];
        int[] copy = new int[n];
		for (int i = 0; i < n; i++) {
			array[i] = in.nextInt();
            copy[i] = array[i];
		}
		in.close();

		Arrays.sort(copy);

        List<Integer> list = new ArrayList<>();
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            if (copy[i] == array[i] && copy[i] > max) {
                list.add(copy[i]);
            }

            if (array[i] > max) {
                max = array[i];
            }

        }

		System.out.println(list.size());
		System.out.print(list.get(0));
		for (int i = 1; i < list.size(); i++) {
			System.out.print(" " + list.get(i));
		}
	}
}
