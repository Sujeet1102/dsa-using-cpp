#include<iostream>
using namespace std;

struct Node{
    char rowNo, book;
    int seatNo, pin;
    Node* prev;
    Node* next;
};

class System{
    public:
    Node* head;
    System(){
        head = NULL;
    }
    public: 
    void Create(){
        Node *cn, *nn;
        volatile int k = 2;
        int j = 1;
        char c = 'A';
        do{
            int i = 1;
            do{
                k=(k*k)/10+100-k/2;
                nn = new Node();
                nn->next = nn->prev =NULL;
                nn->rowNo = c;
                nn->book = 'a';
                nn->seatNo = i;
                nn->pin = k;

                if(head == NULL){
                    head = nn;
                    nn->prev = nn->next = head;
                }
                else{
                    cn = head;
                    while(cn->next != head){
                        cn = cn->next;
                    }
                    nn->prev = cn;
                    cn->next = nn;
                    nn->next = head;
                    head->prev = nn;
                    
                }
                i++;
            }while(i <= 7);
        j++;
        c++;
        }while(j <= 10);
    }
    void Display(){
        Node* cn = head;
        cout<<"------------------------------------------------------------------\n";
		cout<<"|                            Platinum                            |\n";
        while(cn->next != head){

            if((cn->prev)->rowNo != cn->rowNo){
                cout<<"| ";
            }

			cout<<cn->rowNo;
			cout<<cn->seatNo;

            if(cn->book=='a'){
                cout << " -> a  ";
            }
            else{
                cout << " -> b  ";
            }
            
            if((cn->next)->rowNo != cn->rowNo){
                cout<<"|\n";
            }
            if(cn->rowNo == 'C' && cn->seatNo == 7){
                cout<<"------------------------------------------------------------------\n";
				cout<<"|                             Gold                               |\n";
            }
            if(cn->rowNo == 'H' && cn->seatNo == 7){
                cout<<"------------------------------------------------------------------\n";
				cout<<"|                            Silver                              |\n";
            }
            cn = cn->next;
        }
        cout<<cn->rowNo;
		cout<<cn->seatNo;
		if(cn->book == 'a'){
            cout << " -> a  "; 
        }
		else{
            cout << " -> b  ";  
    
        }
        cout<<"|\n"; 
		cout<<"------------------------------------------------------------------\n\n";
        cout<<"                          SCREEN THIS WAY                         \n\n";
		cout<<"PLATINUM-> 150              GOLD-> 100                  SILVER->60\n";
    }
    
