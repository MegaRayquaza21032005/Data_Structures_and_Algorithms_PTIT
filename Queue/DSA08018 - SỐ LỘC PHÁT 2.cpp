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

vector<string> v;
ll len[1009];
void solocphat()
{
    queue<string> q;
    int len = 0;
    q.push("6");
    q.push("8");
    while(len <= 15)
    {
        string s = q.front(); q.pop();
        len = s.size();
        v.pb(s);
        q.push(s + "6");
        q.push(s + "8");
    }
    
}
int main()
{
    fast;
    int T; cin >> T;
    v.pb("NULL");
    solocphat();
    len[1] = 2;
    len[2] = 6;
    FOR(i, 3, 15)
    {
        len[i] = len[i - 1] + (len[i - 1] - len[i - 2]) * 2;
    }
    while(T--)
    {
        int n; cin >> n;
        cout << len[n] << endl;
        FOR(i, 1, len[n]) cout << v[i] << " ";
        cout << endl;
    }
    return 0;
} 