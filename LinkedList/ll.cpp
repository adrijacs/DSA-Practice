#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
   int data;
   Node* next;
   Node(int data1,Node* next1){
       data=data1;
       next=next1;
   }
   Node(int data1){
    data=data1;
    next=nullptr;
   }
};

class LL{
  private:
  Node* head;
  public:
  LL(){
    head=nullptr;
  }
  void insertAtBegin(int data){
    Node* newNode=new Node(data);
    if(head==nullptr){
      head=newNode;
      return;
    }
    newNode->next=head;
    head=newNode;

  }
  void insertPos(int val,int k){
    if(head==NULL){
      if(k==1){
        Node* newNode=new Node(val);
        head=newNode;
        return;
      }
      else{
        return;
      }
    }
    if(k==1){
      insertAtBegin(val);
    }
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
      cnt++;
      if(cnt==(k-1)){
        Node* newNode=new Node(val);
        newNode->next=temp->next;
        temp->next=newNode;
        break;
      }
      temp=temp->next;
    }
  }
  void insertBeforeValue(int val,int ele){
    if(head==NULL){
      cout<<"Linked List is empty";
      return;
    }
     if(head->data==ele){
      Node* newNode=new Node(val);
      insertAtBegin(val);
      return;
    }

    Node* temp=head;
    while(temp->next!=NULL){
     
      if(temp->next->data==ele){
        Node* newNode=new Node(val);
        newNode->next=temp->next;
        temp->next=newNode;
        break;
      }
      temp=temp->next;
    }
  }
  
  void insert(int data){
    Node* newNode=new Node(data);
     if(head==nullptr){
      head=newNode;
      return;
     }
     Node* temp=head;
     while(temp->next!=NULL){
      temp=temp->next;
     }
     temp->next=newNode;
  }
  void deleteStart(){
    if(head==nullptr){
      return;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
  }
  void deleteEnd(){
    if(head==nullptr ||head->next==nullptr){
      delete head;
      head==nullptr;
      return;
    }
    Node* temp=head;
    while(temp->next->next!=nullptr){
      temp=temp->next;
    }
    Node* toDelete=temp->next;
    temp->next=nullptr;
    delete toDelete;
  }
  void deleteK(int k){
    if(head == NULL)cout<<"Linked List is empty"<<endl;
    if(k==1){
      deleteStart();
      return;
    }
    int cnt=0;
    Node* temp=head;
    Node* prev=nullptr;
    while(temp!=NULL){
      cnt++;
      if(cnt==k){
        prev->next=prev->next->next;
        delete temp;
        break;
      }
      prev=temp;
      temp=temp->next;
    }
  }
  void deleteEle(int val){
     if(head == NULL)cout<<"Linked List is empty"<<endl;
    if(head->data==val){
      deleteStart();
      return;
    }
  
    Node* temp=head;
    Node* prev=nullptr;
    while(temp!=NULL){
    
      if(temp->data==val){
        prev->next=prev->next->next;
        delete temp;
        break;
      }
      prev=temp;
      temp=temp->next;
    }

  }
  void display(){
    if(head==nullptr){
      cout<<"Linked List is empty";
      return;
    }
    Node* temp=head;
    while(temp!=NULL){
      if(temp->next==NULL){
        cout<<temp->data;
      }
      else{
        cout<<temp->data<<"->";
      }
      temp=temp->next;
    }
    cout<<endl;
  }

};

int main(){
  LL ll;
  ll.insert(4);
  ll.insert(5);
  ll.insert(6);
  ll.insert(7);
  ll.insert(8);
  ll.display();
  // ll.deleteEnd();
  // ll.display();
  // ll.deleteStart();
  // ll.display();
  // ll.deleteK(6);
  // ll.display();
  ll.deleteEle(4);
  ll.display();
  ll.insertAtBegin(2);
  ll.display();
  // ll.insertPos(99,4);
  ll.insertBeforeValue(33,2);
  ll.display();



}