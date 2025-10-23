#include <iostream>
using namespace std;

int main() {
    string s;
    cout << "Enter input: ";
    cin >> s;

    int Count = 0;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%' || s[i] == '=') {
            Count++;
            cout << "operator" << Count << ": " << s[i] << endl;
        }
    }

    if(Count == 0) {
        cout << "No operators found" << endl;
    }

    return 0;
}
