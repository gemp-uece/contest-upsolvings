/*

Problema: J. Jagged Skyline
Link: https://codeforces.com/gym/104020/problem/J

I) Primeira ideia: iterar de (1...W) e realizar uma busca binária dados os valores de (1...10ˆ18)
I.I) Complexidade: O(W*log2(10ˆ18)) ~= O(W*60) O(1e5) e seriam 6*(1e5) queries. 




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
    int w, h; cin >> w >> h;
    vector<int> cols(w);
    for (int i = 0; i < w; i++){
        cols[i] = i + 1;
    }
    random_shuffle(cols.begin(), cols.end());
    pii best = {1,0}; // best W e best H;
    for(int i : cols){
        if(best.second == h) break;
        
        cout << "? " << i << " " << best.second + 1 << endl;
        cout.flush();

        string response; cin >> response;
        if(response[0] == 's') continue;

        // busca binária:
        int l = best.second+1, r = h, colH = l;
        while(l <= r){
            int mid = l + (r - l)/2;
            cout << "? " << i << " " << mid << endl;
            cout.flush();
            cin >> response;
            if(response[0] == 'b'){
                colH = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        if(colH > best.second){
            best = {i,colH};
        }
    }

    cout << "! " << best.first << " " << best.second << endl;
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