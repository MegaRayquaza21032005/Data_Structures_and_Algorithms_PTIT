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

int a[1009], n, k, test = 0, ans = INT_MAX;
vector<string> res;


void Try(int i, const string &s, string tmp)
{
    if(tmp.size() >= 1)
    {
        res.pb(tmp);
    }
    FOR(j, i, n - 1)
    {
        tmp += s[j];
        Try(j + 1, s, tmp);
        tmp.pop_back();
    }
}
int main()
{
    fast;
    int T = 1; 
    cin >> T;
    while(T--)
    {
        cin >> n;
        string s; cin >> s;
        Try(0, s, "");
        //sort(res.begin(), res.end());
        for(string s : res) cout << s << " ";
        cout << endl;
        res = {};
    }
}