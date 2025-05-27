// problem: https://codeforces.com/gym/105925/problem/A

#include <bits/stdc++.h>
#include <csignal>
#include <cstdio>
using namespace std;

#define int long long
#define map unordered_map
#define all(A) A.begin(), A.end()

#define bug(x) cout << #x << ' ' << x << endl


mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int solve()
{

  int c, g; cin >> c >> g;
  
  // cout << c << ' ' << g << endl;

  if(c == 1)
    cout  << "vivo e morto" << endl;
  else if (g == 1)
    cout  << "vivo" << endl;
  else
    cout  << "morto" << endl;
  
  return 1;
} 

signed main()
{

  int t = 1;
  //cin >> t;
  while(t--)
    solve();

}


