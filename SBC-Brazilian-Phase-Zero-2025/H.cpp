// problem: https://codeforces.com/gym/105925/problem/H

#include <bits/stdc++.h>
#include <csignal>
#include <cstdio>
using namespace std;

#define int long long
#define map unordered_map
#define all(A) A.begin(), A.end()
#define double long double
#define bug(x) cout << #x << ' ' << x << endl

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());


struct Position {
  int flipped;
  int val;
};

void Print(vector<Position> & a)
{
  // cout << "AAAA" << endl;

  // for(int i = a.size()-1; i >= 0; i--)
  // {
  //   cout << a[i].flipped;
  // }
  // cout << endl;
}

bool is_pal(vector<Position> & a)
{
  
  for(int i = 0; i < a.size(); i++)
  {
    if(a[i].flipped != a[a.size() - i - 1].flipped)
      return false;
  }

  return true;
}

int get_val(vector<Position> & a)
{
  int res = 0;
  for(auto v : a)
    if(v.flipped)
      res += v.val;

  return res;
}


int solve(int max)
{
  vector<Position> v;

  // int max; cin >> max;

  int aux = max;
  int base = 1;
  int qtd = 0;

  while(aux != 0)
  {
    Position p = {aux %2, base};
  
    if (p.flipped)
      qtd++;
    v.push_back(p);
    base*=2;
    aux/=2;
  }

  if(max == 1)
    return 1;

  if(qtd == 1)
    return max - 1;

  Print(v);



  if(is_pal(v))
    return max;

  // if(qtd == 1)
  // {
  //   int sum = 0;
  //   for(int i = 1; i < v.size()-1; i++)
  //     sum += v[i].val;

  //   return cout << sum << endl , 0;
  // }

  int first_one = -1;

  bool is_there_a_need = false;

  bool decided = false;

  for(int i = v.size()/2; i < v.size(); i++)
  {
    int l = v.size() - i -1;
    int r = i;
    if(decided)
    {
      v[l].flipped = v[r].flipped;
      continue; 
    }

    if(v[i].flipped and first_one == -1)
    {
      first_one = i;
    }


    if(v[r].flipped and !v[l].flipped)
    {
      v[l].flipped = 1;

      int inverse_first_one = v.size() - first_one - 1;

      for(int z = inverse_first_one; z < first_one; z++)
      {
        v[z].flipped = 1;
      }

      v[inverse_first_one].flipped = v[first_one].flipped = 0;

      decided = true;
      continue;
    }

    if(v[l].flipped and !v[r].flipped)
    {
      v[l].flipped = 0;
      decided = true;
      continue;
    }

  }

  Print(v);

  return get_val(v);
} 

signed main()
{
  int aux; cin >> aux;
  cout << solve(aux) << endl;
}


