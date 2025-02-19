import java.util.Scanner;

public class random {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        System.out.print("Enter the number of rows (students): ");
        int size = in.nextInt();
        System.out.print("Enter the number of columns (scores per student): ");
        int ssize = in.nextInt();
        
        double arr[][] = new double[size][ssize];
        
        System.out.println("Enter the scores for each student:");
        for (int i = 0; i < size; i++) {
            System.out.println("Student " + (i + 1) + ":");
            for (int j = 0; j < ssize; j++) {
                System.out.print("Score " + (j + 1) + ": ");
                arr[i][j] = in.nextDouble();
            }
        }
        
        System.out.println("\nScores entered:");
        for (int i = 0; i < arr.length; i++) {
            System.out.print("Student " + (i + 1) + ": ");
            for (int j = 0; j < arr[i].length; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();  
        }
    }
    public void add(){
        int a=5,b=7;
        int c = a+b;
        System.out.println(c);
    }
    public void multiply(){
        int a=5,b=7;
        int c = a*b;
        System.out.println(c);
    }
}
