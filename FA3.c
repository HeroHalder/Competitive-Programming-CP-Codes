#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int data)
{
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* root, int data)
{
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

void postOrder(Node* root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int main()
{
    int values[] = {50, 17, 72, 12, 23, 54, 76, 9, 14, 67};
    int n = sizeof(values) / sizeof(values[0]);

    Node* root = NULL;
    //Insert to BFS
    for (int i = 0; i < n; i++)
    {
        root = insert(root, values[i]);
    }
    //P-order Trav
    printf("Post-order Traversal:\n");
    postOrder(root);
    printf("\n");

    return 0;
}

