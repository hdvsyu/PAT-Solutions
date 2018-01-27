package basicLevel1029;
import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String should = in.nextLine().toUpperCase();
        String reality = in.nextLine().toUpperCase();
        in.close();
        String result = "";
        for (int i = 0; i < should.length(); i++)
            if (reality.indexOf(should.charAt(i)) == -1 && result.indexOf(should.charAt(i)) == -1)
                result += should.charAt(i);
        System.out.println(result);
    }
}
