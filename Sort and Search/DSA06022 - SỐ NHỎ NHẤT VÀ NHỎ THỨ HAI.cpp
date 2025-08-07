#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
const int mod = 1e9 + 7;

bool bin_search(vector<int> a, int x)
{
    int l = 0, r = a.size() - 1;
    while(l <= r)
    {
        int m = (l + r) / 2;
        if(a[m] == x) return true;
        else if(a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return false;
}
int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n, m; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int m1 = a[0], m2 = -1;
        for(int i = 1; i < n; ++i)
        {
            if(a[i] != m1)
            {
                m2 = a[i];
                break;
            }
        }
        if(m2 == -1) cout << -1 << endl;
        else cout << m1 << " " << m2 << endl;
    }
}
 