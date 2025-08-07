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

struct edge
{
    int u, v, w;
};

int v, e;
vector<pi> ke[1009];
vector<edge> canh;
int visited[1009];

void input(int v, int e)
{
    FOR(i, 1, e)
    {
        int x, y, w;
        cin >> x >> y >> w;
        // ke[x].pb({y, w});
        // ke[y].pb({x, w});
        canh.pb({x, y, w});
        canh.pb({y, x, w});
    }
}

void Dijkstra(int s)
{
    priority_queue<pi, vector<pi>, greater<pi>> q;
    vector<int> d(1009, 1e9);
    d[s] = 0;
    q.push({0, s});
    while(!q.empty())
    {
        pi top = q.top(); q.pop();
        int u = top.second;
        int cost = top.first;
        if(cost > d[u]) continue;
        for(pi x : ke[u])
        {
            int v = x.first;
            int w = x.second;
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
    FOR(i, 1, v) cout << d[i] << " ";
}

void Bellman_Ford(int s)
{
    vector<int> d(1009, 1e9);
    d[s] = 0;
    FOR(i, 1, v - 1)
    {
        FOR(j, 0, 2 * e - 1)
        {
            int u = canh[j].u;
            int v = canh[j].v;
            int w = canh[j].w;
            if(d[u] < (int) 1e9)
            {
                d[v] = min(d[v], d[u] + w);
            }
        }
    }
    FOR(i, 1, v) cout << d[i] << " ";
}
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        int s;
        cin >> v >> e >> s;
        input(v, e);
        Bellman_Ford(s);
        cout << endl;
        canh = {};
        //FOR(i, 1, v) ke[i] = {};
    }
    return 0;
}