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
/*
1 phía kí hiệu là màu 1, phía còn lại kí hiệu là màu 2
*/
bool DFS(int u)
{
    color[u] = 3 - color[parent[u]];
    for(int v : ke[u])
    {
        if(color[v] == 0)
        {
            parent[v] = u;
            if(!DFS(v)) return false;
        }
        else if(color[v] == color[u]) return false;
    }
    return true;

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
        color[0] = 2;
        bool check = true;
        FOR(i, 1, v)
        {
            if(!DFS(i))
            {
                check = false;
                break;
            }
        }
        if(check) cout << "YES\n";
        else cout << "NO\n";
        ms(color, 0);
        FOR(i, 1, v)
        {
            ke[i]= {};
        }
    }
    return 0;
} 