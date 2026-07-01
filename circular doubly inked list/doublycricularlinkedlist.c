#include<stdio.h>
#include<stdlib.h>

// Structure of Doubly Circular Linked List
struct node{
    int data;
    struct node *prev;
    struct node *next;
};

// Traversal
void traversal(struct node *head){
    if(head==NULL){
        printf("List is Empty\n");
        return;
    }

    struct node *ptr=head;

    do{
        printf("%d <-> ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);

    printf("(HEAD)\n");
}

// Count number of nodes
void countNode(struct node *head){
    if(head==NULL){
        printf("Number of Nodes = 0\n");
        return;
    }

    int count=0;
    struct node *ptr=head;

    do{
        count++;
        ptr=ptr->next;
    }while(ptr!=head);

    printf("Number of Nodes = %d\n",count);
}

// Insert at Beginning
struct node* insertBegin(struct node *head,int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));

    newnode->data=data;

    if(head==NULL){
        newnode->next=newnode;
        newnode->prev=newnode;
        return newnode;
    }

    struct node *last=head->prev;

    newnode->next=head;
    newnode->prev=last;

    last->next=newnode;
    head->prev=newnode;

    head=newnode;

    return head;
}

// Insert at End
struct node* insertEnd(struct node *head,int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));

    newnode->data=data;

    if(head==NULL){
        newnode->next=newnode;
        newnode->prev=newnode;
        return newnode;
    }

    struct node *last=head->prev;

    newnode->next=head;
    newnode->prev=last;

    last->next=newnode;
    head->prev=newnode;

    return head;
}

// Delete First Node
struct node* deleteFirst(struct node *head){
    if(head==NULL)
        return NULL;

    if(head->next==head){
        free(head);
        return NULL;
    }

    struct node *last=head->prev;
    struct node *temp=head;

    head=head->next;

    last->next=head;
    head->prev=last;

    free(temp);

    return head;
}

// Delete Last Node
struct node* deleteLast(struct node *head){
    if(head==NULL)
        return NULL;

    if(head->next==head){
        free(head);
        return NULL;
    }

    struct node *last=head->prev;
    struct node *secondLast=last->prev;

    secondLast->next=head;
    head->prev=secondLast;

    free(last);

    return head;
}

int main(){

    // Creating 4 nodes
    struct node *head,*second,*third,*fourth;

    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    fourth=(struct node*)malloc(sizeof(struct node));

    // Data
    head->data=10;
    second->data=20;
    third->data=30;
    fourth->data=40;

    // Linking
    head->next=second;
    head->prev=fourth;

    second->next=third;
    second->prev=head;

    third->next=fourth;
    third->prev=second;

    fourth->next=head;
    fourth->prev=third;

    printf("Original List:\n");
    traversal(head);

    printf("\nAfter Insert at Beginning:\n");
    head=insertBegin(head,5);
    traversal(head);

    printf("\nAfter Insert at End:\n");
    head=insertEnd(head,50);
    traversal(head);

    printf("\nAfter Delete First:\n");
    head=deleteFirst(head);
    traversal(head);

    printf("\nAfter Delete Last:\n");
    head=deleteLast(head);
    traversal(head);

    printf("\n");
    countNode(head);

    return 0;
}