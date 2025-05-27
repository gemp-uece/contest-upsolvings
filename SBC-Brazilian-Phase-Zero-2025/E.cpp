// problem: https://codeforces.com/gym/105925/problem/E

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
    int y,k; cin >> y >> k;
    int x = 1;
    vector<int> divisors;
    for(int i = 2; i*i <= y; i++){
        if(y % i == 0){
            divisors.push_back(i);
            divisors.push_back(y/i);
        }
    }
    divisors.push_back(y);
    sort(divisors.begin(), divisors.end());
    int actual = 1; 
    int ans = 0;
    int kcopy = k;
    for(const auto& div : divisors){
        if(div % actual == 0){
            int steps = div/actual - 1;

            if(kcopy - steps <= 0) break;
            actual = div;
            kcopy -= steps;
        }
    }
    cout << actual * (kcopy+1) << endl;
    return 0;
}
