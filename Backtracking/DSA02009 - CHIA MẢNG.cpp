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

int a[1009], n, k, check = 0, sum = 0;
int mark[1009];


void Try(int i, int s, int cnt)
{
    if(check) return;
    if(cnt == k - 1)
    {
        check = 1;
        return;
    }
    if(s == sum)
    {
        Try(0, 0, cnt + 1);
    }
    else if(s > sum) return;
    FOR(j, i + 1, n)
    {
        if(mark[j] == 0)
        {
            mark[j] = 1;
            Try(j, s + a[j], cnt);
            mark[j] = 0;
        }
    }
}
int main()
{
    fast;
    int T = 1; 
    cin >> T;
    while(T--)
    {
        check = 0;
        cin >> n >> k;
        int sum = 0;
        FOR(i, 1, n)
        {
            cin >> a[i];
            sum += a[i];
        }
        if(sum % k != 0)
        {
            cout << 0 << endl;;
        }
        else
        {
            sum /= k;
            Try(0, 0, 0);
            if(check == 1)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }
}