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
int visited[1009];
vector<vector<int>> ke(1009);
vector<pair<int, int>> tree;

void input(int v, int e)
{
    FOR(i, 1, e)
    {
        int x, y; cin >> x >> y;
        ke[x].pb(y);
        ke[y].pb(x);
    }
}

void BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
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

bool lienthong()
{
    BFS(1);
    FOR(i, 1, v)
    {
        if(visited[i] == 0) return false;
    }
    return true;
}

void BFS_spanning_tree(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int x : ke[v])
        {
            if(visited[x] == 0)
            {
                q.push(x);
                visited[x] = 1;
                tree.pb({v, x});
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
        int start;
        cin >> v >> e >> start;
        input(v, e);
        if(!lienthong())
        {
            cout << -1 << endl;
        }
        else
        {
            ms(visited, 0);
            BFS_spanning_tree(start);
            for(auto x : tree)
            {
                cout << x.first << " " << x.second << endl;
            }
        }
        tree = {};
        FOR(i, 1, v) ke[i] = {};
        ms(visited, 0);
    }
    return 0;
} 