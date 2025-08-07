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
const ll llmod = 1e15 + 7;

int dp[1009][1009];
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        int n; cin >> n;
        vector<int> a(n + 9), v;
        FOR(i, 1, n) cin >> a[i];
        FOR(i, 1, n)
        {
            auto it = upper_bound(v.begin(), v.end(), a[i]);
            if(it == v.end()) v.pb(a[i]);
            else *it = a[i];
        }
        cout << n - v.size() << endl;
    }
    
    return 0;
}