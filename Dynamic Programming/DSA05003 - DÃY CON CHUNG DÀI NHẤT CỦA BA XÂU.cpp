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

int dp[109][109][109];
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        int n, m, p; cin >> n >> m >> p;
        string s1, s2, s3; cin >> s1 >> s2 >> s3;
        s1 = " " + s1;
        s2 = " " + s2;
        s3 = " " + s3;
        FOR(i, 1, n)
        {
        	FOR(j, 1, m)
        	{
        		FOR(k, 1, p)
        		{
        			if(s1[i] == s2[j] && s2[j] == s3[k]) dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
        			else dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
				}
			}
		}
		cout << dp[n][m][p] << endl;
		ms(dp, 0);
    }
    return 0;
}

