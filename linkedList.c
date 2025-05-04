#include <stdio.h>
#include <stdlib.h>

// Defining node structure for linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function to traverse and print the linked list
void traverseList(Node *head)
{
    Node *ptr = head;
    printf("Head -> ");
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// Function to insert given data into first node
void insertAtFirst(Node **head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = *head;
    *head = ptr;
}

// Function to insert given data into last node
void insertAtLast(Node **head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;

    if (*head == NULL)
    {
        // List is empty, new node becomes head
        *head = ptr;
        return;
    }

    Node *tempPtr = *head;
    while (tempPtr->next != NULL)
    {
        tempPtr = tempPtr->next;
    }

    tempPtr->next = ptr;
}

// Insert at specific index in linked list
void insertAtIndex(Node **head, int data, int index)
{
    if (index == 0)
    {
        insertAtFirst(head, data);
    }
    else
    {
        Node *ptr = (Node *)malloc(sizeof(Node *));
        ptr->data = data;

        int i = 0;
        Node *tempPtr = *head;
        while (i != index - 1 && tempPtr != NULL)
        {
            i++;
            tempPtr = tempPtr->next;
        }

        if (tempPtr == NULL)
        {
            printf("Index out of range!\n");
        }
        else
        {
            ptr->next = tempPtr->next;
            tempPtr->next = ptr;
        }
    }
}

// Function to delete first node of linkedlist
void deleteAtFirst(Node **head)
{
    Node *ptr = *head;
    if (ptr != NULL)
    {
        *head = ptr->next;
        free(ptr);
    }
}

// Function to delete last node of linkedlist
void deleteAtLast(Node **head)
{
    if (*head != NULL)
    {
        Node *ptr = *head;

        if (ptr->next == NULL)
        {
            deleteAtFirst(head);
        }
        else
        {
            Node *tempPtr = ptr->next->next;
            while (tempPtr != NULL)
            {
                tempPtr = tempPtr->next;
                ptr = ptr->next;
            }
            ptr->next = NULL;
            free(tempPtr);
        }
    }
}

// Function to delete node at given index from linkedlist
void deleteAtIndex(Node **head, int index)
{
    if (*head != NULL)
    {
        if (index == 0)
        {
            deleteAtFirst(head);
        }
        else
        {
            Node *ptr = *head;
            int i = 0;
            while (i < index - 1 && ptr != NULL)
            {
                ptr = ptr->next;
                i++;
            }

            if (ptr == NULL || ptr->next == NULL)
            {
                printf("Index out of range!\n");
            }
            else
            {
                Node* tempPtr = ptr->next;
                ptr->next = tempPtr->next;
                free(tempPtr);
            }
        }
    }
}

// Driver code
int main()
{
    Node *head = NULL;
    insertAtFirst(&head, 20);
    insertAtFirst(&head, 10);
    insertAtLast(&head, 30);
    traverseList(head);

    printf("\nInsert at 1 position\n");
    insertAtIndex(&head, 15, 1);
    traverseList(head);

    printf("\nDelete first element position\n");
    deleteAtFirst(&head);
    traverseList(head);

    printf("\nDelete last element position\n");
    deleteAtLast(&head);
    traverseList(head);

    printf("\nDelete 2 index element position\n");
    deleteAtIndex(&head, 1);
    traverseList(head);

    return 0;
}