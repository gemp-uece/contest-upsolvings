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
I)  Sub-problema: Dado uma quantidade de '-','_'. De que forma consigo rearraja-los numa string 
    de modo ter o máximo de subsequências iguais a "-_-".

I.I) Solução do Subproblema:
    O melhor caso é colocar todos os '-' nas extremidades (divididos igualmente entre a esquerda e a direita)
    e todos os '_' no centro. Assim, a string ideal seria:
    [parte_esquerda de '-' ] + [todos os '_'] + [parte_direita de '-'].
II) Ideia: Dessa forma, basta contar as ocorrencias de cada caracter na string, e multiplicar as quantidades:
    quantidade_esquerda['-'] * quantidade_meio['_'] * quantidade_direita['-']

III) Note: Essa operação se refere ao cálculo combinatório de escolhas independentes.
   Ou seja, para cada escolha de um caractere '-' na parte esquerda, há "tra" opções para escolher um '_'
   na parte do meio, e para cada uma dessas escolhas, há "dir" opções para escolher um '-' na parte direita.
   Portanto, o total é dado pelo produto esq * tra * dir.

IV) Complexidade: O(|S|) pois precisamos iterar sobre o tamanho da string.

*/
void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '-') cnt++;
    }
    int tra = s.size() - cnt;
    int esq = cnt/2;
    int dir = esq;
    if(cnt%2 != 0) dir++;
    cout << esq * dir * tra << endl;
}

signed main() { _
    int t = 1; 
    cin >> t;
    while(t--){
        solve();
    }
    exit(0);
}