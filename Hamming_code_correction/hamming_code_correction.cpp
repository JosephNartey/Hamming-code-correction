// Joseph Nartey Opey
// implementation of hamming code detection and corrention for 8  bits. 
#include<iostream>
using namespace std;

int main() {
	int Rec_data[10], c, c1, c2, c3, i;

	cout << "\n\nEnter received data bits one by one\n";
	for (i = 0; i<7; i++)
		cin >> Rec_data[i];

	c1 = Rec_data[6] ^ Rec_data[4] ^ Rec_data[2] ^ Rec_data[0];
	c2 = Rec_data[5] ^ Rec_data[4] ^ Rec_data[1] ^ Rec_data[0];
	c3 = Rec_data[3] ^ Rec_data[2] ^ Rec_data[1] ^ Rec_data[0];
	c = c3 * 4 + c2 * 2 + c1;

	if (c == 0) {
		cout << "\nNo error while transmission of data\n";
	}
	else {
		cout << "\nError on position " << c;

		cout << "\nData sent : ";
		for (i = 0; i<7; i++)
			cout << Rec_data[i];

		cout << "\nData received : ";
		for (i = 0; i<7; i++)
			cout << Rec_data[i];

		cout << "\nCorrect message is\n";

		//if errorneous bit is 0 we complement it else vice versa
		if (Rec_data[7 - c] == 0)
			Rec_data[7 - c] = 1;
		else
			Rec_data[7 - c] = 0;
		for (i = 0; i<7; i++) {
			cout << Rec_data[i];
		}
	}
	return 0;
}