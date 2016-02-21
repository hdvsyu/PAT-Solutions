package basicLevel1018;
//errors
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] peopleOne = new int[3];	
		int peopleOneWonB = 0;
		int peopleOneWonC = 0;
		int peopleOneWOnJ = 0;
		int peopleTwoWOnB = 0;
		int peopleTwoWonC = 0;
		int peopleTwoWonJ = 0;
		for (int i = 0; i < n; i++) {
			String A = in.next();
			String B = in.next();
			
			if (A.equals("C")) {
				if (B.equals("C")) {
					peopleOne[1]++;
				} else if (B.equals("J")) {
					peopleOne[0]++;
					peopleOneWonC++;
				} else {
					peopleOne[2]++;
					peopleOneWonB++;
				}
			} else if (A.equals("J")) {
				if (B.equals("C")) {
					peopleOne[2]++;
					peopleTwoWonC++;
				} else if (B.equals("J")) {
					peopleOne[1]++;
				} else {
					peopleOne[0]++;
					peopleOneWOnJ++;
				}
				
			} else {
				// A.equals("B")
				if (B.equals("C")) {
					peopleOne[0]++;
					peopleOneWonB++;
				} else if (B.equals("J")) {
					peopleOne[2]++;
					peopleTwoWonJ++;
				}	else {
				//B.equal("B")
					peopleOne[1]++;
				}
			}
		}
		in.close();
		
		System.out.println(peopleOne[0] +" " + peopleOne[1] + " " + peopleOne[2]);
		System.out.println(peopleOne[2] + " " + peopleOne[1] + " " + peopleOne[0]);
		
		int max = peopleOneWonB;
		char maxSymbol = 'B';
		if (peopleOneWonC > max) {
			max = peopleOneWonC;
			maxSymbol = 'C';
		}
		if (peopleOneWOnJ > max) {
			max = peopleOneWOnJ;
			maxSymbol = 'J';
		}
		
		System.out.print(maxSymbol);
		
		max = peopleTwoWOnB;
		maxSymbol = 'B';
		if (peopleTwoWonC > max) {
			max = peopleTwoWonC;
			maxSymbol = 'C';
		}
		if (peopleTwoWonJ > max) {
			max = peopleTwoWonJ;
			maxSymbol = 'J';
		}
		
		System.out.println(" " + maxSymbol);
	}

}
