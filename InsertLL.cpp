// Insertion of Linked List
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* head;

void Insert(int data, int n){
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;
    if(n == 1){
        temp1->next = head;
        head = temp1;
        return;
    }
    Node* temp2 = head;
    for(int i = 0; i < n-2; i++){
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;

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

int main(){
    head = NULL;
    int data, n, number;
    cout << "How many numbers to insert: "; //Enter num in order only
    cin >> number;
    for(int i = 0; i < number; i++){
        cout << "Which position to insert: ";
        cin >> n;
        cout << "What number to insert: ";
        cin >> data;
        Insert(data,n);
    }
    Display();
}