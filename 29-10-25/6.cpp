#include<iostream>
using namespace std;

void findMinMax(int arr[], int size) {

    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (min > arr[i]) {
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

int main() {

    while (true) {
        cout << "---------Array Min/Max Finder----------" << endl;

        int n;
        cout << "How many numbers do you want to check? ";
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

        findMinMax(numbers, n);
    }

    return 0;
}
