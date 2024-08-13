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
   int arr[]={2,3,4,1};
   int n=sizeof(arr)/sizeof(arr[0]);
   Node* head=new Node(arr[0]);
   Node* mover=head;
   for(int i=1;i<n;i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
   }
   mover=head;
   while(mover!=NULL){
    cout<<mover->data<<"->";
    mover=mover->next;
   }


}