#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int long long
#define pii pair<int,int>
#define ld long double

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int maxn = 1e6+5;;

/*
Problema: A. New World, New Me, New Array
Link: https://codeforces.com/contest/2072/problem/A


I) Sub-problema: Dado que eu posso usar no maximo N números que variam entre [-p,p], consigo chegar em K ?
I.I) Note 1: O numero de operação, nao depende do sinal de K ou P, dado que P varia entre [-P,P].
II) Ideia: O melhor caso para minimizar o numero de operação é sempre usar o máximo de P sempre que possivel,
e se restar algo ao final, uma operação será o suficiente para chegarmos em K.
III) Complexidade: O(1)
*/

void solve(){
    int n,k,p; cin >> n >> k >> p;
    p = abs(p);
    k = abs(k);
    // sempre coloco o maximo de p's que consigo em n.
    if(n * p < k){
        cout << "-1" << endl;
        return;
    }

    int ans = k/p;
    if(k%p != 0) ans++;
    cout << ans << endl;

}

signed main() { _
    int t = 1; 
    cin >> t;
    while(t--){
        solve();
    }
    exit(0);
}