package basicLevel1041;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		Student[] students = new Student[n];
		for (int i = 0; i < n; i++) {
			students[i] = new Student(in.next(), in.next(), in.next());
		}
		
		int m = in.nextInt();
		for (int i = 0; i < m; i++) {
			String findTestSite = in.next();
			
			for (int j = 0; j < n; j++) {
				if (students[j].testSite.equals(findTestSite)) {
					System.out.println(students[j].id + " " + students[j].correctSite);
				}
			}
		}
		in.close();
	}

}

class Student {
	String id;
	String testSite;
	String correctSite;
	
	public Student(String id, String testSite, String correctSite) {
		this.id = id;
		this.testSite = testSite;
		this.correctSite = correctSite;
	}
}
