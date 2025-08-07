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
int parent[1000009], sz[1000009];

void init()
{
    FOR(i, 1, v)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int u)
{
    if(u == parent[u]) return u;
    else return parent[u] = find(parent[u]);
}

bool Union(int u, int v)
{
    u = find(u);
    v = find(v);
    if(u == v) return false;
    if(sz[u] >sz[v])
    {
        parent[v] = u;
        sz[u] += sz[v];
    }
    else
    {
        parent[u] = v;
        sz[v] += sz[u];
    }
    return true;
}

void input(int v, int e)
{
    FOR(i, 1, e)
    {
        int x, y; cin >> x >> y;
        Union(x, y);
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
        init();
        input(v, e);
        cout << *max_element(sz + 1, sz + v + 1) << endl;
    }
    return 0;
} 