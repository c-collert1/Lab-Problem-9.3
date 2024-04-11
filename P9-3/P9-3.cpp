#include <iostream>
using namespace std;

void displayRuns(int values[], int size);
bool hasRun(int values[], int size);

int main() {
    int rolls[] = { 1, 1, 2, 3, 3, 3, 4, 4, 4, 4, 5, 6, 6, 6, 6, 6, 5, 5, 5, 5 };
    int SIZE = 20;

    cout << "runs: ";
    displayRuns(rolls, SIZE);

    if (hasRun(rolls, SIZE)) {
        cout << "The array has 1 or more runs." << endl;
    }
    else {
        cout << "The array does not have a run." << endl;
    }
}

void displayRuns(int values[] , int size) {
    bool inRun = false;
    int startOfRun = 0;

    for (int i = 1; i <= size; ++i) {
        if (i == size || values[i] != values[i - 1]) {
            if (inRun) {
                cout << "(";
                for (int j = startOfRun; j < i; ++j) {
                    cout << values[j];
                    if (j != i - 1) {
                        cout << " ";
                    }
                }
                cout << ")";
                if (i != size) {
                    cout << " ";
                }
                inRun = false;
            }
            else {
                cout << values[i - 1];
                if (i != size) {
                    cout << " ";
                }
            }
        }
        else {
            if (!inRun) {
                inRun = true;
                startOfRun = i - 1;
            }
        }
    }
    cout << endl;
}

bool hasRun(int values[], int size) {
    for (int i = 1; i < size; ++i) {
        if (values[i] == values[i - 1]) {
            return true;
        }
    }
    return false;
}
