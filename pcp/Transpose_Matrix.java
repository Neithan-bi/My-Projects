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
		int[][] transpose = new int[col][row];
		System.out.println("Enter elements for a " + row + " X " + col + " matrix:");

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                transpose[j][i] = matrix[i][j];
            }
        }
            
        System.out.println("Enter elements for a " + row + " X " + col + " matrix:");
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
        
        System.out.println("Enter elements for a " + row + " X " + col + " matrix:");
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < row; j++) {
                System.out.print(transpose[i][j] + " ");
            }
            System.out.println();
        }
	}
}
