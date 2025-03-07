import java.util.Scanner;
public class Main
{
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
	    System.out.print("Enter the Number: ");
	    int no = sc.nextInt();
	    int factors = 0;
	    for (int i = 2;i < i;i++){
	        if (no % i == 0){
	            factors++;
	        }
	    }
	    if(factors){
	        System.out.print("Prime Number");
	    }
	    else{
	        System.out.print("Composite Number");
	    }
	}
}
