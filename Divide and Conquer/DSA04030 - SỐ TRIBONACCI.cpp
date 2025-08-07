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


/*
0 1 0 0  *   T1          T2
0 0 1 0      T2    =     T3                                                                                          
1 1 1 0      T3          T4                                                                                   
1 1 1 1      S3          S4                                                                                    


*/
ll bin_mul(ll a, ll b)
{
    if(b == 1) return a % llmod;
    else if(b == 0) return 0;
    else
    {
        ll x = bin_mul(a, b / 2) % llmod;
        x = (x + x) % llmod;
        if(b & 1) return (x + a % llmod) % llmod;
        else return x;
    }
}
struct Matrix
{
    ll a[5][5];
    friend Matrix operator *(Matrix x, Matrix y)
    {
        Matrix res;
        FOR(i, 0, 3)
        {
            FOR(j, 0, 3)
            {
                res.a[i][j] = 0;
                FOR(k, 0, 3)
                {
                    res.a[i][j] += bin_mul(x.a[i][k], y.a[k][j]);
                    res.a[i][j] %= llmod;
                }
            }
        }
        return res;
    }
};

Matrix bin_pow(Matrix A, int n)
{
    if(n == 1) return A;
    else
    {
        Matrix res = bin_pow(A, n / 2);
        res = res * res;
        if(n & 1) return res * A;
        else return res;
    }
}
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        int n; cin >> n;
        if(n == 0) cout << 0 << endl;
        else if(n == 1) cout << 1 << endl;
        else if(n == 2) cout << 3 << endl;
        else if(n == 3) cout << 6 << endl;
        else
        {
            Matrix A;
            FOR(i, 0, 3)
            {
                FOR(j, 0, 3) A.a[i][j] = 0;
            }
            A.a[0][1] = A.a[1][2] = A.a[2][0] = A.a[2][1] = A.a[2][2] = 1;
            FOR(i, 0, 3) A.a[3][i]  = 1;

            Matrix res = bin_pow(A, n - 3);
            cout << (1 * res.a[3][0] + 2 * res.a[3][1] + 3 * res.a[3][2] + 6 * res.a[3][3]) % llmod << endl;
        }
    }
    return 0;
}