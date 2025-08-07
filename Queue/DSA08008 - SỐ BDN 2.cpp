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

void binary_number()
{
    queue<ll> q;
    q.push(0);
    q.push(1);
    while(q.front() * 10 <= (ll) 5e18)
    {
        ll tmp = q.front();
        q.pop();
        v.pb(tmp);
        if(tmp == 0) continue;
        q.push(tmp * 10);
        q.push(tmp * 10 + 1);
    }
}
int main()
{
    fast;
    int T; cin >> T;
    binary_number();
    while(T--)
    {
        ll n; cin >> n;
        ll cnt = 0;
        FOR(i, 1, v.size() - 1)
        {
            if(v[i] % n == 0)
            {
                cout << v[i] << endl;
                break;
            }
        }
    }
    return 0;
} 