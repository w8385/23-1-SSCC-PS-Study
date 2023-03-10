/*
 * 세가지 조건을 분기하여 상금을 계산하는 문제
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a == b && b == c) {
        cout << 10000 + a * 1000;
    } else if (a == b || b == c || a == c) {
        cout << 1000 + (a == b ? a : c) * 100;
    } else {
        cout << max({a, b, c}) * 100;
    }
}