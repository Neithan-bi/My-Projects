import java.util.Scanner;
public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int no1,no2,big,temp;
		System.out.print("Enter no1: ");
		no1 = sc.nextInt();
        System.out.print("Enter no2: ");
        no2 = sc.nextInt();
        big = no1<no2?no1:no2;
        temp = big;
        while(true)
        {
            if (temp % no1 == 0 && temp % no2 == 0)
            {
                break;
            }
            else
            {
                temp = temp + big;
            }
        }
        System.out.println("The LCM is: " + temp);
    }
}
