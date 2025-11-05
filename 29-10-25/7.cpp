#include<iostream>
using namespace std;
#include<string>

void findFullName(string firstName, string lastName) {

    string fullName = firstName + " " + lastName;

    cout << "output: full name = " << fullName << endl;
    cout << endl;
    cout << endl;
}

int main() {

    string first;
    string last;

    while (true) {
        cout << "---------Full Name Concatenator----------" << endl;

        cout << "Enter First name: ";
        cin >> first;

        cout << "Enter Lastname: ";
        cin >> last;

        findFullName(first, last);
    }

    return 0;
}
