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
    while(a[i] == 0 && i >= 1)
    {
        a[i] = 1;
        --i;
    }
    if(i == 0) final = 1;
    else a[i] = 0;
}
int main()
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        final = 0;
        string s; cin >> s;
        n = s.size();
        for(int i = 0; i < n; ++i)
        {
            a[i + 1] = s[i] - '0';
        }
        generate();
        for(int i = 1; i <= n; ++i) cout << a[i];
        cout << endl;
    }
    return 0;
}