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
int parent[1009], sz[1009];

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

bool Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a == b) return false;
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
        int x, y;
        cin >> x >> y;
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
        int q; cin >> q;
        while(q--)
        {
            int x, y; cin >> x >> y;
            if(find(x) == find(y))
            {
                cout << "YES\n";
            }
            else cout << "NO\n";
        }
    }
    return 0;
}