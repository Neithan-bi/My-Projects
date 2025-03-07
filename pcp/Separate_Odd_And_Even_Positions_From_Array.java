import java.util.*;
class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Size of Array");
        int size = sc.nextInt();
        int[] a = new int[size];
        for (int i = 0; i < size; i++){
            System.out.print("Enter Element: ");
            a[i] = sc.nextInt();
        }
        int even_size = (size + 1) / 2;
        int odd_size = size / 2;
        int[] Odd_elements = new int[odd_size];
        int[] Even_elements = new int[even_size];
        int Even_position = 0,Odd_position = 0;
        for (int i = 0; i < size; i++){
            if (i % 2 == 0){
                Even_elements[Even_position] = a[i];
                Even_position++;
            }
            else{
                Odd_elements[Odd_position] = a[i];
                Odd_position++;
            }
        }
        System.out.println("Odd Position Elements: ");
        for (int i = 0;i < Odd_position; i++){
            System.out.print(Odd_elements[i] + " ");
        }
        System.out.println();
        System.out.println("Even Position Elements: ");
        for (int i = 0;i < Even_position; i++){
            System.out.print(Even_elements[i] + " ");
        }
    }
}
