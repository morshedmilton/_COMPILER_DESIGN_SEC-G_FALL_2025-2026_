#include<iostream>
using namespace std;

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

int main() {

    while (true) {
        cout << "---------Array Average Calculator----------" << endl;

        int n;
        cout << "How many numbers do you want to average? ";
        cin >> n;

        if (n <= 0) {
            cout << "Please enter a positive number." << endl;
            cout << endl;
            continue;
        }

        int numbers[n];

        cout << "Enter " << n << " numbers (separated by spaces): ";
        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
        }

        findAverage(numbers, n);
    }

    return 0;
}
