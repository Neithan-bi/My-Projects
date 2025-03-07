import java.util.Scanner;
public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter No.of Terms: ");
		int no = sc.nextInt();
		System.out.print("Enter the Starting No: ");
		int a = sc.nextInt();
		System.out.print("Enter the Ending No: ");
		int b = sc.nextInt();
		for (int i = 0; i < no; ++i) {
            System.out.print(a + " ");

            // compute the next term
            int c = a + b;
            a = b;
            b = c;
        }
		
	}
}
