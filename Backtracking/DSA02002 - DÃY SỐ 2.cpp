#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
const int mod = 1e9 + 7;

int x[1009], n, k, cnt = 0;
int mark[1009];

void Try(int i)
{
    for(int j = 1; j <= i; ++j)
    {
        x[j] += x[j + 1];
    }
    if(i != 1) Try(i - 1);
    else return;
    for(int j = i - 1; j >= 1; --j)
    {
        x[j] -= x[j + 1];
    }
    cout << "[";
    for(int j = 1; j <= i - 1; ++j)
    {
        cout << x[j];
        if(j != i - 1) cout << " ";
        else cout << "] ";
    }
}
int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        for(int i = 1; i <= n; ++i)
        {
            cin >> x[i];
        }
        Try(n);
        for(int j = n - 1; j >= 1; --j)
        {
            x[j] -= x[j + 1];
        }
        cout << "[";
        for(int j = 1; j <= n; ++j)
        {
            cout << x[j];
            if(j != n) cout << " ";
            else cout << "] ";
        }
        cout << endl;
    }
}
 