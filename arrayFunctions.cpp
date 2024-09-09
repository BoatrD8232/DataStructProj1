#include "arrayFunctions.h"

int findIndex(int data[], int size) {
	int target;
	string input;
	cout << "Enter the integer to be found: " << endl;
	cin >> input;
	target = stoi(input);
	for (int i = 0; i < size; i++) {
		if (target == data[i]) {
			cout << "The item is at index " << i << endl;
			return i;
		}
	}
	cout << "The item could not be found" << endl;
	return -1;
}

int modVal(int data[], int index, int newVal, int size) {
	cout << "Old value: " << data[index] << endl;
	int oldVal = data[index];
	data[index] = newVal;
	cout << "New value: " << data[index] << endl;
	return oldVal;
}

void addInt(int data[], int newVal, int& size, int cap) {
	if (size < cap) {
		data[size] = newVal;
		size++;
	}
	else {
		throw length_error("full array");
	}
}

void removeInt(int data[], int index, int& size) {
	cout << "Removed " << data[index] << " at index " << index << endl;
	for (int i = index; i < size - 1; i++) {
		data[i] = data[i + 1];
	}
	size--;
}

void printArray(int data[], int size) {
	for (int i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

char printMenu() {
	char choice = '0';
	while (choice < 'a' || choice > 'f') {
		cout << "Select an option: " << endl;
		cout << "a) Find a value and return the index" << endl;
		cout << "b) Modify the value at a certain index" << endl;
		cout << "c) Add an integer to the end of the array" << endl;
		cout << "d) Remove an integer at a certain index" << endl;
		cout << "e) Print the current array" << endl;
		cout << "f) Exit the function" << endl;
		cin >> choice;
		choice = tolower(choice);
		if (choice < 'a' || choice > 'f') {
			cout << "Invalid choice" << endl;
		}
	}
	return choice;
}
