import java.util.*;                                                          
public class Area_Of_Circle {                                                
    public static void main(String[] args) {                                 
        System.out.print("Enter radius of circle : ");                       
        Scanner in = new Scanner(System.in);                                 
        int radius = in.nextInt();                                           
        double area = radius*radius*Math.PI;                                 
        System.out.printf("Area of Circle of Radius %d is %.2f",radius,area);
        in.close();                                                          

    }
}



