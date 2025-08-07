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
        int n, k; cin >> n >> k;
        vector<int> v(n + 9);
        for(int i = 1; i <= n; ++i)
        {
            cin >> v[i];
        }
        sort(v.begin() + 1, v.begin() + n + 1, greater<int>());
        for(int i = 1; i <= k; ++i) cout << v[i] << " ";
        cout << endl;
    }
}
 