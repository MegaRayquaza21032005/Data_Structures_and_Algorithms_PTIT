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

int a[10009], n, k, final = 0;

void Try(int i, int sum, vector<int> &v)
{
    if(i > n)
    {
        if(sum == k)
        {
            final = 1;
            cout << "[";
            for(int i = 0; i < v.size(); ++i)
            {
                cout << v[i];
                if(i == v.size() - 1)
                {
                    cout << "] ";
                }
                else cout << " ";
                
            }
        }
        return;
    }
    v.pb(a[i]);
    Try(i + 1, sum + a[i], v);
    v.pop_back();
    Try(i + 1, sum, v);
}
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        final = 0;
        cin >> n >> k;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        vector<int> v;
        Try(1, 0, v);
        if(final == 0) cout << -1;
        v = {};
        cout << endl;
    }
    
}