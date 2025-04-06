// https://codeforces.com/gym/104059/problem/I

#include <bits/stdc++.h>

#define int long long
#define endl '\n'
#define bug(A) cout << #A << ' ' <<  A << endl


using namespace std;

char grid[101][101];

vector<vector<int>> values;
int n, m;
int memo[(int)1e6];
bool calculated[(int)1e6];

int dp(int pos)
{
    if(calculated[pos])
        return memo[pos];

    int val = values[pos][0];

    int diff=  1e11;

    for(int j = 1; j < values[pos].size(); j++)
    {
        if(diff == 1e11)
        {
            if(pos+j == n)
                diff = -values[pos][j];
            else
                diff = dp(pos+j) - values[pos][j];
        }
        else
        {
            if(pos+j == n)
                diff = min(diff, -values[pos][j]);
            else
                diff = min(diff, dp(pos+j) - values[pos][j]);
        }

    }
    calculated[pos] = true;
    return memo[pos] = val + diff;
}

signed main()
{
    cin >> n >> m;
    fill(calculated, calculated + n+100, false);
    values.resize(n, vector<int>(1));

    for(int i = 0; i < n; i++)
    {
        cin >> values[i][0];
        for(int j = 0; j < m && j < n-i; j++)
        {
            int aux; cin >> aux;

            values[i].push_back(aux);
        }
    }

    cout << dp(0) << endl;

    return 0;
}