package basicLevel1047;

//I turn it to c plus plus it being passed.
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] team = new int[1001];
		int max = 0;
		for (int i = 0; i < n; i++) {
			String[] scores = in.next().split("[-]");
			int value = in.nextInt();
			int index = Integer.parseInt(scores[0]);
			team[index] += value;
			
			if (team[index] > team[max]) {
				max = index;
			}
		}
		in.close();
		
		System.out.println(max + " " + team[max]);
	}

}
