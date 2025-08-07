#include <stdio.h>
#include <string.h>

int main() { 
    char str[] = "world of c is not vast bro wdym lil bro";
    char sub[] = "bro";

    char *pos = strstr(str, sub);
    if (pos != NULL) {
        printf("Substring found at position: %ld\n", pos - str);
    } else {
        printf("Substring not found.\n");
    }
    char *pos2 = str;
    int index;
    while ((pos2 = strstr(pos2, sub)) != NULL) {
        printf("Substring found at index: %d\n", index);
        pos2 += strlen(sub);
        index++;
    }
    if (index == 0) {
        printf("Substring not found.\n");
    }
    char str2[] = "hello world";
    char *token = strtok(str2,",");
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, ",");
    }
}
