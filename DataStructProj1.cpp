/*
Data Structures Assignment 1
author- David Boatright
*/
#include "arrayFunctions.h"

int main()
{
    // The total capacity of the array.
    const int cap = 150;
    // size- the current number of managed items in the array.
    // index- stores an index when reading from the file or when runnning a function.
    // tempInt- stores an int for use with the functions.
    int size = 0, index = 0, tempInt;
    // The array of integers
    int data[cap];
    // Controls which function is run or if the program terminates.
    char choice = '0';
    // All but inp are used in the reading from file section.
    // inp- stores user input, for conversion.
    string line, subline, inp, num;
    // Opens the file, breaks it into lines, further breaks it into integers, puts it into data.
    ifstream myfile("A1input.txt");
    while (getline(myfile, line)) {
        stringstream subline(line);
        while (getline(subline, num, ' ')) {
            data[index] = stoi(num);
            size++;
            index++;
        }
    }
    myfile.close();
    // This loop controls if the program runs multiple times.
    while (choice != 'f') {
        choice = printMenu();
        // This switch handles which function will be run. Most of the exception handling happens in the switch.
        switch (choice) {
            case 'a':
                try {
                    findIndex(data, size);
                }
                catch (invalid_argument) {
                    cout << "Please enter a number" << endl;
                }
                break;
            case 'b':
                try {
                    cout << "Enter the index of the integer to be modified: " << endl;
                    cin >> inp;
                    index = stoi(inp);
                    if (index < 0 || index >= size) {
                        throw std::out_of_range("The index is out of range.");
                    }
                    cout << "Enter the new value to be used: " << endl;
                    cin >> inp;
                    tempInt = stoi(inp);
                    modVal(data, index, tempInt, size);
                }
                catch (out_of_range) {
                    cout << "Not a valid index, cannot modify value" << endl;
                }
                catch (invalid_argument) {
                    cout << "Not a vaild integer, cannot modify value" << endl;
                }
                break;
            case 'c':
                try {
                    cout << "Enter the number to be added: " << endl;
                    cin >> inp;
                    tempInt = stoi(inp);
                    addInt(data, tempInt, size, cap);
                }
                catch (length_error) {
                    cout << "The array cannot accept any more values" << endl;
                }
                catch (invalid_argument) {
                    cout << "Not a vaild integer, cannot add value" << endl;
                }
                break;
            case 'd':
                try {
                    cout << "Enter the index of the integer to be removed: " << endl;
                    cin >> inp;
                    index = stoi(inp);
                    if (index < 0 || index >= size) {
                        throw std::out_of_range("The index is out of range.");
                    }
                    if (size == 0) {
                        throw length_error("Array is empty");
                    }
                    removeInt(data, index, size);
                }
                catch (length_error) {
                    cout << "The array is empty, nothing can be removed." << endl;
                }
                catch (invalid_argument) {
                    cout << "Please enter a number" << endl;
                }
                catch (out_of_range) {
                    cout << "Not a valid index, cannot remove" << endl;
                }
                break;
            case 'e':
                printArray(data, size);
                break;
        }
    }
}



