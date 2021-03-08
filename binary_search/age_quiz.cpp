#include <bits/stdc++.h>
using namespace std;

/* 年齢当てゲーム
20歳以上36歳未満の範囲内で年齢を当てる
4回まで｢Yes/No｣で答えられる質問が出来る

※4回なのは配列のサイズNに対して,
　binary_searchの最悪計算量がO( log_2(N) )なため
*/

int main () {
    cout << "Age Quiz" << endl;

    int left = 20, right = 36;

    while ( right - left > 1 ) {
        int mid = left + ( right - left ) / 2;
        cout << "Is the age less than " << mid << "? (y/n)" << endl;
        
        string ans;
        cin >> ans;

        if (ans == "y") right = mid;
        else left = mid;
    }

    cout << "The age is " << left << endl;
}