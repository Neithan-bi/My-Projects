import java.util.*;

public class Display_p_from_User {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter number : ");
        int num = in.nextInt();
        int count = 0;
        int i = 1;
        while (count < num) {
            int divisorCount = 0;
            for (int j = 2; j <= Math.sqrt(i); j++) {
                if (i % j == 0) {
                    divisorCount++;
                    break;
                }
            }
            if (divisorCount == 0) {
                System.out.println(i);
                count++;
            }
            i++;
        }
        in.close();
    }
}
