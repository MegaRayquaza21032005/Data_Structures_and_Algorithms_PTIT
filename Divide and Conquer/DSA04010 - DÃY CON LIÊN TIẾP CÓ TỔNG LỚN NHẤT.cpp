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
int crossing_sum(int a[], int l, int r, int m)
{
    int M1 = INT_MIN, M2 = INT_MIN;
    int sum = 0;
    FORD(i, m, l)
    {
        sum += a[i];
        M1 = max(M1, sum);
    }
    sum = 0;
    FOR(i, m + 1, r)
    {
        sum += a[i];
        M2 = max(M2, sum);
    }
    return M1 + M2;
}
int max_sum(int a[], int l, int r)
{
    if(l == r) return a[l];
    else
    {
        int m = (l + r) / 2;
        return max({max_sum(a, l, m), max_sum(a, m + 1, r), crossing_sum(a, l, r, m)});
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
        FOR(i, 1, n)
        {
            cin >> a[i];
        }
        cout << max_sum(a, 1, n) << endl;
        
    }
    return 0;
}