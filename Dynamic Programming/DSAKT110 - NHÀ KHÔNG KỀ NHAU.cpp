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
    cin >> T;
    while(T--)
    {
        int n; cin >> n;
        vector<int> a(n + 9), dp(n + 9);
        FOR(i, 1, n) cin >> a[i];
        dp[0] = 0;
        dp[1] = a[1];
        FOR(i, 2, n)
        {
            dp[i] = max(dp[i - 2] + a[i], dp[i - 1]);
        }
        cout << dp[n] << endl;
    }

}