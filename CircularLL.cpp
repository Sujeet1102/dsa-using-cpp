// Circular Linked List
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* head = NULL;
Node* GetNewNode(int x){
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
void InsertAtHead(int x){
    Node* n = GetNewNode(x);
    Node* temp = head;
    if(head == NULL){
        n->next = n;
        head = n;
        return;
    }
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void InsertAtTail(int x){
    if(head == NULL){
        InsertAtHead(x);
        return;
    }
    Node* n = GetNewNode(x);
    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}
void Display(){
    Node* temp = head;
    do{
        cout << temp->data<<" ";
        temp = temp->next;
    }while(temp != head);
    cout << endl;
}
void DeleteAtEnd(){
    Node* temp = head;
    while(temp->next->next != head){
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = head;
    delete toDelete;
}
void DeleteAtStart(){
    Node* temp1 = head;
    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = head->next;
    head = head->next;
    delete temp1;
}

int main(){
    head = NULL;
    InsertAtHead(1);
    InsertAtTail(2);
    InsertAtTail(3);
    InsertAtTail(4);
    Display();
    DeleteAtStart();
    Display();
    DeleteAtEnd();
    Display();
}