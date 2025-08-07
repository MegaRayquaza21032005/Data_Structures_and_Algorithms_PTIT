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

int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n + 9);
        FOR(i, 1, n) cin >> a[i];
        vector<int> Max(n + 9); //lưu giá trị lớn nhất từ i đến n
        int res = -1;
        Max[n] = a[n];
        FORD(i, n - 1, 1)
        {
            Max[i] = max(Max[i + 1], a[i]);
        }
        int i = 1, j = 1;
        while(i <= n && j <= n)
        {
            if(a[i] < Max[j])
            {
                res = max(res, j - i);
                ++j;
            }
            else ++i;
        }
        if(res == 0) res = -1;
        cout << res << endl;
    }
}