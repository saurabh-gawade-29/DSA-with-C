#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev; // prev means previous node
    struct Node *next; // next means next node
};

int main()
{
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;
    struct Node *forth = NULL;

    // Allocate memory
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    forth = (struct Node *)malloc(sizeof(struct Node));

    // Assign data
    head->prev = NULL;
    head->data = 10;
    head->next = second;

    second->prev = head;
    second->data = 20;
    second->next = third;

    third->prev = second;
    third->data = 30;
    third->next = forth;

    forth->prev = third;
    forth->data = 40;
    forth->next = NULL;

    // Traversal forward
    struct Node *temp = head;
    printf("Forward Traversal: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}