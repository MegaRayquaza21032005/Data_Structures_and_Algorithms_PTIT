#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
const ll mod = 1e9 + 7;

ll F[1000];
void fibo()
{
    F[0] = 0;
    F[1] = 1;
    FOR(i, 2, 92)
    {
        F[i] = (F[i - 1] + F[i - 2]);
    }
}

int Find(ll n, ll k)
{
    if(n == 1) return 0;
    if(n == 2) return 1;
    if(k <= F[n - 2]) return Find(n - 2, k);
    else return Find(n - 1, k - F[n - 2]);
}
int main()
{
    fast;
    int t = 1;
    cin >> t;
    fibo();
    while(t--)
    {
        ll n, k;
        cin >> n >> k;
        cout << Find(n, k) << endl;
    }
}