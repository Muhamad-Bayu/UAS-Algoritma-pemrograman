#include <iostream>
#include <vector>
using namespace std;

// Fungsi Binary Search
bool binarySearch(const vector<int>& data, int target) {
    int left = 0, right = data.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (data[mid] == target) return true;
        if (data[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

// Fungsi Linear Search
bool linearSearch(const vector<int>& data, int target) {
    for (size_t i = 0; i < data.size(); i++) {
        if (data[i] == target) return true;
    }
    return false;
}

int main() {
    cout << "Nama	: Muhamad Bayu Aji" << endl;
	cout << "NIM 	: 241011403012" << endl;
	cout << "Kelas 	: 01TPLK009" << endl;
	cout << "==========================" << endl;
	
	int datasetA[] = {1, 3, 5, 7, 9, 11}; // Data terurut
    int datasetB[] = {4, 2, 8, 6, 10, 12}; // Data tidak terurut
    int target = 5;
    int sizeA = sizeof(datasetA) / sizeof(datasetA[0]);
    int sizeB = sizeof(datasetB) / sizeof(datasetB[0]);

    // Binary Search untuk Dataset A
    vector<int> vecA(datasetA, datasetA + sizeA);
    if (binarySearch(vecA, target))
        cout << "Target ditemukan di Dataset A menggunakan Binary Search.\n";
    else
        cout << "Target tidak ditemukan di Dataset A.\n";

    // Linear Search untuk Dataset B
    vector<int> vecB(datasetB, datasetB + sizeB);
    if (linearSearch(vecB, target))
        cout << "Target ditemukan di Dataset B menggunakan Linear Search.\n";
    else
        cout << "Target tidak ditemukan di Dataset B.\n";

    return 0;
}

