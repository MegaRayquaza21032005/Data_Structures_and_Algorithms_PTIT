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

int a[1000009];
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        int n; cin >> n;
        FOR(i, 1, n)
        {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        int cnt = n, l = 1, r = (n >> 1) + 1;
        while(l <= (n >> 1) && r <= n)
        {
            if(a[l] * 2 <= a[r])
            {
                --cnt;
                ++l;
                ++r;
            }
            else ++r;
        }
        cout << cnt << endl;
    }
    return 0;
}