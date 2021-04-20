
#include<iostream>
using namespace std;
int main(){
    int vel=10;
    // int *p=&vel;
    // cout<<"指针与对象地址"<<endl;
    // cout<<&vel<<endl;//0x61fe1c
    // cout<<p<<endl;//0x61fe1c
    // cout<<&p<<endl;//  0x61fe10
    // cout<<*p<<endl;//10
   
    cout<<"指向指针的指针"<<endl;
    int ival=1024;
    int*pi=&ival;
    int **ppi=&pi;
    cout << "The value of ival\n"
        << "direct value: "<< ival<< "\n"
        <<"indirect value: "<< *pi << "\n"
        << "doubly indirect value: " << **ppi<< endl;
    return 0;
}
