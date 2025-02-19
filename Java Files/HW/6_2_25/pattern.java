import java.util.Scanner;

public class pattern {
    void pattern1(int x) {
        for (int i = x; i >= 1; i--) {
            for (int j = 1; j <= i; j++) System.out.print(j);
            System.out.println();
        }
        System.out.println();
    }

    void pattern2(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = n - i - 1; j >= 1; j--) System.out.print(" ");
            for (int j = 0; j <= i; j++) System.out.print("* ");
            System.out.println();
        }
        System.out.println();
    }

    void pattern3(int n) {
        int a = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(a + " ");
                a++;
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner patterns = new Scanner(System.in);
        int n = patterns.nextInt();
        System.out.println();
        pattern p = new pattern();
        p.pattern1(n);
        p.pattern2(n);
        p.pattern3(n);
        patterns.close();
    }
}
