#include <iostream>
using namespace std;

int main() {
    string s;
    cout << "Enter input: ";
    getline(cin, s);

    if(s.length() >= 2 && s[0] == '/' && s[1] == '/') {
        cout << "Single line comment" << endl;
    }

    else if((s.length() >= 2 && s[0] == '/' && s[1] == '*') && (s.length() >= 2 && s[s.length() -2] == '*' && s[s.length() -1] == '/')) {
        cout << "multi-line comment" << endl;
    }

    else {
        cout << "Not a comment" << endl;
    }

    return 0;
}
