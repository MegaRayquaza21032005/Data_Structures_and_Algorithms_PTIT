#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
const int mod = 1e9 + 7;

int n, k, a[1009], final = 0;

void Try(int i)
{
    for(int j = a[i - 1]; j <= n; ++j)
    {
        a[i] = j;
        if(i == k)
        {
            for(int l = 1; l <= k; ++l)
            {
                cout << char (a[l] + 64);
            }
            cout << endl;
        }
        else Try(i + 1);
    }
}
int main()
{
    fast;
    int T = 1; 
    //cin >> T;
    while(T--)
    {
        a[0] = 1;
        char c; cin >> c;
        cin >> k;
        n = c - 'A' + 1;
        Try(1);
    }
}
 