#include <stdio.h>  //io
#include <stdlib.h> //malloc

// Node structure
struct Node // Define the structure for a node in the linked list
{
    int data;
    struct Node *next; // Pointer to the next node
};

int main() // main function
{
    // Create nodes
    struct Node *head = NULL;   // Initialize head pointer
    struct Node *second = NULL; // Initialize second pointer
    struct Node *third = NULL;  // Initialize third pointer - next node address no idea

    // Allocate memory
    head = (struct Node *)malloc(sizeof(struct Node));   // Allocate memory for head node
    second = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for second node
    third = (struct Node *)malloc(sizeof(struct Node));  // Allocate memory for third node

    // Assign data & links
    head->data = 10;     // Assign data to head node
    head->next = second; // Link head node to second node

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    // Traversing list
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}