// Implementation of List data structure and its operations

#include <stdio.h>

// Defining list data structure
typedef struct {
    int count;          // Count property to handle counter of the List
    int data[100];      // Data array to story data of the List
} List;

// Prototyping different list operations
void createList(List* l);
void insertElement(List* l, int position, int element);
void deleteElement(List*l, int position);
void printList(List*l);

// Creating function to create list
void createList(List*l){
    // Initializing iterative variable i,
    // zero variable to check is 0 or not,
    // element variable to store temporary input value from list
    int i = 0, zero = 0, element;

    // Run loop until user input 0
    while (!zero){
        // Take list values as input from user
        printf("Enter any value and 0 to exit input: ");
        scanf("%d", &element);
        
        // Check if element is 0 zero or not and if 0 then make zero true
        if (element == 0){
            zero = 1;
        }
        else{
            // Otherwise put user input element into ith value of list data
            l->data[i] = element;

            // Increment the iterator i value by 1
            i++;
        }
    }

    // Assign the value of list count equal to number values inputed by user
    l->count = i;
}

// Creating function to insert element at given position in the list data
void insertElement(List* l, int position, int element){
    // Creating temp variable and initializing its value by total filled indices in list data
    int temp = l->count - 1;

    // Run loop until value of temp is less than or equal to value of index where we intent to insert new element
    while (temp >= position - 1){
        // Update the (i+1)th value with ith value of list data
        l->data[temp+1] = l->data[temp];

        // Decreate the temp value by 1
        temp--;
    }

    // Insert the new element into position index of list data
    l->data[position - 1] = element;

    // Increase the list count by 1
    l->count++;
}

// Creating function to delete element from given position in the list data
void deleteElement(List* l, int position){
    // Run loop from position index to second last value of list data
    for (int i = position - 1; i < l->count - 1; i++){
        // Update the ith value with (i+1)th value of list data
        l->data[i] = l->data[i+1];
    }

    // Decrease the list count by 1
    l->count--;
}

// Creating function to print the list data
void printList(List *l){
    // Run loop from 1st element to last element of list data
    for (int i = 0; i < l->count; i++){
        // Print list data into single row
        printf("%d ", l->data[i]);
    }

    // Print new line
    printf("\n");
}

// Driver function
int main(){
    // Declaring list
    List list;

    // Invoking every functions one by 0
    createList(&list);
    insertElement(&list, 2, 3);
    deleteElement(&list, 3);
    printList(&list);

    
    return 0;
}