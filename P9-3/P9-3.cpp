#include <iostream>
#include<ctime>
using namespace std;

void displayRuns(int values[], int size);
bool hasRun(int values[], int size);

int main() {
   
    srand(time(NULL));
    int rolls[20];
    int SIZE = 20;

    for (int i = 0; i < SIZE; ++i) {
        rolls[i] = rand() % 6 + 1;
    }

    if (hasRun(rolls, SIZE)) {
        cout << "has run: ";
        displayRuns(rolls, SIZE);
        cout << endl;
    }
    else {
        cout << "no run: ";
        displayRuns(rolls, SIZE);
        cout << endl;
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
