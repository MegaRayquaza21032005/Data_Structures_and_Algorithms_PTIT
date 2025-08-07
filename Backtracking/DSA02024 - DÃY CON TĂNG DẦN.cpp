#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
const int mod = 1e9 + 7;

int a[1009], n, k, check = 0, sum;
vector<string> res;
vector<int> v;

void Try(int i, int x)
{
    if(v.size() >= 2)
    {
        string s = "";
        for(auto x : v) s += to_string(x) + " ";
        res.pb(s);
    }
    if(i == n) return;
    else
    {
        for(int j = i + 1; j <= n; ++j)
        {
            if(a[j] >= x)
            {
                v.pb(a[j]);
                Try(j, a[j]);
                v.pop_back();
            }
        }
    }
}
int main()
{
    fast;
    int T = 1;
    //cin >> T;
    while(T--)
    {
        cin >> n;
        for(int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        Try(0, 0);
        sort(res.begin(), res.end());
        for(auto v : res)
        {
            cout << v << endl;
        }
    }
}