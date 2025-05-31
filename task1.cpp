#include<iostream>
using namespace std;

void input(char name[10][20], int marks[10][5]) {

	cout << "ENTER THE NAME AND MARKS OF % SUBJECT" << endl << endl << endl;

	int result[10][2], sum = 0, average, top_score = -9999;
	for (int i = 0; i < 10; i++) {

		cout << "ENTER NAME OF " << i + 1 << " STUDENT: ";
		cin.ignore();
		cin.getline(name[i], 20);
		cout << endl;

		for (int j = 0; j < 5; j++) {
			cout << "ENETER THE MARKS OF THE " << j + 1 << " SUBJECT: ";
			cin >> marks[i][j];
			sum += marks[i][j];
		}
		average = sum / 5;

		for (int j = 0; j < 5; j++) {
			if (top_score < marks[i][j]) {
				top_score = marks[i][j];
			}
		}

		result[i][0] = average;
		result[i][1] = top_score;


		cout << endl;
	}
	cout << "NAME  SUBJECT 1  SUBJECT 2  SUBJECT 3  SUBJECT 4  SUBJECT 5  AVERAGE  TOP_MARKS" << endl;

	for (int i = 0; i < 10; i++) {

		for (int j = 0; name[i][j] != '\0'; j++) {
			cout << name[i][j];
		}
		cout << "       ";
		for (int j = 0; j < 5; j++) {
			cout << marks[i][j] << "        ";
		}
		cout << result[i][0] << "        ";
		cout << result[i][1] << "        ";
		cout << endl;
	}

}

int main() {

	char name[4][20];
	int marks[4][5];
	input(name, marks);

	return 0;
}