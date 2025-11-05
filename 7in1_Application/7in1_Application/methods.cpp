#include "methods.h"
#include <iostream>
#include <string>

using namespace std;

//task1
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

//task2
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

//task3
void isCommentLine(string a){
    if(a.length() < 2) {
        cout<<"Not a comment";
        cout<<endl;
        cout<<endl;
        return;
    }

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
    else{
        cout<<"Not a comment";
        cout<<endl;
        cout<<endl;
    }
}

//task4
void isIdentifier(string a){
    if (a.length() == 0) {
        cout << "Not an Identifier" << endl;
        cout << endl;
        cout << endl;
        return;
    }

    if (!((a[0] >= 'a' && a[0] <= 'z') ||
          (a[0] >= 'A' && a[0] <= 'Z') ||
          (a[0] == '_'))) {
        cout << "Not an Identifier" << endl;
        cout << endl;
        cout << endl;
        return;
    }

    for (int i = 1; i < a.length(); i++) {
        if (!((a[i] >= 'a' && a[i] <= 'z') ||
              (a[i] >= 'A' && a[i] <= 'Z') ||
              (a[i] >= '0' && a[i] <= '9') ||
              (a[i] == '_'))) {
            cout << "Not an Identifier" << endl;
            cout << endl;
            cout << endl;
            return;
        }
    }

    cout << "an Identifier" << endl;
    cout << endl;
    cout << endl;
}

//task5
void findAverage(int arr[], int size) {
    double sum = 0;

    for (int i = 0; i < size; i++) {
        sum = sum + arr[i];
    }

    double average = sum / size;

    cout << "Average value: " << average << endl;
    cout << endl;
    cout << endl;
}

//task6
void findMinMax(int arr[], int size) {
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    cout << "Minimum value: " << min << endl;
    cout << "Maximum value: " << max << endl;
    cout << endl;
    cout << endl;
}

//task7
void findFullName(string firstName, string lastName) {
    string fullName = firstName + " " + lastName;

    cout << "output: full name = " << fullName << endl;
    cout << endl;
    cout << endl;
}
