#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
const ll mod = 1e15 + 7;

int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        int n; cin >> n;
        vector<int> dp(n + 9);
        int i2 = 1, i3 = 1, i5 = 1;
        int x = 2, y = 3, z = 5;
        dp[1] = 1;
        FOR(i, 2, n)
        {
            int tmp = min({x, y, z});
            dp[i] = tmp;
            if(tmp == x) x = dp[++i2] * 2;
            if(tmp == y) y = dp[++i3] * 3;
            if(tmp == z) z = dp[++i5] * 5;
        }
        cout << dp[n] << endl;
    }

}