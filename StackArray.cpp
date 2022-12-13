#include<iostream>
using namespace std;

struct Stack{
    int top = -1;
    int A[30];
}s;

class Stack_Array {
    public:
    int x;
    void Push(){
        if(s.top == 5){
            cout << "Stack is full";
            return;
        }
        cout << "Enter integer: ";
        cin >> x;
        s.A[++s.top] = x;
    }
    void Pop(){
        if(s.top == -1){
            cout << "List is empty" << endl;
            return;
        }
        s.top--;
    }
    void Display(){
        cout << "Stack: ";
        for (int i =0; i<= s.top; i++){
            cout << s.A[i];
        }
    }
};
int main(){
    Stack_Array a;
    s.top = -1;
    int choice;
    while (-1)
    {
        cout<<"1. Push"<<endl<<"2. Pop"<<endl<<"3. Display"<<endl<<"4. Exit"<<endl;
        cout<<"Enter Choice :";
        cin>>choice;
        switch (choice)
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