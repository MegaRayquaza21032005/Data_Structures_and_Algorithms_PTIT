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


int main()
{
    fast;
    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        deque<int> dq;
        while(n--)
        {
            int q; cin >> q;
            if(q == 1) cout << dq.size() << endl;
            else if(q == 2)
            {
                if(dq.empty()) cout << "YES\n";
                else cout << "NO\n";
            }
            else if(q == 3)
            {
                int x; cin >> x;
                dq.push_back(x);
            }
            else if(q == 4)
            {
                if(!dq.empty()) dq.pop_front();
            }
            else if(q == 5)
            {
                if(!dq.empty()) cout << dq.front() << endl;
                else cout << -1 << endl;
            }
            else
            {
                if(!dq.empty()) cout << dq.back() << endl;
                else cout << -1 << endl;
            }
        }
    }
    return 0;
}