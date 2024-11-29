#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}Node;

typedef struct{
    int size;
    Node *head;
    Node *tail;
}DoubleLinkedList;
void displayNode(Node *node);


void initDoubleLinkedList(DoubleLinkedList *l){
    l->size=0;
    l->head = NULL;
    l->tail = NULL;
}

void insertFirst(DoubleLinkedList *l, int data){
    Node *newHead = (Node *)malloc(sizeof(Node));

    newHead->data = data;
    newHead -> next = NULL;
    newHead -> prev = NULL;

    if(newHead==NULL){
        perror("Faild to allocate space for newHead");
        return;
    }
    if(l->head==NULL)
        l->head = newHead;
    else{
        newHead->next = l->head;
        l->head -> prev = newHead;
        l->head = newHead;
    }
    if(l->tail==NULL){
        l->tail = newHead;
        l->tail->next = NULL;
    }
    l->size++;
    return;
}

void insertLast(DoubleLinkedList *l, int data){
    Node *newTail = (Node*)malloc(sizeof(Node));
    if(newTail==NULL){
        perror("Faild to allocate space");
    }
    newTail->data = data;
    newTail->next = NULL;
    newTail -> prev = NULL;
    if(l->head == NULL){
        l->head = newTail;
        l->head->next = NULL;
    }
    if(l->tail==NULL){
        l->tail = newTail;

    }
    else{
        l->tail->next = newTail;
        newTail ->prev = l->tail;
        l->tail = newTail;
    }
    return;
}

void deleteNode(Node *node, int delete, DoubleLinkedList *l){
    if(node==NULL)
        return;
    Node *next = node->next;
    if(node->data == delete){
        if(node->prev) node->prev->next = node->next;
        else l->head = node->next;
        if(node->next) node ->next ->prev = node->prev;
        else{ l->tail = node->prev; node->prev->next =NULL;}
        free(node);
    }
    deleteNode(next,delete,l);
}

void deleteFromList(DoubleLinkedList *l, int dataToDelete){
    deleteNode(l->head, dataToDelete,l);
}
void display(DoubleLinkedList *l){
    displayNode(l->head);
}
void displayNode(Node *node){
    if(node==NULL){
        printf(" end");
        return;
    }
    printf(" %d ->",node->data);
    displayNode(node->next);
}

int main(void){
    DoubleLinkedList *l = (DoubleLinkedList *)malloc(sizeof(DoubleLinkedList));
    initDoubleLinkedList(l);
    insertFirst(l, 12);
    insertFirst(l, 11);
    insertFirst(l, 14);
    display(l);
    printf("\n");
    insertLast(l,23);
    insertLast(l,22);
    insertLast(l,25);
    insertLast(l,26);
    insertLast(l,26);
    insertLast(l,26);
    insertLast(l,230);
    display(l);
    printf("\n");

    deleteFromList(l,230);
    display(l);
    printf(" head is: %d and tail is: %d", l->head->data, l->tail->data);
}