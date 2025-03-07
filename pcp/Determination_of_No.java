import java.util.*;
class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int no = sc.nextInt();
        if (no > 0){
            System.out.println("Positive");
        }
        else if(no < 0){
            System.out.println("Negative");
        }
        else{
            System.out.println("Zero");
        }
    }
}