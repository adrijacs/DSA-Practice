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

int main(){
  Node* temp1=new Node(3);
  Node* temp2=new Node(4);
  Node* temp3=new Node(5);
  temp1->next=temp2;
  temp2->next=temp3;
  Node* temp=temp1;
  while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->next;
  }


}