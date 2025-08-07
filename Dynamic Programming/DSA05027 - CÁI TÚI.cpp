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

int w[1000009], v[1000009], dp[1009][1009];
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        int n, S; cin >> n >> S;
        FOR(i, 1, n) cin >> w[i];
        FOR(i, 1, n) cin >> v[i];
        FOR(i, 1, n)
        {
            FOR(j, 1, S)
            {
                dp[i][j] = dp[i - 1][j];
                if(j >= w[i])
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
                }
            }
        }
        cout << dp[n][S] << endl;
    }
}

/*
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

ll dp[1009][1009];
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        int n, S; cin >> n >> S;
        vector<int> w(n + 9), v(n + 9);
        FOR(i, 1, n) cin >> w[i];
        FOR(i, 1, n) cin >> v[i];
        FOR(i, 0, n)
        {
            FOR(j, 0, S)
            {
                if(i == 0 || j == 0) dp[i][j] = 0;
                else
                {
                    if(j < w[i]) dp[i][j] = dp[i - 1][j];
                    else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
                }
            }
        }
        cout << dp[n][S] << endl;
        ms(dp, 0);
    }

}
*/
