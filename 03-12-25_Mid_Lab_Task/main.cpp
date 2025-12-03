#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isKeyword(string str) {
    if (str == "int" || str == "main" || str == "if" || str == "else" ||
        str == "cout" || str == "return" || str == "using" || str == "namespace") {
        return true;
    }
    return false;
}

bool isLetter(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int main() {
    ifstream file("sample.txt");
    if (!file.is_open()) return 1;

    char ch;
    int idCount = 1;

    cout << "Character \t Type" << endl;
    cout << "--------------------------------" << endl;

    while (file.get(ch)) {
        if (ch == ' ' || ch == '\n' || ch == '\t') continue;

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^') {
            cout << ch << " \t\t Operator" << endl;
        }
        else if (ch == '=') {
            if (file.peek() == '=') {
                file.get(ch);
                cout << "== \t\t Operator" << endl;
            } else if (file.peek() == '<') {
                file.get(ch);
                cout << "=< \t\t Operator" << endl;
            } else if (file.peek() == '>') {
                file.get(ch);
                cout << "=> \t\t Operator" << endl;
            } else {
                cout << "= \t\t Operator" << endl;
            }
        }
        else if (ch == '<' || ch == '>') {
            cout << ch << " \t\t Operator" << endl;
        }
        else if (ch == ',' || ch == ';' || ch == ':' || ch == '(' || ch == ')' ||
                 ch == '{' || ch == '}' || ch == '[' || ch == ']') {
            cout << ch << " \t\t Punctuation" << endl;
        }
        else if (ch == '"') {
             cout << ch << " \t\t Punctuation" << endl;
        }
        else if (isDigit(ch)) {
            string num = "";
            num += ch;
            while (isDigit(file.peek())) {
                file.get(ch);
                num += ch;
            }
            cout << num << " \t\t Constant" << endl;
        }
        else if (isLetter(ch)) {
            string word = "";
            word += ch;
            while (isLetter(file.peek()) || isDigit(file.peek())) {
                file.get(ch);
                word += ch;
            }
            if (isKeyword(word)) {
                cout << word << " \t\t Keyword" << endl;
            } else {
                cout << word << " \t\t Identifier (id" << idCount++ << ")" << endl;
            }
        }
    }
    file.close();
    return 0;
}
