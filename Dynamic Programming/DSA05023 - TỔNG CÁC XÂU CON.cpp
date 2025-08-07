#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
#define pi pair<int, int>
const int mod = 1e9 + 7;
const ll llmod = 1e15 + 7;

int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        string s; cin >> s;
        ll res = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            for(int j = 0; j <= i; ++j)
            {
                res += stoll(s.substr(j, i - j + 1));
            } 
        }
        cout << res << endl;
    }
    return 0;
}