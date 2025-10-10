#include <stdio.h>
#include <stdlib.h>

// Structure for a Huffman Tree node
struct Node
{
    char ch;
    int freq;
    struct Node *left, *right;
};

// Create a new node
struct Node *createNode(char ch, int freq)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->ch = ch;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Print Huffman codes (0 for left, 1 for right)
void printCodes(struct Node *root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    // Print when it's a leaf node
    if (!root->left && !root->right)
    {
        printf("%c: ", root->ch);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

int main()
{
    // Step 1: Create leaf nodes manually
    struct Node *A = createNode('A', 5);
    struct Node *B = createNode('B', 9);
    struct Node *C = createNode('C', 12);
    struct Node *D = createNode('D', 13);
    struct Node *E = createNode('E', 16);
    struct Node *F = createNode('F', 45);

    // Step 2: Build the tree manually (for small demo)
    struct Node *AB = createNode('$', A->freq + B->freq);
    AB->left = A;
    AB->right = B;

    struct Node *C_AB = createNode('$', C->freq + AB->freq);
    C_AB->left = C;
    C_AB->right = AB;

    struct Node *DE = createNode('$', D->freq + E->freq);
    DE->left = D;
    DE->right = E;

    struct Node *C_AB_DE = createNode('$', C_AB->freq + DE->freq);
    C_AB_DE->left = C_AB;
    C_AB_DE->right = DE;

    struct Node *root = createNode('$', F->freq + C_AB_DE->freq);
    root->left = F;
    root->right = C_AB_DE;

    // Step 3: Print Huffman codes
    int arr[100];
    printf("Huffman Codes:\n");
    printCodes(root, arr, 0);

    return 0;
}