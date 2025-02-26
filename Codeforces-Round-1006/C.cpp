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

void min_max(int &a, int &b){
    b = a + b;
    a = min(a,b-a);
    b = b - a;
}

/*


/*
I)  Sub-problema: Montar um array com N com menor MEX possivel, tal que cada elemento elemento 𝑎1 | 𝑎2 | 𝑎3 | … | 𝑎𝑛 = 𝑥.

II) Solução do Subproblema e Ideia: 
    - Note 1: Precisamos achar o primeiro elemento que nao contribui para a validação: 𝑎1 | 𝑎2 | 𝑎3 | … | 𝑎𝑛 = 𝑥.
        Pois esse elemento será o nosso menor MEX possível.
    Dessa forma, basta iteramos de 0 até N - 1, tendo em vista que nosso Array só deve ter no máximo N elementos, e sempre 
    que cumprir com a validacao do problema, adicionamos na resposta, quando nao, paramos a iteração e verificamos se os 
    elementos que ja colocamos no array sao suficientes para cumprir a validação do problema.
    Se sim, temos a resposta.
    Quando nao, basta colocarmos o ultimo elemento do array como X, pois ele nao irá inteferir na resposta.

III) Note:
    - Zeros no array nao influenciam na validação : 𝑎1 | 𝑎2 | 𝑎3 | … | 𝑎𝑛 = 𝑥.
    - Para checar se um numero i nao contribui para validação, isso acontece quando um bit esta setado em i e nao esta setado em x.
        portanto, basta checar fazendo essa operação : (i & (~x)) == 0 

IV) Complexidade: O(N)

*/


bool check(int i, int x){
    return (i & (~x)) == 0;
}
 

void solve(){
    int n, x; cin >> n >> x;
    if(n == 1){
        cout << x << endl;
        return;
    }  
    vector<int> ans(n,0);
    int j = 0, isValid = 0;
    for(int i = 0; i < n; i++){
        if(check(i,x)){
            ans[j] = i;
            j++;
            isValid |= i;
        } else {
            break;
        }
    }
    if(isValid != x){
        ans.back() = x;
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
    cout << endl;

}

signed main() { _
    int t = 1; 
    cin >> t;
    while(t--){
        solve();
    }
    exit(0);
}