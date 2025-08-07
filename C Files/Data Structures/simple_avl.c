#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *l;
    struct Node *r;
    int h;
} Node;

Node* newNode(int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = v;
    n->l = NULL;
    n->r = NULL;
    n->h = 1;
    return n;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node* n) {
    if (n == NULL) return 0;
    return n->h;
}

int bal(Node* n) {
    if (n == NULL) return 0;
    return height(n->l) - height(n->r);
}

Node* rotR(Node* y) {
    Node* x = y->l;
    Node* T = x->r;
    x->r = y;
    y->l = T;
    y->h = max(height(y->l), height(y->r)) + 1;
    x->h = max(height(x->l), height(x->r)) + 1;
    return x;
}

Node* rotL(Node* x) {
    Node* y = x->r;
    Node* T = y->l;
    y->l = x;
    x->r = T;
    x->h = max(height(x->l), height(x->r)) + 1;
    y->h = max(height(y->l), height(y->r)) + 1;
    return y;
}

Node* insert(Node* n, int v) {
    if (n == NULL) return newNode(v);
    if (v < n->val) n->l = insert(n->l, v);
    else if (v > n->val) n->r = insert(n->r, v);
    else return n;

    n->h = max(height(n->l), height(n->r)) + 1;
    int b = bal(n);

    if (b > 1 && v < n->l->val) return rotR(n);
    if (b < -1 && v > n->r->val) return rotL(n);
    if (b > 1 && v > n->l->val) {
        n->l = rotL(n->l);
        return rotR(n);
    }
    if (b < -1 && v < n->r->val) {
        n->r = rotR(n->r);
        return rotL(n);
    }
    return n;
}

void print(Node* n) {
    if (n != NULL) {
        print(n->l);
        printf("%d ", n->val);
        print(n->r);
    }
}

int main() {
    Node* root = NULL;
    int vals[] = {10, 20, 30, 40, 50, 25};
    for (int i = 0; i < 6; i++) root = insert(root, vals[i]);
    printf("AVL Tree: ");
    print(root);
    printf("\n");
    return 0;
}
