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

int main()
{
    fast;
    int T = 1;
    //cin >> T;
    while(T--)
    {
        int n, S; cin >> n >> S;
        vector<int> a(n + 9), dp(S + 9, 1e9);
        FOR(i, 1, n) cin >> a[i];
        dp[0] = 0;
        FOR(i, 1, n)
        {
            FOR(j, a[i], S)
            {
                dp[j] = min(dp[j], dp[j - a[i]] + 1);
            }
        }
        cout << (dp[S] == 1e9 ? -1 : dp[S]) << endl;
    }

}
