#include <iostream>
#include <cstring>  
using namespace std;      
int main(){
    int i;
    char str[]="Yeahboi";
    i=0;
    while(isalpha(str[i])){
        i++;
    }
    printf("the first %d characters are alphabetic\n",i);
    return 0;
}