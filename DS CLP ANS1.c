#include <stdio.h>
#include <stdlib.h>
#include <string.h>
                    // I have define structure for tree node
typedef struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
} Node;
                                  // F for creating new node
Node* createNode(char data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void postorder(Node* root)    // postOrder trav
{
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->data);
}

void printSuccessors(Node* root) //Sucessors
{
    if (root == NULL) return;
    if (root->left)
    {
        printf("%c ", root->left->data);
        printSuccessors(root->left);
    }
    if (root->right)
    {
        printf("%c ", root->right->data);
        printSuccessors(root->right);
    }
}

Node* findNode(Node* root, char target) //node finding
{
    if (root == NULL) return NULL;
    if (root->data == target) return root;
    Node* found = findNode(root->left, target);
    if (found) return found;
    return findNode(root->right, target);
}

int main()
{
    Node *A = createNode('A');  // mannually creating b tree
    Node *B = createNode('B');
    Node *C = createNode('C');
    Node *D = createNode('D');
    Node *E = createNode('E');
    Node *F = createNode('F');
    Node *G = createNode('G');
    Node *H = createNode('H');
    Node *I = createNode('I');
    Node *J = createNode('J');

    A->left = B; //building tree Structure
    A->right = C;
    B->left = D;
    B->right = E;
    C->left = F;
    C->right = G;
    D->left = H;
    D->right = I;
    F->right = J;

    printf("Postorder traversal: ");
    postorder(A);
    printf("\n");

    char input;
    printf("Enter the node: ");
    scanf(" %c", &input);

    Node* node = findNode(A, input);
    if (node)
    {
        printf("Successors of %c: ", input);
        printSuccessors(node);
        printf("\n");
    }
    else
    {
        printf("Node not found in the tree.\n");
    }

    return 0;
}
