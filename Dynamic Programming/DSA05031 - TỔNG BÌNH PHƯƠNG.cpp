#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
#define pi pair<int, int>
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
        vector<int> dp(n + 9, 1e9);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i)
        {
            int root = sqrt(i);
            for(int j = root; j >= 1; --j)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}