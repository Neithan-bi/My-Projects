import java.util.Scanner;
public class Main
{
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
		int row,col;
		System.out.print("Enter No of Rows: ");
		row = sc.nextInt();
		System.out.print("Enter No of Columns: ");
		col = sc.nextInt();
		int[][] matrix = new int[row][col];
		System.out.println("Enter elements for a " + row + " X " + col + " matrix:");

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }
        System.out.println("\nElements for a 3x3 matrix:");
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
	}
}
