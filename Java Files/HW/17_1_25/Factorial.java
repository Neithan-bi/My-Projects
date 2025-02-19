import java.util.*;
public class Factorial {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.println("Enter factorial value : ");

        int n = in.nextInt();

        int factorial = 1;

        for(int i = 1;i<=n;i++) {
            factorial *= i; }

        System.out.printf("The integer for the factorial number %d is %d",n,factorial);
        in.close();
        
    }
}
