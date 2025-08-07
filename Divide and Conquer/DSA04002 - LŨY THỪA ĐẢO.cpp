#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
const ll mod = 1e9 + 7;

ll reverse(ll n)
{
    ll res = 0;
    while(n != 0)
    {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}
ll binpow(ll a, ll b)
{
    if(b == 0) return 1;
    else
    {
        ll x = binpow(a, b / 2);
        x = (x % mod * x % mod) % mod;
        if(b & 1) return (x * a) % mod;
        return x;
    }
}
int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        ll r = reverse(n);
        cout << binpow(n, r) << endl;
    }
}