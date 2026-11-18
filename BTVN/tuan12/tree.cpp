#include<iostream>

struct Node{
    int data;
    Node* lp;
    Node* rp;
};

Node* newNode(int value){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp -> data = value;
    temp -> lp = NULL;
    temp -> rp = NULL;
    return temp;
}

void insertBT(Node** root, int* arr, int n, int index){
    if(index < n){
        *root = newNode(arr[index]);
        insertBT(&(*root) -> lp, arr, n, 2*index + 1);
        insertBT(&(*root) -> rp, arr, n, 2*index + 2);
    }
}

void hienThi_postOrder(Node* root){
    if(root == NULL) return;
    hienThi_postOrder(root -> lp);
    hienThi_postOrder(root -> rp);
    printf("%d ", root -> data);
}

void hienThi_inOrder(Node* root){
    if(root == NULL) return;
    hienThi_inOrder(root -> lp);
    printf("%d ", root -> data);
    hienThi_inOrder(root -> rp);
}

void hienThi_preOrder(Node* root){
    if(root == NULL) return;
    printf("%d ", root -> data);
    hienThi_preOrder(root -> lp);
    hienThi_preOrder(root -> rp);
}

void freeTree(Node** root){
    if(*root == NULL) return;
    freeTree(&(*root) -> lp);
    freeTree(&(*root) -> rp);
    free(*root);
    *root = NULL;
}

int calSum(Node* root){
    if(root == NULL) return 0;
    return root -> data + calSum(root -> lp) + calSum(root -> rp);
}

int calHeight(Node* root){
    if(root == NULL) return 0;
    int LH = calHeight(root -> lp);
    int RH = calHeight(root -> rp);
    return 1 + (LH >= RH ? LH : RH);
}

int main(){
    int arr[7] = {11, 23, 18, 2, 4, 7, 9};
    Node* bt = NULL;
    insertBT(&bt, arr, 7, 0);

    printf("Pre-order: ");
    hienThi_preOrder(bt);
    printf("\n");

    printf("In-order: ");
    hienThi_inOrder(bt);
    printf("\n");

    printf("Post-order: ");
    hienThi_postOrder(bt);
    printf("\n");

    printf("Sum: %d\n", calSum(bt));
    printf("Height: %d\n", calHeight(bt));

    freeTree(&bt);
}