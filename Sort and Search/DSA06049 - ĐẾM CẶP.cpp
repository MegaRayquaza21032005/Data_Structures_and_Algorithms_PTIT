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

int bin_search(int a[], int l, int r, int x, int k)
{
    int res = -1;
    while(l <= r)
    {
        int m = (l + r) / 2;
        if(a[m] - x < k)
        {
            res = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return res;
}
int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n, k; cin >> n >> k;
        int a[n + 9];
        ll cnt = 0;
        FOR(i, 1, n)
        {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        FOR(i, 1, n)
        {
            int x = bin_search(a, i + 1, n, a[i], k);
            if(x != -1)
            {
                cnt += (x - i);
            }
        }
        cout << cnt << endl;
    }
}
 