#include<iostream>
using namespace std;
bool Greater(int a, int b){
    if(a < b){
        return true;
    }
    else {
        return false;
    }
}
int main(){
    cout << Greater(6,4);
}