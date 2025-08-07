#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
const int mod = 1e9 + 7;

int cnt[10000009];
int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n, k; cin >> n;
        vector<int> a(n + 9);
        string s = "";
        for(int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            s += to_string(a[i]);
        }
        set<char> se;
        for(char x : s)
        {
            se.insert(x);
        }
        for(auto x : se) cout << x << " ";
        cout << endl;
    }
    return 0;
}
 