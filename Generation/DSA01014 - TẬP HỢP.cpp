#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
const int mod = 1e9 + 7;

int a[1009], n, k, s, final = 0;
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
        for(int j = i + 1; j <= k; ++j)
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
    while(true)
    {
        ll cnt = 0;
        final = 0;
        cin >> n >> k >> s;
        if(n == 0 && k == 0 && s == 0) break;
        ll m = 0, M = 0;
        for(int i = 1; i <= k; ++i)
        {
            m += i;
            M += (n - i + 1);
        }
        if(s > M || s < m) cout << "0\n";
        else
        {
            init();
            while(!final)
            {
                int sum = 0;
                for(int i = 1; i <= k; ++i) sum += a[i];
                if(sum == s) cnt++;
                generate();
            } 
            cout << cnt << endl;
        }
    }
    return 0;
}
