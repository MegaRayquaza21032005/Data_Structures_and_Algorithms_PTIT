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
const ll llmod = 1e15 + 7;

vector<ll> v;

string process(string s)
{
    string tmp;
    for(ll x : v)
    {
        tmp = to_string(x);
        int i = 0;
        FOR(j, 0, s.size() - 1)
        {
            if(s[j] == tmp[i]) ++i;
        }
        if(i == tmp.size()) return tmp;
    }
    return to_string(-1);
}
int main()
{
    fast;
    int T; cin >> T;
    FORD(i, 100, 0) v.pb(1ll * i * i * i);
    while(T--)
    {
        string s; cin >> s;
        cout << process(s) << endl;
    }
    return 0;
} 