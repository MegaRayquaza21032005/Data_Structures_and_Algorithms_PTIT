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
        vector<int> a(n + 9);
        ll res = 0;
        for(int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            cnt[a[i]]++;
        }
        sort(a.begin() + 1, a.begin() + n + 1);
        int l = 1, r = n;
        while(l < r)
        {
            if(a[l] + a[r] == k)
            {
                if(a[l] != a[r])
                {
                    res += 1ll * cnt[a[l]] * cnt[a[r]];
                    while(a[l] == a[l + 1]) ++l;
                    ++l;
                    while(a[r] == a[r - 1]) --r;
                    --r;
                }
                else
                {
                    res += 1ll * cnt[a[l]] * (cnt[a[l]] - 1) / 2;
                    break;
                }
            }
            else if(a[l] + a[r] < k) l++;
            else r--;
        }
        cout << res << endl;
        memset(cnt, 0, sizeof(cnt));
    }
    return 0;
}
 