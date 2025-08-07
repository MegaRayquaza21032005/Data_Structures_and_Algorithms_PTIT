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
    for(int i = 1; i <= k; ++i)
    {
        cin >> a[i];
        b[i] = a[i];
    }
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
int process(int a[], int b[], int n)
{
    int cnt = 0;
    set<int> se;
    for(int i = 1; i <= k; ++i)
    {
        se.insert(b[i]);
    }
    for(int i = 1; i <= k; ++i)
    {
        if(se.find(a[i]) == se.end()) cnt++;
    }
    return cnt;
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
        if(final == 0) cout << process(a, b, n) << endl;
        else cout << k << endl;
    }
    return 0;
}
