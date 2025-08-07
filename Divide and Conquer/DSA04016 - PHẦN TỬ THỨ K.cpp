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

int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> v;
        FOR(i, 1, n)
        {
            int x; cin >> x;
            v.pb(x);
        }
        FOR(i, 1, m)
        {
            int x; cin >> x;
            v.pb(x);
        }
        sort(v.begin(), v.end());
        cout << v[k - 1] << endl;
    }
}