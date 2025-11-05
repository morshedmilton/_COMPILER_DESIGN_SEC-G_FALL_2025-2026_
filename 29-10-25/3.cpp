#include<iostream>
using namespace std;

void isCommentLine(string a){
        if(a[0]=='/' && a[1]=='/'){
           cout<<"Single Line Comment"<<endl;
           cout<<endl;
           cout<<endl;
           }
           else if(a[0]=='/' && a[1]=='*' && a[a.length()-2]=='*' && a[a.length()-1]=='/'){
            cout<<"Multi Line Comment"<<endl;
            cout<<endl;
            cout<<endl;
           }

           else{cout<<"Not a comment";
            cout<<endl;
            cout<<endl;
           }

}

int main(){

    string a;

    while(true){
    cout<<"---------Comment Line Identifier----------"<<endl;
    cout<<"Enter Anything I will tell your given input is Comment or Not : ";
    cin>>a;
    isCommentLine(a);

    }
        return 0;
}
