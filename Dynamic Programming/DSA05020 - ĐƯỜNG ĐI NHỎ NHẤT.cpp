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

ll a[1009][1009], dp[1009][1009];
void input(int n, int m)
{
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
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
        int n, m;
        cin >> n >> m;
        input(n, m);
        for(int i = 1; i <= n; ++i) dp[i][1] = dp[i - 1][1] + a[i][1];
        for(int j = 1; j <= m; ++j) dp[1][j] = dp[1][j - 1] + a[1][j];
        for(int i = 2; i <= n; ++i)
        {
            for(int j = 2; j <= m; ++j)
            {
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + a[i][j];
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}