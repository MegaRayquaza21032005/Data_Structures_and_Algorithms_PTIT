#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
const int mod = 1e9 + 7;

int a[1009], n, k, final = 0;
void init()
{
    for(int i = 1; i <= n; ++i) a[i] = 0;
}
void generate()
{
    int i = n;
    while(a[i] == 1 && i >= 1)
    {
        a[i] = 0;
        --i;
    }
    if(i == 0) final = 1;
    else a[i] = 1;
}
bool check(int a[], int n)
{ 
    if(a[n] == 1 || a[1] == 0) return false;
    else
    {
        for(int i = 1; i <= n - 1; ++i)
        {
            if(a[i] == 1 && a[i + 1] == 1) return false;
        }
    }
    return true;
}
int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        final = 0;
        cin >> n;
        init();
        while(!final)
        {
            if(check(a, n))
            {
                for(int i = 1; i <= n; ++i)
                {
                    if(a[i] == 0) cout << 'A';
                    else cout << 'H';
                }
                cout << endl;
            }
            generate();
        }
    }
    return 0;
}