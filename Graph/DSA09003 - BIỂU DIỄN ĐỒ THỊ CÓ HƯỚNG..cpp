#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl "\n"
const int mod = 1e9 + 7;

int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        int v, e; cin >> v >> e;
        vector<vector<int>> ke(v + 9);
        for(int i = 1; i <= e; ++i)
        {
            int a, b; cin >> a >> b;
            ke[a].push_back(b);
            //ke[b].push_back(a);
        }
        for(int i = 1; i <= v; ++i)
        {
            sort(ke[i].begin(), ke[i].end());
            cout << i << ": ";
            for(int x : ke[i]) cout << x << " ";
            cout << endl;
        }
    }
}