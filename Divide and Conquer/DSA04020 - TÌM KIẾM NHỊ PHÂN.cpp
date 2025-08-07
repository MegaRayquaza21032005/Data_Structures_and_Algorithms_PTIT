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

int a[1000009];
int bin_search(int a[], int n, int k)
{
    int l = 1, r = n, res = -1;
    while(l <= r)
    {
        int m = (l + r) / 2;
        if(a[m] == k)
        {
            res = m;
            break;
        }
        else if(a[m] < k)
        {
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
        int n, k;
        cin >> n >> k;
        FOR(i, 1, n) cin >> a[i];
        int tmp = bin_search(a, n, k);
        if(tmp == -1) cout << "NO" << endl;
        else cout << tmp << endl;
    }
}