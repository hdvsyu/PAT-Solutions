package basicLevel1041;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException{
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(bufferedReader.readLine());
		Student[] students = new Student[n];
		for (int i = 0; i < n; i++) {
			String[] strings = bufferedReader.readLine().split(" ");
			students[i] = new Student(strings[0], strings[1], strings[2]);
		}
		
		int m = Integer.parseInt(bufferedReader.readLine());
		String[] test = bufferedReader.readLine().split(" ");
		for (int i = 0; i < m; i++) {
			String findTestSite = test[i];
			
			for (int j = 0; j < n; j++) {
				if (students[j].testSite.equals(findTestSite)) {
					System.out.println(students[j].id + " " + students[j].correctSite);
				}
			}
		}
		bufferedReader.close();
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
