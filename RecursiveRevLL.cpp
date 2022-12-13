// Reversing Linked list Recursion
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* head;

void Insert(int x){
    Node* temp = new Node();
    temp->data = x;
    if(head!=NULL){
        temp->next = head;
    }
    head = temp;
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
void Reverse(Node* p){
    if(p->next == NULL){
        head = p;
        return;
    }
    Reverse(p->next);
    Node* q = p->next;
    q->next = p;
    p->next = NULL;
}
int main(){
    head = NULL;
    int data, number;
    cout << "How many numbers to insert: "; //Enter num in order only
    cin >> number;
    for(int i = 0; i < number; i++){
        cout << "What number to insert in : ";
        cin >> data;
        Insert(data);
    }
    Display();
    Reverse(head);
    Display();
}