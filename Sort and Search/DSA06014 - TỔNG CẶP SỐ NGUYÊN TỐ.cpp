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
    for(int i = 0; i <= 1e6; ++i)
    {
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for(int i = 2; i <= 1000; ++i)
    {
        if(prime[i])
        {
            p.push_back(i);
            for(int j = i * i; j <= 1e6; j += i)
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
    sang();
    // for(int x : p) cout << x << " ";
    // cout << bin_search(p, 7);
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n, check = 0; cin >> n;
        for(int i = 2; i <= n; ++i)
        {
            if(prime[i] && prime[n - i])
            {
                cout << i << " " << n - i << endl;
                check = 1;
                break;
            }
        }
        if(check == 0) cout << -1 << endl;
    }
}
 