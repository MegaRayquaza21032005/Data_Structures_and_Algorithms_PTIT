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
vector<vector<int>> ke(1009);
int visited[1009];

void input(int v, int e)
{
    FOR(i, 1, e)
    {
        int x, y; cin >> x >> y;
        ke[x].pb(y);
        //ke[y].pb(x);
    }
    FOR(i, 1, v) sort(ke[i].begin(), ke[i].end());
}

void DFS(int u)
{
    visited[u] = 1;
    cout << u << " ";
    for(int v : ke[u])
    {
        if(visited[v] == 0)
        {
            DFS(v);
        }
    }
}

void BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while(!q.empty())
    {
        int v = q.front(); q.pop();
        cout << v << " ";
        for(int x : ke[v])
        {
            if(visited[x] == 0)
            {
                q.push(x);
                visited[x] = 1;
            }
        }
    }
}
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        int u;
        cin >> v >> e >> u;
        input(v, e);
        BFS(u);
        cout << endl;
        ms(visited, 0);
        FOR(i, 1, v) ke[i]= {};
    }
    return 0;
} 