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


void Try(int i, int sum, vector<int> &v)
{
    if(sum == n) res.pb(v);
    if(sum > n) return;
    FORD(j, i, 1)
    {
        v.pb(j);
        Try(j, sum + j, v);
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
        cin >> n;
        vector<int> v;
        Try(n, 0, v);
        cout << res.size() << endl;
        for(auto v : res)
        {
            cout << "(";
            FOR(i, 0, v.size() - 1)
            {
                cout << v[i];
                if(i == v.size() - 1) cout << ") ";
                else cout << " ";
            }
        }
        cout << endl;
        res = {};
        v = {};
    }
}