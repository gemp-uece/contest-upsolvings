// https://codeforces.com/gym/104059/problem/L

#include <bits/stdc++.h>

#define int long long
#define endl '\n'
#define bug(A) cout << #A << ' ' <<  A << endl


using namespace std;

char grid[101][101];


void paint(int x , int y, int widht, int height, char color)
{
    while(widht--)
    {
        int aux_y = y;
        int aux_heigth = height;
        
        while(aux_heigth--)
        {
            grid[aux_y][x] = color;
            aux_y++;
        }
        x++;
    }
}


signed main()
{
    int n, m, q; cin >> n >> m >> q;

    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
            grid[i][j] = '0';
    }

    if((n*m) % q)
        return cout << "IMPOSSIBLE" << endl, 0;

    int area = n*m/q;
    
    int height = n +1;

    for(int i = 1; i <= n; i++)
    {
        // bug(i);
        // bug(area%i);
        // bug(area/i);
        if(area%i || area/i > m || n%i)
            continue;

        height = i;
        break;
    }

    // bug(n%height);
    if(n%height > 0)
        return cout << "IMPOSSIBLE" << endl, 0;

    int base = 0;

    int group=0;

    while(base + height <= n)
    {
        int w = 0, w_size = area/height; 
        
        for(; w + w_size<= m; w+=w_size) 
        {
            // cout << group << endl;
            paint(w, base, w_size, height, 'A'+(group++));
        }
        base+=height;
    }

    base = m- (m%(area/height));
    int width = m+1;

    for(int i = 1; i <= m - base; i++)
    {
        if(area%i || area/i > n || m%i)
            continue;

        width = i;
        break;
    }
    // bug(m);
    // bug(base);
    // bug(width);
    // bug((m-base)%width);  
    if((m-base)%width > 0)
        return cout << "IMPOSSIBLE" << endl, 0;


    // cout << "\nM\n" << endl;

    while(base + width <= m)
    {
        

        int h = 0, h_size = area/width; 
        // bug(h_size);
        // bug(width);
        for(; h + h_size <= n; h+=h_size) 
        {
            // cout << group << endl;
            paint(base, h, width, h_size, 'A'+(group++));
        }
        base+=width;
    }

    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < m; x++)
            if(grid[y][x] == '0') grid[y][x] = 'A'+(group);
    }




    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < m; x++)
            cout << grid[y][x];
        cout << endl;
    }

    return 0;
}