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

int dp[10000009];
int main()
{
    fast;
    int t = 1;
    //cin >> t;
    while(t--)
    {
        int n, m, k; cin >> n;
        ll a[n + 9];
        vector<int> odd, even;
        FOR(i, 1, n)
        {
            int x; cin >> x;
            if(i & 1)
            {
                odd.pb(x);
            }
            else
            {
                even.pb(x);
            }
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end(), greater<int>());
        int i = 0, j = 0;
        while(i < odd.size() && j < even.size())
        {
            cout << odd[i++] << ' ' << even[j++] << " ";
        }
        if(n & 1)
        {
            cout << odd[j++] << " ";
        }
        cout << endl;
    }
}
 