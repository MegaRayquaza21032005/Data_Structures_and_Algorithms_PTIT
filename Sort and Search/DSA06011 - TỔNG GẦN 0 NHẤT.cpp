#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
const int mod = 1e9 + 7;


int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> v(n + 9);
        for(int i = 1; i <= n; ++i)
        {
            cin >> v[i];
        }
        int m = INT_MAX, res = 0;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = i + 1; j <= n; ++j)
            {
                int x = abs(v[i] + v[j]);
                if(x < m)
                {
                    m = x;
                    res = v[i] + v[j];
                }
            }
        }
        cout << res << endl;
    }
}
 