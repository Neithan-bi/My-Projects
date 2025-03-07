#include <stdio.h>
#include <conio.h>
int main()
{
    char ch;
    char pwd[200];
    int i = 0;
    printf("Enter Ur Password: ");
    while((ch = getch()) != 13){
        pwd[i] = ch;
        i++;
        printf("* ");
    }
    printf("The Password is %s",pwd);
    return 0;
}