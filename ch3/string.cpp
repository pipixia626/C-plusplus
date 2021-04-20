#include<string>
#include<iostream>
#include<cctype>
using namespace std;
int main(){
   //初始化
    string s1;
    string s2(s1);
    string s3("value");
    string s4="valuse";
    string s5(20,'c');
    
   
    while(getline(cin,s1)){
        if(s1=="q")break;
        cout<<s1<<endl;
    }
    char s='a';
    isalnum(s);//是字母或者数字时为真
    isalpha(s);//是否为字母
    isdigit(s);//数字
    islower(s);//小写
    isupper(s);//大写
    ispunct(s);//标点符合
    
    
}
