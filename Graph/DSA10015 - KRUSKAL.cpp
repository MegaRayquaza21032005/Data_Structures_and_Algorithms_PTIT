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
vector<edge> canh;
int v, e;
int parent[1009], sz[1009];

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}
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
    if(a == b)
    {
        return false;
    }
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
        int x, y, w;
        cin >> x >> y >> w;
        canh.pb({x, y, w});
        canh.pb({y, x, w});
    }
}

void Kruskal()
{
    sort(canh.begin(), canh.end(), cmp);  //sắp xếp ds cạnh theo thứ tự tăng dần về chi phí
    int cost = 0;   // giá trị nhỏ nhất của cây khung
    vector<edge> res;  // cạnh trong cây khung
    for(edge x : canh)
    {
        if(res.size() == v - 1) break;  // cây khung v đỉnh có v - 1 cạnh
        if(Union(x.u, x.v))
        {
            cost += x.w;
            res.pb({x.u, x.v, x.w}); // res.pb(x);
        }
    }
    if(res.size() < v - 1) cout << -1 << endl; // đồ thị ko liên thông
    else
    {
        cout << cost << endl;
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
        Kruskal();
        FOR(i, 1, v) canh = {};
    }
    return 0;
}