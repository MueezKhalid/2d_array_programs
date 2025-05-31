#include<iostream>
using namespace std;

void record(int team[6][4]) {
    int result[6];
    bool failed_teams[6][4] = {}; 

    for (int i = 0; i < 6; i++) {
        int total_scores = 0;
        cout << endl << "ENTER DATA FOR TEAM NUMBER " << i + 1 << endl << endl;
        for (int j = 0; j < 4; j++) {
            cout << "ENTER POINTS OF ROUND NUMBER " << j + 1 << ": ";
            cin >> team[i][j];
            total_scores += team[i][j];
            if (team[i][j] <= 10) {
                failed_teams[i][j] = true;
            }
        }
        result[i] = total_scores;
    }

    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (result[i] < result[j]) {
                int temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
        }
    }


    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (failed_teams[i][j]) {
                cout << "TEAM NUMBER " << i + 1 << " FAILED TO MAKE MORE THAN 10 IN ROUND " << j + 1 << endl;
            }
        }
    }

    for (int i = 0; i < 6; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += team[i][j];
        }
        if (sum == result[0]) {
            cout << "TEAM NUMBER " << i + 1 << " WINS WITH HIGHEST SCORE" << endl;
        }
        else if (sum == result[1]) {
            cout << "TEAM NUMBER " << i + 1 << " WINS SECOND HIGHEST SCORE" << endl;
        }
    }
}

int main() {
    int team[6][4];
    record(team);
    return 0;
}
