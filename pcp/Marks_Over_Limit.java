import java.util.*;
class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int marks[] = new int[size];
        for (int i = 0;i < size; i++){
            marks[i] = sc.nextInt();
        }
        int count = 0;
        int maximumMark = sc.nextInt();
        for(int i = 0;i < size;i++){
            if (marks[i] >= maximumMark){
                count = count + 1;
            }
        }
        System.out.print(count);
    }
}
