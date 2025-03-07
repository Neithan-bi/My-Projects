import java.util.Scanner;
class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String password = sc.nextLine();
        boolean len = false,upper = false,lower = false,digit = false,spch = false;
        if (password.length() >= 8){
            len = true;
        }
        for(char i : password.toCharArray()){
            if(Character.isUpperCase(i)){
                upper = true;
            }
            else if (Character.isLowerCase(i)){
                lower = true;
            }
            else if(Character.isDigit(i)){
                digit = true;
            }
            else if (!Character.isWhitespace(i)){
                spch = true;
            }
        }
        if (len == true && upper == true && lower == true && digit == true && spch == true){
            System.out.println("Strong");
        }
        else{
            System.out.println("Weak");
        }
    }
}
