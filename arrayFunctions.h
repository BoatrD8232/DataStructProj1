#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

/*
findIndex- finds the index of a user chosen integer.
param data- the current array of integers.
param size- The current number of valid integers in the array.
return- the index of the value or -1 if not found.
*/
int findIndex(int data[], int size);

/*
modVal- replaces a value at a user given index with a user given integer.
param data- the current array of integers.
param index - the index of the value to be modified.
param newVal- the new value to replace the old value with.
param size- The current number of valid integers in the array.
return- the old value.
*/
int modVal(int data[], int index, int newVal, int size);

/*
addInt- adds an integer to the end of the array.
param data- the current array of integers.
param newVal- the new value to place at the end.
param size- The current number of valid integers in the array.
param cap- the total capacity of the array.
*/
void addInt(int data[], int newVal, int& size, int cap);

/*
removeInt- removes the integer at a user given index.
param data- the current array of integers.
param index- the index to be removed.
param size- The current number of valid integers in the array.
*/
void removeInt(int data[], int index, int& size);

/*
printArray- prints the current array.
param data- the current array of integers.
param size- The current number of valid integers in the array.
*/
void printArray(int data[], int size);

/*
printMenu- prints the choices to the user.
returns - the user's choice as a char.
*/
char printMenu();
