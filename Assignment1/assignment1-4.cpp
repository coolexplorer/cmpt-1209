#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_NUM_OF_SCORES = 20;

int main() {
    string stdID;
    cout << "Enter the student ID: ";
    cin >> stdID;
    int scores[MAX_NUM_OF_SCORES];
    int n;
    cout << "Enter the number of scores: ";
    cin >> n;

    for (int i=0 ; i < n ; i++) {
        cout << "Enter score " << i + 1 << ": ";
        cin >> scores[i];
    }

    ofstream file(stdID + ".txt");
    for (int i=0 ; i < n ; i++)
        file << scores[i] << '\n';

    cout << "The file was successfully created!" << endl;

    file.close();

    return 0;
}