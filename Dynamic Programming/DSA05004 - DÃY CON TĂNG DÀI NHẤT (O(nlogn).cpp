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
    //cin >> T;
    while(T--)
    {
        int n; cin >> n;
        vector<int> a(n + 9);
        FOR(i, 1, n) cin >> a[i];
        vector<int> v;
        v.pb(a[1]);
        FOR(i, 2, n)
        {
            if(a[i] > *v.rbegin())
            {
                v.pb(a[i]);
            }
            else
            {
                int pos = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
                v[pos] = a[i];
            }
        }
        cout << v.size() << endl;
    }

}


/*
FOR(i, 1, n)
{
    auto it = lower_bound(v.begin(), v.end(), a[i]);
    if(it == v.end())
    {
        v.pb(a[i]);
    }
    else
    {
        *it = a[i];
    }
}
*/
