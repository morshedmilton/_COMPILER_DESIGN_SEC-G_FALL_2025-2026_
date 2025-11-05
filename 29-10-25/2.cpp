#include<iostream>
using namespace std;

void isOperator(string a){

    int count=0;

    for(int i=0; i<a.length() ; i++){
        if(a[i] == '=' || a[i] == '+' || a[i] == '-' || a[i] == '*'|| a[i] == '/' ||a[i] == '%' || a[i] =='='){
            count++;
            cout<<"Operator "<<count<<":"<<a[i]<<endl;
        }
        else{}
    }
    cout<<"Total Operators: "<<count<<endl;
    cout<<endl;
    cout<<endl;

    if(count==0){
        cout<<"No Operator found in your text"<<endl;
        cout<<endl;
        cout<<endl;
    }



}

int main(){

    string a;

    while(true){
    cout<<"---------Operator Searcher----------"<<endl;
    cout<<"Enter Anything I will tell you the operators present in your text : ";
    cin>>a;
    isOperator(a);

    }
        return 0;
}

