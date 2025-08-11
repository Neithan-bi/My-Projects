#include <stdio.h>
void printarr(int *p) { 
    for(int i = 4 ; i >= 0 ; i--) printf("%d\n",*(p+i));
    printf("%d",'c');


}
int main() {
    int array[] = {1,2,3,7};
    int *a = printarr;    

}
   