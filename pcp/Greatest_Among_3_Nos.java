import java.util.*;
class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int no1,no2,no3;
        no1 = sc.nextInt();
        no2 = sc.nextInt();
        no3 = sc.nextInt();
        if ((no1 >= no2)&& (no1 >= no3)){
            System.out.println(no1);
        }
        else if((no2 >= no3) && (no2 >= no1)){
            System.out.println(no2);
        }
        else{
            System.out.println(no3);
        }
    }
}
