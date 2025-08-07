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

int a[1009], n, k, check = 0;
vector<int> v;
vector<vector<int>> res;
void Try(int i, int sum)
{
    if(sum >= k)
    {
        if(sum == k)
        {
            check = 1;
            res.pb(v);
        }
        return;
    }
    if(i == n + 1) return;
    FOR(j, i, n)
    {
        v.pb(a[j]);
        Try(j, sum + a[j]);
        v.pop_back();
    }
}
int main()
{
    fast;
    int T = 1; 
    cin >> T;
    while(T--)
    {
        check = 0;
        cin >> n >> k;
        FOR(i, 1, n) cin >> a[i];
        sort(a + 1, a + n + 1);
        Try(1, 0);
        if(res.size() != 0) cout << res.size() << " ";
        for(auto v : res)
        {
            cout << "{";
            FOR(i, 0, v.size() - 1)
            {
                cout << v[i];
                if(i == v.size() - 1) cout << "} ";
                else cout << " ";
            }
        }
        if(check == 0) cout << -1;
        cout << endl;
        res = {};
        v = {};
    }
}