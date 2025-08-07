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
        string s; cin >> s;
        if(s[0] == '0')
        {
        	cout << 0 << endl;
        	continue;
		}
        int n = s.size();
        s = " " + s;
        dp[0] = dp[1] = 1;
    	FOR(i, 2, n)
    	{
    		if(s[i] != '0') dp[i] = dp[i - 1];
    		if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) dp[i] += dp[i - 2];
		}
		cout << dp[n] << endl;
		ms(dp, 0);
    }
    return 0;
}