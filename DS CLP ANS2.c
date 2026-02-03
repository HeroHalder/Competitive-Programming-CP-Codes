#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *left, *right;
} Node;

 Node* newNode(int val)
{
    Node* n = malloc(sizeof(Node));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

Node* insert(Node* root, int val)
{
    if (!root) return newNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

Node* queue[100]; // Simple Q
int front = 0, rear = 0;

void enqueue(Node* n)
{
    queue[rear++] = n;
}
Node* dequeue()
{
    return queue[front++];
}
int isEmpty()
{
    return front == rear;
}

void bfs(Node* root)
{
    if (!root) return;
    enqueue(root);
    while (!isEmpty())
    {
        Node* curr = dequeue();
        printf("%d", curr->val);
        if (!isEmpty()) printf(" -> ");
        if (curr->left) enqueue(curr->left);
        if (curr->right) enqueue(curr->right);
    }
}

int main()
{
    int vals[] = {50, 17, 72, 12, 23, 54, 76, 9, 14, 67};
    Node* root = NULL;
    for (int i = 0; i < 10; i++) root = insert(root, vals[i]);
    bfs(root);
    return 0;
}
