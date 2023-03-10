/*
 * 어떤 정수에 0부터 9까지 각 숫자가 몇 번씩 쓰였는지를 구하는 프로그램
 */

#include <bits/stdc++.h>

using namespace std;

    int v[10];

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int p = a * b * c;
    while (p) {
        v[p % 10]++;
        p /= 10;
    }

    for (int i: v) {
        cout << i << endl;
    }
}