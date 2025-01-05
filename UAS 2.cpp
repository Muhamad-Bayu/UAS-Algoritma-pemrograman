#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

// Fungsi Merge
void merge(vector<tuple<int, string, string, int>>& data, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<tuple<int, string, string, int>> L(n1);
    vector<tuple<int, string, string, int>> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = data[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = data[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (get<3>(L[i]) <= get<3>(R[j])) {
            data[k] = L[i];
            i++;
        } else {
            data[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        data[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        data[k] = R[j];
        j++;
        k++;
    }
}

// Fungsi Merge Sort
void mergeSort(vector<tuple<int, string, string, int>>& data, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(data, left, mid);
        mergeSort(data, mid + 1, right);
        merge(data, left, mid, right);
    }
}

int main() {
    cout << "Nama	: Muhamad Bayu Aji" << endl;
	cout << "NIM 	: 241011403012" << endl;
	cout << "Kelas 	: 01TPLK009" << endl;
	cout << "==========================" << endl;
	
	vector<tuple<int, string, string, int>> orders;

    orders.push_back(make_tuple(1, "Lokasi A", "Tujuan A", 5));
    orders.push_back(make_tuple(2, "Lokasi B", "Tujuan B", 3));
    orders.push_back(make_tuple(3, "Lokasi C", "Tujuan C", 8));
    orders.push_back(make_tuple(4, "Lokasi D", "Tujuan D", 2));

    mergeSort(orders, 0, orders.size() - 1);

    cout << "Data setelah sorting berdasarkan waktu pengiriman:\n";
    for (size_t i = 0; i < orders.size(); i++) {
        cout << "ID: " << get<0>(orders[i])
             << ", Lokasi Pengambilan: " << get<1>(orders[i])
             << ", Lokasi Tujuan: " << get<2>(orders[i])
             << ", Waktu: " << get<3>(orders[i]) << endl;
    }

    return 0;
}

