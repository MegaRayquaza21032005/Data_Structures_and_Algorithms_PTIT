#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
const int mod = 1e9 + 7;

int n, m, a[1009][1009], final = 0, cnt = 0;
int dx[2] = {1, 0};
int dy[2] = {0, 1};
void input(int n, int m)
{
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j) cin >> a[i][j];
    }
}
void Try(int i, int j)
{
    for(int k = 0; k < 2; ++k)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1 > 0 && i1 <= n && j1 > 0 && j1 <= m)
        {
            if(i1 == n && j1 == m)
            {
                cnt++;
            }
            else
            {
                Try(i1, j1);
            }
        }
    }
}
int main()
{
    fast;
    int T = 1; 
    cin >> T;
    while(T--)
    {
        cnt = 0;
        cin >> n >> m;
        input(n, m);
        Try(1, 1);
        cout << cnt << endl;
    }
}
 