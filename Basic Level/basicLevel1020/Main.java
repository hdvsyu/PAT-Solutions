package basicLevel1020;

//errors
import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);

		int n = in.nextInt();
		int d = in.nextInt();
		int m = 0;
		double p = 0;
		MoonCake[] moonCakes = new MoonCake[n];
		for (int i = 0; i < n; i++) {
			moonCakes[i] = new MoonCake();
			moonCakes[i].memoryTotal = in.nextInt();
			m += moonCakes[i].memoryTotal;
		}

		for (int i = 0; i < n; i++) {
			moonCakes[i].saleTotal = in.nextInt();
			p += moonCakes[i].saleTotal;
			moonCakes[i].pricePeer = moonCakes[i].saleTotal * 1.0 / moonCakes[i].memoryTotal;
		}
		in.close();

		if (m >= d) {
			Arrays.sort(moonCakes);

			double total = 0;
			for (int i = 0; i < n; i++) {
				if (d - moonCakes[i].memoryTotal >= 0) {
					total += moonCakes[i].saleTotal;
					d -= moonCakes[i].saleTotal;
				} else {
					total += moonCakes[i].pricePeer * d;
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
	int memoryTotal;
	int saleTotal;
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
