/*
 * 6과 9가 혼용이 가능한 숫자 세트의 최솟값
 */

#include <bits/stdc++.h>

using namespace std;

int s[9];

int main() {
    int n;
    cin >> n;

    while (n) {
        if (n % 10 == 9) s[6]++;
        else s[n % 10]++;
        n /= 10;
    }

    s[6] = (s[6] + 1) / 2;
    cout << *max_element(s, s + 9) << endl;
}