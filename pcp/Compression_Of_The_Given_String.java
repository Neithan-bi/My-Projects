import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Original String: ");
        String input = sc.next();
        String compressed = compressString(input);
        
        System.out.println("Compressed string: " + compressed);
    }

    public static String compressString(String str) {
        String compressed = "";
        int countConsecutive = 0;

        for (int i = 0; i < str.length(); i++) {
            countConsecutive++;

            
            if (i + 1 >= str.length() || str.charAt(i) != str.charAt(i + 1)) {
                compressed += str.charAt(i);
                compressed += countConsecutive;
                countConsecutive = 0;
            }
        }

        return compressed.length() < str.length() ? compressed : str;
    }
}
