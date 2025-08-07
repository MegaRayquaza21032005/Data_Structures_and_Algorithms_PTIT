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

int dp[1009][1009];
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        string s; cin >> s;
        int n = s.size();
        s = " " + s;
        FOR(i, 1, n) dp[i][i]  = 1;
        int res  = 1;
        for(int len = 2; len <= n; ++len)
        {
            FOR(i, 1, n - len + 1)
            {
                int j = i + len - 1;
                if(len == 2)
                {
                    if(s[i] == s[j])
                    {
                        dp[i][j] = 1;
                        res = len;
                    }
                }
                else
                {
                    if(s[i] == s[j] && dp[i + 1][j - 1] == 1)
                    {
                        dp[i][j] = 1;
                        res = len;
                    }
                }
            }
        }
        cout << res << endl;
        ms(dp, 0);
    }
    return 0;
}