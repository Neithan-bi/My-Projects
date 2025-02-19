
import java.util.Scanner;
public class largest_of_3nos {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter values for X, Y, Z :-");
        int x = in.nextInt();
        int y = in.nextInt();
        int z = in.nextInt();
        if(x!=y | x!=z){
        if(x>y && x>z) System.out.println("X is largest");
        if(y>x && y>z) System.out.println("Y is largest");
        else System.out.println("Z is largest"); }
        else System.out.println("Some varibales are equal pls try again");
        in.close();    

    }
}
