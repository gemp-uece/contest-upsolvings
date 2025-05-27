// problem: https://codeforces.com/gym/105925/problem/J

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

/**
 * [4,3,1,2]
 * Estou procurando um A[j], tal que A[i] + (j-i)*k > A[j]
 * A[i] - i*k > A[j] - j*k
 * 
 * Ou seja, basta achar um A[j] < A[i]
 * 
 * */

signed main() { _
    int n,k; cin >> n >> k;
    vector<int> A(n), B(2*n),Ans(n);
    for(auto& x : A) cin >> x;
    int i = 0;
    vector<int> nextSmaller(2*n, -1);

    for(auto& x : B){
        x = A[i%n] - i * k;
        i++;
    }
    dbg(B);

    int len = B.size();
    stack<int> stk;
    // link : https://www.youtube.com/watch?v=pA9_8hZtFjk
    for(int i = 0; i < len; i++){
        while(!stk.empty() && B[i] < B[stk.top()]){
            nextSmaller[stk.top()] = (i%n) + 1;
            stk.pop();
        }
        stk.push(i);
    }
    dbg(nextSmaller);
    for(int i = 0; i < n; i++){
        cout << nextSmaller[i] << " ";
    }

    cout << endl;

    return 0;
}
