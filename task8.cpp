#include<iostream>
using namespace std;

void library_tracker() {
    char books[5][5];

    cout << "Enter status for each book (A = Available, I = Issued, M = Missing):" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Shelf " << i + 1 << ":" << endl;
        for (int j = 0; j < 5; j++) {
            cout << "  Book " << j + 1 << ": ";
            cin >> books[i][j];
        }
    }

    cout << endl << "Displaying Book Status:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Shelf " << i + 1 << ": ";
        for (int j = 0; j < 5; j++) {
            cout << books[i][j] << " ";
        }
        cout << endl;
    }

    int available = 0, issued = 0, missing = 0;
    int max_missing = 0;
    int missing_rows[5] = { 0 };

    for (int i = 0; i < 5; i++) {
        int row_missing = 0;
        for (int j = 0; j < 5; j++) {
            if (books[i][j] == 'A' || books[i][j] == 'a') {
                available++;
            }
            else if (books[i][j] == 'I' || books[i][j] == 'i') {
                issued++;
            }
            else if (books[i][j] == 'M' || books[i][j] == 'm') {
                missing++;
                row_missing++;
            }
        }
        missing_rows[i] = row_missing;
        if (row_missing > max_missing) {
            max_missing = row_missing;
        }
    }

    
    cout << endl<< "Total Available Books: " << available << endl;
    cout << "Total Issued Books: " << issued << endl;
    cout << "Total Missing Books: " << missing << endl;

 
    cout << endl << "Shelf(s) with Highest Missing Count (" << max_missing << "): ";
    for (int i = 0; i < 5; i++) {
        if (missing_rows[i] == max_missing) {
            cout << "Shelf " << i + 1 << " ";
        }
    }
    cout << endl << endl;
}

int main() {
    library_tracker();
    return 0;
}
