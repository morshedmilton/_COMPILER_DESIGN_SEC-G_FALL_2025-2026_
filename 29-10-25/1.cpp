#include<iostream>
using namespace std;

void numaric_Constant(string a){
    bool isNumaric=true;

    for(int i=0; i<a.length() ; i++){
        if(!(a[i] >= '0' && a[i]<= '9')){
                isNumaric=false;
        }
}
     if(isNumaric){
        cout<<"Numaric Constant"<<endl;
        cout<<endl;
        cout<<endl;
     }
     else{cout<<"Not Numaric Constant"<<endl;
        cout<<endl;
        cout<<endl;
     }
}

int main(){

    string a;

    while(true){
    cout<<"---------Numaric Constant Tester----------"<<endl;
    cout<<"Enter Anything I will tell your given input Numaric Constant or Not : ";
    cin>>a;
    numaric_Constant(a);

    }
        return 0;
}
