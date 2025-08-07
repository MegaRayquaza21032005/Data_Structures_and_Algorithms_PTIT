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

ll Find(ll n, ll k)
{
    if(n == 1) return 1;
    ll tmp = pow(2, n - 1);
    if(k == tmp) return n;
    else if(k < tmp) return Find(n - 1, k);
    else return Find(n - 1, k - tmp);
}
int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        ll n, k;
        cin >> n >> k;
        cout << Find(n, k) << endl;
    }
}