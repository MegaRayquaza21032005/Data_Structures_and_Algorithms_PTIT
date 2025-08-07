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

int a[1009][1009], dp[1009][1009], n, m;
void input(int n, int m)
{
    FOR(i, 1, n)
    {
        FOR(j, 1, m) cin >> a[i][j];
    }
}

int BFS()
{
    queue<pair<int, int>> q;
    q.push({1, 1});
    while(!q.empty())
    {
        int i = q.front().first, j = q.front().second;
        q.pop();
        if(i == n && j == m) return dp[i][j];
        if(i + a[i][j] >= 1 && i + a[i][j] <= n && dp[i + a[i][j]][j] == 0)
        {
            dp[i + a[i][j]][j] = dp[i][j] + 1;
            q.push({i + a[i][j], j});
        }
        if(j + a[i][j] >= 1 && j + a[i][j] <= m && dp[i][j + a[i][j]] == 0)
        {
            dp[i][j + a[i][j]] = dp[i][j] + 1;
            q.push({i, j + a[i][j]});
        }
    }
    return -1;
}
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        input(n, m);
        cout << BFS() << endl;
        ms(a, 0);
        ms(dp, 0);
    }  
    return 0;
}