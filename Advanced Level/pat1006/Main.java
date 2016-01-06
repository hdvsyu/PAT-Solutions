package pat1006;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int m = in.nextInt();
		Person[] persons= new Person[m];
		for (int i = 0; i < m; i++) {
			persons[i] = new Person(in.next(), in.next().split(":"), in.next().split(":"));
		}
		in.close();
		
		//sort by signInTime
		Arrays.sort(persons, new Comparator<Person>() {

			@Override
			public int compare(Person o1, Person o2) {
				if (o1.signInTime[0] > o2.signInTime[0]) {
					return 1;
				} else if (o1.signInTime[0] < o2.signInTime[0]) {
					return -1;
				} else {
					
					if (o1.signInTime[1] < o2.signInTime[1]) {
						return -1;
					} else if (o1.signInTime[1] > o2.signInTime[2]) {
						return 1;
					} else {
						
						if (o1.signInTime[2] > o2.signInTime[2]) {
							return 1;
						} else if (o1.signInTime[2] < o2.signInTime[2]) {
							return -1;
						} else {
							return 0;
						}
							
						
					}
					
				}
			}
		});
		
		System.out.print(persons[0].id + " ");
		
		Arrays.sort(persons, new Comparator<Person>() {

			@Override
			public int compare(Person o1, Person o2) {
				if (o1.signOutTime[0] > o2.signOutTime[0]) {
					return 1;
				} else if (o1.signOutTime[0] < o2.signOutTime[0]) {
					return -1;
				} else {
					
					if (o1.signOutTime[1] < o2.signOutTime[1]) {
						return -1;
					} else if (o1.signOutTime[1] > o2.signOutTime[2]) {
						return 1;
					} else {
						
						if (o1.signOutTime[2] > o2.signOutTime[2]) {
							return 1;
						} else if (o1.signOutTime[2] < o2.signOutTime[2]) {
							return -1;
						} else {
							return 0;
						}
							
						
					}
					
				}
			}
		});
		
		System.out.print(persons[persons.length - 1].id);
	}

}

class Person {
	String id;
	int[] signInTime;
	int[] signOutTime;
	
	public Person(String id, String[] signInTime, String[] signOutTime) {
		this.id = id;
		
		this.signInTime = new int[3];
		this.signInTime[0] = Integer.parseInt(signInTime[0]);
		this.signInTime[1] = Integer.parseInt(signInTime[1]);
		this.signInTime[2] = Integer.parseInt(signInTime[2]);
		
		this.signOutTime = new int[3];
		this.signOutTime[0] = Integer.parseInt(signOutTime[0]);
		this.signOutTime[1] = Integer.parseInt(signOutTime[2]);
		this.signOutTime[2] = Integer.parseInt(signOutTime[2]);
	}
}