    void Display1(Node* temp[20], int n){
        if(n!=1)
		{
			cout<<"------------------------------------------------------------------\n";
			cout<<"THANK YOU!\nYOU HAVE SUCCESFULLY BOOKED THE SEATS\n";
			for(int i=1;i<n;i++){
                cout<<temp[i]->rowNo<<temp[i]->seatNo<<"    PIN : "<<temp[i]->pin<<"\n";
            }
			cout<<"!!!!!!!!!!!!!!!!!!KEEP PIN SAFELY!!!!!!!!!!!!!!!!!!!\n";
			cout<<"PINS ARE REQUIRED AT THE TIME OF CANCELATION OF SEATS\n";
			cout<<"------------------------------------------------------------------\n";
		}

    }
    void bookSeat(){
        Node *cn, *BookedSeats[20];
        int n, z, flag, seat;
        char row, ch;
        do{
            z = 1;
            cout<<"\nEnter No Of Tickets You Want To Buy: ";
            cin >> n;

            cout << "\nEnter the seat numbers: \n";

            for(int i=1; i<=n; i++){
                cout<<"NO "<<i<<" = ";
                cin>>row>>seat;

                cn = head;

                if(row >= 'A' && row <= 'E'){

                    while(cn->next != head){
                        if(cn->rowNo == row && cn->seatNo == seat){
                            if(cn->book == 'a'){
                                cn->book = 'b';
                                BookedSeats[z] = cn;
                                z++;
                            }
                            else{
                                cout<<"Invalid!";
                                cout<<cn->rowNo<<cn->seatNo<<" Seat is alredy reserved \n";
                            }
                        }
                        cn = cn->next;
                    }
                    if(cn->rowNo==row && cn->seatNo==seat){
                        if(cn->book=='a')
                        {
                            cn->book='b';
                            BookedSeats[z]=cn;
                            z++;
                        }
                        else
                        {
                            cout<<"INVALID CHOISE!\n";
                            cout<<cn->rowNo<<cn->seatNo<<" Seat is alredy reserved\n";
                        }
                    }
                }
                if(row>= 'F' && row<= 'J'){
                    while(cn->prev != head){
                        if(cn->rowNo == row && cn->seatNo == seat){
                            if(cn->book == 'a'){
                                cn->book = 'b';
                                BookedSeats[z] = cn;
                                z++;
                            }
                            else{
                                cout<<"Invalid!";
                                cout<<cn->rowNo<<cn->seatNo<<" Seat is alredy reserved \n";
                            }
                        }
                        cn = cn->prev;
                    }
                    /*if(cn->rowNo==row && cn->seatNo==seat){
                        if(cn->book=='a')
                        {
                            cn->book='b';
                            BookedSeats[z]=cn;
                            z++;
                        }
                        else
                        {
                            cout<<"INVALID CHOISE!\n";
                            cout<<cn->rowNo<<cn->seatNo<<" Seat is alredy reserved\n";
                        }
                    } */
                }
                
            }
            Display1(BookedSeats,z);
			cout<<"\n\nPRESS 1 To Check Seat Status\n";
			cout<<"PRESS 2 To book other seat\n";
			cout<<"PRESS 3 To Exit BOOKING PORTAL\n";
			cout<<"\nINPUT: ";
			cin>>ch;
			if(ch==1)
			Display();

        }while(ch == 2);

    }
    void Cancel(){
        Node* cn;
        int seat, pin, ch;
        char row;
        cout<<"SEAT CANCELLATION\n";
        do{
            cn = head;
            cout << "Seat Number: ";
            cin>>row>>seat;
            cout << "PIN: ";
            cin >> pin;
            if(row >= 'A' && row <= 'E'){
                while(cn->next != head){

                    if(cn->rowNo == row && cn->seatNo == seat && cn->pin == pin){
                        cout<<"Are you sure u want to cancle the Seat (y/n) ";
						char c;
						cin>>c;
						if(c=='y'||c=='Y')
						{
							cout<<"SEAT CANCELED SUCCESFULLY!\n";
							cn->book='a';
						}
                    }
                    else if(cn->rowNo == row && cn->seatNo == seat && cn->pin != pin){
                        cout << "Invalid SEAT NUMBER && PIN combination!!!!\n";
                    }
                    cn = cn->next;
                }
                if(cn->rowNo == row && cn->seatNo == seat && cn->pin == pin){
                    cout<<"Are you sure u want to cancle the Seat (y/n) ";
						char c;
						cin>>c;
						if(c=='y'||c=='Y')
						{
							cout<<"SEAT CANCELED SUCCESFULLY!\n";
							cn->book='a';
						}
                }
                else if(cn->rowNo == row && cn->seatNo == seat && cn->pin != pin){
                        cout << "Invalid SEAT NUMBER && PIN combination!!!!\n";
                }
            }
            if(row >= 'F' && row <= 'J'){

                while(cn->prev != head){
                    if(cn->rowNo == row && cn->seatNo == seat && cn->pin == pin){
                        cout<<"Are you sure u want to cancle the Seat (y/n) ";
						char c;
						cin>>c;
						if(c=='y'||c=='Y')
						{
							cout<<"SEAT CANCELED SUCCESFULLY!\n";
							cn->book='a';
						}
                    }
                    else if(cn->rowNo == row && cn->seatNo == seat && cn->pin != pin){
                        cout << "Invalid SEAT NUMBER && PIN combination!!!!\n";
                    }
                    cn = cn->prev;
                }
                if(cn->rowNo == row && cn->seatNo == seat && cn->pin == pin){
                    cout<<"Are you sure u want to cancle the Seat (y/n) ";
						char c;
						cin>>c;
						if(c=='y'||c=='Y')
						{
							cout<<"SEAT CANCELED SUCCESFULLY!\n";
							cn->book='a';
						}
                }
                else if(cn->rowNo == row && cn->seatNo == seat && cn->pin != pin){
                        cout << "Invalid SEAT NUMBER && PIN combination!!!!\n";
                }
            }
            cout<<"\n\nPRESS 1 To Check Seat Status\n"; 
			cout<<"PRESS 2 To Cancle More Tickets\n";
			cout<<"PRESS 3 To Exit CANCELATION PORTAL\n";
			cout<<"\ninput: ";
			cin>>ch;
			if(ch==1){
			    Display();
            }

        }while(ch == 2);

    }
};
int main(){
    System a;
    int ch;
    int c;
    cout<<"\n\n\n";
	cout<<"                 Welcome To VIIT Cinema\n";
	cout<<"                     Seating Arrangement\n\n";
    a.Create();
    a.Display();
    do{
        cout<<"\n\n\n";
		cout<<"PRESS 1-> BOOK TICKETS\n";
		cout<<"PRESS 2-> CANCEL TICKETS\n";
		cout<<"PRESS 3-> EXIT\n";
		cout<<"\nINPUT: ";
		cin>>ch;
        switch(ch){
            case 1:
            a.bookSeat();
            a.Display();
            break;
            case 2:
            a.Cancel();
            a.Display();
            break;
        }
        if(ch != 3){
            cout<<"\n\nPRESS 1 To Main Menu\n";
			cout<<"PRESS 2 To Exit CINEMA PORTAL\n";
			cout<<"\nINPUT: ";
			cin>>c;
        }
    } while(c == 1);
    cout<<"\n\n\n";
    return 0;
}