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

int a[1009], n, k, test = 0;
vector<vector<int>> res;

bool prime(int n)
{
    if(n < 2) return false;
    FOR(i, 2, sqrt(n))
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void Try(int i, int sum, vector<int> &v)
{
    if(prime(sum)) res.pb(v);
    if(i > n) return;
    else
    {
        FOR(j, i + 1, n)
        {
            v.pb(a[j]);
            Try(j, sum + a[j], v);
            v.pop_back();
        }
    }
}
int main()
{
    fast;
    int T = 1; 
    cin >> T;
    while(T--)
    {
        cin >> n;
        FOR(i, 1, n) cin >> a[i];
        sort(a + 1, a + n + 1, greater<int>());
        vector<int> v;
        Try(0, 0, v);
        sort(res.begin(), res.end());
        for(auto v : res)
        {
            for(auto x : v) cout << x << " ";
            cout << endl;
        }
        res = {};
        v = {};
    }
}