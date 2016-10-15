#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

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
