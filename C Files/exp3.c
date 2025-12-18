#include <stdio.h>
#include <string.h>
void search(char pattern[], char txt[]) {
    int m = strlen(pattern);
    int n = strlen(txt);  
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (txt[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            printf("Pattern found at index %d\n", i);
        }
    }
}
int main() {
    char txt[] = "THIS IS A TEST TEXT";
    char pat[] = "TEST";
    printf("Text: \"%s\"\n", txt);
    printf("Pattern: \"%s\"\n", pat);
    search(pat, txt);
    printf("\n");
    char txt2[] = "AABAACAADAABAABA";
    char pat2[] = "AABA";
    printf("Text: \"%s\"\n", txt2);
    printf("Pattern: \"%s\"\n", pat2);
    search(pat2, txt2);
    return 0;
}