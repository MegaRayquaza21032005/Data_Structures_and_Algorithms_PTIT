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
        multiset<int> mse;
        for(int i = 0; i < n; ++i)
        {
            int x; cin >> x;
            mse.insert(x);
        }
        for(auto x : mse) cout << x << " ";
        cout << endl;
    }
    return 0;
}
 