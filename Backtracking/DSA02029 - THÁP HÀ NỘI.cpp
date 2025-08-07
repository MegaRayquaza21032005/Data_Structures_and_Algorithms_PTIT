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

int a[1009], n, k, check = 0;

void Try(int i, char a, char b, char c)
{
    if(i == 1)
    {
        cout << a << " -> " << c << endl;
    }
    else
    {
        Try(i - 1, a, c, b);
        Try(1, a, b, c);
        Try(i - 1, b, a, c);
    }
}
int main()
{
    fast;
    int T = 1; 
    //cin >> T;
    while(T--)
    {
        int n; cin >> n;
        Try(n, 'A', 'B', 'C');
    }
}