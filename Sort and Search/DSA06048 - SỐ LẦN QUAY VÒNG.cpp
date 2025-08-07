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
        int n; cin >> n;
        ll a[n + 9];
        int cnt = 1;
        FOR(i, 1, n)
        {
            cin >> a[i];
        }
        FOR(i, 2, n)
        {
            if(a[i] >= a[i - 1]) ++cnt;
            else break;
        }
        if(cnt != n) cout << cnt << endl;
        else cout << 0 << endl;
    }
}
 