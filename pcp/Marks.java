import java.util.*;
class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int marks = sc.nextInt();
        if (marks >= 90){
            if (marks <= 100){
                System.out.println("A");
            }
        }
        else if (marks >= 80){
            if (marks < 90){
                System.out.println("B");
            }
        }
        else if (marks >= 70 ){
            if(marks < 80){
                System.out.println("C");
            }
        }
        else if (marks >= 60){
            if(marks < 70){
                System.out.println("D");
            }
        }
        else{
            System.out.println("F");
        }
    }
}
