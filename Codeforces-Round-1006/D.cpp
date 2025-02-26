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
I) Sub-problema: deslocar um elemento da posição i do array para uma posição i < j < N, 
    de modo que reduz a quantidade de inversões no array.

II) Solução: Checar todos os pares (i,j) o que aconteceria se eu trocasse o i para a posição j+1. Isso quer dizer:
    - Minha resposta melhora sempre que no intervalo de [i,j] eu tiver um elemento a[j] menor que a[i],
    - Minha resposta piora sempre que no intervalo de [i,j] eu tiver um elemento a[j] maior que a[i].
    Levando isso em consideração, eu sempre guardo meu melhor (i,j).

III) Notes: Dificil imaginar que a solução quadratica passasse :x, mas como sao poucos elementos N <= 2000, isso pode indicar
    que fosse funcionar.

IV) Complexidade: O(Nˆ2)

*/

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int best = 0, bestl = 0, bestr = 0;
    for(int l = 0; l < n; l++){
        int d = 0;
        for(int r = l+1; r < n; r++){
            if(arr[r] > arr[l]) d++;
            else if(arr[r] < arr[l]) d--;

            if(d < best){
                best = d;
                bestl = l;
                bestr = r;
            }
        }
    }
    cout << bestl + 1 << " " << bestr + 1 << endl;
}

signed main() { _
    int t = 1; 
    cin >> t;
    while(t--){
        solve();
    }
    exit(0);
}