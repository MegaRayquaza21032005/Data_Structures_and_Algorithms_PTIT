#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
const ll mod = 1e15 + 7;

int a[1009][1009], dp[1009][1009], ans;
void input(int n, int m)
{
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            dp[i][j] = a[i][j];
            if(a[i][j] == 1) ans = 1;
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
        int n, m; cin >> n >> m;
        ans = 0;
        input(n, m);
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= m; ++j)
            {
                if(a[i][j] == 1)
                {
                    if(a[i - 1][j] == 0 || a[i][j - 1] == 0 || a[i - 1][j - 1] == 0) continue;
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << endl;
        ms(dp, 0);
    }
    
}