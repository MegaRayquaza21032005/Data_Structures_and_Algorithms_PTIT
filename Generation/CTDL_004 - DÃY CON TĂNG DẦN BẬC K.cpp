#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

int a[100], n, k, final = 0, cnt = 0;
int b[100];
void init()
{
    for(int i = 1; i <= n; ++i) a[i] = 0;
}

void generator()
{
    int i = n;
    while(a[i] == 1 && i >= 1)
    {
        a[i] = 0;
        --i;
    }
    if(i==0) final = 1;
    else
    {
        a[i] = 1;
    }
}
bool check(int a[], int b[], int n)
{
    int tmp = INT_MIN;
    int sum = 0;
    for(int i = 1; i <= n; ++i) sum += a[i];
    if(sum != k) return false;
    else
    {
        for(int i = 1; i <= n; ++i)
        {
            if(a[i] == 1)
            {
                if(b[i] <= tmp) return false;
                else tmp = b[i];
            }
        }
    }
    return true;
}
int main()
{
    fast;
    int t = 1;
    while(t--)
    {
        cin >> n >> k;
        for(int i = 1; i <= n; ++i) cin >> b[i];
        init();
        final = 0;
        cnt = 0;
        while(final == 0)
        {
            if(check(a, b, n)) cnt++;
            generator();
        }
        cout << cnt << endl;
    }
}