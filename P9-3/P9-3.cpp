#include <iostream>
using namespace std;

void displayRuns(const int rolls[], int size);

int main() {
    int rolls[] = { 1, 1, 2, 3, 3, 3, 4, 4, 4, 4, 5, 6, 6, 6, 6, 6, 5, 5, 5, 5 };
    int SIZE = 20;

    cout << "runs: ";
    displayRuns(rolls, SIZE);
}

void displayRuns(const int rolls[], int size) {
    bool inRun = false;
    int startOfRun = 0;

    for (int i = 1; i <= size; ++i) {
        if (i == size || rolls[i] != rolls[i - 1]) {
            if (inRun) {
                cout << "(";
                for (int j = startOfRun; j < i; ++j) {
                    cout << rolls[j];
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
                cout << rolls[i - 1];
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
