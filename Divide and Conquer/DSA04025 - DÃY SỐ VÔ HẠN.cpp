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
    ll a[2][2], n;
    friend Matrix operator * (Matrix x, Matrix y)
    {
        Matrix res;
        FOR(i, 0, 1)
        {
            FOR(j, 0, 1)
            {
                res.a[i][j] = 0;
                FOR(k, 0, 1)
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
        ll n, k; cin >> n;
        Matrix A;
        A.a[0][0] = 1; A.a[0][1] = A.a[1][0] = 1;
        A.a[1][1] = 0;
        A = binpow(A, n);
        cout << A.a[0][1] << endl;
    }
    return 0;
}
