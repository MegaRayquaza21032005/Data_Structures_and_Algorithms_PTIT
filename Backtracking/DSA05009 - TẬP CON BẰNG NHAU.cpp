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

int n, k, a[1009], sum = 0, cnt = 0, check = 0;

void Try(int i, int s)
{
    if(check == 1) return;
    if(s == sum)
    {
        check = 1;
        cout << "YES\n";
        return;
    }
    if(s > sum) return;
    FOR(j, i + 1, n)
    {
        Try(j, s + a[j]);
    }
}
int main()
{
    fast;
    int T = 1; 
    cin >> T;
    while(T--)
    {
        sum = 0;
        check = 0;
        cin >> n;
        FOR(i, 1, n)
        {
            cin >> a[i];
            sum += a[i];
        }
        if(sum & 1)
        {
            cout << "NO\n";
        }
        else
        {
            sum /= 2;
            Try(0, 0);
            // if(check) cout << "YES\n";
            // else cout << "NO\n";
            if(check == 0) cout << "NO\n";

        }
    }
}