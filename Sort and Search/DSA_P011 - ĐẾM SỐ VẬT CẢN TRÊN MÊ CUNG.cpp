#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
const int mod = 1e9 + 7;

char a[1009][1009];
int cnt = 0, n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
void input(int n, int m)
{
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }
}
void Try(int i, int j)
{
    a[i][j] = '.';
    for(int k = 0; k < 4; ++k)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1 > 0 && i1 <= n && j1 > 0 && j1 <= m && a[i1][j1] == '#') Try(i1, j1);
    }
}
int main()
{
    fast;
    cin >> n >> m;
    input(n, m);
    int cnt = 0;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(a[i][j] == '#')
            {
                cnt++;
                Try(i, j);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
 