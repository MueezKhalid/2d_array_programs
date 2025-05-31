#include <iostream>
using namespace std;

void input(char name[10][20], int marks[10][5]) {
    cout << "ENTER THE NAME AND MARKS OF 5 SUBJECTS" << endl << endl;

    int result[10][2]; 
    cin.ignore(); 

    for (int i = 0; i < 10; i++) {
        int sum = 0, average, top_score = -9999;

        cout << "ENTER NAME OF STUDENT " << i + 1 << ": ";
        cin.getline(name[i], 20); 
        cout << endl;

        for (int j = 0; j < 5; j++) {
            cout << "ENTER MARKS OF SUBJECT " << j + 1 << ": ";
            cin >> marks[i][j];
            sum += marks[i][j];
            if (marks[i][j] > top_score) {
                top_score = marks[i][j];
            }
        }

        average = sum / 5;
        result[i][0] = average;
        result[i][1] = top_score;
        cout << endl;

        cin.ignore(); 
    }

    cout << "\nNAME            SUBJECT 1  SUBJECT 2  SUBJECT 3  SUBJECT 4  SUBJECT 5  AVERAGE   TOP_MARKS\n";

    for (int i = 0; i < 10; i++) {
        cout.width(15);
        cout << left << name[i];

        for (int j = 0; j < 5; j++) {
            cout.width(10);
            cout << marks[i][j];
        }
        cout.width(10);
        cout << result[i][0];
        cout.width(10);
        cout << result[i][1];
        cout << endl;
    }
}

int main() {
    char name[10][20];
    int marks[10][5];
    input(name, marks);
    return 0;
}
