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

int n, k, a[1009], p, sum = 0;
int dp[1009];
vector<int> tmp;
vector<vector<int>> res;

int prime[1009];
void sang()
{
    for(int i = 2; i <= 1000; ++i)
    {
        prime[i] = 1;
    }
    for(int i = 2; i <= sqrt(1000); ++i)
    {
        if(prime[i] == 1)
        {
            for(int j = i * i; j <= 1000; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}

void Try(int i, int sum, const vector<int> &v, int index)
{
    if(sum > k) return;
    if(sum == k)
    {
        if(tmp.size() == n)
        {
            res.pb(tmp);
        }
        return;
    }
    else
    {
        for(int j = index; j < v.size(); ++j)
        {
            tmp.pb(v[j]);
            Try(i + 1, sum + v[j], v, j + 1);
            tmp.pop_back();
        }
    }
}
int main()
{
    fast;
    int T = 1; 
    sang();
    cin >> T;
    while(T--)
    {
        cin >> n >> p >> k;
        vector<int> v;
        for(int i = p + 1; i <= k; ++i)
        {
            if(prime[i]) v.pb(i);
        }
        //cout << "Test " << x << ": " << endl;
        Try(0, 0, v, 0);
        cout << res.size() << endl;
        for(auto v : res)
        {
            for(auto x : v)
            {
                cout << x << " ";
            }
            cout << endl;
        }
        res.clear();
    }
}