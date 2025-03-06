import java.util.*;
class ExceptionHandling {
  
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (true){ 
        try {
            int a = in.nextInt();
            int b = in.nextInt();
            int result = a / b;
            System.out.println(result);
            break;
        } catch(ArithmeticException e) {
            System.out.println("Error: Division by zero is not allowed");
        } catch(InputMismatchException e) {
            System.out.println("Input data type mismatch, please enter the correct data type (int)."); 
        } catch(Exception e) {
            System.out.println("Runtime error occured");  } }
        
        in.close();








    }
}
