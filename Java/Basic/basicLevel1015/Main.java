package basicLevel1015;

// The test point 2, 3, 4 run time out.
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int l = in.nextInt();
		int h = in.nextInt();

		Set<Student> setOne = new TreeSet<>();
		Set<Student> setTwo = new TreeSet<>();
		Set<Student> setThree = new TreeSet<>();
		Set<Student> setFour = new TreeSet<>();
		for (int i = 0; i < n; i++) {
			int id = in.nextInt();
			int mora = in.nextInt();
			int talent = in.nextInt();

			if (mora >= l && talent >= l) {
				Student temp = new Student(id, mora, talent, h);
				switch (temp.classType) {
				case 1:
					setOne.add(temp);
					break;
				case 2:
					setTwo.add(temp);
					break;
				case 3:
					setThree.add(temp);
					break;
				case 4:
					setFour.add(temp);
					break;
				}
			}
		}
		in.close();

		
		System.out.println(setOne.size() + setTwo.size() + setThree.size() + setFour.size());
		for (Student s : setOne) {
			System.out.printf("%08d %d %d\n", s.id, s.mora, s.talent);
		}
		for (Student s : setTwo) {
			System.out.printf("%08d %d %d\n", s.id, s.mora, s.talent);
		}
		for (Student s : setThree) {
			System.out.printf("%08d %d %d\n", s.id, s.mora, s.talent);
		}
		for (Student s : setFour) {
			System.out.printf("%08d %d %d\n", s.id, s.mora, s.talent);
		}
	}
}

class Student implements Comparable<Student> {
	int id;
	int mora;
	int talent;
	int score;
	int classType;

	public Student(int id, int mora, int talent, int h) {
		this.id = id;
		this.mora = mora;
		this.talent = talent;
		this.score = talent + mora;

		if (mora >= h && talent >= h) {
			classType = 1;
		} else if (mora >= h && talent < h) {
			classType = 2;
		} else if (mora < h && talent < h && mora >= talent) {
			classType = 3;
		} else {
			classType = 4;
		}

	}

	@Override
	public int compareTo(Student s) {

		if (this.score < s.score) {
			return 1;
		} else if (this.score > s.score) {
			return -1;
		} else {
			if (this.mora < s.mora) {
				return 1;
			} else if (this.mora > s.mora) {
				return -1;
			} else {
				if (this.id > s.id) {
					return 1;
				} else if (this.id < s.id) {
					return -1;
				} else {
					return 0;
				}
			}
		}
	}

}
