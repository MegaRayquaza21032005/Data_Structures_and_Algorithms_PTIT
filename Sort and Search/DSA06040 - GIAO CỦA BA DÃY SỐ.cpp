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
        int n, m, k; cin >> n >> m >> k;
        ll a[n + 9], b[m + 9], c[k + 9];
        int check = 0;
        FOR(i, 1, n) cin >> a[i];
        FOR(i, 1, m) cin >> b[i];   
        FOR(i, 1, k) cin >> c[i];
        int i = 1, j = 1, l = 1;
        while(i <= n && j <= m && l <= k)
        {
            if(a[i] == b[j] && b[j] == c[l])
            {
                check = 1;
                cout << a[i] << " ";
                ++i; ++j; ++l;
            }
            else if(a[i] < b[j]) ++i;
            else if(b[j] < c[l]) ++j;
            else ++l;
        }
        if(check == 0) cout << -1;
        cout << endl;
    }
}
 