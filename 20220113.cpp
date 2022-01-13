#include <iostream>

using namespace std;

void displayArray(int* arr, int size);
int* reallocateMemory(int* arr, int capacity);

int main() {
	int count = 0, capacity = 5;
	int* arr = new int[capacity];
	
	bool isFinished = false;

	while (!isFinished) {
		cout << "Input your positive number(0: Exit): ";

		int value = 0;
		cin >> value;

		if (value == 0) {
			break;
		}

		if (count >= capacity) {
			capacity *= 2;
			arr = reallocateMemory(arr, capacity);
		}

		arr[count] = value;
		count++;
		
	}

	cout << "Number Count: " << count << endl;
	displayArray(arr, count);

	delete[] arr;

	return 0;
}

void displayArray(int* arr, int size) {
	cout << "Array: ";
	for (int i = size - 1; i >= 0; --i) {
		cout << *(arr + i) << ' ';
	}
	cout << endl;
}

int* reallocateMemory(int* arr, int capacity) {
	int newCapacity = capacity * 2;
	int* temp = new int[newCapacity];

	for (int i = 0; i < capacity; ++i) {
		temp[i] = arr[i];
	}

	delete[] arr;
	arr = temp;
	
	return arr;
}
