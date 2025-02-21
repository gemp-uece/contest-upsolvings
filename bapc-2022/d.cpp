/*

Problema: Dividing DNA (Interativo)
Link: https://codeforces.com/gym/104020/problem/D

Para esse problema, temo seguinte ideia:
temos uma string hipotetica s de tamanho n e queremos consultar em um banco de dados os intervalos pertecentes a s, 
se a substring resultante aparece no nosso banco de dados.

note: para a uma string x aparecer no banco de dados, ela pode aparecer como substring das strings presentes no banco.


então pela natureza de iterativa do problema, temos que ir perguntando sobre intervalos (a,b) e receberemos as respostas:
present ou absent, indicando se a substring gerado no intervalo (a,b) é presente no banco de dados ou não.
e por fim, devemos responder a quantidade de intervalos absents que temos.

I) a ideia é testarmos todos os intervalos de possibilidades.
I.I) contudo, isso é O(n*n), e ele limita a 2*n queries.
II) Vamos melhorar a busca por intervalos usando os seguintes fatos:
* Pegando o exemplo da questão: CTGCAA. 
* Observação 1: 
Imagine que você tem um intervalo (0,0) e pergunta ao sistema:
- se ele é present, precisamos incrementar aquela string para achar um ponto que ela nao seja mais present
- se ela é absent, achamos um intervalo que incrementa nossa resposta. Logo, podemos ir procurar outro intervalo que nao contenha 
o intervalo que ja temos a resposta. 

??? Por que isso é valido ? 
=> Pela ideia de: Intervalos Disjuntos. 
=> O problema ele pede o maior numero de subsets possivel Disjuntos, logo, o nosso melhor caso é intervalos unitários, procurar intervalos compostos
em que (0,0) é absent e procurar (0,1)..(0,x) até ser absent de novo, estaremos perdendo o valor de (0,0) e um possivel outro intervalo presente que tambem é absent, 
logo nossa resposta ficaria menor.
Portanto, precisamos de intervalos unitários, ou dos menores possiveis que sao absents.


III) Seguindo com a solução, o approach é : 
dado um inicio : cur = 0.
procuro pelo proximo intervalo absent (0,0..i).
encontrei, faço: cur = i;
e sigo em loop, para proximos intervalos:
(i, i...i++)

*/
 


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

const int maxn = 2e5+5;

void solve(){
    int n; cin >> n;
    int ans = 0;
    int cur = 0;
    for(int i = 1; i <= n; i++){
        cout << "? " << cur << " " << i << endl;
        cout.flush();

        string resposta; cin >> resposta;
        if(resposta[0] == 'a'){
            ans++;
            cur = i;
        }
    }
    cout << "! " << ans << endl;
    cout.flush();
}

signed main() { _
    int t = 1; 
    // cin >> t;
    while(t--){
        solve();
    }
    exit(0);
}