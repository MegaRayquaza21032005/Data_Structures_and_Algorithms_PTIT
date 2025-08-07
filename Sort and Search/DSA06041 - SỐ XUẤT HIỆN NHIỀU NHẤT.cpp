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

int dem[1000009];
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
            dem[a[i]]++;
        }
        double limit = 1.0 * n / 2;
        int res = 0, ans = 0;
        FOR(i, 1, n)
        {
            if(dem[a[i]] > limit)
            {
                res = max(res, dem[a[i]]);
                ans = a[i];
                check = 1;
            }
        }
        if(check == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << ans << endl;
        }
        ms(dem, 0);
    }
}
 