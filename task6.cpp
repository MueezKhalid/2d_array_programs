#include<iostream>
using namespace std;

void seat_layout(char airplane[6][4]) {

    for (int i = 0; i < 6; i++) {
        cout << "ENTER THE DATA FOR THE " << i + 1 << " ROW NUMBER" << endl << endl;
        for (int j = 0; j < 4; j++) {
            cout << "ENTER THE DATA FOR THE COLUMN NUMBER " << j + 1 << " IS: ";
            cin >> airplane[i][j];          }
    }

    cout << "\n---------------- DISPLAYING SEATS ----------------\n";
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            cout << airplane[i][j] << "  ";
        }
        cout << endl;
    }
    int row, col;
    cout << "\nENTER THE ROW NUMBER (1-6) YOU WANT TO BOOK SEAT: ";
    cin >> row;
    cout << "ENTER THE COLUMN NUMBER (1-4) YOU WANT TO BOOK SEAT: ";
    cin >> col;

    row--;
    col--;

    if (row < 0 || row >= 6 || col < 0 || col >= 4) {
        cout << "INVALID SEAT LOCATION!" << endl;
    }
    else if (airplane[row][col] == 'E' || airplane[row][col] == 'e') {
        airplane[row][col] = 'B';
        cout << "YOU HAVE SUCCESSFULLY CONFIRMED THE SEAT" << endl;
    }
    else if (airplane[row][col] == 'B' || airplane[row][col] == 'b') {
        cout << "ALREADY BOOKED" << endl;
    }

    int total_seats = 0, max_empty = -1, max_row = -1;

    for (int i = 0; i < 6; i++) {
        int row_seats = 0;
        for (int j = 0; j < 4; j++) {
            if (airplane[i][j] == 'E' || airplane[i][j] == 'e') {
                total_seats++;
                row_seats++;
            }
        }
        if (row_seats > max_empty) {
            max_empty = row_seats;
            max_row = i;
        }
    }

    cout << "\nTOTAL SEATS AVAILABLE IN AIRPLANE ARE: " << total_seats << endl;

    if (max_row != -1) {
        cout << "HIGHEST EMPTY SEATS ARE IN ROW: " << max_row + 1
            << " WITH " << max_empty << " SEATS." << endl;
    }
}

int main() {
    char airplane[6][4];
    seat_layout(airplane);
    return 0;
}
