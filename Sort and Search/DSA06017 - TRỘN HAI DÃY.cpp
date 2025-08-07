#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
const int mod = 1e9 + 7;

int prime[10000009];
vector<int> p;
void sang()
{
    for(int i = 0; i <= 1e7; ++i)
    {
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for(int i = 2; i <= sqrt(1e7); ++i)
    {
        if(prime[i])
        {
            p.push_back(i);
            for(int j = i * i; j <= 1e7; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}
int bin_search(vector<int> p, int x)
{
    int l = 0, r = p.size() - 1, res = -1;
    while(l <= r)
    {
        int m = (l + r) / 2;
        if(p[m] < x)
        {
            res = m;
            l = m + 1;
        }
        else r = m - 1;
    }
    return res;
}
int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n, m; cin >> n >> m;
        vector<int> a(n), b (m), v;
        for(int i = 0; i < n; ++i)
        {
            int x; cin >> x;
            v.push_back(x);
        }
        for(int i = 0; i < m; ++i)
        {
            int x; cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); ++i)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
}
 