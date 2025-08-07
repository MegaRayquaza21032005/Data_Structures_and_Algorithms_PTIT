#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
const int mod = 1e9 + 7;

ll luythua(ll a, ll b)
{
    ll res = 1;
    while(b > 0)
    {
        if(b % 2 == 1)
        {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        b /= 2;
    }
    return res;
}
int main()
{
    fast;
    int t; cin >> t;
    while(t--)
    {
        ll a, b;
        cin >> a >> b;
        cout << luythua(a, b) << endl;
    }
    return 0;
}
 