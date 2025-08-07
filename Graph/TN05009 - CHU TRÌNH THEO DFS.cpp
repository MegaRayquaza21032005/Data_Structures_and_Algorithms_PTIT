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

/*
1
6 6
1 2
1 3 
1 6
3 4
3 5
4 5
--> NO chứ ko phải 3 4 5 3
*/
int v, e;
vector<vector<int>> ke(1009);
vector<pi> canh;
int visited[1009], parent[1009];

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

int check = 0;
void DFS(int u)
{
    if(check) return;
    visited[u] = 1;
    for(int v : ke[u])
    {
        if(check) return;
        if(visited[v] == 1 && parent[u] != v && v == 1) // đỉnh phải bắt đầu và kết thúc ở 1
        {
            vector<int> res;
            int tmp = u;
            res.pb(v);
            while(tmp != v)
            {
                res.pb(tmp);
                tmp = parent[tmp];
            }
            res.pb(v);
            FORD(i, res.size() - 1, 0)
            {
                cout << res[i] << " ";
            }
            check = 1;
            return;
        }
        if(visited[v] == 0)
        {
            parent[v] = u;
            DFS(v);
        }
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
        input(v, e);
        check = 0;
        DFS(1);
        if(check == 0) cout << "NO";
        cout << endl;
        ms(visited, 0);
        FOR(i, 1, v) ke[i]= {};
        ms(parent, 0);
    } 
    return 0;
} 