#include<iostream>
using namespace std;

// K Group reverse of linked list
class Node{

    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;

    }
};

int getlength(Node* &head){

    Node* temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }

    return len;
}

Node* ReverseLL(Node* &head, int k){

    if(head==NULL){
        cout<<"Your LL is empty "<<endl;
        return NULL;
    }

    int len=getlength(head);

    // if k value is greater than LL length
    if(k>len){
        cout<<"Enter a valid Number"<<endl;
        return head;
    }

    // K is less than LL length

    // Step A: Reverse k Nodes of LL

    Node* prev=NULL;
    Node* curr=head;
    Node* forward=NULL;
    int count=0;

    while(count<k){

        forward=curr->next;
        curr->next=prev;

        prev=curr;
        curr=forward;
        count++;
    }

    // Reverse LL through recursion
        ReverseLL(forward, k);

    return prev;
}

void print(Node* &head){

    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){

    Node* head=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(30);
    Node* forth=new Node(40);
    Node* fifth=new Node(50);
    Node* sixth=new Node(60);
    Node* seventh=new Node(70);

    head->next=second;
    second->next=third;
    third->next=forth;
    forth->next=fifth;
    fifth->next=sixth;
    sixth->next=seventh;
    seventh->next=NULL;

    int k;
    cout<<"Enter the value of K : ";
    cin>>k;
    cout<<endl;
    cout<<"The LL data is: ";
    print(head);
    cout<<endl;
    ReverseLL(head,k);
    cout<<"After reverse LL: ";
    print(head);



    return 0;
}