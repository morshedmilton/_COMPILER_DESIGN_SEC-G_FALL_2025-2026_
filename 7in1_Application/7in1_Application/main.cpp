#include <iostream>
#include <string>
#include "methods.h"

using namespace std;

int main() {
    int choice;

    while (true) {
        cout << "--------- 7-in-1 Application ---------" << endl;
        cout << "1. Numaric Constant Tester" << endl;
        cout << "2. Operator Searcher" << endl;
        cout << "3. Comment Line Identifier" << endl;
        cout << "4. Identifier Checker" << endl;
        cout << "5. Array Average" << endl;
        cout << "6. Array Min/Max" << endl;
        cout << "7. Full Name Concatenator" << endl;
        cout << "--------------------------------------" << endl;
        cout << "Enter your choice (1-7): ";
        cin >> choice;
        cout << endl;

        switch(choice) {
            case 1: {
                cout << "---------Numaric Constant Tester----------" << endl;
                cout << "Enter Anything: ";
                string a;
                cin >> a;
                numaric_Constant(a);
                break;
            }
            case 2: {
                cout << "---------Operator Searcher----------" << endl;
                cout << "Enter Anything: ";
                string a;
                cin >> a;
                isOperator(a);
                break;
            }
            case 3: {
                cout << "---------Comment Line Identifier----------" << endl;
                cout << "Enter Anything: ";
                string a;
                cin >> a;
                isCommentLine(a);
                break;
            }
            case 4: {
                cout << "---------Identifier Identifier----------" << endl;
                cout << "Enter Anything: ";
                string a;
                cin >> a;
                isIdentifier(a);
                break;
            }
            case 5: {
                cout << "---------Array Average Calculator----------" << endl;
                int n;
                cout << "How many numbers do you want to average? ";
                cin >> n;
                if (n <= 0) {
                    cout << "Please enter a positive number." << endl << endl;
                    break;
                }
                int numbers[n];
                cout << "Enter " << n << " numbers (separated by spaces): ";
                for (int i = 0; i < n; i++) {
                    cin >> numbers[i];
                }
                findAverage(numbers, n);
                break;
            }
            case 6: {
                cout << "---------Array Min/Max Finder----------" << endl;
                int n;
                cout << "How many numbers do you want to check? ";
                cin >> n;
                if (n <= 0) {
                    cout << "Please enter a positive number." << endl << endl;
                    break;
                }
                int numbers[n];
                cout << "Enter " << n << " numbers (separated by spaces): ";
                for (int i = 0; i < n; i++) {
                    cin >> numbers[i];
                }
                findMinMax(numbers, n);
                break;
            }
            case 7: {
                cout << "---------Full Name Concatenator----------" << endl;
                string first, last;
                cout << "Enter First name: ";
                cin >> first;
                cout << "Enter Lastname: ";
                cin >> last;
                findFullName(first, last);
                break;
            }
            default: {
                cout << "Invalid choice. Please enter a number between 1 and 7." << endl;
                cout << endl;
                cout << endl;
                break;
            }
        }
    }

    return 0;
}
