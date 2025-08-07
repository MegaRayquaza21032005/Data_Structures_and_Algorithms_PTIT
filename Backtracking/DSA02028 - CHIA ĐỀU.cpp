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

int a[1009], n, k, ans = INT_MAX, check = 0, sum = 0, dem = 0;
int dp[1009];


void Try(int i, int cnt)
{
    if(cnt == k)
    {
        if(i == n) dem++;
        return;
    }
    FOR(j, i + 1, n)
    if(dp[j] - dp[i] == sum)
    {
        Try(j, cnt + 1);
    }
}
int main()
{
    fast;
    int T = 1; 
    //cin >> T;
    while(T--)
    {
        dem = 0;
        cin >> n >> k;
        FOR(i, 1, n)
        {
            cin >> a[i];
            dp[i] = dp[i - 1] + a[i];
        }
        if(dp[n] % k != 0) cout << 0 << endl;
        else
        {
            sum = dp[n] / k;
            Try(0, 0);
            cout << dem << endl;
        }
    }
}

/*
int a[10009], pre[10009], n, k, sum = 0, res = 0;

void Try(int i, int cnt)
{
    if(cnt == k)
    {
        if(i == n + 1) res++;
        return;
    }
    for(int j = i; j <= n; ++j)
    {
        if(pre[j] - pre[i - 1] == sum)
        {
            Try(j + 1, cnt + 1);
        }
    }
}
int main()
{
    fast;
    int T = 1;
    //cin >> T;
    while(T--)
    {
        cin >> n >> k;
        res = sum = 0;
        for(int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            sum += a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        if(sum % k != 0)
        {
            cout << 0 << endl;
        }
        else
        {
            sum /= k;
            Try(1, 0);
            cout << res << endl;
        }
    }
    
}
*/