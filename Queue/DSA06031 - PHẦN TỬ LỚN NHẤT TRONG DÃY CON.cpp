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
    int T = 1;
    cin >> T;
    while(T--)
    {
        int n, k; cin >> n >> k;
        int a[n + 9];
        FOR(i, 1, n) cin >> a[i];
        deque<int> dq;
        FOR(i, 1, k)
        {
            while(!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
            dq.push_back(i);
        }
        cout << a[dq.front()] << " ";
        FOR(i, k + 1, n)
        {
            if(i - k == dq.front()) dq.pop_front();
            while(!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
            dq.push_back(i);
            cout << a[dq.front()] << " ";
        }
        cout << endl;
    }
    
    return 0;
}