#include <bits/stdc++.h>
using namespace std;

/* ペア和のK以上の中での最小値
    N個の正整数 a_0 ~ a_N-1
    N個の正整数 b_0 ~ b_N-1
    2組の整数列からそれぞれ1個ずつ選んで和を取る
    整数K以上の範囲内でその和の最小値を求めよ

全探索ではO(N^2)だが以下の方法で考えるとO(NlogN)に落とせる
N個の正整数 b_0 ~ b_N-1 が与えられたとき，
K - a_i 以上の範囲内で最小値を求める 
*/

const int INF = 20000000;


int main () {
    int K, N;
    cout << "N:" << endl; cin >> N;
    cout << "K:" << endl; cin >> K;
    vector<int> a(N), b(N);

    for (int i=0; i<N; ++i) {
        cout << "a_" << i << " = " << endl; cin >> a[i];
        cout << "b_" << i << " = " << endl; cin >> b[i];
    }

    int min_value = INF;

    sort(b.begin(), b.end());

    for (int i = 0; i < N; ++i) {
        // aを固定すればK-aとなるbを見つければ良くなる
        // 2分探索でO(logN)にできる
        auto iter = lower_bound(b.begin(), b.end(), K-a[i]);

        int val = *iter;

        if (a[i] + val < min_value) min_value = a[i] + val;
    }

    cout << "anser" << min_value << endl;
}