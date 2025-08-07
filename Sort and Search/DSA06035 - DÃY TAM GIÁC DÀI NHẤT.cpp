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
        int n, k; cin >> n;
        vector<int> a (n + 9), inc(n + 9), dec(n + 9);
        FOR(i, 1, n)
        {
            cin >> a[i];
        }
        inc[1] = 1, dec[n] = 1;
        FOR(i, 2, n)
        {
            if(a[i] > a[i - 1]) inc[i] = inc[i - 1] + 1;
            else inc[i] = 1;
        }
        FORD(i, n - 1, 1)
        {
            if(a[i] > a[i + 1]) dec[i] = dec[i + 1] + 1;
            else dec[i] = 1;
        }
        int res = 0;
        FOR(i, 1, n)
        {
            res = max(res, dec[i] + inc[i] - 1);
        }
        cout << res << endl;
    }
}
 