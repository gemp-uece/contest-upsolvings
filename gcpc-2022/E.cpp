// https://codeforces.com/gym/104059/problem/E

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

    /**
     *  A | B | A + B | A + 3B | 3A + 5B | 5A + 11B | 11A + 21B |
     *  A : 1 | 0 | 1 | 1 | 3 | 5 | 11 |
     * 
     * 
     * 
     * */
    int n; cin >> n;
    vector<long double> fib(1005);

    fib[1] = 1.00;
    fib[2] = 1.00;
    for(int i = 3; i <= 1000; i++){
        fib[i] = fib[i-1] + 2.00*fib[i-2];
    }

    if(n == 1){
        cout << 100 << " " << 0 << endl;
        return 0;
    } 
    if(n == 2){
        cout << 0 << " " << 100 << endl;
        return 0;
    }
    n = min((int)1000,n);
    cout << fixed << setprecision(32);
    long double soma = fib[n-2] + fib[n-1];
    long double x = (fib[n-2]/soma)*100.00;
    long double y = (fib[n-1]/soma)*100.00;
    cout << x << " "<<  y << endl;

    return 0;
}