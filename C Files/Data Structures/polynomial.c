#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int power;
    struct Node* next; };

// Function to create a new node
struct Node* create(int coefficient, int power) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->power = power;
    newNode->next = NULL;
    return newNode; }

// Function to insert a node at the end of the polynomial
void insertNode(struct Node** poly, int coefficient, int power) {
    struct Node* newNode = create(coefficient, power);
    if (*poly == NULL) {
            *poly = newNode;
            return; }
    struct Node* temp = *poly;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode; }

// Function to display the polynomial
void displayPoly(struct Node* poly) {
    while (poly != NULL) {
                printf("%dx^%d", poly->coefficient, poly->power);
                poly = poly->next;
                if (poly != NULL) printf(" + ");   }
    printf("\n"); }

// Function to add two polynomials
struct Node* addPoly(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 != NULL || poly2 != NULL) {
        int coefficient;
        int power;
        if (poly1 == NULL) {
            insertNode(&result, poly2->coefficient, poly2->power);
            poly2 = poly2->next;
        } else if (poly2 == NULL) {
            insertNode(&result, poly1->coefficient, poly1->power);
            poly1 = poly1->next;
        } else if (poly1->power == poly2->power) {
            coefficient = poly1->coefficient + poly2->coefficient;
            insertNode(&result, coefficient, poly1->power);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->power > poly2->power) {
            insertNode(&result, poly1->coefficient, poly1->power);
            poly1 = poly1->next;
        } else {
            insertNode(&result, poly2->coefficient, poly2->power);
            poly2 = poly2->next; } }  // Adding the negated polynomial to poly1
    return result; }

// Function to subtract two polynomials
struct Node* subtractPoly(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* tempPoly2 = poly2;
    // Negating the coefficients of the second polynomial
    while (tempPoly2 != NULL) {
        insertNode(&result, -tempPoly2->coefficient, tempPoly2->power);
        tempPoly2 = tempPoly2->next; }
    result = addPoly(poly1, result); 
    return result; }

// Function to multiply two polynomials
struct Node* multiplyPoly(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    for (struct Node* ptr1 = poly1; ptr1 != NULL; ptr1 = ptr1->next) {
        for (struct Node* ptr2 = poly2; ptr2 != NULL; ptr2 = ptr2->next) {
            insertNode(&result, ptr1->coefficient * ptr2->coefficient, ptr1->power + ptr2->power); } }
    return result; }

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *result = NULL;
    // Creating two polynomials: 3x^2 + 5x + 6 and 4x + 2
    insertNode(&poly1, 3, 2);
    insertNode(&poly1, 5, 1);
    insertNode(&poly1, 6, 0);
    insertNode(&poly2, 4, 1);
    insertNode(&poly2, 2, 0);

    printf("Polynomial 1: ");
    displayPoly(poly1);
    printf("Polynomial 2: ");
    displayPoly(poly2);

    // Addition
    result = addPoly(poly1, poly2);
    printf("Addition: ");
    displayPoly(result);

    // Subtraction
    result = subtractPoly(poly1, poly2);
    printf("Subtraction: ");
    displayPoly(result);

    // Multiplication
    result = multiplyPoly(poly1, poly2);
    printf("Multiplication: ");
    displayPoly(result);

    return 0;
}
