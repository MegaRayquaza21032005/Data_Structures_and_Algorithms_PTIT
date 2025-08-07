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

int a[1000009];
int search(int a[], int l, int r, int x)
{
    int res = -1;
    while(l <= r)
    {
        int m = (l + r) / 2;
        if(a[m] >= x)
        {
            res = m;
            r = m - 1;
        }
        else l = m + 1;

    }
    return res;
}
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        int n, k; cin >> n >> k;
        FOR(i, 1, n)
        {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        ll cnt = 0;
        FOR(i, 1, n - 1)
        {
            int pos = search(a, i + 1, n, a[i] + k);
            if(pos == -1) cnt += (n - i);
            else
            {
                pos--;
                cnt += (pos - i);
            }
        }
        cout << cnt << endl;
    }
    return 0;
}