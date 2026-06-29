#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* prev;
    struct node* next;
};
//traversal
void traversalnode(struct node* head){
    struct node* ptr=head;
    while(ptr!=NULL){
        printf("%d <->",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

//backward traversal
void backtraversalnode(struct node* head){
    struct node* ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
        
    }
    while(ptr!=NULL){
        printf("%d ->",ptr->data);
        ptr=ptr->prev;
    }
    printf("\n");
}
//insertion at beggining
struct node* insertatbegin(struct node* head,int data){
    struct node* ptr= (struct node*)malloc(sizeof(struct node));
    ptr->next=head;
    head->prev=ptr;
    ptr->prev=NULL;
    ptr->data=data;
    head=ptr;
    return ptr;
}

//insertion at end
struct node* insertatend(struct node* head,int data){
    struct node* temp=head;
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=ptr;
    ptr->prev=temp;
    ptr->data=data;
    ptr->next=NULL;
    return head;
}

//insert at index
struct node* insertatindex(struct node* head,int index,int data){
    struct node* ptr= (struct node*)malloc(sizeof(struct node));
    struct node* temp=head;
    int i=0;
    while(i!=index-1){
        temp=temp->next;
        i++;
    }
    ptr->next=temp->next;
    temp->next=ptr;
    ptr->prev=temp;
    ptr->data=data;
    return head;
}

//insert after node
struct node* insertafternode(struct node* head,struct node* prevnode,int data){
    struct node* ptr= (struct node*)malloc(sizeof(struct node));
    ptr->prev=prevnode;
    ptr->next=prevnode->next;
    prevnode->next=ptr;
    ptr->data=data;
    return head;
}

//delete first node
struct node* deleteatfirst(struct node* head){
    struct node* ptr=head;
    head=head->next;
    head->next->prev=NULL;
    free(ptr);
    return head;
}

//delete last node
struct node* deleteatend(struct node* head){
    struct node* ptr=head;
    struct node* temp=head->next;
    while(temp->next!=NULL){
        temp=temp->next;
        ptr=ptr->next;
    }
    ptr->next=NULL;
    free(temp);
    return head;
}

//deletion at index
struct node* deleteatindex(struct node* head,int index){
    struct node* ptr =head;
    struct node* temp=head->next;
    int i=0;
    while(i<index-1){
        ptr=ptr->next;
        temp=temp->next;
        i++;
    }
    ptr->next=temp->next;
    temp->next->prev=ptr;
    free(temp);
    return head;
}

//delete particular data
struct node* deletedata(struct node* head,int value){
    struct node* ptr=head;
    struct node* temp=head->next;
    while(temp->data!=value){
        temp=temp->next;
        ptr=ptr->next;
    }
    ptr->next=temp->next;
    temp->next->prev=ptr;
    free(temp);
    return head;
}

int main(){
    // initializing node
    struct node* head;
    struct node* second;
    struct node* third;
    struct node* fourth;

    //creating node
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));

    //linking head node
    head->data=10;
    head->next=second;
    head->prev=NULL;

    //linking second node
    second->data=20;
    second->next=third;
    second->prev=head;

    //linking third node
    third->data=30;
    third->next=fourth;
    third->prev=second;

    //linking fourth node
    fourth->data=40;
    fourth->next=NULL;
    fourth->prev=third;

    //traversing
    printf("Default linked list: ");
    traversalnode(head);

    //backward traversal
    printf("Default linked list backward: ");
    backtraversalnode(head);

    //insert at begin
    printf("linked list after insert at begin: ");
    head=insertatbegin(head,5);
    traversalnode(head);

    //insert at end
    printf("linked list after insert at end: ");
    head=insertatend(head,50);
    traversalnode(head);

    //insert at index
    printf("linked list after insert at index: ");
    head=insertatindex(head,2,15);
    traversalnode(head);

    //insert after node
    printf("linked list after insert after node: ");
    head=insertafternode(head,third,35);
    traversalnode(head);

    //delete first node
    printf("linked list after delete first node: ");
    head=deleteatfirst(head);
    traversalnode(head);

    //delete last node
    printf("linked list after delete last node: ");
    head=deleteatend(head);
    traversalnode(head);

    //delete at index node
    printf("linked list after delete at index node: ");
    head=deleteatindex(head,4);
    traversalnode(head);

    //delete at data node
    printf("linked list after delete at particular data node: ");
    head=deletedata(head,15);
    traversalnode(head);
    return 0;
}