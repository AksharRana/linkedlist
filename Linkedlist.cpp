#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next=NULL;
    node(int val){
        data=val;
    }
};
void insertatTail(node*&head,int val){
    node*n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void display(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void insertatHead(node*&head,int val){
    node*n=new node(val);
    n->next=head;
    head=n;
}
bool search(node*head,int key){
    node*temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
// DELETION AT THE HEAD
void deleteathead(node*&head){
    node*temp=head;
    head=head->next;
    delete temp;
}
// DELETION OF A NODE
void deletion(node*&head,int key){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deleteathead(head);
        return;
    }
    node*temp=head;
    while(temp->next->data!=key){
        temp=temp->next;
    }
    node*todelete=temp->next;
    temp->next=todelete->next;
    delete todelete;
}
// ITERATIVE METHOD OF REVERSING A LINKED LIST
node* reverse(node*&head){
    node*prevptr=NULL;
    node*currptr=head;
    node*nextptr;
    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }
    head=prevptr;
    return head;
}
//RECURSIVE METHOD OF REVERSING A LINKEDLIST
node*reverseRecursive(node*&head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    node*newhead=reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
node* reverseK(node*head,int k){
    node*prevptr=NULL;
    node*currptr=head;
    node*nextptr;
    int count=0;
    while(currptr!=NULL&&count<k){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    if(nextptr!=NULL){
        head->next=reverseK(nextptr,k);
    }
    return prevptr; 
}
int main(){
    node*head=NULL;
    insertatTail(head,1);
    insertatTail(head,2);
    insertatTail(head,3);
    // display(head);
    insertatTail(head,4);
    insertatTail(head,5);
    insertatTail(head,6);
    display(head);
    node*newhead=reverseK(head,2);
    display(newhead);
    // deleteathead(head);
    // deletion(head,3);
    // display(head);
    // cout<<search(head,1)<<endl;
    return 0;
}