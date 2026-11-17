#include <stdio.h>
#include<stdlib.h> 

struct Node{
    int data;
    struct Node* next;
};

void printList(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}

void addNode(struct Node** head, int data){
    struct Node* newNode =(struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = *head;
    *head = newNode;
    
}

void freeList(struct Node** head){
    struct Node* current = *head;
    struct Node* nextNode = NULL;

    while(current != NULL){
        nextNode = current -> next;
        free(current);
        current = nextNode;
    }

    *head = NULL;

}

// Reverse a linked list iteratively
// Changing its 'next' pointers and its head pointer
void reverse(struct Node** head){
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while(current != NULL){
        // Store the next node
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

int main(){
    int keys[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(keys)/sizeof(keys[0]);
 
    struct Node* head = NULL;
    for (int i = n - 1; i >=0; i--) {
        addNode(&head, keys[i]);
    }
 
    reverse(&head);
 
    printList(head);

    freeList(&head);
 
    return 0;
}