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

vector<vector<int>> ke(100009);
int visited[1000009], parent[1000009];
void input(int n)
{
    FOR(i, 1, n)
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
        int x = q.front(); q.pop();
        for(int v : ke[x])
        {
            if(visited[v] == 0)
            {
                q.push(v);
                visited[v] = 1;
                parent[v] = x;
            }
        }
    }
}

void path(int s, int t)
{
    vector<int> v;
    while(t != s)
    {
        v.pb(t);
        t = parent[t];
    }
    v.pb(s);
    FORD(i, v.size() - 1, 0) cout << v[i] << " ";
    cout << endl;
}
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        int n; cin >> n;
        input(n - 1);
        BFS(1);
        FOR(i, 2, n)
        {
            if(ke[i].size() == 1) // check đỉnh i có phải node lá không
            {
                path(1, i);
            }
        }
        ms(visited, 0);
        ms(parent, 0);
        FOR(i, 1, n) ke[i] = {};
    }
    return 0;
}