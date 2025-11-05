#include<iostream>
using namespace std;

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

int main() {

    string a;

    while (true) {
        cout << "---------Identifier Identifier----------" << endl;
        cout << "Enter Anything I will tell your given input is Identifier or not: ";
        cin >> a;
        isIdentifier(a);
    }

    return 0;
}
