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
int visited[1009], parent[1009], color[1009];

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

bool DFS(int u)
{
    color[u] = 1;
    for(int v : ke[u])
    {
        if(color[v] == 1) return true;
        if(color[v] == 0)
        {
            if(DFS(v)) return true;
        }
    }
    color[u] = 2;
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
        int check = 0;
        FOR(i, 1, v)
        {
            if(color[i] == 0)
            {
                if(DFS(i))
                {
                    cout << "YES\n";
                    check = 1;
                    break;
                }
            }
        }
        if(check == 0) cout << "NO\n";
        ms(visited, 0);
        FOR(i, 1, v) ke[i]= {};
        ms(color, 0);
    }
    return 0;
} 