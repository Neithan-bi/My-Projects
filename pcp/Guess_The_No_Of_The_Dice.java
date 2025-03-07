import java.util.concurrent.ThreadLocalRandom;
import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int attempts = 5;
		int correct = 0;
		int value = ThreadLocalRandom.current().nextInt(1,7);
		while (attempts > 0){
		    System.out.print("Guess the no of the dice: ");
		    int choice = sc.nextInt();
		    if (choice == value){
		        System.out.println("The no you Guess is correct");
		        correct = 1;
		        break;
		    }
		    else if (choice < value){
		        attempts--;
		        System.out.println("The value is too low");
		        System.out.println("The Remaining Attempts " + attempts);
		    }
		    else if (choice > value){
		        attempts--;
		        System.out.println("The value is too high");
		        System.out.println("The Remaining Attempts " + attempts);
		    }
		}
		if (correct == 0){
		    System.out.print("You failed");
		}
		else{
		    System.out.println("congratulations you got it!");
		}
	}
}
