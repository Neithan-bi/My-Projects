import java.util.Scanner;
public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String noOfNames = sc.nextLine();
		String[] Names = noOfNames.split(" ");
		for(String i : Names){
		    System.out.print(UpdatedName(i) + " ");
		}
	}
	public static String UpdatedName(String name){
	    char[] chars = name.toCharArray();
        chars[0] = Character.toUpperCase(chars[0]);
        
        for (int i = 1; i < chars.length; i++) {
            chars[i] = Character.toLowerCase(chars[i]);
        }
        
        return new String(chars);
	}
}
