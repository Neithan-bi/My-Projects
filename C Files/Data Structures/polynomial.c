#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 100
void addPoly(int* poly1, int* poly2, int* result, int maxPower) {
    for (int i = 0; i <= maxPower; i++) {
        result[i] = poly1[i] + poly2[i];
    }
}
void subtractPoly(int* poly1, int* poly2, int* result, int maxPower) {
    for (int i = 0; i <= maxPower; i++) {
        result[i] = poly1[i] - poly2[i];
    }
}
void multiplyPoly(int* poly1, int* poly2, int* result, int maxPower1, int maxPower2) {
    for (int i = 0; i <= maxPower1 + maxPower2; i++) {
        result[i] = 0;
    }
    for (int i = 0; i <= maxPower1; i++) {
        for (int j = 0; j <= maxPower2; j++) {
            result[i + j] += poly1[i] * poly2[j];
        }
    }
}

void displayPoly(int* poly, int maxPower) {
    for (int i = maxPower; i >= 0; i--) {
        if (poly[i] != 0) {
            if (i != maxPower && poly[i] > 0) printf(" + ");
            printf("%dx^%d", poly[i], i);
        }
    }
    printf("\n");
}

int main() {
    int poly1[MAX_TERMS] = {0}, poly2[MAX_TERMS] = {0}, result[MAX_TERMS] = {0};
    int maxPower1 = 2, maxPower2 = 1;
    poly1[2] = 3; poly1[1] = 5; poly1[0] = 6;
    poly2[1] = 4; poly2[0] = 2;

    printf("Polynomial 1: ");
    displayPoly(poly1, maxPower1);
    printf("Polynomial 2: ");
    displayPoly(poly2, maxPower2);


    addPoly(poly1, poly2, result, maxPower1 > maxPower2 ? maxPower1 : maxPower2);
    printf("Addition: ");
    displayPoly(result, maxPower1 > maxPower2 ? maxPower1 : maxPower2);


    subtractPoly(poly1, poly2, result, maxPower1 > maxPower2 ? maxPower1 : maxPower2);
    printf("Subtraction: ");
    displayPoly(result, maxPower1 > maxPower2 ? maxPower1 : maxPower2);

    multiplyPoly(poly1, poly2, result, maxPower1, maxPower2);
    printf("Multiplication: ");
    displayPoly(result, maxPower1 + maxPower2);

    return 0;
}
