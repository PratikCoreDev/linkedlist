#include<stdio.h>
#include<stdlib.h>

//structure of nodes

struct node{
    int data;
    struct node* next;
};

//number of element in linked list
void numberelement(struct node* head){
    struct node* ptr=head;
    int num=0;
    do{
        num++;
        ptr=ptr->next;
    }while(ptr!=head);
    printf("The number of elements in linked list is: %d \n",num);
}

//traversal
void traversalnode(struct node* head){
    struct node* ptr = head;
    do{
        printf("%d ->",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
    printf("\n");
}

int searchingunsorted(struct node* head, int value) {
    struct node*ptr=head;
    int index = 0;
    while (ptr->next != head) {
        if (ptr->data == value) {
            return index;   // return position
        }
        else{
            ptr = ptr->next;
            index++;
        }
    }
    return -1;  // value not found
}

int searchingsorted(struct node* head,int value){
    struct node* ptr=head;
    int index=0;
    while(ptr->next!=head){
        if(value>ptr->data){
            ptr=ptr->next;
            index++;
        }
        else if(value==ptr->data){
            return index;
        }
        else{
            break;
        }
    }
    return -1;
}

//insertion at beggining
struct node* insertatbegin(struct node* head,int data){
    struct node* ptr= (struct node*)malloc(sizeof(struct node));
    struct node* p=head->next;
    while(p->next!=head){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    ptr->data=data;
    head=ptr;
    return ptr;
}

//insertion at end
struct node* insertatend(struct node*head,int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* temp = head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=ptr; 
    ptr->data=data;
    ptr->next=head;

    return head;
}

//insertion after a given node
struct node* insertafternode(struct node* head,struct node* prevnode,int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->next=prevnode->next;
    prevnode->next=ptr;
    ptr->data=data;
    return head;
}

//insertion at particular index
struct node* insertatindex(struct node*head,int n,int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* temp=head;
    int i=0;
    while(i!=n-1){
        temp=temp->next;
        i++;
    }
    ptr->next=temp->next;
    temp->next=ptr;
    ptr->data=data;
    
    return head;
}

//deletion of first node
struct node* deletefirstnode(struct node* head){
    struct node* ptr=head;
    struct node*temp=ptr;
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    ptr->next=head->next;
    head=head->next;

    free(temp);
    return head;
}
//deletion at index
struct node* deletionatindex(struct node* head,int index){
    struct node* ptr=head;
    struct node* temp=head->next;
    int i=0;
    while(i!=index-1){
        temp= temp->next;
        ptr=ptr->next;
        i++;
    }
    ptr->next=temp->next;
    free(temp);
    return head;
}
//deletion last node
struct node* deletelastnode(struct node* head){
    struct node* ptr=head;
    struct node* temp=head->next;
    while(temp->next!=head){
        ptr=ptr->next;
        temp=temp->next;
    }
    ptr->next=head;
    free(temp);
    return head;
}

//delete given value
struct node* deletevalue(struct node* head,int value){
    struct node* ptr=head;
    struct node* temp=head->next;
    while(temp->data!=value && temp->next!=head){
        ptr=ptr->next;
        temp=temp->next;
    }
    if(temp->data==value){
        ptr->next=temp->next;
        free(temp);
    }
    else{
        printf("Value not found \n");
    }
    return head;
}


//main function
int main(){

    //initializing the nodes
    struct node* head;
    struct node* second;
    struct node* third;
    struct node* fourth;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));

    //first node
    head->data=10;
    head->next=second;

    //second node
    second->data = 20;
    second->next=third;

    //third node
    third->data=30;
    third->next=fourth;

    //fourth node
    fourth->data=40;
    fourth->next=head;

    //traversal perform default
    printf("Traversing default: ");
    traversalnode(head);

    //searching a data in unsorted
    int posunsorted = searchingunsorted(head, 30);

    if (posunsorted != -1) {
        printf("The value 30 is found at position %d\n", posunsorted);
    } 
    else {
        printf("Value not found\n");
    }

    //searching a data in sorted
    int possorted = searchingsorted(head, 30);

    if (possorted != -1) {
        printf("The value 30 is found at position %d\n", possorted);
    } 
    else {
        printf("Value not found\n");
    }


    //insertion at beggining
    printf("Traversing after insert at beggin: ");
    head=insertatbegin(head,5);
    traversalnode(head);

    //insertion at end
    printf("Traversing after insert at end: ");
    head=insertatend(head,50);
    head=insertatend(head,60);
    head=insertatend(head,70);
    traversalnode(head);

    //insertion after given node
    printf("Traversing after insert after given node: ");
    head=insertafternode(head,second,25);
    traversalnode(head);

    //insertion at particular index
    printf("Traversing after insert at index: ");
    head=insertatindex(head,2,15);
    traversalnode(head);

    //deletion first node
    printf("Traversing after deleting first node : ");
    head=deletefirstnode(head);
    traversalnode(head);

    //deletion at index
    printf("Traversing after deleting at index : ");
    head=deletionatindex(head,2);
    traversalnode(head);

    //deletion last node
    printf("Traversing after deleting last node : ");
    head=deletelastnode(head);
    traversalnode(head);

    //deletion a certain value
    printf("Traversing after deleting certain value : ");
    head=deletevalue(head,30);
    traversalnode(head);




    //number of elements in linked list
    numberelement(head);
    return 0;
}