#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_CONTACTS 100
#define MAX_RECENT 5

typedef struct Contact {
    char name[MAX_NAME];
    char number[20];
    struct Contact* next;
} Contact;

typedef struct Stack {
    char name[MAX_NAME];
    char number[20];
} Stack;

typedef struct TreeNode {
    char name[MAX_NAME];
    char number[20];
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Globals
Contact* head = NULL;
Stack recent[MAX_RECENT];
int top = -1;
TreeNode* root = NULL;

// Stack Functions
void push_recent(char* name, char* number) {
    if (top < MAX_RECENT - 1) {
        top++;
    } else {
        for (int i = 0; i < MAX_RECENT - 1; i++) {
            recent[i] = recent[i + 1];
        }
    }
    strcpy(recent[top].name, name);
    strcpy(recent[top].number, number);
}

void view_recent() {
    if (top == -1) {
        printf("No recent contacts.\n");
        return;
    }
    printf("\nRecently Added Contacts:\n");
    for (int i = top; i >= 0; i--) {
        printf("%s - %s\n", recent[i].name, recent[i].number);
    }
}

// Linked List Functions
void add_contact_ll(char* name, char* number) {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->number, number);
    newContact->next = head;
    head = newContact;
}

// BST Tree Functions
TreeNode* insert_bst(TreeNode* root, char* name, char* number) {
    if (root == NULL) {
        TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
        strcpy(newNode->name, name);
        strcpy(newNode->number, number);
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (strcmp(name, root->name) < 0)
        root->left = insert_bst(root->left, name, number);
    else
        root->right = insert_bst(root->right, name, number);
    return root;
}

TreeNode* search_bst(TreeNode* root, char* keyword) {
    if (root == NULL)
        return NULL;
    if (strcmp(root->name, keyword) == 0 || strcmp(root->number, keyword) == 0)
        return root;
    if (strcmp(keyword, root->name) < 0)
        return search_bst(root->left, keyword);
    return search_bst(root->right, keyword);
}

TreeNode* delete_bst(TreeNode* root, char* name) {
    if (root == NULL) return NULL;
    if (strcmp(name, root->name) < 0)
        root->left = delete_bst(root->left, name);
    else if (strcmp(name, root->name) > 0)
        root->right = delete_bst(root->right, name);
    else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        TreeNode* succParent = root;
        TreeNode* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
        strcpy(root->name, succ->name);
        strcpy(root->number, succ->number);
        if (succParent != root)
            succParent->left = delete_bst(succParent->left, succ->name);
        else
            succParent->right = delete_bst(succParent->right, succ->name);
    }
    return root;
}

// Linked List Functions
void display_all() {
    Contact* temp = head;
    if (!temp) {
        printf("No contacts found.\n");
        return;
    }
    printf("\nAll Contacts:\n");
    while (temp) {
        printf("%s - %s\n", temp->name, temp->number);
        temp = temp->next;
    }
}

void delete_contact_ll(char* name) {
    Contact* temp = head;
    Contact* prev = NULL;

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Contact not found in list.\n");
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Contact deleted from list.\n");
}

// Main Menu
int main() {
    int choice;
    char name[MAX_NAME], number[20], keyword[50];

    while (1) {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display All Contacts\n");
        printf("4. Delete Contact\n");
        printf("5. View Recently Added Contacts\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // buffer clear

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                gets(name);
                printf("Enter Number: ");
                gets(number);
                add_contact_ll(name, number);
                root = insert_bst(root, name, number);
                push_recent(name, number);
                printf("Contact Added.\n");
                break;

            case 2:
                printf("Enter Name or Number to Search: ");
                gets(keyword);
                TreeNode* found = search_bst(root, keyword);
                if (found)
                    printf("Found: %s - %s\n", found->name, found->number);
                else
                    printf("Contact Not Found.\n");
                break;

            case 3:
                display_all();
                break;

            case 4:
                printf("Enter Name to Delete: ");
                gets(name);
                delete_contact_ll(name);
                root = delete_bst(root, name);
                break;

            case 5:
                view_recent();
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);
        }
    }
    return 0;
}

