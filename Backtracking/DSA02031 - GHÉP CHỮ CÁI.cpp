#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
const int mod = 1e9 + 7;

int n, k, a[1009], final = 0;
int mark[1009];

bool check()
{
    for(int i = 2; i <= n - 1; ++i)
    {
        if(a[i] == 1)
        {
            if(a[i - 1] == 5 || a[i + 1] == 5) return true;
            else return false;
        }
        else if(a[i] == 5)
        {
            if(a[i - 1] == 1 || a[i + 1] == 1) return true;
            else return false;
        }
    }
    return true;
}
void Try(int i)
{
    for(int j = 1; j <= n; ++j)
    {
        if(mark[j] == 0)
        {
            mark[j] = 1;
            a[i] = j;
            if(i == n)
            {
                if(check())
                {
                    for(int i = 1; i <= n; ++i) cout << char(a[i] + 64);
                    cout << endl;
                }
            }
            else Try(i + 1);
            mark[j] = 0;
        }
    }
}
int main()
{
    fast;
    int T = 1; 
    //cin >> T;
    while(T--)
    {
        char c; cin >> c;
        n = c - 'A' + 1;
        Try(1);
    }
}