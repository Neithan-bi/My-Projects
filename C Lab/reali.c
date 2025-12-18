#include <stdio.h>
int main() {
int n;
printf("Enter size of board (N): ");
scanf("%d", &n);
int board[20][20];
printf("Enter the %d x %d matrix (0 = empty, 1 = queen):\n", n, n);
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
scanf("%d", &board[i][j]);
}
}
printf("\nThe matrix you entered:\n");
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
printf("%d ", board[i][j]);
}
printf("\n");
}
int valid = 1;
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
if (board[i][j] == 1) {
for (int k = 0; k < n; k++) {
if (k != j && board[i][k] == 1) valid = 0;
if (k != i && board[k][j] == 1) valid = 0;
}
for (int k = 1; k < n; k++) {
if (i + k < n && j + k < n && board[i+k][j+k] == 1) valid = 0;
if (i - k >= 0 && j - k >= 0 && board[i-k][j-k] == 1) valid = 0;
if (i + k < n && j - k >= 0 && board[i+k][j-k] == 1) valid = 0;
if (i - k >= 0 && j + k < n && board[i-k][j+k] == 1) valid = 0;
}
}
}
}
if (valid)
printf("\n matrix is valid .\n");
else
printf("\nmatrix is not valid\n");
return 0;
}
