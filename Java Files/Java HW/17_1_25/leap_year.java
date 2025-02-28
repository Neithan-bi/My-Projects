import java.util.*;
public class leap_year {
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        System.out.println("Enter value your data : ");

        int year = in.nextInt();

        if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {

            System.out.println(year+" is a leap");
        }
        else {
            System.out.println(year+" is not a leap");
        }
        in.close();
    }
}
