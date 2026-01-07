#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;

  cout << "DFA for RE = (ba)* b* a [a+ba(a+b)]*" << endl;
  cout << "Enter string: ";
  cin >> input;

  int state = 0;

  for (int i = 0; i < input.length(); i++) {
    char c = input[i];

    if (c != 'a' && c != 'b') {
      state = 5;
      break;
    }

    if (state == 0) {
      if (c == 'a')
        state = 2;
      else
        state = 1;
    } else if (state == 1) {
      if (c == 'a')
        state = 2;
      else
        state = 1;
    } else if (state == 2) {
      if (c == 'a')
        state = 2;
      else
        state = 3;
    } else if (state == 3) {
      if (c == 'a')
        state = 4;
      else
        state = 5;
    } else if (state == 4) {
      if (c == 'a' || c == 'b')
        state = 2;
    } else {
      state = 5;
    }
  }

  cout << endl;
  if (state == 2) {
    cout << "DFA ACCEPTED" << endl;
  } else {
    cout << "DFA REJECTED" << endl;
  }

  return 0;
}