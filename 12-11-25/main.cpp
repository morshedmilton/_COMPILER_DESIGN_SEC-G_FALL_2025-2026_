#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void isIdentifier(string a) {
    if (a.length() == 0) {
        cout << a << ": Not an Identifier (empty)" << endl;
        return;
    }

    if (!((a[0] >= 'a' && a[0] <= 'z') ||
          (a[0] >= 'A' && a[0] <= 'Z') ||
          (a[0] == '_'))) {

        cout << a << ": Not an Identifier (invalid start)" << endl;
        return;
    }

    for (int i = 1; i < a.length(); i++) {
        if (!((a[i] >= 'a' && a[i] <= 'z') ||
              (a[i] >= 'A' && a[i] <= 'Z') ||
              (a[i] >= '0' && a[i] <= '9') ||
              (a[i] == '_'))) {

            cout << a << ": Not an Identifier (invalid character)" << endl;
            return;
        }
    }


    cout << a << ": an Identifier" << endl;
}

int main() {
    cout << "---------Identifier Identifier----------" << endl;

    ifstream inputFile;
    inputFile.open("sample.txt");

    if (!inputFile.is_open()) {
        cout << "Error! Could not open sample.txt" << endl;
        return 1;
    }

    string a;
    cout << "Reading from sample.txt..." << endl;
    while (inputFile >> a) {

        cout<<endl;
        isIdentifier(a);
        cout<<endl;
    }
    inputFile.close();
    return 0;
}
