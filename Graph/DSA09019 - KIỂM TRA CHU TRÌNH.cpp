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
vector<vector<int>> ke(1009);
vector<pi> canh;
int visited[1009], parent[1009];

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

bool DFS(int u)
{
    visited[u] = 1;
    for(int v : ke[u])
    {
        if(visited[v] == 1 && parent[u] != v) return true;
        if(visited[v] == 0)
        {
            parent[v] = u;
            if(DFS(v)) return true;
        }
    }
    return false;
}

bool BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while(!q.empty())
    {
        int v = q.front(); q.pop();
        for(int x : ke[v])
        {
            if(visited[x] == 1 && parent[v] != x) return true;
            if(visited[x] == 0)
            {
                parent[x] = v;
                q.push(x);
                visited[x] = 1;
            }
        }
    }
    return false;
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
        bool check = false;
        FOR(i, 1, v)
        {
            if(visited[i] == 0)
            {
                if(BFS(i)) // DFS(i);
                {
                    cout << "YES\n";
                    check = true;
                    break;
                }
            }
        }
        if(check == false) cout << "NO\n";
        ms(visited, 0);
        FOR(i, 1, v) ke[i]= {};
        ms(parent, 0);
    }
    return 0;
} 