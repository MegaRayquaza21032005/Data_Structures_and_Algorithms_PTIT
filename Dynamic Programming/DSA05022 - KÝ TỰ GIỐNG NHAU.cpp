#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
#define pi pair<int, int>
const int mod = 1e9 + 7;
const ll llmod = 1e15 + 7;

/*
dp[0] = 0: không có ký tự thì không tốn thời gian.

dp[1] = X: chỉ cần insert 1 lần.

Với mỗi i từ 2 đến N, ta xét các cách sau:

    Insert: dp[i] = dp[i - 1] + X

    Copying: nếu i là chẵn, có thể tạo từ i/2 bằng cách nhân đôi, nên dp[i] = min(dp[i], dp[i/2] + Z)

    Copying và xóa: nếu i là lẻ, có thể nhân đôi i/2, rồi xóa 1 ký tự: dp[i] = min(dp[i], dp[(i+1)/2] + Z + Y)
*/
int dp[1000009];
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while (T--)
    {
        int n, x, y, z;
        cin >> n >> x >> y >> z;
        dp[0] = 0;
        dp[1] = x;
        for (int i = 2; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + x;
            if (i % 2 == 0)
            {
                dp[i] = min(dp[i], dp[i / 2] + z);
            }
            else
            {
                dp[i] = min(dp[i], dp[(i + 1) / 2] + y + z);
            }
        }
        cout << dp[n] << endl;
        memset(dp, 0, sizeof(dp));
    }
    return 0;
}