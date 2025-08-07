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
        for(int i = 0; i < n; ++i) cin >> v[i];
        sort(v.begin(), v.begin() + n);
        int l = 0, r = n - 1;
        while(l <= r)
        {
            if(l != r) cout << v[r] << " " << v[l] << " ";
            else cout << v[r] << " ";
            r--; l++;
        }
        cout << endl;
    }
    return 0;
}
 