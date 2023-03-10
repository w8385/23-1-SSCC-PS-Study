/*
 * 야찌를 구현하는 문제
 */

#include <bits/stdc++.h>

using namespace std;

int dice[7];

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < 3; i++) {
        int d;
        cin >> d;
        dice[d]++;
    }

    int res = 0;
    for (int i = 0; i < 6; i++) {
        if (s[i] == 'Y') {
            res = max(res, (i + 1) * (dice[i + 1] + 2));
        }
    }
    if (s[6] == 'Y') {
        for (int i = 1; i < 7; i++) {
            if (1 < dice[i]) {
                res = max(res, 4 * i);
            }
        }
    }
    if (s[7] == 'Y') {
        for (int i = 1; i < 6; i++) {
            if (3 == dice[i]) {
                res = max(res, 12 + 3 * i);
            } else if (2 == dice[i]) {
                for (int j = 1; j < 7; j++) {
                    if (1 == dice[j]) {
                        res = max(res, max(2 * i + 3 * j, 2 * j + 3 * i));
                    }
                }
            }
        }
        if (3 == dice[6]) {
            res = max(res, 28);
        } else if (2 == dice[6]) {
            for (int i = 1; i < 6; i++) {
                if (1 == dice[i]) {
                    res = max(res, 18 + 2 * i);
                }
            }
        }
    }
    if (s[8] == 'Y') {
        if (dice[6] == 0) {
            bool little = true;
            for (int i = 1; i < 6; i++) {
                if (1 < dice[i]) {
                    little = false;
                    break;
                }
            }
            if (little) {
                res = max(res, 30);
            }
        }
    }
    if (s[9] == 'Y') {
        if (dice[1] == 0) {
            bool big = true;
            for (int i = 2; i < 7; i++) {
                if (1 < dice[i]) {
                    big = false;
                    break;
                }
            }
            if (big) {
                res = max(res, 30);
            }
        }
    }
    if (s[10] == 'Y') {
        for (int i = 1; i < 7; i++) {
            if (3 == dice[i]) {
                res = max(res, 50);
            }
        }
    }
    if (s[11] == 'Y') {
        int cur = 12;
        for (int i = 1; i < 7; i++) {
            cur += i * dice[i];
        }
        res = max(res, cur);
    }
    cout << res;
}