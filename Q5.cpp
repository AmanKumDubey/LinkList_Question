#include<iostream>

using namespace std;

// 0 1 2 sort in Linked List
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

Node* Sort2(Node* &head){

     if(head==NULL){
        cout<<"Your LL is empty "<<endl;
        return NULL;
    }
    if(head->next==NULL){
        return head;
    }

    Node* zerohead=new Node(-101);
    Node* zerotail=zerohead;

    Node* onehead=new Node(-101);
    Node* onetail=onehead;

    Node* twohead=new Node(-101);
    Node* twotail=twohead;

    //traverse the original LL

   

    Node* curr=head;
    while(curr!=NULL){
        if(curr->data==0){
            //take out zero wali node
            Node* temp=curr;
            curr=curr->next;
            temp->next=NULL;

            //apend the zero node in zerohead;

            zerotail->next=temp;
            zerotail=temp;
        }
        else if(curr->data==1){
            //take one wali node
            Node* temp=curr;
            curr=curr->next;
            temp->next=NULL;

            //apend the zero node in zerohead ll
            onetail->next=temp;
            onetail=temp;
        }
        else if(curr->data==2){
            Node* temp=curr;
            curr=curr->next;
            temp->next=NULL;

            //apend the zero node in zerohead

            twotail->next=temp;
            twotail=temp;

        }
    }

    // modify one
    Node* temp=onehead;
    onehead=onehead->next;
    temp->next=NULL;
    delete temp;


    //modify two wali node
    temp=twohead;
    twohead=twohead->next;
    temp->next=NULL;
    delete temp;


    //join list
    if(onehead!=NULL){
        zerotail->next=onehead;
        if(twohead!=NULL){
            onetail->next=twohead;
        }
    }
    else{
        if(twohead!=NULL){
            zerotail->next=twohead;
        }

    }
        temp=zerohead;
        zerohead=zerohead->next;
        temp->next=NULL;
        delete temp;
    

return zerohead;
    
}

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){

    Node* head=new Node(1);
    Node* first=new Node(2);
    Node* second=new Node(1);
    Node* third=new Node(0);
    Node* fourth=new Node(0);

    head->next=first;
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=NULL;

    cout<<endl;

    print(head);

    Sort2(head);
    cout<<endl<<"After sorting "<<endl;

    print(head);


    return 0;
}
