import java.util.Scanner;
public class Main
{
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
	    System.out.print("Enter the Size: ");
	    int size = sc.nextInt();
	    int[] Arr = new int[size];
	    System.out.println("Enter the Elements ");
	    int EvenSum = 0,OddSum = 0;
	    for (int i = 0;i < size;i++){
	        Arr[i] = sc.nextInt();
	    }
	    for(int i = 0;i < size;i++){
	        if (Arr[i] % 2 == 0){
	            EvenSum = EvenSum + Arr[i];
	        }
	        else{
	            OddSum = OddSum + Arr[i];
	        }
	    }
	    System.out.println("The Sum of Even Elements in the Array: " + EvenSum);
	    System.out.println("The Sum of Odd Elements in the Array: " + OddSum);
	}
}
