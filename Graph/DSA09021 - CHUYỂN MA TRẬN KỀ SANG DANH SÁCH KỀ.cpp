#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl "\n"
const int mod = 1e9 + 7;

int a[1009][1009];
void input(int v)
{
    for(int i = 1; i <= v; ++i)
    {
        for(int j = 1; j <= v; ++j)
        {
            cin >> a[i][j];
        }
    }
}
int main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int v;
        cin >> v;
        input(v);
        vector<vector<int>> ke(v + 9);
        for(int i = 1; i <= v; ++i)
        {
            for(int j = 1; j <= v; ++j)
            {
                if(a[i][j] == 1)
                {
                    ke[i].push_back(j);
                }
            }
        }
        for(int i = 1; i <= v; ++i)
        {
            if(ke[i].size() != 0)
            {
                for(int x : ke[i]) cout << x << " ";
                cout << endl;
            }
        }
    }
}