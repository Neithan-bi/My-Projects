
import java.util.*;
public class ewr {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter no. of Students : ");
        int size = in.nextInt();
        System.out.print("Enter no. of Subjects : ");
        int ssize = in.nextInt();
        double arr[][] = new double[size][ssize];
        for(int i = 0 ; i < arr.length ; i++ ){
            for(int j = 0 ; j < arr[i].length ; j++) {
                System.out.printf("Enter marks for students %d for subjects %d.",(i+1),(j+1));
                arr[i][j] = in.nextInt();
            }
        }
        
        for(int i = 0 ; i < size; i++){
            for(int j = 0 ; j < ssize ; j++){
                System.out.print(arr[i][j]);
            }
            System.out.println("");
        }
    }
    
}
