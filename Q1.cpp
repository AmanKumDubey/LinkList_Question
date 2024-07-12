#include<bits/stdc++.h>

using namespace std;

// How to return the middle node of a LL

class Node{

    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};


Node* getMiddle(Node* &head){

    // If LL is empty

    if(head==NULL){
        cout<<"LL is Empty "<<endl;
        return head;
    }
    // If only one
    if(head->next==NULL){
            return head;
    }

    // if more than one

    Node* slow=head;
    Node* fast=head;

    while(slow!=NULL && fast!=NULL){
        fast=fast->next;

        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
    }
    return slow;

}
void print(Node* &head){

    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){

    Node* first=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(30);
    Node* forth=new Node(40);
    Node* fifth=new Node(50);


    first->next=second;
    second->next=third;
    third->next=forth;
    forth->next=fifth;
    fifth->next=NULL;

    cout<<endl;
    print(first);

    cout<<endl;
   cout<< getMiddle(first)->data<<endl;;




    return 0;
}