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

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n, k; cin >> n >> k;
        unordered_map<int, int> mp;
        ll cnt = 0;
        FOR(i, 1, n)
        {
            int x; cin >> x;
            ++mp[x];
        }
        for(auto it : mp)
        {
            if(k - it.first != it.first)
            {
                if(mp.find(k - it.first) != mp.end())
                {
                    cnt += 1ll * it.second * mp[k - it.first];
                    mp[k - it.first] = 0;
                    mp[it.first] = 0;
                }
            }
            else
            {
                cnt += 1ll * it.second * (it.second - 1) / 2;
                mp[it.first] = 0;
            }
        }
        cout << cnt << endl;
    }
}
 