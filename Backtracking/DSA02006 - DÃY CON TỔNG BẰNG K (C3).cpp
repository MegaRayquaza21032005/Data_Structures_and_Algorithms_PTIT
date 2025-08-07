#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define pi pair<int, int>
#define ms(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
const int mod = 1e9 + 7;
const ll llmod = 1e15 + 7;

int a[10009], n, k, check = 0;
int res = INT_MAX;

void Try(int i, int sum, vector<int> &v)
{
    if(sum >= k)
    {
        if(sum == k)
        {
            check = 1;
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
    for(int j = i; j <= n; ++j)
    {
        if(sum + a[j] > k) break;
        v.pb(a[j]);
        Try(j + 1, sum + a[j], v);
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
        cin >> n >> k;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        check = 0;
        vector<int> v;
        Try(1, 0, v);
        if(check == 0) cout << -1;
        cout << endl;
    }
    
}