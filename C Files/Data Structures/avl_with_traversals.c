#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

Node* createNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node* node) {
    if (node == NULL) return 0;
    return node->height;
}

int balanceFactor(Node* node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* insert(Node* node, int val) {
    if (node == NULL) return createNode(val);

    if (val < node->val)
        node->left = insert(node->left, val);
    else if (val > node->val)
        node->right = insert(node->right, val);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    if (balance > 1 && val < node->left->val)
        return rightRotate(node);

    if (balance < -1 && val > node->right->val)
        return leftRotate(node);

    if (balance > 1 && val > node->left->val) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && val < node->right->val) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->val);
    }
}

void levelOrder(Node* root) {
    if (root == NULL) return;

    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node* current = queue[front++];
        printf("%d ", current->val);

        if (current->left != NULL)
            queue[rear++] = current->left;
        if (current->right != NULL)
            queue[rear++] = current->right;
    }
}

int main() {
    Node* root = NULL;
    int n, val;

    printf("Enter number of values: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("\nInorder (Sorted): ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\nBFS (Level Order): ");
    levelOrder(root);

    printf("\n");
    return 0;
}
