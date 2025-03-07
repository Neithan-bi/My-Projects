import java.util.Scanner;
public class test {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[][] tab = new int[3][3];
        int[] r = new int[3];
        int[] c = new int[3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print("Enter value for [" + i + "][" + j + "] : ");
                tab[i][j] = in.nextInt();}}
                for (int i = 0; i < 3; i++) {
                    for(int j=0;j<3;j++){
                        r[i]+=tab[i][j];
                        c[i]+=tab[j][i];}}
                for(int i =0;i<3;i++){
                    if(r[i]==c[i]) System.out.print("Row " + (i + 1) + " and Column " + (i + 1) + " have the same sum:"+r[i]);
                       }}}