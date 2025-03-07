import java.util.*;
class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Size of Array: ");
        int size = sc.nextInt();
        int[] a = new int[size];
        for (int i = 0; i < size; i++){
            System.out.print("Enter Element: ");
            a[i] = sc.nextInt();
        }
        int Even_sum = 0,Odd_sum = 0;
        for (int i = 0; i < size; i++){
            if (i % 2 == 0){
                Even_sum = Even_sum + a[i];
            }
            else{
                Odd_sum = Odd_sum + a[i];   
            }
        }
        System.out.println("The Sum of Element in the even position is " + Even_sum);
        System.out.println("The Sum of Element in the odd position is " + Odd_sum);
    }
}
