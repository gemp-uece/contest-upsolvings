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
    int n, m; cin >> n >> m;
    vector<int> cost(n+1); vector<vector<int>> revenda(n+1, vector<int>());
    for(int i = 1; i <= n; i++){
        cin >> cost[i];
        int len = min(m, n-i+1);
        for(int j = 0; j < len;j++){
            int aux; cin >> aux;
            revenda[i].push_back(aux);
        }
    }
    dbg(revenda);
    dbg(cost);

    vector<int> dp(n+2,LINF);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int mes = i - j + 1;
            //usar o pc do (mes) -> até -> i.
            // e revender ele ao preço de revenda em j-1. 
            if(mes <= 0) break;
            if(j > revenda[mes].size()) continue; 

            dp[i] = min(dp[i], dp[mes-1] + cost[mes] - revenda[mes][j-1]);
        }
    }
    cout << dp[n] << endl;

    
    return 0;
}