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
 
// có thể sử dụng bfs
int h[100009];
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        int n; cin >> n;
        h[1] = 0;
        int M = INT_MIN;
        while(--n)
        {
            int u, v; cin >> u >> v;
            h[v] = h[u] + 1;
            M = max(M, h[v]);
        }
        cout << M << endl;
    }
    return 0;
} 