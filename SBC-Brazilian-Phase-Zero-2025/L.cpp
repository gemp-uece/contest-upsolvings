// problem: https://codeforces.com/gym/105925/problem/L

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x;
    cin >> x;
    long long ans = log2(8 * x * pow(10, 6)) + 1;
    cout << ans << endl;
}
