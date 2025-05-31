#include<iostream>
#include<iomanip>
using namespace std;

void product_ratings() {
    int ratings[10][5];

    for (int i = 0; i < 10; i++) {
        cout << "Enter ratings for User " << i + 1 << " (1 to 5):" << endl;
        for (int j = 0; j < 5; j++) {
            cout << "  Product " << j + 1 << ": ";
            cin >> ratings[i][j];
        }
    }

    float avg[10] = { 0 };
    int perfect[5] = { 0 };

    for (int j = 0; j < 5; j++) {
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            sum += ratings[i][j];
            if (ratings[i][j] == 5) {
                perfect[j]++;
            }
        }
        avg[j] = sum / 10.0;
    }

    cout << fixed << setprecision(2);
    cout << endl;
    cout << "Average Ratings for Each Product:" << endl;
    for (int j = 0; j < 5; j++) {
        cout << "  Product " << j + 1 << ": " << avg[j] << endl;
    }

    cout << endl;
    cout << "Number of Users Who Gave a Perfect Rating (5):" << endl;
    for (int j = 0; j < 5; j++) {
        cout << "  Product " << j + 1 << ": " << perfect[j] << " users" << endl;
    }

    float minAvg = avg[0];
    for (int j = 1; j < 5; j++) {
        if (avg[j] < minAvg) {
            minAvg = avg[j];
        }
    }

    cout << endl;
    cout << "Product(s) with the Worst Average Score (" << minAvg << "): ";
    for (int j = 0; j < 5; j++) {
        if (avg[j] == minAvg) {
            cout << "Product " << j + 1 << "  ";
        }
    }
    cout << endl;

    int count = 0;
    cout << endl;
    cout << "PERFECT RATING (5) COUNT TOTAL: ";
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            if (ratings[i][j] == 5) {
                count++;
            }
        }
    }
    cout << count << endl << endl;
}

int main() {
    product_ratings();
    return 0;
}
