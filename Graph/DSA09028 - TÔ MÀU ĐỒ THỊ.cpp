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

int v, e, M;
vector<vector<int>> ke(1009);
int visited[1009], color[1009], parent[1009];

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

bool safe(int u, int c) // đỉnh u có màu là c
{
    for(int v : ke[u]) // các đỉnh kề của u có đỉnh nào có màu là c không
    {
        if(color[v] == c) return false;
    }
    return true;
}
bool DFS(int u)
{
    if(u > v) return true;
    FOR(c, 1, M)
    {
        if(safe(u, c))
        {
            color[u] = c;
            if(DFS(u + 1)) return true;
            color[u] = 0;
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
        cin >> v >> e >> M;
        input(v, e);
        bool check = false;
        if(DFS(1)) cout << "YES\n";
        else cout << "NO\n";
        ms(color, 0);
        FOR(i, 1, v)
        {
            ke[i]= {};
        }
    }
    return 0;
}