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
vector<vector<int>> ke(1009), t_ke(1009); // đồ thị và đồ thị chuyển vị
int visited[1009];
stack<int> st;

void input(int v, int e)
{
    FOR(i, 1, e)
    {
        int x, y; cin >> x >> y;
        ke[x].pb(y);
        t_ke[y].pb(x); // lưu đồ thị chuyển vị
        //ke[y].pb(x);
    }
    FOR(i, 1, v) sort(ke[i].begin(), ke[i].end());
    FOR(i, 1, v) sort(t_ke[i].begin(), t_ke[i].end());
}
void DFS1(int u) // dùng cho đồ thị chuyển vị --> in ra thành phần liên thông mạnh
{
    visited[u] = 1;
    //cout << u << ' ';
    for(int v : t_ke[u])
    {
        if(visited[v] == 0) DFS1(v);
    }
}

void DFS(int u) // dùng cho đồ thị gốc
{
    visited[u] = 1;
    for(int v : ke[u])
    {
        if(visited[v] == 0) DFS(v);
    }
    st.push(u);
}

bool Kosaraju()
{
    ms(visited, 0);
    int cnt = 0;
    while(!st.empty())
    {
        int u = st.top(); st.pop();
        if(visited[u] == 0)
        {
            DFS1(u);
            ++cnt;
            //cout << endl;
        }
    }
    return cnt == 1;
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
        FOR(i, 1, v)
        {
            if(visited[i] == 0)
            {
                DFS(i);
            }
        }
        if(Kosaraju()) cout << "YES\n";
        else cout << "NO\n";
        ms(visited, 0);
        FOR(i, 1, v)
        {
            ke[i]= {};
            t_ke[i] = {};
        }
    }
    return 0;
}