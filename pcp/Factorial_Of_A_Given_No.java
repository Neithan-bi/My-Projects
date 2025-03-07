import java.util.Scanner;
public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int no,factorial = 1;
		System.out.print("Enter a No: ");
		no = sc.nextInt();
		for(int i = 1;i <= no;i++){
		    factorial = factorial * i;
		}
		System.out.println("The Factorial of " + no + " is " + factorial);
	}
}
