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
    // Transformamos o problema em um grafo com nós 1, 2, ..., n+1.
    // Um aresta de i para i+j (1 <= j <= min(m, n-i+1)) representa:
    // comprar um CPU em mês i e revender após j meses,
    // com custo: cost[i] - revenda[i][j-1].
    //
    // Queremos encontrar o menor custo total para ir do nó 1 até o nó n+1.
    // Como os nós são processados em ordem crescente, essa estrutura é um DAG,
    // e podemos resolver com programação dinâmica.
    
    // dp[k] será o custo mínimo para atingir o nó k.
    // Nós iniciamos em dp[1] = 0 (compra do CPU no mês 1 ainda não gerou custo, 
    // a operação de compra e revenda será feita ao sair do nó).

    vector<int> dp(n+2, LINF);
    dp[1] = 0;

    for(int i = 1; i <= n; i++){
        int maxDuration = min(m, n - i + 1);
        for(int j = 1; j <= maxDuration; j++){
            int next = i + j;
            int edgeCost = cost[i] - revenda[i][j-1];
            dp[next] = min(dp[next], dp[i] + edgeCost);
        }
    }
    // dp[n+1] contém o custo mínimo total após vender o último CPU no "mês n+1"
    cout << dp[n+1] << endl;

    
    return 0;
}