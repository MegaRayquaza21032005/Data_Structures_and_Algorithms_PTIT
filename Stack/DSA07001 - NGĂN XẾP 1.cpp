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
    vector<int> v;
    string s;
    while(cin >> s)
    {
        if(s == "push")
        {
            int x; cin >> x;
            v.pb(x);
        }
        else if(s == "pop")
        {
            if(v.size() != 0) v.pop_back();
        }
        else
        {
            if(v.size() == 0) cout << "empty" << endl;
            else
            {
                for(auto x : v) cout << x << " ";
                cout << endl;
            }
        }
    }
    return 0;
}