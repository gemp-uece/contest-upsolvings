// https://codeforces.com/gym/104059/problem/K

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int long long
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long long MOD = 1e9 + 7;

signed main() { _
    int n;int m; cin >> m;cin >> n;

    string s; cin >> s;
    char cur = 'L';
    for(int i = 0; i < s.size();i++){
        if(n == 0){
            break;
        }
        if(cur != s[i]){
            n--;
            cur = s[i];
        }
        cur = (cur == 'L' ? 'R' : 'L');
    }
    cout << n << endl;
    return 0;
}