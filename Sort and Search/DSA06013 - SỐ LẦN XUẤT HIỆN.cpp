#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
const int mod = 1e9 + 7;

int cnt[10000009];
int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n, k; cin >> n >> k;
        vector<int> v(n + 9);
        for(int i = 1; i <= n; ++i)
        {
            cin >> v[i];
            cnt[v[i]]++;
        }
        if (cnt[k] != 0) cout << cnt[k] << endl;
        else cout << -1 << endl;
        memset(cnt, 0, sizeof(cnt));
    }
}
 