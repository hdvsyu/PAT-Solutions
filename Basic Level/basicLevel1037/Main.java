package basicLevel1037;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);

		Coin p = new Coin(in.next().split("[.]"));
		Coin a = new Coin(in.next().split("[.]"));
		in.close();

		Coin result = new Coin();
		if (p.galleon > a.galleon) {
			System.out.print("-");

			// p minus a
			if (p.kunt < a.kunt) {
				p.kunt += 29;
				p.sickle--;
			}
			result.kunt = p.kunt - a.kunt;

			if (p.sickle < a.sickle) {
				p.sickle += 17;
				p.galleon--;
			}
			result.sickle = p.sickle - a.sickle;
			result.galleon = p.galleon - a.galleon;
		} else {
			// a minus p
			if (p.kunt > a.kunt) {
				a.kunt += 29;
				a.sickle--;
			}
			result.kunt = a.kunt - p.kunt;

			if (p.sickle > a.sickle) {
				a.sickle += 17;
				a.galleon--;
			}
			result.sickle = a.sickle - p.sickle;
			result.galleon = a.galleon - p.galleon;
		}

		System.out.print(result.galleon + "." + result.sickle + "." + result.kunt);
	}

}

class Coin {
	int galleon;
	int sickle;
	int kunt;

	public Coin() {
		this.galleon = this.sickle = this.kunt = 0;
	}

	public Coin(String[] coin) {
		this.galleon = Integer.parseInt(coin[0]);
		this.sickle = Integer.parseInt(coin[1]);
		this.kunt = Integer.parseInt(coin[2]);

	}
}
