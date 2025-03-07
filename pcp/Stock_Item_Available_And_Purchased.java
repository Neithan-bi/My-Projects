import java.util.Scanner;
public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int Total_candidate = 10;
		int purchased = sc.nextInt();
		if (Total_candidate - purchased >= 5){
		    int balance = Total_candidate - purchased;
		    System.out.println("Total Candies Sold: " + purchased);
		    System.out.print("Balance Candies: " + balance);    
		}
		else{
		    System.out.print("You cannot buy the Candies");
		}
	}
}