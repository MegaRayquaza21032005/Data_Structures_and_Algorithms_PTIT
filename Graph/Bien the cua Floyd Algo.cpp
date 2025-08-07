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
tìm đường đi giữa 2 đỉnh x và y sao cho (trọng số của cạnh lớn nhất trong quá trình di chuyển) là min
*/
int v, e;
int visited[1009], dp[400][400];
vector<vector<int>> ke(1009);

void input(int v, int e)
{
    FOR(i, 1, e)
    {
        int x, y, w; cin >> x >> y >> w;
        dp[x][y] = w;
    }
}

void Floyd()
{
    FOR(i, 1, v)
    {
        FOR(j, 1, v)
        {
            if(dp[i][j] == 0) dp[i][j] = 1e9;
        }
    }
    FOR(i, 1, v) dp[i][i] = 0;
    FOR(k, 1, v)
    {
        FOR(i, 1, v)
        {
            FOR(j, 1, v)
            {
                if(dp[i][k] < 1e9 && dp[k][j] < 1e9 && dp[i][j] > max(dp[i][k], dp[k][j]))
                {
                    dp[i][j] = max(dp[i][k], dp[k][j]);
                    //   dp[i][j] = min(dp[i][j], max(dp[i][k], dp[k][j]));
                    /*
                    đường đi từ i đến j có cạnh i -> j tối ưu hơn hay là chèn thêm k vào i -> k -> j thì trọng số tối ưu hơn
                    */
                }
            }
        }
    }
}
int main()
{
    fast;
    int T = 1;
    //cin >> T;
    while(T--)
    {
        int q;
        cin >> v >> e >> q;
        input(v, e);
        Floyd();
        while(q--)
        {
            int x, y; cin >> x >> y;
            if(dp[x][y] >= 1e9) cout << -1 << endl;
            else cout << dp[x][y] << endl;
        }
        FOR(i, 1, v) ke[i] = {};
        ms(visited, 0);
    }
    return 0;
} 