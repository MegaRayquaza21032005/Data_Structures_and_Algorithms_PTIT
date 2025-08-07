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
        int n, m, k; cin >> n;
        ll a[n + 9];
        int check = 0;
        FOR(i, 1, n)
        {
            cin >> a[i];
            dp[i] = dp[i - 1] + a[i];
        }
        FOR(i, 1, n)
        {
            if(dp[i - 1] == dp[n] - dp[i])
            {
                cout << i << endl;
                check = 1;
                break;
            }
        }
        if(!check)
        {
            cout << "-1" << endl;
        }
    }
}
 