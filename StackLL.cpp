#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
class Stack_LL{
    public:
    int x;
    Node* head = NULL;
    void Push(){
        cout << "Enter number: ";
        cin >> x;
        Node* temp = new Node();
        temp->data = x;
        temp->next = head;
        head = temp;
    }
    void Pop(){
        if(head == NULL){
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
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
};
int main(){
    Stack_LL a;
    int Choice;
    while(-1){
        cout<<"1. Push"<<endl<<"2. Pop"<<endl<<"3. Display"<<endl<<"4. Exit"<<endl;
        cout<<"Enter Choice :";
        cin>>Choice;
        switch (Choice)
        {
            case 1:
            a.Push();
            break;
            case 2:
            a.Pop();
            break;
            case 3:
            a.Display();
            break;
            default:
            exit(0);
            break;
        }
    }
}
