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

bool Halminton_path(int u, int cnt)
{
    if(cnt == v) return true;
    else
    {
        visited[u] = 1;
        for(int v : ke[u])
        {
            if(visited[v] == 0)
            {
                if(Halminton_path(v, cnt + 1)) return true;
            }
        }
        visited[u] = 0;
    }
    return false;
}

bool has_Halminton_path()
{
    FOR(i, 1, v)
    {
        ms(visited, 0);
        if(Halminton_path(i, 1)) return true;
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
        cout << has_Halminton_path() << endl;
        memset(visited, 0,sizeof(visited));
        FOR(i, 1, v)
        {
            ke[i]= {};
        }
    }
    return 0;
} 