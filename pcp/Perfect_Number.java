import java.util.*;
class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int factors = 0;
        int count;
        int starting = sc.nextInt();
        int ending = sc.nextInt();
        for(int i = starting;i <= ending;i++){
            factors = 0;
            count = 0;
            for (int j = 1;j < i;j++){
                if (i % j == 0){
                    count = count + j;
                }
            }
            if(count == i){
                System.out.print(i + " ");
            }
        }
    }
}
