#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define ll long long

int n, s, a[1009], b[1009][1009], final = 0, cnt = 1;

void input(int a[][1009], int n)
{
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j) cin >> b[i][j];
    }
}
void init()
{
    for(int i = 1; i <= n; ++i) a[i] = i;
}
void generator()
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
int main() 
{
    fast;
    cin >> n >> s;
    input(b, n);
    vector<vector<int>> res;
    init();
    while(final == 0)
    {
        ll sum = 0;
        for(int i = 1; i <= n; ++i)
        {
            sum += b[i][a[i]];
        }
        if(sum == s)
        {
            vector<int> tmp;
            for(int i = 1; i <= n; ++i)
            {
                tmp.push_back(a[i]);
            }
            res.push_back(tmp);
        }
        generator();
    }
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); ++i)
    {
        for(int x : res[i]) cout << x << " ";
        cout << endl;
    }
    return 0;
}