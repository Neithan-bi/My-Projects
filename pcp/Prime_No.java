import java.util.Scanner;
public class Main
{
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
	    System.out.print("Enter the Starting Number: ");
	    int Start = sc.nextInt();
        System.out.print("Enter the Ending Number: ");
	    int End = sc.nextInt();
	    for(int i = Start;i <= End;i++){
	        if(Prime(i) && CompletedPrime(i)){
	            System.out.print(i + " ");
	        }
	    }
	}
	public static boolean Prime(int no){
	    int factors = 0;
	    if (no < 3 ){
	        return false;
	    }
	    for (int i = 2;i <= no;i++){
	        if (no % i == 0){
	            factors++;
	        }
	    }
	    if(factors == 0){
	        return true;
	    }
	    else{
	        return false;
	    }
	}
	public static boolean CompletedPrime(int number) {
        while (number > 0) {
            int digit = number % 10;
            if (!Prime(digit)) {
                return false;
            }
            number /= 10;
        }
        return true;
    }
}
