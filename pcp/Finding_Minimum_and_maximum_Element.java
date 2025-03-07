public class Main
{
	public static void main(String[] args) {
	    int[] a = {4,8,6,5,9,5,1,2,3,0};
	    int max_element = a[0];
	    int min_element = a[0];
	    for (int i = 0;i < 10;i++){
	        if (max_element <= a[i]){
	            max_element = a[i];
	        }
	        if (min_element > a[i]){
	            min_element = a[i];
	        }
	    }
	    System.out.println("The Maximum Element from the Array:" + max_element);
	    System.out.println("The Minimum Element from the Array:" + min_element);
	}
}