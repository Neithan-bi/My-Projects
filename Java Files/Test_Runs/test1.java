import java.util.*;
public class test1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter no for students and subjects: ");
        int size = in.nextInt();
        int ssize = in.nextInt();
        double arr[][] = new double[size][ssize];
        for(int i = 0; i < arr.length; i++) {
                for(int j = 0; j < arr[i].length; j++) {
                        arr[i][j] = in.nextDouble();
            }
        }
        for(int i = 0; i < arr.length; i++) {
                for(int j = 0; j < arr[i].length; j++) {
                        System.out.print(arr[i][j] + " ");
            }
                System.out.println();
        }
        in.close();
    }
}
