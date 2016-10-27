#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

/* This program takes in numbers from the user, puts them into a vector, prints out the vector,
sorts the numbers from lowest to highest, and then prints out the sorted vector. */

// This method prompts the user for numbers, which are put into a stringstream. 
// The unsorted vector is then printed out.
void readData(vector<int>& v) {
	
	string userIn;
	cout << "Enter numbers separated by spaces: ";
	getline(cin, userIn);
	int numbers;
	stringstream ss(userIn);

	if(isalpha(ss.peek())) {
		cout << "Enter numbers only";
	}
	
	while (!ss.eof()) {
		ss >> numbers;
		v.push_back(numbers);
	}
	
	cout << endl;
	cout << "Unsorted Vector:" << endl;
	for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void selectionSort(vector<int>& v) {
	
	int i, j;
    int minNumber;
    int minIndex;
    int temp;
    
    for (i = 0; i < v.size()-1 ; i++) {
        minNumber = v[i];
        minIndex = i;
        for (j = i; j < v.size(); j++) {
            if (minNumber>v[j]) {
                minNumber = v[j];
                minIndex = j;
            }
        }
        temp = v[i];
        v[i] = v[minIndex];
        v[minIndex] = temp;
    }
}

void printVector(vector<int>& v) {

	cout << endl;
	cout << "Sorted Vector:" << endl;
	for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
	
	vector<int> myVector;
	
	readData(myVector);
	
	selectionSort(myVector);
	
	printVector(myVector);
	
	return 0;
}
