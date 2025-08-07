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

/*
Ý tưởng:

*/
ll binpow(ll a, ll b)
{
    if(b == 0) return 1;
    else
    {
        ll x = binpow(a, b / 2) % 123456789;
        x *= x;
        x %= 123456789;
        if(b & 1) return x * (a % 123456789) % 123456789;
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
        cout << binpow(2, n - 1) << endl;
    }
}
 