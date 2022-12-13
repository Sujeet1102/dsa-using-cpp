// Queue implementation using array
#include<iostream>
using namespace std;

class Queue_Array{
    public:
    int head = -1;
    int tail = -1;
    int A[10];

    bool IsEmpty(){
        if(head == -1 && tail == -1){
            return true;
        }
        else{
            return false;
        }
    }
    void Enqueue(){
        int x;
        cout << "Enter number to be enqueued: ";
        cin >> x;
        if(IsEmpty()){
            head = 0;
        }
        tail++;
        A[tail] = x;
    }
    void Dequeue(){
        if(IsEmpty()){
            cout << "Empty List";
            return;
        }
        else if(head == tail){
            head = tail = -1;
            return;
        }
        head = head + 1;
    }
    void Display(){
        if(IsEmpty()){
            cout << "Empty List";
            return;
        }  
        for(int i=head;i<=tail;i++){
            cout<<A[i]<<endl;
        }
    }
    int Front(){
        return head;
    }
    int Back(){
        return tail;
    }
};
int main(){

    Queue_Array b;
    int c;
    while(1)
    {
        cout<<"1.Enqueue :"<<endl<<"2.Dequeue :"<<endl<<"3.Display :"<<endl<<"4.Exit:"<<endl<<"5.Display Front:"<<endl<<"6.Display Back:"<<endl;
        cout<<"Enter your choice :";
        cin>>c;
        switch (c)
        {
            case 1:
            b.Enqueue();
            break;
            case 2:
            b.Dequeue();
            break;
            case 3:
            b.Display();
            break;
            case 4:
            b.Front();
            break;
            case 5:
            b.Back();
            break;
            case 6:
            exit(0);
            break;
        }
    }
    return 0;
}