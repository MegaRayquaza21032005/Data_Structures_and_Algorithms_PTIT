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

ll binpow(ll a, ll b)
{
    ll res = 1;
    while(b != 0)
    {
        if(b & 1)
        {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1; // b /= 2;
    }
    return res;
}
int main()
{
    fast;
    ll a, b;
    while(cin >> a >> b)
    {
        if(a == 0 && b == 0) break;
        cout << binpow(a, b) << endl;
    }
    return 0;
}