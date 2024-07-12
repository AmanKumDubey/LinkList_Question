#include<iostream>

using namespace std;

// Detect and Delete Loop
// Find starting loop
// delete loop

class Node{

    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

// cheak loop
bool CheakLoop(Node* &head){

        if(head==NULL){
            cout<<"The LL is Empty "<<endl;
            return false;
        }

        Node* slow=head;
        Node* fast=head;

        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }

            if(slow==fast){
                return true;
            }

        }
        return false;

}
// find starting loop

Node* FindLoop(Node* &head){

        if(head==NULL){
            cout<<"The LL is Empty "<<endl;
            return NULL;
        }

        Node* slow=head;
        Node* fast=head;

        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }

            if(slow==fast){
                break;
            }
        }
        
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
}

// remove loop
Node* RemoveLoop(Node* &head){

    if(head==NULL){
        cout<<"The LL is Empty "<<endl;
        return NULL;
    }

    Node* slow=head;
    Node*fast=head;

    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }

        if(slow==fast){
                break;
            }
    }

    Node* prev=fast;
    while(slow!=fast){
        prev=fast;
        slow=slow->next;
        fast=fast->next;
    }
    prev->next=NULL;

    return slow;

}
// Print
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
    Node* forth=new  Node(40);
    Node* fifth=new Node(50);
    Node* sixth=new Node(60);
    

    head->next=second;
    second->next=third;
    third->next=forth;
    forth->next=fifth;
    fifth->next=sixth;
    sixth->next=NULL;


    cout<<"The LL data is: "<<endl;
    print(head);
    cout<<endl;
    cout<<"The LL has loop: "<<CheakLoop(head)<<endl;

   cout<<"The starting loop is: " <<FindLoop(head)->data<<endl;

   RemoveLoop(head);
   cout<<"The LL data is: ";
    print(head);
    cout<<endl;
   cout<<"The LL has loop: "<<CheakLoop(head)<<endl;

    return 0;
}