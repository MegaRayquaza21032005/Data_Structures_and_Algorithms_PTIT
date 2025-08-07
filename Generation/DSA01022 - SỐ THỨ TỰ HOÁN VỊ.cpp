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
    for(int i = 1; i <= n; ++i)
    {
        a[i] = i;
    }
}
void generate()
{
    int i = n - 1;
    while(a[i] > a[i + 1] && i >= 1)
    {
        --i;
    }
    if(i == 0) final = 1;
    else
    {
        int j = n;
        while(a[j] < a[i]) --j;
        swap(a[i], a[j]);
        reverse(a + i + 1, a + n + 1);
    }
}
int process(int a[], int b[], int n)
{
    for(int i = 1; i <= n; ++i)
    {
        if(a[i] != b[i]) return 0;
    }
    return 1;
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
        for(int i = 1; i <= n; ++i) cin >> b[i];
        init();
        int cnt = 1;
        while(final == 0)
        {
            if(process(a, b, n))
            {
                cout << cnt << endl;
                break;
            }
            cnt++;
            generate();
        }
    }
    return 0;
}
