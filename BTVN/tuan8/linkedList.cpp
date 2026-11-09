#include<stdlib.h>
#include<stdio.h>

// Setting the linked lists to store integers
struct Node {
    int data;
    Node* next;
};

void initList1(Node*& head){
    head = NULL;
}

// Add a new node to the beginning of the list
void insertBegin1(Node*& head, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = head;
    head = newNode;
}

void initList2(Node**head){
    *head = NULL;
}

// Add a new node to the beginning of the list
void insertBegin2(Node** head, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = *head;
    *head = newNode;
}
void insertEnd(Node** head, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = NULL;

    if(*head == NULL){
        *head = newNode;
        return;
    }
    else{
        Node* ptr = *head;
        while(ptr -> next != NULL){
            ptr = ptr -> next;
        }
        ptr -> next = newNode;
    }
}

// Adding a new value after a specific node
void insertAfter(Node** p, int value){
    if(*p == NULL){
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = (*p) -> next;
    (*p) -> next = newNode;

}

// O(n)
void insertBefore(Node** head, Node* p, int value){
    if(p == NULL){
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = value;
    Node* ptr = *head;
    if(p == *head){
        newNode -> next = p;
        *head = newNode;
        return;
    }
    while(ptr -> next != p){
        ptr = ptr -> next;
    }
    newNode -> next = ptr -> next;
    ptr -> next = newNode;
}

// O(1)
void insertBefore2(Node** head, Node* p, int value){
    if(p == NULL)
        return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = p -> data;
    p -> data = value;
    newNode -> next = p -> next;
    p -> next = newNode;
}

// Delete the first node of the list
void deleteBegin(Node** head){
    if(*head == NULL){
        return;
    }

    Node* ptr = *head;
    if(ptr -> next == NULL){
        free(ptr);
        *head = NULL;
        return;
    }

    while(ptr -> next -> next != NULL){
        ptr = ptr -> next;
    }
    Node* ptr2 = ptr -> next;
    free(ptr2);
    ptr -> next = NULL;
}

// Find the node with a specific value in the list
Node* searchNode(Node* head, int value){
    while(head == NULL){
        if(head -> data == value){
            return head;
        }
        head = head -> next;
    }
    return NULL;
}

Node* initList3(Node* head){
    head = NULL;
    return head;
}

// Add a new node to the beginning of the list
Node* insertBegin3(Node* head, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = head;
    head = newNode;
    return head;
}

void hienThi(Node* head){
    if(head == NULL){
        printf("\nList is empty");
    }
    else{
        printf("\nList: ");

        while(head != NULL){
            printf("%d ", head -> data);
            head = head -> next;
        }
    }
}

int main(){
    Node* list = NULL;
    initList1(list);
    insertBegin1(list, 1);
    insertBegin1(list, 2);
    insertBegin1(list, 3);
    insertBegin1(list, 4);
    insertBegin1(list, 5);
    hienThi(list);
    insertEnd(&list, 6);
    hienThi(list);
    //bo sung 7 vao sau 3
    Node* p = searchNode(list, 3);
    insertAfter(&p, 7);
    hienThi(list);
    //bo sung 9 vao truoc 5
    p = searchNode(list, 5);
    insertBefore(&list, p, 9);
    hienThi(list);
 
  /*
  Node* list = NULL;
  initList2(&list);
  insertBegin2(&list, 1);
  insertBegin2(&list, 2);
  insertBegin2(&list, 3);
  insertBegin2(&list, 4);
  insertBegin2(&list, 5);
  hienThi(list);

  Node* list = initList3(list);
  list = insertBegin3(list, 1);
  list = insertBegin3(list, 2);
  list = insertBegin3(list, 3);
  list = insertBegin3(list, 4);
  list = insertBegin3(list, 5);
  hienThi(list);
  */
 
 
}
