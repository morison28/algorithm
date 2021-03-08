#include <bits/stdc++.h>
using namespace std;

/*
N個の風船はそれぞれ高度H_i, 1秒ごとの上昇速度S_iを持っている
競技開始時に1個風船を割ることができ，そこから1秒ごとに1個の風船を割ることが出来る
最終的に風船を全て割りたい
風船を割るときには高度分のペナルティを受ける
最終的なペナルティは，各風船を割った時に得られるペナルティの最大値とする
最終的なペナルティの最小値を求めよ
*/

const long long INF = 1LL << 60; // 大きな数字に設定しておく

int main () {
    // 入力
    int N; cin >> N;
    vector<long long> h(N), s(N);
    for (int i=0; i<N; ++i) cin >> h[i] >> s[i];

    // 二分探索
    long long left = 0, right = INF;

    while ( right - left > 1 ) {
        long long mid = (left + right) / 2;

        cout << "mid:" << mid << endl;

        // 判定
        bool ok = true;
        vector<long long> t(N, 0); // 各風船を割るまでの制限時間
        for (int i = 0; i<N; ++i) {
            // そもそもmidが初期高度より低かったらfalse
            if ( mid < h[i] ) ok = false;
            else t[i] = (mid - h[i]) / s[i];
        }

        // 時間制限が差し迫っている順にソート
        sort(t.begin(), t.end());
        for (int i = 0; i<N; ++i) {
            if (t[i] < i) ok = false; // 時間切れ発生
        }

        if (ok) right = mid;
        else left = mid;
    }

    cout << right << endl;
}