#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
const int mod = 1e9 + 7;

int a[1009], n, k, final = 0;
int b[1009];
void init()
{
    for(int i = 1; i <= k; ++i) a[i] = i;
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
    //cin >> t;
    while(t--)
    {
        final = 0;
        cin >> n >> k;
        set<int> se;
        for(int i = 1; i <= n; ++i)
        {
            int x; cin >> x;
            se.insert(x);
        }
        n = se.size();
        int i = 1;
        for(auto x : se)
        {
            b[i++] = x;
        }
        init();
        while(!final)
        {
            for(int i = 1; i <= k; ++i)
            {
                cout << b[a[i]] << " ";
            }
            cout << endl;
            generate();
        }
    }
    return 0;
}
