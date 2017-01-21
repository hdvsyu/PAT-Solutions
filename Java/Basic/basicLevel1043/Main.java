package basicLevel1043;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		String string = in.nextLine();
		in.close();

		List<Character> PList = new ArrayList<>();
		List<Character> AList = new ArrayList<>();
		List<Character> TList = new ArrayList<>();
		List<Character> eList = new ArrayList<>();
		List<Character> sList = new ArrayList<>();
		List<Character> tList = new ArrayList<>();

		for (int i = 0; i < string.length(); i++) {
			switch (string.charAt(i)) {
			case 'P':
				PList.add(string.charAt(i));
				break;
			case 'A':
				AList.add(string.charAt(i));
				break;
			case 'T':
				TList.add(string.charAt(i));
				break;
			case 'e':
				eList.add(string.charAt(i));
				break;
			case 's':
				sList.add(string.charAt(i));
				break;
			case 't':
				tList.add(string.charAt(i));
				break;

			}
		}

		int maxSize = PList.size();
		if (AList.size() > maxSize) {
			maxSize = AList.size();
		}
		if (TList.size() > maxSize) {
			maxSize = TList.size();
		}
		if (eList.size() > maxSize) {
			maxSize = eList.size();
		}
		if (sList.size() > maxSize) {
			maxSize = sList.size();
		}
		if (tList.size() > maxSize) {
			maxSize = tList.size();
		}
		for (int i = 0; i < maxSize; i++) {

			if (i < PList.size()) {
				System.out.print(PList.get(i));
			}
			if (i < AList.size()) {
				System.out.print(AList.get(i));
			}
			if (i < TList.size()) {
				System.out.print(TList.get(i));
			}
			if (i < eList.size()) {
				System.out.print(eList.get(i));
			}
			if (i < sList.size()) {
				System.out.print(sList.get(i));
			}
			if (i < tList.size()) {
				System.out.print(tList.get(i));
			}
		}
	}

}
