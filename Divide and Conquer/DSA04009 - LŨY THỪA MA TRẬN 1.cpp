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

struct Matrix 
{
    ll a[20][20], n;
    friend Matrix operator * (Matrix x, Matrix y)
    {
        Matrix res;
        res.n = x.n;
        FOR(i, 1, x.n)
        {
            FOR(j, 1, y.n)
            {
                res.a[i][j] = 0;
                FOR(k, 1, res.n)
                {
                    res.a[i][j] += x.a[i][k] * y.a[k][j];
                    res.a[i][j] %= mod;
                }
            }
        }
        return res;
    }
};

Matrix binpow(Matrix x, ll k)
{
    if(k == 1) return x;
    else
    {
        Matrix A = binpow(x, k / 2);
        A = A * A;
        if(k & 1) return A * x;
        else return A;
    }
}
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        ll n, k; cin >> n >> k;
        Matrix A;
        A.n = n;
        FOR(i, 1, n)
        {
            FOR(j, 1, n) cin >> A.a[i][j];
        }
        A = binpow(A, k);
        FOR(i, 1, n)
        {
            FOR(j, 1, n) cout << A.a[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}
