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
        vector<ll> dp1(n + 9), dp2(n + 9);
        FOR(i, 1, n)
        {
            cin >> a[i];
            dp1[i] = a[i];
            dp2[i] = a[i];
        }
        FOR(i, 1, n)
        {
            FOR(j, 1, i - 1)
            {
                if(a[j] < a[i])
                {
                    dp1[i] = max(dp1[i], dp1[j] + a[i]);
                }
            }
        }
        FORD(i, n, 1)
        {
            FORD(j, n, i + 1)
            {
                if(a[j] < a[i])
                {
                    dp2[i] = max(dp2[i], dp2[j] + a[i]);
                }
            }
        }
        ll res = INT_MIN;
        FOR(i, 1, n)
        {
            res = max(res, dp1[i] + dp2[i] - a[i]);
        }
        cout << res << endl;
    }

}
