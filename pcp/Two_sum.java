import java.util.Scanner;
class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int len = sc.nextInt();
        int[] array = new int[len];
        for (int i = 0;i < len;i++){
            array[i] = sc.nextInt();
        }
        int target = sc.nextInt();
        for(int i = 0;i < len;i++){
            for( int j = i + 1 ; j < len;j++){
                if (array[i] + array[j] == target){
                    System.out.print(i);
                    System.out.print(" " + j);
                    return;
                }
            }
        }
    }
}
