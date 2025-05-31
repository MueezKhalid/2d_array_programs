#include<iostream>
#include<iomanip>
using namespace std;

void factory_quality() {
    float defects[3][7];

    for (int i = 0; i < 3; i++) {
        cout << "Enter defect percentages for Shift " << i + 1 << " (7 days):" << endl;
        for (int j = 0; j < 7; j++) {
            cout << "  Day " << j + 1 << ": ";
            cin >> defects[i][j];
        }
    }

    float shift_avg[3] = { 0 };
    float day_avg[7] = { 0 };

    for (int i = 0; i < 3; i++) {
        float sum = 0;
        for (int j = 0; j < 7; j++) {
            sum += defects[i][j];
            day_avg[j] += defects[i][j];
        }
        shift_avg[i] = sum / 7.0;
    }

    for (int j = 0; j < 7; j++) {
        day_avg[j] /= 3.0;
    }

    cout << fixed << setprecision(2) << endl;

    cout << "Average Defect Percentage Per Shift:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "  Shift " << i + 1 << ": " << shift_avg[i] << "%" << endl;
    }

    cout << endl << "Average Defect Percentage Per Day:" << endl;
    for (int j = 0; j < 7; j++) {
        cout << "  Day " << j + 1 << ": " << day_avg[j] << "%" << endl;
    }

    cout << endl << "Critical Shifts (Average Defects > 10%): ";
    bool found = false;
    for (int i = 0; i < 3; i++) {
        if (shift_avg[i] > 10.0) {
            cout << "Shift " << i + 1 << " ";
            found = true;
        }
    }
    if (!found) {
        cout << "None";
    }

    cout << endl << endl;
}

int main() {
    factory_quality();
    return 0;
}
