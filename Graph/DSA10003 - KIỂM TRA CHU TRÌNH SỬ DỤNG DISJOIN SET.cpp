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
int visited[1009], parent[1009],sz[1009];
bool ok = false;

void init(int v)
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

bool Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a == b)
    {
        ok = true;
        return false;
    }
    // if(a < b) parent[b] = a;
    // else parent[a] = b;
    if(sz[a] > sz[b])
    {
        parent[b] = a;
        sz[a] += sz[b];
    }
    else
    {
        parent[a] = b;
        sz[b] += sz[a]; 
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
        ok = false;
        cin >> v >> e;
        init(v);
        input(v, e);
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}