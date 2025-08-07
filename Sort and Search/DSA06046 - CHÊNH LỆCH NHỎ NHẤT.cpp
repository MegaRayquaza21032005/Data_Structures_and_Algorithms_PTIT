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

int dp[10000009];
int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int a[n + 9];
        FOR(i, 1, n)
        {
            cin >> a[i];
        }
        int res = INT_MAX;
        sort(a + 1, a + n + 1);
        FOR(i, 2, n)
        {
            res = min(res, a[i] - a[i - 1]);
        }
        cout << res << endl;
    }
}
 