package basicLevel1029;
import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String should = in.nextLine();
        String reality = in.nextLine();
        in.close();
        String bad = "";
        for (int i = 0; i < should.length(); i++)
            if (reality.indexOf(should.charAt(i)) == -1 && bad.indexOf(Character.toUpperCase(should.charAt(i))) == -1)
                bad += Character.toUpperCase(should.charAt(i));
        System.out.println(bad);
    }
}
