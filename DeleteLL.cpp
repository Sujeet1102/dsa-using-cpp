/* Deletion of Linked List Implementation */
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
void Delete(int n){
    Node* temp1 = head;
    if(n == 0 && n<0){
        cout << "Invalid number";
        return;
    }
    if(n == 1){
        head = temp1->next;
        delete temp1;
        return;
    }
    for(int i = 0; i < n-2; i++){
        temp1 = temp1->next;
    }
    Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    delete temp2;
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
    Insert(0);
    Insert(1);
    Insert(2);
    Insert(3);
    Display();
    int n = 0;
    cout << "Enter Node number to delete: ";
    cin >> n;
    Delete(n);
    Display();
}