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

/*
BT: có bao nhiêu cách để tạo ra mệnh giá S từ n đồng xu
note: quan tâm đến thứ tự
2 + 2 + 5 != 2 + 5 + 2 != 5 + 2 + 2
=> dp[i] = dp[i - a[j]] + dp[i - a[j] - a[j]] + ... + dp[i - a[j] - ... - a[j]]
*/
int main()
{
    fast;
    int T = 1;
    //cin >> T;
    while(T--)
    {
        int n, S; cin >> n >> S;
        vector<int> a(n + 9), dp(S + 9, 0);
        FOR(i, 1, n) cin >> a[i];
        dp[0] = 1;
        FOR(i, 1, S)
        {
            FOR(j, 1, n)
            {
                if(a[j] <= i)
                {
                    dp[i] += dp[i - a[j]];
                    dp[i] %= mod;
                }
            }
        }
        cout << dp[S] << endl;
    }

}
