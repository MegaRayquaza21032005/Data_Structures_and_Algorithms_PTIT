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
    q.push("9");
    while(cnt <= 18)
    {
        string tmp = q.front();
        q.pop();
        v.pb(tmp);
        cnt = tmp.size();
        q.push(tmp + "0");
        q.push(tmp + "9");
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
        FOR(i, 0, v.size() - 1)
        {
            if(stoll(v[i]) % n == 0)
            {
                cout << v[i] << endl;
                break;
            }
        }
    }
    return 0;
}