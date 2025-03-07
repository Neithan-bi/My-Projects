import java.util.Scanner;
public class Main
{
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
	    System.out.print("Enter The size of the Array: ");
	    int size = sc.nextInt();
	    int temp;
	    int[] array = new int[size];
	    for(int i = 0;i < size; i++){
	        array[i] = sc.nextInt();
	    }
	    
	     for (int i = 0; i < size - 1; i++) {
           for(int j = 0;j < size - 1; j++){
               if(array[j] > array[j + 1]){
                   temp = array[j];
                   array[j] = array[j+1];
                   array[j + 1] = temp;
               }
           }
	     }
	    for(int i = 0;i < size; i++){
	        System.out.print(array[i] + " ");
	    }
	}
}
