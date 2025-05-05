#include <stdio.h>
#include <stdlib.h>

// Defining node structure for doubly linked list
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Function to traverse and print the doubly linked list
void traverseList(Node *head)
{
    Node *ptr = head;

    printf("NULL <=> ");
    while (ptr != NULL)
    {
        printf("%d <=> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// Function to insert given data into first node of doubly linked list
void insertAtFirst(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;

    if (*head != NULL){
        (*head)->prev = newNode;
    }
    
    *head = newNode;
}

// Function to insert given data into last node of doubly linked list
void insertAtLast(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
    }
    else
    {
        Node* ptr = *head;
        while (ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->prev = ptr;
    }
}

// Function to insert given data into first node of doubly linked list
void deleteAtFirst(Node **head){
    if (*head != NULL){
        Node*ptr = *head;
        if (ptr->next == NULL){
            *head = NULL;
            free(ptr);
        }
        else{
            ptr->next->prev = NULL;
            *head = ptr->next;
            free(ptr);
        }
    }
}

// Function to insert given data into last node of doubly linked list
void deleteAtLast(Node **head){
    if (*head != NULL){
        Node* ptr = *head;
        if (ptr->next == NULL){
            deleteAtFirst(head);
        }
        else{
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->prev->next = NULL;
            free(ptr);
        }
    }
}

int main()
{
    Node *head = NULL;
    insertAtFirst(&head, 10);
    insertAtFirst(&head, 20);
    insertAtFirst(&head, 30);
    // insertAtLast(&head, 30);
    // insertAtLast(&head, 20);
    // insertAtLast(&head, 10);
    traverseList(head);

    deleteAtLast(&head);
    traverseList(head);
    return 0;
}