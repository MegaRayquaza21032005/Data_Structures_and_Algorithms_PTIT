#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
const int mod = 1e9 + 7;
const ll llmod = 1e15 + 7;

int v, e;
vector<vector<int>> ke(100009);
int visited[100009];

void input(int v, int e)
{
    FOR(i, 1, e)
    {
        int x, y; cin >> x >> y;
        ke[x].pb(y);
        ke[y].pb(x);
    }
    FOR(i, 1, v) sort(ke[i].begin(), ke[i].end());
}

int DFS(int u)
{
    visited[u] = 1;
    int cnt = 1;
    for(int v : ke[u])
    {
        if(visited[v] == 0)
        {
            cnt += DFS(v);
        }
    }
    return cnt;
}
int tplt()
{
    int res = INT_MIN;
    FOR(i, 1, v)
    {
        if(visited[i] == 0)
        {
            res = max(res, DFS(i));
        }
    }
    return res;
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
        cout << tplt() << endl;
        memset(visited, 0,sizeof(visited));
        FOR(i, 1, v)
        {
            ke[i]= {};
        }
    }
    return 0;
} 