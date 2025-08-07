#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
const int mod = 1e9 + 7;

int a[1009], n, k, final = 0;
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
    cin >> t;
    while(t--)
    {
        final = 0;
        cin >> n >> k;
        init();
        while(!final)
        {
            int cnt = 0;
            for(int i = 1; i <= n; ++i)
            {
                if(a[i] == 1) cnt++;
            }
            if(cnt == k)
            {
                for(int i = 1; i <= n; ++i)
                {
                    cout << a[i];
                }
                cout << endl;
            }
            generate();
        }
    }
    return 0;
}