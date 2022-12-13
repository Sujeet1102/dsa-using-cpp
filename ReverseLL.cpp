// Reverse Linked List Incursively and Print Recursion
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head = NULL;

void Insert(int data){
    Node* temp = new Node();
    temp->data = data;
    if(head!=NULL){
        temp->next = head;
    }
    head = temp;
}

void Reverse(){
    Node *prev, *current, *next;
    prev = NULL;
    current = head;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
void Display(){
    Node* temp = head;
    cout << "List is: ";
    while(temp !=NULL){
        cout << " " << temp->data;
        temp = temp->next;
    }
    cout << "\n";
}

void Print(Node* p){
    //Recursion
    if(p == NULL){
        return;
    }
    cout << " " << p->data;
    Print(p->next);
}
void ReversePrint(Node* p){
    //Recursion
    if(p == NULL){
        return;
    }
    Print(p->next);
    cout << " " << p->data;
}


int main(){
    head = NULL;
    Insert(0);
    Insert(1);
    Insert(2);
    Insert(3); 
     Display(); 
     Reverse();
     Display();
//    Print(head);
//    cout << endl;
//    ReversePrint(head);
}