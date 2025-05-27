// problem: https://codeforces.com/gym/105925/problem/F

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int long long
typedef long long ll;
#ifdef DEBUG
    #define dbg(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
    #define dbg(x)
#endif

void _print(long long x) { cerr << x; }
void _print(string x) { cerr << '"' << x << '"'; }
void _print(char x) { cerr << '\'' << x << '\''; }
void _print(bool x) { cerr << (x ? "true" : "false"); }

template<typename T, typename V> void _print(pair<T, V> p) { cerr << "{"; _print(p.first); cerr << ", "; _print(p.second); cerr << "}"; }
template<typename T> void _print(vector<T> v) { cerr << "["; for (auto &i : v) { _print(i); cerr << ", "; } cerr << "]"; }
template<typename T> void _print(set<T> s) { cerr << "{"; for (auto &i : s) { _print(i); cerr << ", "; } cerr << "}"; }
template<typename T, typename V> void _print(map<T, V> m) { cerr << "{"; for (auto &i : m) { _print(i); cerr << ", "; } cerr << "}"; }


const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long long MOD = 1e9 + 7;


signed main() { _
    int n, q; cin >> n;
    vector<int> A(n);
    for(auto &x: A) cin>> x;

    const int OFFSET = 10;
    const int MAXS = 80;
    static int dp[5][MAXS+1];
    memset(dp,0,sizeof(dp));

    dp[0][OFFSET] = 1;

    for(int i = 0; i < n; i++){
        int v = A[i];
        for(int k = 4; k >= 1; k--){
            if(v >= 0){
                for(int s = MAXS; s >= v; s--){
                    dp[k][s] += dp[k-1][s-v];
                }
            } else {
                for(int s = 0; s <= MAXS + v; s++){
                    dp[k][s] += dp[k-1][s-v];
                }
            }
        }
    }

    cin >> q;
    while(q--){
        int x; cin >> x;
        cout << dp[4][x + OFFSET] << endl;
    }

    return 0;
}
