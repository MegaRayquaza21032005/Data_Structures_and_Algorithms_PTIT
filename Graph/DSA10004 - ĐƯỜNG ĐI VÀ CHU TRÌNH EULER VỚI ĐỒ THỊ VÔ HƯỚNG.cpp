#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
#define pi pair<int, int>
const int mod = 1e9 + 7;
const ll llmod = 1e15 + 7;


int v, e;
vector<int> ke[1009];
int visited[1009], deg[1009];

void input(int v, int e)
{
    FOR(i, 1, e)
    {
        int x, y;
        cin >> x >> y;
        deg[x]++;
        deg[y]++;
    }
}

int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        cin >> v >> e;
        input(v, e);
        int odd = 0;
        FOR(i, 1, v)
        {   
            if(deg[i] & 1) ++odd;
        }
        if(odd == 0) cout << 2 << endl;
        else if(odd == 2) cout << 1 << endl;
        else cout << 0 << endl;
        FOR(i, 1, v) ke[i] = {};
        ms(deg, 0);
    }
    return 0;
}