package advancedLevel1003;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	public static List<List<City>> maze = null;
	public static int[] minimum = null;
	public static boolean[] isVisited = null;
	public static int teams = 0;
	public static int cnt = 0;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int c1 = in.nextInt();
		int c2 = in.nextInt();

		isVisited = new boolean[n];
		minimum = new int[n];
		for (int i = 0; i < n; i++) {
			minimum[i] = 1000000007;
		}
		minimum[c2] = 0;
		maze = new ArrayList<>(n);
		for (int i = 0; i < n; i++) {
			maze.add(new ArrayList<City>(n));
		}

		int[] temp = new int[n];
		for (int i = 0; i < n; i++) {
			temp[i] = in.nextInt();
		}

		for (int i = 0; i < m; i++) {
			int ctemp1 = in.nextInt();
			int ctemp2 = in.nextInt();
			int l = in.nextInt();

			maze.get(ctemp1).add(new City(ctemp2, temp[ctemp2], l));
			maze.get(ctemp2).add(new City(ctemp1, temp[ctemp1], l));
		}
		in.close();

		Queue<Integer> queue = new LinkedList<>();
		queue.add(c2);
		bfs(queue, 1);

		isVisited = new boolean[n];
		isVisited[c2] = true;
		dfs(c2, temp[c2], 0, c1);
		System.out.println(cnt + " " + teams);
	}

	public static void bfs(Queue<Integer> q, int step) {

		if (q.isEmpty()) {
			return;
		}

		Queue<Integer> queue = new LinkedList<>();
		while (!q.isEmpty()) {
			int cur = q.poll();
			isVisited[cur] = true;

			List<City> cities = maze.get(cur);
			for (City city : cities) {
				if (!isVisited[city.cityNum] && queue.contains(city.cityNum)) {
					minimum[city.cityNum] = minimum[city.cityNum] < minimum[cur] + city.len ? minimum[city.cityNum]
							: minimum[cur] + city.len;
					queue.add(city.cityNum);
				}
			}
		}
		bfs(queue, step + 1);
	}

	public static void dfs(int curCity, int curTeam, int curPath, int ternimal) {

		if (curPath > minimum[curCity]) {
			return;
		}

		if (curPath <= minimum[ternimal]) {
			cnt++;
			teams = teams > curTeam ? teams : curTeam;
			return;
		}

		List<City> list = maze.get(curCity);
		for (City city : list) {
			if (!isVisited[city.cityNum]) {
				isVisited[city.cityNum] = true;
				dfs(city.cityNum, curTeam + city.teamNum, curPath + city.len, ternimal);
				isVisited[city.cityNum] = false;
			}
		}
	}
}

class City {
	int cityNum;
	int teamNum;
	int len;

	public City(int cityNum, int teamNum, int len) {
		this.cityNum = cityNum;
		this.teamNum = teamNum;
		this.len = len;
	}
}