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

int a[1009], n, k, test = 0, ans = INT_MAX;
vector<vector<int>> res;


void Try(int i, int cnt)
{
    if(cnt > ans) return;
    if(i == 1)
    {
        ans = min(ans, cnt);
        return;
    }
    if(i % 2 == 0)
    {
        Try(i / 2, cnt + 1);
    }
    if(i % 3 == 0)
    {
        Try(i / 3, cnt + 1);
    }
    Try(i - 1, cnt + 1);
}
int main()
{
    fast;
    int T = 1; 
    cin >> T;
    while(T--)
    {
        ans = INT_MAX;
        cin >> n;
        Try(n, 0);
        if(n != 1) cout << ans << endl;
        else cout << 1 << endl;
    }
}