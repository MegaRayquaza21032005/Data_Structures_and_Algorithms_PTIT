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


int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n, k; cin >> n >> k;
        vector<int> a(n + 9);
        FOR(i, 1, n) cin >> a[i];
        multiset<int> mse;
        FOR(i, 1, k) mse.insert(a[i]);
        cout << *mse.rbegin() << " ";
        FOR(i, k + 1, n)
        {
            mse.insert(a[i]);
            mse.erase(mse.find(a[i - k]));
            cout << *mse.rbegin() << " ";
        }
        cout << endl;
    }
    return 0;
}
 