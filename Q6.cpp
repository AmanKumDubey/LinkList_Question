#include<bits/stdc++.h>
using namespace std;

// Add 2 number represented by LL

class Node{

    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

Node* reverse(Node* head){
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=curr->next;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}
Node* solve(Node* &head1, Node* &head2){

    head1=reverse(head1);
    head2=reverse(head2);


    Node* ansHead=NULL;
    Node* ansTail=NULL;

    int carry=0;
while(head1!=NULL && head2!=NULL){
    // calculation

    int sum=carry+head1->data+head2->data;
    int digit=sum%10;
    carry=sum/10;

    //create newNode for digit

    Node* newNode=new Node(digit);
    // atach the newNode into  the answer wali LL

    if(ansHead==NULL){
        // first node insert krke 
        ansHead=newNode;
        ansTail=newNode;
    }

    else{
        ansTail->next=newNode;
        ansTail=newNode;
    }
    head1=head1->next;
    head2=head2->next;
    }
    // jb head2 LL ki ength head2 list se jyada ho

    while(head1!=NULL){
            int sum=carry+head1->data;
            int digit=sum%10;
            carry=sum/10;

            Node* newNode=new Node(digit);

            ansTail->next=newNode;
            ansTail=newNode;
            head1 =head1->next;
    }
    while(head2!=NULL){
            int sum=carry+head2->data;
            int digit=sum%10;
            carry=sum/10;

            Node* newNode=new Node(digit);

            ansTail->next=newNode;
            ansTail=newNode;
            head2 =head2->next;
    }
    while(carry!=0){
        int sum=carry;
        int digit=sum%10;
        carry=sum/10;

        Node* newNode =new Node(digit);
        ansTail->next=newNode;
        ansTail=newNode;
    }
    ansHead=reverse(ansHead);

    return ansHead;
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}
int main(){

    Node* head1=new Node(2);
    Node* second1=new Node(4);
     Node* third1=new Node(9);
    head1->next=second1;
    second1->next=third1;

    Node* head2=new Node(5);
    Node* second2=new Node(6);
    Node* third2=new Node(4);
    Node* fourth2=new Node(9);


    head2->next=second2;
    second2->next=third2;
    third2->next=fourth2;
    

    print(head1);
    cout<<endl;
    print(head2);

    cout<<endl;
    Node* ans=solve(head1,head2);

    print(ans);

    return 0;
}