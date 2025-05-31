#include<iostream>
using namespace std;

void input(float resturant_record[7][4]) {

	
	for (int i = 0; i < 7; i++) {
		
		cout << "ENTER DATA FOR DAY " << i + 1 << endl << endl;

		for (int j = 0; j < 4; j++) {
			cout << "ENTER SALES FOR THE ITEM NUMBER " << j + 1 << ": ";
			cin >> resturant_record[i][j];
		}
		cout << endl;
	}

	cout << "DAY    ITEM 1    ITEM 2    ITEM 3    ITEM 4" << endl;
	for (int i = 0; i < 7; i++) {
		cout << i+1 << "         ";
		for (int j = 0; j < 4; j++) {
			cout << resturant_record[i][j] << "        ";
		}
		cout << endl;
	}
	cout << endl;
	//counting sales by item

	int sales_per_item = 0, sales_per_item_max = -999, sales_per_day = 0 , sales_per_day_max = -999;
	for (int i = 0; i < 4; i++) {
		sales_per_item = 0;
		for (int j = 0; j < 7; j++) {
			sales_per_item += resturant_record[j][i];
		}
		cout << "ITEM NUMBER " << i + 1 << " TOTAL SALES ARE: " << sales_per_item << endl;

		if (sales_per_item_max < sales_per_item) {
			sales_per_item_max = sales_per_item;
		}
	}
	for (int i = 0; i < 4; i++) {
		int checking1 = 0;
		for (int j = 0; j < 7; j++) {
			checking1 += resturant_record[j][i];
		}
		if (sales_per_item_max == checking1) {
			cout << "THE HEIGHEST SALES PER ITEM IS: " << sales_per_item_max << endl;
			break;
		}
	}

	//counting sales by day
	cout << endl;
	for (int i = 0; i < 7; i++) {
		sales_per_day = 0;
		for (int j = 0; j < 4; j++) {
			sales_per_day += resturant_record[i][j];
		}
		if (sales_per_day_max < sales_per_day) {
			sales_per_day_max = sales_per_day;
		}
		cout << "DAY " << i + 1 << " TOTAL SALES ARE: " << sales_per_day << endl;
	}
	for (int i = 0; i < 7; i++) {
		int checking2 = 0;
		for (int j = 0; j < 4; j++) {
			checking2 += resturant_record[i][j];
		}
		if (sales_per_day_max == checking2) {
			cout << "THE HEIGHEST SALES DAY WISE IS: " << sales_per_day_max << endl;
			break;
		}
	}




}

int main() {

	float resturant_record[7][4];
	input(resturant_record);

	return 0;
}