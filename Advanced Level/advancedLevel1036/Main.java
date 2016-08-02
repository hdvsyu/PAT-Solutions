package advancedLevel1036;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(bufferedReader.readLine());
		Student girl = null, boy = null;
		for (int i = 0; i < n; i++) {
			String[] info = bufferedReader.readLine().split(" ");
			Student t = new Student(info[0], info[1], info[2], Integer.parseInt(info[3]));
			if (t.gender.equals("M")) {
				boy = boy == null ? t : (boy.grade < t.grade ? boy : t);
			} else { // t.gender.equals("F");
				girl = girl == null ? t : (girl.grade > t.grade ? girl : t);
			}
		}
		bufferedReader.close();
		
		if (girl != null) System.out.println(girl.name + " " + girl.id);
		else System.out.println("Absent");
		if (boy != null) System.out.println(boy.name + " " + boy.id);
		else System.out.println("Absent");
		if (boy == null || girl == null) System.out.println("NA");
		else System.out.println(girl.grade - boy.grade);
	}

}

class Student {
	String name, gender, id;
	int grade;
	
	public Student(String name, String gender, String id, int grade) {
		this.name = name;
		this.gender = gender;
		this.id = id;
		this.grade = grade;
	}
}