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

int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        int check = 0;
        ll n, k; cin >> n >> k;
        vector<ll> a(n), v;
        for(int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sort(a.begin() ,a.end());
        ll ans = 0;
        for(int i = 0; i < n - 2; ++i)
        {
            int l = i + 1, r = n - 1;
            while(l < r)
            {
                ll x = a[i] + a[l] + a[r];
                if(x == k)
                {
                    check = 1;
                    break;
                }
                else if(x < k) ++l;
                else --r;
            }
        }
        if(check == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
 