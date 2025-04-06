// https://codeforces.com/gym/104059/problem/C

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
    int n, q; cin >> n >> q;
    set<int> streets;
    while(q--){
        char op; cin >> op;
        if(op == '-'){
            int x; cin >> x;
            streets.insert(x);
        }
        if(op == '+'){
            int x; cin >> x;
            streets.erase(x);
        }
        if(op == '?'){
            int u, v; cin >> u >> v;
            if(u > v) swap(u,v);

            if(streets.find(u) != streets.end() || streets.find(v) != streets.end()){
                cout << "impossible" << endl;
                continue;
            }
            streets.insert(u);
            streets.insert(v);

            auto posu = streets.find(u);
            auto posv = streets.find(v);
            auto nxt = next(posu);

            if(u == *streets.begin() && v == *streets.rbegin()){
                cout << "possible" << endl;
                streets.erase(u);
                streets.erase(v);
                continue;
            }
            if(*nxt == v){
                cout << "possible" << endl;
                streets.erase(u);
                streets.erase(v);
                continue;
            }
            streets.erase(u);
            streets.erase(v);
            cout << "impossible" << endl;
        }
    }
    return 0;
}