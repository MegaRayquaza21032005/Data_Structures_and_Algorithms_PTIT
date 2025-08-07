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
        string s1, s2; cin >> s1 >> s2;
        int n = s1.size(), m = s2.size();
        s1 = "@" + s1;
        s2 = "@" + s2;
        FOR(i, 1, n) dp[i][0] = 0;
        FOR(i, 1, m) dp[0][i] = 0;
        FOR(i, 1, n)
        {
            FOR(j, 1, m)
            {
                if(s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        cout << dp[n][m] << endl;
        ms(dp, 0);
    }
    
    return 0;
}