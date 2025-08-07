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
        vector<int> a(n + 9);
        vector<ll> dp(n + 9);
        FOR(i, 1, n)
        {
            cin >> a[i];
            dp[i] = a[i];
        }
        FOR(i, 1, n)
        {
            FOR(j, 1, i - 1)
            {
                if(a[j] < a[i])
                {
                    dp[i] = max(dp[i], dp[j] + a[i]);
                }
            }
        }
        cout << *max_element(dp.begin() + 1, dp.begin() + n + 1) << endl;
    }

}
