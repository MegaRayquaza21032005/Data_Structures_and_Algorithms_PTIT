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

/*
ý tưởng: giống bài coin 2 - leetcode
*/
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        int n, k; cin >> n >> k;
        vector<int> a(n + 9), dp(k + 9, 0); // dp[i]: số cách để tạo ra tổng = i
        for(int i = 1; i <= n; ++i) cin >> a[i];
        dp[0] = 1;
        for(int i = 1; i <= k; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(i >= a[j])
                {
                    dp[i] += dp[i - a[j]];
                    dp[i] %= mod;
                }
            }
        }
        cout << dp[k] << endl;
    }
    return 0;
}