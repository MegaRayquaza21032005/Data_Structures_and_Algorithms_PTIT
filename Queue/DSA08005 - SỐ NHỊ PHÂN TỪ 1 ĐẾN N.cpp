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

void binary_number()
{
    queue<string> q;
    int cnt = 0;
    q.push("0");
    q.push("1");
    while(cnt <= 16)
    {
        string tmp = q.front();
        q.pop();
        v.pb(tmp);
        cnt = tmp.size();
        if(tmp == "0") continue;
        q.push(tmp + "0");
        q.push(tmp + "1");
    }
}
int main()
{
    fast;
    int T; cin >> T;
    binary_number();
    while(T--)
    {
        int n; cin >> n;
        FOR(i, 1, n) cout << v[i] << " ";
        cout << endl;
    }
    return 0;
} 