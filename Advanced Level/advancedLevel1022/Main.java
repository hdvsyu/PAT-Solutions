package advancedLevel1022;

import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		in.nextLine();
		Book[] books = new Book[10001];
		for (int i = 0; i < n; i++) {
			books[i] = new Book();

			books[i].id = in.nextLine();
			books[i].title = in.nextLine();
			books[i].author = in.nextLine();
			books[i].keyWords = in.nextLine();
			books[i].publisher = in.nextLine();
			books[i].publishYear = in.nextLine();
		}

		int m = in.nextInt();
		in.nextLine();
		for (int i = 0; i < m; i++) {

			String query = in.nextLine();
			String querySub = query.substring(3);
			Set<String> treeSet = new TreeSet<>();
			if (query.charAt(0) == '1') {
				// Query a book title.
				for (int j = 0; j < n; j++) {
					if (books[j].title.equals(querySub)) {
						treeSet.add(books[j].id);
					}
				}
			} else if (query.charAt(0) == '2') {
				// Query name of author.
				for (int j = 0; j < n; j++) {
					if (books[j].author.equals(querySub)) {
						treeSet.add(books[j].id);
					}
				}
			} else if (query.charAt(0) == '3') {
				// Query a key word.
				for (int j = 0; j < n; j++) {
					if (books[j].keyWords.contains(querySub)) {
						treeSet.add(books[j].id);
					}
				}
			} else if (query.charAt(0) == '4') {
				// Query name of a publisher
				for (int j = 0; j < n; j++) {
					if (books[j].publisher.equals(querySub)) {
						treeSet.add(books[j].id);
					}
				}
			} else {
				// query.charAt(0) == '5'
				// Query a 4-digit number representing the year.
				for (int j = 0; j < n; j++) {
					if (books[j].publishYear.equals(querySub)) {
						treeSet.add(books[j].id);
					}
				}
			}

			System.out.println(query);
			if (treeSet.isEmpty()) {
				System.out.println("Not Found");
			} else {
				for (String t : treeSet) {
					System.out.println(t);
				}
			}
		}

		in.close();
	}

}

class Book {
	String id;
	String title;
	String author;
	String keyWords;
	String publisher;
	String publishYear;

}