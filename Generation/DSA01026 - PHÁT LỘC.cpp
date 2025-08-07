#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
const int mod = 1e9 + 7;

int a[1009], n, k, final = 0;
void init()
{
    for(int i = 1; i <= n; ++i) a[i] = 6;
}
void generate()
{
    int i = n;
    while(a[i] == 8 && i >= 1)
    {
        a[i] = 6;
        --i;
    }
    if(i == 0) final = 1;
    else a[i] = 8;
}
bool check(int a[], int n)
{
    if(a[1] != 8 || a[n] != 6) return false;
    for(int i = 1; i <= n - 1; ++i)
    {
        if(a[i] == 8 && a[i + 1] == 8) return false;
    }
    for(int i = 1; i <= n - 3; ++i)
    {
        if(a[i] == 6 && a[i + 1] == 6 && a[i + 2] == 6 && a[i + 3] == 6) return false;
    }
    return true;
}
int main()
{
    fast;
    int t = 1;
    //cin >> t;
    while(t--)
    {
        final = 0;
        cin >> n;
        init();
        while(!final)
        {
            if(check(a, n))
            {
                for(int i = 1; i <= n; ++i) cout << a[i];
                cout << endl;
            }
            generate();
        }
    }
    return 0;
}