#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[50];
    printf("Enter your name :");
    fgets(name,sizeof(name),stdin);
    int  i = 0;
    int inWord = 0;
    while(name[i] !='\0') {
        if(name[i] == ' ') {
            inWord =0;
        } else if (!inWord) {
            name[i] = toupper(name[i]);
            inWord = 1;
        } else { 
            name[i] = tolower(name[i]);
        }
        i++;
    }
    printf("Hello %s",name);
   /* printf("%s",name);
    printf("%d",strlen(name));
    char name1[50];
    strcpy(name1,name);
    printf("\n%s",name1);
    int length = strlen(name);
    for(int i = 0 ;i <length ; i++) {
        name[i] = toupper(name[i]);
        inWord = 1;
    printf("%s\n",name);*/
}