// Linked List Simple
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

void Insert(int x){
    Node* temp = new Node();
    temp->data = x;
    if(head!=NULL){
        temp->next = head;
    }
    head = temp;
}
void Print(){
    Node* temp = head;
    cout << "List is: ";
    if (head == NULL)
    {
        cout<<"linked list is empty :";
    }
    while(temp !=NULL){
        cout << " " << temp->data;
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    int n, x;
    head = NULL;
    cout << "How many numbers: ";
    cin >> n;
    for(int i=0; i<n; i++){
        cout << "Enter number: \n";
        cin >> x;
        Insert(x);
        Print();
    }
        
}