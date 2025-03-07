import java.util.*;
public class Main
{
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
	    System.out.print("Enter the Size of the Array: ");
	    int size = sc.nextInt();
	    int[] a = new int[size];
	    for (int i = 0;i < size;i++){
	        System.out.print("Enter Element: ");
	        a[i] = sc.nextInt();
	    }
	    int max_element = a[0];
	    int min_element = a[0];
	    for (int i = 0;i < size;i++){
	        if (max_element <= a[i]){
	            max_element = a[i];
	        }
	    }
	    System.out.println("The Maximum Element from the Array:" + max_element);
	    System.out.println("The Minimum Element from the Array:" + min_element);
	}
}