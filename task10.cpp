#include <iostream>
using namespace std;

void electionResult() {
    int votes[6][4], candidate_total[4] = { 0 }, station_total[6] = { 0 };
    for (int i = 0; i < 6; i++) {
        cout << "Enter votes for Polling Station " << i + 1 << ": " << endl;
        for (int j = 0; j < 4; j++) {
            cout << "Candidate " << j + 1 << ": ";
            cin >> votes[i][j];
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            candidate_total[j] += votes[i][j];
            station_total[i] += votes[i][j];
        }
    }
    cout << endl << "Total votes per candidate:" << endl;
    for (int j = 0; j < 4; j++)
        cout << "Candidate " << j + 1 << ": " << candidate_total[j] << endl;

    cout << endl << "Total votes per polling station:" << endl;
    for (int i = 0; i < 6; i++)
        cout << "Polling Station " << i + 1 << ": " << station_total[i] << endl;

    int max_votes = candidate_total[0];
    for (int j = 1; j < 4; j++)
        if (candidate_total[j] > max_votes)
            max_votes = candidate_total[j];

    cout << endl << "Winner(s) with " << max_votes << " votes: ";
    for (int j = 0; j < 4; j++)
        if (candidate_total[j] == max_votes)
            cout << "Candidate " << j + 1 << " ";
    cout << endl;

    bool lowTurnoutFound = false;
    for (int i = 0; i < 6; i++) {
        if (station_total[i] < 100) {
            if (!lowTurnoutFound) {
                cout << endl << "Polling stations with turnout less than 100:" << endl;
                lowTurnoutFound = true;
            }
            cout << "Polling Station " << i + 1 << " with " << station_total[i] << " votes" << endl;
        }
    }
    if (!lowTurnoutFound)
        cout << endl << "All polling stations had turnout of 100 or more." << endl;
}

int main() {
    electionResult();
    return 0;
}
