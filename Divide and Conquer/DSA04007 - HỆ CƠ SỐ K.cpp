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

int convert(string s, int k)
{
    int ans = 0;
    int power = 1;
    reverse(s.begin(), s.end());
    for(char x : s)
    {
        ans += (x - '0') * power;
        power *= k;
    }
    return ans;
}
string to_base(int n, int k)
{
    string ans = "";
    while(n > 0)
    {
        int r = n % k;
        if(r < 10) ans += (char)(r + '0');
        else ans += (char)(r - 10 + 'A');
        n /= k;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        int k; cin >> k;
        string a, b; cin >> a >> b;
        int res = convert(a, k) + convert(b, k);
        cout << to_base(res, k) << endl;
    }
    return 0;
}