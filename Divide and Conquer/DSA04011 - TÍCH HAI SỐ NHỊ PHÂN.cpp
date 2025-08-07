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

int convert(string s)
{
    int ans = 0;
    int power = 1;
    reverse(s.begin(), s.end());
    for(char x : s)
    {
        ans += (x - '0') * power;
        power *= 2;
    }
    return ans;
}
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        string a, b; cin >> a >> b;
        ll res = 1ll * convert(a) * convert(b);
        cout << res << endl;
    }
    return 0;
}