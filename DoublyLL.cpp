/* Doubly linked List Implementation*/
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};
Node* head = NULL;

Node* GetNewNode(int x){
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void InsertAtHead(int x){
    Node* newNode = GetNewNode(x);
    if(head == NULL){
        head = newNode;
        return;
    }
    head->prev = newNode; 
    newNode->next = head;
    head = newNode;

}
void InsertAtEnd(int x){
    Node* newNode = GetNewNode(x);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;


}
void Display(){
    Node* temp = head;
    cout << "Forward List is: ";
    while(temp !=NULL){
        cout << " " << temp->data;
        temp = temp->next;
    }
    cout << "\n";
}
void ReverseDisplay(){
    Node* temp = head;
    while(temp->next !=NULL){
        temp = temp->next;
    }
    cout << "Backward List is: ";
    while(temp !=NULL){
        cout << " " << temp->data;
        temp = temp->prev;
    }
    cout << "\n";
}

int main(){
    head = NULL;
    InsertAtHead(2);
    Display();
    ReverseDisplay();
    InsertAtHead(4);
    Display();
    ReverseDisplay();
    InsertAtHead(6);
    Display();
    ReverseDisplay();
    InsertAtEnd(5);
    Display();
    ReverseDisplay();
    InsertAtEnd(7);
    Display();
    ReverseDisplay();
}