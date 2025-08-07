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

ll dp[1000009];
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        int n, k; cin >> n >> k;
        dp[0] = dp[1] = 1;
        FOR(i, 2, n)
        {
        	FOR(j, 1, k)
        	{
        		dp[i] += dp[i - j];
        		dp[i] %= mod;
        		if(i - j == 0) break;
			}
		}
		cout << dp[n] << endl;
		ms(dp, 0);
    }
    return 0;
}