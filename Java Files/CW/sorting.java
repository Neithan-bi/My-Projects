import java.util.*;
public class sorting {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int arr[] = {3, 7, 9, 5, 2, 1, 10, 8, 6, 4};
        System.out.println("Unsorted array : ");
        for (int i = 0; i < arr.length; i++) System.out.print(arr[i] + " ");
        for (int i = 0; i < arr.length-1; i++) {
            for (int j = i+1; j < 10; j++){
                if (arr[i] > arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
                
            }
        }
        System.out.println("\nSorted array : ");
        for (int i = 0; i < arr.length; i++) System.out.print(arr[i] + " ");
            
    }
}
