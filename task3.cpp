#include<iostream>
using namespace std;

void hospital_record(char data[7][5]) {
	
	cout << "1. S FOR STABLE" << endl;
	cout << "2. C CRITICAL" << endl;
	cout << "3. R FOR RECOVERED" << endl;
	
	int catag1 = 0, catag2 = 0, catag3 = 0;
	bool check[7][5] = {0};
	
	for (int i = 0; i < 7; i++) {
	
		cout << endl <<"ENTER DATA FOR DAY " << i + 1 << endl;
		for (int j = 0; j < 5; j++) {
			cout << "ENETER CONDITION OF PATIENT NUMBER " << j + 1 << ": ";
			cin >> data[i][j];
			if (data[i][j] == 's' || data[i][j] == 'S') {
				catag1++;
			}
			else if (data[i][j] == 'c' || data[i][j] == 'C') {
				catag2++;
				check[i][j] = true;
			}
			else if (data[i][j] == 'r' || data[i][j] == 'R') {
				catag3++;
			}
			else {
				continue;
			}
		}
	}

	cout << "TOTAL CRITICAL PATIENTS ARE: " << catag1 << endl;
	cout << "TOTAL STABLE PATIENTS ARE: " << catag2 << endl;
	cout << "TOTAL RECOVERY PATIENTS ARE: " << catag3 << endl;


	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 5; j++) {
			if (check[i][j] == true) {
				cout << "CRETICAL PATIENTS FOUND IN " << i + 1 << " DAY" << endl;
				break;
			}
		}
	}

}

int main() {

	char data[7][5];

	hospital_record(data);

	return 0;
}