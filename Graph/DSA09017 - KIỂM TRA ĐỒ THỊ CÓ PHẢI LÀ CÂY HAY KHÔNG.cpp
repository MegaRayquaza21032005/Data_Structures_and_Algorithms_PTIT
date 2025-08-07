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

/*
Điều kiện để là cây:
    Có đúng N đỉnh và N-1 cạnh.

    Liên thông (tức từ một đỉnh, duyệt được toàn bộ đồ thị).

    Không có chu trình (vì cây không có chu trình).
*/
int v, e;
vector<vector<int>> ke(1009);
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

void DFS(int u)
{
    visited[u] = 1;
    for(int v : ke[u])
    {
        if(visited[v] == 0)
        {
            DFS(v);
        }
    }
}

// bool DFS(int u)
// {
//     visited[u] = 1;
//     for(int v : ke[u])
//     {
//         if(visited[v] == 1 && parent[u] != v) return true;
//         if(visited[v] == 0)
//         {
//             if(DFS(v)) return true;;
//         }
//     }
//     return false;
// }
bool BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while(!q.empty())
    {
        int v = q.front(); q.pop();
        for(int x : ke[v])
        {
            if(visited[x] == 1 && parent[v] != x) return true;
            if(visited[x] == 0)
            {
                q.push(x);
                visited[x] = 1;
                parent[x] = v;
            }
        }
    }
    return false;
}

bool checktplt()
{
    int cnt = 0;
    FOR(i, 1, v)
    {
        if(visited[i] == 0)
        {
            ++cnt;
            DFS(i); 
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
        cin >> v;
        input(v, v - 1);
        if(checktplt())
        {
            if(BFS(1))
            {
                cout << "YES\n";
            }
            else cout << "NO\n";
        }
        else cout << "NO\n";
        ms(visited, 0);
        FOR(i, 1, v) ke[i]= {};
    }
    return 0;
} 