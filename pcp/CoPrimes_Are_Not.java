import java.util.*;
class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int no1 = sc.nextInt();
        int no2 = sc.nextInt();
        int max = 0;
        int factors = 0;
        if (no1 >= no2){
            max = no1;
        }
        else{
            max = no2;
        }
        for (int i = 1;i <= max;i++){
            if ((no1 % i == 0) && (no2 % i == 0)){
                factors = factors + 1;
            }
        }
        if (factors == 1){
            System.out.print("YES");
        }
        else{
            System.out.print("NO");
        }
    }
}