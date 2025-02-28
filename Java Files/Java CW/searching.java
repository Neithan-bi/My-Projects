import java.util.*;
public class searching {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int arr[] = {1,2,3,4,5,6,7,8,9,10};
        System.out.println("Enter element to be searched : ");
        int temp = in.nextInt();
        int flag = 1;
        for(int i = 0 ; i < 10 ; i++){
            if(arr[i] == temp) {
                System.out.println("Super");
                flag = 0;
                break; 
             }
            
        }
        if(flag == 1) System.out.println("Poda");


    }
}
