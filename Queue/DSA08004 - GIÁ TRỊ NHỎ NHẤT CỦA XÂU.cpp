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

int dem[1009];
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        int k; cin >> k;
        string s; cin >> s;
        priority_queue<int> pq;
        for(char x : s) dem[x]++;
        FOR(i, 65, 90)
        {
            if(dem[i] != 0) pq.push(dem[i]);
        }
        while(k-- && !pq.empty())
        {
            int x = pq.top();
            pq.pop();
            --x;
            if(x > 0) pq.push(x);
        }
        ll res = 0;
        while(!pq.empty())
        {
            int x = pq.top(); pq.pop();
            res += 1ll * x * x;
        }
        cout << res << endl;  
        memset(dem, 0, sizeof(dem));
    }  
    return 0;
}