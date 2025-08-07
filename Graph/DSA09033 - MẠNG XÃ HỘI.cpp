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
int visited[1009];
vector<vector<int>> ke(1000009);

void input(int v, int e)
{
    FOR(i, 1, e)
    {
        int x, y; cin >> x >> y;
        ke[x].pb(y);
        ke[y].pb(x);
    }
}

bool check()
{
    FOR(i, 1, v)
    {
        for(int x : ke[i])
        {
            if(ke[x].size() != ke[i].size()) return false;
        }
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
        if(check()) cout << "YES\n";
        else cout << "NO\n";
        FOR(i, 1, v) ke[i] = {};
    }
    return 0;
} 