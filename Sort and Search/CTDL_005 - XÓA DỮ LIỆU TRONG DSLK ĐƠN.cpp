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

int a[10000009], n, k;

int main()
{
    fast;
    int T = 1; 
    //cin >> T;
    while(T--)
    {
        int n; cin >> n;
        FOR(i, 1, n)
        {
            cin >> a[i];
        }
        cin >> k;
        FOR(i, 1, n)
        {
            if(a[i] != k)
            {
                cout << a[i] << " ";
            }
        }
    }
}