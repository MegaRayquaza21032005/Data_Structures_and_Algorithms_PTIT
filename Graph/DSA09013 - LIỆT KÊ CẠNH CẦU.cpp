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
int visited[1009];

void input(int v, int e)
{
    FOR(i, 1, e)
    {
        int x, y; cin >> x >> y;
        ke[x].pb(y);
        ke[y].pb(x);
        canh.pb({x, y});
    }
    FOR(i, 1, v) sort(ke[i].begin(), ke[i].end());
}

void DFS(int u, int s, int t)
{
    visited[u] = 1;
    for(int v : ke[u])
    {
        if((u == s && v == t) || (u == t && v == s)) continue;
        else if(visited[v] == 0)
        {
            DFS(v, s, t);
        }
    }
}

void BFS(int u, int s, int t)
{
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while(!q.empty())
    {
        int v = q.front(); q.pop();
        for(int x : ke[v])
        {
            if((x == s && v == t) || (x == t && v == s)) continue;
            if(visited[x] == 0)
            {
                q.push(x);
                visited[x] = 1;
            }
        }
    }
}

int demtplt(int s, int t)
{
    int cnt = 0;
    FOR(i, 1, v)
    {
        if(visited[i] == 0)
        {
            ++cnt;
            DFS(i, s, t);
            //BFS(i, s, t);
        }
    }
    return cnt;
}

bool canh_cau(int s, int t, int lt)
{
    ms(visited, 0);
    return demtplt(s, t) > lt;
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
        int lt = demtplt(-1, -1); // số lượng thành phần liên thông ban đầu
        for(pi x : canh)
        {
            int s = x.first, t = x.second;
            if(canh_cau(s, t, lt)) cout << s << " " << t << " ";
        }
        cout << endl;
        ms(visited, 0);
        FOR(i, 1, v) ke[i]= {};
        canh = {};
    }
    return 0;
} 