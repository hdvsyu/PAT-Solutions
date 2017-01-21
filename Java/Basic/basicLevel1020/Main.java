package basicLevel1020;

// please use c plus plus.
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);

		int n = in.nextInt();	// n表示月饼的种类数
		int d = in.nextInt();	// d表示市场最大需求量
		int m = 0;	// m为所有月饼的库存量
		
		double p = 0;
		
		
		MoonCake[] moonCakes = new MoonCake[n];
		// 读取每种月饼的库存量
		for (int i = 0; i < n; i++) {
			moonCakes[i] = new MoonCake();
			moonCakes[i].memoryTotal = in.nextDouble();
			m += moonCakes[i].memoryTotal;
		}

		Set<MoonCake> set = new TreeSet<>();
		// 读取每种月饼的总售价，并求出单个月饼的售价
		for (int i = 0; i < n; i++) {
			moonCakes[i].saleTotal = in.nextDouble();
			p += moonCakes[i].saleTotal;
			moonCakes[i].pricePeer = moonCakes[i].saleTotal / moonCakes[i].memoryTotal;
			set.add(moonCakes[i]);
		}
		in.close();

		if (m >= d) {
			
			double total = 0;
			for (MoonCake moonCake : set) {
				if (d - moonCake.memoryTotal >= 0) {
					total += moonCake.saleTotal;
					d -= moonCake.memoryTotal;
				} else {
					total += moonCake.pricePeer * d;
					break;
				}
			}

			System.out.printf("%.2f", total);
		} else {
			System.out.printf("%.2f", p);	
		}
	}

}

class MoonCake implements Comparable<MoonCake> {
	double memoryTotal;
	double saleTotal;
	double pricePeer;

	@Override
	public int compareTo(MoonCake o) {
		if (this.pricePeer > o.pricePeer) {
			return -1;
		} else if (this.pricePeer < o.pricePeer) {
			return 1;
		} else {
			return 0;
		}
	}

}
