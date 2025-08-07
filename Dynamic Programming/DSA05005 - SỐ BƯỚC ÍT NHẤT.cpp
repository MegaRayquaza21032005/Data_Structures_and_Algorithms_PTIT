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

int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        int n; cin >> n;
        vector<int> a(n + 9), dp(n + 9, 1);
        FOR(i, 1, n) cin >> a[i];
        FOR(i, 2, n)
        {
        	FOR(j, 1, i - 1)
        	{
        		if(a[i] >= a[j])
        		{
        			dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		cout << n - *max_element(dp.begin() + 1, dp.begin() + n + 1) << endl;
    }
    return 0;
}
