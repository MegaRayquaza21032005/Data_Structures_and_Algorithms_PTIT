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

int a[1000], b[1000], c[1000];
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        int n, m; cin >> n >> m;
        FOR(i, 0, n - 1) cin >> a[i];
        FOR(i, 0, m - 1) cin >> b[i];
        FOR(i, 0, n - 1)
        {
            FOR(j, 0, m - 1)
            {
                c[i + j] += a[i] * b[j];
            }
        }
        FOR(i, 0, m + n - 2) cout << c[i] << " ";
        cout << endl;
        ms(c, 0);
    }
    return 0;
}