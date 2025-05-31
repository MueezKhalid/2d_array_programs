#include<iostream>
using namespace std;

void weather_temp(float weather[5][5]) {

	float average, sum = 0;
	float result[5][3], max = -999, min = 999;

	for (int i = 0; i < 5; i++) {
		
		float max = -999, min = 999;
		
		cout << endl << "ENTER TEMP IN ROW " << i + 1 << endl;
		for (int j = 0; j < 5; j++) {
			cout << "ENTER TEMPERATURE : ";
			cin >> weather[i][j];
			sum += weather[i][j];

			if (max < weather[i][j]) {
				max = weather[i][j];
			}
			if (min > weather[i][j]) {
				min = weather[i][j];
			}
		}
		average = sum / 5;

		result[i][0] = average;
		result[i][1] = max;
		result[i][2] = min;
	}
	cout << "DAY  TEMP1  TEMP2  TEMP3  TEMP4  TEMP5  AVG    MAX    MIN" << endl;
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << "      ";
		for (int j = 0; j < 5; j++) {
			cout << weather[i][j] << "      ";

		}
		cout << result[i][0] << "      ";
		cout << result[i][1] << "      ";
		cout << result[i][2] << "      " << endl;
	
	}
}

int main() {

	float weather[5][5];
	weather_temp(weather);

	return 0;
}