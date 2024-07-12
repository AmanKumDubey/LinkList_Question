#include<iostream>

using namespace std;


// Cheak Palindrome is valid or not


class Node{

    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
// insertAtHead
void inserAtHead(Node* &head, Node* &tail, int data){

    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }

    //create a node

    Node* newNode=new Node(data);
    //initialise
    newNode->next=head;
    head=newNode;
}
// inserAttail
void insertAtTail(Node* &head, Node* &tail, int data){

    if(head==NULL){
        Node*newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }

    Node* newNode=new Node(data);
    tail->next=newNode;
    tail=newNode;
}

// Print the data
void print(Node* &head){

    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

// Find the length
int findLength(Node* &head){
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}
// Insert At Any Position

void insertAtPosition(Node* &head, Node* &tail,int data, int position){

    if(head==NULL){
        Node*newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }

    //inserAt head
    if(position==0){
        inserAtHead(head, tail,data);
    }
    //inaertAtntail
    int len=findLength(head);

    if(position>=len){
        insertAtTail(head,tail,data);
        return;
    }
    // step 1 find length

    int i=1;
    Node* prev=head;
    while(i<position){
        prev=prev->next;
        i++;
    }
    Node* curr=prev->next;
    //step 2
    Node* newNode= new Node(data);

    //step 3
    newNode->next=curr;
    //sep 3
    prev->next=newNode;

}

// reverse LL LIst

Node* reverse(Node* &head){

    Node* prev=NULL;
    Node* curr=head;
    Node* next=curr->next;

    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;

        prev=curr;
        curr=next;

    }
    return prev;
}

bool cheakPalindrome(Node* &head){

    // If Empty
    if(head==NULL){
        cout<<"LL is Empty "<<endl;
        return true;
    }
    // If only one node
    if(head->next==NULL){
        return true;
    }

    // if >1 node

    // find middle

    Node* slow=head;
    Node* fast=head->next;


    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
    }

    // reverse the Node
    Node* reverseLLkaHead=reverse(slow->next);

    slow->next=reverseLLkaHead;

    Node* temp1=head;
    Node* temp2=reverseLLkaHead;

    while(temp2!=NULL){

        if(temp1->data!=temp2->data){
            return false;
        }
        else{
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    return true;

}
int main(){

    Node* head=NULL;
    Node* tail=NULL;

    insertAtPosition(head, tail, 12,0);
    insertAtPosition(head, tail, 14,1);
    insertAtPosition(head, tail, 10,3);
    insertAtPosition(head, tail, 14,4);
    insertAtPosition(head, tail, 14,5);

    // print
    print(head);
    cout<<endl;

    bool ispalindrome= cheakPalindrome(head);

    if(ispalindrome){
        cout<<"This LL is palindrome "<<endl;
    }

    else{
        cout<<"This is not palindrome "<<endl;
    }


    return 0;
}