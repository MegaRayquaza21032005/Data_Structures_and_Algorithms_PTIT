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
int main()
{
    fast;
    int t = 1;
    //cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i = 1; i <= n; ++i) cin >> b[i];
        init();
        int cnt = 0;
        while(!final)
        {
            int sum = 0;
            for(int i = 1; i <= n; ++i)
            {
                if(a[i] == 1) sum += b[i];
            }
            if(sum == k)
            {
                cnt++;
                for(int i = 1; i <= n; ++i)
                {
                    if(a[i] == 1) cout << b[i] << " ";
                }
                cout << endl;
            }
            generate();
        }
        cout << cnt << endl;
    }
    return 0;
}
