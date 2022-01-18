#include <iostream>

using namespace std;

void merge(const char s1[], const char s2[], char s3[]);

int main() {
	// step = 0 is for the first string, step = 1 is for the second string.
	int step = 0;
	int index1 = 0, index2 = 0;
	char ch;
	char s1[21] = "";
	char s2[21] = "";
	char* s3 = nullptr;

	cout << "Input the characters. (Digit is delimiter)" << endl;

	cin.get(ch);

	while (ch < '0' || ch > '9' && index1 < 20) {
		s1[index1] = ch;
		index1++;
		cin.get(ch);
	}
	s1[index1] = '\0';

	while (ch < '0' || ch > '9' && index2 < 20) {
		s2[index2] = ch;
		index2++;
		cin.get(ch);
	}
	s2[index1] = '\0';

	s3 = new char[index1 + index2 + 1];

	merge(s1, s2, s3);
	
	cout << s3;

	delete[] s3;
	return 0;
}

void merge(const char s1[], const char s2[], char s3[]) {
	if (s1[0] != '\0' && s2[0] != '\0') {
		if (s1[0] > s2[0]) {
			s3[0] = s2[0];
			merge(s1, s2 + 1, s3 + 1);
		}
		else {
			s3[0] = s1[0];
			merge(s1 + 1, s2, s3 + 1);
		}
	}
	else if (s1[0] == '\0' && s2[0] != '\0') {
		s3[0] = s2[0];
		merge(s1, s2 + 1, s3 + 1);
	}
	else if (s1[0] != '\0' && s2[0] == '\0') {
		s3[0] = s1[0];
		merge(s1 + 1, s2, s3 + 1);
	}
	else {
		s3[0] = '\0';
	}
}