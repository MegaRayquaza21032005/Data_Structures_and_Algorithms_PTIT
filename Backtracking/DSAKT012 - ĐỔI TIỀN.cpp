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

int a[1009], n, k, test = 0, ans = INT_MAX, check = 0;
vector<string> res;


void Try(int i, int cnt, int sum)
{
    if(cnt > ans) return;
    if(sum == k)
    {
        check = 1;
        ans = min(ans, cnt);
        return;
    }
    if(sum > k) return;
    FOR(j, i + 1, n)
    {
        if(sum + a[j] <= k)
        {
            Try(j, cnt + 1, sum + a[j]);
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
        ans = INT_MAX;
        cin >> n >> k;
        FOR(i, 1, n) cin >> a[i];
        sort(a + 1, a + n + 1, greater<int>());
        Try(0, 0, 0);
        if(check == 0) cout << -1 << endl;
        else cout << ans << endl;
    }
}