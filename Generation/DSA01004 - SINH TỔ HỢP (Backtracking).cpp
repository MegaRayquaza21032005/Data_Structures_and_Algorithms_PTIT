#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
const ll mod = 1e15 + 7;

int a[10009], n, k, final;

void Try(int i)
{
    if(i > k)
    {
        for(int j = 1; j <= k; ++j)
        {
            cout << a[j];
        }
        cout << " ";
        return;
    }
    for(int j = a[i - 1] + 1; j <= n - k + i; ++j)
    {
        a[i] = j;
        Try(i + 1);
    }
}
int main()
{
    fast;
    int T = 1;
    cin >> T;
    while(T--)
    {
        cin >> n >> k;
        Try(1);
        cout << endl;
    }
    
}