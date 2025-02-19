import java.util.*;
public class prime_or_not {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter a number : ");
        int a = in.nextInt();
        if(a % 2 == 0) System.out.printf("%d is even.",a);
        else System.out.printf("%d is odd.",a);
        in.close();
    }
}
