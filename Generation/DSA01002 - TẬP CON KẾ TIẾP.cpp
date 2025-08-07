#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
const int mod = 1e9 + 7;

int a[109], n, k, final = 0;
int b[109];
void init()
{
    for(int i = 1; i <= k; ++i) cin >> a[i];
}
void generate()
{
    int i = k;
    while(a[i] == n - k + i && i >= 1)
    {
        --i;
    }
    if(i == 0) final = 1;
    else
    {
        a[i]++;
        for(int j = i + 1; j <= n; ++j)
        {
            a[j] = a[j - 1] + 1;
        }
    }
}
int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        final = 0;
        cin >> n >> k;
        init();
        generate();
        if(final == 1)
        {
            for(int i = 1; i <= k; ++i) cout << i << " ";
            cout << endl;
        }
        else
        {
            for(int i = 1; i <= k; ++i) cout << a[i] << " ";
        }
        cout << endl; 
    }
    return 0;
}
