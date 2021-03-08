#include <bits/stdc++.h>
using namespace std;

int binary_search(int key, vector<int> a) {
    /*
    Args:
      key: 目的のデータ
      a  : 探索対象の配列
    Returns:
      目的のデータのインデックス
      見つからないときは-1
    */
    int left = 0, right = a.size()-1;
    while( right >= left ) {
        int mid = left + (right - left) / 2;
        if (a[mid] == key) return mid;
        else if (a[mid] > key) right = mid - 1;
        else if (a[mid] < key) left = mid + 1;
    }
    return -1;
}

int main () {
    // Input
    int N;
    cout << "array size: "; cin >> N;
    vector<int> a(N);
    for (int i=0; i<N; ++i) {
        cout<<"a["<<i<<"]: ";
        cin >> a[i];
    }

    int target;
    string ans;

    while (true) {
        cout << "target: ";
        cin >> target;
        if (binary_search(target, a) == -1) cout << "not exist" << endl;
        else cout << "find, index is " << binary_search(target, a) << endl;

        cout << "continue?(y/n)";
        cin >> ans;
        if (ans == "n") break;
    }

    cout << "bye" << endl;
}